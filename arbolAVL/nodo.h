#ifndef NODO_H
#define NODO_H

template <typename T>
struct Nodo {
    T dato;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(T valor);
    int obtenerAltura();
};

#endif // NODO_H
