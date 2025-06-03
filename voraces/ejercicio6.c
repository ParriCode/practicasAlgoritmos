/**
 * @file ejercicio6.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */


 #include <stdlib.h>
 #include <stdio.h>
 
 /**
  * @brief  Encontrar el varlo minimo de una curva concava
  * 
  * @param v vector
  * @param a primer elemento
  * @param b ultimo elemento
  * 
  * @return el valor minimo
  */
 int  divide(int * v, int a, int b ){
     if(a >=b){
         return v[a];
     }else{
         int m = (a+b)/2;
         if(v[m] <= v[m+1]){
             return divide(v, a , m);
 
         }else{
             return divide(v, m+1 , b);
         }
 
 
     }
 
 }
 
 typedef struct {
     int id;
     int *bombones;
     int nbombones;
 }caja;
 
 /**
  * @brief comparar cajas por numero de bombones
  * 
  * @param a 
  * @param b 
  * @return 
  */
 int comparar_cajas(const void * a, const void *b){
     return ((caja * )b)->nbombones - ((caja*) a)->nbombones;
 }
 
 void voraz(int  *bombones, int nbombones, caja * cajas, int ncajas){
     int count;
     int comprar[ncajas];
 
     int conseguidos = 0; //bombones conseguidos
 
     for(int c = 0; c < ncajas; ++c){
 
         comprar[c] = 0; //inicializar todas las compras a 0
     }
     comprar[0] = cajas[0].id; //La primera caja se comprar
   /*  for(int b = 0; b < cajas[0].nbombones;++b){
         bombones[cajas[0].bombones[b]] = 1; //Se compra la primera caja aleatoriamente
     }*/
     int id = 0;
     int maxcount = 0; //numero máximo de conteo
     int k = 0;
     int u = 0;
     while(conseguidos != nbombones){
         for(int c = 0; c < ncajas; ++c){
             //ver si el bombon está en lacada
             count = 0;
             for(int b = 0; b < cajas[c].nbombones; ++b){
                 if(!bombones[ cajas[c].bombones[b]]){ //verificar cuantos bombones nuevos sse añadirían
                     ++count; 
                 }
             }
             if(count > maxcount){
                 u = c;
             }
         }
        //siguiente caja de combones, la siguiente más pequeña pues es más probable que 
         comprar[k] = cajas[u].id;
 
         for(int b = 0; b < cajas[u].nbombones; ++b){
             if(!bombones[ cajas[u].bombones[b]]){ //Poner los bombones comprados a 1 
                 bombones[ cajas[u].bombones[b]] = 1;
                 ++conseguidos;
             }
         }
 
     }
     printf("BOMBONES \n");
     for(int i = 0; i < nbombones; ++i){
         printf("%d ", bombones[i]);
     }
     
 }
 
 int main() {
     int bombones[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Bombones disponibles (0 = no comprado)
     int nbombones = sizeof(bombones) / sizeof(bombones[0]);
     
     caja cajas[] = {
         {1, (int[]){0, 1}, 2},
         {2, (int[]){2, 3}, 2},
         {3, (int[]){4, 5}, 2},
         {4, (int[]){6, 7}, 2},
         {5, (int[]){8, 9}, 2}
     };
     int ncajas = sizeof(cajas) / sizeof(cajas[0]);
     
     // Ordenar las cajas por número de bombones
     qsort(cajas, ncajas, sizeof(caja), comparar_cajas);
     
     // Ejecutar el algoritmo voraz
     voraz(bombones, nbombones, cajas, ncajas);
     
     return 0;
 }