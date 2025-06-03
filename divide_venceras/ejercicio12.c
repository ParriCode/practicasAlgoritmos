#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int min_loc(int v[], int a , int b){
    if(b -a < 10){
        for(int i = a +1; i < b-1; i++){
            if(v[i] < v[i-1] && v[i] < v[i+1]){
                return v[i]; //minimo local en el caso base
            }
        }
    }else{
        int m = (a+b) / 2;
        if(v[m] <= v[m-1] && v[m] <= v[m+1]){
            return v[m]; 
        }else if(v[m] >= v[m-1]){
            return min_loc(v, a, m-1); 
        }else{
            return min_loc(v, m, b); 
        }
    }
}

int main() {
    int n;
    printf("Ingrese el número de elementos: ");
    scanf("%d", &n);
    
    int *v = malloc(n * sizeof(int));
    
    printf("Ingrese los elementos del vector:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    
    int min_local = min_loc(v, 0, n );
    
    if (min_local != INT_MAX) {
        printf("El mínimo local es: %d\n", min_local);
    } else {
        printf("No hay mínimo local.\n");
    }
    
    free(v);
    
    return 0;
}