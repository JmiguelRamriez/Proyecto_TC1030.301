#include <iostream>
#include <vector>
#include "Restaurante.h"
#include "Cocinero.h"
#include "Mesero.h"
#include "Mesa.h"
#include "Comida.h"
#include "Orden.h"
#include "Cliente.h"

using namespace std;

void limpiar_consola(){
    #ifdef _WIN32
        system("cls");  // Comando para limpiar la consola en sistemas Windows
    #else
        system("clear");  // Comando para limpiar la consola en sistemas Unix/Linux
    #endif
}

void pausar() {
    cout << "\nPresiona Enter para continuar...";
    cin.ignore();  // Limpia el buffer
    cin.get();     // Espera a que el usuario presione Enter
}

//Funcion para mostrar menu 
void mostrarMenu(){
    cout <<"Porfavor solo ingresar numeros" << endl;
    cout <<"(1) Mostrar informacion del restaurante" <<endl;
    cout <<"(2) Mostrar menu" <<endl;
    cout <<"(3) Ordenar" <<endl;
    cout <<"(4) SALIR" <<endl;    
}

int main() {
    //Creacion del restaurante
    Restaurante rest;

    //Creacion de los objetos tipo mesa
    Mesa m1(1, 2, false);
    Mesa m2(2, 4, false);
    Mesa m3(3, 6, false);
    Mesa m4(4, 8, false);
    
    //Se agrega el objeto mesa al restaurante
    rest.agregar_mesa(m1);
    rest.agregar_mesa(m2);
    rest.agregar_mesa(m3);
    rest.agregar_mesa(m4);

    //Creacion de los objetos tipo empleado
    Empleado* emp1 = new Cocinero("Carlos", 101, "Cocinero", "Carnes", "Mañana");
    Empleado* emp2 = new Mesero("Laura", 102, "Mesero", "Tarde", true);
    Empleado* emp3 = new Cocinero("Ana", 103, "Cocinero", "Postres", "Tarde");
    Empleado* emp4 = new Mesero("Luis", 104, "Mesero", "Mañana", true);
    Empleado* emp5 = new Mesero("Alberto", 105, "Mesero", "Mañana", true);
   
    //Se agregan los empleados al restaurante
    rest.agregar_empleado(emp1);
    rest.agregar_empleado(emp2);
    rest.agregar_empleado(emp3);
    rest.agregar_empleado(emp4);
    rest.agregar_empleado(emp5);
   
    //Creacion del objeto cliente


    //Creacion del objeto comida
    Comida comida1("Pizza", 120.00, 10);
    Comida comida2("Pizza vegetariana", 125.0, 20);
    Comida comida3("Ensalada César", 80.5, 10);
    Comida comida4("Pasta Alfredo", 130.0, 18);
    Comida comida5("Tacos al pastor", 110.0, 10);
    Comida comida6("Enchiladas", 110.0, 18);
    Comida comida7("Sándwich club", 95.0, 12);
    Comida comida8("Lasagna", 140.0, 25);
    Comida comida9("Helado de vainilla", 60.0, 5);
    Comida comida10("Postre de chocolate", 70.0, 8);

    //Se agrega la comida al restaurante
    rest.agregar_comida(comida1);
    rest.agregar_comida(comida2);
    rest.agregar_comida(comida3);
    rest.agregar_comida(comida4);
    rest.agregar_comida(comida5);
    rest.agregar_comida(comida6);
    rest.agregar_comida(comida7);
    rest.agregar_comida(comida8);
    rest.agregar_comida(comida9);
    rest.agregar_comida(comida10);

    //Arreglos para el restaurante
    Mesa mesas[4] = {m1,m2,m3,m4};
    Empleado* empleados[5] = { emp1, emp2,emp3,emp4,emp5 };
    Comida comidas[10] = { comida1,comida2,comida3,comida4,comida5,comida6,comida7,comida8,comida9,comida10 };
    
    int opcion;
    do{
        
        mostrarMenu();
        cin >> opcion;
        limpiar_consola();
        switch (opcion){
            case 1:
                cout << rest.mostrar_informacion() << endl;
                pausar();
                limpiar_consola();
                break;
            case 2:
                for (int i = 0; i < 10; i++) {
                cout << "--- Comida " << (i + 1) << " ---" << endl;
                cout << comidas[i].informacion() << endl;
                } 
                pausar();
                limpiar_consola();   
                break;
            case 3: 
                string nombre, correo, numero;
                cout << "Ingrese su nombre: "; 
                getline(cin, nombre);
                cout << "Ingrese su numero de mesa: "; 
                getline(cin, numero);

                
                // Mostrar mesas disponibles
                cout << "Mesas disponibles:\n";
                bool hayMesaDisponible = false;
                for (int i = 0; i < 4; i++) {
                    if (!mesas[i].get_estado()) {
                        cout << "- Mesa " << mesas[i].get_numero() 
                        << " (capacidad: " << mesas[i].get_capacidad() << " personas)\n";
                        hayMesaDisponible = true;
                    }
                }

                if (!hayMesaDisponible) {
                    cout << "No hay mesas disponibles en este momento.\n";
                    pausar();
                    limpiar_consola();
                    break;
                }

                // Selección de mesa
                int numMesa;
                cout << "\nSeleccione una mesa: ";
                cin >> numMesa;

                bool mesaValida = false;
                for (int i = 0; i < 4; i++) {
                    if (mesas[i].get_numero() == numMesa && !mesas[i].get_estado()) {
                        mesas[i].set_estado(true);
                        mesaValida = true;
                        break;
                    }
                }

                if (!mesaValida) {
                    cout << "Mesa no válida o ya está ocupada.\n";
                    pausar();
                    limpiar_consola();
                    break;
                }

                // Crear objeto orden
                Orden orden(rest.get_total_ordenes() + 1, false);
                Cliente cliente1(nombre, numero, orden);
                // Selección de comidas
                char agregar;
                do {
                    cout << "\n--- Menú ---\n";
                    for (int i = 0; i < 10; i++) {
                        cout << (i + 1) << ". " << comidas[i].get_nombre()
                            << " - $" << comidas[i].get_precio() << endl;
                    }
                    int eleccion;
                    cout << "Elija el número de comida que desea agregar: ";
                    cin >> eleccion;

                    if (eleccion >= 1 && eleccion <= 10) {
                        orden.agregar_comida(comidas[eleccion - 1]);
                        cout << "Comida agregada.\n";
                    } else {
                        cout << "Opción inválida.\n";
                    }

                    cout << "¿Desea agregar otra comida? (s/n): ";
                    cin >> agregar;
                } while (agregar == 's' || agregar == 'S');

                // Asignar mesero disponible
                Mesero* meseroAsignado = nullptr;
                for (int i = 0; i < 5; i++) {
                    if (empleados[i]->get_tipo_empleado() == "Mesero") {
                        Mesero* m = (Mesero*)empleados[i];
                        if (m->get_disponibilidad()) {
                            meseroAsignado = m;
                            m->set_disponibilidad(false);
                            break;
                        }
                    }
                }

                if (meseroAsignado != nullptr) {
                    cout << "Mesero asignado: " << meseroAsignado->get_nombre() << endl;
                } else {
                    cout << "No hay meseros disponibles. La orden no puede ser procesada.\n";
                    pausar();
                    limpiar_consola();
                    break;
                }

                // Agregar la orden al restaurante
                rest.agregar_orden(orden);

                // Mostrar información final
                cout << "\nOrden creada con éxito:\n";
                cout << orden.informacion();
                pausar();
                limpiar_consola();
                break;
            }

    } while (opcion != 4); 
    return 0;
}
