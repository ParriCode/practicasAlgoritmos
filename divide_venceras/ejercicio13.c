#include <stdlib.h>
#include <stdio.h>

int concava(int v[] , int a , int b){
    if(b == a){
        return v[a];
    }else{
        int m = (a + b) / 2;
        if(v[m] >= v[m +1]){
            return concava(v, m +1,  b); //buscamos en la parte izquierda
        }else{
            return concava(v, a , m); //buscamos en la parte derecha
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
    
    int result = concava(v, 0, n - 1);
    
    printf("El elemento concavo es: %d\n", result);
    
    free(v);
    
    return 0;
}