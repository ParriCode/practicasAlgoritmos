#include <stdlib.h>
#include <stdio.h>

#include "imatriz2d/imatriz2d.h"
#define MAX(a, b) ((a) < (b) ? (a) : (b))

void botellonjusto(int * v , int n  ){

    //cantidad totañ
    int cantidad = 0; 
    for(int i = 0; i <= n; ++i){
        cantidad += v[i];
    }
    int cantidad2 = cantidad/2;

    imatriz2d m = icreamatriz2d(n+1,cantidad+1);
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= cantidad; ++j){
            m[i][j] = 0;  // inicialización de la matriz
        }
    }
    int sol[n+1];
    for(int i = 0; i <=n ; ++i){
        sol[n] = 0;
    }
    int k = 0;
 //   for(int i = 0; i<= n; cantidad)
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= cantidad; ++j){
            if(v[i] <= j){
                m[i][j]  =  m[i-1][j-v[i]] + v[i];
                sol[k++] = i;  
            }
            else{
                m[i][j]  = m[i-1][j];
            }
        }
    }

    //imprimit matriz
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= cantidad; ++j){
            printf("%d, ", m[i][j]);
        }
        printf("\n");

    }

    for(int i = 0; i < k ; ++i){
        printf("%d, ", sol[i]);
    }
    printf("\n");

    ifreematriz2d(&m);
}




/**
 * @brief Problema del cambio de monedas
 * 
 * 
 * @param argc 
 * @param argv 
 * @return 
 */
int main(int argc , char * argv[]){
    int v[] = {0,6,10,8,2};
    botellonjusto(v, 4);

    return 0;
}