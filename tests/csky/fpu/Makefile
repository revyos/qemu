CORE_OBJ = core 
BOARD_DIR = ../board/smartl/ck803s
CFLAGS = -g2 -mcpu=ck803efr1 
TARGET_CROSS = csky-abiv2-elf

CC = $(TARGET_CROSS)-gcc

ROOTDIR = $(shell pwd)/
srcdir = $(ROOTDIR)../
EXPECT = expect
RUNTEST = runtest
RUNTESTFLAGS =

all: 803 810 610

803:
	@echo "  CC    $(BOARD_DIR)/crt0.o"
	@$(CC) -c $(CFLAGS) $(BOARD_DIR)/crt0.S -o $(BOARD_DIR)/crt0.o
	@echo "  CC    $(BOARD_DIR)/uart.o"
	@$(CC) -c $(CFLAGS) $(BOARD_DIR)/uart.c -o $(BOARD_DIR)/uart.o
	make -C ck803

810:
	make -C ck810
610:
	make -C ck610
clean:
	rm -f $(BOARD_DIR)/*.o
	rm -f 803
	make -C ck803 clean
	make -C ck810 clean
	make -C ck610 clean



