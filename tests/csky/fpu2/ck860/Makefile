SRC = $(wildcard *.c)
OBJFILE = $(SRC:%.c=%.elf)
INCLUDE = -I../../include
CFLAGS = -g2 -O2 -mcpu=ck860f -static -mhard-float -mfpu=fpv3
all: case

case: $(OBJFILE)

%.elf: %.c fpu_structs.h
	@echo "  CC    ck860/$*.elf"
	@csky-abiv2-linux-gcc $(CFLAGS) $(INCLUDE) $< -o $*.elf
	@#csky-abiv2-elf-objdump -S $*.elf > $*.asm
clean:
	rm -rf  *.o *.a *.asm *.elf *.s
