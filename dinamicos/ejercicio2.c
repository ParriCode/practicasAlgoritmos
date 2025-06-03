#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ivector/ivector.h"
#include "imatriz2d/imatriz2d.h"

/**
 * @brief Funcion 
 * 
 * 
 * @param n 
 * @param m 
 * @return 
 */
int funcion(int n , int m){
    //imatriz2d mat = icreamatriz2d(n +1, m +1);
    ivector v = icreavector(m+1);
    if(m == 0) return 0;
    if(m == 1) return n;
    for(int j = 0; j <= m; ++j){
        v[j] = 0;
    }
    v[0] = 0;
    v[1] = n;
    for(int i = 2; i <= m; ++i){
        v[i] = v[(int)ceil((float)i/2)]+ v[(int)floor((float)i/2)];
    }
    int sol = v[m];
    ifreevector(&v);
    return sol;
}
int main(){
    int m = 5;
    int n = 10;
    printf("Resultado es: %d\n", funcion(n, m));


    return 0;
}