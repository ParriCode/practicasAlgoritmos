#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void subsecuencia(int v[], int N, int k, int s[] , int ns, int sol[], int *l){
    if(k == N ){
        if( ns > *l){
            *l = ns; //Actualizamos la longitud de la solución
            for(int i = 0; i < ns; ++i){
                sol[i] = s[i]; //Guardamos la solución
            }
        }
        return ;
    }
    //sigue creciendo el vector
    else if(ns == 0 || v[k] > s[ns - 1]){ //Si es el primer elemento o es mayor que el último
        s[ns] = v[k]; //Añadimos el elemento
        subsecuencia(v, N, k + 1, s, ns + 1, sol, l); //Seguimos con la siguiente posición
    }
    //Sino simplemente sigue adelante
    subsecuencia(v, N, k + 1, s, ns, sol, l); //Seguimos con la siguiente posición sin añadir el elemento

}
int main(){
    int v[] = {3, 1, 4, 5, 9, 2, 6, 5, INT_MIN};
    int N = sizeof(v) / sizeof(v[0]);
    int s[N];
    int sol[N];
    int l = 0; // Longitud de la solución
    subsecuencia(v, N, 0, s, 0, sol, &l);
    
    printf("Subsecuencia más larga: ");
    for(int i = 0; i < l; ++i){
        printf("%d ", sol[i]);
    }
    printf("\nLongitud: %d\n", l);

    return 0;
}