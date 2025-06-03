/**Supón que deseas estimar el área de una figura que no tiene una forma sencilla
de ser calculada, pero puedes simular puntos aleatorios dentro de un cuadrado
que rodea la figura. Si un punto cae dentro de la figura, se cuenta como un
"éxito". Si cae fuera, se cuenta como un "fracaso".
Diseña e implementa un algoritmo Numérico que estime el área de la
figura. */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

// Función que determina si un punto (x, y) está dentro de un círculo de radio 5
int dentro_circulo(double x , double y){
    const int radio = 5;
    return sqrt(y*y + x*x ) <= radio;
}

/**
 * @brief Función que devuelve el área aproximada de la figura dada.
 * 
 * @param a Ancho del rectángulo que rodea la figura.
 * @param b Altura del rectángulo que rodea la figura.
 * @param dentro_figura Puntero a una función que determina si un punto (x, y) está dentro de la figura.
 * @return El área aproximada de la figura.
 */
double area_figura(int a, int b, int ( *dentro_figura)(double , double)){
    int puntos = 10000; // Número de puntos aleatorios a generar
    int dentro = 0;     // Contador de puntos dentro de la figura
    int fuera = 0;      // Contador de puntos fuera de la figura
    int x , y;
    srand(time(NULL));  // Inicializa la semilla para la generación de números aleatorios

    // Genera puntos aleatorios y verifica si están dentro de la figura
    for(int i = puntos; i >= 0; --i){
        x = a * (double)rand() / RAND_MAX;
        y = b * (double)rand() / RAND_MAX; 
        if(dentro_figura(x - a / 2, y - b / 2)){ //Hay que poner el rectuangulo en centro del cuadrado
            ++dentro; 
        } else {
            ++fuera;
        }
    }

    // Imprime el número de puntos dentro y fuera
    printf("dentro = %d, fuera = %d \n", dentro, fuera);

    // Calcula y retorna el área aproximada de la figura
    return a * b * (double)dentro / (double)puntos;
}

int main(int argc , char * argv[]){
    int x = 10; // Ancho del rectángulo
    int y = 10; // Altura del rectángulo

    double area = area_figura(10, 10, &dentro_circulo);

    printf("El area es %lf\n", area); // Tiene que dar un valor aproximado a 78.5

    return 0;
}