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

all: pig unpig test extra

pig.o: pig.c pig.h pigify.c pigify.h
	$(CC) -c pig.c pigify.c

pig: pig.o pig.h pigify.o pigify.o
	$(CC)  pig.o pigify.o -o pig

test.o: test.c pig.c pig.h pigify.c pigify.h
	$(CC) -c test.c pig.c pigify.c

test: test.o pig.c pig.h pigify.o pigify.o
	$(CC) test.o pigify.o -o test

unpig.o: unpig.c pigify.c pigify.h
	$(CC) -c unpig.c pigify.c

unpig: unpig.o pigify.o pigify.o
	$(CC) unpig.o pigify.o -o unpig

extra.o: extra.c
	$(CC) -c extra.c

extra: extra.o
	$(CC) extra.o -o extra

clean:
	rm -rf *.o pig extra test *.dSYM *~
