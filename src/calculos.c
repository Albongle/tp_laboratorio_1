/*
 * calculos.c
 *
 *  Created on: 11 abr. 2020
 *      Author: aleja
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


/**
 * Prensenta el menu de opciones.
 * IngresoA es el operador X posible de ingresar en la opcion 1 del menu
 * IngresoB es el operador Y posible de ingresar en la opcion 2 del menu
 * check controla el ingreso al menu para determinar la opcion a mostrar
 *
 */
int menu(int ingresoA, int ingresoB, int check)
{

	//printf("control de vuelta %d\n", check); //sacar

switch(check)
	{
	case 0:
			{
				printf("1-Ingrese el primer operador(X)\n2-Ingrese el segundo operador(Y)\n3-Calcular todas las operaciones\n4-Informar resultado\n5-Salir\n");
				break;
			}
	case 1:
			{
				printf("1-Ingrese el primer operador(%d)\n2-Ingrese el segundo operador(Y)\n3-Calcular todas las operaciones\n4-Informar resultado\n5-Salir\n", ingresoA);
				break;
			}

	case 2:
			{
				printf("1-Ingrese el primer operador(X)\n2-Ingrese el segundo operador(%d)\n3-Calcular todas las operaciones\n4-Informar resultado\n5-Salir\n", ingresoB);
				break;
			}

	default:
			{
				printf("1-Ingrese el primer operador(%d)\n2-Ingrese el segundo operador(%d)\n3-Calcular todas las operaciones\n4-Informar resultado\n5-Salir\n",ingresoA, ingresoB);
				break;
			}
	}
return 1;
}



/**
 * Realiza los calculos necesarios
 * Recibe numeros de entrada y un check que valida que se haya ingresado las dos opciones antes de realizar los calculos
 * Devuelve los resultados de cada operacion matematica y para las opeaciones Factorial y Division retorna el resultado de esa operacion
 * que permite tomar consideraciones al momento de realizar la impresion de resultados
 */



static int getFactorial(double* factor1, double* factor2,int num1,int num2);
static int getMulti(int* multi,int num1,int num2);
static int getDiv(float* div,int num1,int num2);
static int getResta(int* resta,int num1,int num2);
static int getSuma(int* suma,int num1,int num2);
int getCalculos(int num1, int num2, int check, int* pResSuma, int* pResResta, int* pResMulti, float* pResDiv, int* chkDiv, double* pResFactA,double* pResFactB, int* chkFact)
{
int ret=0;
int suma;
int resta;
float div;
int multi;
double factor1;
double factor2;

if(check>=3)
{
	getSuma(&suma, num1, num2);
	*pResSuma=suma;
	getResta(&resta, num1, num2);
	*pResResta=resta;
	*chkDiv=getDiv(&div, num1, num2);
	*pResDiv=div;
	getMulti(&multi, num1, num2);
	*pResMulti=multi;
	*chkFact=getFactorial(&factor1, &factor2, num1, num2);
	*pResFactA=factor1;
	*pResFactB=factor2;
ret=1;
}
return ret;
}


/**
 * Realiza la suma entre 2 numeros
 * Deveuelve por puntero el resultado
 */
static int getSuma(int* suma,int num1,int num2)
{
	int ret=0;
	if(suma!=NULL)
	{
		*suma=num1+num2;
		ret=1;
	}
return ret;
}


/**
 * Realiza la resta entre 2 numeros
 * Deveuelve por puntero el resultado
 */
static int getResta(int* resta,int num1,int num2)
{
	int ret=0;
	if(resta!=NULL)
	{
		*resta=num1-num2;
		ret=1;
	}
return ret;
}


/**
 * Realiza la division entre 2 numeros
 * Deveuelve por puntero el resultado
 * Retornara 1 en caso que se haya podido realizar la division
 */
static int getDiv(float* div,int num1,int num2)
{
	int ret=0;
	if(div!=NULL && num2>0)
	{
		*div=(float)num1/num2;
		ret=1;
	}
return ret;
}

/**
 * Realiza la multiplicacion entre 2 numeros
 * Deveuelve por puntero el resultado
 */
