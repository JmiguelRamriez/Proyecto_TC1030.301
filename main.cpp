/*
 * Proyecto Sistema de Gestion de Restaurante
 * [Jose Miguel Ramirez Gutierrez]
 * [A01712628]
 * [09/06/2025]
 *
 * Archivo principal que implementa el menú interactivo
 * para gestionar las operaciones del restaurante.
 * Incluye funciones para:
 * - Mostrar información del restaurante
 * - Gestionar mesas y órdenes
 * - Procesar pagos
 * - Interacción con clientes
 */

#include <iostream>
#include "Restaurante.h"
#include "Cocinero.h"
#include "Mesero.h"
#include "Mesa.h"
#include "Comida.h"
#include "Orden.h"
#include "Cliente.h"
using namespace std;

// Funcion para lmpia la consola dependiendo del sistema operativo
void limpiar_consola(){
    #ifdef _WIN32
        system("cls");//Comando para limpiar la consola en sistemas Windows
    #else
        system("clear");//Comando para limpiar la consola en sistemas Unix/Linux
    #endif
}

// Funcion para pausar la ejecución hasta que el usuario presione Enter
void pausar() {
    cout << "\nPresiona Enter para continuar...";
    cin.ignore();// Limpia el buffer
    cin.get();// Espera a que el usuario presione Enter
}

//Funcion para mostrar menu de opciones
void mostrarMenu(){
    cout <<"(1) Mostrar informacion del restaurante" <<endl;
    cout <<"(2) Mostrar menu" <<endl;
    cout <<"(3) Ordenar" <<endl;
    cout <<"(4) Pagar orden" <<endl;
    cout <<"(5) SALIR" <<endl;     
}

// Funcion para mostrar la informacion del restaurante
void mostrarInformacionRestaurante(Restaurante& rest, Empleado* empleados[], int totalEmpleados) {
    // Información general del restaurante
    cout << rest.mostrar_informacion() << endl;
    
    // Tareas de cocineros
    cout << "--- Cocineros ---" << endl;
    for (int i = 0; i < totalEmpleados; i++) {
        if (empleados[i]->get_tipo_empleado() == "Cocinero") {
            empleados[i]->realizar_tarea();
        }
    }

    cout << "--- Meseros ---" << endl;
    for (int i = 0; i < totalEmpleados; i++) {
        if (empleados[i]->get_tipo_empleado() == "Mesero") {
            empleados[i]->realizar_tarea();
        }
    }   
    
    pausar();
    limpiar_consola();
}

// Funcion para mostrar el menu de comidas
void mostrarMenuComidas(Comida comidas[], int totalComidas) {
    cout << "=== MENU DE COMIDAS ===" << endl;
    for (int i = 0; i < totalComidas; i++) {
        cout << "--- Comida " << (i + 1) << " ---" << endl;
        cout << comidas[i].informacion() << endl;
    }
    pausar();
    limpiar_consola();
}

// Funcion para mostrar las mesas disponibles
void mostrarMesasDisponibles(Mesa mesas[], int totalMesas) {
    cout << "Mesas disponibles:\n";
    bool MesaDisponible = false;
    
    for (int i = 0; i < totalMesas; i++) {
        if (!mesas[i].get_estado()) {
            cout << "- Mesa " << mesas[i].get_numero()
                 << " (capacidad: " << mesas[i].get_capacidad()
                 << " personas)\n";
            MesaDisponible = true;
        }
    }

    if (!MesaDisponible) {
        cout << "No hay mesas disponibles en este momento.\n";
    }
}

// Funcion para seleccionar una mesa
int seleccionarMesa(Mesa mesas[], int totalMesas) {
    int numMesa;
    cout << "\nSeleccione una mesa: ";
    cin >> numMesa;

    for (int i = 0; i < totalMesas; i++) {
        if (mesas[i].get_numero() == numMesa && !mesas[i].get_estado()) {
            mesas[i].set_estado(true);
            return numMesa;  // Retorna el numero de mesa valido
        }
    }

    cout << "Mesa no valida o ya esta ocupada.\n";
    pausar();
    limpiar_consola();
    return 0;  
}

