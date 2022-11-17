SRC = $(wildcard *.c)
SRS = $(wildcard *.S)
OBJFILE = $(SRS:%.S=%.o) $(SRC:%.c=%.o)
CFLAGS = -g2 -static -march=rv64gc -Wa,-march=rv64gc_xtheadmatrix
TARGET_CROSS = riscv64-unknown-linux-gnu
CC = $(TARGET_CROSS)-gcc
INCLUDE = -I../../include -I.
matrix_case: case

case: $(OBJFILE)

%.o: %.S matrix_insn.h
	@echo "  CC    case/$@"
	@$(CC) $(CFLAGS) -c $(INCLUDE) -o $@  $<

%.o: %.c matrix_insn.h
	@echo "  CC    case/$@"
	@$(CC) $(CFLAGS) -c $(INCLUDE) -o $@  $<
	@echo "  CC    case/$*.elf"
	$(CC) $(CFLAGS) matrix_insn.o  $(INCLUDE)   $*.o -o $*.elf
clean:
	rm -rf  *.o *.a *.asm *.elf
