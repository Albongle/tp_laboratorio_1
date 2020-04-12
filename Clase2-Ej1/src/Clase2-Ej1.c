/*
 ============================================================================
 Name        : Clase2-Ej1.c
 Author      : Alejandro Bongioanni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	int num;
	int i;
	int acum=0;
	float prom=0;
	int max;
	int min;




	setbuf(stdout, NULL); //Para mostrar en consola

	for (i=1 ; i<6; i++)
	{


	printf("Ingrese un numero  \n"); //ingreso de datos
	scanf("%d",&num);

	acum+=num;
	//max y min
	if(i==1)
		{
		max=num;
		min=num;

		}
	else
		{

		if (num>max)

		{
		max=num;
		}
		if (num<min)
		{
		min=num;
		}
		}

	}
	prom=(float)acum/(i-1);

	printf("El numero maximo es %d   \n", max);
	printf("El numero min es %d  \n", min);
	printf("El promdio  es %.2f \n", prom);


	system("PAUSE()");
}
