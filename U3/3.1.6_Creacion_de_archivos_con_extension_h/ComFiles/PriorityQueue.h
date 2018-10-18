/** PriorityQueue.h
 */
#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#define SIZE	10

#define OVERFLOW	-1
#define UNDERFLOW	-2

/*Devuelve 1 si la cola est\'a vacia, y 
  devuelve 0 en caso contrario*/
int Empty();

/*Coloca I en la cola de prioridad*/
void Put(int I);

/*Obtiene el entero de mayor prioridad
  (el m\'inimo de los enteros en la cola)*/
int Get();

#endif /* PRIORITY_QUEUE */
