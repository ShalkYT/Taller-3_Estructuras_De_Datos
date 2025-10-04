#include "arbolAVL.h"
#include <stack>

// Constructor
template <typename T>
arbolAVL<T>::arbolAVL() {
    Raiz = nullptr;
}

// Funciones que retornan el balance entre los hijos de un nodo
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

// Funcion de rotacion a la derecha
template <typename T>
void arbolAVL<T>::rotarDerecha(Nodo<T>* &n){
    Nodo<T>* aux = n->izquierda;
    n->izquierda = aux->derecha;
    aux->derecha = n;
    n->actualizarAltura();  // Actualizar altura del nodo rotado
    aux->actualizarAltura(); // Actualizar altura de la nueva raíz
    n = aux;
}

// Funcion de rotacion a la izquierda
template <typename T>
void arbolAVL<T>::rotarIzquierda(Nodo<T>* &n){
    Nodo<T>* aux = n->derecha;
    n->derecha = aux->izquierda;
    aux->izquierda = n;
    n->actualizarAltura();  // Actualizar altura del nodo rotado
    aux->actualizarAltura(); // Actualizar altura de la nueva raíz
    n = aux;
}

// Funcion de insercion auxiliar recursiva (más estable)
template <typename T>
void arbolAVL<T>::insert(Nodo<T>* &n, T dato){
    if(n == nullptr){
        n = new Nodo<T>(dato);
        return;
    }
    
    if(dato < n->dato){
        insert(n->izquierda, dato);
    }else if(dato > n->dato){
        insert(n->derecha, dato);
    }else{
        return; // Dato duplicado
    }

    int balanceFactor = balance(n);

    // Rotación simple derecha
    if (balanceFactor > 1 && dato < n->izquierda->dato)
        rotarDerecha(n);

    // Rotación simple izquierda
    if (balanceFactor < -1 && dato > n->derecha->dato)
        rotarIzquierda(n);

    // Rotación doble izquierda-derecha
    if (balanceFactor > 1 && dato > n->izquierda->dato) {
        rotarIzquierda(n->izquierda);
        rotarDerecha(n);
    }

    // Rotación doble derecha-izquierda
    if (balanceFactor < -1 && dato < n->derecha->dato) {
        rotarDerecha(n->derecha);
        rotarIzquierda(n);
    }
}

// Funcion para insertar, utiliza la funcion privada insertar
template <typename T>
void arbolAVL<T>::insert(T dato){
    insert(Raiz, dato);
}

// Funcion para eliminar un nodo (recursiva - más estable)
template <typename T>
void arbolAVL<T>::erase(Nodo<T>* &n, T dato){
    if(n == nullptr) return;

    if(dato < n->dato){
        erase(n->izquierda, dato);
    }else if(dato > n->dato){
        erase(n->derecha, dato);
    }else{
        // Nodo encontrado
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
            // Nodo con dos hijos: obtener sucesor inorden
            Nodo<T>* temp = n->derecha;
            while(temp->izquierda != nullptr){
                temp = temp->izquierda;
            }
            n->dato = temp->dato;
            erase(n->derecha, temp->dato);
        }
    }

    if(n == nullptr) return;

    int balanceFactor = balance(n);

    // Caso izquierda-izquierda
    if(balanceFactor > 1 && balance(n->izquierda) >= 0)
        rotarDerecha(n);

    // Caso izquierda-derecha
    if(balanceFactor > 1 && balance(n->izquierda) < 0){
        rotarIzquierda(n->izquierda);
        rotarDerecha(n);
    }

    // Caso derecha-derecha
    if(balanceFactor < -1 && balance(n->derecha) <= 0)
        rotarIzquierda(n);

    // Caso derecha-izquierda
    if(balanceFactor < -1 && balance(n->derecha) > 0){
        rotarDerecha(n->derecha);
        rotarIzquierda(n);
    }
}

// Funcion para eliminar
template <typename T>
void arbolAVL<T>::erase(T dato){
    erase(Raiz, dato);
}

// Funcion para obtener el valor de la raiz
template <typename T>
T arbolAVL<T>::obtenerRaiz() {
    if (Raiz != nullptr) {
        return Raiz->dato;
    }
    throw std::runtime_error("El árbol está vacío");
}

// Funcion para obtener la altura del arbol
template <typename T>
int arbolAVL<T>::obtenerAltura() {
    if (Raiz != nullptr) {
        return Raiz->obtenerAltura();
    }
    return 0;
}

// Funcion para obtener el balance de la raiz
template <typename T>
int arbolAVL<T>::obtenerBalanceRaiz() {
    return balance(Raiz);
}

// Funcion de recorrido inOrden iterativa
template <typename T>
void arbolAVL<T>::inOrden(Nodo<T>* raiz, std::list<T>& lista) {
    if(raiz == nullptr) return;

    std::stack<Nodo<T>*> pila;
    Nodo<T>* actual = raiz;

    while(actual != nullptr || !pila.empty()){
        // Ir al nodo más a la izquierda
        while(actual != nullptr){
            pila.push(actual);
            actual = actual->izquierda;
        }

        // El actual es nullptr, tomar el nodo de la pila
        actual = pila.top();
        pila.pop();

        // Procesar el nodo
        lista.push_back(actual->dato);

        // Ir al subárbol derecho
        actual = actual->derecha;
    }
}

// Funcion publica para el recorrido inOrden
template <typename T>
void arbolAVL<T>::inordenEnLista(std::list<T>& lista) {
    lista.clear();
    inOrden(Raiz, lista);
}