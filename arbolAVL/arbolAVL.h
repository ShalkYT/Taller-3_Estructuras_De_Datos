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
<<<<<<< HEAD
        void inorden(Nodo<T>* n, std::list<T>& lista);
=======
        void inOrden(Nodo<T>* n, std::list<T>& lista);
>>>>>>> 26acf8b16cd701130dcf9f05f8fecf1c95ce5223

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