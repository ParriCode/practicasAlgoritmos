#include <stdio.h>
#include <stdlib.h>


void combinaciones(char * v, int n,int voc, int k, char * sol){

    if(n == 0 || k == 5){
        if(voc == 2){ //Solucion debe tener exactamente 2 vocales
            for(int i = 0; i< 5 ; ++i){
                printf("%c, ", sol[i]);
            }
            printf("\n");
        }
     
        return;
    }
    for(int i= n-1 ; i >= 0; --i){
        if( v[i] == 'A' || v[i] == 'E' || v[i] == 'I'  ||  v[i] == 'O' || v[i] == 'U'){
            if(voc < 2){
                sol[k] = v[i];

                combinaciones(v , n-1, voc +1 , k +1,sol);
            }
        }else{
            sol[k] = v[i];
            combinaciones(v , n-1, voc  , k +1,sol);
        }
        
    }


}

int main(){

    int n = 8;
    char v[8] = {'1','2','3','A','E','I','O','U'};
    char sol[5];
    combinaciones(v,n,0,0,sol);
    return 0;
}