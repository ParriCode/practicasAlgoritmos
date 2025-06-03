/*************************ivector.c***************************/
/*             M�dulo en C para uso de objetos               */
/*                  VECTOR DE REALES FLOAT                   */
/*************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "fvector.h"

fvector fcreavector(int tam) {
	fvector v;

	if ( (v=(fvector)malloc(tam*sizeof(float))) == NULL){
		fprintf(stderr, "fcreavector: No hay memoria.\n");
		exit(1);
	}
	return(v);
}

/*************************************************************/

void ffreevector (fvector *v) {

	if (*v){
		free (*v);
		*v=NULL;
	}
}
