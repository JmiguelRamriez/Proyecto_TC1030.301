#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>
#include <string>

using namespace std;

class Empleado {
    protected:
        string nombre;
        int id;
        string rol;
        string tipo_empleado; 

    public:
        Empleado();
        Empleado(string nom, int id, string rol);

        string get_nombre();
        int get_id();
        string get_rol();
        string get_tipo_empleado();  

        void set_nombre(string nom);
        void set_id(int i);
        void set_rol(string r);
        void set_tipo_empleado(string tipo); 

        virtual void realizar_tarea(); 
};

// Implementación

Empleado::Empleado() {
    nombre = "";
    id = 0;
    rol = "";
    tipo_empleado = "Empleado";
}

Empleado::Empleado(string nom, int i, string r) 
: nombre(nom), id(i), rol(r) {
    tipo_empleado = "Empleado";
}

string Empleado::get_nombre() {
    return nombre;
}

int Empleado::get_id() {
    return id;
}

string Empleado::get_rol() {
    return rol;
}

string Empleado::get_tipo_empleado() {
    return tipo_empleado;
}

void Empleado::set_nombre(string nom) {
    nombre = nom;
}

void Empleado::set_id(int i) {
    id = i;
}

void Empleado::set_rol(string r) {
    rol = r;
}

void Empleado::set_tipo_empleado(string tipo) {
    tipo_empleado = tipo;
}

void Empleado::realizar_tarea() {
    cout<<"Empleado"<<nombre<< " está realizando una tarea general." << endl;
}

#endif
