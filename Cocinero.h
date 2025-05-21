#include <iostream>
#include <string>
#include "Empleado.h"

using namespace std;

class Cocinero : public Empleado {
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
    void realizar_tarea();
};

// Constructor por defecto
Cocinero::Cocinero() : Empleado() {
    especialidad = "";
    turno = "";
}

// Constructor parametrizado
Cocinero::Cocinero(string nom, int i, string r, string esp, string tr): Empleado(nom, i, r), especialidad(esp), turno(tr) {}

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
    cout << "El cocinero " << get_nombre() << " está preparando su especialidad: " 
        << especialidad << " en el turno " << turno << "." << endl;
}
