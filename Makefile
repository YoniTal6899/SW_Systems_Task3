CC=gcc
AR=ar
FLAGS= -Wall -g
.PHONY: all clean

all: string_actions.c
	$(CC) $(FLAGS) -o stringProg.out string_actions.c

clean:
	rm -f *.o *.a *.so *.out