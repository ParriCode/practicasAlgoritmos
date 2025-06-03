#include <stdio.h>
#include <stdlib.h>
#include "imatriz2d/imatriz2d.h"


/**
 * @brief Dada una matriz de adyacencia encontrar un camino de hamilton en el grafo
 * 
 * 
 * @param m matriz de adyacencia
 * @param n tamaño
 */
void hamilton(imatriz2d m, int n,int k, int *sol , int v, int *encontrado){
  //  printf("HOLA %d\n",k);
    if(*encontrado) return;
    if(v == n ){
        printf("Hamilton: \n");
        for(int i = 0; i< v; ++i){
            printf("%d, ",sol[i]);
        }
        printf("\n");
        *encontrado = 1;
        return;
    }
    else{
        for(int i = 0; i < n ; ++i){ //recorrer todos los vertices
            if(m[k][i]){ //poda del arbol  
                sol[v] = i;
                m[k][i] = 0; // marcar como visitado para la poda
                m[i][k] = 0;
                hamilton(m , n ,i , sol , v+1,encontrado);
            }
        }
    }
}
#define TAM 6
int main(){

    int adj[TAM][TAM] = {
        {0, 0, 0, 0, 1,1},  // vértice 1 conectado a 2 y 5
        {0, 0, 0, 1, 1,0},  // vértice 2 conectado a 1 y 3
        {0, 0, 0, 1, 0,1},  // vértice 3 conectado a 2 y 4
        {0, 1, 1, 0, 0,0},  // vértice 4 conectado a 3 y 5
        {1, 1, 0, 0, 0,0},   // vértice 5 conectado a 1 y 4
        {1, 0, 1, 0, 0,0}   // vértice 5 conectado a 1 y 4
    };
    /*int adj[TAM][TAM] = {
        {0,1,1,1},
        {1,0,1,1},
        {1,1,0,1},
        {1,1,1,0}
    };*/
    imatriz2d m;
    m = icreamatriz2d(TAM,TAM);
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            m[i][j] = adj[i][j];
        }
    }
    
    int sol[TAM];
    int encontrado = 0;
    hamilton(m,TAM,0,sol,0, &encontrado);

    return 0;
}