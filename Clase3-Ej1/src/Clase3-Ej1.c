/*
 ============================================================================
 Name        : Clase3-Ej1.c
 Author      : Alejandro Bongioanni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Calculos.h"


int main(void) {
	fflush(stdin); // Limpia Buffer entrada
	setbuf(stdout,NULL); //Limpia Buffer salida
	int ingreso;
	system("CLS()"); //borra pantalla
	setbuf(stdout, NULL);

	printf("Ingrese el radio de un circulo \n");
	scanf("%d",&ingreso);

	printf("\nEl area del circulo es %.2f ", GetArea(ingreso));




	system("PAUSE()"); //pausa
	return 0;
}





//getche(); devuelve un caracter por teclado


