/**
 * @file ejercicio3.h
 * @author your name (you@domain)
 * @brief 
 * @version 0.1
 * @date 2025-03-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#ifndef EJERCICIO3_H
#define EJERCICIO3_H

#include "../imatriz2d/imatriz2d.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdio.h>
#include <limits.h>

#define NO_EDGE -1 // nalor que representa la ausencia de arista
void primMST(imatriz2d m, int n){
    int padres[n];
    int claves[n];
    int visitados[n];
    for(int i = 0; i < n ; ++i){
        claves[i] = INT_MAX; //Claves puestas en infinito
        visitados[i] = 0; //ningun nodo visitado
        padres[i] = -1; //Nadie con padre
    }


    claves[0] = 0; //primera clave es 0 , nodo raiz
    //n -1 porque el padre ya está incluido
    for(int c = 0; c < n -1; ++c){
        int min = INT_MAX;
        int k = -1; 
        for(int v = 0; v < n; ++v){
            if(!visitados[v] && claves[v] < min){
                min = claves[v];
                k = v;
            }
        }
        //Si la k no se actualiza entonces el grafo es no conexo
        if( k == -1){printf("Grafo no conexo"); break;}
        visitados[k] = 1;

        //actualizar claves de ls nodos más cercanos
        for(int v = 0; v < n; ++v){
            if( m[k][v] != -1 && !visitados[v] && m[k][v] < claves[v]){
                padres[v] = k;
                claves[v] = m[k][v];
            }
        }
        //imprimit padres
        
        
    }


    printf("\nArista   Peso\n");
    int total = 0;
    for (int i = 1; i < n; i++) {
        if (padres[i] != -1) {
            printf("%d - %d    %d\n", padres[i], i, m[padres[i]][i]);
            total += m[padres[i]][i];
        }
    }
    printf("Peso total del MST: %d\n", total);

}
void redOrdenadores(imatriz2d m, int n) {
    primMST(m,n);
    printf("Primer prim acabado\n");
   
    int parent[n];   // Almacena el MST
    int key[n];      // nalores clave para seleccionar la arista mínima
    int inMST[n];    // Nodos incluidos en el MST
    
    // Inicialización
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        inMST[i] = 0;
        parent[i] = -1;
    }
    
    key[0] = 0; // Iniciar desde el nodo 0

    for (int count = 0; count < n - 1; count++) {
        // Seleccionar nodo con clave mínima no incluido en MST
        int min = INT_MAX, u = -1;
        for (int v = 0; v < n; v++) {
            if (!inMST[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }
        
        if (u == -1) {
            printf("¡Grafo no conexo! No existe MST completo.\n");
            return;
        }
        
        inMST[u] = 1; // Incluir nodo en MST
        
        // Actualizar claves de nodos adyacentes
        for (int v = 0; v < n; v++) {
            if (m[u][v] != NO_EDGE && !inMST[v] && m[u][v] < key[v]) {
                parent[v] = u;
                key[v] = m[u][v];
            }
        }
    }

    // Imprimir MST y peso total
    printf("Arista   Peso\n");
    int total = 0;
    for (int i = 1; i < n; i++) {
        if (parent[i] != -1) {
            printf("%d - %d    %d\n", parent[i], i, m[parent[i]][i]);
            total += m[parent[i]][i];
        }
    }
    printf("Peso total del MST: %d\n", total);
}


#endif
