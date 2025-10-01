#include "arbolRN.h"

template <typename T>
void arbolRN<T>::insertar(T dato){
    elementos.insert(dato);
}

template <typename T>
void arbolRN<T>::eliminar(T dato){
    elementos.erase(dato);
}

template <typename T>
void arbolRN<T>::inOrden(){
    typename std::set<T>::iterator it = elementos.begin();
    for(; it != elementos.end(); ++it){
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
}

