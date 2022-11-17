#!/bin/bash

num_total=0
num_fail=0


make 860
cd ck860
for file in *.elf
do
    if [[ $file =~ "denormalize" ]]
    then
        cmd="qemu-cskyv2 -cpu ck860f -csky-extend denormal=on $file"
    else
        cmd="qemu-cskyv2 -cpu ck860f $file"
    fi
    $cmd
    if [ $? -ne 0 ]
    then
        num_fail=`expr $num_fail + 1`
    fi
    num_total=`expr $num_total + 1`
done


echo -e "\n------summary------"
echo "Total  case: $num_total"
echo "Failed case: $num_fail"
echo -e "------------------\n"

cd ..
make clean
