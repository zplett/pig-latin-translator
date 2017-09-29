# Detect OS for cflags (whether I can use gccx)
OS := $(shell uname)
# Establish OS specific commands
ifeq ($(OS), Darwin)
	CC := gcc -g -pedantic -std=c99 -Wall -Wextra
else
	ifeq ($(OS), Linux)
		CC := gccx
	endif
endif
# End of OS specification

all: test

% : %.c pig.h
	$(CC) -c $< -o $@

clean:
	rm -rf *.o pig test
