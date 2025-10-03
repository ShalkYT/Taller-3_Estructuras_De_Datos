#include <iostream>
#include "AVLTree.h"

using namespace std;

int main() {
    AVLTree arbol;

    cout << "Insertando elementos en el AVL..." << endl;
    int valores[] = {10, 20, 30, 40, 50, 25};
    for (int v : valores) {
        arbol.insertar(v);
        cout << "\nDespués de insertar " << v << ":" << endl;
        cout << "Raíz: " << arbol.obtenerRaiz() << endl;
        cout << "Altura del árbol: " << arbol.obtenerAltura() << endl;
        cout << "Factor de balance de la raíz: " << arbol.obtenerBalanceRaiz() << endl;
    }

    cout << "\nRecorridos después de las inserciones:" << endl;
    cout << "InOrden: ";  arbol.inOrden();
    cout << "PreOrden: "; arbol.preOrden();
    cout << "PosOrden: "; arbol.posOrden();

    cout << "\nEliminando el nodo 30..." << endl;
    arbol.eliminar(30);

    cout << "\nDespués de eliminar 30:" << endl;
    cout << "Raíz: " << arbol.obtenerRaiz() << endl;
    cout << "Altura del árbol: " << arbol.obtenerAltura() << endl;
    cout << "Factor de balance de la raíz: " << arbol.obtenerBalanceRaiz() << endl;

    cout << "\nRecorridos después de la eliminación:" << endl;
    cout << "InOrden: ";  arbol.inOrden();
    cout << "PreOrden: "; arbol.preOrden();
    cout << "PosOrden: "; arbol.posOrden();

    return 0;
}
