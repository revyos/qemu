CORE_OBJ = a.out 
CFLAGS = -g2 

CC = gcc

all: core

core:
	gcc -c $(CFLAGS) op_dspv2.c -o op_dspv2.o
	gcc -c $(CFLAGS) op_tcg.c -o op_tcg.o
	gcc -c $(CFLAGS) main.c -o main.o
	gcc main.o op_dspv2.o op_tcg.o -o a.out
	rm -f *.o

clean:
	rm -f *.o

