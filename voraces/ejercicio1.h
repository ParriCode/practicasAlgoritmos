/**
 * @file ejercicio1.h
 * @author Jose Luis Parrilla Fuentes (theparri@protonmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */
 

#ifndef EJERCICIO1_H
#define EJERCICIO1_H


typedef struct{
    int id;
    int tiempo;
    int cobrar;
} pedido;

int comparar(const void *a, const void *b);

void peticion_entregas(pedido *pedidos, int n);
#endif