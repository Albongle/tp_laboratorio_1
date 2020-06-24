/*
 * ventas.c
 *
 *  Created on: 17 jun. 2020
 *      Author: aleja
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ventas.h"




eVentas* eVentas_new()
{
	eVentas* this=(eVentas*) malloc(sizeof(eVentas));
	if(this!=NULL)
	{
		eVentas_setId(this,0);
		eVentas_setFecha(this,"");
		eVentas_setCodigoProducto(this,"");
		eVentas_setCantidad(this,0);
		eVentas_setPrecioUnit(this,0);
		eVentas_setCuit(this,"");
		eVentas_setMonto(this,0);
	}
	return this;
}

eVentas* eVentas_newParametros(char* id_VentaStr,char* fecha,char* codigo, char* cantidadStr,char* precioUnitStr,char*cuit, char* monto)
{
	eVentas* this=eVentas_new();

		if(this!=NULL && id_VentaStr!=NULL && fecha!=NULL && codigo!=NULL && cantidadStr!=NULL && precioUnitStr!=NULL && cuit!=NULL && monto!=NULL)
		{

			eVentas_setId(this,atoi(id_VentaStr));
			eVentas_setFecha(this,fecha);
			eVentas_setCodigoProducto(this,codigo);
			eVentas_setCantidad(this,atoi(cantidadStr));
			eVentas_setPrecioUnit(this,atof(precioUnitStr));
			eVentas_setCuit(this,cuit);
			eVentas_setMonto(this,atof(monto));
		}
		return this;

}

int eVentas_setId(eVentas* this,int id)
{
	int ret=0;
	static int maxId=0;
	if (this!=NULL)
	{
		if(id<0)
		{
			maxId++;
			this->id_Venta=maxId;
		}
		else
		{
			if(id>maxId)
			{
				maxId=id;
			}
			this->id_Venta=id;
		}
		ret=1;
	}
	return ret;
}

int eVentas_getId(eVentas* this,int* id)
{
	int ret=0;
		if (this!=NULL && id !=NULL)
		{
			*id=this->id_Venta;
			ret=1;
		}
		return ret;

}

int eVentas_setFecha(eVentas* this,char* fecha)
{
	int ret=0;


	if (this!=NULL && fecha!=NULL)
	{
		strcpy(this->fecha, fecha);
		ret=1;
	}
	return ret;
}



int eVentas_getFecha(eVentas* this,char* fecha)
{
	int ret=0;
		if (this!=NULL && fecha !=NULL)
		{
			strcpy(fecha,this->fecha);
			ret=1;
		}
		return ret;

}



int eVentas_setCodigoProducto(eVentas* this,char* codigo)
{
	int ret=0;

	if (this!=NULL && codigo!=NULL)
	{
		strcpy(this->codigo_prod,codigo);
		ret=1;
	}
	return ret;
}

int eVentas_getCodigoProducto(eVentas* this,char* codigo)
{
	int ret=0;

	if (this!=NULL && codigo!=NULL)
	{
		strcpy(codigo,this->codigo_prod);
		ret=1;
	}
	return ret;
}




int eVentas_setCantidad(eVentas* this,int cantidad)
{
	int ret=0;

	if (this!=NULL && cantidad>=0)
	{
		this->cantidad=cantidad;
		ret=1;
	}
	return ret;
}

int eVentas_getCantidad(eVentas* this,int* cantidad)
{
	int ret=0;

	if (this!=NULL && cantidad!=NULL)
	{
		*cantidad=this->cantidad;
		ret=1;
	}
	return ret;
}



int eVentas_setPrecioUnit(eVentas* this,float precio)
{
	int ret=0;

	if (this!=NULL)
	{
		this->precioUnit=precio;
		ret=1;
	}
	return ret;
}

int eVentas_getPrecioUnit(eVentas* this,float* precio)
{
	int ret=0;

	if (this!=NULL && precio!=NULL)
	{
		*precio=this->precioUnit;
		ret=1;
	}
	return ret;
}


int eVentas_setCuit(eVentas* this,char* cuit)
{
	int ret=0;

	if (this!=NULL && cuit!=NULL)
	{
		strcpy(this->cuitCliente, cuit);
		ret=1;
	}
	return ret;
}

int eVentas_getCuit(eVentas* this,char* cuit)
{
	int ret=0;

	if (this!=NULL && cuit!=NULL)
	{
		strcpy(cuit,this->cuitCliente);
		ret=1;
	}
	return ret;
}

int eVentas_setMonto(eVentas* this,float monto)
{
	int ret=0;

	if (this!=NULL && monto>=0)
	{
		this->monto=monto;
		ret=1;
	}
	return ret;
}

int eVentas_getMonto(eVentas* this,float* monto)
{
	int ret=0;

	if (this!=NULL && monto!=NULL)
	{
		*monto=this->monto;
		ret=1;
	}
	return ret;
}


int ventas_Print(eVentas* this)
{
	int ret=0;
	int id;
	char fecha[30];
	char codigoProducto[30];
	int cantidad;
	float precioUnit;
	char cuit[30];
	if (this!=NULL)
	{
		if(eVentas_getId(this,&id))
		{
			if(eVentas_getFecha(this,fecha))
			{
				if(eVentas_getCodigoProducto(this,codigoProducto))
				{
					if(eVentas_getCantidad(this,&cantidad))
					{
						if(eVentas_getPrecioUnit(this,&precioUnit))
						{
							if(eVentas_getCuit(this,cuit))
							{
								printf("%d\t%s\t\t%-15.15s\t\t%d\t\t%13.2f\t\t%-13.13s\n",id,fecha,codigoProducto,cantidad,precioUnit,cuit);
								ret=1;
							}
						}
					}
				}
			}
		}
	}

	return ret;
}


int cantidad_Ventas(void* pElement)
{
	int returnAux=0;

	if(pElement!=NULL)
	{
		pElement=(eVentas*) pElement;
		eVentas_getCantidad(pElement,&returnAux);
	}
	return returnAux;
}


int cantidad_VentasMayorADiezmil(void* pElement)
{
	int returnAux=0;
	int cantidad;
	float precioUnit;
	float monto;

	if(pElement!=NULL)
	{
		pElement=(eVentas*) pElement;
		eVentas_getCantidad(pElement,&cantidad);
		eVentas_getPrecioUnit(pElement,&precioUnit);
		monto= cantidad*precioUnit;
		if(monto>10000)
		{
			returnAux=1;
		}
	}
	return returnAux;
}

int cantidad_VentasMayorAVeintemil(void* pElement)
{
	int returnAux=0;
	int cantidad;
	float precioUnit;
	float monto;

	if(pElement!=NULL)
	{
		pElement=(eVentas*) pElement;
		eVentas_getCantidad(pElement,&cantidad);
		eVentas_getPrecioUnit(pElement,&precioUnit);
		monto= cantidad*precioUnit;
		if(monto>20000)
		{
			returnAux=1;
		}
	}
	return returnAux;
}

int cantidad_TVsLCD(void* pElement)
{
	int returnAux=0;
	int cantidad=0;
	char codigo[30];


	if(pElement!=NULL)
	{
		pElement=(eVentas*) pElement;
		eVentas_getCantidad(pElement,&cantidad);
		eVentas_getCodigoProducto(pElement,codigo);

		if(stricmp(codigo,"LCD_TV")==0)
		{
			returnAux=cantidad;
		}
	}
	return returnAux;
}
