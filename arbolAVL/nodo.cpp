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
    int altIzq = (izquierda != nullptr) ? izquierda->altura : 0;
    int altDer = (derecha != nullptr) ? derecha->altura : 0;
    altura = 1 + std::max(altIzq, altDer);
}