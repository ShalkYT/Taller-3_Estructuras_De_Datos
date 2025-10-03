# Compilador de C++
CC = g++
CFLAGS = -Wall -Wextra -std=c++17  # Opciones de compilación

# Archivos fuente del proyecto
SRC = Nodo.cpp AVLTree.cpp Arbolito.cpp
OBJ = $(SRC:.cpp=.o)  # Genera los archivos objeto reemplazando .cpp por .o

# Nombre del ejecutable
EXEC = arbol_avl

# Regla principal: compilar todo
all: $(EXEC)

# Enlaza los archivos objeto para crear el ejecutable
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

# Regla para compilar archivos .cpp en .o asegurando la dependencia con su .h
%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar archivos generados (.o y el ejecutable)
clean:
	rm -f $(OBJ) $(EXEC)

# Regla para ejecutar el programa después de compilar
run: $(EXEC)
	./$(EXEC)
