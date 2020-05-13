/*
 * employees.h
 *
 *  Created on: 3 may. 2020
 *      Author: aleja
 */
#include "sector.h"
#ifndef EMPLEADOS_H_
#define EMPLEADOS_H_


typedef struct{
int id;
char nombre[51];
char apellido[51];
float sueldo;
int sector;
int isEmpty;
}eEmpleados;



/**
 * brief iniciliza array
 * param pArrayEmpleados es el array que se va a inicializar
 * param tam es el tamaño del array
 * param valorInt es el valor que se envia para cargar en el array
 */
void inicializarEmpleados(eEmpleados* pArrayEmpleados,int tam,int valorInt);
/**
 * brief realiza el alta de empleados
 * param pArrayEmpleados es el array que se va a inicializar
 * param tamArrayEmpleados es el tamaño del array de empleados
 * param id, es el ID que se le va a asignar al empleado al momento del alta
 * param pArraysectores es el array que se va a inicializar
 * param tamArraysectores es el tamaño del array de sectores a los cuales puede pertencer el empleado
 * return 1 en caso exitoso
 */
int altaEmpleado(eEmpleados* pArrayEmpleados, int tamArrayEmpleados, int id, eSector* pArraysectores, int tamArraysectores);
/**
 * brief realiza la baja de empleados
 * param pArrayEmpleados es el array  de empleados
 * param tamArrayEmpleados es el tamaño del array de empleados
 * param pArraysectores es el array de sectores
 * param tamArraysectores es el tamaño del array de sectores a los cuales puede pertencer el empleado
 * return 1 en caso exitoso o 0 en caso de haber cancelado la baja
 */
int bajaEmpleado(eEmpleados* pArrayEmpleados, int tamArrayEmpleados, eSector* pArraySectores, int tamArraySectores);
/**
 * brief realiza la modificacion de empleados
 * param pArrayEmpleados es el array  de empleados
 * param tamArrayEmpleados es el tamaño del array de empleados
 * param id, es el ID del empleado que se va a modificar
 * param pArraysectores es el array de sectores
 * param tamArraysectores es el tamaño del array de sectores a los cuales puede pertencer el empleado
 * return 1 en caso exitoso o 0 en caso de haber cancelado la modificacion
 */
int modificarEmpleados(eEmpleados* pArrayEmpleados, int tamArrayEmpleados, int id, eSector* pArraySectores, int tamArraySectores);
/**
 * brief realiza el ordenamiento del array por 2 opciones primero por apellido y luego por nombre de sector
 * param pArrayEmpleados es el array de empleados
 * param tamArrayEmpleados es el tamaño del array de empleados
 * param pArraysectores es el array de sectores
 * param tamArraysectores es el tamaño del array de sectores a los cuales puede pertencer el empleado
 * param sentido es el sentido para realizar el ordenamiento, debe asignarse '0' (descendente) o '1'(ascendente)
 * return 1 en caso exitoso o 0 en caso contrario
 */
int ordenaEmpleados(eEmpleados* pArrayEmpleados,int tamArrayEmpleados,eSector* pArraySectores, int tamArraySectores, int sentido);
/**
 * brief imprime empleados
 * param pArrayEmpleados es el array de empleados
 * param tamArrayEmpleados es el tamaño del array de empleados
 * param pArraysectores es el array de sectores
 * param tamArraysectores es el tamaño del array de sectores a los cuales puede pertencer el empleado
 */
void imprimeEmpleados(eEmpleados* pArrayEmpleados, int tamArrayEmpleados, eSector* pArraySectores, int tamArraySectores);
/**
 * brief harcodea empleados
 * param pArrayEmpleados es el array de empleados
 * param tam es el tamaño del array de empleados
 * param cantidad es la cantidad de empleados que se quiere harcodear, la funcion cuenta de 10 resgistros
 */
int hardcodearEmpleados(eEmpleados* pArrayEmpleados, int tam, int cantidad);
/**
 * brief funcion usada para chequear el Q de posiciones libres
 * param pArrayEmpleados es el array de empleados
 * param tam es el tamaño del array de empleados
 * return la cantidad de posiciones libres
 */
int buscaVacios(eEmpleados* pArrayEmpleados, int tam);

#endif /* EMPLEADOS_H_ */
