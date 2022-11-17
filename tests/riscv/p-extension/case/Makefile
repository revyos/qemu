ifeq ($(RV32), y)
SRC = $(wildcard *.c)
else
SRC = $(wildcard *.c)
SRC += $(wildcard rv64/*.c)
endif
SRS = $(wildcard *.S)
OBJFILE = $(SRS:%.S=%.o) $(SRC:%.c=%.o)
ifeq ($(RV32), y)
TARGET_CROSS = riscv64-unknown-elf
CFLAGS = -DRV32 -g2 -static -march=rv32imacxthead -mabi=ilp32 -Wall -march=rv32imacpxthead  -mabi=ilp32  -T../e902/ckcpu.ld -nostartfiles
else
CFLAGS = -DRV64 -g2 -static -march=rv64imafdcxthead -mabi=lp64d -Wa,-march=rv64imafdcpxthead  -mabi=lp64d
TARGET_CROSS = riscv64-unknown-linux-gnu
endif
CC = $(TARGET_CROSS)-gcc
INCLUDE = -I../include -I.
rvv_case: case
BOARD_DIR = ../e902

case: $(OBJFILE)

%.o: %.S rvp_insn.h
	@echo "  CC    case/$@"
	$(CC) $(CFLAGS) -c $(INCLUDE) -o $@  $<

ifeq ($(RV32), y)
%.o: %.c rvp_insn.h
	@echo "  CC    case/$@"
	@$(CC) $(CFLAGS) -c $(INCLUDE) -o $@  $<
	@echo "  CC    case/$*.elf"
	$(CC) $(CFLAGS) $(BOARD_DIR)/crt0.o $*.o rvp_insn.o $(BOARD_DIR)/uart.o ../wrap/wrap.a -Wl,-gc-sections $(INCLUDE) -o $*.elf
else
%.o: %.c rvp_insn.h
	@echo "  CC    case/$@"
	@$(CC) $(CFLAGS) -c $(INCLUDE) -o $@  $<
	@echo "  CC    case/$*.elf"
	$(CC) $(CFLAGS) rvp_insn.o  $(INCLUDE)   $*.o -o $*.elf
endif
clean:
	rm -rf  *.o *.a *.asm *.elf rv64/*.a rv64/*.o rv64/*.elf rv64/*.asm
