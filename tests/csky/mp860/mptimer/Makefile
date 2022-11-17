SRC = $(wildcard *.c)
SRS = $(wildcard *.S)
OBJFILE = $(SRS:%.S=%.o) $(SRC:%.c=%)
BOARD_DIR = ../smartl
INCLUDE = -I. -I../../include -I$(BOARD_DIR)
CFLAGS = -g2 -O0 -mcpu=ck803efr1 -msoft-float

all: case

case: $(OBJFILE)

%.o: %.S
	@echo "  CC    case/$@"
	@csky-abiv2-elf-gcc $(CFLAGS) -c $(INCLUDE) -o $@  $<

%: %.c
	@echo "  CC    case/$@.o"
	@csky-abiv2-elf-gcc $(CFLAGS) -c $(INCLUDE) -O0 -o $@.o  $<
	@echo "  CC    case/$@.elf"
	@csky-abiv2-elf-gcc $(CFLAGS) $(BOARD_DIR)/uart.o crt0.o micfunc.o -T$(BOARD_DIR)/ckcpu.ld -nostartfiles -lgcc $@.o -o $@.elf
	@#csky-abiv2-elf-objdump -S $@.elf > $@.asm
clean:
	rm -rf  *.o *.a *.asm *.elf
