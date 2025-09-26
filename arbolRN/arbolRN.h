#ifndef ARBOLRN_H
#define ARBOLRN_H

#include <iostream>
#include <set>

class arbolRN{
private:
    std::set<int> elementos;
public:
    void insertar(int dato);
    void eliminar(int dato);

    void inOrden();
};

#endif