// Funcion para solicitar el nombre del cliente
string solicitarNombreCliente() {
    string nombre;
    do {
        cout << "Ingrese su nombre: ";
        cin.ignore();
        getline(cin, nombre);
        
        if(nombre.empty()) {
            cout << "Error: El nombre no puede estar vacio.\n";
        }
    } while(nombre.empty());
    
    return nombre;
}

// Funcion para seleccionar comidas y agregarlas a la orden
void seleccionarComidas(Comida comidas[], int totalComidas, Orden& orden) {
    const int OPCION_MINIMA = 1;
    const int OPCION_MAXIMA = totalComidas;
    char agregar;

    do {
        // Mostrar menu de comidas
        cout << "\n--- MENU PRINCIPAL ---\n";
        for (int i = 0; i < totalComidas; i++) {
            float precio = comidas[i].get_precio();
            cout << (i + 1) << ". " << comidas[i].get_nombre() << " - $";
            // Mostrar precio sin decimales si es entero
            precio == (int)precio ? cout << (int)precio : cout << precio;
            cout << endl;
        }

        // Solicitar selección
        int eleccion;
        cout << "\nElija el numero de comida que desea agregar (" 
             << OPCION_MINIMA << "-" << OPCION_MAXIMA << "): ";
        cin >> eleccion;

        // Validar y agregar comida
        if (eleccion >= OPCION_MINIMA && eleccion <= OPCION_MAXIMA) {
            orden.agregar_comida(comidas[eleccion - 1]);
            cout << "\n " << comidas[eleccion - 1].get_nombre() 
                 << " agregado a la orden.\n";
        } else {
            cout << "\n Opción invalida. Intente nuevamente.\n";
        }

        // Preguntar por mas comidas
        do {
            cout << "\n¿Desea agregar otra comida? (s/n): ";
            cin >> agregar;
        } while (agregar != 's' && agregar != 'n');

        limpiar_consola();
    } while (agregar == 's');
}

// Funcion para asignar un mesero disponible
Mesero* asignarMesero(Empleado* empleados[], int total) {
    for (int i = 0; i < total; i++) {
        if (empleados[i]->get_tipo_empleado() == "Mesero") {
            Mesero* m = (Mesero*)empleados[i];  
            if (m->get_disponibilidad()) {
                m->set_disponibilidad(false);
                limpiar_consola();
                return m;
            }
        }
    }
    return nullptr;
}

// Funcion para pagar la orden de una mesa
void pagarOrden(Restaurante& rest, Mesa mesas[], int totalMesas) {
    // Mostrar mesas ocupadas
    cout << "=== MESAS OCUPADAS ===" << endl;
    bool hayMesasOcupadas = false;
    
    for (int i = 0; i < totalMesas; i++) {
        if (mesas[i].get_estado() && mesas[i].get_cliente_actual() != nullptr) {
            cout << mesas[i].informacion() << endl;
            hayMesasOcupadas = true;
        }
    }

    if (!hayMesasOcupadas) {
        cout << "No hay mesas ocupadas en este momento.\n";
        pausar();
        limpiar_consola();
        return;
    }

    // Solicitar numero de mesa a pagar
    int numMesa;
    cout << "\nIngrese el numero de mesa que desea pagar: ";
    cin >> numMesa;

    // Buscar la mesa seleccionada
    bool mesaValida = false;
    for (int i = 0; i < totalMesas; i++) {
        if (mesas[i].get_numero() == numMesa && mesas[i].get_estado()) {
            mesaValida = true;
            Cliente* cliente = mesas[i].get_cliente_actual();
            
            if (cliente == nullptr) {
                cout << "Error: No hay cliente asignado a esta mesa.\n";
                break;
            }
            
            // Mostrar informacion detallada
            cout << "\n=== DETALLE DE LA MESA #" << numMesa << " ===" << endl;
            cout << mesas[i].informacion() << endl;
            
            // Obtener numero de orden
            int numOrden = cliente->get_orden().get_numero_orden();
            
            // Confirmar pago
            char confirmar;
            cout << "\n¿Confirmar pago para esta mesa? (s/n): ";
            cin >> confirmar;
            
            if (confirmar == 's' || confirmar == 'S') {
                cout << "\nProcesando pago..." << endl;
                
                // Eliminar la orden del restaurante
                rest.eliminar_orden(numOrden);
                
                // Liberar memoria del cliente
                delete cliente;
                mesas[i].asignar_cliente(nullptr);
                
                // Liberar la mesa
                mesas[i].liberar_mesa();
                
                cout << "Pago realizado con éxito.\n";
                cout << "Orden #" << numOrden << " eliminada. Órdenes activas restantes: " 
                     << rest.get_total_ordenes() << endl;
            } else {
                cout << "Pago cancelado.\n";
            }
            
            break;
        }
    }

    if (!mesaValida) {
        cout << "Número de mesa inválido o no está ocupada.\n";
    }

    pausar();
    limpiar_consola();
}

