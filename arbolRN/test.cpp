#include <iostream>
#include "arbolRN.h"

int main() {
    arbolRN<int> arbol;
    std::list<int> lista;

    std::cout << "Insertando elementos en el AVL..." << std::endl;
    int valores[] = {10, 20, 30, 40, 50, 25};
    for (int v : valores) {
        arbol.insert(v);
        std::cout << "\nDespués de insertar " << v << ":" << std::endl;
        std::cout << "InOrden: ";  arbol.inordenEnLista(lista);
        for (int val : lista) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\nEliminando el nodo 30..." << std::endl;
    arbol.erase(30);

    std::cout << "\nDespués de eliminar 30:" << std::endl;
    std::cout << "InOrden: ";  arbol.inordenEnLista(lista);
    for (int val : lista) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}