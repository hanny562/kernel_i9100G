/*
 * Samsung MIPI panel support
 *
 * Copyright 2011 samsung electronics.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http: www.gnu.org/licenses/>.
 */

typedef enum 
{
    ACL_STATUS_0P = 0,
    ACL_STATUS_40P,    
    ACL_STATUS_43P,    
    ACL_STATUS_45P,    
    ACL_STATUS_47P,    
    ACL_STATUS_48P,    
    ACL_STATUS_50P,   
    ACL_STATUS_MAX
} ACL_STATUS;


const u8 acl_cutoff_0p_param_set[] = {   /* DUMMY */
	0xC1,
	0x47, 0x53, 0x13, 0x53,
	0x00, 0x00, 0x03, 0x1F,
	0x00, 0x00, 0x04, 0xFF,
	0x00, 0x00, 0x00, 0x00,       	
	0x00, 0x00, 0x00, 0x00,       	
	0x00, 0x00, 0x00, 0x00,       	
	0x00, 0x00, 0x00, 0x00,
};

const u8 acl_cutoff_40p_param_set[] = {
	0xC1,
	0x47, 0x53, 0x13, 0x53,
	0x00, 0x00,	0x03, 0x1F,
	0x00, 0x00,	0x04, 0xFF,
	0x00, 0x00, 0x00, 0x00,       	
	0x00, 0x01, 0x06, 0x0C,       	
	0x11, 0x16, 0x1C, 0x21,       	
	0x26, 0x2B, 0x31, 0x36,
};

const u8 acl_cutoff_43p_param_set[] = {
	0xC1,
	0x47, 0x53, 0x13, 0x53,
	0x00, 0x00, 0x03, 0x1F,
	0x00, 0x00, 0x04, 0xFF,
	0x00, 0x00, 0x00, 0x00,       	
	0x00, 0x00, 0x00, 0x00,       	
	0x10, 0xAC, 0x28, 0x31,       	
	0x3A, 0x40, 0x46, 0x4B,
};

const u8 acl_cutoff_45p_param_set[] = {
	0xC1,
	0x47, 0x53, 0x13, 0x53,
	0x00, 0x00, 0x03, 0x1F,
	0x00, 0x00, 0x04, 0xFF,
	0x00, 0x00, 0x00, 0x00,       	
	0x00, 0x00, 0x00, 0x00,       	
	0x10, 0x20, 0x2B, 0x35,       	
	0x3D, 0x44, 0x4A, 0x50,
};

const u8 acl_cutoff_47p_param_set[] = {
	0xC1,
	0x47, 0x53, 0x13, 0x53,
	0x00, 0x00, 0x03, 0x1F,
	0x00, 0x00, 0x04, 0xFF,
	0x00, 0x00, 0x00, 0x00,       	
	0x00, 0x00, 0x00, 0x00,       	
	0x11, 0x21, 0x2D, 0x38,      	
	0x41, 0x49, 0x4F, 0x55,
};

const u8 acl_cutoff_48p_param_set[] = {
	0xC1,
	0x47, 0x53, 0x13, 0x53,
	0x00, 0x00, 0x03, 0x1F,
	0x00, 0x00, 0x04, 0xFF,
	0x00, 0x00, 0x00, 0x00,       	
	0x00, 0x00, 0x00, 0x00,       	
	0x11, 0x21, 0x2E, 0x39,       	
	0x42, 0x4A, 0x51, 0x57,
};

const u8 acl_cutoff_50p_param_set[] = {
	0xC1,
	0x47, 0x53,	0x13, 0x53,
	0x00, 0x00,	0x03, 0x1F,
	0x00, 0x00,	0x04, 0xFF,
	0x00, 0x00, 0x00, 0x00,       	
	0x00, 0x00, 0x01, 0x0F,       	
	0x16, 0x1D, 0x24, 0x2A,       	
	0x31, 0x38, 0x3F, 0x46,
};

const u8 * acl_cutoff_param_set_tbl[ACL_STATUS_MAX] = {
    acl_cutoff_0p_param_set,
	acl_cutoff_40p_param_set,
	acl_cutoff_43p_param_set,
	acl_cutoff_45p_param_set,
	acl_cutoff_47p_param_set,
	acl_cutoff_48p_param_set,
	acl_cutoff_50p_param_set, 
};

