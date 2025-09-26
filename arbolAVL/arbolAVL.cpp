#include "arbolAVL.h"

template <typename T>
arbolAVL<T>::arbolAVL() {
    Raiz = nullptr;
}

template <typename T>
int arbolAVL<T>::balance(Nodo<T>* n){
    int i, d;
    if(n == nullptr) return 0;
    if(n->izquierda == nullptr){ i = 0; 
    }else i = n->izquierda->obtenerAltura();
    if(n->derecha == nullptr){d = 0;
    }else d = n->derecha->obtenerAltura();

    return i-d;
}

template <typename T>
void arbolAVL<T>::rotarDerecha(Nodo<T>* &n){
    Nodo<T>* aux = n->izquierda;
    n->izquierda = aux->derecha;
    aux->derecha = n;
    n = aux;
}

template <typename T>
void arbolAVL<T>::rotarIzquierda(Nodo<T>* &n){
    Nodo<T>* aux = n->derecha;
    n->derecha = aux->izquierda;
    aux->izquierda = n;
    n = aux;
}

template <typename T>
void arbolAVL<T>::insertar(T dato){
    // Implementar la inserción en el árbol AVL
    
}
