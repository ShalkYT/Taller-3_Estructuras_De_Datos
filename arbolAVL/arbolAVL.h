#ifndef ARBOLAVL_H
#define ARBOLAVL_H

#include <iostream>
#include <list>

#include "nodo.h"

template <typename T>
class arbolAVL {

    private:
        Nodo<T>* Raiz;

        // Funciones auxiliares
        int balance(Nodo<T>* n);
        void rotarDerecha(Nodo<T>* &n);
        void rotarIzquierda(Nodo<T>* &n);
        void insert(Nodo<T>* &n, T dato);
        void erase(Nodo<T>* &N, T dato);
        void inordenRecursivo(Nodo<T>* n, std::list<T>& lista);

    public:
        // Constructor
        arbolAVL();

        // Operaciones básicas
        void insert(T dato);
        void erase(T dato);
        T obtenerRaiz();
        int obtenerAltura();
        int obtenerBalanceRaiz();
        void inordenEnLista(std::list<T>& lista);


};

// Incluir la implementación de templates
#include "arbolAVL.cpp"

#endif // ARBOLAVL_H