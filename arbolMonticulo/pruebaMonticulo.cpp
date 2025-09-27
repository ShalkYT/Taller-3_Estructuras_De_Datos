#include <iostream>
#include <list>
#include <string>
#include "monticulo.h"

using namespace std;

void pruebaMinHeapBasico() {
    cout << "=== PRUEBA MIN-HEAP BÁSICO ===" << endl;
    monticulo<int> heapMin(false); // min-heap
    
    int elementos[] = {10, 5, 15, 3, 7};
    int n = sizeof(elementos) / sizeof(elementos[0]);
    
    cout << "Insertando: ";
    for (int i = 0; i < n; i++) {
        cout << elementos[i] << " ";
        heapMin.insert(elementos[i]);
    }
    cout << endl;
    
    cout << "Top (mínimo): " << heapMin.top() << endl;
    cout << "Tamaño: " << heapMin.size() << endl;
    
    list<int> inorden;
    heapMin.inordenEnLista(inorden);
    
    cout << "Recorrido INORDEN: ";
    for (list<int>::iterator it = inorden.begin(); it != inorden.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    cout << "Esperado: 10 5 7 3 15 (depende de la estructura)" << endl;
    cout << endl;
}

void pruebaMinHeapConStrings() {
    cout << "=== PRUEBA MIN-HEAP CON STRINGS ===" << endl;
    monticulo<string> heapMin(false); // min-heap
    
    string elementos[] = {"000015", "000010", "000020", "000005", "000012"};
    int n = sizeof(elementos) / sizeof(elementos[0]);
    
    cout << "Insertando: ";
    for (int i = 0; i < n; i++) {
        cout << elementos[i] << " ";
        heapMin.insert(elementos[i]);
    }
    cout << endl;
    
    cout << "Top (mínimo): " << heapMin.top() << endl;
    
    list<string> inorden;
    heapMin.inordenEnLista(inorden);
    
    cout << "Recorrido INORDEN: ";
    for (list<string>::iterator it = inorden.begin(); it != inorden.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    cout << endl;
}

void pruebaMinHeapEliminacion() {
    cout << "=== PRUEBA ELIMINACIÓN EN MIN-HEAP ===" << endl;
    monticulo<int> heapMin(false); // min-heap
    
    int elementos[] = {20, 10, 30, 5, 15, 25, 35};
    int n = sizeof(elementos) / sizeof(elementos[0]);
    
    cout << "Insertando: ";
    for (int i = 0; i < n; i++) {
        cout << elementos[i] << " ";
        heapMin.insert(elementos[i]);
    }
    cout << endl;
    
    cout << "Top inicial: " << heapMin.top() << endl;
    
    list<int> inorden1;
    heapMin.inordenEnLista(inorden1);
    cout << "Inorden inicial: ";
    for (list<int>::iterator it = inorden1.begin(); it != inorden1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // Eliminar el mínimo
    cout << "Eliminando el mínimo (" << heapMin.top() << ")..." << endl;
    heapMin.erase(heapMin.top());
    
    cout << "Nuevo top: " << heapMin.top() << endl;
    
    list<int> inorden2;
    heapMin.inordenEnLista(inorden2);
    cout << "Inorden después de eliminar mínimo: ";
    for (list<int>::iterator it = inorden2.begin(); it != inorden2.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // Eliminar un elemento del medio
    cout << "Eliminando 15..." << endl;
    heapMin.erase(15);
    
    list<int> inorden3;
    heapMin.inordenEnLista(inorden3);
    cout << "Inorden después de eliminar 15: ";
    for (list<int>::iterator it = inorden3.begin(); it != inorden3.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    cout << endl;
}

void comparacionMinVsMax() {
    cout << "=== COMPARACIÓN MIN-HEAP vs MAX-HEAP ===" << endl;
    
    int datos[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    int n = sizeof(datos) / sizeof(datos[0]);
    
    // MIN-HEAP
    monticulo<int> minHeap(false);
    cout << "MIN-HEAP - Insertando: ";
    for (int i = 0; i < n; i++) {
        cout << datos[i] << " ";
        minHeap.insert(datos[i]);
    }
    cout << endl;
    
    cout << "Top min-heap: " << minHeap.top() << endl;
    
    list<int> inordenMin;
    minHeap.inordenEnLista(inordenMin);
    cout << "Inorden min-heap: ";
    for (list<int>::iterator it = inordenMin.begin(); it != inordenMin.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // MAX-HEAP
    monticulo<int> maxHeap(true);
    cout << "MAX-HEAP - Insertando: ";
    for (int i = 0; i < n; i++) {
        cout << datos[i] << " ";
        maxHeap.insert(datos[i]);
    }
    cout << endl;
    
    cout << "Top max-heap: " << maxHeap.top() << endl;
    
    list<int> inordenMax;
    maxHeap.inordenEnLista(inordenMax);
    cout << "Inorden max-heap: ";
    for (list<int>::iterator it = inordenMax.begin(); it != inordenMax.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    cout << "¿Los inorden son diferentes? ";
    if (inordenMin.size() == inordenMax.size()) {
        bool iguales = true;
        list<int>::iterator itMin = inordenMin.begin();
        list<int>::iterator itMax = inordenMax.begin();
        
        for (; itMin != inordenMin.end(); ++itMin, ++itMax) {
            if (*itMin != *itMax) {
                iguales = false;
                break;
            }
        }
        cout << (iguales ? "NO (ERROR)" : "SÍ (CORRECTO)") << endl;
    } else {
        cout << "SÍ (tamaños diferentes)" << endl;
    }
    cout << endl;
}

void pruebaMinHeapConDatosOriginales() {
    cout << "=== PRUEBA MIN-HEAP CON DATOS ORIGINALES ===" << endl;
    monticulo<int> heapMin(false); // min-heap
    
    int elementos[] = {21, 19, 14, 5, 13, 10, 12, 2, 1, 6, 11, 8, 7, 3};
    int n = sizeof(elementos) / sizeof(elementos[0]);
    
    cout << "Insertando " << n << " elementos..." << endl;
    for (int i = 0; i < n; i++) {
        heapMin.insert(elementos[i]);
    }
    
    cout << "Top (mínimo): " << heapMin.top() << endl;
    cout << "Tamaño: " << heapMin.size() << endl;
    
    list<int> inorden;
    heapMin.inordenEnLista(inorden);
    
    cout << "Recorrido INORDEN: ";
    for (list<int>::iterator it = inorden.begin(); it != inorden.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // Verificar que el mínimo es correcto
    int minEsperado = elementos[0];
    for (int i = 1; i < n; i++) {
        if (elementos[i] < minEsperado) {
            minEsperado = elementos[i];
        }
    }
    
    cout << "Mínimo esperado: " << minEsperado << endl;
    cout << "Mínimo obtenido: " << heapMin.top() << endl;
    cout << "¿Mínimo correcto? " << (heapMin.top() == minEsperado ? "SÍ" : "NO") << endl;
    cout << endl;
}

void pruebaOperacionesMixtasMinHeap() {
    cout << "=== PRUEBA OPERACIONES MIXTAS MIN-HEAP ===" << endl;
    monticulo<int> heapMin(false);
    
    cout << "add 10" << endl; heapMin.insert(10);
    cout << "add 5" << endl;  heapMin.insert(5);
    cout << "add 15" << endl; heapMin.insert(15);
    cout << "add 3" << endl;  heapMin.insert(3);
    cout << "add 7" << endl;  heapMin.insert(7);
    
    cout << "Top después de inserciones: " << heapMin.top() << endl;
    
    list<int> inorden1;
    heapMin.inordenEnLista(inorden1);
    cout << "Inorden: ";
    for (list<int>::iterator it = inorden1.begin(); it != inorden1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    cout << "del 3" << endl; heapMin.erase(3);
    cout << "Nuevo top: " << heapMin.top() << endl;
    
    list<int> inorden2;
    heapMin.inordenEnLista(inorden2);
    cout << "Inorden después de eliminar 3: ";
    for (list<int>::iterator it = inorden2.begin(); it != inorden2.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    cout << "add 2" << endl; heapMin.insert(2);
    cout << "Nuevo top: " << heapMin.top() << endl;
    
    list<int> inorden3;
    heapMin.inordenEnLista(inorden3);
    cout << "Inorden final: ";
    for (list<int>::iterator it = inorden3.begin(); it != inorden3.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    cout << "PRUEBAS COMPLETAS DE MIN-HEAP" << endl;
    cout << "=============================" << endl << endl;
    
    pruebaMinHeapBasico();
    pruebaMinHeapConStrings();
    pruebaMinHeapEliminacion();
    comparacionMinVsMax();
    pruebaMinHeapConDatosOriginales();
    pruebaOperacionesMixtasMinHeap();
    
    cout << "=== TODAS LAS PRUEBAS COMPLETADAS ===" << endl;
    
    return 0;
}