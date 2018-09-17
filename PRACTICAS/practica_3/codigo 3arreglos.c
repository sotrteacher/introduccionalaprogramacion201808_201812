#include <stdio.h>
int main(){
    int numeros[6], i, valor;
    for(i=0; i<6; i++)
		scanf("%d", &numeros[i]);
	printf("Numero a buscar:\n");
	scanf("%d", &valor);
    for(i=0; i<6; i++){
        if(valor==numeros[i])
              printf("Encontrado en la posicion: %d\n", i);
    }
    getch();
}
