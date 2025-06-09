# Contexto
Este proyecto es un sistema de simulación para gestionar el funcionamiento interno de un restaurante. Se manejan clases como clientes, meseros, cocineros, mesas, órdenes y el menú del restaurante. Implementa clases como `Cliente`, `Mesero`, `Cocinero`, `Mesa`, `Orden` y `Comida` para mostrar todas las interacciones del negocio. El sistema permite:

- Registrar órdenes de los clientes con múltiples items del menú
- Asignar mesas y personal según disponibilidad
- Gestionar la preparación de alimentos por especialidad
- Administrar el flujo completo desde el pedido hasta el pago

## Funcionalidad

### Gestión de Órdenes
- Registro de órdenes con múltiples items del menú
- Cálculo automático de totales y tiempos de preparación

### Gestión de Personal
- Asignación de meseros a mesas
- Especialización de cocineros por tipo de comida

### Administración de Menú
- Catálogo completo de comidas con precios y tiempos de preparación
- Capacidad para agregar/editar platillos

### Control de Mesas
- Sistema de ocupación/liberación de mesas
Gestión de órdenes:
- Los clientes pueden realizar órdenes de comida que se almacenan en el sistema.
- Cada orden puede contener múltiples elementos del menú.
- Los meseros registran la orden y la envían a cocina para ser preparada.

# Consideraciones y recomendaciones
Lenguaje: C++ estándar (compatible con C++11 o superior)
Plataformas soportadas: Windows, Linux, macOS  
  Límites del sistema:
- Ingresar solo valores numéricos cuando se soliciten
- Respetar los límites del sistema
- Seguir el flujo secuencial del menú
- Verificar disponibilidad de mesas/meseros

- Máx. 10 mesas 
- Máx. 6 empleados
- Máx. 20 items en menú
- Máx. 30 órdenes simultáneas
- Máx. 10 comidas por orden

# Instrucciones de ejecución
Instrucciones de Ejecución
### En Linux:
Para compilar:
g++ main.cpp 

Para ejecutar:
./a.out 

### En Windows:
Para compilar:
g++ main.cpp 

Para ejecutar:
a.exe



