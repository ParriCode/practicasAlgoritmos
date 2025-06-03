/**Dado un conjunto de puntos P en un plano, se desea encontrar el par de puntos
(pi, pj) cuya distancia euclídea entre ellos sea mínima. Para solucionar este
problema se diseña el siguiente algoritmo probabilístico:
1. Elegir (pimin, pjmin) aleatoriamente y establecer su distancia como la
distancia mínima inicial dmin
2. Repetir:
a. Elegir (pi, pj) aleatoriamente y actualizar dmin, pimin y pjmin si
su distancia es menor
Hasta que estemos razonablemente seguros de que hemos
encontrado el par con la distancia mínima. Podemos usar
criterios como un número fijo de iteraciones o basarnos en la
probabilidad de mejora para decidir cuándo detenernos.


¿Qué tipo de algoritmo probabilístico sería? Razona sobre la validez de dicho algoritmo */



// Sería un algoritmo de montecarlo ya que
/**
 * 1. Encuentra solución exácta
 * 2. No garantiza que la solución sea correcta
 * 3. La eficiencia es inversamente proporcional a su precisión  (Cuantas menos iteraciones , menos precisión)
 * 4. Con cada llamada se aumenta la probabilidad de tener la solución
 */

#include <stdio.h>

int main(){
    printf("*Dado un conjunto de puntos P en un plano, se desea encontrar el par de puntos\n"
           "(pi, pj) cuya distancia euclídea entre ellos sea mínima. Para solucionar este\n"
           "problema se diseña el siguiente algoritmo probabilístico:\n"
           "1. Elegir (pimin, pjmin) aleatoriamente y establecer su distancia como la\n"
           "distancia mínima inicial dmin\n"
           "2. Repetir:\n"
           "a. Elegir (pi, pj) aleatoriamente y actualizar dmin, pimin y pjmin si\n"
           "su distancia es menor\n"
           "Hasta que estemos razonablemente seguros de que hemos\n"
           "encontrado el par con la distancia mínima. Podemos usar\n"
           "criterios como un número fijo de iteraciones o basarnos en la\n"
           "probabilidad de mejora para decidir cuándo detenernos.\n"
           "\n"
           "\n"
           "¿Qué tipo de algoritmo probabilístico sería? Razona sobre la validez de dicho algoritmo */\n"
           "\n"
           "\n"
           "// Sería un algoritmo de montecarlo ya que\n"
           "/**\n"
           " * 1. Encuentra solución exácta\n"
           " * 2. No garantiza que la solución sea correcta\n"
           " * 3. La eficiencia es inversamente proporcional a su precisión  (Cuantas menos iteraciones , menos precisión)\n"
           " * 4. Con cada llamada se aumenta la probabilidad de tener la solución\n"
           " \n");
    return 0;
}