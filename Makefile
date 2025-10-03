CC = g++
CFLAGS = -std=c++11

RECURSOS =

taller_3_ordenamiento_busqueda:
	$(CC) $(CFLAGS) $(RECURSOS) taller_3_ordenamiento_busqueda.cxx -o test

test:
	$(CC) $(CFLAGS) $(RECURSOS) prueba_include_AVL.cpp -o testmake tall

clear:
	rm -f test