// Funcion principal del programa
int main() {

    //Creacion del objeto restaurante
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
    Empleado* emp2 = new Mesero("Marcela", 102, "Mesero", "Tarde", true);
    Empleado* emp3 = new Cocinero("Ana", 103, "Cocinero", "Postres", "Tarde");
    Empleado* emp4 = new Mesero("Luis", 104, "Mesero", "Mañana", true);
    Empleado* emp5 = new Mesero("Alberto", 105, "Mesero", "Mañana", true);
    Empleado* emp6 = new Mesero("Benji", 106, "Mesero", "Mañana", true);
   
    //Se agregan los empleados al restaurante
    rest.agregar_empleado(emp1);
    rest.agregar_empleado(emp2);
    rest.agregar_empleado(emp3);
    rest.agregar_empleado(emp4);
    rest.agregar_empleado(emp5);
    rest.agregar_empleado(emp6);

    //Creacion del objeto comida
    Comida comida1("Pizza", 120, 10);
    Comida comida2("Pizza vegetariana", 125, 20);
    Comida comida3("Ensalada César", 80.5f, 10);
    Comida comida4("Pasta Alfredo", 130, 18);
    Comida comida5("Tacos al pastor", 110, 10);
    Comida comida6("Enchiladas", 110, 18);
    Comida comida7("Sándwich club", 95, 12);
    Comida comida8("Lasagna", 140, 25);
    Comida comida9("Helado de vainilla", 60, 5);
    Comida comida10("Postre de chocolate", 70, 8);

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
    Empleado* empleados[6] = { emp1, emp2,emp3,emp4,emp5,emp6 };
    Comida comidas[10] = { comida1,comida2,comida3,comida4,comida5,comida6,
        comida7,comida8,comida9,comida10 };
    
    // Bucle principal del programa
    int opcion;
    do{
        // Muestra el menu principal y lee la opción
        mostrarMenu();
        cin >> opcion;
        limpiar_consola();
        switch (opcion){
            case 1:
                mostrarInformacionRestaurante(rest, empleados, 6); 
                break;

            case 2:
                mostrarMenuComidas(comidas, 10);
                break;

            case 3:     
            {            
                mostrarMesasDisponibles(mesas, 4); 

                int numMesa = seleccionarMesa(mesas, 4);
                if (numMesa == 0) {  
                break;  
                }

                string nombreCliente = solicitarNombreCliente();
                Orden orden(rest.get_total_ordenes() + 1, false);

                limpiar_consola();
                seleccionarComidas(comidas, 10, orden); 
    
                Mesero* mesero = asignarMesero(empleados, 6);     
                if (mesero) {
                        cout << "Mesero asignado: " << mesero->get_nombre();
                    } else {
                        cout << "No hay meseros disponibles.\n";
                        pausar();
                        limpiar_consola();
                        // Liberar mesa si es necesario
                        mesas[numMesa - 1].set_estado(false);  
                    }
                
                // Agregar la orden al restaurante
                rest.agregar_orden(orden);

                // Crear cliente con la orden y la mesa asignada
                Cliente* cliente = new Cliente(nombreCliente, to_string(numMesa),
                orden);
                mesas[numMesa - 1].asignar_cliente(cliente);

                // Mostrar información final
                cout << "\nOrden creada con exito:\n";
                cout << orden.informacion();

                pausar();
                limpiar_consola();
                break;
            }            
            case 4:
                // Pagar orden
                pagarOrden(rest, mesas, 4);
        }   
            
    } while (opcion != 5); // Opción para salir del programa

    rest.liberar_empleados(); // Libera memoria 
    
    return 0;
}