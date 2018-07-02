all: program

program: main list
		gcc -o program main.o list.o

main: main.c list.h
		gcc -c main.c

list: list.c list.h
		gcc -c list.c

clean:
	rm -rf *.o output

backup:
	test ! -d backup && mkdir backup 
	cp *.c ./backup
	cp *.h ./backup
