#ifndef AVLTREE_H
#define AVLTREE_H

#include "Nodo.h"
#include <iostream>
using namespace std;

class AVLTree {
private:
    Nodo* raiz;

    int altura(Nodo* n);
    int balance(Nodo* n);
    
    Nodo* rotarDerecha(Nodo* y);
    Nodo* rotarIzquierda(Nodo* x);
    
    Nodo* insertar(Nodo* nodo, int dato);
    Nodo* eliminar(Nodo* nodo, int dato);
    
    Nodo* nodoMinimo(Nodo* nodo);
    
    void inOrden(Nodo* nodo);
    void preOrden(Nodo* nodo);
    void posOrden(Nodo* nodo);

public:
    AVLTree();
    ~AVLTree();
    void insertar(int dato);
    void eliminar(int dato);
    int obtenerAltura();
    int obtenerRaiz();
    int obtenerBalanceRaiz();

    void inOrden();
    void preOrden();
    void posOrden();
};

#endif

