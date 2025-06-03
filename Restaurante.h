Restaurante::Restaurante(Mesa m[], int t_m, Empleado* e[], int t_e, Comida c[], int t_c) {
    total_mesas = (t_m <= 10) ? t_m : 10;
    for (int i = 0; i < total_mesas; i++) {
        mesas[i] = m[i];
    }

    total_empleados = (t_e <= 5) ? t_e : 5;
    for (int i = 0; i < total_empleados; i++) {
        empleados[i] = e[i]; // punteros
    }

    total_comidas = (t_c <= 20) ? t_c : 20;
    for (int i = 0; i < total_comidas; i++) {
        menu[i] = c[i];
    }

    total_ordenes = 0;
}