enum 
{
    AMS529HA01_1_9_GAMMA_30CD = 0,
    AMS529HA01_1_9_GAMMA_40CD,        
    //AMS529HA01_1_9_GAMMA_50CD,
    AMS529HA01_1_9_GAMMA_70CD,
    //AMS529HA01_1_9_GAMMA_80CD,
    AMS529HA01_1_9_GAMMA_90CD,
    AMS529HA01_1_9_GAMMA_100CD,
    AMS529HA01_1_9_GAMMA_110CD,    
    AMS529HA01_1_9_GAMMA_120CD,
    AMS529HA01_1_9_GAMMA_130CD,
    AMS529HA01_1_9_GAMMA_140CD,
    AMS529HA01_1_9_GAMMA_150CD,
    AMS529HA01_1_9_GAMMA_160CD,    
    AMS529HA01_1_9_GAMMA_170CD,
    AMS529HA01_1_9_GAMMA_180CD,    
    AMS529HA01_1_9_GAMMA_190CD,    
    AMS529HA01_1_9_GAMMA_200CD,    
    AMS529HA01_1_9_GAMMA_210CD,    
    AMS529HA01_1_9_GAMMA_220CD,    
    AMS529HA01_1_9_GAMMA_230CD,    
    AMS529HA01_1_9_GAMMA_240CD,    
    AMS529HA01_1_9_GAMMA_250CD,
    AMS529HA01_1_9_GAMMA_260CD,
    AMS529HA01_1_9_GAMMA_270CD,
    AMS529HA01_1_9_GAMMA_280CD,
    AMS529HA01_1_9_GAMMA_290CD,
    AMS529HA01_1_9_GAMMA_300CD,
    AMS529HA01_1_9_GAMMA_MAX
};

enum 
{
    AMS529HA01_2_2_GAMMA_30CD = 0,
    AMS529HA01_2_2_GAMMA_40CD,        
    //AMS529HA01_2_2_GAMMA_50CD,
    AMS529HA01_2_2_GAMMA_70CD,
    //AMS529HA01_2_2_GAMMA_80CD,
    AMS529HA01_2_2_GAMMA_90CD,
    AMS529HA01_2_2_GAMMA_100CD,
    AMS529HA01_2_2_GAMMA_110CD,    
    AMS529HA01_2_2_GAMMA_120CD,
    AMS529HA01_2_2_GAMMA_130CD,
    AMS529HA01_2_2_GAMMA_140CD,
    AMS529HA01_2_2_GAMMA_150CD,
    AMS529HA01_2_2_GAMMA_160CD,    
    AMS529HA01_2_2_GAMMA_170CD,
    AMS529HA01_2_2_GAMMA_180CD,    
    AMS529HA01_2_2_GAMMA_190CD,    
    AMS529HA01_2_2_GAMMA_200CD,    
    AMS529HA01_2_2_GAMMA_210CD,    
    AMS529HA01_2_2_GAMMA_220CD,    
    AMS529HA01_2_2_GAMMA_230CD,    
    AMS529HA01_2_2_GAMMA_240CD,    
    AMS529HA01_2_2_GAMMA_250CD,
    AMS529HA01_2_2_GAMMA_260CD,
    AMS529HA01_2_2_GAMMA_270CD,
    AMS529HA01_2_2_GAMMA_280CD,
    AMS529HA01_2_2_GAMMA_290CD,
    AMS529HA01_2_2_GAMMA_300CD,
    AMS529HA01_2_2_GAMMA_MAX
};

const u8 ams529ha01_19gamma_30cd_param_set[] = {
    0xFA, 0x01,    
	0x0F,	0x0F,	0x0F,
	0x5F,	0x5F,	0xFF,
	0xDB,	0xB1,	0xDE,
	0xE3,	0xD5,	0xE0,
	0xCD,	0xC2,	0xC5,
	0xD9,	0xD8,	0xD5,
	0x00,	0x41,	0x00,
	0x3B,	0x00,	0x58,
};

const u8 ams529ha01_19gamma_40cd_param_set[] = {
    0xFA, 0x01,    
	0x0F,	0x0F,	0x0F,
	0x8F,	0x8F,	0xFF,
	0xDA,	0xBB,	0xDB,
	0xE2,	0xD5,	0xDE,
	0xCB,	0xC3,	0xC3,
	0xD9,	0xD8,	0xD5,
	0x00,	0x48,	0x00,
	0x42,	0x00,	0x61,
};

const u8 ams529ha01_19gamma_50cd_param_set[] = {
    0xFA, 0x01,    
	0x0F,	0x0F,	0x0F,
	0xA9,	0xA9,	0xFF,
	0xDC,	0xC2,	0xDA,
	0xE2,	0xD9,	0xDE,
	0xC6,	0xBF,	0xBE,
	0xD9,	0xD8,	0xD5,
	0x00,	0x4F,	0x00,
	0x49,	0x00,	0x6A,
};

const u8 ams529ha01_19gamma_60cd_param_set[] = {
    0xFA, 0x01,    
	0x0F,	0x0F,	0x0F,
	0xDD,	0x0,	0xFF,
	0xDB,	0xC4,	0xD8,
	0xE2,	0xD9,	0xDD,
	0xC7,	0xC2,	0xC0,
	0xD6,	0xD5,	0xD1,
	0x00,	0x54,	0x00,
	0x4E,	0x00,	0x71,
};

const u8 ams529ha01_19gamma_70cd_param_set[] = {
    0xFA, 0x01,    
	0x0F,	0x0F,	0x0F,
	0xE3,	0x0,	0xFF,
	0xDB,	0xC8,	0xD7,
	0xE1,	0xDA,	0xDD,
	0xC6,	0xC1,	0xBE,
	0xD4,	0xD4,	0xCF,
	0x00,	0x59,	0x00,
	0x53,	0x00,	0x78,
};

