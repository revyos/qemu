CORE_OBJ = csi.core.elf
BOARD_DIR = ../board/smartl/ck803s
CFLAGS = -g2 -mcpu=ck803r1 -msoft-float
TARGET_CROSS = csky-abiv2-elf

CC = $(TARGET_CROSS)-gcc

ROOTDIR = $(shell pwd)/
srcdir = $(ROOTDIR)../
EXPECT = expect
RUNTEST = runtest
RUNTESTFLAGS =

all: core

core:
	@echo "  CC    $(BOARD_DIR)/crt0.o"
	@$(CC) -c $(CFLAGS) $(BOARD_DIR)/crt0.S -o $(BOARD_DIR)/crt0.o
	@echo "  CC    $(BOARD_DIR)/uart.o"
	@$(CC) -c $(CFLAGS) $(BOARD_DIR)/uart.c -o $(BOARD_DIR)/uart.o
	make -C case

clean:
	rm -f $(BOARD_DIR)/*.o
	rm -f site.exp
	rm -rf testresult
	make -C case clean



