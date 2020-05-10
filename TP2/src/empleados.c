/*
 * employees.c
 *
 *  Created on: 3 may. 2020
 *      Author: aleja
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "empleados.h"
#include "utn.h"
#include "sector.h"

static void imprimeEmpleado(eEmpleados pArrayEmpleados,eSector* pArraySectores,int tamArraySectores);
static int modifEmpleado(eEmpleados empleadoRec ,int opcion, eEmpleados* auxEmpleado, eSector* pArraySectores, int tamArraySectores);
static int buscarEmpleadoPorId(eEmpleados* pArrayEmpleados,int tam,int buscaId);
static int buscaIndice(eEmpleados* pArrayEmpleados, int tam);
static eEmpleados nuevoEmpleado(int id,char nombre[],char apellido[], float sueldo,int idsector);
static void swap(eEmpleados* pArrayEmpleados, int pos);
static int opcionesModificacion();


int hardcodearEmpleados(eEmpleados* pArrayEmpleados, int tam, int cantidad)
{

	int cont=0;
	int i;
	if(pArrayEmpleados!=NULL && tam>0 && cantidad >0)
	{
		eEmpleados listaAuxiliar[]=
		{
			{0, "The", "Negan", 30000.59,1000,0},
			{1, "Monica", "Gaztambide",35000.42,1001,0},
			{2, "Raquel", "Murillo",43000.33,1002,0},
			{3, "Rick", "Grimes",29000.09,1002,0},
			{4, "Daryl", "Dixon",30000.10,1001,0},
			{5, "Rosita", "Espinoza",29000.55,1001,0},
			{6, "Judith", "Grimes",25000.48,1002,0},
			{7, "Marty", "Byrde",22000.65,1001,0},
			{8, "Eugene", "Porter",19000.10,1000,0},
			{9, "Jacob", "Shell",38000.90,1002,0},

		};


		if (cantidad <=tam && cantidad && cantidad <11)
		{
			for(i=0; i<cantidad; i++)
			{
				pArrayEmpleados[i]=listaAuxiliar[i];
				cont++;
			}


		}
	}

return cont;
}





int altaEmpleado(eEmpleados* pArrayEmpleados, int tamArrayEmpleados, int id, eSector* pArraysectores, int tamArraysectores)
{
int indice;
int ret=0;
char bufferNombre[51];
char bufferApellido[51];
float bufferSueldo;
int bufferIdsector;


system("CLS()");
printf("*****Alta Empleado*****\n\n");
	if(pArrayEmpleados!=NULL && tamArrayEmpleados>=0 && pArraysectores!=NULL && tamArraysectores>0)
	{
			indice=buscaIndice(pArrayEmpleados,tamArrayEmpleados);

			if(indice==-1)
			{
				printf("Sistema completo, no se puede agregar mas Empleados\n\n");
				system("PAUSE()");
			}
			else
			{

					fflush(stdin);
					if(utn_getTexto(bufferNombre,"Ingrese el nombre del empleado\n","Error verifique los datos ingresados quedan %d intentos\n",3,50))
					{
						fflush(stdin);
						if(utn_getTexto(bufferApellido,"Ingrese el Apellido del empleado\n","Error verifique los datos ingresados quedan %d intentos\n",3,50))
						{
							fflush(stdin);
							if(utn_getNumeroConDecimales(&bufferSueldo,"Ingrese el sueldo del empleado\n","Error verifique los datos ingresados quedan %d intentos\n",1,9999999,3))
							{
								fflush(stdin);
								mostrarSectores(pArraysectores,tamArraysectores); //Hacer Funcion
								if(utn_getNumero(&bufferIdsector,"\nIngrese Id de sector para el empleado\n","Error verifique los datos ingresados quedan %d intentos\n",1000,1002,3))
								{
									pArrayEmpleados[indice]=nuevoEmpleado(id,bufferNombre,bufferApellido,bufferSueldo,bufferIdsector);
									ret=1;
								}
							}
						}

					}
			}
	}

return ret;
}

static int buscaIndice(eEmpleados* pArrayEmpleados, int tam)
{
int indice=-1;
int i;

if(pArrayEmpleados!=NULL && tam>0 )
{

	for(i=0;i<tam;i++)
	{
		if(pArrayEmpleados[i].isEmpty==1)
		{
			indice=i;
			break;
		}
	}
}
return indice;
}

static eEmpleados nuevoEmpleado(int id,char nombre[],char apellido[],float sueldo,int idSector)
{
	eEmpleados nuevoEmpleado;

	if(nombre != NULL && apellido !=NULL)
	{
	nuevoEmpleado.id=id;
	strcpy(nuevoEmpleado.nombre,nombre);
	strcpy(nuevoEmpleado.apellido,apellido);
	nuevoEmpleado.sueldo=sueldo;
	nuevoEmpleado.sector=idSector;
	nuevoEmpleado.isEmpty=0;
	}
return nuevoEmpleado;
}




void inicializarEmpleados(eEmpleados* pArrayEmpleados,int tam,int valorInt)
{
	int i;
	if(pArrayEmpleados!=NULL && tam>0)
	{
		for(i = 0; i < tam; i++)
		{
			pArrayEmpleados[i].isEmpty=valorInt;
		}
	}
}


static int buscarEmpleadoPorId(eEmpleados* pArrayEmpleados,int tam,int buscaId)
{
int indice=-1;
int i;
if(pArrayEmpleados!=NULL && tam>0 )
{

	for(i=0;i<tam;i++)
	{
		if (pArrayEmpleados[i].isEmpty==0 && pArrayEmpleados[i].id==buscaId)
		{
			indice=i;
			break;
		}

	}

}
return indice;
}




void imprimeEmpleados(eEmpleados* pArrayEmpleados, int tamArrayEmpleados, eSector* pArraySectores, int tamArraySectores)
{
	int i;
	int flag=0;


	if(pArrayEmpleados!=NULL && tamArrayEmpleados>=0 && pArraySectores!=NULL && tamArraySectores>0)
		{
			printf("ID\tNombre\tApellido\tSueldo\t\t\tSector\n");
			for(i=0;i<tamArrayEmpleados;i++)
			{
				if(pArrayEmpleados[i].isEmpty==0)
				{
					imprimeEmpleado(pArrayEmpleados[i],pArraySectores,tamArraySectores);
					flag=1;
				}
			}
		}

	if(flag==0)
	{
		system("CLS()");
		printf("\n---No hay Empleados que mostrar---\n\n");
	}
}

static void imprimeEmpleado(eEmpleados pArrayEmpleados,eSector* pArraySectores,int tamArraySectores)
{
	char descrSector [20];

	if(pArraySectores!=NULL && tamArraySectores>0)
	{
		buscarSector(pArraySectores,pArrayEmpleados.sector,tamArraySectores,descrSector);
		printf("%d\t%-2.5s\t%-2.5s\t\t%.2f\t\t%s\n",pArrayEmpleados.id,pArrayEmpleados.nombre,pArrayEmpleados.apellido,pArrayEmpleados.sueldo,descrSector);
	}
}





int modificarEmpleados(eEmpleados* pArrayEmpleados, int tamArrayEmpleados, int id, eSector* pArraySectores, int tamArraySectores)
{
	int indice;
	int valorBuscado;
	char respuesta;
	eEmpleados auxEmpleado;
	int ret=0;
	int opcion;

	system("CLS()");
	printf("*****Modificar Empleado*****\n\n");
	if(pArrayEmpleados!=NULL && pArraySectores!=NULL && tamArrayEmpleados>0 &&tamArraySectores>0)
	{

		imprimeEmpleados(pArrayEmpleados,tamArrayEmpleados,pArraySectores,tamArraySectores);
		printf("\n\n\n");
		utn_getNumero(&valorBuscado,"Ingrese el ID del Empleado que desea modificar \n","Error verifique los datos ingresados quedan %d intentos\n",0,1000,3);

		indice=buscarEmpleadoPorId(pArrayEmpleados,tamArrayEmpleados,valorBuscado);
		if(indice==-1)
		{
			printf("No se encontro el empleado para el ID ingresado\n");
			system("PAUSE()");
		}
		else
		{

			printf("\n\n\n");
			printf("ID\tNombre\tApellido\tSueldo\t\t\tSector\n");
			imprimeEmpleado(pArrayEmpleados[indice],pArraySectores,tamArraySectores);
			printf("\n\n");
			opcion=opcionesModificacion();

			if(modifEmpleado(pArrayEmpleados[indice],opcion,&auxEmpleado,pArraySectores,tamArraySectores))
			{

				utn_getCaracter(&respuesta,"Confirma la modificacion (s-n)\n","Error, verifique la respuesta ingresada\n","sn\0",3);

			}
			if(respuesta=='s')
			{
				pArrayEmpleados[indice]=auxEmpleado;
				printf("Se modifico el empleado\n");
				ret=1;
			}

			else
			{
			printf("Se cancelo la modificacion\n");
			}

		}
	}

return ret;
}


static int modifEmpleado(eEmpleados empleadoRec ,int opcion, eEmpleados* auxEmpleado, eSector* pArraySectores, int tamArraySectores)
{
	eEmpleados modifEmpleado;
	int ret=0;
	char nombre[51];
	char apellido[51];
	float sueldo;
	int sector;

	modifEmpleado=empleadoRec;

	switch(opcion)
	{
		case 1:
				{
					if(utn_getTexto(nombre,"\nIngrese el nuevo nombre del empleado\n","Error verifique los datos ingresados quedan %d intentos\n",3,50))
					{
						strcpy(modifEmpleado.nombre,nombre);
						*auxEmpleado=modifEmpleado;
						ret=1;
					}
					else
					{
						printf("No se pudo modificar el nombre\n");
					}

					break;
				}
		case 2:
				{
					if(utn_getTexto(nombre,"\nIngrese el nuevo apellido del empleado\n","Error verifique los datos ingresados quedan %d intentos\n",3,50))
					{
						strcpy(modifEmpleado.apellido,apellido);
						*auxEmpleado=modifEmpleado;
						ret=1;
							}
					else
					{
						printf("No se pudo modificar el Apellido\n");
					}

					break;
				}

		case 3:
				{
					if(utn_getNumeroConDecimales(&sueldo,"\nIngrese el nuevo sueldo del empleado\n","Error verifique los datos ingresados quedan %d intentos\n",1,9999999,3))
					{
						modifEmpleado.sueldo=sueldo;
						*auxEmpleado=modifEmpleado;
						ret=1;
					}
					else
					{
						printf("No se pudo modificar el sueldo del empleado\n");
					}

					break;
				}

		case 4:
				{

					printf("\n\n");
					mostrarSectores(pArraySectores,tamArraySectores);
					if(utn_getNumero(&sector,"\nIngrese Id de sector para el Empleado\n","Error verifique los datos ingresados quedan %d intentos\n",1000,1002,3))
					{
						modifEmpleado.sector=sector;
						*auxEmpleado=modifEmpleado;
						ret=1;
					}
					else
					{
						printf("No se pudo modificar el Id del sector del empleado\n");
					}

					break;
				}

		default:
				{
					break;
				}


	}

return ret;
}


static int opcionesModificacion()
{
	int opcion=0;
	printf("*****Opciones de Modificacion*****\n\n");

	printf("1-Nombre\n");
	printf("2-Apellido\n");
	printf("3-Sueldo\n");
	printf("4-Sector\n");
	printf("5-Salir\n");

	if(!(utn_getNumero(&opcion,"Elija un opcion: ","Error verifique los datos ingresados quedan %d intentos\n",1,5,3)))
	{
		printf("No se reconocio el ingreso, supero el maximo de posibilidades\n");
		system("PAUSE()");
	}

return opcion;
}


int bajaEmpleado(eEmpleados* pArrayEmpleados, int tamArrayEmpleados, eSector* pArraySectores, int tamArraySectores)
{
	int indice;
	int valorBuscado;
	char respuesta;
	int ret=0;

	system("CLS()");
	printf("*****Baja Empleado*****\n\n");
	if(pArrayEmpleados!=NULL && pArraySectores!=NULL && tamArrayEmpleados>0 &&tamArraySectores>0)
	{
		imprimeEmpleados(pArrayEmpleados,tamArrayEmpleados,pArraySectores,tamArraySectores);
		printf("\n\n\n");
		utn_getNumero(&valorBuscado,"Ingrese el Id del empleaado a dar de baja \n","Error verifique los datos ingresados quedan %d intentos\n",0,1000,3);

		indice=buscarEmpleadoPorId(pArrayEmpleados,tamArrayEmpleados,valorBuscado);
		if(indice==-1)
		{
			printf("No se encontro el alumno para el legajo ingresado\n");
			system("PAUSE()");
		}
		else
		{

			printf("\n\n\n");
			printf("ID\tNombre\tApellido\tSueldo\t\t\tSector\n");
			imprimeEmpleado(pArrayEmpleados[indice],pArraySectores,tamArraySectores);
			printf("\n\n");

			utn_getCaracter(&respuesta,"Confirma la baja (s-n)\n","Error, verifique la respuesta ingresada\n","sn\0",3);


			if(respuesta=='s')
			{
				pArrayEmpleados[indice].isEmpty=1;
				printf("Se elmino el Empleado\n");
				ret=1;
			}

			else
			{
			printf("Se cancelo la baja\n");
			}

		}
	}

return ret;
}



int ordenaEmpleados(eEmpleados* pArrayEmpleados,int tamArrayEmpleados,eSector* pArraySectores, int tamArraySectores, char sentido)
{
	int flagSwap=1;
	int i;
	int cont=0;
	int retorno = 0;
	char descrSector[tamArrayEmpleados][20];



	if(pArrayEmpleados != NULL && tamArrayEmpleados > 0 && pArraySectores!=NULL && tamArraySectores>0 && sentido!=' ')
			{
				while(flagSwap)
				{
					cont++;
					flagSwap = 0;
					for(i = 0 ; i < tamArrayEmpleados-cont ; i++)
					{
						switch (sentido)
						{
						case '>':
							{
							if((stricmp(pArrayEmpleados[i].apellido,pArrayEmpleados[i+1].apellido))<0 && pArrayEmpleados[i].isEmpty==0 && pArrayEmpleados[i+1].isEmpty==0)
								{
									flagSwap = 1;
									swap(pArrayEmpleados, i);
								}
							else if((stricmp(pArrayEmpleados[i].apellido,pArrayEmpleados[i+1].apellido))==0 && pArrayEmpleados[i].isEmpty==0 && pArrayEmpleados[i+1].isEmpty==0)
							{
								buscarSector(pArraySectores,pArrayEmpleados[i].sector,tamArraySectores,descrSector[i]);
								buscarSector(pArraySectores,pArrayEmpleados[i+1].sector,tamArraySectores,descrSector[i+1]);
								if((stricmp(descrSector[i],descrSector[i+1]))<0)
								{
									flagSwap = 1;
									swap(pArrayEmpleados, i);
								}

							}
							break;
							}
						case '<':
							{
							if((stricmp(pArrayEmpleados[i].apellido,pArrayEmpleados[i+1].apellido))>0 && pArrayEmpleados[i].isEmpty==0 && pArrayEmpleados[i+1].isEmpty==0)
								{
									flagSwap = 1;
									swap(pArrayEmpleados, i);
								}

							else if((stricmp(pArrayEmpleados[i].apellido,pArrayEmpleados[i+1].apellido))==0 && pArrayEmpleados[i].isEmpty==0 && pArrayEmpleados[i+1].isEmpty==0)
								{
									buscarSector(pArraySectores,pArrayEmpleados[i].sector,tamArraySectores,descrSector[i]);
									buscarSector(pArraySectores,pArrayEmpleados[i+1].sector,tamArraySectores,descrSector[i+1]);
									if((stricmp(descrSector[i],descrSector[i+1]))>0)
									{
										flagSwap = 1;
										swap(pArrayEmpleados, i);
									}

								}
							break;
							}
						}
					}
				}
retorno = 1;
			}
return retorno;
}

static void swap(eEmpleados* pArrayEmpleados, int pos)
{
	eEmpleados buffer;

	if (pArrayEmpleados!=NULL && pos >=0)
	{
		buffer=pArrayEmpleados[pos];
		pArrayEmpleados[pos]=pArrayEmpleados[pos+1];
		pArrayEmpleados[pos+1]=buffer;
	}
}

int buscaVacios(eEmpleados* pArrayEmpleados, int tam)
{
int cont=0;
int i;

if(pArrayEmpleados!=NULL && tam>0 )
{

	for(i=0;i<tam;i++)
	{
		if(pArrayEmpleados[i].isEmpty==1)
		{
			cont++;
		}
	}
}
return cont;
}
