#include <iostream>
#include "arbolAVL.h"
using namespace std;

int main() {
    arbolAVL<int> arbol;
    std::list <int> lista;

    cout << "Insertando elementos en el AVL..." << endl;
    int valores[] = {10, 20, 30, 40, 50, 25};
    for (int v : valores) {
        arbol.insert(v);
        cout << "\nDespués de insertar " << v << ":" << endl;
        cout << "Raíz: " << arbol.obtenerRaiz() << endl;
        cout << "Altura del árbol: " << arbol.obtenerAltura() << endl;
        cout << "Factor de balance de la raíz: " << arbol.obtenerBalanceRaiz() << endl;
    }

    cout << "\nRecorridos después de las inserciones:" << endl;
    cout << "InOrden: ";  arbol.inordenEnLista(lista);
    for (int val : lista) {
        cout << val << " ";
    }
    cout << endl;

    cout << "\nEliminando el nodo 30..." << endl;
    arbol.erase(30);

    cout << "\nDespués de eliminar 30:" << endl;
    cout << "Raíz: " << arbol.obtenerRaiz() << endl;
    cout << "Altura del árbol: " << arbol.obtenerAltura() << endl;
    cout << "Factor de balance de la raíz: " << arbol.obtenerBalanceRaiz() << endl;

    cout << "\nRecorridos después de la eliminación:" << endl;
    cout << "InOrden: ";  arbol.inordenEnLista(lista);
    for (int val : lista) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}