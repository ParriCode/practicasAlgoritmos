#include <stdio.h>
#include <stdlib.h>




//longitud no mayor que 5 con 2 vocales 


/**
 * @brief 
 * 
 * 
 * @param simbolos 
 * @param n 
 * @param palabra 
 * @param k 
 */
void palabras(char * simbolos , int n , char palabra[6], int k, int nvocales) {
    if(nvocales > 2){
        return; // poda si las vocales son mayores que 2
    }
    else if(k ==5  ){
        if(nvocales != 2){return;}
        else{
            printf("palabra: %s\n", palabra);
            return; //ya se hace solo pero lo pongo para que quede más claro
        }
       

        //solucion
    }else{
        for(int i = 0; i< n; ++i){
            palabra[k] = simbolos[i];
            if(simbolos[i] == 'A' || simbolos[i] == 'E' ||  simbolos[i] == 'I' ||  simbolos[i] == 'O' || simbolos[i] == 'U'){
                //hay una nueva vocal
                palabras(simbolos, n , palabra, k+1, nvocales +1);

            }
            else{
                palabras(simbolos, n , palabra, k+1, nvocales );

            }
            palabra[k] = 0;
        }
 
    }


}


int main(){
    char simbolos[8] = {'1', '2','3','A','E','I','O','U'};
    int n = 8;
    char palabra[6] = {0,0,0,0,0,'\0'};  //Terminador de string para todos los casos
    palabras(simbolos, n , palabra, 0,0);
    return 0;
}