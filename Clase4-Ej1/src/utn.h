/*
 * utn.h
 *
 *  Created on: 2 abr. 2020
 *      Author: aleja
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroConDecimales(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getTexto(char pTexto[], char* mensaje, char* mensajeError, int reintentos, int size);


#endif /* UTN_H_ */


