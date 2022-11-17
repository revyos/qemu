BOARD_DIR = ./smartl
CFLAGS = -g2 -mcpu=ck803efr1 -msoft-float
TARGET_CROSS = csky-abiv2-elf

CC = $(TARGET_CROSS)-gcc

ROOTDIR = $(shell pwd)/
srcdir = $(ROOTDIR)../
EXPECT = expect
RUNTEST = runtest
RUNTESTFLAGS =

all: core 

core:
	@echo "  CC    $(BOARD_DIR)/uart.o"
	@$(CC) -c $(CFLAGS) $(BOARD_DIR)/uart.c -o $(BOARD_DIR)/uart.o
	make -C boot 
	make -C mic 
	make -C mptimer 
clean:
	rm -f $(BOARD_DIR)/*.o
	make -C boot clean
	make -C mic clean
	make -C mptimer clean



