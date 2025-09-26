#ifndef NODO_H
#define NODO_H

#include <algorithm>

template <typename T>
struct Nodo{
    T dato;
    Nodo<T>* izquierda;
    Nodo<T>* derecha;

    Nodo(T valor);
    int obtenerAltura();
};

template <typename T>
Nodo<T>::Nodo(T valor) {
    dato = valor;
    izquierda = nullptr;
    derecha = nullptr;
}

template <typename T>
int Nodo<T>::obtenerAltura(){
    if(izquierda == nullptr && derecha != nullptr){
        return 1 + derecha->obtenerAltura();
    }
    if(derecha == nullptr && izquierda != nullptr){
        return 1 + izquierda->obtenerAltura();
    }
    if(izquierda != nullptr && derecha != nullptr){
        int alturaIzquierda = izquierda->obtenerAltura();
        int alturaDerecha = derecha->obtenerAltura();
        return 1 + std::max(alturaIzquierda, alturaDerecha);
    }else{
        return 1;
    }
}

#endif // NODO_H
