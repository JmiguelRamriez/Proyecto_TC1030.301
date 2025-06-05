#ifndef COMIDA_H
#define COMIDA_H
#include <iostream>
#include <string>
using namespace std;

class Comida {

    private:
    string nombre;
    int precio;
    int tiempo_preparacion;

    public:
    Comida();
    Comida(string n, int p, int t_p);

    string get_nombre();
    int get_precio();
    int get_tiempo_preparacion();

    void set_nombre(string n);
    void set_precio(int p);
    void set_tiempo_preparacion(int t_p);
    string informacion();
};

Comida::Comida(){
    nombre = "";
    precio = 0;
    tiempo_preparacion = 0.0;
}

Comida::Comida(string n, int p , int t_p):nombre(n), precio(p), 
tiempo_preparacion(t_p){}

string Comida::get_nombre(){
    return nombre;
}

int Comida::get_precio(){
    return precio;
}

int Comida::get_tiempo_preparacion(){
    return tiempo_preparacion;
}

void Comida::set_nombre(string n){
    nombre = n;
}

void Comida::set_precio(int p){
    precio = p;
}

void Comida::set_tiempo_preparacion(int t_p){
    tiempo_preparacion = t_p;
}

string Comida::informacion(){
    string info = "Nombre: " + nombre + "\n";
    info += "Precio: $" + to_string(precio) + "\n";
    info += "Tiempo de preparación: " + to_string(tiempo_preparacion) + 
    " minutos\n";
    return info;
}

#endif