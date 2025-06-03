/**
 * @file merguesort.c
 * @author Jose Luis Parrilla Fuentes (theparri@protonmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */

int n0_ternaria = 100000;


/**
 * @brief Busqueda ternaria de un elemento dado un vector ordenado
 * @pre El vector Debe estar ordenado
 * @param v vector ordenado
 * @param a Comienzo del vector
 * @param b Final del vector
 * @param ele elemento a buscar
 * @post posicion del elemento encontrado
 */
int ternaria_rec(int v[], int a, int b, int ele){
    
    if(a > b) return -1; //Condicion de parada

    if(v[a] == ele) return a;
    if(v[--b] == ele) return b;
    if(b < n0_ternaria){
        //Busqueda lineal una vez pasado el umbral
        for(int i= a; i< b;++i){
            if(v[i] == ele){return i;}
        }
        return -1;
    }else{
        int ca= a+ (b-a)/3;
        int cb = b-(b-a)/3;
        if(ele < v[ca]){
            return ternaria_rec(v,a+1 ,ca-1, ele); // se le suma 1 al elemento pues v[a] ya ha sido comprobado
        }else if(ele < v[cb]){
            return ternaria_rec(v,ca ,cb-1  , ele); 
        }else if(ele < v[b]){ //Es posible que se pida un elemento fuera de rango
            return ternaria_rec(v,cb, b , ele); //tercer segment
        }else{return -1;} // El elemento no se encuentra en el vector
    }

        
  
  //  }


}

/**
 * @brief Inicialización del algoritmo de buqueda ternaria 
 * @pre El vector debe estar ordenado
 * @param v Vector 
 * @param tam tamaño del vector
 * @param ele elemento a buscar
 * @return posicion del elemento , -1 si no se encuentra
 */
int ternaria(int v[] , int tam, int ele){
    if(ele >= v[0] && ele <= v[tam-1]){ //Comprobar que el elemento se cneutnra dentro del rango del vector
      //  printf("El elemento se encuentra ene l rango\n");
        return ternaria_rec(v, 0 , tam, ele); 
    }
    else return -1 ;
}
int main() {
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int tam = sizeof(v) / sizeof(v[0]);
    int ele = 10; // Elemento a buscar
    int pos = ternaria(v, tam, ele);
    
    if (pos != -1) {
        printf("El elemento %d se encuentra en la posicion %d\n", ele, pos);
    } else {
        printf("El elemento %d no se encuentra en el vector.\n", ele);
    }
    
    return 0;
}
