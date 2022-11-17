CC=csky-abiv2-elf-gcc
NEWLIBCC=/home/xialf/workspace/tools-chain/install/bin/csky-abiv2-elf-gcc
SRS = $(wildcard *.S)
SRC = $(wildcard *.c)
OBJFILE = $(SRS:%.S=%.o) $(SRC:%.c=%.o)
CFLAGS = -c -mcpu=ck803s -O2

ifeq ($(LIBC),newlib)
CC=$(NEWLIBCC)
endif

ifeq ($(V),)
Q=@
else
Q=
endif

$(info $(CC))
all: semi-case
newlib: newlib-case

semi-case: $(OBJFILE)
	@echo linking...
	$(Q)$(CC) -o semi-case -mcpu=ck803s -nostartfiles -Tckcpu.ld -L. $(OBJFILE)  -Wl,--whole-archive -lsemi -Wl,-no-whole-archive
	$(Q)csky-abiv2-elf-objdump -S semi-case > semi-case.asm

newlib-case: $(OBJFILE)
	@echo linking...
	$(Q)$(CC) -o newlib-case -mcpu=ck803s -nostartfiles -Tckcpu.ld -L. $(OBJFILE) -Wl,--whole-archive -Wl,-lhosted -Wl,-no-whole-archive
	$(Q)csky-abiv2-elf-objdump -S newlib-case > newlib-case.asm

%.o: %.c
	@echo "  CC   $@"
	$(Q)$(CC) $(CFLAGS)  -o $@  $<
	$(Q)#csky-abiv2-linux-objdump -S $@ > $*.asm
%.o: %.S
	@echo "  CC   $@"
	$(Q)$(CC) $(CFLAGS)  -o $@  $<
clean:
	rm -rf  *.o *.asm *.elf *.data semi-case test2.txt test3.txt
