/*
 * utn.c
 *
 *  Created on: 10 abr. 2020
 *      Author: aleja
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



static int getInt(int* pResultado);
static int esNumerica(char* cadena);
/**
 * brief realiza la validacion del ingreso de numeros enteros esbalenciendo un rango de posibilidades
 * param pMensaje es el mensaje que se va a mostrar antes de solicitar el ingreso
 * param pMensajeError es el mensaje de error que se va a informar en caso que el ingreso no cumpla las condiciones
 * param minimo es donde se debera establecer el numero minimo permitido a ingresar
 * param maximo es donde se debera establecer el numero maximo permitido a ingresar
 * param reintentos es la cantidad de reintentos que se le va a birndar al usuario en caso de error
 * *pNumero devolvera por puntero el numero ingresado
 * return 1 en caso exitoso
 */
int utn_getNumero(int* pNumero, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos)
{
int ret=0;
int ingreso;
if (pNumero!= NULL && pMensaje != NULL && pMensajeError != NULL && maximo >= minimo && reintentos >=0 )
{
	do
	{
		printf(pMensaje);
		if(getInt(&ingreso))
		{

			if(ingreso<minimo || ingreso>maximo)
			{
				fflush(stdin);
				printf(pMensajeError, reintentos);
				reintentos--;
			}
		}
		else
		{
			printf(pMensajeError,reintentos);
			reintentos--;
		}


	}while (reintentos>=0 && (ingreso<minimo || ingreso>maximo));

	if (reintentos>=0)
	{

		ret=1;
		*pNumero=ingreso;
	}

}
else
{

	ret=0;
	printf(pMensajeError, reintentos);
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
		*pResultado=atol(buffer);
		ret=1;
	}

}

return ret;
}

static int esNumerica(char* cadena)
{
int ret=0;
int i=0;
if(cadena!=NULL)
{
	while(cadena[i]!='\0')
	{
		if(!(isdigit(cadena[i])) && (cadena[i]!='-'))
		{
			break;
		}
		else if ((cadena[i]=='-' && i!=0)||(cadena[0]=='-' && cadena[1]=='0' && strlen(cadena)==2))
		{break;}
		i++;
	}
	if(cadena[i]=='\0' && cadena[0]!='\0')
	{ret=1;}
}

return ret;
}
/**
 * brief realiza la validacion del ingreso de numeros flotantes positivos y negativos, esbalenciendo un rango de posibilidades
 * param pMensaje es el mensaje que se va a mostrar antes de solicitar el ingreso
 * param pMensajeError es el mensaje de error que se va a informar en caso que el ingreso no cumpla las condiciones
 * param minimo es donde se debera establecer el numero minimo permitido a ingresar
 * param maximo es donde se debera establecer el numero maximo permitido a ingresar
 * param reintentos es la cantidad de reintentos que se le va a birndar al usuario en caso de error
 * *pNumero devolvera por puntero el numero ingresado
 * return 1 en caso exitoso
 */
