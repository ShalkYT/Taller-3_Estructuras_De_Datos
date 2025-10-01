#ifndef ARBOLRN_H
#define ARBOLRN_H

#include <iostream>
#include <set>

template <typename T>
class arbolRN{
private:
    // Conjunto de datos el cual es la implementacion del arbolRN
    std::set<T> elementos;
public:
    // Funciones para la logica del arbolRN en nuestro codigo

    // Funciones basicas
    void insertar(T dato);
    void eliminar(T dato);

    // Funciones de recorrido
    void inOrden();
};

#include "arbolRN.cpp"

#endif
