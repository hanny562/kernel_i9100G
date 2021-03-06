#include <linux/module.h>

#include <linux/init.h>
#include <linux/fs.h>
#include <linux/i2c.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/sched.h>
#include <linux/pm.h>
#include <linux/sysctl.h>
#include <linux/proc_fs.h>
#include <linux/delay.h>
#include <linux/platform_device.h>
#include <linux/input.h>
#include <asm/gpio.h>
#include <linux/miscdevice.h>
#include <asm/uaccess.h>
#include <linux/earlysuspend.h>
#include <asm/io.h>
#include <linux/hrtimer.h>

#include "i2c_bitbang.h"

/*****************************************************************
/    Low Level routines for internal use ONLY. DO NOT CALL.	 /
*****************************************************************/

// Bus_Delay()
// Wait the desired number of micro-seconds
// Bus-Freq in Khz range
// ****************************************************************************
static void inline Bus_Delay(int usecs)
{
	udelay(usecs);
}


// fSDATACheck()
// Check SDATA pin for high or low logic level and return value to calling
// routine.
// Returns:
//     0 if the pin was low.
//     1 if the pin was high.
// ****************************************************************************
static unsigned char inline fSDATACheck(void)
{
	//omap_writew(0x0103, 0x4A100130);	//tmp OD hack for i2c4
	gpio_direction_input(SDATA_PIN);

	if(gpio_get_value(SDATA_PIN))
		return (1);
	else
		return (0);
	}

   


// SCLKHigh()
// Set the SCLK pin High
// ****************************************************************************
static void inline SCLKHigh(void)
{
	gpio_direction_output(SCLK_PIN, 1);
}




// SCLKLow()
// Make Clock pin Low
// ****************************************************************************
static void inline SCLKLow(void)
{
	gpio_direction_output(SCLK_PIN, 0);
}




// SetSCLKHiZ()
// Set SCLK pin to HighZ drive mode.
// ****************************************************************************
static void inline SetSCLKHiZ(void)
{
	gpio_direction_input(SCLK_PIN);
}




// SDATAHigh()
// Make SDATA pin High
// ****************************************************************************
static void inline SDATAHigh(void)
{
	//omap_writew(0x011B, 0x4A100130);	//tmp OD hack for i2c4
	gpio_direction_output(SDATA_PIN, 1);
}




// SDATALow()
// Make SDATA pin Low
// ****************************************************************************
static void inline SDATALow(void)
{
	//omap_writew(0x011B, 0x4A100130);	//tmp OD hack for i2c4
	gpio_direction_output(SDATA_PIN, 0);
}




// SDATAHiZ()
// Set SDATA pin to an input (HighZ drive mode).
// ****************************************************************************
static void inline SDATAHiZ(void)
{
	gpio_direction_input(SDATA_PIN); // ENA-> DIS
}





/*****************************************************************
/    High Level routines for internal use ONLY. DO NOT CALL.	 /
*****************************************************************/

// ============================================================================
// Generate_Start()
// Description:
// Generates Start signal on i2c bus
// ============================================================================
static void inline Generate_Start(void)
{
	SCLKHigh();
	SDATAHigh();
	Bus_Delay(HALF_BUS_ON_PERIOD);

	SDATALow();
	Bus_Delay(BUS_ON_PERIOD);

	SCLKLow();
	Bus_Delay(HALF_BUS_OFF_PERIOD);

}

// ============================================================================
// Generate_Stop()
// Description:
// Generates Stop signal on i2c bus
// ============================================================================
static void inline Generate_Stop(void)
{
	SDATALow();
	Bus_Delay(HALF_BUS_OFF_PERIOD);

	SCLKHigh();
	Bus_Delay(HALF_BUS_ON_PERIOD);

	SDATAHigh();
	Bus_Delay(HALF_BUS_ON_PERIOD);
}


#if 0
// ============================================================================
// RunClock()
// Description:
// Run Clock without sending/receiving bits. Use this when transitioning from
// write to read and read to write "num_cycles" is number of SCLK cycles, not
// number of counter cycles.
//
// SCLK cannot run faster than the specified maximum frequency of 8MHz. Some
// processors may need to have delays added after setting SCLK low and setting
// SCLK high in order to not exceed this specification. The maximum frequency
// of SCLK should be measured as part of validation of the final program
//
// ============================================================================
static void RunClock(unsigned int iNumCycles)
{
    int i;

    for(i=0; i < iNumCycles; i++) {
        SCLKLow();
	Bus_Delay(HALF_BUS_OFF_PERIOD);
        SCLKHigh();
	Bus_Delay(BUS_ON_PERIOD);
	Bus_Delay(HALF_BUS_OFF_PERIOD);
    }
    // function exits with CLK high.

}
#endif


