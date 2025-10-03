#include "AVLTree.h"

AVLTree::AVLTree() : raiz(nullptr) {}

AVLTree::~AVLTree() {
    while (raiz) eliminar(raiz->dato);
}

int AVLTree::altura(Nodo* n) {
    return n ? n->altura : 0;
}

int AVLTree::balance(Nodo* n) {
    return n ? altura(n->izquierda) - altura(n->derecha) : 0;
}
int AVLTree::obtenerAltura() {
    return altura(raiz);
}

int AVLTree::obtenerRaiz() {
    return raiz ? raiz->dato : -1;  // -1 indica que el árbol está vacío.
}

int AVLTree::obtenerBalanceRaiz() {
    return balance(raiz);
}


Nodo* AVLTree::rotarDerecha(Nodo* y) {
    Nodo* x = y->izquierda;
    Nodo* T2 = x->derecha;

    x->derecha = y;
    y->izquierda = T2;

    y->altura = max(altura(y->izquierda), altura(y->derecha)) + 1;
    x->altura = max(altura(x->izquierda), altura(x->derecha)) + 1;

    return x;
}

Nodo* AVLTree::rotarIzquierda(Nodo* x) {
    Nodo* y = x->derecha;
    Nodo* T2 = y->izquierda;

    y->izquierda = x;
    x->derecha = T2;

    x->altura = max(altura(x->izquierda), altura(x->derecha)) + 1;
    y->altura = max(altura(y->izquierda), altura(y->derecha)) + 1;

    return y;
}

Nodo* AVLTree::insertar(Nodo* nodo, int dato) {
    if (!nodo) return new Nodo(dato);

    if (dato < nodo->dato)
        nodo->izquierda = insertar(nodo->izquierda, dato);
    else if (dato > nodo->dato)
        nodo->derecha = insertar(nodo->derecha, dato);
    else
        return nodo;

    nodo->altura = 1 + max(altura(nodo->izquierda), altura(nodo->derecha));

    int balanceFactor = balance(nodo);

    if (balanceFactor > 1 && dato < nodo->izquierda->dato)
        return rotarDerecha(nodo);

    if (balanceFactor < -1 && dato > nodo->derecha->dato)
        return rotarIzquierda(nodo);

    if (balanceFactor > 1 && dato > nodo->izquierda->dato) {
        nodo->izquierda = rotarIzquierda(nodo->izquierda);
        return rotarDerecha(nodo);
    }

    if (balanceFactor < -1 && dato < nodo->derecha->dato) {
        nodo->derecha = rotarDerecha(nodo->derecha);
        return rotarIzquierda(nodo);
    }

    return nodo;
}

void AVLTree::insertar(int dato) {
    raiz = insertar(raiz, dato);
}

Nodo* AVLTree::nodoMinimo(Nodo* nodo) {
    while (nodo->izquierda) nodo = nodo->izquierda;
    return nodo;
}

Nodo* AVLTree::eliminar(Nodo* nodo, int dato) {
    if (!nodo) return nodo;

    if (dato < nodo->dato)
        nodo->izquierda = eliminar(nodo->izquierda, dato);
    else if (dato > nodo->dato)
        nodo->derecha = eliminar(nodo->derecha, dato);
    else {
        if (!nodo->izquierda || !nodo->derecha) {
            Nodo* temp = nodo->izquierda ? nodo->izquierda : nodo->derecha;
            delete nodo;
            return temp;
        }

        Nodo* temp = nodoMinimo(nodo->derecha);
        nodo->dato = temp->dato;
        nodo->derecha = eliminar(nodo->derecha, temp->dato);
    }

    if (!nodo) return nodo;

    nodo->altura = 1 + max(altura(nodo->izquierda), altura(nodo->derecha));
    int balanceFactor = balance(nodo);

    if (balanceFactor > 1 && balance(nodo->izquierda) >= 0)
        return rotarDerecha(nodo);

    if (balanceFactor > 1 && balance(nodo->izquierda) < 0) {
        nodo->izquierda = rotarIzquierda(nodo->izquierda);
        return rotarDerecha(nodo);
    }

    if (balanceFactor < -1 && balance(nodo->derecha) <= 0)
        return rotarIzquierda(nodo);

    if (balanceFactor < -1 && balance(nodo->derecha) > 0) {
        nodo->derecha = rotarDerecha(nodo->derecha);
        return rotarIzquierda(nodo);
    }

    return nodo;
}

void AVLTree::eliminar(int dato) {
    raiz = eliminar(raiz, dato);
}

// Recorridos
void AVLTree::inOrden(Nodo* nodo) {
    if (nodo) {
        inOrden(nodo->izquierda);
        cout << nodo->dato << " ";
        inOrden(nodo->derecha);
    }
}

void AVLTree::preOrden(Nodo* nodo) {
    if (nodo) {
        cout << nodo->dato << " ";
        preOrden(nodo->izquierda);
        preOrden(nodo->derecha);
    }
}

void AVLTree::posOrden(Nodo* nodo) {
    if (nodo) {
        posOrden(nodo->izquierda);
        posOrden(nodo->derecha);
        cout << nodo->dato << " ";
    }
}

// Métodos públicos para llamar a los recorridos
void AVLTree::inOrden() {
    inOrden(raiz);
    cout << endl;
}

void AVLTree::preOrden() {
    preOrden(raiz);
    cout << endl;
}

void AVLTree::posOrden() {
    posOrden(raiz);
    cout << endl;
}
