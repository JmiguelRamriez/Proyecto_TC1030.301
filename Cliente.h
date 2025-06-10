/*
* Cliente.h
* [Jose Miguel Ramirez Gutierrez]
* [A01712628]
* [09/06/2025] 
*
* Clase Cliente que representa a un cliente en un restaurante.
* Incluye información sobre el nombre del cliente, la mesa asignada y la orden realizada.
* Permite al cliente hacer pedidos y pagar la cuenta.
*/

#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <string>
#include "Orden.h"

using namespace std;

class Cliente{
    private:
        string nombre; // Nombre del cliente
        string mesa_asignada; // Mesa asignada al cliente
        Orden orden; // Orden actual del cliente
    public:
        // Constructores
        Cliente();
        Cliente(string nom, string m_a, Orden o); 

        // Getters
        string get_nombre();
        string get_mesa_asignada();
        Orden get_orden();

        // Setters
        void set_nombre(string nom);
        void set_mesa_asignada(string m_a);
        void set_orden(Orden o);

        // Métodos de funcionalidad
        void pagar_cuenta();    // Procesa el pago de la orden
};

// Constructor por defecto
Cliente::Cliente(){
    nombre = "";
    mesa_asignada = "";
}

// Constructor con parámetros
Cliente::Cliente(string nom, string m_a, Orden o): 
nombre(nom), mesa_asignada(m_a), orden(o){}

string Cliente::get_nombre(){
    return nombre;
}

string Cliente::get_mesa_asignada(){
    return mesa_asignada;
}

Orden Cliente::get_orden(){
    return orden;
}

void Cliente::set_nombre(string nom){
    nombre = nom;
}

void Cliente::set_mesa_asignada(string m_a){
    mesa_asignada = m_a;
}

void Cliente:: set_orden(Orden o){
    orden = o;
}

// Método para hacer un pedido
void Cliente::pagar_cuenta() {
    if (orden.get_estado()) {
        float total = orden.calcular_total();
        cout << nombre << " ha pagado $" << total << " por su orden." << endl;
        // Liberar mesa asociada
    } else {
        cout << "La orden no estalista para pagar." << endl;
    }
}

#endif