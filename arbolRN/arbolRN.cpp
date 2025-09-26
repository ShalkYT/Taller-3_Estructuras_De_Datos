#include "arbolRN.h"

void arbolRN::insertar(int dato){
    elementos.insert(dato);
}

void arbolRN::eliminar(int dato){
    elementos.erase(dato);
}

void arbolRN::inOrden(){
    std::set<int>::iterator it;
    for(it = elementos.begin(); it != elementos.end(); ++it){
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
}

