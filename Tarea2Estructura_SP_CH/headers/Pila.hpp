#ifndef PILA_HPP
#define PILA_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Pila {
private:
    int capacidad; // Tamaño del arreglo
    int tope;      // Índice del elemento superior (-1 si está vacía)
    T* elementos;  // Puntero al arreglo dinámico

    // Métodos privados
    void redimensionar();
    bool isFull() const;

public:
    // Buen funcionamiento (Los 4 grandes de C++)
    Pila(int capInicial = 2); // Capacidad inicial pequeña para probar el redimensionamiento
    Pila(const Pila<T>& otra);
    Pila<T>& operator=(const Pila<T>& otra);
    ~Pila();

    // Operaciones de la pila
    void push(T valor);
    void pop();
    T getTop() const;
    bool isEmpty() const;
    void clear();
    int size() const;
    int getCapacidad() const;
    void print() const;
};

// Inclusión obligatoria del código de la plantilla
#include "../templates/Pila.tpp"

#endif
