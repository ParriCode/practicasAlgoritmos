#include <stdlib.h>
#include <stdio.h>
#include "ivector/ivector.h"
#include "imatriz2d/imatriz2d.h"
#include <math.h>
#include <limits.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))
/**
 * @brief 
 * 
 * 
 * @param m vector con los tipos de moneda
 * @param n numero de tipos de moneda
 * @param c suma de dinero que tienen que tener las monedas
 * 
 */
void cambio(ivector m, int n , int c){
    imatriz2d matrix;
    matrix = icreamatriz2d(n+1 ,c +1 );
    for(int i = 0; i<= n ; ++i){
        for(int j = 0; j <= c; ++j){
            matrix[i][j] = INT_MAX;
        }
    }
    //Inicializar a 0
    for(int i = 0; i<= n; ++i){
        matrix[i][0] = 0;
    }
        
    for(int j = 1; j <= c ; ++j){
        for(int i = 1; i <= n; ++i){
        
            if(m[i] > j){
                matrix[i][j] =  matrix[i-1][j];
            } else{
                matrix[i][j] =  MIN(matrix[i-1][j], matrix[i][ j - m[i]] +1);   
            }
        }
    }
    for(int i = 1; i<= n ; ++i){
        for(int j = 0; j <= c; ++j){
            if(matrix[i][j] == INT_MAX){
                printf("if,");
            }else{
                printf("%2d,", matrix[i][j] ) ;

            }
        }
        printf("\n");
    }

    int k = matrix[n][c]; //Este ees el numero de monedas que se van a necesitar
    int i = n; //Número de monedas que tenemos
    printf("Solucion: ");
    while(i >0 ){
        //Si el número de abajo coincide quiere decir que no estamos cogiendo una moneda del valor actual es decir m[i]
        if(matrix[i][c] == matrix[i-1][c] ){
            --i;
        }else{
            c = c - m[i];//Cogemos la moneda y restamos la cantidad
            printf("%d,", m[i]);//imprimimos las monedas que estamos usando
        }
    }
    printf("\n");
    ifreematriz2d(&matrix);

    
}


/**
 * @brief Problema del cambio de monedas
 * 
 * 
 * @param argc 
 * @param argv 
 * @return 
 */
int main(int argc , char * argv[]){
    ivector m = icreavector(3);
    m[0] = 0;
    m[1] = 1;
    m[2] = 2;
    m[3] = 5;
    m[4] = 7;
    int c = 45;
    cambio(m, 4 , c);
    return 0;
}