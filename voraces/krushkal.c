#include <stdlib.h>
#include "disjoint/disjoint.h"  // Debe contener disjoint_nuevo, disjoint_find, disjoint_merge
#include <stdio.h>
typedef struct {
    int origen;
    int destino;
    int coste;
} Arista;

int comparar_aristas(const void *a, const void *b) {
    const Arista *A1 = (const Arista *)a;
    const Arista *A2 = (const Arista *)b;
    return A1->coste - A2->coste;
}

/**
 * @brief Implementación del algoritmo de Kruskal para encontrar el árbol generador mínimo de un grafo.
 * @param N Número de nodos en el grafo.
 * @param M Número de aristas en el grafo.
 * @param A Arreglo de aristas del grafo.
 * @param peso Puntero donde se almacenará el peso total del árbol generador mínimo.
 * @return Conjunto disjunto que representa los componentes conectados del grafo.
 */
int kruskal(int N, int M, Arista A[], Arista mst[], int *peso) {
    disjoint conjuntos = disjoint_nuev(N);
    qsort(A, M, sizeof(Arista), comparar_aristas);

    int aristasAGM = 0;
    *peso = 0;
    for (int i = 0; i < M && aristasAGM < N - 1; i++) {
        int cjtoOrig = disjoint_find(conjuntos, A[i].origen);
        int cjtoDest = disjoint_find(conjuntos, A[i].destino);

        if (cjtoOrig != cjtoDest) {
            disjoint_merge(conjuntos, cjtoOrig, cjtoDest);
            *peso += A[i].coste;
            mst[aristasAGM++] = A[i]; // ← GUARDAMOS LA ARISTA
        }
    }

    return aristasAGM; // ← devolvemos el nº de aristas del MST
}

int main() {
    int n_vertices = 7;
    int n_aristas = 12;
    //Grfo de la teoría
    Arista aristas[] = {
    {0, 1, 1},
    {1, 2, 2},
    {0, 3, 4},
    {1, 3, 6},
    {1, 4, 4},
    {2, 4, 5},
    {2, 5, 5},
    {3, 4, 3},
    {4, 5, 8},
    {3, 6, 4},
    {4, 6, 7},
    {5, 6, 3}
    };

    int peso = 0;
    Arista mst[100]; // ← tamaño suficientemente grande (N-1 como máximo)

    int total_mst = kruskal(n_vertices, n_aristas, aristas, mst, &peso);
    printf("Peso del árbol generador mínimo: %d\n", peso);
    printf("Aristas del árbol generado:\n");
    for (int i = 0; i < total_mst; i++) {
        printf("%d -- %d (peso = %d)\n", mst[i].origen, mst[i].destino, mst[i].coste);
    }

}
