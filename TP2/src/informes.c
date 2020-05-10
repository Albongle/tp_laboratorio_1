/*
 * informes.c
 *
 *  Created on: 4 may. 2020
 *      Author: aleja
 */
#include <stdio.h>
#include <stdlib.h>
#include "sector.h"
#include "empleados.h"


static double totalSalario(eEmpleados* pArrayEmpleados,int tamArrayEmpleados, int* qEmpleados);
static int qEmpleadoSuperanProm(eEmpleados* pArrayEmpleados,int tamArrayEmpleados, float promSalario);

void empleadosOrdenados(eEmpleados* pArrayEmpleados,int tamArrayEmpleados,eSector* pArraySectores, int tamArraySectores, char sentido)
{
if(pArrayEmpleados!=NULL && tamArrayEmpleados>0 && pArraySectores!=NULL && tamArraySectores>0 && sentido!=' ')
{
	ordenaEmpleados(pArrayEmpleados,tamArrayEmpleados,pArraySectores,tamArraySectores,'>');
	imprimeEmpleados(pArrayEmpleados,tamArrayEmpleados,pArraySectores,tamArraySectores);
}
}

void totYpromSalario(eEmpleados* pArrayEmpleados,int tamArrayEmpleados)
{
double totSalario;
int qEmpleados;
float promSalario;
int qEmpMaxSalarioPromedio;


totSalario=totalSalario(pArrayEmpleados,tamArrayEmpleados,&qEmpleados);
if(qEmpleados>0)
{
	promSalario=totSalario/qEmpleados;
}

qEmpMaxSalarioPromedio=qEmpleadoSuperanProm(pArrayEmpleados,tamArrayEmpleados,promSalario);

printf("El total de salarios es: %.2lf\n", totSalario);
printf("El promedio de salarios es: %.2f\n", promSalario);
printf("%d empleados superan el promedio de salarios\n",qEmpMaxSalarioPromedio);
}


static int qEmpleadoSuperanProm(eEmpleados* pArrayEmpleados,int tamArrayEmpleados, float promSalario)
{
int resultado=0;
int i;

if(pArrayEmpleados!=NULL && tamArrayEmpleados>0 && promSalario>0)
{
	for(i=0; i<tamArrayEmpleados; i++)
	{
		if(pArrayEmpleados[i].isEmpty==0 && pArrayEmpleados[i].sueldo>promSalario)
			{
				resultado++;
			}

	}

}

return resultado;
}

static double totalSalario(eEmpleados* pArrayEmpleados,int tamArrayEmpleados,int* qEmpleados)
{
double resultado=0;
int i;
int cont=0;
if(pArrayEmpleados!=NULL && tamArrayEmpleados>0)
{
	for(i=0;i<tamArrayEmpleados;i++)
	{
		if(pArrayEmpleados[i].isEmpty==0)
		{
			resultado+=pArrayEmpleados[i].sueldo;
			cont++;
		}
	}
	*qEmpleados=cont;
}

return resultado;
}

