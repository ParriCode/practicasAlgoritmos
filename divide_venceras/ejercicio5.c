/**
 * @file ejercicio5.c
 * @author Jose Luis Parrilla Fuentes (theparri@protonmail.com)
 * @brief Algoritmo que calcula la cantidad de números dentro de una matriz que se encuentran entre dos valores dados 
 * @version 0.1
 * @date 2025-02-26
 * 
 */
#include <stdio.h>
#include "imatriz2d/imatriz2d.h"
/**
 * 
 */
int suma_matriz_nxn_entre_valores_clasico(imatriz2d v,int n,  int a, int b){
    int contador = 0;
    for(int i = 0; i < n;++i ){
        for(int j = 0; j< n;++j){
            if(v[i][j] >= a ||  v[i][j] <= b){
                --contador;
            }
        }
    }
    return contador;
}


/**
 * @brief Sumar los elementos de una matriz entre2 valores
 * @param n tamaño de la matriz
 * @param m , primer elemento de la columna
 * @param a , primer valor
 * @param b segundo valor
 * 
 */
int suma_matriz_nxn_entre_valores(imatriz2d v, int n,int m,  int a, int b){
    if(n <= 1){
      //  printf("i = %d, n = %d , m = %d, v= %d\n", i , n, m,v);
        if(v[0][m] <= b && v[0][m] >= a){
            return 1;
        }else{return 0;}
    }else{    
        int s = 0;
        s+= suma_matriz_nxn_entre_valores(v       ,n/2 , m, a , b );
        s+= suma_matriz_nxn_entre_valores(v       ,n/2 , m+ n/2, a , b);
        s+= suma_matriz_nxn_entre_valores(v+n/2   ,n/2 , m, a , b );
        s+= suma_matriz_nxn_entre_valores(v+n/2   ,n/2 ,m+n/2, a, b);
    
        return s;
    }
}

int main() {
    int n = 4; // Tamaño de la matriz
    imatriz2d v = icreamatriz2d(n, n); // Crear una matriz de n x n

    // Inicializar la matriz con algunos valores
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            v[i][j] = i * n + j + 1; // Ejemplo de inicialización
        }
    }

    int a = 5, b = 10; // Valores entre los cuales contar
    int resultado_clasico = suma_matriz_nxn_entre_valores_clasico(v, n, a, b);
    int resultado_divide_y_venceras = suma_matriz_nxn_entre_valores(v, n, 0, a, b);

    printf("Resultado clásico: %d\n", resultado_clasico);
    printf("Resultado divide y vencerás: %d\n", resultado_divide_y_venceras);

    ifreematriz2d(v); // Liberar memoria de la matriz
    return 0;
}