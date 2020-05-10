/*
 * informes.h
 *
 *  Created on: 4 may. 2020
 *      Author: aleja
 */
#include "sector.h"
#include "empleados.h"


#ifndef INFORMES_H_
#define INFORMES_H_


/**
 * brief recibe los aarrays de empleado y secortores, ordena y luego imprime
 * param pArrayEmpleados, es el array de empleados
 * param tamArrayEmpleadosr es tama�o del array de empleados
 * pArraySectores es el array de sectores
 * param tamArraySectores es el tama�o del array de secores
 * param sentido es el sentido en el que se va a ordenar el array de empleados, deberia ingresarse el caracter '>' para ordenar de manera descendente o '<' para ordenar de manera ascendente
 */
void empleadosOrdenados(eEmpleados* pArrayEmpleados,int tamArrayEmpleados,eSector* pArraySectores, int tamArraySectores, char sentido);
/**
 * brief recibe los aarrays de empleado para calcular total/promedio de salarios y el Q de empleados que superan el promedio del salario
 * param pArrayEmpleados, es el array de empleados
 * param tamArrayEmpleadosr es tama�o del array de empleados
 */
void totYpromSalario(eEmpleados* pArrayEmpleados,int tamArrayEmpleados);

#endif /* INFORMES_H_ */
