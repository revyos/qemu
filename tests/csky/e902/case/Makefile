SRC = $(wildcard *.c)
OBJFILE = $(SRC:%.c=%.elf)
BOARD_DIR = ../../board/smartl/e902
INCLUDE = -I../../include -I$(BOARD_DIR)
CFLAGS = -g -O0
all: case

case: $(OBJFILE)

%.elf: %.c
	@echo "  CC    case/$*.elf"
	@riscv32-unknown-elf-gcc $(CFLAGS) $(INCLUDE) $(BOARD_DIR)/uart.o $(BOARD_DIR)/crt0.o  -T$(BOARD_DIR)/ckcpu.ld -nostartfiles -lgcc $*.c -o $*.elf
	@riscv32-unknown-elf-objdump -S $*.elf > $*.asm
clean:
	rm -rf  *.o *.a *.asm *.elf
