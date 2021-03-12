CFLAGS=-Wall -std=gnu99 -pedantic -Werror

rotate-matrix: read-matrix.o rotate.o
	gcc -o rotate-matrix read-matrix.o rotate.o
rotate.o: rotate.c
	gcc $(CFLAGS) -c rotate.c
