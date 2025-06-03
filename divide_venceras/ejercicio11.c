#include <stdlib.h>
#include <stdio.h>

#include <limits.h>

int f(int V[], int U[], int a , int b){
    if(a == b){
        return V[a] == U[a] ? -1: a;
    }else{
        int m = (a+b)/2;
        int i1 = f(V, U, a, m);
        int i2 = f(V, U, m + 1, b);
        if(i1 == -1 && i2 == -1){
            return -1; //si ambos son -1 entonces no hay diferencias
        }
        if(i1 != -1 && i2 != -1){
            return i1 < i2 ? i1 : i2;
        }
        return i1 != -1 ? i1 : i2;
    }
}

int main() {
    int n;
    printf("Ingrese el número de elementos: ");
    scanf("%d", &n);
    
    int *V = malloc(n * sizeof(int));
    int *U = malloc(n * sizeof(int));
    
    printf("Ingrese los elementos del vector V:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &V[i]);
    }
    
    printf("Ingrese los elementos del vector U:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &U[i]);
    }
    
    int result = f(V, U, 0, n - 1);
    
    if (result != -1) {
        printf("El primer índice donde V y U son diferentes es: %d\n", result);
    } else {
        printf("No hay índices donde V y U no sean diferentes.\n");
    }
    
    free(V);
    free(U);
    
    return 0;
}