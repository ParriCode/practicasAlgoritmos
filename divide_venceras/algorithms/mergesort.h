/**
 * @file merguesort.c
 * @author Jose Luis Parrilla Fuentes (theparri@protonmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-26
 * 
 */
#ifndef __MERGUE_SORT__
#define __MERGUE_SORT__ 

/**
 * @brief Ordena un vector de enteros v de tamaño n mediante el algoritmo de inserción
 * @details El algoritmo consiste en recorrer el vector e insertar luego yendo hacia atrás en la posición correcta
 * @param v vector
 * @param n numero de elementos del vector
 * @post v estara ordenado de menor a mayor
 */
void insercion(int v[], int n);


/**
 * @brief 
 * @pre Vectores ordenados
 * 
 * @param v puntero vector v
 * @param u puntero vector u
 * @param n Longitud de v
 * @param m Longitud de u
 * @post Vector V ordenado
 */
void merge(int v[], int u[], int n, int m);


/**
 * @brief Ordenacion por metodo merguesort
 * @details n0 == 10
 * @param v 
 * @param a 
 * @param b 
 */
void mergesort(int v[], int a , int b);


#endif