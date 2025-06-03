#include <stdio.h>
#include <stdlib.h>



int busqueda_binaria_abajo(int v[], int a, int b, int x) {
    if (a > b) {
        return b; 
    }
    int m = (a + b) / 2;
    
    if (v[m] == x) {
        return m; 
    } else if (v[m] < x) {
        return busqueda_binaria_abajo(v, m + 1, b, x); 
    } else {
        return busqueda_binaria_abajo(v, a, m - 1, x); 
    }
}
int busqueda_binaria_arriba(int v[], int a, int b, int x) {
    if (a > b) {
        return a; 
    }
    int m = (a + b) / 2;
    
    if (v[m] == x) {
        return m; 
    } else if (v[m] < x) {
        return busqueda_binaria_arriba(v, m + 1, b, x); 
    } else {
        return busqueda_binaria_arriba(v, a, m - 1, x);
    }
}


int valores_rango(int v[], int a , int b, int A , int B ){
    a = busqueda_binaria_arriba(v, a, b, A);
    b = busqueda_binaria_abajo(v, a, b, B);
    return (b-a +1);
    
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
    
    int A, B;
    printf("Ingrese el rango A y B: ");
    scanf("%d %d", &A, &B);

    int count = valores_rango(v, 0, n - 1, A, B);

    printf("Número de elementos en el rango [%d, %d]: %d\n", A, B, count);

    free(v);
    return 0;
}