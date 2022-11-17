CORE_OBJ = core
BOARD_DIR = ../board/smartl/e902
CFLAGS = -g -O0
TARGET_CROSS = /home/liuzw/tools/csky-riscv/bin/riscv32-unknown-elf
INCLUDE = -I$(BOARD_DIR)

CC = $(TARGET_CROSS)-gcc

ROOTDIR = $(shell pwd)/
srcdir = $(ROOTDIR)../
EXPECT = expect
RUNTEST = runtest
RUNTESTFLAGS =

all: core

core:
	@echo "  CC    $(BOARD_DIR)/crt0.o"
	@$(CC) -c $(CFLAGS) $(INCLUDE) $(BOARD_DIR)/crt0.S -o $(BOARD_DIR)/crt0.o
	@echo "  CC    $(BOARD_DIR)/uart.o"
	@$(CC) -c $(CFLAGS) $(INCLUDE) $(BOARD_DIR)/uart.c -o $(BOARD_DIR)/uart.o
	make -C case

clean:
	rm -f $(BOARD_DIR)/*.o
	rm -f core
	make -C case clean



