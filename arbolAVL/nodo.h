#ifndef NODO_H
#define NODO_H

#include <algorithm>
#include <queue>

template <typename T>
struct Nodo{
    T dato;
    Nodo<T>* izquierda;
    Nodo<T>* derecha;
    int altura;  // Cachear la altura para evitar recalcularla

    Nodo(T valor);
    int obtenerAltura();
    void actualizarAltura();  // Nueva función para actualizar altura
};

#include "nodo.cpp"

#endif // NODO_H
