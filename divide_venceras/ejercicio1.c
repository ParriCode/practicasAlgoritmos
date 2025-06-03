#include <stdio.h>

int n0_mergesort = 64;

/* ---------- inserción ---------- */
void insercion(int v[], int n){
    for (int i = 1; i < n; ++i){
        int aux = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > aux){
            v[j + 1] = v[j];
            --j;
        }
        v[j + 1] = aux;
    }
}

/* ---------- merge ---------- */
void merge(int v[], int a, int m, int b){
    int n1 = m - a + 1;
    int n2 = b - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; ++i) L[i] = v[a + i];
    for (int j = 0; j < n2; ++j) R[j] = v[m + 1 + j];

    int i = 0, j = 0, k = a;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]) v[k++] = L[i++];
        else               v[k++] = R[j++];
    }
    while (i < n1) v[k++] = L[i++];
    while (j < n2) v[k++] = R[j++];
}

/* ---------- mergesort ---------- */
void mergesort(int v[], int a, int b){
    if (a >= b) return;

    if ((b - a + 1) < n0_mergesort){
        insercion(v + a, b - a + 1);
    } else {
        int m = a + (b - a) / 2;
        mergesort(v, a, m);
        mergesort(v, m + 1, b);
        merge(v, a, m, b);
    }
}

/* ---------- main (prueba) ---------- */
int main(void){
    int v[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof v / sizeof v[0];

    mergesort(v, 0, n - 1);

    printf("Vector ordenado: ");
    for (int i = 0; i < n; ++i) printf("%d ", v[i]);
    putchar('\n');
}
