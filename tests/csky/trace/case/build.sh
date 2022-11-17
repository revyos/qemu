#! /bin/sh

make clean
make

echo "  CC   client.elf"
rm trace-client.elf
gcc trace-client.c -o client.elf
