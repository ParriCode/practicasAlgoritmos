#include <stdio.h>

#include <stdlib.h>
#include <limits.h>
#include "imatriz2d/imatriz2d.h"

void recorrido(imatriz2d tablero, int n , int k, int x, int y, int * encontrado){
   // fflush(stdout);
    if(k == n*n ){ //Solucion encontrada
        *encontrado = 1;
        printf("ENCONTRADO \n");
        for(int i = 0; i < n ; ++i){
            for(int j = 0; j < n ; ++j){
                printf("%2d ",tablero[i][j]);
            }
            printf("\n");
        }
        return ;

    }
    if( x < 0 || x >=  n || y < 0 || y  >= n  ||tablero[x][y] != 0 ) {return; //poda de arbol , esta solucion ya no sirve
    }else{
        tablero[x][y] = k+1; // Se marca como visitada y además es gay
        if(!*encontrado) recorrido(tablero, n, k +1, x-1 ,y-2, encontrado);
        if(!*encontrado) recorrido(tablero, n, k +1, x-2 ,y-1, encontrado);
        if(!*encontrado) recorrido(tablero, n, k +1, x-2 ,y+1, encontrado);
        if(!*encontrado) recorrido(tablero, n, k +1, x-1 ,y+2, encontrado);

        if(!*encontrado) recorrido(tablero, n, k +1, x+1 ,y+2, encontrado);
        if(!*encontrado) recorrido(tablero, n, k +1, x+2 ,y+1, encontrado);
        if(!*encontrado) recorrido(tablero, n, k +1, x+2 ,y-1, encontrado);
        if(!*encontrado) recorrido(tablero, n, k +1, x+1 ,y-2, encontrado);

        tablero[x][y] = 0;
    }
}


#define n 10
int main(){
    imatriz2d m = icreamatriz2d(n,n);
    for(int i = 1; i < n -1; ++i){
        for(int j = 1; j < n -1; ++j){
            m[i][j] = 0; 

        }
    }
    for(int i = 0; i < n ; ++i){
        for(int j = 0; j < n ; ++j){
            printf("%2d ",m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    imatriz2d sol = icreamatriz2d(n,n);
    int encontrado = 0;
    recorrido(m, n, 0,0,0,&encontrado);
    return 0;
}