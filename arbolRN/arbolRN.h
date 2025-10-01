#ifndef ARBOLRN_H
#define ARBOLRN_H

#include <iostream>
#include <set>

template <typename T>
class arbolRN{
private:
    std::set<T> elementos;
public:
    void insertar(T dato);
    void eliminar(T dato);

    void inOrden();
};

#include "arbolRN.cpp"

#endif
