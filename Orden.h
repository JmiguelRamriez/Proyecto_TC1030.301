/*
* Orden.h
* [Jose Miguel Ramirez Gutierrez]
* [A01712628] 
* [09/06/2025]
*
* Clase Orden que representa un pedido realizado por un cliente.
* Contiene información sobre el número de orden, lista de comidas,
* cantidad de items y estado de preparación.
* Proporciona métodos para gestionar y mostrar información de la orden.
*/
#ifndef ORDEN_H
#define ORDEN_H

#include <iostream>
#include <string>
#include "Comida.h"

using namespace std;

class Orden {
    private:
        int numero_orden;
        Comida listaComida[10]; // Lista de comidas en la orden (máx 10)
        int cantidad_comidas; // Contador de comidas actuales
        bool estado; // Estado de la orden (entregada/pendiente)

    public:
        // Constructores
        Orden();
        Orden(int numero_orden, bool estado);

        // Getters
        int get_numero_orden();
        bool get_estado();
        
        // Setters
        void set_numero_orden(int n_o);
        void set_estado(bool e);
        void agregar_comida(Comida& comida);

        // Métodos
        int calcular_total();
        string informacion();
};

// Constructor por defecto
Orden::Orden() {
    numero_orden = 0;
    cantidad_comidas = 0;
    estado = false;
}

// Constructor parametrizado
Orden::Orden(int n_o, bool e) 
: numero_orden(n_o), estado(e) {
    cantidad_comidas = 0;
}

int Orden::get_numero_orden() {
    return numero_orden;
}

bool Orden::get_estado() {
    return estado;
}

int Orden::calcular_total() {
    int total = 0.0;
    for (int i = 0; i < cantidad_comidas; i++) {
        total += listaComida[i].get_precio();
    }
    return total;
}

void Orden::set_numero_orden(int n_o) {
    numero_orden = n_o;
}

void Orden::set_estado(bool e) {
    estado = e;
}

void Orden::agregar_comida(Comida& comida) {
    if (cantidad_comidas < 10) {
        listaComida[cantidad_comidas] = comida;
        cantidad_comidas++;
    } else {
        cout << "No se pueden agregar mas comidas. Orden llena." << endl;
    }
}

string Orden::informacion() {
    string info = "Orden #" + to_string(numero_orden) + "\n";
    info += "Estado: " + string(estado ? "Entregada" : "Pendiente") + "\n";
    info += "Comidas:\n";
    for (int i = 0; i < cantidad_comidas; i++) {
        info += "- " + listaComida[i].get_nombre() +
        " | $" + to_string(listaComida[i].get_precio()) +
        " | Tiempo: " + to_string(listaComida[i].get_tiempo_preparacion()) +
        " min\n";
    }
    info += "Total: $" + to_string(calcular_total()) + "\n";
    return info;
}

#endif
