/**
 * @file ejercicio4.c
 * @author Jose Luis Parrilla
 * @brief Implementación de un algoritmo que calcula el sumatorio de los elementos de un vector sin tener en cuenta el 
 * máximo ni el mínimo.
 * 
 * Este archivo contiene dos implementaciones del algoritmo:
 * - Una versión clásica que recorre el vector de forma iterativa.
 * - Una versión recursiva basada en divide y vencerás.
 * 
 * @version 0.1
 * @date 2025-02-26
 */

#include "ejercicio4.h"

/**
 * @brief Calcula la suma de los elementos de un vector sin tener en cuenta el máximo ni el mínimo (versión clásica).
 * 
 * Este algoritmo recorre el vector de forma iterativa, identificando el máximo y el mínimo, y luego calcula la suma
 * excluyendo estos valores. Si el máximo o el mínimo aparecen varias veces, se excluyen todas sus ocurrencias.
 * 
 * @param v Puntero al vector de enteros.
 * @param a Índice inicial del rango del vector a considerar.
 * @param b Índice final (exclusivo) del rango del vector a considerar.
 * @return int La suma de los elementos del vector sin incluir el máximo ni el mínimo.
 */
int sumaMM_clasico(int *v, int a, int b){
    int countmin = 0;
    int countmax = 0;
    int min = 0x70000000; // Valor inicial alto para encontrar el mínimo.
    int max = 0x80000000; // Valor inicial bajo para encontrar el máximo.
    int sum = 0;

    for(int i = a; i < b; ++i){
        sum += v[i];
        
        if(v[i] == min){ ++countmin; }
        if(v[i] == max){ ++countmax; }
        if(v[i] < min){
            countmin = 1; // Número de veces que aparece el mínimo.
            min = v[i];
        }
        if(v[i] > max){
            countmax = 1; // Número de veces que aparece el máximo.
            max = v[i];
        }
    }
    return sum - countmax * max - countmin * min;
}

/**
 * @brief Calcula la suma de los elementos de un vector sin tener en cuenta el máximo ni el mínimo (versión recursiva).
 * 
 * Este algoritmo utiliza el enfoque de divide y vencerás para dividir el vector en dos mitades, calcular la suma de
 * cada mitad y luego combinar los resultados. Si el rango es suficientemente pequeño, utiliza la versión clásica.
 * 
 * @param v Puntero al vector de enteros.
 * @param a Índice inicial del rango del vector a considerar.
 * @param b Índice final (inclusivo) del rango del vector a considerar.
 * @return int La suma de los elementos del vector sin incluir el máximo ni el mínimo.
 */
int sumaMM(int *v, int a, int b){
    if(a >= b){
        return v[a];
    } else {
        int m = (a + b) / 2;
        int s1 = sumaMM(v, a, m);
        int s2 = sumaMM(v, m + 1, b);
        return s1 + s2; // Combina las sumas de las dos mitades.
    }
}