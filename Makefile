CC=gcc
AR=ar
FLAGS= -Wall -g
.PHONY: all clean

all: string_actions.c 
	$(CC) $(FLAGS) string_actions.c -o stringProg.out




clean:
	rm -f *.o *.a *.so *.out