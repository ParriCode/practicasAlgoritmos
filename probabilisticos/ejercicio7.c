/**
 * @file ejercicio7.c
 * @author Jose Luis Parrilla Fuentes
 * @brief Un heap o montículo es un árbol binario en el que cada nodo es mayor que sus
 *          hijos, si existen. Diseña un algoritmo probabilístico que, dado un árbol binario
 *          implementado en un vector, determine si es o no un heap eligiendo al azar un
 *          elemento entre 0 y n/2 y compruebe si está ordenado parcialmente. ¿Qué tipo de
 *          algoritmo probabilístico sería y qué garantías de precisión ofrece?
 * @version 0.1
 * @date 2025-04-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#include <stdlib.h>
#include <stdio.h> 
#include <time.h>




/**
 * @brief Dado un vector determinar si es heap o no , utilizando el método de montecarlo
 * La función puede dar falsos positivos  , sin embargo los negativos son certeros
 * La probabilidad de que diga la verdad 
 * @details La probabilidad de encontrarse con un nodo intruso , siendo R el número de intrusos es R / (n/2) 
 * Es decir , la probabilidad de no encontrarlos es 1- 2R/n, por tanto si hacemos k pruebas nos queda
 * (1- 2R/n)^k  , disminuyendo la probabilidad de encontrar un falso positivo
 * 
 * @param heap monticulo a evaluar
 * @param tam tamaño del montículo
 * @param precision número de veces que se va a evaluar un indice aleatorio
 * @return true si es montículo (puede fallar) , false sino lo es (no falla)
 */
int es_heap(int * heap, int tam, int precision){
    int  n = (tam/2) -1; //Empieza en 0 , sino podemos sobrepasar el indice
    printf("n =%d\n",n);
    for(int i = 0; i < precision; ++i){
        int indice = rand() % n;
        printf("n =%d\n",indice);
        
        int hijo_izq = 2*indice +1;
        int hijo_der = 2*indice +2;
        //Hayu que verificar que es padre de sus hijos
        if(!(heap[indice] > heap[hijo_der] && heap[indice] > heap[hijo_izq])){
            return 0;
        }
    }
    return 1;
    


}

int main(int argc, char *argv[]){

    srand(time(NULL));
    int heap[10] = {20,19,18,17,16,15,14,23,12,11};
    if(es_heap(heap,10,4)){
        printf("Es heap\n");
    }else{
        printf("No es heap\n");
    }

    return 0;
}