/**
 * @file ejercicio12.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */


 #include <stdlib.h>
 #include <stdio.h>
#include <limits.h>



typedef struct {
    int semana;
    int vendedora;
    int compradora;
} entrada;

/**
 * @brief funcion comparador de las semanas
 *
 * @param a
 * @param b
 * @return
 */
int cmp_semana(const void  * a , const void  * b){

    return ((entrada * )a)->semana - ((entrada *) b)->semana; 
}
/**
 * @brief 
 * 
 *
 * @param vendedoras 
 * @param compradoras 
 * @param semana 
 * @param ngranjas 
 * @param infectadas 
 */
void epidemia(entrada *entradas, int nentradas, int ngranjas, int *infectadas, int ninfectadas) {
    // Ordenar las transacciones por semanas
    qsort(entradas, nentradas, sizeof(entrada), &cmp_semana);
    int cuarentena[ngranjas];
    int ncuarentena = ninfectadas;
    //inicializar la cuarentan
    for(int i = 0; i < ngranjas; ++i){
        cuarentena[i] = 0;
    }
    for(int i = 0; i< ninfectadas; ++i){
        cuarentena[infectadas[i]-1] = 1;
    }
   

    // Imprimir las transacciones ordenadas
    printf("\nTransacciones ordenadas por semanas:\n");
    for (int i = 0; i < nentradas; ++i) {
        printf("Semana %d: Granja %d vende a Granja %d\n",
               entradas[i].semana, entradas[i].vendedora, entradas[i].compradora);
    }
    printf("Granajas en cuarentena\n");
    for(int i = 0; i< ngranjas; ++i){
        printf("%d: %d\n",i, cuarentena[i]);
    }

    int aux;
    for(int i = 0; i < nentradas; ++i){
        //La vendedora está en cuarentena
        cuarentena[entradas[i].compradora -1]  |= cuarentena[entradas[i].vendedora -1];
    
        
    }
    printf("\nSOLUCION\n======== \n");
    printf("Granajas en cuarentena\n");
    for(int i = 0; i< ngranjas; ++i){
        printf("%d: %d\n",i+1, cuarentena[i]);
    }
    // Aquí puedes continuar con la lógica de la epidemia...
}


int main() {
    int ngranjas = 5;
    int ninfectadas = 2;
    int infectadas[] = {1, 3};
    entrada *entradas = (entrada *)malloc(sizeof(entrada) * 10);
    int nentradas = 0;

    // Simulación de transacciones
    entradas[nentradas++] = (entrada){1, 1, 2};
    entradas[nentradas++] = (entrada){2, 2, 3};
    entradas[nentradas++] = (entrada){3, 3, 4};
    entradas[nentradas++] = (entrada){4, 4, 5};

    epidemia(entradas, nentradas, ngranjas, infectadas, ninfectadas);

    free(entradas);
    return 0;
}