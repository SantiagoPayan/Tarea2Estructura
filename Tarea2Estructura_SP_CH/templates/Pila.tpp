#include <iostream>

/**
 * ============================================================================
 * MÉTODOS PRIVADOS - Gestión interna de la estructura
 * ============================================================================
 */

/**
 * Verifica si la pila está llena (alcanzó su capacidad máxima).
 * 
 * @return true si el índice del tope es igual a capacidad - 1, false en caso contrario
 */
template <typename T>
bool Pila<T>::isFull() const {
    return tope == capacidad - 1;
}

/**
 * Duplica la capacidad del arreglo dinámico cuando la pila está llena.
 * Redimensiona el arreglo y copia todos los elementos al nuevo espacio.
 * 
 * Proceso:
 * 1. Multiplica la capacidad por 2
 * 2. Crea un nuevo arreglo con la nueva capacidad
 * 3. Copia todos los elementos del arreglo antiguo al nuevo
 * 4. Libera la memoria del arreglo antiguo
 * 5. Actualiza el puntero para apuntar al nuevo arreglo
 * 
 * Complejidad: O(n) donde n es el número de elementos
 */
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

/**
 * ============================================================================
 * CONSTRUCTORES Y DESTRUCTORES - Ciclo de vida del objeto
 * ============================================================================
 */

/**
 * Constructor de la clase Pila.
 * Inicializa la pila con una capacidad específica.
 * 
 * @param capInicial Capacidad inicial del arreglo (por defecto suele ser una constante)
 * 
 * Inicialización de miembros:
 * - capacidad: se asigna al valor del parámetro
 * - tope: se inicializa a -1 (indica pila vacía)
 * - elementos: se asigna memoria dinámica para 'capInicial' elementos
 */
template <typename T>
Pila<T>::Pila(int capInicial) : capacidad(capInicial), tope(-1) {
    elementos = new T[capacidad];
}

/**
 * Destructor de la clase Pila.
 * Se encarga de liberar la memoria dinámica asignada al arreglo 'elementos'.
 * Se ejecuta automáticamente cuando el objeto se destruye.
 */
template <typename T>
Pila<T>::~Pila() {
    delete[] elementos;
}

/**
 * Constructor de copia.
 * Crea una nueva pila que es copia exacta de otra pila existente.
 * 
 * @param otra Referencia constante a la pila que se desea copiar
 * 
 * Proceso:
 * 1. Copia la capacidad y el índice del tope de la pila original
 * 2. Asigna memoria para el nuevo arreglo
 * 3. Copia elemento por elemento del arreglo original
 * 
 * Complejidad: O(n) donde n es el número de elementos
 */
template <typename T>
Pila<T>::Pila(const Pila<T>& otra) : capacidad(otra.capacidad), tope(otra.tope) {
    elementos = new T[capacidad];
    for (int i = 0; i <= tope; ++i) {
        elementos[i] = otra.elementos[i];
    }
}

/**
 * Operador de asignación.
 * Permite asignar una pila a otra usando el operador '='.
 * Implementa copia profunda (deep copy) de los datos.
 * 
 * @param otra Referencia constante a la pila que se desea copiar
 * @return Referencia a la pila actual (*this) para permitir asignaciones encadenadas
 * 
 * Proceso:
 * 1. Verifica que no sea auto-asignación (this != &otra)
 * 2. Libera la memoria del arreglo antiguo
 * 3. Copia capacidad y tope
 * 4. Asigna nueva memoria y copia todos los elementos
 * 5. Retorna referencia a sí mismo
 * 
 * Nota: La verificación 'this != &otra' evita liberar memoria antes de copiarla
 * Complejidad: O(n) donde n es el número de elementos
 */
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

/**
 * ============================================================================
 * OPERACIONES PÚBLICAS - Funcionalidad de la pila (LIFO)
 * ============================================================================
 */

