#ifndef ARBOLRN_H
#define ARBOLRN_H

#include <iostream>
#include <set>
#include <list>

template <typename T>
class arbolRN{
private:
    // Conjunto de datos el cual es la implementacion del arbolRN
    std::set<T> elementos;
public:
    // Funciones para la logica del arbolRN en nuestro codigo

    // Funciones basicas
    void insert(T dato);
    void erase(T dato);

    // Funciones de recorrido
    void inordenEnLista(std::list<T>& lista);
};

#include "arbolRN.cpp"

#endif
