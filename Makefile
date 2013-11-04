CFLAGS = -luv -pthread
LD_LIBRARY_PATH = /usr/local/lib

export CFLAGS
export LD_LIBRARY_PATH

all: clean test

clean:
	rm -f hook-test
	cd ./examples && $(MAKE) clean

test:
	$(CC) test.c $(CFLAGS) -o hook-test
	./hook-test

examples:
	cd ./examples && $(MAKE)

.PHONY: all clean test examples
