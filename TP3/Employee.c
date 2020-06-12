#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"


static int menuEdit(void);

Employee* employee_new()
{
	Employee* this=(Employee*) malloc(sizeof(Employee));
	if(this!=NULL)
	{
		employee_setId(this,0);
		employee_setNombre(this,"");
		employee_setHorasTrabajadas(this,0);
		employee_setSueldo(this,0);
	}
	return this;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* this=employee_new();

		if(this!=NULL)
		{
			employee_setId(this,atoi(idStr));
			employee_setNombre(this,nombreStr);
			employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr));
			employee_setSueldo(this,atoi(sueldoStr));
		}
		return this;

}

int employee_setId(Employee* this,int id)
{
	int ret=0;
	static int maxId=0;
	if (this!=NULL)
	{
		if(id<0)
		{
			maxId++;
			this->id=maxId;
		}
		else
		{
			if(id>maxId)
			{
				maxId=id;
			}
			this->id=id;
		}
		ret=1;
	}
	return ret;
}

int employee_getId(Employee* this,int* id)
{
	int ret=0;
		if (this!=NULL && id !=NULL)
		{
			*id=this->id;
			ret=1;
		}
		return ret;

}

int employee_setNombre(Employee* this,char* nombre)
{
	int ret=0;
	if (this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre,nombre);
		ret=1;
	}
	return ret;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int ret=0;
	if (this!=NULL && nombre!=NULL)
		{
			strcpy(nombre,this->nombre);
			ret=1;
		}
		return ret;

}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int ret=0;
	if (this!=NULL && horasTrabajadas>=0)
	{
		this->horasTrabajadas=horasTrabajadas;
		ret=1;
	}
	return ret;

}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int ret=0;
	if (this!=NULL && horasTrabajadas!=NULL)
	{
		*horasTrabajadas=this->horasTrabajadas;
		ret=1;
	}
	return ret;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int ret=0;
	if (this!=NULL && sueldo>=0)
	{
		this->sueldo=sueldo;
		ret=1;
	}
	return ret;
}


int employee_getSueldo(Employee* this,int* sueldo)
{
	int ret=0;
	if (this!=NULL && sueldo!=NULL)
	{
		*sueldo=this->sueldo;
		ret=1;
	}
	return ret;
}

int employee_getDatos(Employee* this,char* id,char* nombre,char* horasTrabajadas,char* sueldo)
{
	int ret=0;

	if (this!=NULL && id!=NULL && nombre!=NULL && horasTrabajadas!=NULL && sueldo!=NULL)
	{
		sprintf(id,"%d",this->id);
		sprintf(sueldo,"%d",this->sueldo);
		sprintf(horasTrabajadas,"%d",this->horasTrabajadas);
		strcpy(nombre,this->nombre);
		ret=1;

	}
return ret;
}

int employee_delete(Employee* this)
{
	int ret=0;
	if(this!=NULL)
	{
		free(this);
		ret=1;
	}
	return ret;
}

int employee_Add(Employee** this)
{
	int ret=0;
	int id=-1;
	int horasTrabajadas;
	int sueldo;
	char nombreStr[128];
	Employee* empAux=NULL;
	if(this!=NULL)
	{
		empAux=employee_new();
		if(empAux!=NULL)
		{
			system("CLS()");
			printf("\n\n****Alta de empleado****\n\n");
			fflush(stdin);
			if(utn_getTexto(nombreStr,"Ingrese el nombre del empleado\n","Error verifique los datos ingresados quedan %d intentos\n",3,50))
			{
				fflush(stdin);
				if(utn_getNumero(&horasTrabajadas,"Ingrese las horas trabajadas\n","Error verifique los datos ingresados quedan %d intentos\n",0,99999,3))
				{
					fflush(stdin);
					if(utn_getNumero(&sueldo,"Ingrese el sueldo del empleado \n","Error verifique los datos ingresados quedan %d intentos\n",0,999999,3))
					{
						employee_setNombre(empAux,nombreStr);
						employee_setId(empAux,id);
						employee_setHorasTrabajadas(empAux,horasTrabajadas);
						employee_setSueldo(empAux,sueldo);
						ret=1;
					}
				}
			}
		}
		else
		{
			ret=-1;
		}
	}

	*this=empAux;
	return ret;
}

