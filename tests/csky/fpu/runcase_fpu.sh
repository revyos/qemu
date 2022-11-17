#!/bin/bash

num_total=0
num_fail=0

make 803
cd ck803
for file in *.elf
do
    if [[ $file =~ "denormalize" ]]
    then
        cmd="qemu-system-cskyv2 -machine smartl -cpu ck803efr1 -csky-extend denormal=on -kernel $file -nographic"
    else
        cmd="qemu-system-cskyv2 -machine smartl -cpu ck803efr1 -kernel $file -nographic"
    fi
    $cmd
    if [ $? -ne 0 ]
    then
        num_fail=`expr $num_fail + 1`
    fi
    num_total=`expr $num_total + 1`
done
cd ../

make 810
cd ck810
for file in *.elf
do
    cmd="qemu-cskyv2 $file"
    $cmd
    if [ $? -ne 0 ]
    then
        num_fail=`expr $num_fail + 1`
    fi
    num_total=`expr $num_total + 1`
done
cd ../

make 610
cd ck610
for file in *.elf
do
    cmd2="qemu-cskyv1 $file"
    $cmd2
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
