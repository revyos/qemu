SRC = $(wildcard *.c)
SRS = $(wildcard *.S)
OBJFILE = $(SRS:%.S=%.o) $(SRC:%.c=%.o)
BOARD_DIR = ../../board/smartl/ck803s
INCLUDE = -I../../include -I$(BOARD_DIR)
#CFLAGS=-g -O2 -mcpu=ck860 -msoft-float -Wa,-mcpu=ck860fv -DVDSP_FLOAT
#CFLAGS = -g -O2 -mcpu=ck803r2 -msoft-float -Wa,-mcpu=ck803vr3
all: case

case: $(OBJFILE)

%.o: %.S
	@echo "  CC    case/$@"
	@csky-abiv2-elf-gcc $(CFLAGS) -c $(INCLUDE) -o $@  $<

%.o: %.c
	@echo "  CC    case/$@"
	@csky-abiv2-elf-gcc $(CFLAGS) -c $(INCLUDE) -o $@  $<
	@echo "  CC    case/$*.elf"
	@csky-abiv2-elf-gcc $(CFLAGS) $(BOARD_DIR)/uart.o $(BOARD_DIR)/crt0.o dspv3_insn.o $(INCLUDE) -T$(BOARD_DIR)/ckcpu.ld -nostartfiles -lgcc $*.o -o $*.elf
	@#csky-abiv2-elf-objdump -S $@.elf > $@.asm
clean:
	rm -rf  *.o *.a *.asm *.elf
