/**
 * @file prim.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "prim.h"
#include <limits.h>

// El motherfucker algoritmo de prim encuentra un arbol generador minimal comunicando las aristas de un grafo conexo

void prim2(imatriz2d m, int n) {
    int mascerca[n];
    int mindist[n];
    int T[n-1][2];
    int k = -1;
    int min = INT_MAX;

    for(int i = 0; i < n; ++i){
        mindist[i] = m[i][0];
        mascerca[i] = 0;
    }
    mindist[0] = -1;

    for(int i = 0; i< n-1; ++i){
        k = -1;
        min = INT_MAX;
        for(int j = 0; j < n; ++j){
            if(mindist[j] != -1; && mindist[j] < min){
                min = mindist[j];
                k = j;
            }
        }
        if(k == -1){
            printf("GRAFO NO CONEXO");
        }
        T[i][0] = mascerca[k];
        T[i][1] = k;
        mindist[k] = -1;
        printf(" %d - %d costo: %d ", T[i][0], T[i][1] , min);

        for(int j = 0; j< n; ++j){
            if(m[k][j] < mindist[j] && mindist[j] != -1){
                mascerca[j] = k;
                mindist[j] = m[k][j];
            }
        }




    }
    


}

void prim(imatriz2d m, int N) {
    prim2(m , N);
    return;
    int mascerca[N];  // Guarda el nodo más cercano en el MST
    int mindist[N];   // Guarda la distancia mínima al MST
    int T[N - 1][2];  // Guarda las aristas del MST
    int k = 0, min;

    // Inicializar arrays
    for (int i = 0; i < N; ++i) {
        mascerca[i] = 0;        // Inicialmente, cada nodo está conectado al nodo 0
        mindist[i] = m[i][0];   // Distancia al nodo 0
    }
    mindist[0] = -1; // Nodo 0 ya está en el árbol

    for (int i = 0; i < N - 1; ++i) {
        min = INT_MAX;
        k = -1;

        // Encontrar el nodo no visitado más cercano
        for (int j = 0; j < N; ++j) {
            if (mindist[j] != -1 && mindist[j] < min) {
                min = mindist[j];
                k = j;
            }
        }

        // Si no encontramos un nodo válido, el grafo no es conexo
        if (k == -1) {
            printf("GRAFO NO CONEXO\n");
            return;
        }

        // Guardamos la arista en el MST
        T[i][0] = mascerca[k];
        T[i][1] = k;
        printf("Arista seleccionada: %d - %d, costo: %d\n", mascerca[k], k, min);

        // Marcar el nodo como visitado
        mindist[k] = -1;

        // Actualizar las distancias
        for (int j = 0; j < N; ++j) {
            if (m[k][j] < mindist[j] && mindist[j] != -1) {
                mindist[j] = m[k][j];
                mascerca[j] = k;
            }
        }
    }

    // Imprimir el árbol generador mínimo
    printf("\nAristas del Árbol Generador Mínimo:\n");
    for (int i = 0; i < N - 1; ++i) {
        printf("%d - %d\n", T[i][0], T[i][1]);
    }
}

