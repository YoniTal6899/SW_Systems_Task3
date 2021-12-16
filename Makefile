CC=gcc
AR=ar
FLAGS= -Wall -g
.PHONY: all clean

all: string_actions.o
	$(CC) $(FLAGS) -o stringProg.out string_actions.o

clean:
	rm -f *.o *.a *.so *.out