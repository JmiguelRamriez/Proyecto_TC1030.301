#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <string>
#include "Orden.h"

using namespace std;

class Cliente{
    private:
    string nombre;
    string mesa_asignada;
    Orden orden;

    public:
    Cliente();
    Cliente(string nom, string m_s, Orden o);

    string get_nombre();
    string get_mesa_asignada();
    Orden get_orden();

    void set_nombre(string nom);
    void set_mesa_asignada(string m_a);
    void set_orden(Orden o);
    void hacer_pedido(Orden& o);
    void pagar_cuenta();
};

Cliente::Cliente(){
    nombre = "";
    mesa_asignada = "";
}

Cliente::Cliente(string nom, string m_a, Orden o): nombre(nom), mesa_asignada(m_a), orden(o){}

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

void Cliente::pagar_cuenta() {
    float total = orden.calcular_total();
    cout << nombre << " ha pagado $" << total << " por su orden." << endl;
}

#endif