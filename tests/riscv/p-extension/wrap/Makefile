SRC = $(wildcard *.c)
OBJFILE = $(SRS:%.S=%.o) $(SRC:%.c=%.o)
ifeq ($(RV32), y)
TARGET_CROSS = riscv64-unknown-elf
CFLAGS = -DRV32 -g2 -static -march=rv32imac -mabi=ilp32 -T../e902/ckcpu.ld -nostartfiles
#-lgcc
else
TARGET_CROSS = riscv64-unknown-linux-gnu
CFLAGS = -DRV64 -g2 -static -march=rv64imfd -mabi=lp64d -Wa,-march=rv64imfdp
endif
CC = $(TARGET_CROSS)-gcc
AR = $(TARGET_CROSS)-ar
INCLUDE = -I../include -I.

wrap: $(OBJFILE)
	$(AR) rv $@.a $^

%.o: %.c minilibc_stdio.h
	@echo "  CC    case/$@"
	@$(CC) $(CFLAGS) -c $(INCLUDE) -o $@  $<
clean:
	rm -rf  *.o *.a *.asm *.elf
