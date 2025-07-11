/**
 * @file ejercicio11.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int id;
    int longitud;
} cinta;

int cmp(const void *a, const void *b){
    return ((cinta*)b)->longitud - ((cinta*)a)->longitud; 
}

void mezclar_cintas(cinta * cintas, int n){
    //ordenar de mayor a menor , ya que si la mayor se queda estática tendremos que hacer un menor número de movimientos
    qsort(cintas, n, sizeof(cinta) , &cmp);
    int suma_movimientos = 0;
    int antmov  = cintas[n-1].longitud;
    for(int i = 0; i < n; ++i){
        printf("%d ", cintas[i]);
    } 
    for(int i = n-1; i>= 0; --i){

        suma_movimientos += cintas[i].longitud + antmov;
    }
    printf("\n");
    printf("El total de movimientoes es %d\n", suma_movimientos);
}

int main() {
    int n;
    printf("Introduce el número de cintas: ");
    scanf("%d", &n);
    
    cinta *cintas = (cinta *)malloc(n * sizeof(cinta));
    
    for(int i = 0; i < n; ++i) {
        cintas[i].id = i + 1; // Asignar un ID a cada cinta
        printf("Introduce la longitud de la cinta %d: ", cintas[i].id);
        scanf("%d", &cintas[i].longitud);
    }
    
    mezclar_cintas(cintas, n);
    
    free(cintas);
    return 0;
}