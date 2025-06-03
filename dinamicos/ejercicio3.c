#include <stdio.h>
#include <stdlib.h>

#include "ivector/ivector.h"
#include "imatriz2d/imatriz2d.h"

/**
 * @brief Calcula el equivalente a Q[m, n] 
 * 
 * @param n 
 * @param m 
 * @param v rector con valores v[1..m]
 * @return resultado
 */
int funcion(int m, int n, ivector v) {
    int sol;
    int sum;
    imatriz2d mat = icreamatriz2d(m + 1, n + 1);

    //Todo inicializado a 0
    for (int i = 0; i <= m; ++i)
        for (int j = 0; j <= n; ++j)
            mat[i][j] = 0;
    //Casos base
    for (int j = 0; j <= n; ++j)
        mat[0][j] = 1;
    for (int i = 0; i <= m; ++i)
        mat[i][0] = 1;

    // Llenado de la matriz según la recurrencia
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j < v[i]) {
                mat[i][j] = mat[i-1][j];
            } else {
                sum = 0;
                for (int k = 1; k < v[i]; ++k) {
                    sum += mat[i][j-k];
                }
                mat[i][j] = sum;
            }
        }
    }

    printf("matreiz:\n");
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }

    sol = mat[m][n];
    ifreematriz2d(&mat);
    return sol;
}

int main() {
    int n, m;

    printf("Ingrese n : ");
    scanf("%d", &n);

    printf("Ingrese m : ");
    scanf("%d", &m);

    ivector v = icreavector(m + 1); // Usaremos v[1]..v[m]

    printf("Introduce los %d elementos del vector v\n", m);
    v[0] = 0; //el primer vçertice no se utiliza

    for (int i = 1; i <= m; ++i) {
        printf("v[%d] = ", i);
        scanf("%d", &v[i]);
    }

    int resultado = funcion(m, n, v);
    printf("\nresultado: %d\n", resultado);

    ifreevector(&v);
    return 0;
}
