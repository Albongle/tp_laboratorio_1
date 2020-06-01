#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int ret=0;
	int id;
	char idStr[10];
	char nombreStr[128];
	int horasTrabajadas;
	char horasTrabajadasStr[10];
	int sueldo;
	char sueldoStr[20];

	if (pArrayListEmployee!=NULL)
	{
		if(utn_getNumero(&id,"Ingrese el id del empleado\n","Error verifique los datos ingresados quedan %d intentos\n",1,99,3))
		{
			fflush(stdin);
			if(utn_getTexto(nombreStr,"Ingrese el nombre del empleado\n","Error verifique los datos ingresados quedan %d intentos\n",3,50))
			{
				fflush(stdin);
				if(utn_getNumero(&horasTrabajadas,"Ingrese las horas trabajadas\n","Error verifique los datos ingresados quedan %d intentos\n",0,24,3))
				{
					if(utn_getNumero(&sueldo,"Ingrese el sueldo del empleado \n","Error verifique los datos ingresados quedan %d intentos\n",0,999999,3))
					{
						itoa(id,idStr,10);
						itoa(horasTrabajadas,horasTrabajadasStr,10);
						itoa(sueldo,sueldoStr,10);
						employee_newParametros(idStr,nombreStr,horasTrabajadasStr,sueldoStr);
						ret=1;
					}
				}
			}
		}

	}
    return ret;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

