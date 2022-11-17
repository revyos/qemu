#!/bin/sh

num_total=0
num_fail=0

make all 
 
for file in boot/*.elf mic/*.elf mptimer/*.elf
do
    cmd="qemu-system-cskyv2 -machine mp860 -smp 4 -kernel $file -nographic"
    $cmd
    if [ $? -ne 0 ]
    then
        num_fail=`expr $num_fail + 1`
    fi
    num_total=`expr $num_total + 1`
done

echo "\n------sumary------"
echo "Total  case: $num_total"
echo "Failed case: $num_fail"
echo "------------------\n"

make clean
