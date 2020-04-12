/*
 ============================================================================
 Name        : Clase5-Ej1.c
 Author      : Alejandro Bongioanni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define QTY_EMPLEADOS 3

int imprimirArrayInt(int pArray[],int size);
int ordenar(int pArrayE[], int pArrayS[],int size, char opcion);
int swap(int pArray[], int pos);

int main(void)
{
	int arrayEdades[QTY_EMPLEADOS];
	int arraySalarios[QTY_EMPLEADOS];
	int i;
	int bufferEdad;
	int bufferSalario;
	int respuestaE;
	int respuestaS;
	int respuesta;
	int opcion;
	int op_Ord;

	for(i = 0; i < QTY_EMPLEADOS; i++)
	{
		respuestaE = utn_getNumero(&bufferEdad, "Edad?\n","Error tiene que ser de 18 a 65\n",18,65,2);
		respuestaS = utn_getNumero(&bufferSalario, "Salario?\n","Error tiene que ser de 1000 a 100000\n",1000,100000,2);
		if(respuestaE == 1 && respuestaS == 1)
		{
			arrayEdades[i] = bufferEdad;
			arraySalarios[i] = bufferSalario;
		}
	}

	do
	{
		respuesta = utn_getNumero(&opcion, "1-Modificar Edad\n2-Modificar Salario\n3-Mostrar\n4-Ordenar\n6-Salir\n","Error tiene que ser de 1 a 6\n",1,6,2);
		if(respuesta == 1)
		{
			switch(opcion)
			{
				case 1:
					respuesta = utn_getNumero(&i, "Indice de la Edad?\n","Error indice fuera de rango\n",0,QTY_EMPLEADOS,2);
					respuestaE = utn_getNumero(&bufferEdad, "Edad?\n","Error tiene que ser de 18 a 65\n",18,65,2);
					if(respuestaE == 1 && respuesta == 1)
					{
						arrayEdades[i] = bufferEdad;

					}
					break;
				case 2:
					respuesta = utn_getNumero(&i, "Indice del salario?\n","Error indice fuera de rango\n",0,QTY_EMPLEADOS,2);
					respuestaS = utn_getNumero(&bufferSalario, "Salario?\n","Error tiene que ser de 1000 a 100000\n",1000,100000,2);
					if(respuestaS == 1 && respuesta == 1)
					{
						arraySalarios[i] = bufferSalario;
					}

					break;
				case 3:
					imprimirArrayInt(arrayEdades,QTY_EMPLEADOS);
					imprimirArrayInt(arraySalarios,QTY_EMPLEADOS);

					break;
				case 4:

					utn_getNumero(&op_Ord,"\nPorque desea ordenar Edad [1] o Salario [2]?","\nVerifique la letra ingresada",1,2,2);
					if(ordenar(arrayEdades, arraySalarios,QTY_EMPLEADOS,op_Ord) == 0)
					{
						printf("\nSIIIIIII ordeno");

					}
					break;

			}
		}
		system("PAUSE()");
	}while(opcion != 6);

	return EXIT_SUCCESS;

}


int ordenar(int pArrayE[], int pArrayS[],int size, char opcion)
{
	int flagSwap=1;
	int i;
	int cont=0;
	int retorno = -1;
	switch (opcion)
	{

	case 1:
		{
			if(pArrayE != NULL && size > 0)
			{
				while(flagSwap)
				{
					cont++;
					flagSwap = 0;
					for(i = 0 ; i < size-cont ; i++)
					{
						if(pArrayE[i] > pArrayE[i+1])
						{
							flagSwap = 1;
							swap(pArrayE, i);
							swap(pArrayS, i);
						}
					}
				}
		retorno = 0;
			}
			break;
		}

	case 2:
			{
				if(pArrayS != NULL && size > 0)
				{
					while(flagSwap)
					{
						flagSwap = 0;
						for(i = 0 ; i < size-1 ; i++)
						{
							if(pArrayS[i] > pArrayS[i+1])
							{
								flagSwap = 1;
								swap(pArrayS, i);
								swap(pArrayE, i);
							}
						}
					}
			retorno = 0;
				}
				break;
			}
	}
	return retorno;
}


int imprimirArrayInt(int pArray[],int size)
{
	int i;
	int retorno=-1;
	if(pArray != NULL && size > 0)
	{
		for(i = 0; i < size; i++)
		{
			printf("El indice [%d] tiene como valor %d\n", i, pArray[i]);
		}
		retorno=0;
	}

	return retorno;
}

int swap(int pArray[], int pos)
{
int buffer;



	buffer = pArray[pos];
	pArray[pos] = pArray[pos+1];
	pArray[pos+1] = buffer;



return 1;
}
