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
int longfija(int *a, int n , int m, int k ,int c, int *sol){
    if(  k == m ){
        if(c == 0 ){ 
            for(int i = 0; i < m ; ++i){
                printf("%d, ", sol[i]);
            }
            printf("\n");
        }
        return 0;
    }
    for(int i = n-1; i>=0 ;--i){
 
        if( a[i] <= c){
            sol[k] = a[i];
            longfija(a,i ,m,k+1 , c -  a[i],sol);   
        }
    }
    return 0;
    
}

void longvariable(int *a, int n , int k , int c, int h ,int *sol ){
    if( k == n || c == 0){
        if( c == 0 ){
            for(int i = 0; i< h ; ++i){
                printf("%d, ",sol[i]);
            }
            printf("\n");
        }
        return;

    }
    for(int i = k; i< n; ++i){
     
       
        if( c - a[i]  >= 0 ){
            sol[h] = a[i];
            longvariable(a,n, i+1,c - a[i] , h+1,sol);
        }
       
    }
}

#define num 9
#define mm 3
int main(int argc , char *argv[]){

    int a[num] = {3,4,6,7,1,10,8,9 , 2};
    int c = 10;
    int sol[mm];
    longfija(a, num,  mm ,0,  c, sol); 

    int sol2[num];
    //inicilizar sol a 0
    for(int i = 0; i< num; ++i){
        sol2[i] = 0;
    }
    printf("LONTIGUD VARIABLE\n");
    longvariable(a,num, 0, c , 0,sol2);



    return 0;
}