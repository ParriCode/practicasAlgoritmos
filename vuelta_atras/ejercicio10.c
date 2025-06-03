#include <stdlib.h>
#include <stdio.h>




typedef enum{
    O = 0,
    C =1 ,
    E = 2,
    B = 3
} palo ;

typedef struct {
    int num;
    palo p;
    int usada;
} carta;

#define N_CARTAS 4
#define N_PALOS 2
int nsol = 0;
void combinacion(carta * cartas , int n , int k , int suma, carta * sol ,int d, int palo ){
    
    if(suma< 0 || d == 3) return;
    if( k == -1){
        if(suma == 0){

            printf("SOL %d \n carta: ",nsol);
            for(int i = 0; i< N_CARTAS; ++i){
                printf("[%2d %d] ",sol[i].num, sol[i].p);
            }
            ++nsol;
        }
    }else{
        for(int i= k; i < n ; ++i){
            if(!cartas[i].usada){
                cartas[i].usada = 1;
                sol[k] = cartas[i];
                if(cartas[i].p != palo){
                    combinacion(cartas,n,i+1,suma- cartas[i].num,sol, d +1, cartas[i].p);

                }else{
                    combinacion(cartas,n,i+1,suma- cartas[i].num,sol, d, cartas[i].p);

                }                
                cartas[i].usada = 0;
                
            }
        }
    }
}

int main(){
    carta cartas[40];
    int k = 0;
    for(int j = 0; j < 4; ++j){
        for(int i = 1; i <= 12;++i){
            if(i == 8) i = 10;
            
            
            cartas[k].num = i;
            cartas[k].p = j;
            cartas[k].usada = 0;
            ++k;
        }
    }

    for(int i = 0; i< 40; ++i){
        printf("carta: %2d %d\n",cartas[i].num, cartas[i].p);
    }
    carta sol[4];
    combinacion(cartas,0,3,31,sol,0,-1);
    printf("k = %d \n",k);
}