#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

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
int menu();

int main()
{
	system("COLOR E");
	setbuf(stdout, NULL);
    int option = 0;;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    	system("CLS()");
    	option=menu();
        switch(option)
        {
            case 1:
            {
            	controller_loadFromText("data.csv",listaEmpleados);
            	break;

            }
            case 2:
            {

            	break;
            }
            case 3:
            {
            	controller_addEmployee(listaEmpleados);
            	break;
            }
            case 4:
            {

            	break;
            }
            case 5:
            {


            	break;
            }
            case 6:
            {

            	break;
            }
            case 7:
            {

            	break;
            }
            case 8:
            {

            	break;
            }
            case 9:
            {

            	break;
            }

            case 10:
            {


            	break;
            }


            default:
            {
            	break;
            }
        }
    }while(option != 10);

 system("PAUSE()");
    return 0;
}





int menu()
{
	int option=-1;
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

	if(!(utn_getNumero(&option,"Elija un opcion: ","Error verifique los datos ingresados quedan %d intentos\n",1,10,3)))
	{
		printf("No se reconocio el ingreso, supero el maximo de posibilidades\n");
		system("PAUSE()");
	}

return option;
}



