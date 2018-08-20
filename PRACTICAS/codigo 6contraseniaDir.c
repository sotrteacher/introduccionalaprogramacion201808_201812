#include <stdio.h>
int main(){
    
char usuario[10]; //usuario
char uTest[10]; //para validación de usuario
char caracter1, cTest; //character de la contraseña
int numero, nTest; //entero de la contraseña
int op; //para seleccionar opciones
char op2; //para seleccionar opciones
char *ap_caracter=&caracter1;
int *ap_num=&numero;
printf("Ingrese su usuario: ");
scanf("%s",&usuario);
printf("Ingrese su contrasenia (1caracteres y número):");
fflush(stdin);
scanf("%c%d",&caracter1,&numero);
while(op==1||op==2){
   printf("Seleccione:\n");
   printf("1. Ver usuario y contrasenia\n");
   printf("2. Validar usuario y contrasenia\n");
   fflush(stdin);
   scanf("%d",&op);
   if(op==1){
        	//acciones para ver
   }else if(op==2){
       	//acciones para validar
   }
}
printf("Usuario: %s\n",usuario);
printf("Contraseña: \n");
printf(" entraría a la dirección %p y %p, está seguro de   continuar (S/N)) ",ap_caracter,ap_num);
fflush(stdin);scanf("%c",&op2);
if(op2=='S')
   printf("contrasenia... %c%d\n",*ap_caracter,*ap_num);
printf("Ingrese su usuario: ");
scanf("%s",&uTest);
printf("Ingrese su contrasenia (3 caracteres y un número):");
fflush(stdin);
scanf("%c%d",&cTest,&nTest);
if(strcmp(uTest,usuario)==0){
    printf("CORRECTO!!\n");
}else{
    printf("INCORRECTO!!\n");
}
getch();
}
