BOARD_DIR = ../board/smartl/ck803s
CFLAGS = -g2 -mcpu=ck803efr1 -msoft-float
TARGET_CROSS = csky-abiv2-elf

CC = $(TARGET_CROSS)-gcc

ROOTDIR = $(shell pwd)/
srcdir = $(ROOTDIR)../
EXPECT = expect
RUNTEST = runtest
RUNTESTFLAGS =

all: core 803_case 860_case

core:
	@echo "  CC    $(BOARD_DIR)/crt0.o"
	@$(CC) -c $(CFLAGS) $(BOARD_DIR)/crt0.S -o $(BOARD_DIR)/crt0.o
	@echo "  CC    $(BOARD_DIR)/uart.o"
	@$(CC) -c $(CFLAGS) $(BOARD_DIR)/uart.c -o $(BOARD_DIR)/uart.o

803_case: core
	make -C case CFLAGS="-g -O2 -mcpu=ck803 -msoft-float -Wa,-mcpu=ck803vr3 -DCK803"


860_case: core
	make -C case CFLAGS="-g -O2 -mcpu=ck860 -msoft-float -Wa,-mcpu=ck860fv -DVDSP_FLOAT"

clean:
	rm -f $(BOARD_DIR)/*.o
	rm -f core
	make -C case clean



