#include <stdio.h>
#include "imatriz2d/imatriz2d.h"
#include <stdlib.h>
#include <limits.h>


void recorrido(imatriz2d tablero, int n , int k, int x, int y, imatriz2d sol, int peso, int * minpeso){
  //  printf("hola: %d",k);
   // fflush(stdout);
    if(k == n*n ){ //Solucion encontrada

        if(peso < *minpeso) {
            *minpeso = peso;
            printf("Una solucion encontrada:%d \n",*minpeso);
            for(int i = 0; i < n ; ++i){
                for(int j = 0; j < n; ++j){
        
                    printf("%2d ",sol[i][j]);
                }
                printf("\n");
        
            }
        }
        return ;

    }
    if(peso >= *minpeso || x < 0 || x >=  n || y < 0 || y  >= n  ||tablero[x][y] == -1 ) {return; //poda de arbol , esta solucion ya no sirve
    }else{
        sol[x][y] = k;
        int pes = tablero[x][y];
        tablero[x][y] = -1; // marcar como recorrido
        recorrido(tablero, n, k +1, x+1 ,y+1  ,sol, peso+ (x +2)*(y+2)*(k+1) ,minpeso );
        recorrido(tablero, n, k +1, x+1 ,y    ,sol, peso+ (x +2)*(y+1)*(k+1) ,minpeso );
        recorrido(tablero, n, k +1, x+1 ,y-1  ,sol, peso+ (x +2)*(y  )*(k+1) ,minpeso );
        recorrido(tablero, n, k +1, x   ,y+1  ,sol, peso+ (x +1)*(y+2)*(k+1) ,minpeso );
        recorrido(tablero, n, k +1, x   ,y-1  ,sol, peso+ (x +1)*(y  )*(k+1) ,minpeso );
        recorrido(tablero, n, k +1, x-1 ,y    ,sol, peso+ (x   )*(y+1)*(k+1) ,minpeso );
        recorrido(tablero, n, k +1, x-1 ,y+1  ,sol, peso+ (x   )*(y+2)*(k+1) ,minpeso );
        recorrido(tablero, n, k +1, x-1 ,y-1  ,sol, peso+ (x   )*(y  )*(k+1) ,minpeso );
        tablero[x][y] = pes;
    }
}


#define n 5
int main(){


    imatriz2d m = icreamatriz2d(n,n);
    for(int i = 1; i <= n ; ++i){
        for(int j = 1; j <= n; ++j){
            m[i-1][j-1] = i*j ; 
            printf("%2d ",m[i-1][j-1]);
        }
        printf("\n");
    }
    printf("\n");
    imatriz2d sol = icreamatriz2d(n,n);
    int minpeso = INT_MAX ;
    recorrido(m, n, 0,0,0,sol,0,&minpeso);

  




}