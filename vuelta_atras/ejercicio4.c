#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "imatriz2d/imatriz2d.h"

// Función para imprimir el laberinto
void imprimirLaberinto(imatriz2d l, int f, int c) {
    printf("Laberinto:\n");
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            switch (l[i][j]) {
                case 0: printf(" . "); break; // Camino
                case 1: printf(" # "); break; // Obstáculo
                case 2: printf(" * "); break; // Visitado
                case 3: printf(" E "); break; // Entrada
                case 4: printf(" S "); break; // Salida
            }
        }
        printf("\n");
    }
}

#define CAMINO 0
#define OBSTACULO 1
#define VISITADO 2
#define ENTRADA 3
#define SALIDA 4

typedef enum  {
    NORTE = 0,
    SUR = 1,
    ESTE = 2,
    OESTE = 3
} Direccion;

#define  FILAS  7
#define COLS  7

int * camino(imatriz2d l , int x, int y,int lo,  int *mincamino, Direccion * d, int  k){
    if( !(x < 0 || x == FILAS || y < 0 || y == COLS)){
       // printf("x = %d  y = %d  pos = %d \n",x,y,l[x][y]);
        if(l[x][y] == 4){
            if(lo < *mincamino){ 
                *mincamino = lo;
                printf("Camino: %d |",lo);
                for(int i = 0; i< k; ++i){
                    printf("%d, ",d[i]);
        
                }
                printf("\n");
            }
            
        }
    
        else if(l[x][y] != 1  && l[x][y] != 2){

            l[x][y] = 2;
            d[k] = ESTE;
            camino(l,x,y+1,lo +1,mincamino, d , k+1);
            d[k] = SUR;
            camino(l,x+1,y,lo +1,mincamino, d , k+1);
            d[k] = OESTE;
            camino(l,x,y-1,lo +1,mincamino, d , k+1);
            d[k] = NORTE;
            camino(l,x-1,y,lo +1,mincamino, d , k+1);
            l[x][y] = 0;
        }
    }
    



}

int main(){
    imatriz2d l;

    int laberinto[FILAS][COLS] = {
        {1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 3, 0, 1},
        {1, 0, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 4, 1},
        {1, 1, 1, 1, 1, 1, 1},
    };
    l = icreamatriz2d(FILAS, COLS);
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++) {
            l[i][j] = laberinto[i][j];
        }
    }
    int c[FILAS*COLS];
    int encontrado = 0;
    int min = INT_MAX;
    Direccion d[FILAS*COLS];






    imprimirLaberinto(l,FILAS,COLS);

    camino(l, 1, 4, 0 , &min, d,0);


    printf("Camino: %d |",min);
    for(int i = 0; i< min; ++i){
        printf("%d, ",d[i]);

    }
    printf("\n");


    
    ifreematriz2d(&l);
    return 0;
}