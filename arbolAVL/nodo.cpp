template <typename T>
Nodo<T>::Nodo(T valor) {
    dato = valor;
    izquierda = nullptr;
    derecha = nullptr;
    altura = 1;  // Un nodo recién creado tiene altura 1
}

template <typename T>
int Nodo<T>::obtenerAltura(){
    if(this == nullptr) return 0;
    return this->altura;
}

template <typename T>
void Nodo<T>::actualizarAltura(){
    int altIzq = 0;
    int altDer = 0;
    
    if (izquierda != nullptr) {
        altIzq = izquierda->altura;
    }
    
    if (derecha != nullptr) {
        altDer = derecha->altura;
    }
    
    altura = 1 + std::max(altIzq, altDer);
}
