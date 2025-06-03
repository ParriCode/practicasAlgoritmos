#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "imatriz2d/imatriz2d.h"


/**
 * @brief Obtener el camino más barato entre 2 puertos dado un grafo no dirijido 
 * @details 
 * 
 * @param m grafo de embarcaderos 
 * @param n tamaño del grafo
 * @param a puerto origen
 * @param b puerto destino 
 * @return precio más barato
 */
int precio_barato(imatriz2d m, int n , int a , int b){
    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(i != j && m[i][j] > 0 && m[i][k] + m[k][j] < m[i][j]){
                    m[i][j] = m[i][k] + m[k][j] ;
                }
            }
        }
    }
    printf("Solucion\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(m[i][j] == 1000){
                printf("in,");
            }else{
                printf("%2d,",m[i][j]); 

            }
        }
        printf("\n");
    }
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

    m[0][1] = 3; m[1][0] = 3; // Conexión entre nodo 0 y 1
    m[0][3] = 3; m[3][0] = 7; // Conexión entre nodo 0 y 3
    m[1][2] = 6; m[2][1] = 2; // Conexión entre nodo 1 y 2
    m[2][3] = 30; m[3][2] = 1; // Conexión entre nodo 2 y 3
    m[3][4] = 5; m[4][3] = 5; 

    int precio = precio_barato(m, n, 4 ,2);
    printf("El camino más barato entre %d  - %d tiene precio: %d\n", 2, 4 , m[2][4]);

    ifreematriz2d(&m);
    return 0;
}