#ifndef MESERO_H
#define MESERO_H
#include <iostream>
#include <string>
#include "Empleado.h"

using namespace std;

class Mesero : public Empleado {
private:
    string turno;
    bool disponibilidad;

public:
    Mesero();
    Mesero(string nom, int i, string r, string tr, bool d);

    string get_turno();
    bool get_disponibilidad();
    void set_turno(string tr);
    void set_disponibilidad(bool d);
    virtual void realizar_tarea();
};

Mesero::Mesero() : Empleado() {
    turno = "";
    disponibilidad = false;
    set_tipo_empleado("Mesero");  
}

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
    cout << "El mesero " << get_nombre() << " está atendiendo a los clientes." << endl;
}

#endif
