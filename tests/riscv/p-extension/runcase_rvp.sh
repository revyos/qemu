#!/bin/sh

num_total=0
num_fail=0

make RV32=y
cd case
for file in *.elf
do
    cmd="qemu-system-riscv32 -M smartl -cpu any -kernel $file -nographic"
    $cmd
    if [ $? -ne 0 ]
    then
        num_fail=`expr $num_fail + 1`
    fi
    num_total=`expr $num_total + 1`
done
cd ..
make clean

make RV64=y
cd case
for file in *.elf
do
    cmd="qemu-riscv64 $file"
    $cmd
    if [ $? -ne 0 ]
    then
        num_fail=`expr $num_fail + 1`
    fi
    num_total=`expr $num_total + 1`
done

cd rv64
for file in *.elf
do
    cmd="qemu-riscv64 $file"
    $cmd
    if [ $? -ne 0 ]
    then
        num_fail=`expr $num_fail + 1`
    fi
    num_total=`expr $num_total + 1`
done

echo "\n------summary------"
echo "Total  case: $num_total"
echo "Failed case: $num_fail"
echo "------------------\n"

cd ../..
make clean
