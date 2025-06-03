#include <stdio.h>
#include <stdlib.h>
#include "fvector/fvector.h"

/**
 * @brief 
 * @details La solucion evidente es n = 0
 * 
 *
 * @param n 
 * @return 
 */
float funcion(int n){
    fvector v = fcreavector(n+1);
    float sum = 0;
    v[0] = 0;

    for(int i = 1 ; i<= n; ++i){
        v[i] = i+(2/(float)i)*sum;
        sum += v[i];
    }
    ffreevector(&v);
    return v[n];
}


int main(int argc , char * argv[]){
    int n = 0;
    printf("Introduce el valor n: ");
    scanf("%d",&n);
    printf("\n El valor del resultado es: %f\n", funcion(n));

    return 0;
}