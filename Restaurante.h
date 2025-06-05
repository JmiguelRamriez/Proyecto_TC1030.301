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
    Mesa mesas[10];
    Empleado* empleados[5]; 
    Comida menu[20];
    Orden ordenes[30];
    int total_ordenes;
    int total_empleados;
    int total_comidas;
    int total_mesas;

public:
    Restaurante();
    Restaurante(Mesa m[], int t_m, Empleado* e[], int t_e, Comida c[], int t_c);

    int get_total_mesas();
    int get_total_empleados();
    int get_total_comidas();
    int get_total_ordenes();

    void agregar_mesa(Mesa m);
    void agregar_empleado(Empleado* e); 
    void realizar_tareas_empleados();
    void agregar_comida(Comida c);
    void agregar_orden(Orden o);
    void liberar_empleados();

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

    total_empleados = (t_e <= 5) ? t_e : 5;
    for (int i = 0; i < total_empleados; i++) {
        empleados[i] = e[i]; 
    }

    total_comidas = (t_c <= 20) ? t_c : 20;
    for (int i = 0; i < total_comidas; i++) {
        menu[i] = c[i];
    }

    total_ordenes = 0;
}

// Getters
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
void Restaurante::agregar_mesa(Mesa m) {
    if (total_mesas < 10) {
        mesas[total_mesas++] = m;
    }
}

void Restaurante::agregar_empleado(Empleado* e) {
    if (total_empleados < 5) {
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

void Restaurante::liberar_empleados() {
    for (int i = 0; i < total_empleados; i++) {
        delete empleados[i]; 
    }
}

string Restaurante::mostrar_informacion() {
    string info = "=== INFORMACIÓN DEL RESTAURANTE ===\n";
    info += "Total de mesas: " + to_string(total_mesas) + "\n";
    info += "Total de empleados: " + to_string(total_empleados) + "\n";
    info += "Total de comidas en el menú: " + to_string(total_comidas) + "\n";
    info += "Total de ordenes activas: " + to_string(total_ordenes) + "\n";
    return info;
}
#endif
