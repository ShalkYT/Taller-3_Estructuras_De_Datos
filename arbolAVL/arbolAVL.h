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
        void insertar(Nodo<T>* &n, T dato);
        void eliminar(Nodo<T>* &N, T dato);
        void inOrden(Nodo<T>* n);

    public:
        arbolAVL();
        void insertar(T dato);
        void eliminar(T dato);
        T obtenerRaiz();
        int obtenerAltura();
        int obtenerBalanceRaiz();
        void inOrden();


};

#include "arbolAVL.cpp"

#endif // ARBOLAVL_H