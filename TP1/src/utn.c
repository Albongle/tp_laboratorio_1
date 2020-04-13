/*
 * utn.c
 *
 *  Created on: 10 abr. 2020
 *      Author: aleja
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Funcion para el ingreso de numeros enteros
 * solicita un numero al usuario y devuelve este por puntero en caso que se haya podido comprobar
 * que no posee caracteres adicionales y no sea vacia
 * Retorna 1 en caso exitoso
 */


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
					printf(mensajeError, reintentos);
					reintentos--;
				}
			}
			else
			{
				printf(mensajeError,reintentos);
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
		printf(mensajeError, reintentos);
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


//inicio numero con decimales, positivo o negativo

/**
 * Funcion para el ingreso de numeros con decimales, positivos o negativos
 * solicita un numero al usuario y devuelve este por puntero en caso que se haya podido comprobar
 * que la misma no sea vacia, no tenga mas de un '.' y el signo negativo solo se encuentre en la 1er posisicion
 * Retorna 1 en caso exitoso
 */

static int getFloat(float* pResultado);
static int esNumeroDecimal(char* cadena);

int utn_getNumeroConDecimales(float* numero, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{

		int ret=0;
		float ingreso;
		if (numero!= NULL && mensaje != NULL && mensajeError != NULL && maximo >= minimo && reintentos >=0 )
		{
			do
			{
				printf(mensaje);
				if(getFloat(&ingreso))
				{
					if(ingreso<minimo || ingreso>maximo)
					{
						fflush(stdin);
						printf(mensajeError, reintentos);
						reintentos--;
					}
				}
				else
				{
					printf(mensajeError,reintentos);
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
			printf(mensajeError, reintentos);
		}

		return ret;
}

static int getFloat(float* pResultado)
{
	int ret=0;
	char ingreso[64];
	fgets(ingreso,sizeof(ingreso),stdin);
	ingreso[strlen(ingreso)-1]='\0';
	if(esNumeroDecimal(ingreso))
	{
		*pResultado = atof(ingreso);


		ret=1;
	}
	return ret;
}

static int esNumeroDecimal(char* cadena)
{
	int ret=0;
	int i=0;
	int controlP=0;
	if(cadena!=NULL && cadena[0]!='.' && cadena[strlen(cadena)-1]!='.')
	{
		while(cadena[i]!='\0')
		{

			if((cadena[i]<'0' || cadena[i]>'9') && ((cadena[i]!='.') && (cadena[i]!='-')))
			{
				break;
			}
			else if (cadena[i]=='-' && i!=0)
			{break;}

			else if(cadena[i]=='.')
			{
				controlP++;
			}

			i++;
		}
		if(cadena[i]=='\0' && cadena[0]!='\0' && controlP<=1)
		{ret=1;}
	}

return ret;
}

//FIN numero con decimales




