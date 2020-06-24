/*
 ============================================================================
 Name        : Examen_3.c
 Author      : Alejandro Bongioanni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "LinkedList.h"
#include "ventas.h"
#include "parser.h"
#define ARCH "data_prod.csv"
#define INFORME "informe.txt"

int menu();



int main()
{
	system("COLOR 1F");
	setbuf(stdout, NULL);
    int opcion;
    int i;
    int tam;
    FILE* pFile;
    eVentas* ventaAux=NULL;
    LinkedList* listaVentas= ll_newLinkedList();
    do{
    	system("CLS()");
    	printf("\t\t****Linkedist posee %d  en su lista****\n\n",ll_len(listaVentas));
    	opcion=menu();
        switch(opcion)
        {
            case 1:
            {
            	fflush(stdin);
            	if((pFile=fopen(ARCH,"r"))!=NULL)
            	{
            		if(parser_VentasComoTexto(pFile,listaVentas))
            		{
            			printf("\n\n****Se cargaron los datos****\n");
            			fclose(pFile);
            		}
            	}
            	else
            	{
            		printf("\n\n****No se pudo abrir el archivo****\n");
            	}

            	break;
            }
            case 2:
            {
            	if ((tam=ll_len(listaVentas))>0)
            	{
            		system("CLS()");
            		printf("\n\n****Listado de Ventas****\n");
            		printf("\n\n\nId\tFecha Venta\t\tCodigo Producto\t\tCantidad\tPrecio Unitario\t\tCuit Cliente\n");
            		for (i=0;i<tam;i++)
            		{
            			ventaAux=ll_get(listaVentas,i);
            			if(ventaAux!=NULL)
            			{
            				ventas_Print(ventaAux);
            			}
            		}
            	}
            	else
            	{

            		printf("\n\n\nEl sitema no posee Ventas\n");
            	}

            	break;
            }
            case 3:
            {
            	if ((tam=ll_len(listaVentas))>0)
                {
            		if((pFile=fopen(INFORME,"w"))!=NULL)
            		{
            			if(guardarVentascomoTexto(pFile,listaVentas))
            			{
            				printf("\n\n****Se genero el informe****\n");
            				fclose(pFile);
            			}
            		}
                }
            	else
            	{
            		printf("\n\n\nEl sitema no posee Ventas\n");
            	}

            	break;
            }

            default:
            {


            	break;
            }
        }
        system("PAUSE()");
    }while(opcion != 4);


    return 0;
}



int menu()
{
	int opcion=-1;
	printf("Menu de opciones\n\n");
	printf("1-Cargar archivo\n");
	printf("2-Imprimir Ventas\n");
	printf("3-Generar archivo de montos\n");
	printf("4-Salir\n");
	fflush(stdin);
	if(!(utn_getNumero(&opcion,"Elija un opcion: ","Error verifique los datos ingresados quedan %d intentos\n",1,4,3)))
	{
		printf("No se reconocio el ingreso, supero el maximo de posibilidades\n");
		system("PAUSE()");
	}

return opcion;
}
