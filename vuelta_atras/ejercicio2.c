#include <stdio.h>
#include <stdlib.h>





/**
 * @brief 
 * 
 * 
 * @param a Conjunto de números
 * @param n Número de números
 * @param m Longitud fija del subconjunto cuya suma da C
 * @param c cantidad que debe sumar el subconjunto
 * @param sol  Vector solucion
 * @return Número de soluciones
 */
void longfija(int *A, int n , int m, int k ,int c, int *sol, int s){
    if(  s == m ){
        if(c == 0 ){ 
            for(int i = 0; i < m ; ++i){
                printf("%d, ", sol[i]);
            }
            printf("\n");
        }
        return;
    }
    if( k == n || c < 0){ //final del conjunto o suma superada
        return; 
    }else{
        sol[s] = A[k]; //Cogemos el número actual
        longfija(A, n, m, k + 1, c - A[k], sol, s + 1); //coger el actual
        longfija(A, n, m, k + 1, c, sol, s); //no coger el actual

    }
    return ;
    
}

void longvariable(int *a, int n , int k , int c ,int *sol, int s){
    if(c == 0){

        for(int i = 0; i< s ; ++i){
            printf("%d, ",sol[i]);
        }
        printf("\n");
     
        return;

    }else if(c < 0 || k == n || s == n){ //Si la suma es negativa o hemos llegado al final del conjunto
        return;

    }else{
        sol[s] = a[k]; //Cogemos el número actual
        longvariable(a, n, k + 1, c - a[k], sol, s + 1); //coger el actual
        longvariable(a, n, k + 1, c, sol, s); //no coger el actual
    }
    
}

#define num 9
#define mm 3
int main(int argc , char *argv[]){

    int a[num] = {3,4,6,7,1,10,8,9 , 2};
    int c = 10;
    int sol[mm];
    longfija(a, num,  mm ,0,  c, sol,0); 

    int sol2[num];
    //inicilizar sol a 0
    for(int i = 0; i< num; ++i){
        sol2[i] = 0;
    }
    printf("LONTIGUD VARIABLE\n");
    longvariable(a,num, 0, c ,sol2 ,0);



    return 0;
}