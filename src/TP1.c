/*
 ============================================================================
 Name        : TP1.c
 Author      : Alejandro Bongioanni
 Version     :
 Copyright   : Your copyright notice
 Description : TP1 Calculadora
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "calculos.h"




int main(void)
{
	int i=0;
	int option;
	int checkImput=0;
	int operadorX;
	int operadorY;
	int resSuma;
	int resResta;
	float resDiv;
	int resMulti;
	double resFactor1;
	double resFactor2;
	int chkResDiv;
	int chkResFact;



	setbuf(stdout, NULL);
	do
	{
		if(menu(operadorX, operadorY, checkImput) && utn_getNumero(&option,"Elija una opcion\n","Error debe ser entre 1 y 5\n",1,5,3))
		{

			switch(option)
			{
			case 1:
				{
					system("CLS()");
					if(utn_getNumero(&operadorX,"Ingrese el numero (X)\n","Error debe ser entre 0 y 9999\n", 0,9999,3))
					{
						if(checkImput==option||checkImput==0)
						{
							checkImput=1;
						}
						else
						{checkImput=3;}
					}
				break;
				}
			case 2:
				{
					system("CLS()");
					if(utn_getNumero(&operadorY,"Ingrese el numero (Y)\n","Error debe ser entre 0 y 9999\n", 0,9999,3))
					{

						if(checkImput==option||checkImput==0)
						{
							checkImput=2;
						}
						else
						{checkImput=3;}
					}
				break;
				}

			case 3:
				{
					if(getCalculos(operadorX, operadorY, checkImput, &resSuma, &resResta, &resMulti, &resDiv, &chkResDiv, &resFactor1, &resFactor2,&chkResFact))
					{
						checkImput=4;
						printf("Se realizaron los calculos para las variables ingresadas\n");
					}
					else
					{printf("Resta ingresar operadores\n");}
					break;
				}
			case 4:
				{
					imprimeResultados(operadorX, operadorY, checkImput, resSuma, resResta, resMulti, resDiv, chkResDiv, resFactor1, resFactor2, chkResFact);
					break;
				}
			}

			i++;
		}
		else
		{
			printf("Supero el maximo de posibilidades\n\n\n");
			break;
		}
	system("\n\n\nPAUSE()\n");
	system("CLS()");


	}while (option!=5);

	system("\n\n\nPAUSE()");
	return 0;
}






