#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "imatriz2d/imatriz2d.h"


imatriz2d P;

void tratar(int i) {
    printf("%d ", i);
}
void trayectoria( int  i , int j){
    int k = P[i][j];
    if (k != 0) {
        trayectoria(i, k);
        tratar(k);
        trayectoria(k, j);
    }

}
void camino(int i, int j) {
    tratar(i);
    trayectoria(i, j);
    tratar(j);
}

int min_traducciones(imatriz2d m , int n , int a , int b){
    P = icreamatriz2d(n+1, n+1);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            P[i][j] = 0;
        }
    }
    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(j != i && m[k][j] + m[i][k] < m[i][j]){
                    m[i][j] = m[k][j] + m[i][k];
                    P[i][j] = k; // camino
                }
            }
        }
    }
    printf("Solucion\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(m[i][j] >= 1000){
                printf("in,");
            }else{
                printf("%2d,",m[i][j]); 

            }
        }
        printf("\n");
    }
    printf("\n");
    camino(a, b);
    printf("\n");
    return m[a][b];
}



int main(){
    int n = 5;
    imatriz2d m = icreamatriz2d(n,n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            m[i][j] = (i == j) ? 0 : 1000; 
        }
    }

    m[0][1] = 1; m[1][0] = 1000; // Conexión entre nodo 0 y 1
    m[0][3] = 1; m[3][0] = 1; // Conexión entre nodo 0 y 3
    m[1][2] = 1000; m[2][1] = 1; // Conexión entre nodo 1 y 2
    m[2][3] = 1; m[3][2] = 1; // Conexión entre nodo 2 y 3
    m[3][4] = 1000; m[4][3] = 1; 

    int precio = min_traducciones(m, n, 4, 1);
    printf("El  la traduccion más corta entre %d  - %d tiene traducciones: %d\n", 4, 1 , m[4][1]);

    ifreematriz2d(&m);
    ifreematriz2d(&P);
    return 0;
}