static int getFloat(float* pResultado);
static int esNumeroDecimal(char* cadena);
int utn_getNumeroConDecimales(float* pNumero, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos)
{
int ret=0;
float ingreso;
if (pNumero!= NULL && pMensaje != NULL && pMensajeError != NULL && maximo >= minimo && reintentos >=0 )
{
	do
	{
		printf(pMensaje);
		if(getFloat(&ingreso))
		{
			if(ingreso<minimo || ingreso>maximo)
			{
				fflush(stdin);
				printf(pMensajeError, reintentos);
				reintentos--;
			}
		}
		else
		{
			printf(pMensajeError,reintentos);
			reintentos--;
		}


	}while (reintentos>=0 && (ingreso<minimo || ingreso>maximo));

	if (reintentos>=0)
	{
		ret=1;
		*pNumero=ingreso;
	}
}
else
{
	printf(pMensajeError, reintentos);
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

		if(!(isdigit(cadena[i])) && (cadena[i]!='.') && (cadena[i]!='-'))
		{
			break;
		}
		else if ((cadena[i]=='-' && i!=0)||(cadena[0]=='-' && cadena[1]=='0' && strlen(cadena)==2))
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
/**
 * brief realiza la validacion del ingreso cadenas de texto con las contenmplando espacios en la misma
 * param pMensaje es el mensaje que se va a mostrar antes de solicitar el ingreso
 * param pMensajeError es el mensaje de error que se va a informar en caso que el ingreso no cumpla las condiciones
 * param reintentos es la cantidad de reintentos que se le va a birndar al usuario en caso de error
 * param size es el tamaño que se la va a signar a dicha cadena de texto
 * *pIngreso devolvera por puntero el texto ingresado
 * return 1 en caso exitoso
 */
static int getString(char* pTexto);
int utn_getTexto(char* pIngreso, char* pMensaje, char* pMensajeError, int reintentos, int size)
{
int ret=0;
char bufferIng[size];

if (pIngreso!=NULL && pMensaje!=NULL && pMensajeError!=NULL && reintentos>=0)
{
	do
	{
		fflush(stdin);
		printf(pMensaje);
		fgets(bufferIng,sizeof(bufferIng),stdin);
		bufferIng[strlen(bufferIng)-1]='\0';
		if(getString (bufferIng))
		{

			break;
		}
		else
		{
			printf(pMensajeError, reintentos);
			reintentos--;

		}

	}while(reintentos>=0);
	if (reintentos>=0)
	{
		strcpy(pIngreso,bufferIng);
		ret=1;
	}



}
return ret;
}
static int getString(char* pTexto)
{
int ret=0;
int i=0;
int contEspacios=0;

if(pTexto!=NULL)
{

	while(pTexto[i]!='\0')
	{
		if(isalpha(pTexto[i])||pTexto[i]==' ')
		{
			if(pTexto[i]==' ')
			{contEspacios++;}
			i++;
		}
		else
		{break;}
	}
	if(pTexto[i]=='\0' && pTexto[0]!='\0' && contEspacios !=i)
	{ret=1;}
}
return ret;
}
/**
 * brief realiza la validacion del ingreso de caracteres
 * param pMensaje es el mensaje que se va a mostrar antes de solicitar el ingreso
 * param pMensajeError es el mensaje de error que se va a informar en caso que el ingreso no cumpla las condiciones
 * param pRango es la cadena de caracteres sobre la cual se va a calidar el ingreso, debera de ingresarse '\0' para indicar el final de la cadena
 * param reintentos es la cantidad de reintentos que se le va a birndar al usuario en caso de error
 * *pCaracter devolvera por puntero el caracter ingresado
 * return 1 en caso exitoso
 */
int buscaChar(char* caracter,char* pArrayAbuscar, int size);
int utn_getCaracter(char* pCaracter, char* pMensaje, char* pMensajeError,char* pRango, int reintentos)
{
int ret=0;
int size=strlen(pRango);
int flagC=0;
char bufferIng[10];
if (pCaracter!=NULL && pMensaje!=NULL && pMensajeError!=NULL && pRango!=NULL && size>0 && reintentos>=0)
{

	do
	{


		printf(pMensaje);
		fflush(stdin);
		fgets(bufferIng,sizeof(bufferIng),stdin);
		bufferIng[strlen(bufferIng)-1]='\0';

		if(strlen(bufferIng)==1)
		{
			if(buscaChar(bufferIng,pRango,size))
			{
				flagC=1;
				break;
			}

			else
			{
				printf(pMensajeError, reintentos);
				reintentos--;
			}
		}
		else
		{

			printf("Ingreso mas de un caracter, quedan %d reintentos\n", reintentos);
			reintentos--;
		}
	}while(reintentos>=0);


	if (reintentos>=0 && flagC==1)
	{
		strcpy(pCaracter,bufferIng);
		ret=1;
	}



}
return ret;
}


int buscaChar(char* caracter,char* pArrayAbuscar, int size)
{
int ret=0;
int i=0;
int j;
if(caracter!=NULL && pArrayAbuscar!=NULL && size>0 )
{

	while(pArrayAbuscar[i]!='\0')
	{
		for (j=0; j<size;j++)
		{
			if(pArrayAbuscar[i]==caracter[j])
			{ret=1;
			break;
			}
		}
		i++;
	}

}

return ret;
}

/**
 * brief realiza la validacion del ingreso de Fecha
 * param pDia es el puntero del dia de la fecha que retoranara
 * param pMes es el puntero del mes de la fecha que retoranara
 * param pAnio es el puntero del año de la fecha que retoranara
 * param pMensaje es el mensaje que se va a mostrar antes de solicitar el ingreso
 * param pMensajeError es el mensaje de error que se va a informar en caso que el ingreso no cumpla las condiciones
 * param minDia es el valor minimo de numero de dia a permitir el ingreso
 * param minMes es el valor minimo de numero de mes a permitir el ingreso
 * param minAnio es el valor minimo de numero de año a permitir el ingreso
 * param maxDia es el valor maximo de numero de dia a permitir el ingreso
 * param maxMes es el valor maximo de numero de mes a permitir el ingreso
 * param maxAnio es el valor maximo de numero de año a permitir el ingreso
 * param reintentos es la cantidad de reintentos que se le va a birndar al usuario en caso de error
 * return 1 en caso exitoso
 */

static int getIntFecha(int* pDia, int* pMes, int* pAnio);
int utn_getFecha(int* pDia,int* pMes, int* pAnio , char* pMensaje, char* pMensajeError, int minDia, int maxDia, int minMes, int maxMes,int minAnio, int maxAnio, int reintentos)
{
int ret=0;
int dia;
int mes;
int anio;
if (pDia!= NULL && pMes!= NULL && pAnio!= NULL && pMensaje != NULL && pMensajeError != NULL && maxDia >= minDia && maxMes >= minMes && maxAnio >= minAnio && reintentos >=0 )
{
	do
	{
		printf(pMensaje);
		fflush(stdin);
		if(getIntFecha(&dia, &mes, &anio))
		{

			if((dia<minDia || dia>maxDia)  || (mes<minMes || mes>maxMes) || (anio<minAnio || anio>maxAnio))
			{

				printf(pMensajeError, reintentos);
				reintentos--;
			}
		}
		else
		{

			printf(pMensajeError,reintentos);
			reintentos--;
		}


	}while (reintentos>=0 && ((dia<minDia || dia>maxDia)  || (mes<minMes || mes>maxMes) || (anio<minAnio || anio>maxAnio)));

	if (reintentos>=0)
	{

		ret=1;
		*pDia=dia;
		*pMes=mes;
		*pAnio=anio;
	}

}
else
{

	ret=0;
	printf(pMensajeError, reintentos);
}

return ret;
}

static int esFecha(char* cadena);
static int validaFecha(int dia,int mes,int anio);
static int getIntFecha(int* pDia,int* pMes,int* pAnio)
{
int ret=0;
int dia;
int mes;
int anio;
char cDia[10];
char cMes[10];
char cAnio[10];
char fecha[20];

if (pDia!= NULL && pMes!=NULL && pAnio!=NULL)
{

	scanf("%d/%d/%d",&dia,&mes,&anio);
	fflush(stdin);
	strcpy(fecha,itoa(dia,cDia,10));
	strcat(fecha,itoa(mes,cMes,10));
	strcat(fecha,itoa(anio,cAnio,10));

	if(esFecha(fecha))
	{

		if(validaFecha(dia,mes,anio))
		{

			*pDia=dia;
			*pMes=mes;
			*pAnio=anio;
			ret=1;
		}
	}

}

return ret;
}

static int validaFecha(int dia, int mes, int anio)
{
int ret=0;
int chkDia;


if(dia>0 && mes>0 && anio>0)
{
	switch(mes)
	{
		case 2:
		{
			if((anio%4)==0)
			{
				chkDia=29;
			}
			else
			{
				chkDia=28;
			}
			break;
		}
		case 4:
		case 6:
		case 9:
		case 11:
			{
				chkDia=30;
				break;
			}
		default:
		{
				chkDia=31;
				break;
		}

	}

	if (dia<=chkDia)
	{
		ret=1;
	}

}

return ret;
}

static int esFecha(char* cadena)
{
int ret=0;
int i=0;
if(cadena!=NULL)
{
	while(cadena[i]!='\0')
	{
		if(!(isdigit(cadena[i])) && (cadena[i]!='/'))
		{
			break;
		}
		else if ((cadena[i]=='/' && (i!=2 || i!=5)))
		{break;}
		i++;
	}
	if(cadena[i]=='\0' && cadena[0]!='\0')
	{ret=1;}
}

return ret;
}



/**
 * brief realiza la validacion del ingreso de un CUIL en una cadena de texto
 * param pMensaje es el mensaje que se va a mostrar antes de solicitar el ingreso
 * param pMensajeError es el mensaje de error que se va a informar en caso que el ingreso no cumpla las condiciones
 * param reintentos es la cantidad de reintentos que se le va a birndar al usuario en caso de error
 * param size es el tamaño que se la va a signar a dicha cadena de texto
 * *pIngreso devolvera por puntero el CUIL ingresado
 * return 1 en caso exitoso
 */
static int getCadena(char* pTexto);
int utn_getCuil(char* pIngreso, char* pMensaje, char* pMensajeError, int reintentos, int size)
{
int ret=0;
char bufferIng[size];

if (pIngreso!=NULL && pMensaje!=NULL && pMensajeError!=NULL && reintentos>=0)
{
	do
	{
		fflush(stdin);
		printf(pMensaje);
		fgets(bufferIng,sizeof(bufferIng),stdin);
		bufferIng[strlen(bufferIng)-1]='\0';
		if(getCadena (bufferIng))
		{

			break;
		}
		else
		{
			printf(pMensajeError, reintentos);
			reintentos--;

		}

	}while(reintentos>=0);
	if (reintentos>=0)
	{
		strcpy(pIngreso,bufferIng);
		ret=1;
	}



}
return ret;
}
static int getCadena(char* pTexto)
{
int ret=0;
int i=0;
int contGuion=0;
int largo =strlen(pTexto);

if(pTexto!=NULL && largo==13)
{

	while(pTexto[i]!='\0')
	{
		if(isdigit(pTexto[i])||pTexto[i]=='-')
		{
			if(pTexto[i]=='-')
			{
				if(i!=2 && i !=11)
				{
					break;
				}
				else
				{
					contGuion++;
				}
			}

			i++;
		}
		else
		{break;}
	}
	if(pTexto[i]=='\0' && contGuion==2)
	{ret=1;}
}
return ret;
}




