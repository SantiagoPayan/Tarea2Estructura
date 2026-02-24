#include <iostream>

// --- Métodos Privados ---
template <typename T>
bool Pila<T>::isFull() const {
    return tope == capacidad - 1;
}

template <typename T>
void Pila<T>::redimensionar() {
    capacidad *= 2; // Se duplica la capacidad
    T* nuevoArreglo = new T[capacidad];

    // Copiar los elementos al nuevo arreglo
    for (int i = 0; i <= tope; ++i) {
        nuevoArreglo[i] = elementos[i];
    }

    delete[] elementos; // Liberar memoria vieja
    elementos = nuevoArreglo; // Apuntar al nuevo bloque
}

// --- Buen funcionamiento de la clase ---
template <typename T>
Pila<T>::Pila(int capInicial) : capacidad(capInicial), tope(-1) {
    elementos = new T[capacidad];
}

template <typename T>
Pila<T>::~Pila() {
    delete[] elementos;
}

template <typename T>
Pila<T>::Pila(const Pila<T>& otra) : capacidad(otra.capacidad), tope(otra.tope) {
    elementos = new T[capacidad];
    for (int i = 0; i <= tope; ++i) {
        elementos[i] = otra.elementos[i];
    }
}

template <typename T>
Pila<T>& Pila<T>::operator=(const Pila<T>& otra) {
    if (this != &otra) {
        delete[] elementos;
        capacidad = otra.capacidad;
        tope = otra.tope;
        elementos = new T[capacidad];
        for (int i = 0; i <= tope; ++i) {
            elementos[i] = otra.elementos[i];
        }
    }
    return *this;
}

// --- Operaciones Públicas ---
template <typename T>
void Pila<T>::push(T valor) {
    if (isFull()) {
        redimensionar();
    }
    tope++;
    elementos[tope] = valor;
}

template <typename T>
void Pila<T>::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Error: La pila esta vacia, no se puede hacer pop.");
    }
    tope--; // Al bajar el tope, "borramos" lógicamente el elemento
}

template <typename T>
T Pila<T>::getTop() const {
    if (isEmpty()) {
        throw std::underflow_error("Error: La pila esta vacia, no hay tope.");
    }
    return elementos[tope];
}

template <typename T>
bool Pila<T>::isEmpty() const {
    return tope == -1;
}

template <typename T>
void Pila<T>::clear() {
    tope = -1; // Vaciar es simplemente reiniciar el índice
}

template <typename T>
int Pila<T>::size() const {
    return tope + 1;
}

template <typename T>
int Pila<T>::getCapacidad() const {
    return capacidad;
}

template <typename T>
void Pila<T>::print() const {
    if (isEmpty()) {
        std::cout << "La pila esta vacia." << std::endl;
        return;
    }
    std::cout << "Elementos en la pila (Tope a Base): ";
    for (int i = tope; i >= 0; --i) {
        std::cout << "[" << elementos[i] << "] ";
    }
    std::cout << std::endl;
}
