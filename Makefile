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

test.o: pigify.c test.c pigify.h
	$(CC) -c pigify.c test.c

test: test.o pigify.o
	$(CC) test.o pigify.o -o test

#%.o: %.c pig.c pig.h
#	$(CC) -c pig.c $< 

#% : %.o pig.o pig.h
#	$(CC) $< pig.o -o $@

clean:
	rm -rf *.o pig test *.dSYM *~
