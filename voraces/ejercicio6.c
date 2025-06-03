#include <stdio.h>
#include <stdlib.h>

int cmp(const void * a, const void* b){
    return (*(int *)b) - (*(int *)a);

}

/**
 * @brief Rellenar las baldas con los libros de forma que la media de peso por balda sea lo más homogénea posible
 * @param l libros
 * @param n número de libros
 * @param B baldas
 * @param m número de baldas
 */
int rellenar_baldas(int l[], int n , int B[] , int m){
    double media = 1;
    qsort(l , n , sizeof(int), &cmp);
    printf("Libros ordenados de mayor a menor:\n");
    for(int i = 0; i < n; ++i){
        printf("%d ", l[i]);
    }
    printf("\n");
    int i = 0; int j = 0;
    while(i < n){ //Colocar todos los libros
        if(B[j] <= media){
            B[j] += l[i];
            media += l[i]/m; //añadir el nuevo peso a la media
            ++i;

        }
        else{
            ++j;
            if(j == m){
                j = 0; //Volver a la primera balda
            }

        }
    }
}

int main(){
    int n, m;
    printf("Introduce el número de libros: ");
    scanf("%d", &n);
    int l[n];
    printf("Introduce los pesos de los libros:\n");
    for(int i = 0; i < n; ++i){
        scanf("%d", &l[i]);
    }
    printf("Introduce el número de baldas: ");
    scanf("%d", &m);
    int B[m];
    for(int i = 0; i < m; ++i){
        B[i] = 0;
    }
    rellenar_baldas(l, n, B, m);
    printf("Baldas:\n");
    for(int i = 0; i < m; ++i){
        printf("%d ", B[i]);
    }
    printf("\n");
    return 0;
}