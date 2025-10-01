#include "arbolRN.h"

// Implementaciond de las funciones template

// Funcion de insertar un dato en el arbolRN
template <typename T>
void arbolRN<T>::insertar(T dato){
    elementos.insert(dato);
}

// Funcion de eliminar un dato en el arbolRN
template <typename T>
void arbolRN<T>::eliminar(T dato){
    elementos.erase(dato);
}

// Funcion de recorrido inOrden del arbolRN
template <typename T>
void arbolRN<T>::inOrden(){
    typename std::set<T>::iterator it = elementos.begin();
    for(; it != elementos.end(); ++it){
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
}

