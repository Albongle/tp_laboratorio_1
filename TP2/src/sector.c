/*
 * sector.c
 *
 *  Created on: 3 may. 2020
 *      Author: aleja
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "empleados.h"
#include "sector.h"



void mostrarSectores(eSector* pArraySectores, int tam)
{
	int i;
	printf("ID          Descripcion\n");

	if(pArraySectores!=NULL && tam>=0)
		{
			for(i=0;i<tam;i++)
			{
				mostrarSector(pArraySectores[i]);
			}
		}
}

void mostrarSector(eSector pArraySectores)
{
	printf("%d          %s\n",pArraySectores.idSector, pArraySectores.descripcion);

}

int buscarSector(eSector* pArraySectores,int valorBuscado, int tamArraySectores, char* descrSector)
{
int ret=0;
int i;
if(pArraySectores!=NULL && tamArraySectores>0 )
{

	for(i=0;i<tamArraySectores;i++)
	{
		if (pArraySectores[i].idSector==valorBuscado)
		{
			strcpy(descrSector,pArraySectores[i].descripcion);
			ret=1;
			break;
		}
	}

}
return ret;
}
