/**
 * @file ejercicio6.c
 * @author Jose Luis Parrilla Fuentes
 * @brief Supón que tienes un conjunto de números muy grande, pero no puedes acceder
 *          a todos ellos porque son demasiados. Sin embargo, puedes obtener muestras
 *          aleatorias de los números. Implementa un algoritmo que estime la media del
 *          conjunto de números utilizando únicamente el muestreo aleatorio.
 *          ¿Qué tipo de algoritmo probabilístico sería y qué garantías de precisión
 *          ofrece?
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
 * @brief Uso de un algortimo numérico para calcular la media estimada de un conjunto, 
 * Las garantias de precisión depende mucho de la cantidad de puntos totales del conjunto,
 * de la precisión dada en el algoritmo (cantidad de puntos evaluados del conjunto), y también 
 * de la desviación típica de este , que no haya puntos extremadamente bajos o grandes.
 * 
 * @param conjunto conjutno de numeros
 * @param tam tamaño del conjunto
 * @return media estimada
 */
double media_estimada_conjunto(int * conjunto, int tam){
    float precision = 0.1; // porcentaje de precision 
    int puntos = tam *  precision; //calcular cantidad de puntos respecto del tamaño del conjunto
    int suma = 0;
    for(int i = 0; i< puntos; ++i){
        suma += conjunto[rand() % tam];
    }
    return(suma / (double)puntos);
}


int main(int argc, char * argv[]){
    srand(time(NULL));
    int conjunto[10000];
    for(int i = 0; i< 10000; ++i){
        conjunto[i] = i;
    }
    double media = media_estimada_conjunto(conjunto, sizeof(conjunto) / sizeof(int));
    printf("La media es %lf\n", media);


    return 0;
}