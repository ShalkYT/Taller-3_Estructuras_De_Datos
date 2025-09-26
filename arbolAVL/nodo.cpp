#include "arbolAVL.h"

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