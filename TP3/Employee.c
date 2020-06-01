#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Employee.h"


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
	Employee* this=(Employee*) malloc(sizeof(Employee));
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
	if (this!=NULL && id>=0)
	{
		this->id=id;
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
