#include <stdio.h>
#include "ivector/ivector.h"
#include <stdlib.h>


int vrotado(ivector v , int a , int b){
    if(a == b) return v[a];
    if(b - a == 1) return v[a] < v[b] ? v[a] : v[b];
    int m = (a + b) / 2;
    if(v[m] > v[b]){ //Si el medio es mayor que el final entonces el mínimo está a la derecha
        return vrotado(v, m+1, b);
    }else{ //Si el medio es menor que el final entonces el mínimo está a la izquierda
        return vrotado(v, a, m);
    }
}

int main(){
   ivector v = icreavector(7);
   for(int i = 0; i < 7; i++) v[i] = i + 1;

   v[3] = 0; // Rotamos el vector
    printf("El vector rotado es: ");
   for(int i = 0; i < 7; i++) printf("%d ", v[i]);
   printf("\n");
   printf("El valor mínimo es: %d\n", vrotado(v, 0, 6));
   ifreevector(&v);
   return 0;
}

