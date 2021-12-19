CC=gcc
AR=ar
FLAGS= -Wall -g
.PHONY: all clean

all: stringProg

stringProg: main2.c
	$(CC) $(FLAGS) main2.c -o stringProg

run:
	gcc string_actions.c
clean:
	rm -f *.o *.a *.so *.out stringProg

