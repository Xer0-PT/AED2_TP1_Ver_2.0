all: exec

exec: main.o file.o line2.o line3.o line4.o line5.o line6.o
	gcc -g -o exec main.o file.o line2.o line3.o line4.o line5.o line6.o

main.o: main.c
	gcc -g -o main.o main.c -c -W -Wall -ansi -pedantic

file.o:
	gcc -g -o file.o file.c -c -W -Wall -ansi -pedantic

line2.o:
	gcc -g -o line2.o line2.c -c -W -Wall -ansi -pedantic

line3.o:
	gcc -g -o line3.o line3.c -c -W -Wall -ansi -pedantic

line4.o:
	gcc -g -o line4.o line4.c -c -W -Wall -ansi -pedantic

line5.o:
	gcc -g -o line5.o line5.c -c -W -Wall -ansi -pedantic

line6.o:
	gcc -g -o line6.o line6.c -c -W -Wall -ansi -pedantic

clean:
	rm -rf *.o

run:
	make clean
	make all