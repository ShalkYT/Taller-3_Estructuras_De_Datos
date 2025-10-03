#ifndef NODO_H
#define NODO_H

struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;
    int altura;

    Nodo(int valor);
};

#endif
