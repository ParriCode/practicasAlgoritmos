/**
 * @file ejercicio1.c
 * @author Jose Luis Parrilla Fuentes (theparri@protonmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int id;        // Identificador del pedido
    int tiempo;   // Tiempo de entrega
    int cobrar;   // Cantidad a cobrar por el pedido
} pedido;
 /**
  * @brief comparar dos pedidos
  * @param a 
  * @param b 
  * @return verdadero si a es mayor que b, falso en caso contrario
  */
 int comparar_pedidos(const void *a, const void *b){
     return ((pedido *)b)->cobrar - ((pedido *)a)->cobrar;
 }

 /**
  * @brief Esta funcion devuelve los pedidos que se deben cumplir para tener el máximo beneficio
  * @details Los pedidos que superen el tiempo de entrega no se cobrarán
  *          Para resolverlo ordenaré de mayor a menor por cantidad de dinero a cobrar y los aplicaré en el límite de tiempo
  * @param pedidos vector de pedidos  
  * @param n numero de pedidiso
  */
void  peticion_entregas(pedido *pedidos, int n){
    qsort(pedidos, n, sizeof(pedido), comparar_pedidos);
    int beneficio = 0;
    int entregas[n];
    int ncount  = 0;
    int fuera[n];
    for (size_t i = 0; i < n; i++)
    {
        entregas[i] = -1;
    }
    
    int j = 0;
    for(int i = 0,j = 0; i < n; i++){
        int t = pedidos[i].tiempo -1;
        while(t >= 0 && entregas[t] != -1){
            t--;
        }
        if (t >= 0) {
            entregas[t] = i; // Guardar índice del pedido en la posición disponible
        }
        
    }
    for (int i = 0; i < n; i++) {
        if (entregas[i] != -1) {
            beneficio += pedidos[entregas[i]].cobrar;
        }
    }
    //Comprobar solucion
    printf("Orden de entrega:\n");
    for (int i = 0; i < n; i++) {
        if (entregas[i] != -1) {
            printf("Tiempo %d: Pedido %d (Valor: %d)\n", i + 1, pedidos[entregas[i]].id, pedidos[entregas[i]].cobrar);
        }
    }

    printf("Beneficio máximo: %d\n", beneficio);
 }
 int main(int argc , char * argv[]){
    pedido pedidos[] = {
        {1, 5, 100},
        {2, 3, 200},
        {3, 4, 150},
        {4, 2, 300},
        {5, 1, 250}
    };
    int n = sizeof(pedidos) / sizeof(pedidos[0]);
    peticion_entregas(pedidos, n);
    return 0;
}