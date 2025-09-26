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

// Insertar, publico
template <typename T>
void arbolAVL<T>::insertar(T dato){
    insertar(Raiz, dato);
}

// Insertar, privado
template <typename T>
void arbolAVL<T>::insertar(Nodo<T>* &n, T dato){
    if(n == nullptr){
        n = new Nodo<T>(dato);
    }else if(dato < n->dato){
        insertar(n->izquierda, dato);
    }else if(dato > n->dato){
        insertar(n->derecha, dato);
    }else{
        return;
    }

    int balanceFactor = balance(n);

    if (balanceFactor > 1 && dato < n->izquierda->dato)
        rotarDerecha(n);

    if (balanceFactor < -1 && dato > n->derecha->dato)
        rotarIzquierda(n);

    if (balanceFactor > 1 && dato > n->izquierda->dato) {
        rotarIzquierda(n->izquierda);
        rotarDerecha(n);
    }

    if (balanceFactor < -1 && dato < n->derecha->dato) {
        rotarDerecha(n->derecha);
        rotarIzquierda(n);
    }
}

//Eliminar, publico
template <typename T>
void arbolAVL<T>::eliminar(T dato){
    eliminar(Raiz, dato);
}

//Eliminar, privado
template <typename T>
void arbolAVL<T>::eliminar(Nodo<T>* &n, T dato){
    if(n == nullptr) return;

    if(dato < n->dato){
        eliminar(n->izquierda, dato);
    }else if(dato > n->dato){
        eliminar(n->derecha, dato);
    }else{
        if(n->izquierda == nullptr || n->derecha == nullptr){
            Nodo<T>* temp = n->izquierda ? n->izquierda : n->derecha;

            if(temp == nullptr){
                temp = n;
                n = nullptr;
            }else{
                *n = *temp;
            }
            delete temp;
        }else{
            Nodo<T>* temp = n->derecha;
            while(temp->izquierda != nullptr){
                temp = temp->izquierda;
            }
            n->dato = temp->dato;
            eliminar(n->derecha, temp->dato);
        }
    }

    if(n == nullptr) return;

    int balanceFactor = balance(n);

    if(balanceFactor > 1 && balance(n->izquierda) >= 0)
        rotarDerecha(n);

    if(balanceFactor > 1 && balance(n->izquierda) < 0){
        rotarIzquierda(n->izquierda);
        rotarDerecha(n);
    }

    if(balanceFactor < -1 && balance(n->derecha) <= 0)
        rotarIzquierda(n);

    if(balanceFactor < -1 && balance(n->derecha) > 0){
        rotarDerecha(n->derecha);
        rotarIzquierda(n);
    }
}

//Eliminar, son funciones de apoyo
template <typename T>
T arbolAVL<T>::obtenerRaiz() {
    if (Raiz != nullptr) {
        return Raiz->dato;
    }
    throw std::runtime_error("El árbol está vacío");
}
template <typename T>
int arbolAVL<T>::obtenerAltura() {
    if (Raiz != nullptr) {
        return Raiz->obtenerAltura();
    }
    return 0; // Si el árbol está vacío, la altura es 0
}
template <typename T>
int arbolAVL<T>::obtenerBalanceRaiz() {
    return balance(Raiz);
}


// Recorrido inOrden privado
template <typename T>
void arbolAVL<T>::inOrden(Nodo<T>* n) {
    if (n) {
        inOrden(n->izquierda);
        std::cout << n->dato << " ";
        inOrden(n->derecha);
    }
}


//Recorrido inOrden publico
template <typename T>
void arbolAVL<T>::inOrden() {
    inOrden(Raiz);
    std::cout << std::endl;
}