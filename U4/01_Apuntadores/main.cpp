#include <iostream>
#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int A,B,i;
	int *intPt;
	intPt=&A;
	A='0';B='Z';
	for(i=0;i<20;i++){
		printf("%4d%4c\n",A+i,A+i);
	}
	printf("\n");
	//printf("%p %4d%4c\n",intPt,*intPt,*intPt);
	
	intPt=(int*)malloc(('Z'-'0'+1)*sizeof(int));
	*(intPt+0)='0';          // intPt[0]=*(intPt+0)
	*(intPt+1)='1';          // intPt[1]=*(intPt+1)
	intPt[2]='2';
	for(i='0';i<='Z';i++){
		*(intPt+i-'0')=i;
	}
	
	printf("\n");
	for(i=0;i<'Z'-'0'+1;i++){
		printf("%p %4d%4c\n",intPt+i,*(intPt+i),*(intPt+i));
	}
	
	int siz=sizeof("UPIITA");
	char upiita[]="UPIITA";
	char *charPt=(char*)malloc(siz);
	for(i=0;i<siz;i++){
		*(charPt+i)=upiita[i];
	}
	
	printf("\n");
	for(i=0;i<siz;i++){
		printf("%p %4d%4c\n",charPt+i,charPt[i],*(charPt+i));
	}
	
	
	
	free(intPt);
	free(charPt);
	return 0;
}
