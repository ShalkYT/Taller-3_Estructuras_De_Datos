#include "arbolAVL.h"
#include <stack>

// Constructor
template <typename T>
arbolAVL<T>::arbolAVL() {
    Raiz = nullptr;
}

// Funciones que retornan el balance entre los hijos de un nodo
template <typename T>
int arbolAVL<T>::balance(Nodo<T>* n){
    // Declaracion de variables
    int i, d;

    // Caso en el que el nodo es nulo
    if(n == nullptr) return 0;
    
    // Caso en el que el hijo izquierdo es nulo
    if(n->izquierda == nullptr){ i = 0; }
    // Caso en el que el hijo izquierdo no es nulo
    else i = n->izquierda->obtenerAltura();

    // Caso en el que el hijo derecho es nulo
    if(n->derecha == nullptr){d = 0;
    // Caso en el que el hijo derecho no es nulo
    }else d = n->derecha->obtenerAltura();

    // Retornar la diferencia entre las alturas
    return i-d;
}

// Funcion de rotacion a la derecha
template <typename T>
void arbolAVL<T>::rotarDerecha(Nodo<T>* &n){
    // pasos de la rotacion
    Nodo<T>* aux = n->izquierda;
    n->izquierda = aux->derecha;
    aux->derecha = n;

    n->actualizarAltura();  // Actualizar altura del nodo rotado
    aux->actualizarAltura(); // Actualizar altura de la nueva raíz
    n = aux;
}

// Funcion de rotacion a la izquierda
template <typename T>
void arbolAVL<T>::rotarIzquierda(Nodo<T>* &n){
    //pasos de la rotacion
    Nodo<T>* aux = n->derecha;
    n->derecha = aux->izquierda;
    aux->izquierda = n;
    n->actualizarAltura();  // Actualizar altura del nodo rotado
    aux->actualizarAltura(); // Actualizar altura de la nueva raíz
    n = aux;
}

// TODO #04: Implementar las funciones de insercion y eiminacion del arbolAVL
// Funcion de insercion auxiliar recursiva (más estable)
template <typename T>
void arbolAVL<T>::insert(Nodo<T>* &n, T dato){
    // Caso base: insertar en una posicion vacia
    if(n == nullptr){
        n = new Nodo<T>(dato);
        return;
    }
    
    // Recorrer el arbol para encontrar la posicion correcta
    if(dato < n->dato){
        insert(n->izquierda, dato); // Utilizar recursividad para insertar en el subarbol izquierdo
    }else if(dato > n->dato){
        insert(n->derecha, dato); // Utilizar recursividad para insertar en el subarbol derecho
    }else{
        return; // Dato duplicado
    }

    int balanceFactor = balance(n); // Obtener el factor de balance del nodo actual

    // Dependiendo del factor de balance  comparaciones, realizar las rotaciones necesarias

    // Rotación simple derecha
    if (balanceFactor > 1 && dato < n->izquierda->dato)
        rotarDerecha(n);

    // Rotación simple izquierda
    if (balanceFactor < -1 && dato > n->derecha->dato)
        rotarIzquierda(n);

    // Rotación doble izquierda-derecha
    if (balanceFactor > 1 && dato > n->izquierda->dato) {
        rotarIzquierda(n->izquierda);
        rotarDerecha(n);
    }

    // Rotación doble derecha-izquierda
    if (balanceFactor < -1 && dato < n->derecha->dato) {
        rotarDerecha(n->derecha);
        rotarIzquierda(n);
    }
}

// Funcion para insertar, utiliza la funcion privada insertar
template <typename T>
void arbolAVL<T>::insert(T dato){
    insert(Raiz, dato);
}

