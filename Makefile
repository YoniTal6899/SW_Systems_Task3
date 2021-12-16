CC=gcc
AR=ar
FLAGS= -Wall -g
.PHONY: all clean

all: stringProg

stringProg: string_actions.c
	$(CC) $(FLAGS) string_actions.c -o stringProg

clean:
	rm -f *.o *.a *.so *.out stringProg