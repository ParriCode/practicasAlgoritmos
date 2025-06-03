#include <stdio.h>
#include <stdlib.h>




/**
 * @brief Problema 1: Formas de sacar un valor dado con n dados
 * Se dispone de n dados de 6 caras. Se desea conocer el número de
 * combinaciones que existen para conseguir una puntuación m dada con los n
 * dados.
 * 
 * @param n Numero de dados
 * @param m puntuacion que hay que sacar
 * @param sol Numero de combinaciones posibles
 * @return 
 */
int combinaciones(int n, int m , int sol,int *comb){
    if(n == -1 && m == 0){
        for(int i = 0; i < 5; ++i){
            printf("%d, ",comb[i]);
        }
        printf("\n");
        return sol+1;
    }
    for(int i = 1 ;  i <= 6; ++i){
        if(!(i + n*6 < m || i + n > m)  ){ //Quitar soluciones que no se van a dar
            comb[n] = i;
            sol = combinaciones(n -1 , m-i, sol ,comb);
            //printf("%d, ",i);
        }
    }
    return sol;
}

int main(int argc , char * argv[]){
    printf("HOLA MUNDO");
    int n = 5; 
    int m = 10;
    int sol = 0;
    int comb[n];
    int s = combinaciones(n-1, m ,sol,comb);
    printf("\nResultado: %d\n",s);
    return 0;
}