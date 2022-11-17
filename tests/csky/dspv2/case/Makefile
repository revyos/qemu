SRC = $(wildcard *.c)
OBJFILE = $(SRC:%.c=%.elf)
BOARD_DIR = ../../board/smartl/ck803s
INCLUDE = -I../../include -I$(BOARD_DIR)
CFLAGS = -g2 -O2 -mcpu=ck803efr2 -msoft-float
all: case

case: $(OBJFILE)

dspv2_insn.o: dspv2_insn.S dspv2_insn.h
	@echo "  CC    case/dspv2_insn.o"
	@csky-abiv2-elf-gcc $(CFLAGS) -c $(INCLUDE) -o dspv2_insn.o  dspv2_insn.S

%.elf: %.c sample_array.h dspv2_insn.o
	@echo "  CC    case/$*.elf"
	@csky-abiv2-elf-gcc $(CFLAGS) $(INCLUDE) $(BOARD_DIR)/uart.o $(BOARD_DIR)/crt0.o dspv2_insn.o -T$(BOARD_DIR)/ckcpu.ld -nostartfiles -lgcc $< -o $*.elf
	@#csky-abiv2-elf-objdump -S $@.elf > $@.asm
clean:
	rm -rf  *.o *.a *.asm *.elf
