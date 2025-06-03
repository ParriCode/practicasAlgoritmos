/**
 * @file ejercicio4.c
 * @author Jose Luis Parrilla Fuentes 
 * @brief Resolver el problema del laberinto utilizando un algoritmo Las Vegas. 
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

typedef enum{
    C, //camino
    O, //obstáculo
    E, //Entrada
    S //Salida

} tipos;

typedef enum{
    Norte = 0, Sur, Este,Oeste //puntos cardinales (direcciones)
} direcciones;
/**
 * @brief 
 * 
 * @param m 
 * @param a 
 * @param b 
 * @param xi 
 * @param yi 
 * @return 
 */
int vegas(imatriz2d m, int x , int y, int * camino, int *longcamino){

  

    int n_opciones = 1;
    direcciones opciones[4];
    while(1){
        
        n_opciones = 0;
        //Si estamos en la salida lo cogemos directamente
        if(m[x][y+1] == S){ camino[(*longcamino)++] = Este;  return 1; }
        if(m[x][y-1] == S){ camino[(*longcamino)++] = Oeste; return 1; }
        if(m[x+1][y] == S){ camino[(*longcamino)++] = Sur;   return 1; }
        if(m[x-1][y] == S){ camino[(*longcamino)++] = Norte; return 1; }

        if(m[x][y+1] == C){ //NORTE
            opciones[n_opciones++] = Este;
        }
        if(m[x][y-1] == C){ // SUR
            opciones[n_opciones++] = Oeste;
        }
        if(m[x+1][y] == C){ //ESTE
            opciones[n_opciones++] = Sur;
        }
        if(m[x-1][y] == C){ //OESTE
            opciones[n_opciones++] = Norte;
        }
        m[x][y] = O; //ya visitado no hay backtraking

        if(n_opciones != 0){
            camino[(*longcamino)++] = opciones[rand() % (n_opciones)]; // corregido índice aleatorio
            switch (camino[*longcamino - 1]) {
                case Este:
                    y++;
                    break;
                case Oeste:
                    y--;
                    break;
                case Sur:
                    x++;
                    break;
                case Norte:
                    x--;
                    break;
            
            }
        }else break;
    }
    return 0;
}

int main(int argc , char * argv[]){
    srand(time(NULL));
    int laberinto [10][10] = {
        {O, O, O, O, O, O, O, O, O, O},
        {O, E, C, C, O, O, O, O, C, O},
        {O, C, O, C, O, O, O, O, C, O},
        {O, C, C, C, C, C, S, O, C, O},
        {O, C, O, O, O, O, C, O, C, O},
        {O, C, O, O, O, O, C, O, C, O},
        {O, C, O, O, O, O, C, O, C, O},
        {O, C, O, O, O, C, C, C, C, O},
        {O, C, C, C, C, C, O, O, O, O},
        {O, O, O, O, O, O, O, O, O, O}
    };
    imatriz2d m;
    m = icreamatriz2d(10,10);
    for(int i = 0; i < 10; ++i ){
        for(int j = 0; j < 10; ++j){
            m[i][j] = laberinto[i][j];
        }   
    }
    int camino[10*10];
    int longcamino = 0;
    printf("Iniciando depuración del laberinto...\n"); // Mensaje para depuración
    if(vegas(m , 1, 1, camino, &longcamino)){
        printf("Camino encontrado \n");
    }else{
        printf("Camino NO encontrado\n");
    }
    printf("longitud camino: %d\n", longcamino);
    for(int i = 0;i < longcamino; ++i){
        switch (camino[i])
        {
    
        case Norte:
            printf("N,");
            break;
        case Sur:
            printf("S,");
            break;
        case Este:
            printf("E,");
            break;
        case Oeste:
            printf("O,");
            break;
        
        default:
            break;
        }
    }

    printf("El laberinto queda así: \n");
    for(int i = 0; i < 10; ++i ){
        for(int j = 0; j < 10; ++j){
        switch (m[i][j])
            {
        
            case O:
                printf("O ");
                break;
            case S:
                printf("S ");
                break;
            case E:
                printf("E ");
                break;
            case C:
                printf("C ");
                break;
            
            default:
                break;
            }
        }
        printf("\n");
    }
    ifreematriz2d(&m);
    return 0;
}
