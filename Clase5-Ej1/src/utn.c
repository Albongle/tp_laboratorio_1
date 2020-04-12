/*
 * utn.c
 *
 *  Created on: 2 abr. 2020
 *      Author: aleja
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//string
static int getString(char caracter);
int utn_getTexto(char pTexto[], char* mensaje, char *mensajeError, int reintentos, int size)
{
	system("CLS()");
		setbuf(stdout,NULL);

		 int ret=-1;
		 int i;
		 int cont;
		 char ingreso[size];
		 if (pTexto != NULL && mensaje!= NULL && mensajeError != NULL && reintentos >=0 && size>0)
		 {
			 do
			 {

				 printf("%s",mensaje);
				 fflush(stdin);// limpio buffer
				 fgets(ingreso,size,stdin);
				 ingreso[strlen(ingreso)-1]='\0'; //strlen longitud del array
				 i=0;
				 cont=0;
				 while (ingreso[i]!='\0' && strlen(ingreso)>0)
				 {

					 if (getString(ingreso[i])==1)
					 {cont++;}
					 i++;
				 }

				 if(cont==strlen(ingreso) && cont >0)
				 {break;}

				 reintentos--;
				 printf("%s",mensajeError);

			 	}while(reintentos>=0);

			 if(reintentos>=0)
			 {
				 strncpy( pTexto,ingreso,  size); //copia el texto de  un array a otro
				 ret=1;
			 }

		 }
		return ret;

}


static int getString(char caracter)
{
	int ret=-1;
	if (((caracter>='A' && caracter<='Z') || (caracter>='a' && caracter<='z')))
	{
		ret=1;
	}

	return ret;
}

//fin string


// inicio numero entero
static int getInt(int* pResultado);
static int esNumerica(char* cadena);

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	system("CLS()");
	setbuf(stdout,NULL);

	 int ret=-1;
	 int num;
	 if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	 {
		 do
		 {
			 printf("%s",mensaje);
			 if (getInt(&num)==1) //si getInt=1 puedo escribir la variable
			 {
				 if(num<=maximo && num>=minimo)
				 {break;}
			 }
			 fflush(stdin);// limpio buffer

			 reintentos--;
			 printf("%s",mensajeError);

		 }while(reintentos>=0);

		 if(reintentos>=0)
		 {
			 ret=1;
			 *pResultado = num;
		 }




	 }

return ret;


}

static int getInt(int* pResultado)
{
	int ret=-1;
	char buffer[64]; //buffer ingreso por teclado hasta 64 caracteres
	fgets(buffer,sizeof(buffer),stdin); //sizeof tamaño del ingreso, podia haber usado srtlen?
	buffer[strlen(buffer)-1]='\0'; //strlen longitud del array
	if(esNumerica(buffer)==1) //tuve que cambiar para que valide todos los caracteres
	{
		*pResultado = atoi(buffer); //ASCII to Integer
		ret=1;
	}
	return ret;
}


static int esNumerica(char* cadena)
{
	int ret=-1;
	int i=0;
	if(cadena!=NULL)
	{
		while(cadena[i]!='\0')
		{
			if(cadena[i]<'0' || cadena[i]>'9')
				{break;}
			i++;
		}
		if(cadena[i]=='\0')
		{ret=1;}
	}
return ret;
}
//fin numero entero

//inicio numero con decimales

static int getFloat(float* pResultado);
static int esNumeroDecimal(char* cadena);

int utn_getNumeroConDecimales(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	system("CLS()");
	setbuf(stdout,NULL);

	 int ret=-1;
	 float num;
	 if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	 {
		 do
		 {
			 printf("%s",mensaje);
			 if (getFloat(&num)==1) //si getInt=1 puedo escribir la variable
			 {
				 if(num<=maximo && num>=minimo)
				 {break;}
			 }
			 fflush(stdin);// limpio buffer

			 reintentos--;
			 printf("%s",mensajeError);

		 }while(reintentos>=0);

		 if(reintentos>=0)
		 {
			 ret=1;
			 *pResultado = num;
		 }

	 }
	 return ret;
}

static int getFloat(float* pResultado)
{
	int ret=-1;
	char ingreso[64]; //buffer ingreso por teclado hasta 64 caracteres
	fgets(ingreso,sizeof(ingreso),stdin); //sizeof tamaño del ingreso, podia haber usado srtlen?
	ingreso[strlen(ingreso)-1]='\0'; //strlen longitud del array
	if(esNumeroDecimal(ingreso)==1) //tuve que cambiar para que valide todos los caracteres
	{
		*pResultado = atof(ingreso);//ASCII to Float


		ret=1;
	}
	return ret;
}

static int esNumeroDecimal(char* cadena)
{
	int ret=-1;
	int i=0;
	if(cadena!=NULL)
	{
		while(cadena[i]!='\0')
		{
			if((cadena[i]<'0' || cadena[i]>'9') && (cadena[i]!='.'))
				{break;}
			i++;
		}
		if(cadena[i]=='\0')
		{ret=1;}
	}
return ret;
}

//FIN numero con decimales


int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, char minimo,char maximo,int reintentos)
{
	int retorno = -1;
	char ingreso;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%c",&ingreso);
			if(ingreso >= minimo && ingreso <= maximo)
			{
				*pResultado = ingreso;
				retorno = 0;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos>=0);

	}
	return retorno;
}


