#ifndef MONTICULO_H
#define MONTICULO_H

#include <vector>
#include <list>
#include <string>

template <typename T>
class monticulo {
private:
    std::vector<T> heap;
    bool esMaxHeap;

    // Funciones auxiliares
    size_t padre(size_t i) const;
    size_t hijoIzquierdo(size_t i) const;
    size_t hijoDerecho(size_t i) const;
    bool comparar(const T& a, const T& b) const;
    void flotar(size_t indice);
    void hundir(size_t indice);
    void inordenRecursivo(size_t indice, std::list<T>& lista) const;

public:
    // Constructor
    monticulo(bool maxHeap = true);
    
    // Operaciones básicas
    void insert(const T& valor);
    void erase(const T& valor);
    T top() const;
    bool empty() const;
    size_t size() const;
    void inordenEnLista(std::list<T>& lista) const;
    void clear();
};

// Incluir la implementación de templates
#include "monticulo.cpp"

#endif // MONTICULO_H