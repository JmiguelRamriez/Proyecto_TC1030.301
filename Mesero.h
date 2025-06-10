/*
* Mesero.h
* [Jose Miguel Ramirez Gutierrez]
* [A01712628]
* [09/06/2025]
*
* Clase que representa a un empleado mesero en el restaurante.
* Hereda de la clase base Empleado y añade funcionalidades específicas
* como turno de trabajo y disponibilidad.
* Gestiona la interacción con los clientes y mesas.
*/

#ifndef MESERO_H
#define MESERO_H
#include <iostream>
#include <string>
#include "Empleado.h"

using namespace std;

class Mesero : public Empleado {
    private:
        string turno; // Turno de trabajo (mañana/tarde)
        bool disponibilidad; // Estado de disponibilidad

    public:
        // Constructores
        Mesero();
        Mesero(string nom, int i, string r, string tr, bool d);

        // Getters
        string get_turno();
        bool get_disponibilidad();
        
        // Setters
        void set_turno(string tr);
        void set_disponibilidad(bool d);
        
        // Método sobreescrito
        virtual void realizar_tarea();
};

// Constructor por defecto
Mesero::Mesero() : Empleado() {
    turno = "";
    disponibilidad = false;
    set_tipo_empleado("Mesero");  
}

// Constructor parametrizado
Mesero::Mesero(string nom, int i, string r, string tr, bool d)
:Empleado(nom, i, r), turno(tr), disponibilidad(d) {
    set_tipo_empleado("Mesero");  
}

string Mesero::get_turno() {
    return turno;
}

bool Mesero::get_disponibilidad() {
    return disponibilidad;
}

void Mesero::set_turno(string tr) {
    turno = tr;
}

void Mesero::set_disponibilidad(bool d) {
    disponibilidad = d;
}

void Mesero::realizar_tarea() {
    cout << "El mesero(a) " << get_nombre() << " esta libre" << endl;
}

#endif
