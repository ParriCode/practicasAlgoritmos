/**
 * @file ternaria.h
 * @author Jose Luis Parrilla Fuentes (theparri@protonmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef __TERNARIA_H__
#define __TERNARIA_H__

/**
 * @brief Busqueda ternaria de un elemento dado un vector ordenado
 * @pre El vector Debe estar ordenado
 * @param v vector ordenado
 * @param a Comienzo del vector
 * @param b Final del vector
 * @param ele elemento a buscar
 * @post posicion del elemento encontrado
 */
int ternaria_rec(int v[], int a, int b, int ele);

/**
 * @brief Inicialización del algoritmo de buqueda ternaria 
 * @pre El vector debe estar ordenado
 * @param v Vector 
 * @param tam tamaño del vector
 * @param ele elemento a buscar
 * @return posicion del elemento , -1 si no se encuentra
 */
int ternaria(int v[] , int tam, int ele);

#endif
