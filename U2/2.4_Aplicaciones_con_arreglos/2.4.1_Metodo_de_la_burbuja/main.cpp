#include <iostream>
#include <stdio.h>
//#include "cabecera.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int intArr[]={2,0,1,7,1,0,0,9,1,6,2,5};
int intArrBid[2][12];

/**
 * Algoritmo burbuja
 * orden de menor a mayor.
*/
int main(int argc, char** argv) {
	int tmp,i,j,cambios=0;
//	printf("\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
//	   intArr[0],intArr[1],intArr[2],intArr[3],intArr[4],
//	   intArr[5],intArr[6],intArr[7],intArr[8],intArr[9],
//	   intArr[10],intArr[11]);
	for(i=0;i<sizeof(intArr)/sizeof(int);i++){
		printf("\t%d",intArrBid[0][i]=intArr[i]);
	}
	printf("\n");
	/*Burbuja*/
	for(j=10;j>=0;j--){
		for(i=0;i<=j;i++){
			if(intArr[i]>intArr[i+1]){
				tmp=intArr[i];
				intArr[i]=intArr[i+1];
				intArr[i+1]=tmp;
				cambios++;
			}
		}
		if(!cambios){
			break;/*si no hubo cambios, salimos del for externo*/
		}
		cambios=0;/*otherwise reseteamos cambios*/
//		printf("\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
//	       intArr[0],intArr[1],intArr[2],intArr[3],intArr[4],
//		   intArr[5],intArr[6],intArr[7],intArr[8],intArr[9],
//		   intArr[10],intArr[11]);
		system("pause");
	}
	for(i=0;i<sizeof(intArr)/sizeof(int);i++){
		printf("\t%d",intArrBid[1][i]=intArr[i]);
	}
	printf("\n");
	
	 
	return 0;
}
