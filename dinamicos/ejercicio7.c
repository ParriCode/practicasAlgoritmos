#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "imatriz2d/imatriz2d.h"

int MIN(int a, int b){ return (a < b ? a : b);}
int MAX(int a, int b){ return (a > b ? a : b);}

int camino_mas_ancho(imatriz2d m, int n) {
   // imatriz2d m = icreamatriz2d(n , n );
    imatriz2d p = icreamatriz2d(n , n );

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
         //   m[i][j] = g[i][j];
            if(i == j){
                p[i][j] = INT_MAX;
            }else{
                p[i][j] = -1;
            }
               
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <n; ++j) {
                if (i != j && m[i][k] > 0 && m[k][j] > 0) {
                    int paso = MIN(m[i][k], m[k][j]);
                    if (paso > m[i][j]) {
                        m[i][j] = paso;
                        p[i][j] = k; // o simplemente k

                    }

                }
            }
        }
    }

    printf("solución\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(m[i][j] == INT_MAX){
                printf(" - ");
            }else{
                printf("%2d,", m[i][j]);

            }
        }
        printf("\n");
    }

   return 0;
}
   



int main(int argc, char *argv[]) {
    int n = 5;
    imatriz2d m = icreamatriz2d(n,n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            m[i][j] = (i == j) ? -1 : -1;
        }
    }

    m[0][1] = 3; m[1][0] = 3; 
    m[0][3] = 7; m[3][0] = 7; 
    m[1][2] = 2; m[2][1] = 2; 
    m[2][3] = 1; m[3][2] = 1; 
  //  m[3][4] = 5; m[4][3] = 5; 

    camino_mas_ancho(m, n);
    printf("El camino más ancho entre %d  - %d tiene anchura: %d\n", 1, 4 , m[1][4]);

    ifreematriz2d(&m);
    return 0;
}