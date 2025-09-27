#include <iostream>
#include <list>
#include <string>
#include "monticulo.h"

using namespace std;

void probarInordenEspecifico() {
    cout << "=== PROBANDO INORDEN CON DATOS ESPECÍFICOS ===" << endl;
    monticulo<int> heap(true); // max-heap
    
    // Insertar los datos exactos de la imagen
    int elementos[] = {21, 19, 14, 5, 13, 10, 12, 2, 1, 6, 11, 8, 7, 3};
    int n = sizeof(elementos) / sizeof(elementos[0]);
    
    cout << "Insertando elementos en este orden: ";
    for (int i = 0; i < n; i++) {
        cout << elementos[i] << " ";
        heap.insert(elementos[i]);
    }
    cout << endl;
    
    cout << "Top (raíz): " << heap.top() << endl;
    cout << "Tamaño: " << heap.size() << endl;
    
    // Obtener y mostrar el recorrido inorden
    list<int> inorden;
    heap.inordenEnLista(inorden);
    
    cout << "Recorrido INORDEN: ";
    for (list<int>::iterator it = inorden.begin(); it != inorden.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // Verificar si coincide con lo esperado
    int esperado[] = {2, 5, 1, 19, 6, 13, 11, 21, 8, 10, 7, 14, 3, 12};
    int n_esperado = sizeof(esperado) / sizeof(esperado[0]);
    
    cout << "Esperado: ";
    for (int i = 0; i < n_esperado; i++) {
        cout << esperado[i] << " ";
    }
    cout << endl;
    
    // Comparar resultados
    bool coincide = true;
    list<int>::iterator it = inorden.begin();
    for (int i = 0; i < n_esperado; i++) {
        if (it == inorden.end() || *it != esperado[i]) {
            coincide = false;
            break;
        }
        ++it;
    }
    
    if (coincide && inorden.size() == n_esperado) {
        cout << "✓ El inorden COINCIDE con lo esperado" << endl;
    } else {
        cout << "✗ El inorden NO coincide con lo esperado" << endl;
    }
}

void probarInordenConStrings() {
    cout << "\n=== PROBANDO INORDEN CON STRINGS (CÓDIGOS TV) ===" << endl;
    monticulo<string> heapTVs(true); // max-heap
    
    // Insertar códigos de televisores
    string codigos[] = {"000015", "000010", "000020", "000005", "000012", "000018", "000025"};
    int n = sizeof(codigos) / sizeof(codigos[0]);
    
    cout << "Insertando códigos: ";
    for (int i = 0; i < n; i++) {
        cout << codigos[i] << " ";
        heapTVs.insert(codigos[i]);
    }
    cout << endl;
    
    // Obtener inorden
    list<string> inorden;
    heapTVs.inordenEnLista(inorden);
    
    cout << "Recorrido INORDEN: ";
    for (list<string>::iterator it = inorden.begin(); it != inorden.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    cout << "Top: " << heapTVs.top() << endl;
}

void probarInordenMinHeap() {
    cout << "\n=== PROBANDO INORDEN CON MIN-HEAP ===" << endl;
    monticulo<int> heapMin(false); // min-heap
    
    // Los mismos datos pero en min-heap
    int elementos[] = {21, 19, 14, 5, 13, 10, 12, 2, 1, 6, 11, 8, 7, 3};
    int n = sizeof(elementos) / sizeof(elementos[0]);
    
    cout << "Insertando elementos en MIN-HEAP: ";
    for (int i = 0; i < n; i++) {
        cout << elementos[i] << " ";
        heapMin.insert(elementos[i]);
    }
    cout << endl;
    
    cout << "Top (mínimo): " << heapMin.top() << endl;
    
    list<int> inorden;
    heapMin.inordenEnLista(inorden);
    
    cout << "Recorrido INORDEN (min-heap): ";
    for (list<int>::iterator it = inorden.begin(); it != inorden.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    cout << "PRUEBA ESPECÍFICA DEL RECORRIDO INORDEN" << endl;
    cout << "========================================" << endl << endl;
    
    probarInordenEspecifico();
    probarInordenConStrings();
    probarInordenMinHeap();
    
    cout << "\n=== PRUEBAS COMPLETADAS ===" << endl;
    
    return 0;
}