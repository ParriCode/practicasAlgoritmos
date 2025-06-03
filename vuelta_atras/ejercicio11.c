/*Problema 11. Asignaciones de ordenadores y becarios a los 
vicerrectorados. 
El rector de la Universidad de Jaén ya tiene perfilado su nuevo equipo de 
gobierno.  De  los  nuevos  Vicerrectorados  creados  n  requieren  una  instalación 
informática y personal que la dirija. El rector les ha asignado n máquinas y n 
alumnos que cursan la asignatura de Diseño de Algoritmos para que asuman la 
dirección. 

Pero no todas las máquinas son apropiadas para las necesidades de todos 
los vicerrectorados. Se dispone de una función booleana apropiada(m,v) que 
indica si la máquina m es apropiada para el vicerrectorado v. Asimismo, no todos 
los alumnos conocen todas las máquinas, por lo que disponemos de una función 
booleana  conoce(a,m)  que  indica  si  el  alumno  a  conoce  la  máquina  m. 


Finalmente, no todos los alumnos aceptan trabajar en todos los vicerrectorados, 
por lo disponemos de la función booleana acepta(a,v) que indica si el alumno a 
acepta o no trabajar en el vicerrectorado v.  Se pide diseñar una función basada en la técnica de vuelta atrás capaz de 
encontrar, si existe, una manera de asignar a cada vicerrectorado una máquina 
apropiada a sus necesidades, y un alumno que conozca la máquina y que acepte 
trabajar en el vicerrectorado, si es que tal asignación existe. En caso de que no 
sea posible la asignación, el programa también debe devolverlo.*/



#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Alumno acepta trabajar ene l vicerectorado
 * @param a Alumno
 * @param v vicerectorado
 * @return 1 si acepta , 0 sino
 */
int acepta(int a , int v){
   return (v != a);
  // return a== v;
}
/**
 * @brief 
 * 
 *
 * @param m maquina 
 * @param v vicerectorado
 * @return 
 */
int apropiada(int v, int m){
  return v< m;
  //return m ==v;    
}
/**
 * @brief Comprueba si un alumno conoce una máquina.
 * 
 * @param a Alumno.
 * @param m Máquina.
 * @return 1 si la conoce, 0 en caso contrario.
 */
int conoce(int a , int m){
  return m%2;
}


/**
 * @brief Estructura para almacenar la relación entre alumno, vicerrectorado y máquina.
 * 
 * Esta estructura se utiliza para almacenar la relación entre un alumno, un 
 * vicerrectorado y una máquina en el contexto de asignaciones.
 */
typedef struct {
    int a;
    int v;
    int m;


} relacion;


/**
 * @brief Función recursiva para asignar alumnos, máquinas y vicerrectorados.
 * 
 * @param a Array de alumnos disponibles.
 * @param v Array de vicerrectorados disponibles.
 * @param m Array de máquinas disponibles.
 * @param n Número total de elementos.
 * @param ak Índice actual del alumno.
 * @param vk Índice actual del vicerrectorado.
 * @param mk Índice actual de la máquina.
 * @param tempsol Solución temporal.
 * @param tk Tamaño de la solución temporal.
 * @param sol Array de soluciones finales.
 * @param k Puntero al número de soluciones encontradas.
 */
void asignar(int * a, int * v, int * m, int n,int ak , int vk, int mk , relacion * tempsol, int tk,relacion * sol,int  * k){

    if(ak == n || vk == n || mk == n){
        //Poner en la solución definitiva solo las soluciones encontradas que no han sido repetidas
        for(int j = 0; j < tk; ++j){
          int repetida = 0;
          for(int i = 0 ; i < *k ; ++i){

                if(sol[i].a == tempsol[j].a && sol[i].v == tempsol[j].v && sol[i].m == tempsol[j].m  ){
                    repetida = 1;
                    break; //Esta solucion está repetida
                }
          }
            if(!repetida){
                sol[*k] = tempsol[j];
                ++*k;

            }

        }
       
        return;
        
    }else {
        for(int i = ak; i < n;++i ){
            for(int j = vk; j < n; ++j){
                for(int l = mk ; l < n; ++l){
                  //  if(a[ak] != -1 && vk != -1 && mk != -1 &&  acepta(a[ak],v[vk]) && apropiada(v[vk],m[mk]) && conoce(a[ak],m[mk])){
                    if(a[i] != -1 && v[j] != -1 && m[l] != -1 &&  acepta(a[i],v[j]) && apropiada(v[j],m[l]) && conoce(a[i],m[l])){
                        tempsol[tk].a = a[i];
                        tempsol[tk].v = v[j];
                        tempsol[tk].m = m[l];
                        a[i] = -1;
                        v[j] = -1;
                        m[l] = -1;
                        asignar(a,v,m,n,i+1,j+1,l+1, tempsol ,tk +1 ,sol, k);
                        a[i] = tempsol[tk].a; 
                        v[j] = tempsol[tk].v;
                        m[l] = tempsol[tk].m;
                    
                    }
    
                }
    
            }
        }
    }
 
   
    
    
}
#define n 5
int main(){
    int a[n] = {1,2,3,4,5};
    int v[n] = {5,4,3,1,5};
    int m[n] = {1,2,3,4,5};
    relacion sol[n*n*n]; //En el máximo caso la solución puede ser un grafo completo
    relacion tempsol[n]; //La solución temporal como mucho puede ser de tamaño n
    int k = 0;
    asignar(a,v,m,n,0,0,0,tempsol,0, sol,&k);

    //Imprimir solución 
    if(k == 0){+
        printf("No hay relaciones posibles\n");
    }else{

        printf("TODAS LAS RELACIONES POSIBLES\n");
        for(int i = 0; i < k; ++i){
            printf("%d: a: %d , v: %d, m. %d\n",i, sol[i].a, sol[i].v, sol[i].m);
        }
    }

    return 0;
}