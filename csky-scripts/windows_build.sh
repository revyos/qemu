#!/bin/sh

mkdir build
cd build
mkdir $1
../configure --target-list="cskyv2-softmmu cskyv1-softmmu cskyv2eb-softmmu cskyv1eb-softmmu riscv32-softmmu riscv64-softmmu" --disable-vnc --disable-werror --enable-modules --enable-dynsoc --disable-capstone --python=/usr/bin/python3 --prefix=$1
make
make install
cp ui-gtk.dll $1

make cskysim
cp ../cskysim/soccfg $1 -r
cp ../cskysim/cskysim_w32.exe $1/cskysim.exe

cd $1
rm openbios-*
rm *.bin
rm *.rom
rm *.dtb
rm s390-ccw.img
rm u-boot.e500
rm skiboot.lid
