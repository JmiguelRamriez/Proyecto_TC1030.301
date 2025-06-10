/*
* Mesa.h
* [Jose Miguel Ramirez Gutierrez]
* [A01712628]
* [09/06/2025]
*
* Clase Mesa para gestionar mesas en un restaurante.
* Contiene atributos como número, capacidad, estado y cliente asignado.
* Proporciona métodos para asignar clientes, liberar mesas 
* y mostrar información detallada.
*/
#ifndef MESA_H
#define MESA_H
#include <iostream>
#include <string>
#include "Cliente.h"

using namespace std;

class Mesa{
    private:
        int numero; // Número identificador de la mesa
        int capacidad; // Capacidad máxima de personas
        bool estado; // Estado (ocupada/libre)
        Cliente* cliente_actual; // Puntero al cliente actual asignado
    public:
        // Constructores
        Mesa();
        Mesa(int n, int c, bool e);

        // Getters
        int get_numero();
        int get_capacidad();
        bool get_estado();
        Cliente* get_cliente_actual();

        // Setters
        void set_numero(int n);
        void set_capacidad(int c);
        void set_estado(bool e);
        void asignar_cliente(Cliente* c);
                
        // Metodo
        string informacion();
        void liberar_mesa();
};

// Constructor por defecto
Mesa::Mesa(){
    numero = 0;
    capacidad = 0;
    estado = false;
    cliente_actual = nullptr; // Inicializa el puntero a nullptr
}

// Constructor con parámetros
Mesa::Mesa(int n, int c, bool e)
: numero(n), capacidad(c), estado(e){}


int Mesa::get_numero(){
    return numero;
}

int Mesa::get_capacidad(){
    return capacidad;
}

bool Mesa::get_estado(){
    return estado;
}

// Nuevo getter implementado
Cliente* Mesa::get_cliente_actual() {
    return cliente_actual;
}

void Mesa::set_numero(int n){
    numero = n;
}

void Mesa::set_capacidad(int c){
    capacidad = c;
}

void Mesa::set_estado(bool e){
    estado = e;
}

void Mesa::liberar_mesa() {
    if (estado) {
        estado = false;
        cliente_actual = nullptr;  // Se mantiene igual (no se libera memoria aquí)
        cout << "Mesa #" << numero << " liberada correctamente." << endl;
    } else {
        cout << "La mesa #" << numero << " ya está libre." << endl;
    }
}

string Mesa::informacion() {
    string info = "Mesa #" + to_string(numero) +
                "\nCapacidad: " + to_string(capacidad) +
                "\nEstado: " + (estado ? "Ocupada" : "Libre");
    
    if (estado && cliente_actual != nullptr) {
        info += "\nCliente: " + cliente_actual->get_nombre();
        info += "\nOrden:\n" + cliente_actual->get_orden().informacion();
    }
    return info;
}

void Mesa::asignar_cliente(Cliente* c) { 
    if (c != nullptr) {  // Validación añadida
        estado = true;
        cliente_actual = c;
    }
}
#endif