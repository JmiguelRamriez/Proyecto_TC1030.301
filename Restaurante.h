/*
* Restaurante.h
* [Jose Miguel Ramirez Gutierrez]
* [A01712628]
* [09/06/2025]
*
* Clase principal que gestiona todas las operaciones del restaurante.
* Controla las mesas, empleados, menú y órdenes del sistema.
* Permite agregar, mostrar y gestionar estos elementos.
* Coordina la interacción entre todas las demás clases del sistema.
*/

#ifndef RESTAURANTE_R
#define RESTAURANTE_R
#include <iostream>
#include <string>
#include <sstream>
#include "Mesa.h"
#include "Empleado.h"
#include "Comida.h"
#include "Orden.h"
#include "Cliente.h"

using namespace std;

class Restaurante {
    private:
        // Arreglos para almacenamiento
        Mesa mesas[10]; // Arreglo de mesas (máx 10)
        Empleado* empleados[6]; // Arreglo de punteros a empleados (máx 6)
        Comida menu[20]; // Arreglo de comidas en el menú (máx 20)
        Orden ordenes[30]; // Arreglo de órdenes activas (máx 30)
        
        // Contadores
        int total_ordenes;
        int total_empleados;
        int total_comidas;
        int total_mesas;

    public:
        // Constructores
        Restaurante();
        Restaurante(Mesa m[], int t_m, Empleado* e[], int t_e, Comida c[], int t_c);

        // Getters
        int get_total_mesas();
        int get_total_empleados();
        int get_total_comidas();
        int get_total_ordenes();

        // Métodos de gestión
        void agregar_mesa(Mesa& m);
        void agregar_empleado(Empleado* e); 
        void realizar_tareas_empleados();
        void agregar_comida(Comida c);
        void agregar_orden(Orden o);
        void eliminar_orden(int numero_orden);
        
        // Métodos de limpieza
        void liberar_empleados();
        
        // Métodos de información
        string mostrar_informacion();
};

// Constructor por defecto
Restaurante::Restaurante() {
    total_ordenes = 0;
    total_empleados = 0;
    total_comidas = 0;
    total_mesas = 0;
}

// Constructor con parámetros
Restaurante::Restaurante(Mesa m[], int t_m, Empleado* e[], int t_e, Comida c[], int t_c) {
    total_mesas = (t_m <= 10) ? t_m : 10;
    for (int i = 0; i < total_mesas; i++) {
        mesas[i] = m[i];
    }

    total_empleados = (t_e <= 6) ? t_e : 6;
    for (int i = 0; i < total_empleados; i++) {
        empleados[i] = e[i]; 
    }

    total_comidas = (t_c <= 20) ? t_c : 20;
    for (int i = 0; i < total_comidas; i++) {
        menu[i] = c[i];
    }

    total_ordenes = 0;
}

int Restaurante::get_total_mesas() {
    return total_mesas; 
}
int Restaurante::get_total_empleados() { 
    return total_empleados; 
}
int Restaurante::get_total_comidas() {
    return total_comidas; 
}
int Restaurante::get_total_ordenes() { 
    return total_ordenes; 
}

// Agregar elementos
void Restaurante::agregar_mesa(Mesa &m) {
    if (total_mesas < 10) {
        mesas[total_mesas++] = m;
    }
}

void Restaurante::agregar_empleado(Empleado* e) {
    if (total_empleados < 6) {
        empleados[total_empleados++] = e;
    }
}

void Restaurante::realizar_tareas_empleados() {
    for (int i = 0; i < total_empleados; i++) {
        if (empleados[i] != nullptr) {
            empleados[i]->realizar_tarea();
        }
    }
}

void Restaurante::agregar_comida(Comida c) {
    if (total_comidas < 20) {
        menu[total_comidas++] = c;
    }
}

void Restaurante::agregar_orden(Orden o) {
    if (total_ordenes < 30) {
        ordenes[total_ordenes++] = o;
    }
}

void Restaurante::eliminar_orden(int numero_orden) {
    for (int i = 0; i < total_ordenes; i++) {
        if (ordenes[i].get_numero_orden() == numero_orden) {
            // Mover órdenes posteriores
            for (int j = i; j < total_ordenes - 1; j++) {
                ordenes[j] = ordenes[j + 1];
            }
            total_ordenes--;
        }
    }
}

void Restaurante::liberar_empleados() {
    for (int i = 0; i < total_empleados; i++) {
        delete empleados[i];
        empleados[i] = nullptr; 
    }
    total_empleados = 0; 
}

string Restaurante::mostrar_informacion() {
    string info = "=== INFORMACION DEL RESTAURANTE ===\n";
    info += "Total de mesas: " + to_string(total_mesas) + "\n";
    info += "Total de empleados: " + to_string(total_empleados) + "\n";
    info += "Total de comidas en el menú: " + to_string(total_comidas) + "\n";
    info += "Total de ordenes activas: " + to_string(total_ordenes) + "\n";
    return info;
}
#endif
