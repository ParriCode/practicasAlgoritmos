#include "moreset.h"

#include <stdio.h>
/**
 * @brief Encontrar el elemento mayoritario de un conjunto 
 * @details El elemento mayoritario es el elemento que aparaece un número de veces estrictamente mayor que n/2 
 * @param arr vector del vector
 * @param a posicion inicial
 * @param b posicion final +1
 * @return elemento mayoritario del vector, -1 sino existe
 */
int moreset(unsigned int *arr, int a , int b){
    if(b-a == 1){
    //    printf("%d arr: %u\n",c, arr[a]);
     //   ++c;
        return arr[a];
    }
    if(b-a < 1){return -1;}
    int m = (a+b) / 2;
    int ele1 = moreset(arr, a, m);
    int ele2 = moreset(arr,m, b );
    int contador1 = 0;
    int contador2 = 0;
    //Si son el mismo elemento entonces simplemente se devuelve sin comprobar
    if(ele1 == ele2) {return ele1;}
    for(int i = a; i < b;++i){ //Sino son el mismo elemento se cuentan ambos elementos y se ve cual es el mayor
        if(arr[i] == ele1){
            ++contador1;
        }else if( arr [i] == ele2){
            ++contador2;
        }
    }
    //Se verifica que son mayoritarios 
    if(contador1 > (b-a)/ 2){
        return ele1;
    }
    else if(contador2 > (b-a)/2){
        return ele2;
        
    }
    return -1; //-1 sino  existe elemento mayoritario

}
