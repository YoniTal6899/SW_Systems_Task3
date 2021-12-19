# CC=gcc
# AR=ar
# FLAGS= -Wall -g
# .PHONY: all clean

# all: stringProg

# stringProg: main2.c
# 	$(CC) $(FLAGS) main2.c -o stringProg

# run:
# 	gcc string_actions.c
# clean:
# 	rm -f *.o *.a *.so *.out stringProg


CC=gcc
FLAGS= -Wall -g

#make all
all: stringProg

.PHONY: clean
#make clean
clean: 
	rm -f *.o *.a *.so stringProg

stringProg: main2.o
	$(CC) $(FLAGS) -o stringProg main2.c

main2.o: main2.c 
	$(CC) $(FLAGS) -c main2.c