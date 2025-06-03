#include <iostream>
#include "Restaurante.h"
#include "Cocinero.h"
#include "Mesero.h"
#include "Mesa.h"
#include "Comida.h"
#include "Orden.h"
#include "Cliente.h"

using namespace std;

int main() {
    Restaurante rest;

    Mesa mesa1(1, 4, false);
    Comida comida1("Pizza", 120.00, 10);
    Orden o1(1, true);
    Cliente cli1("Pedro", 1, o1);

    Empleado* emp1 = new Cocinero("Carlos", 101, "Cocinero", "Carnes", "Mañana");
    Empleado* emp2 = new Mesero("Laura", 102, "Mesero", "Tarde", true);
    Empleado* emp3 = new Cocinero("Ana", 103, "Cocinero", "Postres", "Tarde");
    Empleado* emp4 = new Mesero("Luis", 104, "Mesero", "Mañana", false);

    rest.agregar_empleado(emp1);
    rest.agregar_empleado(emp2);
    rest.agregar_empleado(emp3);
    rest.agregar_empleado(emp4);

    rest.agregar_mesa(mesa1);
    rest.agregar_comida(comida1);
    rest.agregar_orden(o1);

    // Mostrar información general
    rest.mostrar_informacion();

    // Mostrar tareas
    cout << "\n--- Tareas de los empleados ---" << endl;
    rest.realizar_tareas_empleados();

    // Mostrar objetos individuales
    cout << "\n--- Información de objetos individuales ---\n";

    cout << "\n[MESA]\n";
    cout << mesa1.informacion() << endl;


    cout << "\n[ORDEN]\n";
    cout << o1.informacion() << endl;

    cout << "\n[EMPLEADOS]\n";
    emp1->realizar_tarea();
    emp2->realizar_tarea();
    emp3->realizar_tarea();
    emp4->realizar_tarea();

    // Liberar memoria de empleados
    rest.liberar_empleados();

    return 0;
}
