#include <stdlib.h>
#include <stdio.h>

#include "imatriz2d/imatriz2d.h"
/**
 * @brief calculo de binomiales 
 * 
 * 
 * @param a arriba
 * @param b  abajo
 */
void binomiales(int a, int b){
    imatriz2d m = icreamatriz2d(b+1, a+1);
 
    for(int i = 0; i<= b; ++i){
        for(int j = 0; j<= a; ++j){
            m[i][j] = 1; //Si j == 0 o i = j;        
        }
    }
    
    for(int j = 1; j<= b; ++j){
        for(int i = j +1; i<= a; ++i){ //quitar triangulo inferior de la matriz igualando i a j+1

            if(i == j){
                m[j][i] = 1;
            }else{
                m[j][i] = m[j][i-1]+ m[j-1][i-1];

            }
        }

    }

    printf("Mostrar matriz\n");
    for(int i = 0; i <= b; ++i){
        for(int j = 0; j <= a; ++j){
            printf("%2d, ",m[i][j]);
        }
        printf("\n");
    }
    printf("La solucion es: %d\n", m[b][a]);
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
    binomiales(10,4);

    return 0;
}