#include <stdio.h>
#include <string.h>
int main(){
	char usuario[20], psw[20];
    scanf("%s", usuario);
	scanf("%s", psw);
    if(strcmp(usuario, "nombre")==0 && strcmp(psw, "psw")==0)
       printf("Bienvenido: %s", usuario);
   else
	   printf("Usuario y/o contraseña incorrectos");
   getch();
}
