#ifndef ARBOLAVL_H
#define ARBOLAVL_H

#include <iostream>

#include "nodo.h"

template <typename T>
class arbolAVL {

    private:
        Nodo<T>* Raiz;

        int balance(Nodo<T>* n);
        void rotarDerecha(Nodo<T>* &n);
        void rotarIzquierda(Nodo<T>* &n);
        void insertar(T dato);
        void buscar(T dato);
        void eliminar(T dato);

    public:
        arbolAVL();



};

#endif // ARBOLAVL_H