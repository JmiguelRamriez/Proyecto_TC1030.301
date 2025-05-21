#include <iostream>
#include <string>
using namespace std;

class Comida {

    private:
    string nombre;
    float precio;
    int tiempo_preparacion;

    public:
    Comida();
    Comida(string n, float p, int t_p);

    string get_nombre();
    float get_precio();
    int get_tiempo_preparacion();

    void set_nombre(string n);
    void set_precio(float p);
    void set_tiempo_preparacion(int t_p);
};

Comida::Comida(){
    nombre = "";
    precio = 0;
    tiempo_preparacion = 0.0;
}

Comida::Comida(string n, float p , int t_p):nombre(n), precio(p), tiempo_preparacion(t_p){}

string Comida::get_nombre(){
    return nombre;
}

float Comida::get_precio(){
    return precio;
}

int Comida::get_tiempo_preparacion(){
    return tiempo_preparacion;
}

void Comida::set_nombre(string n){
    nombre = n;
}

void Comida::set_precio(float p){
    precio = p;
}

void Comida::set_tiempo_preparacion(int t_p){
    tiempo_preparacion = t_p;
}
