# Tarea 2: Implementación de una Pila Dinámica Genérica en C++

## 📌 Descripción del Proyecto
Este proyecto implementa una estructura de datos de **Pila (Stack)** utilizando **Plantillas (Templates)** en C++. La pila está construida internamente sobre un **arreglo dinámico** que ajusta su capacidad automáticamente. Cuando la pila se llena, el arreglo duplica su tamaño para asegurar un rendimiento óptimo y un correcto manejo de la memoria.

## ⚙️ Características y Funcionalidades
La clase `Pila<T>` incluye la implementación de los siguientes recursos:
* **Los 4 grandes de C++:** Constructor por defecto, Destructor, Constructor de copias y Operador de asignación sobrecargado (realizando copias profundas de la memoria dinámica).
* **Operaciones estándar:** * `push()`: Agrega un elemento (y redimensiona si es necesario).
  * `pop()`: Elimina el elemento en el tope.
  * `getTop()`: Devuelve el valor del tope sin eliminarlo.
  * `isEmpty()`: Verifica si la pila está vacía.
  * `clear()`: Vacía la pila lógicamente.
* **Operaciones de utilería:** `size()` (número de elementos actuales), `getCapacidad()` (tamaño real del arreglo dinámico) y `print()` (impresión desde el tope hasta la base).

## 🗂️ Estructura de Archivos
El proyecto está separado en múltiples archivos siguiendo las buenas prácticas de C++ para plantillas:
* `main.cpp`: Contiene el código cliente y un menú interactivo genérico.
* `headers/Pila.hpp`: Contiene la declaración de la clase y sus atributos (`capacidad`, `tope` y el puntero `elementos`).
* `templates/Pila.tpp` (o en la ruta donde lo hayas guardado): Contiene la implementación lógica de los métodos de la plantilla.

## 🧪 Pruebas Realizadas
El programa cliente (`main.cpp`) cuenta con un menú interactivo que permite probar **todos los métodos** de la clase `Pila` utilizando 3 tipos de datos distintos:
1. `int` (Números enteros).
2. `std::string` (Cadenas de texto).
3. `Complejo` (Clase personalizada definida por el programador con sobrecarga de operadores de flujo `<<` y `>>`).

## 🚀 Cómo Compilar y Ejecutar (Linux / Ubuntu)

Para compilar el proyecto utilizando el compilador GNU de C++ (`g++`), abre tu terminal en la carpeta principal del proyecto y ejecuta el siguiente comando:

```bash
g++ main.cpp -o tarea2_pila
