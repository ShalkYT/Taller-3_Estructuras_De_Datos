#ifndef MONTICULO_CPP
#define MONTICULO_CPP

#include "monticulo.h"
#include <iostream>
#include <algorithm>

// Implementación de las funciones template

// MONTICULO.H - Implementación de la clase monticulo (heap)

// Función que retorna el índice del padre de un nodo en el heap
template <typename T>
size_t monticulo<T>::padre(size_t i) const { 
    return (i - 1) / 2;  // Fórmula estándar para encontrar el padre en un heap basado en arreglo
}

// Función que retorna el índice del hijo izquierdo de un nodo
template <typename T>
size_t monticulo<T>::hijoIzquierdo(size_t i) const { 
    return 2 * i + 1;  // Fórmula estándar para hijo izquierdo
}

// Función que retorna el índice del hijo derecho de un nodo
template <typename T>
size_t monticulo<T>::hijoDerecho(size_t i) const { 
    return 2 * i + 2;  // Fórmula estándar para hijo derecho
}

// Función de comparación que determina el orden del heap (max-heap o min-heap)
template <typename T>
bool monticulo<T>::comparar(const T& a, const T& b) const {
    if (esMaxHeap) {
        // Para max-heap: retorna true si a es menor que b (necesita intercambio)
        return a < b;
    } else {
        // Para min-heap: retorna true si a es mayor que b (necesita intercambio)
        return a > b;
    }
}

// Función para flotar un elemento hacia arriba (reparar el heap hacia arriba)
template <typename T>
void monticulo<T>::flotar(size_t indice) {
    // Mientras no sea la raíz
    while (indice > 0) {
        size_t indicePadre = padre(indice);
        // Si la relación padre-hijo viola la propiedad del heap
        if (comparar(heap[indicePadre], heap[indice])) {
            // Intercambiar el elemento con su padre
            std::swap(heap[indicePadre], heap[indice]);
            // Continuar verificando desde la nueva posición
            indice = indicePadre;
        } else {
            // Si no hay violación, terminar
            break;
        }
    }
}

// Función para hundir un elemento hacia abajo (reparar el heap hacia abajo)
template <typename T>
void monticulo<T>::hundir(size_t indice) {
    size_t tamaño = heap.size();
    
    while (true) {
        size_t hijoMayor = indice;  // Asumir que el actual es el mayor/menor
        size_t izquierdo = hijoIzquierdo(indice);
        size_t derecho = hijoDerecho(indice);

        // Comparar con hijo izquierdo si existe
        if (izquierdo < tamaño && comparar(heap[hijoMayor], heap[izquierdo])) {
            hijoMayor = izquierdo;  // Hijo izquierdo es mayor/menor
        }
        
        // Comparar con hijo derecho si existe
        if (derecho < tamaño && comparar(heap[hijoMayor], heap[derecho])) {
            hijoMayor = derecho;  // Hijo derecho es mayor/menor
        }

        // Si se encontró un hijo que debe estar arriba
        if (hijoMayor != indice) {
            // Intercambiar con el hijo apropiado
            std::swap(heap[indice], heap[hijoMayor]);
            // Continuar verificando desde la nueva posición
            indice = hijoMayor;
        } else {
            // Si no hay más violaciones, terminar
            break;
        }
    }
}

// Constructor: crea un montículo vacío especificando el tipo (max-heap o min-heap)
template <typename T>
monticulo<T>::monticulo(bool maxHeap) {
    esMaxHeap = maxHeap;
}

// Insertar un nuevo elemento en el montículo
template <typename T>
void monticulo<T>::insert(const T& valor) {
    // Agregar al final del vector
    heap.push_back(valor);
    size_t indice = heap.size() - 1;
    // Flotar el elemento para mantener la propiedad del heap
    flotar(indice);
}

// Eliminar un elemento específico del montículo
template <typename T>
void monticulo<T>::erase(const T& valor) {
    // Buscar el elemento en el vector
    typename std::vector<T>::iterator it = heap.begin();
    size_t indice = 0;
    bool encontrado = false;
    
    // Recorrer el heap para encontrar el elemento
    for (; it != heap.end(); ++it, ++indice) {
        if (*it == valor) {
            encontrado = true;
            break;
        }
    }
    
    // Si no se encontró, terminar
    if (!encontrado) return;
    
    // Reemplazar el elemento con el último elemento del heap
    heap[indice] = heap.back();
    // Eliminar el último elemento
    heap.pop_back();
    
    // Si el elemento eliminado no era el último, reparar el heap
    if (indice < heap.size()) {
        hundir(indice);  // Hundir el elemento recién movido
    }
}

// Obtener el elemento en la cima del montículo (raíz)
template <typename T>
T monticulo<T>::top() const {
    if (heap.empty()) {
        return T();  // Retornar valor por defecto si está vacío
    }
    return heap.front();  // Retornar el primer elemento (raíz)
}

// Verificar si el montículo está vacío
template <typename T>
bool monticulo<T>::empty() const {
    return heap.empty();
}

// Obtener el número de elementos en el montículo
template <typename T>
size_t monticulo<T>::size() const {
    return heap.size();
}

// Función auxiliar recursiva para recorrido inorden
template <typename T>
void monticulo<T>::inordenRecursivo(size_t indice, std::list<T>& lista) const {
    if (indice >= heap.size()) return;
    
    // CORRECTO: izquierda - raíz - derecha
    inordenRecursivo(hijoIzquierdo(indice), lista);  // izquierda
    lista.push_back(heap[indice]);                   // raíz  
    inordenRecursivo(hijoDerecho(indice), lista);    // derecha
}

// Función pública para obtener el recorrido inorden del montículo
template <typename T>
void monticulo<T>::inordenEnLista(std::list<T>& lista) const {
    // Solo realizar el recorrido si el heap no está vacío
    if (!heap.empty()) {
        inordenRecursivo(0, lista);  // Comenzar desde la raíz
    }
}

// Vaciar completamente el montículo
template <typename T>
void monticulo<T>::clear() {
    heap.clear();  // Limpiar el vector interno
}


#endif // MONTICULO_CPP
