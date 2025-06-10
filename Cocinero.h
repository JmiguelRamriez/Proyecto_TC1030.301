/**
* Cocinero.h
* [Jose Miguel Ramirez Gutierrez]
* [A01712628]
* [09/06/2025] 
*
* Clase que representa a un empleado cocinero en el restaurante
* Hereda de la clase base Empleado y añade funcionalidades específicas 
* como especialidad culinaria y turno de trabajo.
*/

#ifndef COCINERO_H
#define COCINERO_H
#include <iostream>
#include <string>
#include "Empleado.h"

using namespace std;

class Cocinero : public Empleado {
    private: 
        string especialidad; // Area culinaria de especializacion
        string turno; // Turno laboral (mañana/tarde/noche)

    public:
        // Constructores
        Cocinero();
        Cocinero(string nom, int i, string r, string esp, string tr);
        
        // Getters
        string get_especialidad();
        string get_turno();

        // Setters
        void set_especialidad(string esp);
        void set_turno(string tr);
        
        // Métodos
        virtual void realizar_tarea();// Implementación especifica para cocineros
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

string Cocinero::get_especialidad() {
    return especialidad;
}

string Cocinero::get_turno() {
    return turno;
}
void Cocinero::set_especialidad(string esp) {
    especialidad = esp;
}

void Cocinero::set_turno(string tr) {
    turno = tr;
}

// Metodo realizar tarea
void Cocinero::realizar_tarea() {
    cout << "El cocinero(a) " << get_nombre() << " especializado en: " 
         << especialidad << endl << "trabaja en el turno de la " << turno << endl;
}

#endif