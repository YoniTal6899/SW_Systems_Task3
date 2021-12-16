CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB=mylib.o
FLAGS= -Wall -g
.PHONY: all

all: string_actions.o
	$(CC) $(FLAGS) -o stringProg.out string_actions.o

string_actions.o: string_actions.c 
	$(CC) $(FLAGS) -c string_actions.c

clean:
	rm -f *.o *.a *.so *.out