/**
 * @file ejercicio7.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdbool.h>

#include <stdio.h>
/**
 * @brief Verficar si un vector dado es un heap de elemento máximo 
 * @details Para ello verificamos si tiene hijos por la izquierda o por la derecha
 * @param v 

 * @return true si es un heap , false sino lo es
 */
int i = 0;
bool esHeap(int * v, int n, int nivel){
    //Estamos en el último elemento
   // if(nivel ==  n-1 ) return v[(nivel-1) / 2] >= v[nivel]; 
    if(nivel >= n) return true; //Estamos en una hoja
    else{
        if(esHeap(v, n, nivel*2+1) && esHeap(v, n, nivel*2+2)){
            //Si el nivel es 0 quiere decir que estamos en la cabecera  sino se comprueba si el padre es mayor
            return nivel == 0 || v[(nivel-1) / 2] >= v[nivel]; 
        } //Devolvemos si es un heap
    }

}
int main() {
    int v[] = {10, 5, 3, 2, 4};
    int n = sizeof(v) / sizeof(v[0]);
    if (esHeap(v, n, 0)) {
        printf("El vector es un heap.\n");
    } else {
        printf("El vector no es un heap.\n");
    }
    return 0;
}