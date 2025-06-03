/**
 * @file ejercicio4.h
 * @author Jose Luis Parrilla Fuentes (theparri@protonmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-25
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef EJERCICIO4_H
#define EJERCICIO4_H

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int id;
    int duracion;
} bombilla;

int merguesort(bombilla *bombillas, int a, int b) {
    if (a >= b) {
        // Caso base: un solo elemento
        return bombillas[a].duracion;
    } else {
        int s = 0;
        int m = (a + b) / 2;

        // Dividir y conquistar
        s += merguesort(bombillas, a, m);
        s += merguesort(bombillas, m + 1, b);

        // Mezclar los dos subarreglos
        bombilla aux[b - a + 1];
        int i = a, j = m + 1, k = 0;

        while (i <= m && j <= b) {
            if (bombillas[i].duracion >= bombillas[j].duracion) {
                aux[k++] = bombillas[i++];
            } else {
                aux[k++] = bombillas[j++];
            }
        }

        while (i <= m) {
            aux[k++] = bombillas[i++];
        }

        while (j <= b) {
            aux[k++] = bombillas[j++];
        }

        // Copiar el arreglo auxiliar de vuelta al original
        for (int i = a; i <= b; i++) {
            bombillas[i] = aux[i - a];
        }

        return s; // Devolver la suma de las duraciones
    }
}

/**
 * @brief Esta función devuelve el orden óptimo para iluminar una habitación con bombillas.
 * 
 * @param bombillas Bombillas disponibles.
 * @param n Número de bombillas.
 * @param m Bombillas necesarias para iluminar la habitación.
 * @return El orden de las bombillas.
 */
int *iluminacion_continua(bombilla *bombillas, int n, int m) {
    int suma = merguesort(bombillas, 0, n - 1);
    printf("Suma total de duraciones: %d\n", suma);
    int maxt = suma/m;
    printf("Duración máxima teorica: %d\n", maxt);


    // Imprimir bombillas ordenadas
    printf("\nBombillas ordenadas:\n");
    for (int i = 0; i < n; i++) {
        printf("Bombilla %d: %d\n", bombillas[i].id, bombillas[i].duracion);
    }

    int i= 0;
    int j = 0; //iterbombillas
    int * orden = (int * )malloc(sizeof(int) * n);
    //inicializar utilizadas
    int utilizadas[n];
    for(int i = 0; i < n; i++){
        utilizadas[i] = 0;
        orden[i] = -1;
    }
    int nbreak = 0;
    int  nUtilizadas = 0;
    int vistas = 0;
    int s = 0;
    int b = 1;
    for( b = 1; b < m; b++){
        s = 0;
        j = -1;
        vistas = 0;
        //Si la primera ya supera el maximo
        if(bombillas[j+1].duracion > maxt){
            ++j;
            orden[i] = bombillas[j].id;
            utilizadas[j] = 1; 
            ++nUtilizadas;
            ++vistas;
            break;
        }
        
        while(j < n && i < n ){
            ++j;
            if(!utilizadas[j]){
                //primer y mejor caso , que las bombillas sean iguales a la duracion maxima
                if(s +bombillas[j].duracion == maxt){
                    orden[i] = bombillas[j].id;
                    utilizadas[j] = 1; s = 0;
                    ++nUtilizadas;
                    ++vistas;
                    i+=m;
                    break;
                    //segundo caso que sea menor , pero es la bombillas más alta , entonces se suma 
                }else if(s + bombillas[j].duracion < maxt){
                    s += bombillas[j].duracion;
                    orden[i] = bombillas[j].id;
                    utilizadas[j] = 1;
                    ++nUtilizadas;
                    ++vistas;
                    i+=m;
                    printf("j = %d s = %d , i = %d, b = %d\n", j, s, i, b);
                    
                }else if(j == n-1 || (j+nUtilizadas - vistas) == n){
                    //printf("Ultima bombilla = %d , utilizadas = %d vistas = %d\n", j, nUtilizadas, vistas);
                    //si es la última bombilla y no se ha completado la suma
                    //se añade a la siguiente bombilla
                    s += bombillas[j].duracion;
                    orden[i] = bombillas[j].id;
                    utilizadas[j] = 1;
                    ++nUtilizadas;
                    ++vistas;
                    i+=m;
                    break;
                }
            }else{
                vistas++; //bombillas vistas ya
            }
        }
        i = b; //poner el principio
    
    }
    //Ultimas bobillas se deben llenar con los huecos libres
    for(int k = 0; k < n; k++){
        for(int u = m-1; u < n; ++u ){
            if(orden[k] == -1 && !utilizadas[u]){
                orden[k] = bombillas[u].id;
                utilizadas[u] = 1;
                
            }  
        }
    }
    
    //imprimir orden
    printf("\nOrden FINAL de bombillas:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", orden[i]);
    }
    printf("\n");
    



    // Retornar NULL por ahora (puedes implementar lógica adicional si es necesario)
    return NULL;
}

#endif
