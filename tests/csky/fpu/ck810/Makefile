SRC = $(wildcard *.c)
OBJFILE = $(SRC:%.c=%.elf)
INCLUDE = -I../../include
CFLAGS = -g2 -O0 -mcpu=ck810eft -static
all: case

case: $(OBJFILE)

%.elf: %.c fpu_structs.h
	@echo "  CC    case/$*.elf"
	@ csky-abiv2-linux-gcc $(CFLAGS) $(INCLUDE)  $*.c -o $*.elf
	@#csky-abiv2-elf-objdump -S $*.elf > $*.asm
clean:
	rm -rf  *.o *.a *.asm *.elf *.s
