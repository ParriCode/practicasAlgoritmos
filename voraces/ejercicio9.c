#include <stdlib.h>
#include <stdio.h>
#include "disjoint/disjoint.h"  // Debe contener disjoint_nuevo, disjoint_find, disjoint_merge

typedef struct {
    int origen;
    int destino;
} Arista;

int conexo(int N , int M , Arista A[]){
    disjoint conjuntos = disjoint_nuev(N);
    for(int i = 0; i< M ; ++i){
        int orig = disjoint_find(conjuntos, A[i].origen);
        int dest = disjoint_find(conjuntos, A[i].destino);
        if(orig != dest){
            disjoint_merge(conjuntos, orig, dest);
        }
    }
    int n = disjoint_find(conjuntos, 0);
    for(int i = 1; i < N ; ++i){
        if(disjoint_find(conjuntos, i) != n){
            return 0;
        }
    }
    return 1;
}
int main() {
    Arista aristas[] = {
        {0, 1},  // A-B
        {1, 2},  // B-C
  // C-D
        {3, 4},  // D-E
 
    };
    int n_vertices = 5;
    int n_aristas = sizeof(aristas) / sizeof(aristas[0]);
    
    if (conexo(n_vertices, n_aristas, aristas)) {
        printf("El grafo es conexo.\n");
    } else {
        printf("El grafo no es conexo.\n");
    }
    
    return 0;
}