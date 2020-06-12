#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "utn.h"



int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* txt;
	int tam;
	int result;
	char pregunta;

	txt=fopen(path,"r");;
	tam=ll_len(pArrayListEmployee);
	if(txt == NULL)
	{
		printf("\n\n****Cargar de empleados mediante archivo TXT****\n\nNo se pudo abrir el archivo\n");
	}
	else
	{
		if(tam>0)
		{
			printf("\n\n****Cargar de empleados mediante archivo TXT****\n\n");
			fflush(stdin);
			if((utn_getCaracter(&pregunta,"El sistema ya posee informacion,desea remplazarlos?(s/n):\n","Error verifique los datos ingresados, quedan %d reintentos\n","sn\n",3)))
			{
				if(pregunta=='s')
				{
					if((controller_memoryFree(pArrayListEmployee)))
					{
						if((result=parser_EmployeeFromText(txt,pArrayListEmployee)))
						{
							printf("\n\n****Remplazo de informacion mediante archivo TXT****\n\nSe cargaron los empleados\n");
						}
						else if(result==-1)
						{
							printf("\n\n****Remplazo de informacion mediante archivo TXT****\n\nNo hay mas espacio para almacenar toda la informacion del archivo\n");
						}
						else
						{
							printf("\n\n****Remplazo de informacion mediante archivo TXT****\n\nHubo un error al momento de la lectura del archivo\n");
						}
					}
					else
					{
						printf("\n\n****Remplazo de informacion mediante archivo TXT****\n\nHubo un error al momento de eliminar la informacion existente\n");
					}
				}
				else
				{
					printf("\n\n****Se cancelo la cargar****\n\n");
				}
			}
			else
			{
				printf("\n\n****Se cancelo la cargar****\n\nSupero el maximo de intentos\n");
			}
		}
		else if((result=parser_EmployeeFromText(txt ,pArrayListEmployee)))
		{
			printf("\n\n****Cargar de empleados mediante archivo TXT****\n\nSe cargaron los empleados\n");
		}
		else if(result==-1)
		{
			printf("\n\n****Cargar de empleados mediante archivo TXT****\n\nNo hay mas espacio para almacenar toda la informacion del archivo\n");
		}
		else
		{
			printf("\n\n****Cargar de empleados mediante archivo TXT****\n\nHubo un error al momento de la lectura del archivo\n");
		}
		fclose(txt);
	}
	system("PAUSE()");
    return 1;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* bin;
	int tam;
	int result;
	char pregunta;
	tam=ll_len(pArrayListEmployee);
	bin=fopen(path,"rb");
	if(bin==NULL)
	{
		printf("\n\n****Cargar de empleados mediante archivo BIN****\n\nNo se pudo abrir el archivo\n");
	}
	else
	{
		if(tam>0)
		{
			printf("\n\n****Cargar de empleados mediante archivo BIN****\n\n");
			fflush(stdin);
			if((utn_getCaracter(&pregunta,"El sistema ya posee informacion,desea remplazarlos?(s/n):\n","Error verifique los datos ingresados, quedan %d reintentos\n","sn\n",3)))
			{
				if(pregunta=='s')
				{
					if((controller_memoryFree(pArrayListEmployee)))
					{
						if((result=parser_EmployeeFromBinary(bin ,pArrayListEmployee)))
						{
							printf("\n\n****Remplazo de informacion mediante archivo BIN****\n\nSe cargaron los empleados\n");
						}
						else if(result==-1)
						{
							printf("\n\n****Remplazo de informacion mediante archivo BIN****\n\nNo hay mas espacio para almacenar toda la informacion del archivo\n");
						}
						else
						{
							printf("\n\n****Remplazo de informacion mediante archivo BIN****\n\nHubo un error al momento de la lectura del archivo\n");
						}
					}
					else
					{
						printf("\n\n****Remplazo de informacion mediante archivo BIN****\n\nHubo un error al momento de eliminar la informacion existente\n");
					}
				}
				else
				{
					printf("\n\n****Se cancelo la cargar****\n\n");
				}
			}
			else
			{
				printf("\n\n****Se cancelo la cargar****\n\nSupero el maximo de intentos\n");
			}

		}
		else if((result=parser_EmployeeFromBinary(bin,pArrayListEmployee)))
		{
			printf("\n\n****Cargar de empleados mediante archivo BIN****\n\nSe cargaron los empleados\n");
		}
		else if(result==-1)
		{
			printf("\n\n****Cargar de empleados mediante archivo BIN****\n\nNo hay mas espacio para almacenar toda la informacion del archivo\n");
		}
		else
		{
			printf("\n\n****Cargar de empleados mediante archivo BIN****\n\nHubo un error al momento de la lectura del archivo\n");
		}
		fclose(bin);
	}
	system("PAUSE()");
    return 1;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	Employee* empAux=NULL;
	int result;
	if(pArrayListEmployee!=NULL)
	{
		if((result=employee_Add(&empAux)))
		{
			ll_add(pArrayListEmployee,empAux);
			printf("\n\n****Se dio de alta el empleado****\n\n\n");
			printf("ID	Nombre	Horas	Sueldo\n");
			employee_Print(empAux);
		}
		else if(result==-1)
		{
			printf("\n\n****No es posible seguir dando de alta empleados****\n\n\n");
		}
		else
		{
			employee_delete(empAux);
			printf("\n\n****Se cancelo alta del empleado****\n\n\n");
		}
	}
	system("PAUSE()");
    return 1;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int tam;
	int auxId;
	char pregunta;
	int i;
	int flag;

	Employee* empAux=NULL;

	tam=ll_len(pArrayListEmployee);
	if(tam>0)
	{
		controller_ListEmployee(pArrayListEmployee); // imprimo la lista de empleados
		printf("\n\n****Modificacion de Empleado****\n");
		if(utn_getNumero(&auxId,"\n\nIngrese id del empleado a Modificar\n","Error verifique los datos ingresados quedan %d intentos\n",0,999999,3))
		{
			for (i=0; i < tam; i++)
			{
				flag=employee_getPos((empAux=ll_get(pArrayListEmployee,i)),auxId);
				if(flag)
				{
					break;
				}
			}
			if(empAux!=NULL)
			{
				printf("\n****Empleado Seleccionado****\n");
				printf("\nID	Nombre	Horas	Sueldo\n");
				employee_Print(empAux);
				fflush(stdin);
				if(utn_getCaracter(&pregunta,"\n\nDesea modificar los datos del empleado impreso?(s/n):\n","Error verifique los datos ingresados, quedan %d reintentos","sn\n",3))
				{
					if(pregunta=='s')
					{
						if(employee_edit(empAux))
						{
							printf("Se modifico el empleado\n");
						}
						else
						{
							printf("Se cancelo la modificacion\n");
						}
					}
					else
					{
						printf("Se cancelo la modificacion\n");
					}
				}
				else
				{
					printf("Supero el maximo de intentos Se cancelo la modificacion\n");
				}
			}
			else
			{
				printf("No se encoentro empleado con el Id ingresado\n");
			}
		}
	}
	else
	{
		printf("\n\n\nEl sitema no posee empleados\n");
	}
	system("PAUSE()");
    return 1;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int tam;
	int auxId;
	char pregunta;
	int indice;
	int i;
	int flag;
	Employee* empAux=NULL;

	tam=ll_len(pArrayListEmployee);
	if(tam>0)
	{
		controller_ListEmployee(pArrayListEmployee); // imprimo la lista de empleados
		printf("\n\n****Baja de Empleado****\n");
		if(utn_getNumero(&auxId,"\n\nIngrese id del empleado a eliminar\n","Error verifique los datos ingresados quedan %d intentos\n",0,999999,3))
		{
			for (i=0; i < tam; i++)
			{
				flag=employee_getPos((empAux=ll_get(pArrayListEmployee,i)),auxId);
				if(flag)
				{
					break;
				}
			}
			if(empAux!=NULL)
			{
				indice=ll_indexOf(pArrayListEmployee,empAux);
				printf("\n\n****Se va a eliminar el empleado****\n");
				printf("\nID	Nombre	Horas	Sueldo\n");
				employee_Print(empAux);
				fflush(stdin);
				if(utn_getCaracter(&pregunta,"Confirmar la eliminiacion (s/n):\n","Error verifique los datos ingresados, quedan %d reintentos","sn\n",3))
				{
					if(pregunta=='s')
					{
						employee_delete(empAux); // hago el free de la estructurca empleado
						ll_remove(pArrayListEmployee,indice); // elimino el empleado de la linkedist
						printf("Se dio de baja el empleado\n");
					}
					else
					{
						printf("Se cancelo la baja\n");
					}
				}
				else
				{
					printf("Supero el maximo de intentos Se cancelo la baja\n");
				}
			}
			else
			{
				printf("No se encoentro empleado con el Id ingresado\n");
			}
		}

	}
	else
	{
		printf("\n\n\nEl sitema no posee empleados\n");
	}
	system("PAUSE()");
    return 1;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int tam;
	int i;
	Employee* empAux=NULL;
	if(pArrayListEmployee!=NULL)
	{
		tam=ll_len(pArrayListEmployee);
		if (tam>0)
		{
			system("CLS()");
			printf("\n\n****Listado de Empleados****\n");
			printf("\n\n\nID	Nombre	Horas	Sueldo\n");
			for (i=0; i < tam; i++)
			{
				empAux=ll_get(pArrayListEmployee,i);
				if(empAux!=NULL)
				{
					employee_Print(empAux);
				}
			}
		}
		else
		{

			printf("\n\n\nEl sitema no posee empleados\n");
		}

	}
	system("PAUSE()");
    return 1;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int ret =0;
	int sentido;
	int tam;
	if(pArrayListEmployee!=NULL)
	{
		tam=ll_len(pArrayListEmployee);
		if(tam>0)
		{
			fflush(stdin);
			printf("\n\n*****Se va a ordenar por nombre y luego por sueldo*****\n");
			if(utn_getNumero(&sentido,"\nElija el criterio de orden\n0-Descendente\n1-Ascendente\n","Error, verifique los datos ingresados, quedan %d intentos\n",0,1,3))
			{
				printf("\n\nSe esta realizando el ordenamiento...\n");
				ll_sort(pArrayListEmployee,employee_OrdenPorNombre,sentido);
				printf("\n\nSe realizo el ordenamiento por nombre y sueldo\n");
				ret=1;
			}
			else
			{
				printf("No se reconocio el ingreso, se cancelo el ordenamiento\n");
			}
		}
		else
		{
			printf("\n\n\nEl sitema no posee empleados\n");
		}
	}
	system("PAUSE()");
    return ret;
}