const u8 ams529ha01_19gamma_80cd_param_set[] = {
    0xFA, 0x01,    
	0x0F,	0x0F,	0x0F,
	0xF4,	0x0,	0xFE,
	0xDA,	0xC9,	0xD6,
	0xE1,	0xDA,	0xDC,
	0xC4,	0xCA,	0xBD,
	0xD5,	0xD4,	0xD0,
	0x00,	0x5D,	0x00,
	0x57,	0x00,	0x7D,
};

const u8 ams529ha01_19gamma_90cd_param_set[] = {
    0xFA, 0x01,    
	0x0F,	0x0F,	0x0F,
	0xF3,	0x81,	0xFA,
	0xD9,	0xCC,	0xD5,
	0xE0,	0xDA,	0xDB,
	0xC3,	0xC0,	0xBC,
	0xD2,	0xD4,	0xCF,
	0x00,	0x62,	0x00,
	0x5B,	0x00,	0x83,
};

const u8 ams529ha01_19gamma_100cd_param_set[] = {
    0xFA, 0x01,    
	0x3F,	0x3F,	0x3F,
	0xF4,	0xA0,	0xF9,
	0xD9,	0xCC,	0xD4,
	0xDF,	0xDB,	0xDB,
	0xC2,	0xC0,	0xBB,
	0xDA,	0xD2,	0xCE,
	0x00,	0x66,	0x00,
	0x5F,	0x00,	0x88,
};

const u8 ams529ha01_19gamma_110cd_param_set[] = {
    0xFA, 0x01,    
    0x0F,	0x0F,	0x0F,
    0xF5,	0xB1,	0xF8,
    0xD8,	0xCC,	0xD3,
    0xDF,	0xDB,	0xDB,
    0xC1,	0xBF,	0xBA,
    0xD0,	0xD1,	0xCC,
    0x00,	0x6A,	0x00,
    0x63,	0x00,	0x8E,
};

const u8 ams529ha01_19gamma_120cd_param_set[] = {
    0xFA, 0x01,    
	0x3F,	0x3F,	0x3F,
	0xF5,	0xB9,	0xF7,
	0xD8,	0xCE,	0xD3,
	0xDF,	0xDA,	0xDA,
	0xC0,	0xBF,	0xBA,
	0xD0,	0xD1,	0xCC,
	0x00,	0x6D,	0x00,
	0x66,	0x00,	0x92,
};

const u8 ams529ha01_19gamma_130cd_param_set[] = {
    0xFA, 0x01,    
    0x3F,	0x3F,	0x3F,
    0xF5,	0xBF,	0xF6,
    0xD8,	0xCE,	0xD3,
    0xDE,	0xDA,	0xD9,
    0xBF,	0xBE,	0xB9,	
    0xCF,	0xCF,	0xCB,
    0x00,	0x71,	0x00,
    0x6A,	0x00,	0x97,
};

const u8 ams529ha01_19gamma_140cd_param_set[] = {
    0xFA, 0x01,    
    0x0F,	0x0F,	0x0F,
    0xF5,	0xC4,	0xF5,
    0xD8,	0xCE,	0xD2,
    0xDD,	0xDA,	0xD9,
    0xBE,	0xBE,	0xB8,
    0xCF,	0xCF,	0xCB,
    0x00,	0x74,	0x00,
    0x6D,	0x00,	0x9B,
};

const u8 ams529ha01_19gamma_150cd_param_set[] = {
    0xFA, 0x01,    
    0x0F,	0x0F,	0x0F,
    0xF5,	0xC8,	0xF4,
    0xD7,	0xCE,	0xD1,
    0xDD,	0xDA,	0xD9,
    0xBE,	0xBE,	0xB8,
    0xCD,	0xCE,	0xC9,
    0x00,	0x78,	0x00,
    0x70,	0x00,	0xA0,
};

const u8 ams529ha01_19gamma_160cd_param_set[] = {
    0xFA, 0x01,    
    0x0F,	0x0F,	0x0F,
    0xF6,	0xCC,	0xF4,
    0xD6,	0xCE,	0xD0,
    0xDE,	0xDA,	0xD9,
    0xBC,	0xBC,	0xB6,
    0xCC,	0xCE,	0xC9,
    0x00,	0x7B,	0x00,
    0xB7,	0x00,	0xA4,
};

const u8 ams529ha01_19gamma_170cd_param_set[] = {
    0xFA, 0x01,    
	0x0F,	0x0F,	0x0F,
	0xF4,	0xCD,	0xF2,
	0xD7,	0xCE,	0xD1,
	0xDC,	0xDA,	0xD8,
	0xBC,	0xBC,	0xB6,
	0xCC,	0xCD,	0xC8,
	0x00,	0x7E,	0x00,
	0x76,	0x00,	0xA8,
};

const u8 ams529ha01_19gamma_180cd_param_set[] = {
    0xFA, 0x01,    
	0x3F,	0x3F,	0x3F,
	0xF6,	0xD1,	0xF3,
	0xD6,	0xCE,	0xD0,
	0xDC,	0xDA,	0xD8,
	0xBB,	0xBB,	0xB5,
	0xCB,	0xCC,	0xC7,
	0x00,	0x81,	0x00,
	0x79,	0x00,	0xAC,
};

