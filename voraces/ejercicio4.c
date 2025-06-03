/**
 * @file ejercicio4.h
 * @author Jose Luis Parrilla Fuentes (theparri@protonmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-25
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#include <stdlib.h>
#include <stdio.h>
#include "ivector/ivector.h"
typedef struct {
    int id;
    int duracion;
} bombilla;

int cmp_bombilla(const void *a, const void *b) {
    return ((bombilla *)b)->duracion - ((bombilla *)a)->duracion; // Ordenar de mayor a menor duración
}

/**
 * @brief Esta función devuelve el orden óptimo para iluminar una habitación con bombillas.
 * 
 * @param bombillas Bombillas disponibles.
 * @param n Número de bombillas.
 * @param m Bombillas necesarias para iluminar la habitación.
 * @return El orden de las bombillas.
 */
int *iluminacion_continua(bombilla *bombillas, int n, int m) {
    // Ordenar las bombillas por duración de mayor a menor
    qsort(bombillas, n, sizeof(bombilla), cmp_bombilla); 


    // Imprimir bombillas ordenadas
    ivector  orden = icreavector(n); // Crear un vector para almacenar el orden de las bombillas
    
    int puestas[m];
    for(int i = 0; i < m; ++i){
        puestas[i] = bombillas[i].id; // Colocar las primeras bombillas
    }
    int b = 3;
    int d = 0;
    while(1){
        for(int i = 0; i < m; ++i){
            puestas[i]--;
            if(puestas[i] == 0){ //Si la bombilla se ha apagado
                puestas[i] = bombillas[b].id; //Colocar la siguiente bombilla
                orden[b] = bombillas[b].id; //Guardar el orden de la bombilla
                printf("Bombilla %d apagada, se coloca bombilla %d\n", puestas[i], bombillas[b].id);
                ++b; //Aumentar el orden
                if(b == n){ //Si hemos colocado todas las bombillas
                    return orden; //Devolver el orden
                }
            }

        }
        ++d;
        printf("Tiempo transcurrido: %d\n", d);

    }
}

int main() {
    int n = 5;
    int m = 3; 

    bombilla bombillas[] = {
        {1, 10},
        {2, 20},
        {3, 15},
        {4, 25},
        {5, 30}
    };

    // Llamar a la función para iluminar la habitación
    ivector orden = iluminacion_continua(bombillas, n, m);
    // Imprimir el orden de las bombillas
    printf("Orden de las bombillas:\n");
    
    // Liberar memoria si se ha asignado

    ifreevector(&orden); // Liberar memoria del vector de orden

    return 0;
}