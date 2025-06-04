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
 * @param k Posición actual en la solución
 */
void combinaciones(int n , int m , int sol[] , int k){
    if(k == n){
        if(m == 0){
            // Si hemos usado todos los dados y la puntuación es 0, hemos encontrado una combinación válida
            printf("Combinación encontrada: ");
            for(int i = 0; i < n; ++i){
                printf("%d ", sol[i]);
            }
            printf("\n");
        }
        else{
            return;
        }
    }
    else if(m > (n-k)*6 || m < (n-k)){
        return ; //poda de combinaciones imposibles
    }
    else{
        for(int i = 1; i <= 6; ++i){ //Probar cada cara del dado
            sol[k] = i; //Asignar la cara del dado
            combinaciones(n, m - i, sol, k + 1); //Llamada recursiva para el siguiente dado
        }
    }
}

int main(int argc , char * argv[]){
    int n = 5; 
    int m = 10;
    int sol[5];
    combinaciones(n, m, sol, 0);
    return 0;

}