const u8 ams529ha01_19gamma_190cd_param_set[] = {
    0xFA, 0x01,    
    0x0F,	0x0F,	0x0F,
    0xF5,	0xD2,	0xF2,
    0xD5,	0xCE,	0xCF,
    0xDC,	0xDA,	0xD8,
    0xBB,	0xBB,	0xB5,
    0xCA,	0xCC,	0xC7,
    0x00,	0x84,	0x00,
    0x7B,	0x00,	0xAF,
};

const u8 ams529ha01_19gamma_200cd_param_set[] = {
    0xFA, 0x01,    
	0x0F,	0x0F,	0x0F,
	0xF6,	0xD4,	0xF2,
	0xD5,	0xCE,	0xCF,
	0xDC,	0xDA,	0xD8,
	0xB9,	0xBA,	0xB4,
	0xCA,	0xCB,	0xC6,
	0x00,	0x87,	0x00,
	0x7E,	0x00,	0xB3,
};

const u8 ams529ha01_19gamma_210cd_param_set[] = {
    0xFA, 0x01,    
	0x0F,	0x0F,	0x0F,
	0xF5,	0xD4,	0xF0,
	0xD6,	0xCF,	0xD0,
	0xDB,	0xD9,	0xD7,
	0xBA,	0xBA,	0xB3,
	0xCA,	0xCA,	0xC6,
	0x00,	0x89,	0x00,
	0x81,	0x00,	0xB7,
};

const u8 ams529ha01_19gamma_220cd_param_set[] = {
    0xFA, 0x01,    
	0x0F,	0x0F,	0x0F,
	0xF5,	0xD4,	0xEF,
	0xD6,	0xCF,	0xC0,
	0xDA,	0xD9,	0xD6,
	0xBA,	0xBA,	0xB4,
	0xC9,	0xCA,	0xC5,
	0x00,	0x8C,	0x00,
	0x83,	0x00,	0xBA,
};

const u8 ams529ha01_19gamma_230cd_param_set[] = {
    0xFA, 0x01,
	0x0F,	0x0F,	0x0F,
	0xF5,	0xD7,	0xF0,
	0xD5,	0xCD,	0xCE,
	0xDB,	0xDA,	0xD7,
	0xB9,	0xB9,	0xB3,
	0xC8,	0xC9,	0xC4,
	0x00,	0x8F,	0x00,
	0x86,	0x00,	0xBE,
};

const u8 ams529ha01_19gamma_240cd_param_set[] = {
    0xFA, 0x01,    
    0x0F,	0x0F,	0x0F,
    0xF5,	0xD7,	0xEF,
    0xD5,	0xCF,	0xCF,
    0xDA,	0xD8,	0xD6,
    0xB9,	0xB9,	0xB2,
    0xC8,	0xC9,	0xC4,
    0x00,	0x91,	0x00,
    0x88,	0x00,	0xC1,
};

const u8 ams529ha01_19gamma_250cd_param_set[] = {
    0xFA, 0x01,    
	0x0F,	0x0F,	0x0F,
	0xF5,	0xD9,	0xEF,
	0xD4,	0xCE,	0xCF,
	0xDB,	0xD9,	0xD6,
	0xB7,	0xB8,	0xB1,
	0xC9,	0xC9,	0xC4,
	0x00,	0x93,	0x00,
	0x8A,	0x00,	0xC4,
};

const u8 ams529ha01_19gamma_260cd_param_set[] = {
    0xFA, 0x01,    
    0x0F,	0x0F,	0x0F,
    0xF5,	0xD9,	0xEE,
    0xD4,	0xCF,	0xCF,
    0xDB,	0xD9,	0xD6,
    0xB6,	0xB7,	0xB0,
    0xC9,	0xC9,	0xC4,
    0x00,	0x95,	0x00,
    0x8C,	0x00,	0xC7,
};

const u8 ams529ha01_19gamma_270cd_param_set[] = {
    0xFA, 0x01,    
    0x0F,	0x0F,	0x0F,
    0xF5,	0xD9,	0xEE,
    0xD3,	0xCE,	0xCD,	
    0xDB,	0xD9,	0xD6,
    0xB6,	0xB7,	0xB0,
    0xC9,	0xC9,	0xC4,
    0x00,	0x97,	0x00,
    0x8E,	0x00,	0xCA,
};

const u8 ams529ha01_19gamma_280cd_param_set[] = {
    0xFA, 0x01,    
	0x3F,	0x3F,	0x3F,
	0xF6,	0xDA,	0xED,
	0xD3,	0xCF,	0xCF,
	0xD9,	0xD8,	0xD5,
	0xB6,	0xB7,	0xB0,
	0xC8,	0xC9,	0xC3,
	0x00,	0x9A,	0x00,
	0x90,	0x00,	0xCD,	
};

