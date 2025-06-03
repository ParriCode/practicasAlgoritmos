/**
 * @file ejercicio5.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */


 
 #include "imatriz2d/imatriz2d.h"
 #include <limits.h>
 #include <stdio.h>
 
 /**
  * @brief verificar si un grafo no dirigido es conexo 
  * 
  * @param m 
  * @param n 
  * @return 
  */
 int grafo_conexoVORAZ(imatriz2d m, int n){
     int padres[n];
     int claves[n];
     int visitados[n];
     int nady;
     for(int i = 0; i < n; ++i){
         visitados[i] = 0;
         claves[i] = -1;
     }
     int k;
     for(int i = 0; i< n ; ++i){
         nady = 0;
         k = -1;
         for(int f = 0; f < n; ++f){
             for(int c = 0; c < n; ++c){
                 if(m[i][c]){
                     ++nady;
                 }
             }
         }
         
     }
 }
 
 int grafo_conexo(imatriz2d m, int n){
     grafo_conexoVORAZ(m, n);
 
 
     return 1;
     int visitados[n];
     int stack[n];
     int top = 0;
     stack[0] = 0;
     visitados[0] = 1;
     int i = 0;
     int k = 0;
     int count = 0;
     for(int i = 1; i < n;++i){visitados[i] = 0;stack[i] = -1;}
     while(count < n){
         k = -1;
         for(int v = 0; v < n ; ++v){
             if(m[i][v] != -1 && !visitados[v]){
                 k = v;
                 break;
             }
         }
         if(k == -1){
             if(top == -1 ){
                 printf("No es un grfo conexo\n"); return 0;
             }else{
                 k = stack[top];
                 stack[top] = -1;
                 --top;
             
             }
         }else{
             visitados[k] = 1;
             ++count;
             ++top;
 
             stack[top] = i;
 
         }
         i = k;
     }   
     printf("Es un motherfaking grafo conexo\n");
     return 1;   
 }
 
 int main() {
     int n = 5; // Número de nodos
     imatriz2d m = icreamatriz2d(n, n);
     
     // Inicializar la matriz de adyacencia (grafo no dirigido)
     m[0][1] = 1; m[1][0] = 1;
     m[0][2] = 1; m[2][0] = 1;
     m[1][3] = 1; m[3][1] = 1;
     m[2][4] = 1; m[4][2] = 1;
     //m[3][4] = 1; m[4][3] = 1; // Descomentar para hacer el grafo conexo
 
     if (grafo_conexo(m, n)) {
         printf("El grafo es conexo.\n");
     } else {
         printf("El grafo no es conexo.\n");
     }
 
     ifreematriz2d(&m);
     return 0;
 }
