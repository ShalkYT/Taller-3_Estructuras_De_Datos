CC = g++
CFLAGS = -std=c++11

RECURSOS =

taller_3_ordenamiento_busqueda:
	$(CC) $(CFLAGS) $(RECURSOS) taller_3_ordenamiento_busqueda.cxx -o test

clear:
	rm -f test