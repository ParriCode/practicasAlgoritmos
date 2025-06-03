#include <stdlib.h>
#include <stdio.h>

#include "imatriz2d/imatriz2d.h"
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int botellon(int v[], int n) {
    if ((n % 2) != 0) {
        printf("N debe ser par\n");
        return -1;
    }

    // Matriz de (n+2)x(n+2) para evitar desbordes en accesos i+2, j-2...
    imatriz2d mat = icreamatriz2d(n+2, n+2);
    for (int i = 0; i <= n+1; ++i)
        for (int j = 0; j <= n+1; ++j)
            mat[i][j] = 0;

    int sol[n+1];
    int cantidad = 0;
    int k = 0;
    mat[1][1] = v[1];
    mat[1][2] = v[j];
    // Caso base: subintervalos de longitud 1

    // DP bottom-up: longitudes de 2 hasta n
    
    for (int i = 2; i <= n; ++i){
        for (int j = i+1; j <= n; ++j){
            //si listillo coge el primero
            int siguiente1 = v[i+1];
            int siguiente2 = v[j-1];
            //listillo coge el vaso i
            //Hay que ver que coge angonioso
            if(v[i+1] >= v[j]){
                siguiente1 = v[i] + mat[i-2][j];
            }else{
                siguiente1 = v[i] + mat[i-1][j+1];
            }


            if(v[i] >= v[j-1]){
                siguiente2 = v[j]+ mat[i-1][j+1];
            }else{
                siguiente2 = v[j] + mat[i][j+2];
            }
            
            mat[i][j] = MAX(siguiente1, siguiente2) ;  
            
        }
    }

    // Mostrar dimensiones y matriz completa
    printf("Dimensiones reales: %d x %d\n", n+1, n+1);
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            printf("%3d,", mat[i][j]);
        }
        printf("\n");
    }

    // Resultado final
    int resultado = mat[1][n];
    printf("Listillo, comenzando, bebe máximo %d unidades.\n", resultado);

    ifreematriz2d(&mat);
    return resultado;
}

int main(int argc, char *argv[]) {
    int v[4] = {1, 8, 3, 2};
    botellon(v, 4);
    return 0;
}
