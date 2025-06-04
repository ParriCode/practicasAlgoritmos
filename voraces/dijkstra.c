#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "disjoint/disjoint.h"
#include "imatriz2d/imatriz2d.h"

/* imprime el camino origen→v usando el vector pred[] */
static void imprimir_camino(int v, int pred[])
{
    if (pred[v] != -1) imprimir_camino(pred[v], pred);
    printf("%d ", v);
}

/* ------------------------------------------------------------ */
void dijkstra(imatriz2d g, int n, int origen,int D[], int P[])
{
    int visit[n];
    for (int i = 0; i < n; ++i) {
        D[i] = INT_MAX;
        P[i] = -1;
        visit[i] = 0;        
    }
    D[origen] = 0;

    for (int k = 0; k < n - 1; ++k) {
        int u = -1, min = INT_MAX;
        for (int i = 0; i < n; ++i)
            if (!visit[i] && D[i] < min) {
                min = D[i];
                u = i;
            }
        if (u == -1) break;                     // resto inaccesible

        visit[u] = 1;

        for (int v = 0; v < n; ++v)             // relajar aristas
            if (!visit[v] && g[u][v] != INT_MAX &&
                D[u] + g[u][v] < D[v]) {
                D[v] = D[u] + g[u][v];
                P[v] = u;
            }
    }



    /* ---------- salida bonita ---------- */
    printf("distancias mínimas desde %d\n", origen);
    for (int v = 0; v < n; ++v)
        if (D[v] == INT_MAX)
            printf("nodo %d: -1\n", v);
        else
            printf("nodo %d: %d\n", v, D[v]);

    printf("caminos\n");
    for (int v = 0; v < n; ++v) {
        printf("%d ← ", v);
        imprimir_camino(v, P);
        printf("(costo %d)\n", D[v]);
    }
}
/* ------------------------------------------------------------ */
int main(void)
{
    int n = 5;
    imatriz2d g = icreamatriz2d(n, n);

    /* ejemplo reproducible */
    int ejemplo[5][5] = {
        {0,  3,  5, INT_MAX,  1},
        {3,  0,  2,  6,      INT_MAX},
        {5,  2,  0,  2,      3},
        {INT_MAX, 6, 2, 0,   2},
        {1, INT_MAX, 3, 2,   0}
    };
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            g[i][j] = ejemplo[i][j];

    int dist[n], P[n];
    dijkstra(g, n, 0, dist, P);

    ifreematriz2d(&g);
    return 0;
}
