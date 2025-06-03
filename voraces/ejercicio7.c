#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int p , l;
} coche;
typedef struct{
    int p , l;
} trailer;

int comparar_menor(const void *a, const void *b) {
    return ((coche *)b)->p + ((coche *)b)->l - ((coche *)a)->p - ((coche *)a)->l;
}
int comparar_mayor(const void *a, const void *b) {
    return ((coche *)a)->p + ((coche *)a)->l - ((coche *)b)->p - ((coche *)b)->l;
}


int meter(coche c, trailer * t){
    if(c.p <= t->p && c.l <= t->l){
        t->p -= c.p;
        t->l -= c.l;
        return 1; // Se ha podido meter
    }
    return 0; // No se ha podido meter
}

void colocar(coche c[], trailer t[], int nc , int nt){
    qsort(c, nc , sizeof(coche), comparar_menor);
    qsort(t, nt , sizeof(trailer), comparar_mayor);
    int i = 0;
    int  j = 0;
    while(i < nc && j < nt){
        if(meter(c[i], &t[j])){
            i++;
             printf("El coche %d se ha colocado en el trailer %d\n", i, j);
        }else{
            j++;
            printf("Trailer %d tiene %d de peso y %d de longitud restantes\n", j, t[j].p, t[j].l);

        }
       
    }

}

int main() 
{
    /* ----- datos de prueba ----- */
    coche c[] = {
        {  7, 4 },   /* coche 0 */
        { 12, 5 },  /* coche 1 */
        {  8, 4 },  /* coche 2 */
        { 15, 5 },  /* coche 3 */
        {  9, 4 }   /* coche 4 */
    };
    trailer t[] = {
        { 20, 10 },  /* tráiler 0 */
        { 18, 15 },  /* tráiler 1 */
        { 25, 7 }   /* tráiler 2 */
    };

    int nc = sizeof c / sizeof c[0];
    int nt = sizeof t / sizeof t[0];

    colocar(c, t, nc, nt);

    return 0;


}