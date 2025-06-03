
/**
 * @file merguesort.c
 * @author Jose Luis Parrilla Fuentes (theparri@protonmail.com)
 * @brief Implementación del algoritmo mergesort
 * @version 0.1
 * @date 2025-02-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */
int n0_mergesort = 64;

#include <stdlib.h>
/**
 * @brief Ordena un vector de enteros v de tamaño n mediante el algoritmo de inserción
 * @details El algoritmo consiste en recorrer el vector e insertar luego yendo hacia atrás en la posición correcta
 * @param v vector
 * @param n numero de elementos del vector
 * @post v estara ordenado de menor a mayor
 */
void insercion(int v[], int n){
    int j = 0;
    for(int i = 1; i < n ; ++i){
        int aux = v[i];
        int j = i -1;
        while(v[j] > aux && j >= 0){
            v[j+1] = v[j];
            --j;
        }
        v[j+1] = aux;
    }
}
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
void merge(int v[], int u[], int n, int m){
    int i , j , k ;
    i = j = k = 0;
    
    int *w = (int*)malloc((m+n)*sizeof(int));

    while (j < n && k < m) {
        if (v[j] < u[k]) {
            w[i++] = v[j++];
        } else {
            w[i++] = u[k++];
        }
    }
    for(int i = 0;i < n+m; ++i){
        v[i] = w[i];
    }
    free(w);
}
/**
 * @brief Ordenacion por metodo merguesort
 * @details n0 == 10
 * @param v 
 * @param a 
 * @param b 
 */
void mergesort(int v[], int a , int b){
    if(a >= b) return;
    if((b-a+1) < n0_mergesort){
        insercion(v+a,b-a);
    }
    else{
        int m = a+(b-a)/2; //Mitad del vector
        mergesort(v,a,m); //Desde v con m-n 
        mergesort(v,m+1,b); //u coge desde principio hasta m
        merge(v+a,v+m,m-a,b-m); //mergue siempre recibe el puntero bien reservado
        }
}
int main() {
    int v[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(v) / sizeof(v[0]);
    
    mergesort(v, 0, n - 1);
    
    printf("Vector ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    
    return 0;
}