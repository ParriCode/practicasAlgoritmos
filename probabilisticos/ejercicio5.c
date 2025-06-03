/**
 * @file ejercicio5.c
 * @author Jose Luis Parrilla Fuentes
 * @brief Diseña un algoritmo Las Vegas que resuelva el problema de recorrer un tablero
 * de ajedrez con un caballo comenzando en la esquina superior izquierda (0,0) y
 * sin pasar dos veces por el mismo escaque.
 * @version 0.1
 * @date 2025-04-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#include <stdlib.h>
#include <stdio.h>
#include "imatriz2d/imatriz2d.h"
#include <time.h>


/**
 * @brief Recorrer un tablero de ajedrez con un caballo sin pasar 2 veces por el mismo sitio 
 * 
 * 
 * @param tablero 
 * @return true si hay solucion , false sino , la matriz del tablero es modificada 
 */
int recorrer_tablero(imatriz2d tablero){
    tablero[0][0] = 0;
    int nopciones = 1;
    int opciones[8]; //Las opciones vienen "codificadas" para hacerlo más fácil
    int x = 0; 
    int y = 0;
    int camino  = 0;
    while(camino < 64){
        nopciones = 0;
        //Hay que verificar que no se sale de los límites y que la casilla está no visitada (-1)
        if(x+1 >= 0 && x+1 < 8 && y-2 >= 0 && y-2 < 8 && tablero[x+1][y-2] == -1){
            opciones[nopciones++] = 0;
        }
        if(x+1 >= 0 && x+1 < 8 && y+2 >= 0 && y+2 < 8 && tablero[x+1][y+2] == -1){
            opciones[nopciones++] = 1;
        }
        if(x-1 >= 0 && x-1 < 8 && y+2 >= 0 && y+2 < 8 && tablero[x-1][y+2] == -1){
            opciones[nopciones++] = 2;
        }
        if(x-1 >= 0 && x-1 < 8 && y-2 >= 0 && y-2 < 8 && tablero[x-1][y-2] == -1){
            opciones[nopciones++] = 3;
        }
        if(x+2 >= 0 && x+2 < 8 && y+1 >= 0 && y+1 < 8 && tablero[x+2][y+1] == -1){
            opciones[nopciones++] = 4;
        }
        if(x+2 >= 0 && x+2 < 8 && y-1 >= 0 && y-1 < 8 && tablero[x+2][y-1] == -1){
            opciones[nopciones++] = 5;
        }
        if(x-2 >= 0 && x-2 < 8 && y-1 >= 0 && y-1 < 8 && tablero[x-2][y-1] == -1){
            opciones[nopciones++] = 6;
        }
        if(x-2 >= 0 && x-2 < 8 && y+1 >= 0 && y+1 < 8 && tablero[x-2][y+1] == -1){
            opciones[nopciones++] = 7;
        }
        if(nopciones == 0) return 0;
        int opcion = opciones[rand() % (nopciones)];
        switch (opcion)
        {
            case 0:
                ++x;
                y -= 2;
                break;
            case 1:
                ++x;
                y += 2;
                break;
            case 2:
                --x;
                y += 2;
                break;
            case 3:
                --x;
                y -= 2;
                break;
            case 4:
                x += 2;
                ++y;
                break;
            case 5:
                x += 2;
                --y;
                break;
            case 6:
                x -= 2;
                --y;
                break;
            case 7:
                x -= 2;
                ++y;
                break;
        }
        ++camino;

        tablero[x][y] = camino;
    }
    return 1;
}



int main(int argc, char * argv[]){
    srand(time(NULL));
    imatriz2d tablero = icreamatriz2d(8,8);
    //inicalizar las casillas como no visitadas
    for(int i = 0; i< 8; ++i){
        for(int j = 0; j < 8 ; ++j){
            tablero[i][j] = -1;
        }
    }

    if(recorrer_tablero(tablero)){
        printf("Solución encontrada\n");
    }else{
        printf("Solución NO encontrada\n");
    }
    for(int i = 0; i< 8; ++i){
        for(int j = 0; j < 8 ; ++j){
            printf("%2d ",tablero[i][j]);
        }
        printf("\n");
    }

    ifreematriz2d(&tablero);


    return 0;
}