int employee_Print(Employee* this)
{
	int ret=0;
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
	if (this!=NULL)
	{
		if(employee_getId(this,&id))
		{
			if(employee_getNombre(this,nombre))
			{
				if(employee_getHorasTrabajadas(this,&horasTrabajadas))
				{
					if(employee_getSueldo(this,&sueldo))
					{
						printf("%d	%s	%d	%d\n", id,nombre, horasTrabajadas,sueldo);
						ret=1;

					}
				}
			}
		}

	}

	return ret;
}


int employee_getPos(Employee* this,int id)
{

	int ret=0;
	int idAux;
	if(this!=NULL && id>=0)
	{
		employee_getId(this,&idAux);
		if(idAux==id)
		{
			ret=1;
		}
	}
	return ret;
}


int employee_edit(Employee* this)
{
	int ret=0;
	char nombreStr[128];
	int horasTrabajadas;
	int sueldo;
	int opcion;

	if(this!=NULL)
	{
		do
		{
			system("CLS()");
			printf("\n\n****Modificacion de empleado****\n");
			printf("\nID	Nombre	Horas	Sueldo\n");
			employee_Print(this);
			opcion=menuEdit();
			switch(opcion)
			{
				case 1:
				{
					if(utn_getTexto(nombreStr,"\nIngrese el nuevo nombre del empleado\n","Error verifique los datos ingresados quedan %d intentos\n",3,50))
					{
						if(employee_setNombre(this,nombreStr))
						{
							ret=1;
						}
					}
					break;
				}
				case 2:
				{
					if(utn_getNumero(&horasTrabajadas,"\nIngrese las horas trabajadas\n","Error verifique los datos ingresados quedan %d intentos\n",0,9999,3))
					{
						if(employee_setHorasTrabajadas(this,horasTrabajadas))
						{
							ret=1;
						}
					}
					break;
				}
				case 3:
				{
					if(utn_getNumero(&sueldo,"\nIngrese el sueldo del empleado \n","Error verifique los datos ingresados quedan %d intentos\n",0,999999,3))
					{
						if(employee_setSueldo(this,sueldo))
						{
							ret=1;
						}
					}
					break;
				}
				default:
				{
					break;
				}
			}

		}while(opcion!=4);
	}
	return ret;
}


static int menuEdit(void)
{
	int opcion=-1;
	printf("\n\nMenu de edicion\n\n");
	printf("1-Nombre\n");
	printf("2-Horas Trabajadas\n");
	printf("3-Sueldo\n");
	printf("4-Salir\n");

	if(!(utn_getNumero(&opcion,"Elija un opcion: ","Error verifique los datos ingresados quedan %d intentos\n",1,4,3)))
	{
		printf("No se reconocio el ingreso, supero el maximo de posibilidades\n");
		system("PAUSE()");
	}

return opcion;
}


int employee_OrdenPorNombre(void* emp1,void* emp2)
{
	int ret=0;
	char nombre1[128];
	char nombre2[128];
	Employee* empAux1= NULL;
	Employee* empAux2= NULL;

	if(emp1 != NULL && emp2!= NULL)
	{
		empAux1= (Employee*)emp1;
		empAux2= (Employee*)emp2;
		if(employee_getNombre(empAux1,nombre1) && employee_getNombre(empAux2,nombre2))
		{
			if((stricmp(nombre1,nombre2))>0)
			{
				ret=1;
			}
			else if((stricmp(nombre1,nombre2))<0)
			{

				ret=-1;
			}
			else
			{
				ret=employee_OrdenaPorSueldo(empAux1,empAux2);
			}
		}

	}
	return ret;
}
int employee_OrdenaPorSueldo(void* emp1,void* emp2)
{
	int ret=0;
	int sueldo1;
	int sueldo2;
	Employee* empAux1= NULL;
	Employee* empAux2= NULL;
	if(emp1!=NULL && emp2!=NULL)
	{
		empAux1= (Employee*)emp1;
		empAux2= (Employee*)emp2;
		if(employee_getSueldo(empAux1,&sueldo1) && employee_getSueldo(empAux2,&sueldo2))
		{
			if(sueldo1>sueldo2)
			{
				ret=1;
			}
			else if(sueldo1<sueldo2)
			{
				ret=-1;
			}
		}

	}
	return ret;
}

