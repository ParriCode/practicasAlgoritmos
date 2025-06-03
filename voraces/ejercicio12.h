/**
 * @file ejercicio12.hº
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#ifndef EJERCICIO12_H_
#define EJERCICIO12_H_


typedef struct{
    int vendedora;
    int compradora;
    int semana;


} entrada;

void epidemia( entrada * entradas, int nentradas, int ngranjas, int * infectadas, int ninfectadas);


#endif