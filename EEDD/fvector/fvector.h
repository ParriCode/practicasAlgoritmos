/*************************ivector.h***************************/
/*         M�dulo de cabeceras para uso de objetos           */
/*                   VECTORES DE REALES FLOAT                */
/*************************************************************/

#ifndef FVECTOR

#define FVECTOR

typedef float *fvector;

fvector fcreavector(int tam);
void ffreevector(fvector *v);

#endif
