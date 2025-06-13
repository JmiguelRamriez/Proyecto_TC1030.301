/*
* Empleado.h
* [Jose Miguel Ramirez Gutierrez]
* [A01712628]
* [09/06/2025]
*
* Clase base para representar a un empleado en el restaurante.
* Contiene atributos comunes como nombre, ID y rol.
* Proporciona la interfaz básica para todos los tipos de empleados.
* Clase abstracta que debe ser heredada por tipos específicos de empleados.
*/

#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>
#include <string>

using namespace std;

class Empleado {
    protected:
        // Atributos comunes
        string nombre; // Nombre completo del empleado
        int id; // Identificador único
        string rol; // Rol o puesto
        string tipo_empleado; // Tipo específico (Cocinero/Mesero/etc)

    public:
        // Constructores
        Empleado(); 
        Empleado(string nom, int id, string rol);

        // Getters
        string get_nombre();
        int get_id();
        string get_rol();
        string get_tipo_empleado();  
        
        // Setters
        void set_nombre(string nom);
        void set_id(int i);
        void set_rol(string r);
        void set_tipo_empleado(string tipo); 

        // Método virtual 
        virtual void realizar_tarea() = 0; 
};

// Constructor por defecto
Empleado::Empleado() {
    nombre = "";
    id = 0;
    rol = "";
    tipo_empleado = "Empleado";
}

// Constructor con parametros
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

// Metodo virtual para realizar una tarea general

void Empleado::realizar_tarea() {
    cout<<"Empleado"<<nombre<< " esta realizando una tarea general." << endl;
}

#endif
