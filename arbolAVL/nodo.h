#ifndef NODO_H
#define NODO_H

#include <algorithm>

template <typename T>
struct Nodo{
    T dato;
    Nodo<T>* izquierda;
    Nodo<T>* derecha;

    Nodo(T valor);
    int obtenerAltura();
};

#include "nodo.cpp"

#endif // NODO_H
