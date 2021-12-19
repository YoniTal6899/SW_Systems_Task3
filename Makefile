# CC=gcc
# AR=ar
# FLAGS= -Wall -g
# .PHONY: all clean

# all: stringProg

# stringProg: string_actions.c
# 	$(CC) $(FLAGS) string_actions.c -o stringProg

# run:
# 	gcc string_actions.c
# clean:
# 	rm -f *.o *.a *.so *.out stringProg

CC=gcc
FLAGS= -Wall

all: libfuncs.so stringProg 

stringProg: main2.o libfuncs.so
	$(CC) $(FLAGS) main2.o ./libfuncs.so -o stringProg

main.o: main2.c actions.h
	$(CC) $(FLAGS) -c main2.c

libfuncs.so: actions.o
	$(CC) -shared -o libfuncs.so actions.o

actions.o: actions.c actions.h
	$(CC) $(FLAGS) -c actions.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so stringProg