/*
 * parser.h
 *
 *  Created on: 6 jun. 2020
 *      Author: aleja
 */

#include "LinkedList.h"
#ifndef PARSER_H_
#define PARSER_H_



/** \brief Parsea los datos los datos de los empleados desde el archivo data_prod.csv (modo texto).
 *
 * \param path FILE* es el puntero a la referencia del archivo
 * \param pArrayListEmployee LinkedList*, es el listado que almacena las posiciones de memorias de las ventas
 * \return int
 *
 */
int parser_VentasComoTexto(FILE* pFile , LinkedList* pArrayList);

/** \brief guarda los datos de los empleados en un archivo el archivo informe.txt (modo texto).
 *
 * \param path FILE* es el puntero a la referencia del archivo
 * \param pArrayListEmployee LinkedList*, es el listado que almacena las posiciones de las ventas
 * \return int
 *
 */
int guardarVentascomoTexto(FILE* path , LinkedList* pArrayList);



#endif /* PARSER_H_ */
