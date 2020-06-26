#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
#define ARCHTXT "data.csv"
#define ARCHTXTCOPY "dataCopy.csv"
#define ARCHBIN "dataBin.csv"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

/** \brief Carga el menu inicial del sistema
 * \return int la opcion seleccionada
 */
int menu();

int main()
{
	system("COLOR E");
	setbuf(stdout, NULL);
    int opcion = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    	system("CLS()");
    	printf("\t\t****Linkedist posee %d empleados en su lista****\n\n",ll_len(listaEmpleados));
    	opcion=menu();
        switch(opcion)
        {
            case 1:
            {
            	controller_loadFromText(ARCHTXT,listaEmpleados);
            	break;

            }
            case 2:
            {
            	controller_loadFromBinary(ARCHBIN,listaEmpleados);
            	break;
            }
            case 3:
            {
            	controller_addEmployee(listaEmpleados);

            	break;
            }
            case 4:
            {
            	controller_editEmployee(listaEmpleados);
            	break;
            }
            case 5:
            {

            	controller_removeEmployee(listaEmpleados);
            	break;
            }
            case 6:
            {
            	controller_ListEmployee(listaEmpleados);

            	break;
            }
            case 7:
            {
            	controller_sortEmployee(listaEmpleados);
            	break;
            }
            case 8:
            {
            	 controller_saveAsText(ARCHTXTCOPY,listaEmpleados);

            	break;
            }
            case 9:
            {
            	controller_saveAsBinary(ARCHBIN,listaEmpleados);
            	break;
            }


            default:
            {

            	controller_memoryFree(listaEmpleados);
            	break;
            }
        }
    }while(opcion != 10);

 system("PAUSE()");
    return 0;
}





int menu()
{
	int opcion=-1;
	printf("Menu de opciones\n\n");
	printf("1-Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
	printf("2-Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n");
	printf("3-Alta de empleado\n");
	printf("4-Modificar datos de empleado\n");
	printf("5-Baja de empleado\n");
	printf("6-Listar empleados\n");
	printf("7-Ordenar empleados\n");
	printf("8-Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
	printf("9-Guardar los datos de los empleados en el archivo data.csv (modo binario)\n");
	printf("10-Salir\n");

	if(!(utn_getNumero(&opcion,"Elija un opcion: ","Error verifique los datos ingresados quedan %d intentos\n",1,10,3)))
	{
		printf("No se reconocio el ingreso, supero el maximo de posibilidades\n");
		system("PAUSE()");
	}

return opcion;
}



