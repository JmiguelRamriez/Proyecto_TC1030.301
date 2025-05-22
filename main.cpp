#include <iostream>
#include "Comida.h"
#include "Orden.h"
#include "Mesa.h"
#include "Cliente.h"
#include "Empleado.h"
#include "Mesero.h"
#include "Cocinero.h"
#include "Restaurante.h"

using namespace std;

int main(){
    //Se crean los objetos
    Mesa mesa1(1,4, false);//mesa

    //Empleados
    Empleado empleado1("Carlos", 1, "Mesero");
    Empleado empleado2("Ana", 2, "Cocinera");
    
    //Comida
    Comida comida1("Pizza", 120.00, 10);

    //Orden
    Orden o1(1, 150.0);

    //Cliente
    Cliente cli1("Pedro", 1, o1);

    //Arreglos para el restaurante
    Mesa mesas[1] = { mesa1 };
    Empleado empleados[2] = { empleado1, empleado2 };
    Comida comidas[1] = { comida1 };

    //Objeto restaurante
    Restaurante r1(mesas, 1, empleados, 2, comidas, 1);

    //Imprimir los objetos
    cout << "---Mesa---"<< endl;
    cout << mesa1.informacion();

    cout << "--- EMPLEADO ---" << endl;
    cout << "Nombre: " << empleado1.get_nombre() << ", ID: " << empleado1.get_id() << ", Rol: " << empleado1.get_rol() << endl;

    cout << "--- RESTAURANTE ---" << endl;
    cout << "Total Mesas: " << r1.get_total_mesas() << endl;
    cout << "Total Empleados: " << r1.get_total_empleados() << endl;
    cout << "Total Comidas: " << r1.get_total_comidas() << endl;
    cout << "Total Ordenes: " << r1.get_total_ordenes() << endl;
    
    return 0;

}