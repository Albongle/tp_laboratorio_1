#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "ventas.h"


int parser_VentasComoTexto(FILE* pFile , LinkedList* pArrayList)
{
	int ret=0;
	char buffer[6][50];
	int cant=0;
	eVentas* pAuxVenta=NULL;

	if(pFile!=NULL && pArrayList!=NULL)
	{
			 fscanf(pFile, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]);
			 while(!feof(pFile))
			 {
				 cant=fscanf(pFile, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]);
			     if(cant<6)
			     {
			    	 ret=0;
			    	 break;
			     }
			     else
			     {
			    	 if((pAuxVenta=eVentas_newParametros(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5],"0"))!=NULL)
			    	 {
			    		 ll_add(pArrayList,pAuxVenta);
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



int guardarVentascomoTexto(FILE* path,LinkedList* pArrayList)
{
	int ret=0;
	char cantidadV[30];
	char ventasMayorDiez[30];
	char ventasMayorVeinte[30];
	char cantidadTvs[30];
	char* titulo="********************\nInforme de ventas\n********************\n\n";



	if(path!=NULL &&  pArrayList!=NULL)
	{
		sprintf(cantidadV,"%d",ll_count(pArrayList,cantidad_Ventas));
		sprintf(ventasMayorDiez,"%d",ll_count(pArrayList,cantidad_VentasMayorADiezmil));
		sprintf(ventasMayorVeinte,"%d",ll_count(pArrayList,cantidad_VentasMayorAVeintemil));
		sprintf(cantidadTvs,"%d",ll_count(pArrayList,cantidad_TVsLCD));

      	printf("\n\nLa cantidad de ventas total es: %s\n",cantidadV);
        printf("La cantidad de ventas monto mayor a 10000 es: %s\n",ventasMayorDiez);
        printf("La cantidad de ventas monto mayor a 20000 es: %s\n",ventasMayorVeinte);
        printf("La cantidad de TVs LCD vendidos es: %s\n",cantidadTvs);



		fwrite(titulo,sizeof(char),strlen(titulo),path);
		fprintf(path,"- Cantidad de unidades vendidas totales: %s\n- Cantidad de ventas por un monto mayor a $10000: %s\n",cantidadV,ventasMayorDiez);
		fprintf(path,"- Cantidad de ventas por un monto mayor a $20000: %s\n- Cantidad de TVs LCD vendidas: %s\n\n********************",ventasMayorVeinte,cantidadTvs);
		ret=1;



	}
	return ret;
}
