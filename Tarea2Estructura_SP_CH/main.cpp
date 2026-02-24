#include <iostream>
#include <string>
#include "headers/Pila.hpp"

// Clase definida por el programador (Requisito de la tarea)
class Complejo {
private:
    double real;
    double imaginario;
public:
    Complejo(double r = 0, double i = 0) : real(r), imaginario(i) {}
    
    // Para imprimir en la Pila (cout << complejo)
    friend std::ostream& operator<<(std::ostream& os, const Complejo& c) {
        os << c.real << (c.imaginario >= 0 ? "+" : "") << c.imaginario << "i";
        return os;
    }

    // Para que el usuario pueda escribirlo (cin >> complejo)
    friend std::istream& operator>>(std::istream& is, Complejo& c) {
        std::cout << "[Ingresa parte real]: ";
        is >> c.real;
        std::cout << "[Ingresa parte imaginaria]: ";
        is >> c.imaginario;
        return is;
    }
};

// --- MENÚ INTERACTIVO ---
template <typename T>
void menuInteractivo(Pila<T>& pila) {
    int opcion;
    do {
        std::cout << "\n=======================================\n";
        std::cout << "          MENU DE PILA DINAMICA        \n";
        std::cout << "=======================================\n";
        std::cout << "1. Push (Agregar elemento)\n";
        std::cout << "2. Pop (Eliminar tope)\n";
        std::cout << "3. Ver Tope (getTop)\n";
        std::cout << "4. Esta vacia? (isEmpty)\n";
        std::cout << "5. Vaciar Pila (clear)\n";
        std::cout << "6. Ver numero de elementos (size)\n";
        std::cout << "7. Ver capacidad actual\n";
        std::cout << "8. Imprimir toda la pila\n";
        std::cout << "9. Probar Constructor de Copias y Asignacion\n";
        std::cout << "0. Salir y cambiar de tipo de dato\n";
        std::cout << "Elige una opcion: ";
        std::cin >> opcion;

        try {
            switch(opcion) {
                case 1: {
                    T valor;
                    std::cout << "\n-> Ingresa el valor a agregar:\n";
                    std::cin >> valor;
                    pila.push(valor);
                    std::cout << "Elemento agregado exitosamente.\n";
                    break;
                }
                case 2:
                    pila.pop();
                    std::cout << "\n-> Elemento del tope eliminado.\n";
                    break;
                case 3:
                    std::cout << "\n-> El elemento en el tope es: " << pila.getTop() << "\n";
                    break;
                case 4:
                    std::cout << "\n-> La pila " << (pila.isEmpty() ? "SI" : "NO") << " esta vacia.\n";
                    break;
                case 5:
                    pila.clear();
                    std::cout << "\n-> La pila ha sido vaciada.\n";
                    break;
                case 6:
                    std::cout << "\n-> La pila tiene " << pila.size() << " elementos.\n";
                    break;
                case 7:
                    std::cout << "\n-> La capacidad actual del arreglo es: " << pila.getCapacidad() << "\n";
                    break;
                case 8:
                    std::cout << "\n";
                    pila.print();
                    break;
                case 9: {
                    std::cout << "\n--- PRUEBA DE COPIA Y ASIGNACION ---\n";
                    Pila<T> copia(pila); // Constructor de copias
                    std::cout << "1. Pila 'Copia' creada exitosamente. Contenido:\n";
                    copia.print();

                    Pila<T> asignada;
                    asignada = pila;     // Operador de asignación
                    std::cout << "2. Pila 'Asignada' creada exitosamente. Contenido:\n";
                    asignada.print();
                    break;
                }
                case 0:
                    std::cout << "\nSaliendo del menu actual...\n";
                    break;
                default:
                    std::cout << "\nOpcion no valida.\n";
            }
        } catch (const std::exception& e) {
            // Esto atrapará las excepciones si el usuario hace "pop" en una pila vacía
            std::cout << "\n[!] EXCEPCION: " << e.what() << "\n";
        }
    } while (opcion != 0);
}

// --- PROGRAMA PRINCIPAL ---
int main() {
    int tipoDato;
    do {
        std::cout << "\n***************************************\n";
        std::cout << "  SELECCIONA EL TIPO DE DATO A PROBAR  \n";
        std::cout << "***************************************\n";
        std::cout << "1. Numeros Enteros (int)\n";
        std::cout << "2. Textos (string)\n";
        std::cout << "3. Numeros Complejos (Clase personalizada)\n";
        std::cout << "0. Salir del programa\n";
        std::cout << "Elige una opcion: ";
        std::cin >> tipoDato;

        if (tipoDato == 1) {
            Pila<int> pilaEnteros(2); // Empezamos con capacidad 2 para probar el redimensionamiento rápido
            menuInteractivo(pilaEnteros);
        } 
        else if (tipoDato == 2) {
            Pila<std::string> pilaTextos(2);
            menuInteractivo(pilaTextos);
        } 
        else if (tipoDato == 3) {
            Pila<Complejo> pilaComplejos(2);
            menuInteractivo(pilaComplejos);
        }

    } while (tipoDato != 0);

    std::cout << "Programa terminado. ¡Hasta luego!\n";
    return 0;
}
