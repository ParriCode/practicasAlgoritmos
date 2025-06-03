/**
 * @file ejercicio2.c
 * @brief Implementación de funciones para calcular la suma máxima de elementos de dos arreglos bajo ciertas condiciones.
 * @version 0.1
 * @date 2025-03-24
 * 
 * @author Jose Luis Parrilla Fuentes
 * @copyright Copyright (c) 2025
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Función de comparación para ordenar un arreglo en orden descendente.
 * 
 * @param a Puntero al primer elemento a comparar.
 * @param b Puntero al segundo elemento a comparar.
 * @return int Resultado de la comparación: 
 *         - Un valor negativo si *b es menor que *a.
 *         - Cero si *a es igual a *b.
 *         - Un valor positivo si *b es mayor que *a.
 */
int comparar(const void *a, const void *b){
    return *(int *)b - *(int *)a;
}

/**
 * @brief Calcula la suma máxima de elementos del arreglo A que pueden ser emparejados con elementos del arreglo B,
 *        cumpliendo la condición A[i] <= B[j].
 * 
 * @param A Arreglo de enteros que representa los valores a sumar.
 * @param B Arreglo de enteros que representa los valores límite.
 * @param n Tamaño de los arreglos A y B.
 * @return int La suma máxima de los elementos de A que cumplen la condición.
 */
int suma_maxima(int *A, int *B, int n){
    qsort(B, n, sizeof(int), comparar); // Ordenar B en orden descendente.

    int s = 0; // Suma máxima.
    int j = 0; // Iterador para B.
    int i = n - 1; // Iterador para A (comienza desde el final).
    while (i != -1) {
        if (A[i] <= B[j]) { // Si A[i] puede emparejarse con B[j].
            s += A[i]; // Sumar A[i] a la suma máxima.
            ++j; // Avanzar en B.
            --i; // Retroceder en A.
        } else {
            --i; // Retroceder en A si no se cumple la condición.
        }
    }
    return s;
}
int main() {
    int A[] = {1, 2, 3, 4, 5};
    int B[] = {5, 4, 3, 2, 1};
    int n = sizeof(A) / sizeof(A[0]);
    int resultado = suma_maxima(A, B, n);
    printf("La suma máxima es: %d\n", resultado);
    return 0;
}