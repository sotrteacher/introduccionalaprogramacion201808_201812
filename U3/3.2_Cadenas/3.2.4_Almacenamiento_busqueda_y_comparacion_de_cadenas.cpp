// 3.2.4_Almacenamiento_busqueda_y_comparacion_de_cadenas.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"

/*3.2.4 Almacenamiento, b\'usqueda y comparaci\'on
        de cadenas.
  FUNCION gets(). Leer una cadena de caracteres
  La funci\'on gets() lee una l\'inea de la entrada
  est\'andar, stdin, y la almacena en la variable
  especificada. Esta variable es una apuntador a la
  cadena de caracteres leida
  #include <stdio.h>
  char *gets(char *var);
  La variable var, contiene todos los carecteres
  tecleados, excepto el caracter nueva l\'inea (\n),
  que es autom\'aticamente remplazado por el
  caracter nulo (\0), con el cual C finaliza toda
  cadena de caracteres.

  La funci\'on gets() devuelve un apuntador al
  valor leido. Un valor nulo para este apuntador,
  indica un error o una condici\'on de fin de
  archivo (eof).

  La funci\'on gets(), a diferencia de la funci\'on
  scanf(), permite la entrada de una cadena de
  caracteres formada por varias palabras separadas
  por espacios en blanco, sin ning\'un tipo de
  formato. Recordar que para scanf(), el espacio en
  blanco act\'ua como separador de datos en la
  entrada.
*/
/*FUNCION puts(). Escribir una cadena de caracteres
  La funci\'on puts() escribe una cadena de caracteres 
  en la salida estandar stdout, y remplaza el caracter 
  nulo de terminaci\'on de la cadena (\0) por el 
  caracter nueva l\'inea (\n).
  #include <stdio.h>
  int puts(const char *cadena);
*/
#include <stdio.h>
char linea[81];
char *pc;
int main()
{
	printf("Introduce una cadena de caracteres: ");
	/**En DevCpp***************/
	/* pc=gets(linea);        */
	/**************************/
	/**En Visual Studio 2017***********/
	//pc = gets_s(linea,sizeof(linea));
	gets_s(linea, sizeof(linea));
	pc = linea;
	/**********************************/
	printf("La l\\'inea introducida es:\n");
	printf("%s\n",linea);
	puts("Pulse una tecla para continuar");
	getchar();
	puts("\nEscribo la l\\'inea por segunda vez:");
	puts(pc);
    return 0;
}