/**
 * Push: Añade un elemento en la parte superior de la pila.
 * Si la pila está llena, automáticamente se redimensiona.
 * 
 * @param valor Elemento de tipo T que se desea añadir a la pila
 * 
 * Proceso:
 * 1. Verifica si la pila está llena
 * 2. Si está llena, llama a redimensionar() para duplicar la capacidad
 * 3. Incrementa el índice del tope
 * 4. Inserta el nuevo valor en la posición del tope
 * 
 * Complejidad: O(1) amortizado (O(n) solo cuando se redimensiona)
 */
template <typename T>
void Pila<T>::push(T valor) {
    if (isFull()) {
        redimensionar();
    }
    tope++;
    elementos[tope] = valor;
}

/**
 * Pop: Elimina el elemento en la parte superior de la pila.
 * Lanza una excepción si la pila está vacía.
 * 
 * @throws std::underflow_error Si se intenta hacer pop en una pila vacía
 * 
 * Funcionamiento:
 * - Verifica que la pila no esté vacía
 * - Decrementa el índice del tope (borra lógicamente el elemento del tope)
 * - La memoria no se libera, simplemente se marca como "no utilizada"
 * 
 * Nota: Esta es una eliminación lógica, no física. El elemento sigue en memoria
 *       pero el tope ya no lo señala.
 * 
 * Complejidad: O(1)
 */
template <typename T>
void Pila<T>::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Error: La pila esta vacia, no se puede hacer pop.");
    }
    tope--; // Al bajar el tope, "borramos" lógicamente el elemento
}

/**
 * Obtiene el elemento en la parte superior de la pila sin eliminarlo.
 * 
 * @return Copia del elemento en el tope de la pila
 * @throws std::underflow_error Si se intenta acceder al tope de una pila vacía
 * 
 * Complejidad: O(1)
 */
template <typename T>
T Pila<T>::getTop() const {
    if (isEmpty()) {
        throw std::underflow_error("Error: La pila esta vacia, no hay tope.");
    }
    return elementos[tope];
}

/**
 * Verifica si la pila está vacía.
 * 
 * @return true si la pila no contiene elementos, false en caso contrario
 * 
 * Criterio: La pila está vacía si el índice del tope es -1
 * Complejidad: O(1)
 */
template <typename T>
bool Pila<T>::isEmpty() const {
    return tope == -1;
}

/**
 * Vacía la pila, eliminando lógicamente todos los elementos.
 * 
 * Funcionamiento:
 * - Reinicia el índice del tope a -1
 * - No libera la memoria del arreglo (se reutiliza para futuros push)
 * 
 * Complejidad: O(1)
 */
template <typename T>
void Pila<T>::clear() {
    tope = -1; // Vaciar es simplemente reiniciar el índice
}

/**
 * Retorna el número actual de elementos en la pila.
 * 
 * @return Número de elementos actualmente en la pila
 * 
 * Cálculo: tope + 1 (debido a que tope es un índice que comienza en -1)
 * Complejidad: O(1)
 */
template <typename T>
int Pila<T>::size() const {
    return tope + 1;
}

/**
 * Retorna la capacidad actual del arreglo interno.
 * Esta es diferente a size(), que retorna elementos activos.
 * 
 * @return Capacidad máxima actual de la pila
 * 
 * Ejemplo: Una pila con capacidad 10 pero que contiene 3 elementos retornará:
 *          getCapacidad() = 10
 *          size() = 3
 * 
 * Complejidad: O(1)
 */
template <typename T>
int Pila<T>::getCapacidad() const {
    return capacidad;
}

/**
 * Imprime todos los elementos de la pila en consola.
 * Muestra los elementos desde el tope hasta la base.
 * 
 * Formato de salida:
 * - Si está vacía: "La pila esta vacia."
 * - Si contiene elementos: "Elementos en la pila (Tope a Base): [elemento1] [elemento2] ..."
 * 
 * Orden de impresión: De arriba hacia abajo (del tope a la base)
 * 
 * Complejidad: O(n) donde n es el número de elementos
 */
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
