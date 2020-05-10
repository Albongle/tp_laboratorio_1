/*
 * sector.h
 *
 *  Created on: 3 may. 2020
 *      Author: aleja
 */

#ifndef SECTOR_H_
#define SECTOR_H_

typedef struct{
int idSector;
char descripcion[20];
}eSector;


/**
 * brief imprime un sector que se pasa por parametro
 * param pArraySectores es el parameto del array a imprimir
 */
void mostrarSector(eSector pArraySectores);
/**
 * brief imprime todos los sectores
 * param pArraySectore es el array de sectores
 * param tam es el tamaño del array de sectores a los cuales puede pertencer el empleado
 */
void mostrarSectores(eSector* pArraySectores, int tam);
/**
 * brief busca un sector por ID y devuelve por puntero el nombre de este
 * param pArraySectore es el array de sectores
 * param valorBuscado es el ID que se va a buscar
 * param tamArraySectores es el tamaño del array de sectores a los cuales puede pertencer el empleado
 * param descrSector es el puntero donde asignara el nombre ecnontrado para el ID buscado
 * return 1 en caso de haber encontrado un valor, 0 en caso negativo
 */
int buscarSector(eSector* pArraySectores,int valorBuscado, int tamArraySectores, char* descrSector);

#endif /* SECTOR_H_ */
