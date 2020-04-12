/*
 ============================================================================
 Name        : Clase1-Ej1.c
 Author      : Alejandro Bongioanni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//Ejercicio2 ClassRoom

	int main() {

		int a;
		int b;
		int producto;
		int cuadrado;
		setbuf(stdout, NULL);

		do{
		printf("Ingrese numero 1: \n");
		scanf("%d",&a);
			if(a<=0)
			{
				system("CLS()");
	            printf("Ingrese un numero mayor a 0 \n");
	            printf("Ingrese numero 1: \n");
	            scanf("%d",&a);
			}

	    }while(a<=0);

		do{
		system("CLS()");
		printf("Ingrese el numero 2: \n");
		scanf("%d",&b);

			if(b<=0)
			{
			system("CLS()");
			printf("Ingrese un numero mayor a 0 \n");
			printf("Ingrese el numero 2: \n");
			scanf("%d",&b);
			}

	    }while(b<=0);

		producto=a*b;
		cuadrado=a*a;
		system("CLS()");
		printf("El producto es : %d\n", producto);
		printf("El el cuadrado es : %d\n", cuadrado);

		system("PAUSE()");
		return 0;

	}


