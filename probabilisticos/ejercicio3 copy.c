/*Implementa la función de jaque y resuelve por completo el problema de las 8
reinas visto en clase de teoría.*/


#include <stdlib.h>
#include <stdio.h>
#include "imatriz2d/imatriz2d.h"
#include <time.h>

/**
 * @brief Verifica si las reinas colocadas en el tablero están en jaque
 * 
 * @param reinas reinas en el tablero , el indice es la columna , y el valor la fila de la reina
 * @return 1 si hay un jaque en el tablero , 0 sino lo hay
 */
int jaque(int reinas[8]){

    for(int i = 0; i< 8; ++i){ // En la misma conlumna no puede estar porque siempre se avanza así
        for(int j = i +1; j < 8; ++j){
            if(reinas[i] == -1 ) break; //reina no colocada
            if(reinas[j] == -1 ) continue; //reina no colocada
            if(reinas[j] == reinas[i]) return 1; // misma fila
            if(abs(reinas[i] - reinas[j]) == abs(i-j)) return 1; // misma diagonal
        }
    }
    return 0;
}

/**
 * @brief Resuelve el problema de las 8 reinas utilizando sherwood
 * 
 * @param reinas el indice representa la columna y el la valor la fila de la reina
 */
void problema(int*reinas){
    int k = 0;
    int posibles = 0;
    int it = 0; //Para ver el número de iteraciones
    int opciones[8];
    int no; //numero de opciones
    while(k < 8){
        posibles = 0;
        no = 0;
        for (int i = reinas[k] + 1; i < 8; ++i) { // probar desde la siguiente columna
            
            reinas[k] = i;
            if (!jaque(reinas)) {
                opciones[no++] = i;
            }
            reinas[k] = -1; //volver a marcar como no puesta
        }
        if (no == 0) {
            reinas[k] = -1;
            --k; // retroceder de fila
        } else {
            int elegido = opciones[rand() % no];
            reinas[k] = elegido;
            ++k;
        }
        printf("iteracion: %d\n", it);
     
        ++it;
      //  exit(1);

    }



}



/*void colocar_reinas(int * reinas ){
    int k = 0; // reinas puestas
    int aux = 0;
    int puestas = 0;
  

    while(k < 8){
        aux = 0;
        for(int i = 0; i< 8; ++i){
            reinas[k] = i;
            if(jaque(reinas)){


                printf("REINAS NO JAQUE\n");
                for(int i = 0; i < 8; ++i){
                    for(int j = 0; j < 8 ; ++j){
                        if(reinas[i] == j){
                            printf("1 ");
                        }else{printf("0 ");}
            
                    }
                    printf("\n");
            
                }
                aux = 1;
                break;
            }else{
                printf("jaque\n");
                printf("REINAS JAQUE\n");
                for(int i = 0; i < 8; ++i){
                    for(int j = 0; j < 8 ; ++j){
                        if(reinas[i] == j){
                            printf("1 ");
                        }else{printf("0 ");}
            
                    }
                    printf("\n");
            
                }
                printf("=================\n");
            }
            
        }
        if(!aux){

            k = rand() % 8;

            --puestas;

        }
        ++puestas;
        ++k;
    }

}*/

int main(int argc, char *argv[]){
    srand(time(NULL));

    int reinas[8] = {-1,-1,-1,-1
                    ,-1,-1,-1,-1};

    problema(reinas);
    printf("SOLUCION:\n");
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8 ; ++j){
            if(reinas[i] == j){
                printf("1 ");
            }else{printf("0 ");}

        }
        printf("\n");

    }


    return 0;
}