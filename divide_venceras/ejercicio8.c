/**
 * @file ejercicio8.c
 * @author Jose Luis Parrilla Fuentes (theparri@protonmail.com)
 * @brief Sean X e Y dos vectores de enteros sin elementos repetidos de dimensión
 * N. Se sabe que X está ordenado crecientemente y que Y lo está
 * decrecientemente. Diseña un algoritmo DyV que devuelva en tiempo logarítmico,
 * si existe, el índice i tal que X[i] = Y[i]
 * @version 0.1
 * @date 2025-03-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */

/**
 * @brief 
 * 
 */
int intermedio(int* X, int * Y , int ax, int bx ,int ay,int by,  int n){
    if(ax >= bx ){
        return ax == n;
    }
    int mx = (ax+bx)/2;
    int my = (ay+by)/2;
    if(     X[mx] <= n && Y[my] <= n){ return  intermedio(X,Y,ax, mx-1 , my , by,  n);}
    else if(X[mx] <= n && Y[my] >= n){ return  intermedio(X,Y,ax, mx-1 , ay , my-1,  n);}
    else if(X[mx] >  n && Y[my] < n){  return  intermedio(X,Y,mx, bx , my , by,  n);}
    else{                              return  intermedio(X,Y,mx, bx , ay , my-1,  n);};
    


}
int main() {
    int X[] = {1, 2, 3, 4, 5};
    int Y[] = {5, 4, 3, 2, 1};
    int n = sizeof(X) / sizeof(X[0]);
    
    // Llamada a la función intermedio
    int resultado = intermedio(X, Y, 0, n - 1, 0, n - 1, n);
    
    if (resultado) {
        printf("Existe un índice i tal que X[i] = Y[i]\n");
    } else {
        printf("No existe tal índice i\n");
    }
    
    return 0;
}