/*
 * utn.h
 *
 *  Created on: 10 abr. 2020
 *      Author: aleja
 */

#ifndef UTN_H_
#define UTN_H_

/**
 * brief realiza la validacion del ingreso de numeros enteros esbalenciendo un rango de posibilidades
 * param pMensaje es el mensaje que se va a mostrar antes de solicitar el ingreso
 * param pMensajeError es el mensaje de error que se va a informar en caso que el ingreso no cumpla las condiciones
 * param minimo es donde se debera establecer el numero minimo permitido a ingresar
 * param maximo es donde se debera establecer el numero maximo permitido a ingresar
 * param reintentos es la cantidad de reintentos que se le va a birndar al usuario en caso de error
 * *pNumero devolvera por puntero el numero ingresado
 * return 1 en caso exitoso
 */
int utn_getNumero(int* pNumero, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos);
/**
 * brief realiza la validacion del ingreso de numeros flotantes positivos y negativos, esbalenciendo un rango de posibilidades
 * param pMensaje es el mensaje que se va a mostrar antes de solicitar el ingreso
 * param pMensajeError es el mensaje de error que se va a informar en caso que el ingreso no cumpla las condiciones
 * param minimo es donde se debera establecer el numero minimo permitido a ingresar
 * param maximo es donde se debera establecer el numero maximo permitido a ingresar
 * param reintentos es la cantidad de reintentos que se le va a birndar al usuario en caso de error
 * *pNumero devolvera por puntero el numero ingresado
 * return 1 en caso exitoso
 */
int utn_getNumeroConDecimales(float* pNumero, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos);
/**
 * brief realiza la validacion del ingreso cadenas de texto con las contenmplando espacios en la misma
 * param pMensaje es el mensaje que se va a mostrar antes de solicitar el ingreso
 * param pMensajeError es el mensaje de error que se va a informar en caso que el ingreso no cumpla las condiciones
 * param reintentos es la cantidad de reintentos que se le va a birndar al usuario en caso de error
 * param size es el tamaño que se la va a signar a dicha cadena de texto
 * *pIngreso devolvera por puntero el texto ingresado
 * return 1 en caso exitoso
 */
int utn_getTexto(char* pIngreso, char* pMensaje, char* pMensajeError, int reintentos, int size);
/**
 * brief realiza la validacion del ingreso de caracteres
 * param pMensaje es el mensaje que se va a mostrar antes de solicitar el ingreso
 * param pMensajeError es el mensaje de error que se va a informar en caso que el ingreso no cumpla las condiciones
 * param pRango es la cadena de caracteres sobre la cual se va a calidar el ingreso, debera de ingresarse '\0' para indicar el final de la cadena
 * param reintentos es la cantidad de reintentos que se le va a birndar al usuario en caso de error
 * *pCaracter devolvera por puntero el caracter ingresado
 * return 1 en caso exitoso
 */
int utn_getCaracter(char* pCaracter, char* pMensaje, char* pMensajeError,char* pRango, int reintentos);
/**
 * brief realiza la validacion del ingreso de Fecha
 * param pDia es el puntero del dia de la fecha que retoranara
 * param pMes es el puntero del mes de la fecha que retoranara
 * param pAnio es el puntero del año de la fecha que retoranara
 * param pMensaje es el mensaje que se va a mostrar antes de solicitar el ingreso
 * param pMensajeError es el mensaje de error que se va a informar en caso que el ingreso no cumpla las condiciones
 * param minDia es el valor minimo de numero de dia a permitir el ingreso
 * param minMes es el valor minimo de numero de mes a permitir el ingreso
 * param minAnio es el valor minimo de numero de año a permitir el ingreso
 * param maxDia es el valor maximo de numero de dia a permitir el ingreso
 * param maxMes es el valor maximo de numero de mes a permitir el ingreso
 * param maxAnio es el valor maximo de numero de año a permitir el ingreso
 * param reintentos es la cantidad de reintentos que se le va a birndar al usuario en caso de error
 * return 1 en caso exitoso
 */

int utn_getFecha(int* pDia,int* pMes, int* pAnio , char* pMensaje, char* pMensajeError, int minDia, int maxDia, int minMes, int maxMes,int minAnio, int maxAnio, int reintentos);
/**
 * brief realiza la validacion del ingreso de un CUIL en una cadena de texto
 * param pMensaje es el mensaje que se va a mostrar antes de solicitar el ingreso
 * param pMensajeError es el mensaje de error que se va a informar en caso que el ingreso no cumpla las condiciones
 * param reintentos es la cantidad de reintentos que se le va a birndar al usuario en caso de error
 * param size es el tamaño que se la va a signar a dicha cadena de texto
 * *pIngreso devolvera por puntero el CUIL ingresado
 * return 1 en caso exitoso
 */

int utn_getCuil(char* pIngreso, char* pMensaje, char* pMensajeError, int reintentos, int size);


#endif /* UTN_H_ */
