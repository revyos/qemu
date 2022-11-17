ROOTDIR = $(shell pwd)/
srcdir = $(ROOTDIR)../
EXPECT = expect
RUNTEST = runtest
RUNTESTFLAGS =

all: 860

860:
	make -C ck860 -j4
clean:
	rm -f $(BOARD_DIR)/*.o
	make -C ck860 clean



