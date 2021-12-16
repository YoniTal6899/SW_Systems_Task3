CC=gcc
AR=ar
FLAGS= -Wall -g
.PHONY: all clean

all: string_actions.o 
	$(CC) $(FLAGS) string_actions.c -o stringProg.out
	
stringProg.out: string_actions.o
	$(CC) $(FLAGS) -o string_actions.c stringProg.out

string_actions.o: string_actions.c
	$(CC) $(FLAGS) -c string_actions.c

clean:
	rm -f *.o *.a *.so *.out