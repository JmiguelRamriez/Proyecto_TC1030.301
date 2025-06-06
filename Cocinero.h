#ifndef COCINERO_H
#define COCINERO_H
#include <iostream>
#include <string>
#include "Empleado.h"

using namespace std;

/**
 * Cocinero
 * Clase que representa a un empleado cocinero en el restaurante
 * Hereda de la clase base Empleado y añade funcionalidades específicas
 */
class Cocinero : public Empleado {
//Atributos
    private: 
        string especialidad;
        string turno;

    public:
        Cocinero();
        Cocinero(string nom, int i, string r, string esp, string tr);

        string get_especialidad();
        string get_turno();

        void set_especialidad(string esp);
        void set_turno(string tr);
        virtual void realizar_tarea();
};

// Constructor por defecto
Cocinero::Cocinero() : Empleado() {
    especialidad = "";
    turno = "";
    set_tipo_empleado("Cocinero"); 
}

// Constructor parametrizado
Cocinero::Cocinero(string nom, int i, string r, string esp, string tr): 
Empleado(nom, i, r), especialidad(esp), turno(tr) {
    set_tipo_empleado("Cocinero"); 
}

// Getters
string Cocinero::get_especialidad() {
    return especialidad;
}

string Cocinero::get_turno() {
    return turno;
}

// Setters
void Cocinero::set_especialidad(string esp) {
    especialidad = esp;
}

void Cocinero::set_turno(string tr) {
    turno = tr;
}

// Método realizar tarea
void Cocinero::realizar_tarea() {
    cout << "El cocinero(a) " << get_nombre() << " especializado en: " 
         << especialidad << endl << "trabaja en el turno de la " << turno << endl;
}

#endif