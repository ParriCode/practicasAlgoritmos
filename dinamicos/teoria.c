#include <stdlib.h>
#include <stdio.h>
#include "imatriz2d/imatriz2d.h"
/**
 * @brief Calculo sucesión fibonacci con programación dinámica 
 * 
 * 
 * @param n número de la sería a calcular
 * @return numero n de la serie de fibonacci
 */
long fib1(int n){
    int i;
    int *v = (int*)malloc(sizeof(int)*(n+1));
    long res;
    v[0] = 0; v[1] = 1;
    for(i = 2; i <= n; ++i){
        v[i] = v[i-1]+v[i-2];
    }
    res = v[n];
    free(v);
    return res;
}
/**
 * @brief Dado un conjunto n , devolver el número de k-combinaciones posible 
 * 
 * 
 * @param n Número de elementos del conjunto
 * @param k Número de elementos de la combinación
 * @return Número de k-combinaciones posibles
 */
int combinaciones(int n , int k){
    int i;//iterador
    int j;
    int m[n+1][k+1];

    //iniclaizar la matriz en 0
    for(i = 1; i <= n; ++i){
        for(j = 0; j<= k; ++j){
            m[i][j] = 0;
        }
    }

    for(i =  0; i <= n; ++i){
            m[i][0] = 1;
    }
    for(j = 0; j<= k;++j){
        m[j][j] = 1;
    }
    for(i = 2; i<= n; ++i){
        for(j = 1; j<= k; ++j){
            m[i][j] = m[i-1][j-1] + m[i-1][j];
        } 
    }


    return m[n][k];



}


int main(){
    printf("fibbonachi: = %ld \n",fib1(10));
    printf("combinaciones: = %d\n",combinaciones(5,2));


    return 0;
}