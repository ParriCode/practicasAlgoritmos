#include <stdio.h>
#include <stdlib.h>




int monedas[8] = {200,100,50,20,10,5,2,1};
const int num_monedas = 8;
/**
 * @brief 
 * @param c 
 * @param k 

 */
void cambio(int c, int k,int i, int * sol){
    if(c == 0 ){
        printf("Solución encontrada\n");
        for(int j = 0; j < i; ++j){
            printf("%d, ",sol[j]);
        }
        printf("\n");
        return;
    }else if(c > 1000 || k == num_monedas || c < 0 ){
        return;
    }
    else{

        if(c >= monedas[k]){
         //   printf("moneda usada = %d\n", monedas[k]);
            sol[i] = monedas[k];
            cambio(c -monedas[k], k,i+1,sol);
        }else{
            cambio(c, k +1 , i , sol);
        }
        
      
    }

}

int main(){
    int c = 933;
    int sol[100];
    cambio(c, 0, 0,sol);

    return 0;
}