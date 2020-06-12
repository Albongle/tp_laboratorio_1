#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int ret=0;
	char buffer[4][50];
	int cant=0;
	Employee* pAuxEmployee=NULL;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
			 fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
			 while(!feof(pFile))
			 {
				 cant=fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
			     if(cant < 4)
			     {
			    	 ret=0;
			    	 break;
			     }
			     else
			     {
			    	 if((pAuxEmployee=employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]))!=NULL)
			    	 {
			    		 ll_add(pArrayListEmployee,pAuxEmployee);
			    		 ret=1;
			    	 }
			    	 else
			    	 {
			    		 ret=-1;
			    		 break;
			    	 }
			     }
			 }
	}
    return ret;
}


int parser_EmployeeFromBinary(FILE* pFile,LinkedList* pArrayListEmployee)
{
	int cant;
	int ret=0;
	char idAux[10];
	char nombre[128];
	char horasAux[10];
	char sueldoAux[10];
	Employee empAux;
	Employee* pAuxEmployee=NULL;

	if (pFile!=NULL && pArrayListEmployee!=NULL)
	{
		while(!feof(pFile))
		{
			cant=fread(&empAux,sizeof(empAux),1,pFile);
			if(cant!=1)
			{
				if(feof(pFile))
				{
					break;
				}
				else
				{
					ret=0;
					break;
				}
			}
			else
			{
				if((employee_getDatos(&empAux,idAux,nombre,horasAux,sueldoAux)))
				{
					if((pAuxEmployee=employee_newParametros(idAux,nombre,horasAux,sueldoAux))!=NULL)
					{
						ll_add(pArrayListEmployee,pAuxEmployee);
						ret=1;
					}
					else
					{
						ret=-1;
						break;
					}
				}
			}
		}
	}
    return ret;
}

int saveEmployeeAsText(FILE* path , LinkedList* pArrayListEmployee)
{
	int ret=0;
	int tam;
	int i;
	char idAux[10];
	char nombre[128];
	char horasAux[10];
	char sueldoAux[10];
	int flag=0;
	int cant;
	char* titulo="id,nombre,horasTrabajadas,sueldo\n";
	Employee* empAux=NULL;

	if(path!=NULL &&  pArrayListEmployee!=NULL)
	{
		tam=ll_len(pArrayListEmployee);
		if(tam>0)
		{
			fwrite(titulo,sizeof(char),strlen(titulo),path);
			for(i=0;i<tam;i++)
			{
				if((empAux=ll_get(pArrayListEmployee,i))!=NULL)
				{
					if(employee_getDatos(empAux,idAux,nombre,horasAux,sueldoAux))
					{
						cant=fprintf(path,"%s,%s,%s,%s\n",idAux,nombre,horasAux,sueldoAux);
						if(cant<4)
						{
							flag=1;
						}
					}
				}
			}
			if(flag>0)
			{
				ret=-1;
			}
			else
			{
				ret=1;
			}
		}
	}
	return ret;
}

int saveEmployeeAsBin(FILE* path , LinkedList* pArrayListEmployee)
{
	int ret=0;
	int tam;
	int i;
	int flag=0;
	int cant;
	Employee* empAux=NULL;

	if(path!=NULL &&  pArrayListEmployee!=NULL)
	{
		tam=ll_len(pArrayListEmployee);
		if(tam>0)
		{
			for(i=0;i<tam;i++)
			{
				if((empAux=ll_get(pArrayListEmployee,i))!=NULL)
				{
					cant=fwrite(empAux,sizeof(*empAux),1,path);
					if(cant!=1)
					{
						flag=1;
					}
				}
			}
			if(flag>0)
			{
				ret=-1;
			}
			else
			{
				ret=1;
			}
		}

	}

return ret;
}