// Funcion para eliminar un nodo (recursiva - más estable)
template <typename T>
void arbolAVL<T>::erase(Nodo<T>* &n, T dato){
    // Caso base, nodo nulo
    if(n == nullptr) return;

    // Buscar el nodo a eliminar
    if(dato < n->dato){
        erase(n->izquierda, dato); // Utilizar recursividad para buscar en el subarbol izquierdo
    }else if(dato > n->dato){
        erase(n->derecha, dato); // Utilizar recursividad para buscar en el subarbol derecho
    }else{
        // Nodo encontrado
        // Caso con un solo hijo o sin hijos
        if(n->izquierda == nullptr || n->derecha == nullptr){
            Nodo<T>* temp;
            if (n->izquierda) // caso el hijo izquierdo no es nulo
                temp = n->izquierda;
            else // caso ambos hijos son nulos o el hijo derecho no es nulo
                temp = n->derecha; 

            if(temp == nullptr){ // caso ambos hijos son nulos
                temp = n;
                n = nullptr;
            }else{ // caso un solo hijo no es nulo
                *n = *temp;
            }
            delete temp; // Eliminar el nodo
        }else{
            // Nodo con dos hijos: obtener sucesor inorden
            Nodo<T>* temp = n->derecha;
            while(temp->izquierda != nullptr){
                temp = temp->izquierda;
            }
            n->dato = temp->dato;
            erase(n->derecha, temp->dato);
        }
    }

    // Si el árbol tenía solo un nodo
    if(n == nullptr) return;

    // Obtener el factor de balance del nodo actual para verificar si está desbalanceado
    int balanceFactor = balance(n);

    // Caso rotar simple derecha
    if(balanceFactor > 1 && balance(n->izquierda) >= 0)
        rotarDerecha(n);

    // Caso rotar doble izquierda-derecha
    if(balanceFactor > 1 && balance(n->izquierda) < 0){
        rotarIzquierda(n->izquierda);
        rotarDerecha(n);
    }

    // Caso rotar simple izquierda
    if(balanceFactor < -1 && balance(n->derecha) <= 0)
        rotarIzquierda(n);

    // Caso rotar doble derecha-izquierda
    if(balanceFactor < -1 && balance(n->derecha) > 0){
        rotarDerecha(n->derecha);
        rotarIzquierda(n);
    }
}

// Funcion para eliminar
template <typename T>
void arbolAVL<T>::erase(T dato){
    erase(Raiz, dato);
}

// Funcion para obtener el valor de la raiz
template <typename T>
T arbolAVL<T>::obtenerRaiz() {
    if (Raiz != nullptr) {
        return Raiz->dato;
    }
    throw std::runtime_error("El árbol está vacío");
}

// Funcion para obtener la altura del arbol
template <typename T>
int arbolAVL<T>::obtenerAltura() {
    if (Raiz != nullptr) {
        return Raiz->obtenerAltura();
    }
    return 0;
}

// Funcion para obtener el balance de la raiz
template <typename T>
int arbolAVL<T>::obtenerBalanceRaiz() {
    return balance(Raiz);
}

// Funcion de recorrido inOrden iterativa
template <typename T>
void arbolAVL<T>::inorden(Nodo<T>* raiz, std::list<T>& lista) {
    if(raiz == nullptr) return;

    // Pila para simular la recursividad
    std::stack<Nodo<T>*> pila;
    Nodo<T>* actual = raiz;

    while(actual != nullptr || !pila.empty()){
        // Ir al nodo más a la izquierda
        while(actual != nullptr){
            pila.push(actual);
            actual = actual->izquierda;
        }

        // El actual es nullptr, tomar el nodo de la pila
        actual = pila.top();
        pila.pop();

        // Procesar el nodo
        lista.push_back(actual->dato);

        // Ir al subárbol derecho
        actual = actual->derecha;
    }
}

/*
Otra implementación del recorrido inOrden usando recursividad, esta se adapta un poco
mas a la definicion vista en clase del inOrden en la que veiamos que se recorre primero
el hijo izquierdo, luego el nodo y finalmente el hijo derecho, pero puede ser algo mas 
dificil de entender debido a la recursividad.

template <typename T>
void arbolAVL<T>::inorden(Nodo<T>* raiz, std::list<T>& lista) {
    if(raiz == nullptr) return;
    // Recorrer el subarbol izquierdo
    inorden(raiz->izquierda, lista);
    // Procesar el nodo actual
    lista.push_back(raiz->dato);
    // Recorrer el subarbol derecho
    inorden(raiz->derecha, lista);
}
*/

// Funcion publica para el recorrido inOrden
template <typename T>
void arbolAVL<T>::inordenEnLista(std::list<T>& lista) {
    // Limpiar la lista antes de llenarla
    lista.clear();
    inorden(Raiz, lista);
}