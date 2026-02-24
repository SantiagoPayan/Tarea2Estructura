/**
 * @file main.cpp
 * @brief Programa principal para demostrar el funcionamiento de una Pila Dinámica genérica
 * @author Santiago Payan Ibarra
 * @author Jose Maria Nuñez Saille
 * @date 2026-02-24
 * 
 * Este programa implementa un menú interactivo que permite probar una estructura de datos
 * tipo Pila (Stack) con tres tipos de datos diferentes:
 * - Números enteros (int)
 * - Texto (string)
 * - Números complejos (clase personalizada)
 */

#include <iostream>
#include <string>
#include "headers/Pila.hpp"

/**
 * @class Complejo
 * @brief Clase que representa un número complejo (parte real + parte imaginaria)
 * 
 * Esta clase cumple el requisito de usar una clase definida por el programador
 * en la estructura de datos Pila. Implementa operadores para entrada/salida.
 */
class Complejo {
private:
    double real;           ///< Parte real del número complejo
    double imaginario;     ///< Parte imaginaria del número complejo
    
public:
    /**
     * @brief Constructor de Complejo
     * @param r Parte real (por defecto 0)
     * @param i Parte imaginaria (por defecto 0)
     */
    Complejo(double r = 0, double i = 0) : real(r), imaginario(i) {}
    
    /**
     * @brief Operador de salida para imprimir un número complejo
     * @param os Flujo de salida (cout)
     * @param c Número complejo a imprimir
     * @return std::ostream& Referencia al flujo de salida
     * 
     * Formato: parte_real+/-parte_imaginaria*i
     * Ejemplo: 3+4i, 5-2i
     */
    friend std::ostream& operator<<(std::ostream& os, const Complejo& c) {
        os << c.real << (c.imaginario >= 0 ? "+" : "") << c.imaginario << "i";
        return os;
    }

    /**
     * @brief Operador de entrada para leer un número complejo del usuario
     * @param is Flujo de entrada (cin)
     * @param c Número complejo donde se almacenarán los datos
     * @return std::istream& Referencia al flujo de entrada
     * 
     * Solicita al usuario que ingrese la parte real e imaginaria por separado
     */
    friend std::istream& operator>>(std::istream& is, Complejo& c) {
        std::cout << "[Ingresa parte real]: ";
        is >> c.real;
        std::cout << "[Ingresa parte imaginaria]: ";
        is >> c.imaginario;
        return is;
    }
};

/**
 * @brief Menú interactivo para operaciones de Pila
 * @tparam T Tipo de dato genérico que almacena la Pila
 * @param pila Referencia a la Pila con la que se va a trabajar
 * 
 * Permite al usuario realizar las siguientes operaciones:
 * - Push: Agregar elementos a la Pila
 * - Pop: Eliminar el elemento del tope
 * - getTop: Ver el elemento en el tope
 * - isEmpty: Verificar si la Pila está vacía
 * - clear: Vaciar completamente la Pila
 * - size: Obtener el número de elementos
 * - getCapacidad: Ver la capacidad actual del arreglo dinámico
 * - print: Imprimir todos los elementos de la Pila
 * - Pruebas de Constructor de copias y Operador de asignación
 * 
 * La función captura excepciones en caso de operaciones inválidas (ej: pop en pila vacía)
 */
template <typename T>
void menuInteractivo(Pila<T>& pila) {
    int opcion;
    do {
        // Mostrar menú principal
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
                // Opción 1: Agregar elemento (Push)
                case 1: {
                    T valor;
                    std::cout << "\n-> Ingresa el valor a agregar:\n";
                    std::cin >> valor;
                    pila.push(valor);
                    std::cout << "Elemento agregado exitosamente.\n";
                    break;
                }
                
                // Opción 2: Eliminar elemento del tope (Pop)
                case 2:
                    pila.pop();
                    std::cout << "\n-> Elemento del tope eliminado.\n";
                    break;
                
                // Opción 3: Ver el elemento del tope
                case 3:
                    std::cout << "\n-> El elemento en el tope es: " << pila.getTop() << "\n";
                    break;
                
                // Opción 4: Verificar si la Pila está vacía
                case 4:
                    std::cout << "\n-> La pila " << (pila.isEmpty() ? "SI" : "NO") << " esta vacia.\n";
                    break;
                
                // Opción 5: Vaciar la Pila
                case 5:
                    pila.clear();
                    std::cout << "\n-> La pila ha sido vaciada.\n";
                    break;
                
                // Opción 6: Obtener cantidad de elementos
                case 6:
                    std::cout << "\n-> La pila tiene " << pila.size() << " elementos.\n";
                    break;
                
                // Opción 7: Obtener capacidad actual del arreglo dinámico
                case 7:
                    std::cout << "\n-> La capacidad actual del arreglo es: " << pila.getCapacidad() << "\n";
                    break;
                
                // Opción 8: Imprimir todos los elementos de la Pila
                case 8:
                    std::cout << "\n";
                    pila.print();
                    break;
                
                // Opción 9: Probar constructor de copias y operador de asignación
                case 9: {
                    std::cout << "\n--- PRUEBA DE COPIA Y ASIGNACION ---\n";
                    
                    // Prueba del constructor de copias
                    Pila<T> copia(pila);
                    std::cout << "1. Pila 'Copia' creada exitosamente. Contenido:\n";
                    copia.print();

                    // Prueba del operador de asignación
                    Pila<T> asignada;
                    asignada = pila;
                    std::cout << "2. Pila 'Asignada' creada exitosamente. Contenido:\n";
                    asignada.print();
                    break;
                }
                
                // Opción 0: Salir del menú
                case 0:
                    std::cout << "\nSaliendo del menu actual...\n";
                    break;
                
                // Opción inválida
                default:
                    std::cout << "\nOpcion no valida.\n";
            }
        } 
        // Captura de excepciones (ej: pop en Pila vacía)
        catch (const std::exception& e) {
            std::cout << "\n[!] EXCEPCION: " << e.what() << "\n";
        }
    } while (opcion != 0);
}

/**
 * @brief Función principal del programa
 * @return int Código de salida (0 = éxito)
 * 
 * Muestra un menú donde el usuario puede seleccionar qué tipo de dato
 * desea probar en la estructura de datos Pila:
 * 1. Números enteros (int)
 * 2. Texto (std::string)
 * 3. Números complejos (clase Complejo)
 * 
 * Para cada tipo de dato, se crea una Pila con capacidad inicial de 2
 * para demostrar rápidamente el redimensionamiento dinámico.
 */
int main() {
    int tipoDato;
    do {
        // Mostrar menú de selección de tipo de dato
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
            // Crear Pila de enteros con capacidad inicial 2
            Pila<int> pilaEnteros(2);
            menuInteractivo(pilaEnteros);
        } 
        else if (tipoDato == 2) {
            // Crear Pila de strings con capacidad inicial 2
            Pila<std::string> pilaTextos(2);
            menuInteractivo(pilaTextos);
        } 
        else if (tipoDato == 3) {
            // Crear Pila de números complejos con capacidad inicial 2
            Pila<Complejo> pilaComplejos(2);
            menuInteractivo(pilaComplejos);
        }

    } while (tipoDato != 0);

    // Mensaje de finalización
    std::cout << "Programa terminado. ¡Hasta luego!\n";
    return 0;
}
