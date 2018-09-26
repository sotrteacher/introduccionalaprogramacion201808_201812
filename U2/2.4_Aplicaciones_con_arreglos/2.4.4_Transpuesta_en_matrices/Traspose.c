#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i,j;
	float A[2][3]={{2,4,6},{8,10,12}};
	printf("A =\n");
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			printf("\t%f",A[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
