#include <iostream>
#include <string>
#include "Mesa.h"
#include "Empleado.h"
#include "Comida.h"
#include "Orden.h"
#include "Cliente.h"

using namespace std;

class Restaurante{
    private:
    Mesa mesas[10];
    Empleado empleados[5];
    Comida menu[20];
    Orden ordenes[30];
    int total_ordenes;
    int total_empleados;
    int total_comidas;
    int total_mesas;
    
public:
    Restaurante();
    Restaurante(Mesa m[], int t_m, Empleado e[], int t_e, Comida c[], int t_c);


    int get_total_mesas();
    int get_total_empleados();
    int get_total_comidas();
    int get_total_ordenes();

    void agregar_mesa(Mesa m);
    void agregar_empleado(Empleado e);
    void agregar_comida(Comida c);
    void agregar_orden(Orden o);

    void mostrar_informacion();
};

Restaurante::Restaurante() {
    total_ordenes = 0;
    total_empleados = 0;
    total_comidas = 0;
    total_mesas = 0;
}

Restaurante::Restaurante(Mesa m[], int t_m, Empleado e[], int t_e, Comida c[], int t_c) {
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

void Restaurante::agregar_mesa(Mesa m) {
    if (total_mesas < 10) {
        mesas[total_mesas++] = m;
    }
}

void Restaurante::agregar_empleado(Empleado e) {
    if (total_empleados < 5) {
        empleados[total_empleados++] = e;
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

void Restaurante::mostrar_informacion() {
    cout << "Total de mesas: " << total_mesas << endl;
    cout << "Total de empleados: " << total_empleados << endl;
    cout << "Total de comidas en el menú: " << total_comidas << endl;
    cout << "Total de ordenes activas: " << total_ordenes << endl;
}