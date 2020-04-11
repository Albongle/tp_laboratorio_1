/*
 * utn.c
 *
 *  Created on: 10 abr. 2020
 *      Author: aleja
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static int getInt(int* pResultado);
static int esNumerica(char* cadena);

int utn_getNumero(int* numero, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int ret=0;
	int ingreso;
	if (numero!= NULL && mensaje != NULL && mensajeError != NULL && maximo >= minimo && reintentos >=0 )
	{
		do
		{
			printf(mensaje);
			if(getInt(&ingreso))
			{
				if(ingreso<minimo || ingreso>maximo)
				{
					fflush(stdin);
					printf(mensajeError);
					reintentos--;
				}
			}
			else
			{
				printf("Error, el numero ingresado no es entero\n");
				reintentos--;
			}


		}while (reintentos>=0 && (ingreso<minimo || ingreso>maximo));

		if (reintentos>=0)
		{
			ret=1;
			*numero=ingreso;
		}

	}
	else
	{
		printf(mensajeError);
	}

	return ret;
}



static int getInt(int* pResultado)
{
	int ret=0;
	char buffer[64];
	if (pResultado!= NULL)
	{
		fgets(buffer,sizeof(buffer),stdin);
		buffer[strlen(buffer)-1]='\0';
		if (esNumerica(buffer))
		{
			*pResultado=atoi(buffer);
			ret=1;
		}

	}

	return ret;
}

static int esNumerica(char* cadena)
{
	int ret=0;
	int i=0;

	if (cadena!= NULL)
	{

		do
		{
			i++;
		}while(cadena[i]!='\0' && (cadena[i]>='0' && cadena[i]<='9'));

		if (cadena[i]=='\0' && cadena[0]!='\0')
		{
			ret=1;
		}
	}

	return ret;
}




