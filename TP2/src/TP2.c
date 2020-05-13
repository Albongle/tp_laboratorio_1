/*
 ============================================================================
 Name        : TP2.c
 Author      : Alejandro Bongioanni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "empleados.h"
#include "sector.h"
#include "utn.h"
#include "informes.h"
#define Q_EMPLEADOS 1000
#define Q_SECTOR 3

static int menu();
static int subMenu();

int main(void) {

system("COLOR E");
setbuf(stdout, NULL);
eEmpleados empleados[Q_EMPLEADOS];
eSector sectores[]={{1000, "SISTEMAS"},{1001, "ADMINISTRACION"},{1002, "SEGURIDAD"}}; //Hardcodeo sectores;
int ingreso;
int ingreso_sub;
int id=0;

inicializarEmpleados(empleados,Q_EMPLEADOS,1); // inicializo array empleados poniendo en isEmpty 1
//id=id+hardcodearEmpleados(empleados,Q_EMPLEADOS,5); //harcodeo de empleados

do
{
	system("CLS()");
	ingreso=menu();
	switch (ingreso)
	{
		case 1:
		{

			if(altaEmpleado(empleados,Q_EMPLEADOS,id,sectores,Q_SECTOR))
			{
				id++;
			}
			else
			{
				printf("Se cancelo el alta\n");
			}
			break;
		}
		case 2:
		{
			system("CLS()");
			if(buscaVacios(empleados,Q_EMPLEADOS)==Q_EMPLEADOS)
			{
				printf("Aun no se cargo informacion en el sistema\n");
			}
			else
			{
				modificarEmpleados(empleados,Q_EMPLEADOS,id,sectores,Q_SECTOR);
			}
			break;
		}
		case 3:
		{
			system("CLS()");
			if(buscaVacios(empleados,Q_EMPLEADOS)==Q_EMPLEADOS)
			{
				printf("Aun no se cargo informacion en el sistema\n");

			}
			else
			{
				bajaEmpleado(empleados,Q_EMPLEADOS,sectores,Q_SECTOR);

			}
			break;
		}
		case 4:
		{
			system("CLS()");
			if(buscaVacios(empleados,Q_EMPLEADOS)==Q_EMPLEADOS)
			{
				printf("Aun no se cargo informacion en el sistema\n");

			}
			else
			{

				do
				{
					system("CLS()");
					ingreso_sub=subMenu();
					switch (ingreso_sub)
					{
						case 1:
								{
									system("CLS()");
									empleadosOrdenados(empleados,Q_EMPLEADOS,sectores,Q_SECTOR,0);// ordenador
									system("PAUSE()");
									break;
								}
						case 2:
								{
									system("CLS()");
									totYpromSalario(empleados,Q_EMPLEADOS);
									system("PAUSE()");
									break;
								}

						default:
								{
									ingreso_sub=3;
									break;
								}
					}
				}while(ingreso_sub!=3);
				//break;
			}
			break;
		}
		default:
		{
			ingreso=5;
			break;
		}

	}


	system("PAUSE()");
}while(ingreso!=5);








return EXIT_SUCCESS;
}





static int menu()
{
	int opcion=0;

	printf("Menu de opciones\n\n");
	printf("1-Alta de Empleado\n");
	printf("2-Modificar Empleado\n");
	printf("3-Baja de Empleado\n");
	printf("4-Informes\n");
	printf("5-Salir\n");

	if(!(utn_getNumero(&opcion,"Elija un opcion: ","Error verifique los datos ingresados quedan %d intentos\n",1,5,3)))
	{
		printf("No se reconocio el ingreso, supero el maximo de posibilidades\n");

	}



return opcion;
}


static int subMenu()
{
	int opcion=0;

	printf("Menu de informes\n\n");
	printf("1-Listar empleados\n");
	printf("2-Total y promedio de los salarios\n");
	printf("3-Salir\n");

	if(!(utn_getNumero(&opcion,"Elija un opcion: ","Error verifique los datos ingresados quedan %d intentos\n",1,3,3)))
	{
		printf("No se reconocio el ingreso, supero el maximo de posibilidades\n");

	}



return opcion;
}