const u8 ams529ha01_19gamma_290cd_param_set[] = {
    0xFA, 0x01,    
    0x0F,	0x0F,	0x0F,
    0xF4,	0xDA,	0xED,
    0xD4,	0xCF,	0xCE,
    0xDA,	0xD8,	0xD5,
    0xB5,	0xB6,	0xAF,
    0xC9,	0xC9,	0xC4,
    0x00,	0x9B,	0x00,
    0x92,	0x00,	0xCF,
};

const u8 ams529ha01_19gamma_300cd_param_set[] = {
    0xFA, 0x01,    
    0x0F,	0x0F,	0x0F,
    0xF4,	0xDB,	0xED,
    0xD2,	0xCE,	0xCC,
    0xDA,	0xD8,	0xD5,
    0xB5,	0xB6,	0xAF,
    0xC9,	0xC9,	0xC4,
    0x00,	0x9D,	0x00,
    0x94,	0x00,	0xD2,
};

const u8 ams529ha01_22gamma_30cd_param_set[] = { 
    0xFA, 0x01,
    0x0F,	0x0F,	0x0F,
    0xE1,	0x19,	0xFF,
    0xD3,	0x69,	0xDC,
    0xE1,	0xCE,	0xDE,
    0xC5,	0xBA,	0xBD,
    0xD4,	0xD3,	0xD0,
    0x00,	0x40,	0x00,
    0x3B,	0x00,	0x58,
};

const u8 ams529ha01_22gamma_40cd_param_set[] = { 
    0xFA, 0x01,
    0x0F,	0x0F,	0x0F,
    0xE1,	0x19,	0xFF,
    0xD5,	0x97,	0xD9,
    0xE0,	0xD1,	0xDC,
    0xC3,	0xBA,	0xBB,
    0xD2,	0xD1,	0xCE,
    0x00,	0x48,	0x00,
    0x43,	0x00,	0x62,
};

const u8 ams529ha01_22gamma_50cd_param_set[] = { 
    0xFA, 0x01,
    0x0F,	0x0F,	0x0F,
    0xE1,	0x19,	0xFF,
    0xD5,	0xA7,	0xD7,
    0xDF,	0xD1,	0xDA,
    0xC1,	0xBA,	0xB9,
    0xD1,	0xD1,	0xCD,
    0x00,	0x4E,	0x00,
    0x49,	0x00,	0x6A,
};

const u8 ams529ha01_22gamma_60cd_param_set[] = { 
    0xFA, 0x01,
    0x0F,	0x0F,	0x0F,
    0xE1,	0x19,	0xFF,
    0xD6,	0xB1,	0xD5,
    0xDE,	0xD3,	0xD9,
    0xBF,	0xBA,	0xB8,
    0xD1,	0xD0,	0xCC,
    0x00,	0x53,	0x00,
    0x4E,	0x00,	0x71,
};

const u8 ams529ha01_22gamma_70cd_param_set[] = { 
    0xFA, 0x01,
    0x0F,	0x0F,	0x0F,
    0xE1,	0x19,	0xFF,
    0xD6,	0xB6,	0xD4,
    0xDF,	0xD5,	0xDA,
    0xBE,	0xB9,	0xB6,
    0xCE,	0xCF,	0xCA,
    0x00,	0x59,	0x00,
    0x53,	0x00,	0x78,
};

const u8 ams529ha01_22gamma_80cd_param_set[] = { 
    0xFA, 0x01,
    0x0F,	0x0F,	0x0F,
    0xE5,	0x1B,	0xFF,
    0xD9,	0xBF,	0xD6,
    0xDE,	0xD5,	0xD9,
    0xBD,	0xB9,	0xB5,
    0xCE,	0xCD,	0xC9,
    0x00,	0x5D,	0x00,
    0x58,	0x00,	0x7E,
};

const u8 ams529ha01_22gamma_90cd_param_set[] = { 
    0xFA, 0x01,
   0x0F,	0x0F,	0x0F,
   0xE8,	0x1C,	0xFF,
   0xD7,	0xBF,	0xD3,
   0xDD,	0xD5,	0xD9,
   0xBC,	0xB8,	0xB3,
   0xCC,	0xCD,	0xC8,
   0x00,	0x62,	0x00,
   0x5C,	0x00,	0x84,
};

const u8 ams529ha01_22gamma_100cd_param_set[] = { 
    0xFA, 0x01,
    0x0F,	0x0F,	0x0F,
    0xEC,	0x1D,	0xFF,
    0xD5,	0xBF,	0xD1,
    0xDD,	0xD5,	0xD8,
    0xBB,	0xB8,	0xB3,
    0xCB,	0xCC,	0xC7,
    0x00,	0x66,	0x00,
    0x60,	0x00,	0x89,
};

const u8 ams529ha01_22gamma_110cd_param_set[] = { 
    0xFA, 0x01,
    0x0F,	0x0F,	0x0F,
    0xEE,	0x1F,	0xFF,
    0xD5,	0xBF,	0xD0,
    0xDC,	0xD5,	0xD7,
    0xBB,	0xB8,	0xB3,
    0xC9,	0xCA,	0xC5,
    0x00,	0x6A,	0x00,
    0x64,	0x00,	0x8E,
};

