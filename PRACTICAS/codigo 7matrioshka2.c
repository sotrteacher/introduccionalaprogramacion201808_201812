#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//1. Creación de la estructura matrioshka
typedef struct matrioshka{
    char nombre;
    float tamanio;
    char color[10];
    struct matrioshka* espacioHueco;//2a. Modificar la estructura para que pueda contener a otra matrioshka, apuntando a ella.
}matrioshka;

int main()
{
    //2b.Declarar 5 variables del tipo estructura matrioshka
    matrioshka *Ana;
    matrioshka *Beatriz, *Carla, *Daniela;
    matrioshka *Eva = (matrioshka*)malloc(sizeof(matrioshka));
    Ana=(matrioshka*)malloc(sizeof(matrioshka));
    Beatriz=(matrioshka*)malloc(sizeof(matrioshka));
    Carla=(matrioshka*)malloc(sizeof(matrioshka));
    Daniela=(matrioshka*)malloc(sizeof(matrioshka));
    //2c.Colocar los datos de cada una de ellas
    Ana->nombre='A';
    Ana->tamanio=10;
    strcpy ( Ana->color, "Verde" );
    Beatriz->nombre='B';
    Beatriz->tamanio=8;
    strcpy ( Beatriz->color, "Rojo" );
    Carla->nombre='C';
    Carla->tamanio=6.5;
    strcpy ( Carla->color, "Amarillo" );
    Daniela->nombre='D';
    Daniela->tamanio=5;
    strcpy ( Daniela->color, "Rosa" );
    Eva->nombre='E';
    Eva->tamanio=2;
    strcpy ( Eva->color, "Azul" );
    //2d.Agregar a Eva dentro de Daniela, a Daniela dentro de Carla y así sucesivamente
    Ana->espacioHueco=Beatriz;
    //Ana tiene un espacio hueco que será ocupado por Beatriz,
    //Ana tiene el hueco (espacio) donde guardará la dirección (referencia) de que dentro de ella va Beatriz
    //Ana y Beatriz son independientes
    Beatriz->espacioHueco=Carla;
    Carla->espacioHueco=Daniela;
    Daniela->espacioHueco=Eva;
    Eva->espacioHueco=NULL; //Dentro de Eva ya no va ninguna muñeca
    //3.Cambiar tamaño a Eva
    Ana->espacioHueco->espacioHueco->espacioHueco->espacioHueco->tamanio=3;
    //4.Cambiar color a la tercera
    strcpy ( Ana->espacioHueco->espacioHueco->color, "Morado" );
    //5.Imprimir

    printf("Dir. de Ana %p \n", &Ana);
    printf("Nombre %c \n",Ana->nombre);
    printf("Tam %.1f \n",Ana->tamanio);
    printf("Color %s \n",Ana->color);
    printf("Dir. de espacioHueco %p \n\n", Ana->espacioHueco);

    printf("Dir. de Beatriz %p \n", &Beatriz);//debe coincidir con la del espacioHueco de Ana
    printf("Nombre %c \n",Beatriz->nombre);
    printf("Tam %.1f \n",Beatriz->tamanio);
    printf("Color %s \n",Beatriz->color);
    printf("Dir. de espacioHueco %p \n\n", Beatriz->espacioHueco);

    printf("Dir. de Carla %p \n", &Carla);//debe coincidir con la del espacioHueco de Beatriz
    printf("Nombre %c \n",Carla->nombre);
    printf("Tam %.1f \n",Carla->tamanio);
    printf("Color %s \n",Carla->color);
    printf("Dir. de espacioHueco %p \n\n", Carla->espacioHueco);

    printf("Dir. de Daniela %p \n", &Daniela);//debe coincidir con la del espacioHueco de Carla
    printf("Nombre %c \n",Daniela->nombre);
    printf("Tam %.1f \n",Daniela->tamanio);
    printf("Color %s \n",Daniela->color);
    printf("Dir. de espacioHueco %p \n\n", Daniela->espacioHueco);

    printf("Dir. de Eva %p \n", &Eva);//debe coincidir con la del espacioHueco de Daniela
    printf("Nombre %c \n",Eva->nombre);
    printf("Tam %.1f \n",Eva->tamanio);
    printf("Color %s \n",Eva->color);
    printf("Dir. de espacioHueco %p \n\n", Eva->espacioHueco);
    return 0;
}
