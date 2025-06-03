#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct{
    int x , y;
} punto;



double distancia(punto a, punto b){
    return sqrt((a.x -b.x) * (a.x- b.x) + (a.y -b.y) * (a.y-b.y));
}

double caso_base(punto p[], int a, int b){
    double min = distancia(p[a], p[b]);
    for(int i = a; i < b; ++i){
        for(int j = i + 1; j <= b; ++j){
            double d = distancia(p[i], p[j]);
            if(d < min){
                min = d;
            }
        }
    }
    return min;
}
int n0 = 4; // umbral
double distancia_cercana(punto p[], int a , int b){

    if(b -a < n0){
        return caso_base(p, a, b);
    }
    else{
        int m = (a+b)/ 2;
        double min1 = distancia_cercana(p, a, m);
        double min2 = distancia_cercana(p, m + 1, b);
        double min = (min1 < min2) ? min1 : min2;
    
        for(int i= a; i < m; ++i){ //matriz diagonal , así no se duplican las distancias calculadas
            for(int j = m; j < b; ++j){
                double d = distancia(p[i], p[j]);
                if(d < min){
                    min = d;
                }
            }
        }
        return min;
    }
}

int main() {
    int n;
    printf("Ingrese el número de puntos: ");
    scanf("%d", &n);
    
    punto *p = malloc(n * sizeof(punto));
    
    for(int i = 0; i < n; ++i) {
        printf("Ingrese las coordenadas del punto %d (x y): ", i + 1);
        scanf("%d %d", &p[i].x, &p[i].y);
    }
    
    double min_dist = distancia_cercana(p, 0, n - 1);
    
    printf("La distancia más corta entre dos puntos es: %.2f\n", min_dist);
    
    free(p);
    return 0;
}
