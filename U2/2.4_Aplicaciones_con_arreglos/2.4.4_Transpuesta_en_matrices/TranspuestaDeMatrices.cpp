// TranspuestaDeMatrices.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include "..\CommonFiles\Header1.h"

int main(int argc, char *argv[]) {
	int i,j;
	float A[2][3] = { { 2,4,6 },{ 8,10,12 } };
	printf("A =\n");
	/* Se imprime la matriz A */
	for (i = 0; i<2; i++) {
		for (j = 0; j<3; j++) {
			printf("%7.2f",A[i][j]);
		}
		printf("\n");
	}
	/* Para obtener la transpuesta podemos utilizar la 
	macro transpuesta(n,m,A,At) definida en el archivo de  
	cabecera Header1.h  */
	/* como A es de 2 x 3, la transpuesta ser\'a de 3 x 2 */
	Mcof(A_T,3,2);
	transpuesta(2,3,A,A_T);
	printf("Transpuesta de la matriz A:\n");
	/* Se imprime la matriz transpuesta de A */
	for (i = 0; i<3; i++) {
		for (j = 0; j<2; j++) {
			printf("%7.2f", A_T[i][j]);
		}
		printf("\n");
	}

	/* Se usa la macro show_mNxM(A,N,M) */
	printf("La transpuesta de\nA^{t} =\n");
	show_mNxM(A_T,3,2);
	printf("es nuevamente\nA =\n");
	Mcof(A_T_T, 2, 3);
	transpuesta(3, 2, A_T, A_T_T);
	show_mNxM(A_T_T,2,3);

	time_t tiempo,tiempo1;
	tiempo=time(NULL);
	time(&tiempo1);

	return 0;
}

