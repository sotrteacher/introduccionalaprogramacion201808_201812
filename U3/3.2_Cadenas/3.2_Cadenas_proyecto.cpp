// 3.2_Cadenas_proyecto.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <stdio.h>
void show_lista(char l[][64],int size);

/*3.2 Cadenas
  Una cadena de caracteres es un array unidimensional, 
  en el cual todos sus elementos son de tipo char.
*/
int main()
{
	/*3.2.1 Arreglos de caracteres
	  Un array de caracteres puede ser inicializado 
	  asign\'andole un literal. Por ejemplo:
	*/
	char cadena[] = "abcd";
	/*inicializa cadena[0] a cadena[4]. El quinto 
	  elemento, es el caracter nulo (\0), con el cual 
	  C finaliza todas las cadenas de caracteres.
	*/

	/*Si se especifica el tamanio del array de 
	  caracteres y la cadena asignada es m\'as larga 
	  que el tamanio especificado, se obtiene un error 
	  en el momento de la compilaci\'on. Por ejemplo:*/
	//char cadena1[3] = "abcd";
	/*Este ejemplo dar\'ia lugar a un mensaje de error, 
	  indic\'andonos que hemos excedido los l\'imites 
	  del array.*/

	/*Si la cadena asignada es m\'as corta que el 
	  tamanio del array de caracteres, el resto de 
	  los elementos del array son inicializados a 
	  valor nulo (\0).*/
	char cadena2[5] = "abc";
	printf("|%3c|",cadena2[0]);
	printf("|%3c|",cadena2[1]);
	printf("|%3c|",cadena2[2]);
	printf("|%3d|",cadena2[3]);
	printf("|%3d|", cadena2[4]);
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("\n");
	}
	/*3.2.3 Arreglos de cadenas de caracteres
	  El siguiente ejemplo declara un array denominado 
	  lista como un arreglo de cadenas de caracteres.*/
	char lista[39][64] = {
		"Alvarado Reyes Ulises",
		"Arias Lomeli Alejandro",
		"Aquino Paz Gustavo",
		"Arriaga Palma Fernando",
		"Arrieta Mendoza Alan Yohan",
		"Balderrabano Rodriguez Ricardo",
		"Becerril Velasco Axel",
		"Benitez Mondragon Daniel",
		"Carbajal Cruz Raymundo",
		"Casillas Baltazar Obed Salomon",
		"Correa Escobar Jose Luis",
		"Cruz Quixtiano Manuel",
		"Garcia Jimenez Luis Josue",
		"Godinez Torres Ruben",
		"Guerrero Cangas Kevin Ricardo",
		"Guzman Fabila Jafet",
		"Guzman Lopez Jaime",
		"Hernandez Tobon Edgar",
		"Hinojosa Perez Marco Antonio",
		"Martinez Villegas Ricardo",
		"Matamoros Balderas Arturo",
		"Mendoza Meza Manuel Everardo",
		"Navarro Herrera Leon Ricardo",
		"Oliva Hernandez Ian Yared",
		"Olmos Valle Marco Antonio",
		"Olvera Ramirez Angel",
		"Ortega Espinosa Luis David",
		"Ramirez Valdez Gabriel",
		"Rojas Garcia Cristian",
		"Rubio Guerrero Edgar Miguel",
		"Salomon Castillo Jose Luis",
		"Sampson Escarcia Preston Donnet",
		"Sanchez Frausto Arturo",
		"Sanchez Garcia Luis Fernando",
		"Santos Luis Enrique",
		"Torres Cervantes Angel Aaron",
		"Torres Morfin Iktan Zihan",
		"Vega Gutierrez Javier",
		"Velasco Hernandez Eric"
	};
	/*El arreglo de cadenas de caracteres declara e 
	  inicializa por extensi\'on el arreglo denominado 
	  lista como un arreglo de 
	  cadenas de caracteres*/
	show_lista(lista,39);

	/*Antes de leer una cadena de caracteres, debe 
	  declararse el arreglo de tipo char que la va a 
	  contener. La dimensi\'on del arreglo debe 
	  corresponderse con el n\'umero de caracteres 
	  m\'aximo que puede contener la cadena, m\'as uno 
	  correspondiente al caracter nulo de terminaci\'on. 
	  Por ejemplo, si queremos leer un nombre de 40 
	  caracteres de longitud m\'axima,debemos declarar 
	  el arreglo de la forma siguiente:*/
	char nombre[41];
	/*Para leer esta cadena de caracteres, podemos 
	emplear la funci\'on scanf(). En este caso, la 
	variable nombre no necesita ser precedida por el 
	operador &, porque nombre es una dirección, la 
	direcci\'on de comienzo del arreglo.*/
	printf("\nTECLEA UN NOMBRE (Sin espacios):");
	/**En DevCpp************/
	/* scanf("%s",nombre); */
	/***********************/
	/**En Visual Studio******************/
	scanf_s("%s",nombre,sizeof(nombre));
	/************************************/
	printf("%s\n",nombre);


	
    return 0;
}

void show_lista(char l[][64], int size) {
	int i;
	for  (i = 0; i < size; i++)
	{
		printf("%2d %s\n",i+1,l[i]);
	}
}