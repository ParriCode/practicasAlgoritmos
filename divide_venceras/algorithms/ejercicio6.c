/**
 * @file ejercicio6.c
 * @author Jose Luis Parrilla Fuentes (theparri@protonmail.com)
 * @brief Dado un vector de corredores con un dorsal , el algoritmo implementa DyV 
 * para obtener el corredor que más agua ha llevado
 * @version 0.1
 * @date 2025-03-20
 * 
 */

 #include "ejercicio6.h"
 #include <stdio.h>

/**
 * @brief Calcular valor absoluto de un numero
 * 
 */
int abs(int n){
    int mask = n >> (sizeof(int) * 8 -1); //Aquí se desplazan todos los bits menos el último
    return (n+mask)^mask; //invertir si mask es 1 , y como se le suma ya se tiene el complemento a2
}   

  /**
   * @brief 
   * 
   * @param v 
   * @param a 
   * @param n 
   * @param posicion 
   * @return Dorsal del corredor que más agua ha llevado dorsal = posicion dentro del vector
   */
int iter = 0;
  corredor corredor_mas_agua(corredor *v, int a ,int b, int posicion){
    
    if(a == b ){
        return v[a];
    }else{
        int m = (a+b)/2;
        if(a <= m) corredor_mas_agua(v,a   , m, posicion);
        if(m+1 <= b) corredor_mas_agua(v,m+1 , b, posicion);
        int k = -1;
        int i = a;
        int j = m+1;
        corredor aux[posicion];
        //merge de los arreglos hasta la posición indicada , como caa iteracción solo puede hacerse menor
        while(k < posicion && ( i<= m || j <= b)){
            if( i <= m && (v[i].cantidad_agua <= v[j].cantidad_agua || j > b) ){
                aux[++k] = v[i++];
            }else{
                aux[++k] = v[j++];
            }
        }

        for(i = a , k  = 0; i <= b && k < posicion;++i,++k){
            v[i] = aux[k];
            ++iter;
        }
   //     printf("%d, ", iter);
        return v[posicion - 1];
    }
    
  }
 
 
