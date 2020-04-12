/*
 ============================================================================
 Name        : Clase4-Ej1.c
 Author      : Alejandro Bongioanni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#define TAMANIO_ARRAY 64



int main(void)
{
char texto[TAMANIO_ARRAY];
setbuf(stdout,NULL);
fflush(stdin);

if((utn_getTexto(texto, "Ingrese un texto: ","error\n",1,TAMANIO_ARRAY))!=1)
{
	system("CLS()");

	printf("Error supero el numero maximo de posibilidades\n");
}
else
{

	printf("El texto ingresado fue: %s\n", texto);
}

system("PAUSE()");
return 0;
}
