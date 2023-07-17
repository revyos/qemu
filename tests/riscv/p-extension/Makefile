BOARD_DIR = ./e902
CFLAGS = -g -O0 -march=rv32imac -mabi=ilp32
TARGET_CROSS = riscv64-unknown-elf
INCLUDE = -I$(BOARD_DIR)
CC = $(TARGET_CROSS)-gcc

all: core

ifeq ($(RV32), y)
core:
	@echo "  CC    $(BOARD_DIR)/crt0.o"
	@$(CC) -c $(CFLAGS) $(INCLUDE) $(BOARD_DIR)/crt0.S -o $(BOARD_DIR)/crt0.o
	@echo "  CC    $(BOARD_DIR)/uart.o"
	@$(CC) -c $(CFLAGS) $(INCLUDE) $(BOARD_DIR)/uart.c -o $(BOARD_DIR)/uart.o
	make -C wrap
	make -C case
else
core:
	make -C case
endif

clean:
	rm -f $(BOARD_DIR)/*.o
	rm -f core
	make -C case clean
	make -C wrap clean
