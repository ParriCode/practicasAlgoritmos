#include <stdio.h>
#include <stdlib.h>
#include "disjoint/disjoint.h"  // Debe contener disjoint_nuevo, disjoint_find, disjoint_merge

typedef struct {
    int origen;
    int destino;
} Arista;


int conexiones(int N , int M , Arista A[]){
    disjoint conjuntos = disjoint_nuev(N);
    int aristasConectadas = 0;
    for(int i = 0; i< M ; ++i){
        int orig = disjoint_find(conjuntos, A[i].origen);
        int dest = disjoint_find(conjuntos, A[i].destino);
        if(orig != dest){
            disjoint_merge(conjuntos, orig, dest);
            ++aristasConectadas;
            printf("Conectando %d con %d\n", A[i].origen, A[i].destino);
        }
    }
    printf("Aristas conectadas: %d\n", aristasConectadas);
    int nConjuntos = 0;
    int arr[N];
    for(int i = 0; i < N ; ++i){
        arr[i] = disjoint_find(conjuntos, i);
    }
    for(int i = 0; i < N ; ++i){
        if(arr[i] == i){
            ++nConjuntos;
        }
    }
    printf("Número de conjuntos disjuntos: %d\n", nConjuntos);
    printf("relacion de gupos con ususarios = %f\n", nConjuntos / (float)N);
    return aristasConectadas;   
}
int main(){
        Arista aristas[] = {
        {0, 5},  // A-F
        {0, 2},  // A-C
        {1, 6},  // B-G
        {1, 7},  // B-H
        {2, 3},  // C-D
        {2, 5},  // C-F
        {4, 0}   // E-A
    };
    int n_vertices = 8 ;
    int n_aristas = sizeof(aristas) / sizeof(aristas[0]);
   conexiones(n_vertices, n_aristas, aristas);
   return 0;
}