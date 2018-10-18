#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include "..\ComFiles\PriorityQueue.h"

/*Usa la cola de prioridad implementada
  en PriorityQueue.cpp*/
int main()
{
	//int Test_Data[] = {10,5,0,25,15,30,15,20,-6,40};
	int Test_Data[SIZE];
	srand(time(NULL));
	int N,I;
	for (N = 0; N < SIZE; N++) {
		Test_Data[N] = 1 + rand() % 100;
	}
	for (N = 0; N < sizeof(Test_Data) / sizeof(int); N++) {
		printf("%5d",Test_Data[N]);
		Put(Test_Data[N]);
	}
	printf("\n");
	while (!Empty()){
		I = Get();
		printf("%5d",I);
	}
	printf("\n");
    return 0;
}