#ifndef ORDEN_H
#define ORDEN_H
#include <iostream>
#include <string>
#include "Comida.h"

using namespace std;

class Orden {
    private:
    int numero_orden;
    Comida listaComida[10];
    int cantidad_comidas;
    bool estado;

    public:
    Orden();
    Orden(int numero_orden, bool estado);

    int get_numero_orden();
    bool get_estado();
    float calcular_total();
    string informacion();

    void set_numero_orden(int n_o);
    void set_estado(bool e);
    void agregar_comida(Comida& comida);
};

Orden::Orden(){
    numero_orden = 0;
    cantidad_comidas = 0;
    estado = false;
}

Orden::Orden(int n_o, bool e) : numero_orden (n_o), estado(e){}

int Orden::get_numero_orden(){
    return numero_orden;
}

bool Orden::get_estado(){
    return estado;
}
float Orden::calcular_total(){
    float total = 0.0;
    for (int i = 0; i < cantidad_comidas; i++) {
        total += listaComida[i].get_precio();
    }
    return total;
}

void Orden::set_numero_orden(int n_o){
    numero_orden = n_o;
}

void Orden::set_estado(bool e){
    estado = e;
}

void Orden::agregar_comida(Comida& comida){
        if (cantidad_comidas < 10) {
        listaComida[cantidad_comidas] = comida;
        cantidad_comidas++;
    } else {
        cout << "No se pueden agregar más comidas. Orden llena." << endl;
    }
}

string Orden::informacion(){
    cout << "Orden #" << numero_orden << endl;
    cout << "Estado: " << (estado ? "Entregada" : "Pendiente") << endl;
    cout << "Comidas:" << endl;
    for (int i = 0; i < cantidad_comidas; i++) {
        cout<< "- " << listaComida[i].get_nombre()
            << " | $" << listaComida[i].get_precio()
            << " | Tiempo: " << listaComida[i].get_tiempo_preparacion() << " min" << endl;
    }
    cout << "Total: $" << calcular_total() << endl;
}
#endif