all: exec

exec: main.o
	gcc -g -o exec main.o 

main.o: main.c
	gcc -g -o main.o main.c -c -W -Wall -ansi -pedantic

clean:
	rm -rf *.o

run:
	make clean
	make all