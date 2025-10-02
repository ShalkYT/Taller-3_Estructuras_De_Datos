#include "arbolRN.h"

// Implementaciond de las funciones template

// Funcion de insertar un dato en el arbolRN
template <typename T>
void arbolRN<T>::insert(T dato){
    elementos.insert(dato);
}

// Funcion de eliminar un dato en el arbolRN
template <typename T>
void arbolRN<T>::erase(T dato){
    elementos.erase(dato);
}

// Funcion de recorrido inOrden del arbolRN
template <typename T>
void arbolRN<T>::inordenEnLista(std::list<T>& lista){
    typename std::set<T>::iterator it = elementos.begin();
    lista.clear();
    for(; it != elementos.end(); ++it){
        lista.push_back(*it);
    }
    std::cout << std::endl;
}

