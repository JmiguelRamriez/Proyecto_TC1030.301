#ifndef MESA_H
#define MESA_H
#include <iostream>
#include <string>
#include "Cliente.h"

using namespace std;

class Mesa{
    private:
    int numero;
    int capacidad;
    bool estado;

    public:
    Mesa();
    Mesa(int n, int c, bool e);

    int get_numero();
    int get_capacidad();
    bool get_estado();
    Cliente cliente_asignado;
    string informacion();

    void set_numero (int n);
    void set_capacidad(int c);
    void set_estado(bool e);
    void asignar_cliente(Cliente& cliente);
    void liberar_mesa();
};

Mesa::Mesa(){
    numero = 0;
    capacidad = 0;
    estado = false;
}

Mesa::Mesa(int n, int c, bool e): numero(n), capacidad(c), estado(e){}

int Mesa::get_numero(){
    return numero;
}

int Mesa::get_capacidad(){
    return capacidad;
}

bool Mesa::get_estado(){
    return estado;
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
    estado = false; 
}

string Mesa::informacion() {
    string info = "Mesa #" + to_string(numero) +
                "\nCapacidad: " + to_string(capacidad) +
                "\nEstado: " + (estado ? "Ocupada" : "Libre");
    if (estado) {
        info += "\nCliente asignado: " + cliente_asignado.get_nombre();
    }
    info += "\n";
    return info;
}
#endif