for i in $(find . | grep .ko | grep './')
do
        echo $i
/home/sarthak/Downloads/Toolchains/arm-2009q3/bin/arm-none-linux-gnueabi-strip --strip-unneeded $i
done