// ============================================================================
// ReceiveBit()
// Clocks the SCLK pin (high-low-high) and reads the status of the SDATA pin
// after the rising edge.
//
// SCLK cannot run faster than the specified maximum frequency of 8MHz. Some
// processors may need to have delays added after setting SCLK low and setting
// SCLK high in order to not exceed this specification. The maximum frequency
// of SCLK should be measured as part of validation of the final program
//
// Returns:
//     0 if SDATA was low
//     1 if SDATA was high
// ============================================================================
static unsigned char ReceiveBit(void)
{
	unsigned char retval;

	// Generate a clock-period
	// End in the half of CLK-pin low
	Bus_Delay(HALF_BUS_OFF_PERIOD);
	SCLKHigh();
	Bus_Delay(HALF_BUS_ON_PERIOD);

	retval = fSDATACheck();

	Bus_Delay(HALF_BUS_ON_PERIOD);
	SCLKLow();
	Bus_Delay(HALF_BUS_OFF_PERIOD);

	return (retval);
}

// ============================================================================
// ReceiveByte()
// Calls ReceiveBit 8 times to receive one byte.
// Returns:
//     The 8-bit values recieved.
// ============================================================================
static unsigned char ReceiveByte(void)
{
	unsigned char b;
	unsigned char CurrByte = 0x00;

	for (b=0; b<8; b++) {
		CurrByte = (CurrByte<<1) + ReceiveBit();
	}

	Bus_Delay(HALF_BUS_OFF_PERIOD);
	SCLKHigh();
	Bus_Delay(BUS_ON_PERIOD);
	SCLKLow();
	Bus_Delay(HALF_BUS_OFF_PERIOD);

	return(CurrByte);

}


// ============================================================================
// SendByte()
// This routine sends up to one byte of a vector, one bit at a time.
//    CurrByte   the byte that contains the bits to be sent.
//    Size       the number of bits to be sent. Valid values are 1 to 8.
//
// SCLK cannot run faster than the specified maximum frequency of 8MHz. Some
// processors may need to have delays added after setting SCLK low and setting
// SCLK high in order to not exceed this specification. The maximum frequency
// of SCLK should be measured as part of validation of the final program
//
// There is no returned value.
// ============================================================================
static void SendByte(unsigned char CurrByte, unsigned char Size)
{
    unsigned char b = 0;

	for(b=0; b<Size; b++) {
	if (CurrByte & 0x80) {

	    // Send a '1'
	    // Transition in the half of CLK-pin LOW
	    // Generate_Start ends with HALF_BUS_OFF_PERIOD delay in the end.
	    SDATAHigh();
	    Bus_Delay(HALF_BUS_OFF_PERIOD);

	    // Generate a clock-period
	    // End in the half of CLK-pin low
	    SCLKHigh();
	    Bus_Delay(BUS_ON_PERIOD);
	    SCLKLow();
	    Bus_Delay(HALF_BUS_OFF_PERIOD);
	}
	else {
	    // Send a '0'
	    SDATALow();
	    Bus_Delay(HALF_BUS_OFF_PERIOD);

	    // Generate a clock-period
	    // End in the half of CLK-pin low
	    SCLKHigh();
	    Bus_Delay(BUS_ON_PERIOD);
	    SCLKLow();
	    Bus_Delay(HALF_BUS_OFF_PERIOD);
	}
	CurrByte = CurrByte << 1;
	}

	//ACK EMPTY CLK period
	Bus_Delay(HALF_BUS_OFF_PERIOD);
	fSDATACheck();
	SCLKHigh();
	Bus_Delay(BUS_ON_PERIOD);
	SCLKLow();
	Bus_Delay(HALF_BUS_OFF_PERIOD);
}



/*****************************************************************
/  Routines for EXTERNAL use. Edit i2c_bitbang.h before using.	 /
*****************************************************************/

// MUST be called FIRST.
// MUST be called ONLY once.
// Return values:
// success  0
// failure -1
int i2c_bitbang_init(void)
{
	if ( gpio_request(SDATA_PIN, "i2c_bitbang_SDATA") )
		return (-1);
	else if( gpio_request(SCLK_PIN, "i2c_bitbang_SCLK") )
		return (-1);
	else
		return (0);
}


// call to perform i2c_write over gpio-lines.
void i2c_bitbang_write(unsigned char slave_addr, unsigned char reg_addr, unsigned char val)
{
	//Start Condition
	Generate_Start();

	//send chip addr
	//7bit addr + R/W bit zero
	SendByte( (slave_addr<<1), 8);
	
	//send register addr
	SendByte( reg_addr, 8);

	//send register data
	SendByte( val, 8);

	//Stop Condition
	Generate_Stop();
}


// call to perform i2c_read over gpio-lines.
void i2c_bitbang_read(unsigned char slave_addr, unsigned char reg_addr, unsigned char *val)
{

	//Start Condition
	Generate_Start();

	//send chip addr
	//7bit addr + R/W bit one
	SendByte( (slave_addr<<1)+1, 8);
	
	//send register addr
	SendByte( reg_addr, 8);

	//send register data
	*val = ReceiveByte();

	//Stop Condition
	Generate_Stop();

}


MODULE_AUTHOR("Praveen B P, CVS");
MODULE_DESCRIPTION("Generic i2c module via bitbang GPIOs");
