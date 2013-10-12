.SUFFIXES: .c .o

.c.o:
	gcc -Wall -g -c $<

p1: p1_main.o p1_calc_data.o hash_one.o hash_two.o
	gcc p1_main.o p1_calc_data.o hash_one.o hash_two.o -o p1

p1_main.o: p1_header.h

clean:
	rm -f *.o core