const u8 ams529ha01_22gamma_120cd_param_set[] = { 
    0xFA, 0x01,
    0x0F,	0x0F,	0x0F,
    0xF3,	0x21,	0xFF,
    0xD6,	0xC3,	0xD1,
    0xDB,	0xD5,	0xD6,
    0xBA,	0xB7,	0xB2,
    0xC8,	0xCA,	0xC4,
    0x00,	0x6E,	0x00,
    0x67,	0x00,	0x93,
};   

const u8 ams529ha01_22gamma_130cd_param_set[] = { 
    0xFA, 0x01,
    0x0F,	0x0F,	0x0F,
    0xF3,	0x24,	0xFE,
    0xD5,	0xC3,	0xD0,
    0xDB,	0xD5,	0xD6,
    0xB8,	0xB6,	0xB0,
    0xC9,	0xCA,	0xC5,
    0x00,	0x71,	0x00,
    0x6A,	0x00,	0x97,
};   

const u8 ams529ha01_22gamma_140cd_param_set[] = { 
    0xFA, 0x01,
    0x0F,	0x0F,	0x0F,
    0xF2,	0x27,	0xFC,
    0xD5,	0xC3,	0xCF,
    0xDA,	0xD5,	0xD5,
    0xB8,	0xB6,	0xB1,
    0xC7,	0xC8,	0xC3,
    0x00,	0x75,	0x00,
    0x6E,	0x00,	0x9C,
};

const u8 ams529ha01_22gamma_150cd_param_set[] = { 
    0xFA, 0x01,
    0x0F,	0x0F,	0x0F,
    0xF2,	0x2A,	0xFB,
    0xD4,	0xC5,	0xCF,
    0xDB,	0xD5,	0xD5,
    0xB7,	0xB6,	0xB0,
    0xC6,	0xC7,	0xC2,
    0x00,	0x78,	0x00,
    0x71,	0x00,	0xA0,
};

const u8 ams529ha01_22gamma_160cd_param_set[] = { 
    0xFA, 0x01,
    0x0F,	0x0F,	0x0F,
    0xEF,	0x2C,	0xF8,
    0xD4,	0xC5,	0xCE,
    0xDA,	0xD5,	0xD5,
    0xB6,	0xB5,	0xAF,
    0xC6,	0xC7,	0xC1,
    0x00,	0x7B,	0x00,
    0x74,	0x00,	0xA5,
};

const u8 ams529ha01_22gamma_170cd_param_set[] = { 
    0xFA, 0x01,
    0x0F,	0x0F,	0x0F,
    0xEF,	0x3A,	0xF7,
    0xD4,	0xC5,	0xCE,
    0xDA,	0xD5,	0xD4,
    0xB6,	0xB5,	0xAF,
    0xC5,	0xC6,	0xC1,
    0x00,	0x7E,	0x00,
    0x77,	0x00,	0xA8,
};

const u8 ams529ha01_22gamma_180cd_param_set[] = { 
    0xFA, 0x01,
	0x0F,	0x0F,	0x0F,
	0xEE,	0x4F,	0xF6,
	0xD4,	0xC5,	0xCD,
	0xD9,	0xD5,	0xD4,
	0xB5,	0xB4,	0xAE,
	0xC3,	0xC5,	0xBF,
	0x00,	0x82,	0x00,
	0x7A,	0x00,	0xAD,
};

const u8 ams529ha01_22gamma_190cd_param_set[] = { 
    0xFA, 0x01,
    0x0F,	0x0F,	0x0F,
    0xED,	0x6A,	0xF4,
    0xD3,	0xC5,	0xCC,
    0xD9,	0xD5,	0xD5,
    0xB5,	0xB4,	0xAD,
    0xC3,	0xC5,	0xBF,
    0x00,	0x84,	0x00,
    0x7C,	0x00,	0xB0,
};

const u8 ams529ha01_22gamma_200cd_param_set[] = { 
    0xFA, 0x01,
    0x0F,	0x0F,	0x0F,
    0xED,	0x7D,	0xF3,
    0xD4,	0xC7,	0xCE,
    0xD8,	0xD4,	0xD3,
    0xB3,	0xB3,	0xAC,
    0xC3,	0xC4,	0xBE,
    0x00,	0x87,	0x00,
    0x7F,	0x00,	0xB4,
};

const u8 ams529ha01_22gamma_210cd_param_set[] = { 
    0xFA, 0x01,
    0x0F,	0x0F,	0x0F,
    0xDE,	0x8D,	0xF2,
    0xD3,	0xC7,	0xCD,
    0xD8,	0xD4,	0xD3,
    0xB3,	0xB3,	0xAC,
    0xC2,	0xC3,	0xBD,
    0x00,	0x8A,	0x00,
    0x82,	0x00,	0xB8,
};

const u8 ams529ha01_22gamma_220cd_param_set[] = { 
    0xFA, 0x01,
	0x0F,	0x0F,	0x0F,
	0xEE,	0x92,	0xF2,
	0xD2,	0xC5,	0xCB,
	0xD9,	0xD6,	0xD4,
	0xB1,	0xB1,	0xAA,
	0xC3,	0xC4,	0xBE,
	0x00,	0x8C,	0x00,
	0x84,	0x00,	0xBB,
};

