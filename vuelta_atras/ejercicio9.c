#include <stdio.h>
#include <stdlib.h>



typedef struct{
    int a;
    int b;
    int orden;

    

} ficha;

void tresmino(ficha * fichas,int n , int k , int *orden , int a, int b){
    if(3 == k){
        //Imprimir solucion
        printf("SOL\n");
        printf("FICHAS: %d\n",k);
        for (int i = 0; i < n; ++i) {
            printf("Ficha %d: [%d | %d], orden=%d\n", 
                   i, fichas[i].a, fichas[i].b, fichas[i].orden);
        }
        printf("orden: ");
        for(int i = 0; i < k; ++i){
            printf("%d, ",orden[i]);
        }
        return;
   
    }else{
        for(int i = 0; i< n ; ++i){
            if(fichas[i].orden == -1 ){
                orden[k] = i;
                fichas[i].orden= k;
                if(fichas[i].a == a){
                    tresmino(fichas, n , k+1,orden , fichas[i].b, b);
                }
                if(fichas[i].a == b){
                    tresmino(fichas, n , k+1,orden , a , fichas[i].b);
                }
                if(fichas[i].b == a){
                    tresmino(fichas, n , k+1,orden ,  fichas[i].a , b);
                }
                if(fichas[i].b == b){
                    tresmino(fichas, n , k+1,orden ,  a , fichas[i].a);
                }
                orden[k] = 0;
                fichas[i].orden= -1;
            }
        }
    }
}

/*
void tresmino(ficha * fichas ,int n, int k, int * orden){
    if(n  == k){
        printf("SOL\n");
        printf("FICHAS: %d\n",k);
        for (int i = 0; i < n; ++i) {
            printf("Ficha %d: [%d | %d], orden=%d, a1=%d, b1=%d\n", 
                   i, fichas[i].a, fichas[i].b, fichas[i].orden, fichas[i].a1, fichas[i].b1);
        }
        printf("orden: ");
        for(int i = 0; i < k; ++i){
            printf("%d, ",orden[i]);
        }
        return;
        
    }else if(k > 1 && (!fichas[orden[k-1]].a1 &&  !fichas[orden[k-1]].b1)){return;
    }else{
        for(int i = 0; i < n; ++i){
            if(fichas[i].orden == -1){

                fichas[i].orden = k;
                orden[k] = i;

                if(      fichas[i].a == fichas[orden[k-1]].a && !fichas[i].a1 && !fichas[orden[k-1]].a1){
                    fichas[i].a1 = 1; //ficha uisada
                    fichas[orden[k-1]].a1 = 1;
                    tresmino(fichas, n , k+1,orden);
                    fichas[i].a1 = 0; //ficha uisada
                    fichas[orden[k-1]].a1 = 0;

                }else if(fichas[i].a == fichas[orden[k-1]].b && !fichas[i].a1 && !fichas[orden[k-1]].b1){
                    fichas[i].a1 = 1; //ficha uisada
                    fichas[orden[k-1]].b1 = 1;
                    tresmino(fichas, n , k+1,orden);
                    fichas[i].a1 = 0; //ficha uisada
                    fichas[orden[k-1]].b1 = 0;


                }else if(fichas[i].b == fichas[orden[k-1]].a && !fichas[i].b1 && !fichas[orden[k-1]].a1){
                    fichas[i].b1 = 1; //ficha uisada
                    fichas[orden[k-1]].a1 = 1;
                    tresmino(fichas, n , k+1,orden);
                    fichas[i].b1 = 0; //ficha uisada
                    fichas[orden[k-1]].a1 = 0;


                }else if(fichas[i].b == fichas[orden[k-1]].b && !fichas[i].b1 && !fichas[orden[k-1]].b1){
                    fichas[i].b1 = 1; //ficha uisada
                    fichas[orden[k-1]].b1 = 1;
                    tresmino(fichas, n , k+1,orden);
                    fichas[i].b1 = 0; //ficha uisada
                    fichas[orden[k-1]].b1 = 0;

                }
                
                fichas[i].orden = -1; // reiniciar
                orden[k] = 0;



            }
        }
    }
}*/

int main(){
    
    ficha fichas[10] = {
        {0,0,-1},
        {0,1,-1},
        {0,2,-1},
        {0,3,-1},
        {1,1,-1},
        {1,2,-1},
        {1,3,-1},
        {2,2,-1},
        {2,3,-1},
        {3,3,-1},
    };
    ficha sol[10];
    fichas[9].orden = 0; 
    int orden[10] = {0};
    orden[0] = 9;
    tresmino(fichas, 10,1,orden,3,3);

    return 0;
}













