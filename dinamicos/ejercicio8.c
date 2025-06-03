#include <stdlib.h>
#include <stdio.h>

#include "imatriz2d/imatriz2d.h"


int MAX(int a , int b){return a > b ? a : b;}
/**
 * @brief 

 * 

 * @param p vector con los pesos d elos objetos
 * @param n Numero de objetos
 * @param M Capacidad máximo de la mochia
 * @param g vector de la ganancia por objeto
 * @details Tanto p , como g  , el primer elemento debe ser 0
 */
void mochila2(int * p, int n  , int M , int * g ){
    imatriz2d m = icreamatriz2d(n+1,M+1);
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= M; ++j){
            m[i][j] = 0;
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= M; ++j){
            if(p[i] <= j){
                m[i][j] = MAX(m[i][j-p[i]] +g[i] , m[i-1][j]);
            }else{
                m[i][j] = m[i-1][j];
            }
        }
    }
    printf("Mostrar matriz\n");
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= M; ++j){
            printf("%2d, ",m[i][j]);
        }
        printf("\n");
    }
    printf("Mostrar solucion: \n");
    int i = n;
    int j = M;
    int sol[n +1 ];
    for(int k = 0; k <= n; ++k){
        sol[k] = 0;
    }
    while(i > 0){

        if(m[i][j] == m[i-1][j]){
            i--;
        }else{
            j = j - p[i];
            sol[i]++;
            
        }
    }
    for(int k = 1; k <= n; ++k){
        printf("%d ", sol[k]);
    }
    printf("\n");
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
    const int n = 3;
    int peso[] = {0,1,2,3};
    int g[] = {0,1,5,7};
    mochila2(peso , n , 10, g);
    return 0;
}