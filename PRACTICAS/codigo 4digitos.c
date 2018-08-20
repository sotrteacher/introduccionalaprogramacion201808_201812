#include <stdio.h>
int cantidad_digitos(int num){
	int c=0;
	while(num>0){
		num = num / 10;
		c++;
	}
	return c;
}
int main(){
	int numero, c;
     scanf("%d", &numero);
     c = cantidad_digitos(numero);	
     printf("Cantidad de digitos: %d\n", c);
     getch();
}
