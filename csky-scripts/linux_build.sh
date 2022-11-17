#!/bin/bash

function build_v1()
{
	mkdir build_v1
	cd build_v1
	../configure --target-list="cskyv1-softmmu cskyv1-linux-user" --disable-vnc --enable-modules --enable-dynsoc --prefix=$1
	make
	cd -
}

function build_v1eb()
{
	mkdir build_v1eb
	cd build_v1eb
	../configure --target-list="cskyv1eb-softmmu cskyv1eb-linux-user" --disable-vnc --enable-modules --enable-dynsoc --prefix=$1
	make
	cd -
}

function build_v2()
{
	mkdir build_v2
	cd build_v2
	../configure --target-list="cskyv2-softmmu cskyv2-linux-user" --disable-vnc --enable-modules --enable-dynsoc --prefix=$1
	make
	cd -
}

function build_v2eb()
{
	mkdir build_v2eb
	cd build_v2eb
	../configure --target-list="cskyv2eb-softmmu cskyv2eb-linux-user" --disable-vnc --enable-modules --enable-dynsoc --prefix=$1
	make
	cd -
}

function build_cskysim()
{
	cd cskysim
	make cskysim
	cd -
}

function build_rv32()
{
	mkdir build_rv32
	cd build_rv32
	../configure --target-list="riscv32-softmmu riscv32-linux-user" --disable-vnc --enable-modules --enable-dynsoc --prefix=$1
	make
	cd -
}

function build_rv64()
{
	mkdir build_rv64
	cd build_rv64
	../configure --target-list="riscv64-softmmu riscv64-linux-user" --disable-vnc --enable-modules --enable-dynsoc --prefix=$1
	make
	cd -
}

function install()
{
	cd build_v2
	make install
	cd -
	cp cskysim/cskysim                                  $1/bin/
	cp cskysim/soccfg/                                  $1/soccfg -r
	cp build_v2eb/cskyv2eb-softmmu/qemu-system-cskyv2eb $1/bin/
	cp build_v2eb/cskyv2eb-linux-user/qemu-cskyv2eb     $1/bin/
	cp build_v1/cskyv1-softmmu/qemu-system-cskyv1       $1/bin/
	cp build_v1/cskyv1-linux-user/qemu-cskyv1           $1/bin/
	cp build_v1eb/cskyv1eb-softmmu/qemu-system-cskyv1eb $1/bin/
	cp build_v1eb/cskyv1eb-linux-user/qemu-cskyv1eb     $1/bin/
	cp build_rv32/riscv32-softmmu/qemu-system-riscv32   $1/bin/
	cp build_rv64/riscv64-softmmu/qemu-system-riscv64   $1/bin/
}

if [ $# -eq 0 ]
then
	printf "linux_build.sh build/install\n"
	exit
fi

if [ $1 == "build" ]
then
	build_v1     /usr/local
	build_v1eb   /usr/local
	build_v2     /usr/local
	build_v2eb   /usr/local
	build_rv32   /usr/local
	build_rv64   /usr/local
	build_cskysim
elif [ $1 == "install" ]
then
	build_v1       $2
	build_v1eb     $2
	build_v2       $2
	build_v2eb     $2
	build_rv32     $2
	build_rv64     $2
	build_cskysim
	install        $2
else
	printf "linux_build.sh build/install\n"
fi