const u8 ams529ha01_22gamma_230cd_param_set[] = { 
    0xFA, 0x01,
    0x0F,	0x0F,	0x0F,
    0xEC,	0x98,	0xF0,
    0xD3,	0xC7,	0xCC,
    0xD9,	0xD6,	0xD4,
    0xB1,	0xB1,	0xAA,
    0xC1,	0xC2,	0xBD,
    0x00,	0x8F,	0x00,
    0x87,	0x00,	0xBE,
};

const u8 ams529ha01_22gamma_240cd_param_set[] = { 
    0xFA, 0x01,
    0x0F,	0x0F,	0x0F,
    0xEE,	0xA4,	0xF1,
    0xD2,	0xC7,	0xCB,
    0xD8,	0xD5,	0xD3,
    0xB1,	0xB1,	0xAA,
    0xC0,	0xC2,	0xBC,
    0x00,	0x92,	0x00,
    0x89,	0x00,	0xC2,
};

const u8 ams529ha01_22gamma_250cd_param_set[] = { 
    0xFA, 0x01,
	0x0F,	0x0F,	0x0F,
	0xEE,	0xA8,	0xF0,
	0xD2,	0xC7,	0xCB,
	0xD7,	0xD5,	0xD3,
	0xB0,	0xB0,	0xA9,
	0xC1,	0xC2,	0xBC,
	0x00,	0x94,	0x00,
	0x8B,	0x00,	0xC5,
};

const u8 ams529ha01_22gamma_260cd_param_set[] = { 
    0xFA, 0x01,
	0x0F,	0x0F,	0x0F,
	0xED,	0xAC,	0xEF,
	0xD2,	0xC7,	0xCB,
	0xD7,	0xD4,	0xD2,
	0xB0,	0xB0,	0xA9,
	0xC0,	0xC2,	0xBC,
	0x00,	0x96,	0x00,
	0x8D,	0x00,	0xC7,
};

const u8 ams529ha01_22gamma_270cd_param_set[] = { 
    0xFA, 0x01,
	0x0F,	0x0F,	0x0F,
	0xED,	0xAC,	0xEE,
	0xD1,	0xC7,	0xCA,
	0xD8,	0xD5,	0xD3,
	0xAE,	0xAF,	0xA8,
	0xC1,	0xC2,	0xBC,
	0x00,	0x98,	0x00,
	0x8F,	0x00,	0xCA,
}; 

const u8 ams529ha01_22gamma_280cd_param_set[] = { 
    0xFA, 0x01,
    0x0F,	0x0F,	0x0F,
    0xED,	0xAC,	0xEE,
    0xD0,	0xC7,	0xCA,
    0xD7,	0xD5,	0xD2,
    0xAE,	0xAE,	0xA7,
    0xC1,	0xC2,	0xBC,
    0x00,	0x9A,	0x00,
    0x91,	0x00,	0xCD,
}; 

const u8 ams529ha01_22gamma_290cd_param_set[] = { 
	0xFA, 0x01,
	0x0F,	0x0F,	0x0F,
	0xED,	0xB4,	0xED,
	0xD1,	0xC7,	0xCA,
	0xD5,	0xD4,	0xD1,
	0xAF,	0xAF,	0xA8,
	0xC0,	0xC1,	0xBB,
	0x00,	0x9C,	0x00,
	0x93,	0x00,	0xD0,
}; 

const u8 ams529ha01_22gamma_300cd_param_set[] = { 
    0xFA, 0x01,
	0x0F,	0x0F,	0x0F,
	0xEE,	0xB4,	0xEE,
	0xCB,	0xC2,	0xC4,
	0xDA,	0xD7,	0xD5,
	0xAE,	0xAF,	0xA7,
	0xC0,	0xC1,	0xBB,
	0x00,	0x9F,	0x00,
	0x95,	0x00,	0xD4,
};                          

const u8 * ams529ha01_19gamma_set_tbl[AMS529HA01_1_9_GAMMA_MAX] = {        
    ams529ha01_19gamma_30cd_param_set,
    ams529ha01_19gamma_40cd_param_set,        
    ams529ha01_19gamma_70cd_param_set,
    ams529ha01_19gamma_90cd_param_set,
    ams529ha01_19gamma_100cd_param_set,
    ams529ha01_19gamma_110cd_param_set,
    ams529ha01_19gamma_120cd_param_set,
    ams529ha01_19gamma_130cd_param_set,
    ams529ha01_19gamma_140cd_param_set,
    ams529ha01_19gamma_150cd_param_set,
    ams529ha01_19gamma_160cd_param_set,
    ams529ha01_19gamma_170cd_param_set,
    ams529ha01_19gamma_180cd_param_set,
    ams529ha01_19gamma_190cd_param_set,
    ams529ha01_19gamma_200cd_param_set,
    ams529ha01_19gamma_210cd_param_set,
    ams529ha01_19gamma_220cd_param_set,
    ams529ha01_19gamma_230cd_param_set,    
    ams529ha01_19gamma_240cd_param_set,
    ams529ha01_19gamma_250cd_param_set,
    ams529ha01_19gamma_260cd_param_set,
    ams529ha01_19gamma_270cd_param_set,
    ams529ha01_19gamma_280cd_param_set,
    ams529ha01_19gamma_290cd_param_set,
    ams529ha01_19gamma_300cd_param_set,
};