static int getMulti(int* multi,int num1,int num2)
{
	int ret=0;
	if(multi!=NULL)
	{
		*multi=num1*num2;
		ret=1;
	}
return ret;
}

/**
 * Realiza el factorial de 2 numeros
 * Recibe por puntero los resultados a entregar y los numeros sobre el cual va a realizar el factorial
 * Retornara 1 o 2 de acuerdo al numero que haya factoreado o 3 encaso de hacerlo con ambos.
 */
static int getFactorial(double* factor1, double* factor2,int num1,int num2)
{
	int ret=0;
	int i;
	double resultF1=0;
	double resultF2=0;
	if(factor1!=NULL && num1>0)
	{
		resultF1=1;

		for(i=num1; i>0; i--)
		{
			resultF1=resultF1*(double)i;

		}
		*factor1=resultF1;
		ret=1;
	}

	if(factor2!=NULL && num2>0)
	{
		resultF2=1;

		for(i=num2; i>0; i--)
			{
				resultF2=resultF2*(double)i;

			}
		*factor2=resultF2;
		if (ret>0)
			{
				ret=3;
			}
			else
			{
				ret=2;
			}
	}



return ret;
}

/**
 * Imprime los resultados de cada operacion
 * Recibe tanto los resultados, las respuestas obtenidas por cada funcion de claculo asi los numeros ingresados
 * Estos ultimos van a ser utiizados para evaluar el formato a presente el factorial
 */

int imprimeResultados(int num1, int num2, int check, int resSuma, int resResta, int resMulti, float resDiv, int chkResDiv, double resFactor1, double resFactor2,int chkResFact)
{
	int ret=0;
	if(check>=4)
	{
		printf("El resultado de la suma es: %d\n", resSuma);
		printf("El resultado de la resta es: %d\n", resResta);
		if(chkResDiv>0)
		{
			printf("El resultado de la division es: %.2f\n", resDiv);
		}
		else
		{
			printf("No es posible dividir por 0 (cero)\n");
		}
		printf("El resultado de la multiplicacion: %d\n", resMulti);


		printf("check factorial %d\n",chkResFact);
		switch(chkResFact)
				{
					case 1:
					{
						if(num1>20)
						{
							printf("El factorial de (X) es: %E\n", resFactor1);
							printf("No se pudo hacer el factorial de (Y) ya que su ingreso fue %d\n", num2);

						}
						else
						{
							printf("El factorial de (X) es: %.0lf\n", resFactor1);
							printf("No se pudo hacer el factorial de (Y) ya que su ingreso fue %d\n", num2);
						}
							break;
					}
					case 2:
					{
						if(num2>20)
						{
							printf("No se pudo hacer el factorial de (X) ya que su ingreso fue %d\n", num1);
							printf("El factorial de (Y) es: %E\n", resFactor2);
						}
						else
						{
							printf("No se pudo hacer el factorial de (X) ya que su ingreso fue %d\n", num1);
							printf("El factorial de (Y) es: %.0lf\n", resFactor2);
						}
							break;
					}

					case 3:
					{
						if(num1>20 && num2>20)
						{
							printf("El factorial de (X) es: %E\n", resFactor1);
							printf("El factorial de (Y) es: %E\n", resFactor2);
						}
						else if (num1>20)
						{
							printf("El factorial de (X) es: %E\n", resFactor1);
							printf("El factorial de (Y) es: %.0lf\n", resFactor2);

						}
						else if(num2>20)
						{
							printf("El factorial de (X) es: %.0lf\n", resFactor1);
							printf("El factorial de (Y) es: %E\n", resFactor2);

						}
						else
						{
							printf("El factorial de (X) es: %.0lf\n", resFactor1);
							printf("El factorial de (Y) es: %.0lf\n", resFactor2);
						}
							break;
					}
					default :
					{
							printf("No se pudo hacer el factorial de (X) ya que su ingreso fue %d\n", num1);
							printf("No se pudo hacer el factorial de (Y) ya que su ingreso fue %d\n", num2);
							break;
					}

				}
		ret=1;
	}
	else
	{
		{printf("Resta realizar los calculos para los numeros ingresados\n");}
	}
return ret;
}

