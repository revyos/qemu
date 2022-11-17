SRC = $(wildcard *.c)
OBJFILE = $(SRC:%.c=%.elf)
BOARD_DIR = ../../board/smartl/ck803s
INCLUDE = -I../../include -I$(BOARD_DIR)
CFLAGS = -g2 -O2 -mcpu=ck803efr1 -mhard-float
all: case

case: $(OBJFILE)

fpu_insn.o: fpu_insn.S fpu_insn.h
	@echo "  CC    case/fpu_insn.o"
	@csky-abiv2-elf-gcc $(CFLAGS) -c $(INCLUDE) -o fpu_insn.o  fpu_insn.S

%.elf: %.c fpu_insn.o
	@echo "  CC    case/$*.elf"
	@csky-abiv2-elf-gcc $(CFLAGS) $(INCLUDE) $(BOARD_DIR)/uart.o $(BOARD_DIR)/crt0.o fpu_insn.o -T$(BOARD_DIR)/ckcpu.ld -nostartfiles -lgcc $*.c -o $*.elf
	@#csky-abiv2-elf-objdump -S $*.elf > $*.asm
clean:
	rm -rf  *.o *.a *.asm *.elf
