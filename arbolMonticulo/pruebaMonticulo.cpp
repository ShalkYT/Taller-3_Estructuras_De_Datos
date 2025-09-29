#include <iostream>
#include <list>
#include "monticulo.h"

using namespace std;

int main() {
    cout << "=== PRUEBA DE MAX-HEAP ===" << endl;
    
    // 1. Crear un max-heap
    monticulo<int> heap;
    cout << "\n1. Heap creado (siempre sera max-heap)" << endl;
    cout << "¿Esta vacio? " << (heap.empty() ? "SI" : "NO") << endl;
    
    // 2. Insertar elementos
    cout << "\n2. Insertando elementos: 30, 10, 50, 20, 40" << endl;
    heap.insert(30);
    heap.insert(10);
    heap.insert(50);
    heap.insert(20);
    heap.insert(40);
    
    cout << "Tamaño del heap: " << heap.size() << endl;
    cout << "Elemento en la cima (deberia ser 50): " << heap.top() << endl;
    
    // 3. Mostrar elementos ordenados (inorden ascendente)
    cout << "\n3. Elementos en orden ascendente:" << endl;
    list<int> elementos;
    heap.inordenEnLista(elementos);
    
    for (int elem : elementos) {
        cout << elem << " ";
    }
    cout << endl;
    
    // 4. Eliminar elementos
    cout << "\n4. Eliminando el elemento 20" << endl;
    heap.erase(20);
    
    cout << "Tamaño despues de eliminar: " << heap.size() << endl;
    cout << "Elemento en la cima (deberia seguir siendo 50): " << heap.top() << endl;
    
    // Mostrar elementos actualizados
    elementos.clear();
    heap.inordenEnLista(elementos);
    cout << "Elementos actuales: ";
    for (int elem : elementos) {
        cout << elem << " ";
    }
    cout << endl;
    
    // 5. Probar con más inserciones
    cout << "\n5. Insertando mas elementos: 5, 60, 25" << endl;
    heap.insert(5);
    heap.insert(60);
    heap.insert(25);
    
    cout << "Tamaño actual: " << heap.size() << endl;
    cout << "Nuevo elemento en la cima (deberia ser 60): " << heap.top() << endl;
    
    elementos.clear();
    heap.inordenEnLista(elementos);
    cout << "Todos los elementos ordenados: ";
    for (int elem : elementos) {
        cout << elem << " ";
    }
    cout << endl;
    
    // 6. Probar eliminación del elemento máximo
    cout << "\n6. Eliminando el elemento maximo (60)" << endl;
    heap.erase(60);
    
    cout << "Tamaño: " << heap.size() << endl;
    cout << "Nuevo elemento en la cima (deberia ser 50): " << heap.top() << endl;
    
    // 7. Probar con heap vacío
    cout << "\n7. Vaciar el heap" << endl;
    heap.clear();
    cout << "Tamaño despues de clear: " << heap.size() << endl;
    cout << "¿Esta vacio? " << (heap.empty() ? "SI" : "NO") << endl;
    
    // 8. Probar top() en heap vacío
    cout << "\n8. Probando top() en heap vacio:" << endl;
    cout << "Valor devuelto: " << heap.top() << endl;
    
    // 9. Probar con strings (si tu template lo soporta)
    cout << "\n9. Probando con strings:" << endl;
    monticulo<string> heapStrings;
    
    heapStrings.insert("manzana");
    heapStrings.insert("banana");
    heapStrings.insert("cereza");
    heapStrings.insert("dátil");
    
    cout << "Top del heap de strings: " << heapStrings.top() << endl;
    
    list<string> stringsOrdenados;
    heapStrings.inordenEnLista(stringsOrdenados);
    cout << "Strings ordenados: ";
    for (const string& s : stringsOrdenados) {
        cout << s << " ";
    }
    cout << endl;
    
    cout << "\n=== PRUEBA COMPLETADA ===" << endl;
    
    return 0;
}