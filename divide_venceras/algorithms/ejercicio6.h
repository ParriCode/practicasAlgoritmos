/**
 * @file ejercicio6.h
 * @brief Dado un vector de corredores con un dorsal, el algoritmo implementa DyV 
 * para obtener el corredor que más agua ha llevado.
 * @version 0.1
 * @date 2025-03-20
 */

#ifndef __EJERCICIO6_H__
#define __EJERCICIO6_H__

/**
 * @brief Estructura que representa un corredor.
 * 
 * @param dorsal Número de dorsal del corredor.
 * @param cantidad_agua Cantidad de agua llevada por el corredor.
 */
typedef struct corredor {
    int dorsal;
    int cantidad_agua;
} corredor;

/**
 * @brief Encuentra el corredor que más agua ha llevado utilizando un enfoque de divide y vencerás.
 * 
 * @param v Vector de corredores.
 * @param a Índice inicial del rango a considerar.
 * @param b Índice final (exclusivo) del rango a considerar.
 * @param posicion Posición del corredor que más agua ha llevado.
 * @return corredor Estructura del corredor que más agua ha llevado.
 */
corredor corredor_mas_agua(corredor *v, int a, int b, int posicion);

#endif // __EJERCICIO6_H__