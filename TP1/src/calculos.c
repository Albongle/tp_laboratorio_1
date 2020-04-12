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
int menu(float ingresoA, float ingresoB, int check)
{


switch(check)
	{
	case 0:
			{
				printf("1-Ingrese el primer operador(X)\n2-Ingrese el segundo operador(Y)\n3-Calcular todas las operaciones\n4-Informar resultado\n5-Salir\n");
				break;
			}
	case 1:
			{
				printf("1-Ingrese el primer operador(%.2f)\n2-Ingrese el segundo operador(Y)\n3-Calcular todas las operaciones\n4-Informar resultado\n5-Salir\n", ingresoA);
				break;
			}

	case 2:
			{
				printf("1-Ingrese el primer operador(X)\n2-Ingrese el segundo operador(%.2f)\n3-Calcular todas las operaciones\n4-Informar resultado\n5-Salir\n", ingresoB);
				break;
			}

	default:
			{
				printf("1-Ingrese el primer operador(%.2f)\n2-Ingrese el segundo operador(%.2f)\n3-Calcular todas las operaciones\n4-Informar resultado\n5-Salir\n",ingresoA, ingresoB);
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



static int getFactorial(double* factor1, double* factor2,float num1,float num2);
static int getMulti(float* multi,float num1,float num2);
static int getDiv(float* div,float num1,float num2);
static int getResta(float* resta,float num1,float num2);
static int getSuma(float* suma,float num1,float num2);
int getCalculos(float num1, float num2, int check, float* pResSuma, float* pResResta, float* pResMulti, float* pResDiv, int* chkDiv, double* pResFactA,double* pResFactB, int* chkFact)
{
int ret=0;
float suma;
float resta;
float div;
float multi;
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
 * Deveuelve por puntero el resultado de la suma
 */
static int getSuma(float* suma,float num1,float num2)
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
 * Deveuelve por puntero el resultado de la resta
 */
static int getResta(float* resta,float num1,float num2)
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
 * Deveuelve por puntero el resultado de la division
 * Retornara 1 en caso que se haya podido realizar la division, 0 si el divisor es igual a cero
 */
static int getDiv(float* div,float num1,float num2)
{
	int ret=0;
	if(div!=NULL && num2!=0)
	{
		*div=num1/num2;
		ret=1;
	}
return ret;
}

/**
 * Realiza la multiplicacion entre 2 numeros
 * Deveuelve por puntero el resultado de la multiplicacion
 */
static int getMulti(float* multi,float num1,float num2)
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
 * Devuleve por puntero los resultados de la operacion
 * Retornara 1 o 2 de acuerdo al numero que haya podido factoreado o 3 encaso de hacerlo con ambos.
 */
static int getFactorial(double* factor1, double* factor2,float num1,float num2)
{
	int ret=0;
	int i;
	double resultF1=0;
	double resultF2=0;
	float chkNum1;
	float chkNum2;



	chkNum1=(int)num1;
	chkNum1=num1-chkNum1;
	chkNum2=(int)num2;
	chkNum2=num2-chkNum2;

	if(factor1!=NULL && num1>0 && chkNum1<=0 )
	{
		resultF1=1;

		for(i=num1; i>0; i--)
		{
			resultF1=resultF1*(double)i;

		}
		*factor1=resultF1;
		ret=1;
	}

	if(factor2!=NULL && num2>0  && chkNum2<=0)
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
 * que permite tomar decisiones al momento de impirmi.
 * Estos ultimos van a ser utiizados para evaluar el formato a presente el factorial
 */
static int validaFctorial (char* mensaje, int ingreso, double resultado);
int imprimeResultados(float num1, float num2, int check, float resSuma, float resResta, float resMulti, float resDiv, int chkResDiv, double resFactor1, double resFactor2,int chkResFact)
{
	int ret=0;
	if(check>=4)
	{
		printf("El resultado de la suma es: %.2f\n", resSuma);
		printf("El resultado de la resta es: %.2f\n", resResta);
		if(chkResDiv>0)
		{
			printf("El resultado de la division es: %.2f\n", resDiv);
		}
		else
		{
			printf("No es posible dividir por 0 (cero)\n");
		}
		printf("El resultado de la multiplicacion: %.2f\n", resMulti);

		switch(chkResFact)
				{
					case 1:
					{
						validaFctorial ("El factorial del entero de (X) es:", num1, resFactor1 );
						printf("No se pudo hacer el factorial de (Y) ya que su ingreso fue %.2f, debe ser entero y mayor a 0 (cero)\n", num2);
						break;
					}
					case 2:
					{
						printf("No se pudo hacer el factorial de (X) ya que su ingreso fue %.2f, debe ser entero y mayor a 0 (cero)\n", num1);
						validaFctorial ("El factorial del entero de (Y) es:", num2, resFactor2 );
						break;
					}

					case 3:
					{
						validaFctorial ("El factorial del entero de (X) es:", num1, resFactor1 );
						validaFctorial ("El factorial del entero de (Y) es:", num2, resFactor2 );
						break;
					}
					default :
					{
						printf("No se pudo hacer el factorial de (X) ya que su ingreso fue %.2f, debe ser entero y mayor a 0 (cero)\n", num1);
						printf("No se pudo hacer el factorial de (Y) ya que su ingreso fue %.2f, debe ser entero y mayor a 0 (cero)\n", num2);
						break;
					}

				}
		ret=1;
	}

return ret;
}

/**
 * Funcion utilizada para determinar el formato a impirmir el resultado del factorial
 * Recibe el mensaje y resultado a mostrar y valida de acuerdo al numero ingresado inicialmente.
 *
 */
static int validaFctorial (char* mensaje, int ingreso, double resultado)
{
	int ret=0;
	if (ingreso>0)
	{

		if(ingreso>20)
		{
			printf("%s %E\n",mensaje, resultado);

		}
		else
		{
			printf("%s %.0lf\n",mensaje, resultado);
		}


		ret=1;
	}

	return ret;
}

