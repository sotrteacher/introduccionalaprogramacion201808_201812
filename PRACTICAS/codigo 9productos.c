#include <stdio.h>
	#include <conio.h>

	int main()
	{
	char codigo[15];
	int actual, real, opc;
     
	FILE *pf;   
	pf = fopen("PIEZAS.DAT","w"); //Archivo binario
	if(pf==NULL){
		printf("ERROR EN LA OPERACION DE APERTURA");
		return 1;
	}
do{
		printf("Menu:\n 1. Ingresar\n 2. Salir\n");
		scanf("%d", &opc);
		
		if(opc == 1){
	printf("Introduzca el código del producto, cantidad actual y cantidad real");
	scanf("%s %d %d", codigo, &actual, &real);
		fprintf(pf, "%s %d %d", codigo, actual, real);
 		}
	}while(opc!=2);
	fclose(pf);
 
	getch();
	return 0;
}