int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* txt;
	FILE* auxTxt;
	int ret=0;
	int tam;
	int flag=0;
	int result=0;
	char pregunta;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		tam=ll_len(pArrayListEmployee);
		if(tam>0)
		{
			if((auxTxt=fopen(path,"r"))!=NULL)
			{
				fclose(auxTxt);
				printf("\n\nya existe un arhivo con ese nombre\n");
				flag=1;
				if((utn_getCaracter(&pregunta,"Desea continuar de todos modos? (s/n):\n","Error verifique los datos ingresados, quedan %d reintentos","sn\n",3)))
				{
					if(pregunta=='s')
					{
						flag=0;
					}
				}
				else
				{
					printf("\n\nsupero el maximo de posibilidades\n");
				}
			}
			if(flag==0)
			{
				if((txt=fopen(path,"w"))==NULL)
				{
					printf("El archivo no puede ser abierto\n");
				}
				else
				{
					if((result=saveEmployeeAsText(txt,pArrayListEmployee)))
					{

						printf("\n\n\nSe genero el archivo de texto con el listado de empleados\n");
					}
					else if(result<0)
					{
						printf("\n\n\nSe genero el archivo de texto con el listado de empleados pero algunos registros no se pudieron guardar\n");
					}
					else
					{
						printf("\n\n\nNo se pudo generar el archivo de texto\n");
					}
					fclose(txt);
				}
			}
			else
			{
				printf("se cancelo la accion\n");
			}

		}
		else
		{
			printf("\n\n\nEl sitema no posee empleados\n");
		}
	}
	system("PAUSE()");
    return ret;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* bin;
	FILE* auxBin;
	int ret=0;
	int tam;
	int result;
	int flag=0;
	char pregunta;

	tam=ll_len(pArrayListEmployee);
	if(tam>0)
	{
		if((auxBin=fopen(path,"rb"))!=NULL)
		{
			fclose(auxBin);
			printf("\n\nya existe un arhivo con ese nombre\n");
			flag=1;
			fflush(stdin);
			if((utn_getCaracter(&pregunta,"Desea continuar de todos modos? (s/n):\n","Error verifique los datos ingresados, quedan %d reintentos","sn\n",3)))
			{
				if(pregunta=='s')
				{
					flag=0;
				}
			}
			else
			{
				printf("\n\nsupero el maximo de posibilidades\n");
			}
		}
		if(flag==0)
		{
			if((bin=fopen(path,"w+b"))==NULL)
			{
				printf("El archivo no puede ser abierto\n");
			}
			else
			{
				if((result=saveEmployeeAsBin(bin,pArrayListEmployee)))
				{
					printf("\n\n\nSe genero el archivo de binario con el listado de empleados\n");
				}
				else if(result<0)
				{
					printf("\n\n\nSe genero el archivo de binario con el listado de empleados pero algunos registros no se pudieron guardar\n");
				}
				else
				{
					printf("\n\n\nNo se pudo generar el archivo de binario\n");
				}
				fclose(bin);
			}
		}
		else
		{
			printf("se cancelo la accion\n");
		}
	}
	else
	{
		printf("\n\n\nEl sitema no posee empleados\n");
	}


	system("PAUSE()");
    return ret;
}



int controller_memoryFree(LinkedList* pArrayListEmployee)
{
	Employee* empAux=NULL;
	int ret=0;
	int i;
	int tam;


	if (pArrayListEmployee!=NULL)
	{
		tam=ll_len(pArrayListEmployee);
		if(tam>0)
		{
			for(i=0;i<tam;i++)
			{
				{
					empAux=ll_get(pArrayListEmployee,i);
					employee_delete(empAux);
				}
			}

			ll_clear(pArrayListEmployee);
			ret=1;
		}
	}
return ret;
}