const u8 * ams529ha01_22gamma_set_tbl[AMS529HA01_2_2_GAMMA_MAX] = {        
    ams529ha01_22gamma_30cd_param_set,
    ams529ha01_22gamma_40cd_param_set,
	//ams529ha01_22gamma_50cd_param_set,
    ams529ha01_22gamma_70cd_param_set,
    //ams529ha01_22gamma_80cd_param_set,
    ams529ha01_22gamma_90cd_param_set,
    ams529ha01_22gamma_100cd_param_set,
    ams529ha01_22gamma_110cd_param_set,
    ams529ha01_22gamma_120cd_param_set,
    ams529ha01_22gamma_130cd_param_set,
    ams529ha01_22gamma_140cd_param_set,
    ams529ha01_22gamma_150cd_param_set,
    ams529ha01_22gamma_160cd_param_set,
    ams529ha01_22gamma_170cd_param_set,
    ams529ha01_22gamma_180cd_param_set,
    ams529ha01_22gamma_190cd_param_set,
    ams529ha01_22gamma_200cd_param_set,
    ams529ha01_22gamma_210cd_param_set,
    ams529ha01_22gamma_220cd_param_set,
    ams529ha01_22gamma_230cd_param_set,    
    ams529ha01_22gamma_240cd_param_set,
    ams529ha01_22gamma_250cd_param_set,
    ams529ha01_22gamma_260cd_param_set,
    ams529ha01_22gamma_270cd_param_set,
    ams529ha01_22gamma_280cd_param_set,
    ams529ha01_22gamma_290cd_param_set,
    ams529ha01_22gamma_300cd_param_set,
};

/* PANEL INITIALIZE CMD SET */
const u8 s6e8aa0_init_pre1[] = {
	0xF0,
	0x5A,
	0x5A,
};

const u8 s6e8aa0_init_pre2[] = {
	0xFC,
	0x5A,
	0x5A,
};

const u8 s6e8aa0_init_panel[] = {
	0xF8,
	0x25,
	0x34,
	0x00,
	0x00,
	0x00,
	0x8D,
	0x00,
	0x43,
	0x6E,
	0x10,
	0x27,
	0x00,
	0x00,
	0x10,
	0x00,
	0x00,
	0x20,
	0x02,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x02,
	0x08,
	0x08,
	0x23,
	0x23,
	0xC0,
	0xC1,
	0x01,
	0x81,
	0xC1,
	0x00,
	0xC8,
	0xC1,
	0xD3,
	0x01,
};

const u8 s6e8aa0_init_display[] = {
	0xF2,
	0x80,
	0x03,
	0x0D,
};

const u8 s6e8aa0_init_post0[] = {
	0xF6,
	0x00,
	0x02,
	0x00,
};

const u8 s6e8aa0_init_elvss[] = {
	0xB1,
	0x03,
	0x00,
};

const u8 s6e8aa0_init_post1[] = {
	0xB6,
	0x0C,
	0x02,
	0x03,
	0x32,
	0xFF,
	0x44,
	0x44,
	0xC0,
	0x00,
};

const u8 s6e8aa0_init_post2[] = {
	0xD9,
	0x14,
	0x40,
	0x0C,
	0xCB,
	0xCE,
	0x6E,
	0xC4,
	0x0F,
	0x40,
	0x40,
	0x18, // ELVSS Apply 0x18, 0xCE
	0x00,
	0x60,
	0x19,
};

const u8 s6e8aa0_init_post3[] = {
	0xF4,
	0xCF,
	0x0A,
	0x12,
	0x10,
	0x19,
	0x33,
	0x02,
};

/* DSI Command Virtual channel */
#define TCH 1

/*AMS529HA01 TIMINGS */
#define AMS529_WIDTH		800
#define AMS529_HEIGHT		1280
#define AMS529_PCLK			82868

#define AMS529_HBP			134 
#define AMS529_HFP			130 
#define AMS529_HSW			4 
#define AMS529_VBP			2
#define AMS529_VFP			13
#define AMS529_VSW			1

#define DSI_HSA			1 
#define DSI_HFP			97 
#define DSI_HBP			101 
#define DSI_VSA			1
#define DSI_VFP			13
#define DSI_VBP			2

#define GAMMASET_CONTROL //for 1.9/2.2 gamma control from platform
#define ACL_ENABLE
#define DIM_BL			20
#define MIN_BL			30
#define MAX_BL			255
#define MAX_GAMMA_VALUE		24
#define MIN_BRIGHTNESS		0
#define MAX_BRIGHTNESS		255
#define MAX_GAMMA_LEVEL		25

#define GAMMA_PARAM_SET_DATA_COUNT       26
#define ACL_CUTOFF_PARAM_SET_DATA_COUNT  29

