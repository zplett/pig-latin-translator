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

all: pig test

pig.o: pig.c pig.h pigify.c pigify.h
	$(CC) -c pig.c pigify.c

pig: pig.o pig.h pigify.o pigify.o
	$(CC) -g pig.o pigify.o -o pig

test.o: test.c pig.c pig.h pigify.c pigify.h
	$(CC) -c test.c pig.c pigify.c

test: test.o pig.c pig.h pigify.o pigify.o
	$(CC) test.o pigify.o -o test


#%.o: %.c pigify.c pigify.h
#	$(CC) -c $< pigify.c 

#% : %.o pigify.o pigify.h
#	$(CC) $< pigify.o -o $@

clean:
	rm -rf *.o pig test *.dSYM *~
