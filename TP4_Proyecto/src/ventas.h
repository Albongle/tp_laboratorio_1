/*
 * ventas.h
 *
 *  Created on: 17 jun. 2020
 *      Author: aleja
 */

#ifndef VENTAS_H_
#define VENTAS_H_


typedef struct eVentas{

	int id_Venta;
	char fecha[30];
	char codigo_prod[30];
	int cantidad;
	float precioUnit;
	char cuitCliente [30];
	float monto;


}eVentas;
/** \brief reserva memoria para una estructura de tipo ventas e inicializa los campos,
 * retornado su posicion de moemora.
 * \param void
 * \return eVentas* retorna el puntero a la estructura
 */
eVentas* eVentas_new();
/** \brief reserva memoria para una estructura de tipo eVentas y carga la informacion enviada,
 *  retornado su posicion de moemora.
 * \param id_VentaStr
 * \param fecha,
 * \param codigo,
 * \param cantidadStr
 * \param precioUnitStr
 * \param cuit
 * \param monto
 * \return eVentas* retorna el puntero a la estructura
 */
eVentas* eVentas_newParametros(char* id_VentaStr,char* fecha,char* codigo, char* cantidadStr, char* precioUnitStr,char*cuit, char* monto);

/** \brief funcion usada para cargar el Id
 * \param this, es el puntero de la estructura
 * \param id, es el valor que se va asignar
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */
int eVentas_setId(eVentas* this,int id);

/** \brief funcion usada para obtener el Id
 * \param this, es el puntero a la estructura de empleado
 * \param id, es el puntero del valor a obtener
 * \return int 1 en caso de coincidir o 0 en caso contrario
 */
int eVentas_getId(eVentas* this,int* id);
/** \brief funcion usada para cargar la fecha
 * \param this, es el puntero de la estructura
 * \param fecha, es el valor que se va asignar
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */
int eVentas_setFecha(eVentas* this,char* fecha);
/** \brief funcion usada para obtener la fecha
 * \param this, es el puntero a la estructura de empleado
 * \param fecha, es el puntero del valor a obtener
 * \return int 1 en caso de coincidir o 0 en caso contrario
 */
int eVentas_getFecha(eVentas* this,char* fecha);
/** \brief funcion usada para cargar el codigo del prodcuto
 * \param this, es el puntero de la estructura
 * \param codigo, es el valor que se va asignar
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */
int eVentas_setCodigoProducto(eVentas* this,char* codigo);
/** \brief funcion usada para obtener el codigo de un producto
 * \param this, es el puntero a la estructura de empleado
 * \param codigo, es el puntero del valor a obtener
 * \return int 1 en caso de coincidir o 0 en caso contrario
 */
int eVentas_getCodigoProducto(eVentas* this,char* codigo);
/** \brief funcion usada para cargar la cantidad de ventas
 * \param this, es el puntero de la estructura
 * \param cantidad, es el valor que se va asignar
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */
int eVentas_setCantidad(eVentas* this,int cantidad);
/** \brief funcion usada para obtener la cantidad de ventas
 * \param this, es el puntero a la estructura de empleado
 * \param cantidad, es el puntero del valor a obtener
 * \return int 1 en caso de coincidir o 0 en caso contrario
 */
int eVentas_getCantidad(eVentas* this,int* cantidad);
/** \brief funcion usada para cargar el precio
 * \param this, es el puntero de la estructura
 * \param precio, es el valor que se va asignar
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */
int eVentas_setPrecioUnit(eVentas* this,float precio);
/** \brief funcion usada para obtener el precio unitario
 * \param this, es el puntero a la estructura de empleado
 * \param precio, es el puntero del valor a obtener
 * \return int 1 en caso de coincidir o 0 en caso contrario
 */
int eVentas_getPrecioUnit(eVentas* this,float* precio);
/** \brief funcion usada para cargar cuit del cliente
 * \param this, es el puntero de la estructura
 * \param cuit, es el valor que se va asignar
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */
int eVentas_setCuit(eVentas* this,char* cuit);
/** \brief funcion usada para obtener el cuit del cliente
 * \param this, es el puntero a la estructura de empleado
 * \param cuit, es el puntero del valor a obtener
 * \return int 1 en caso de coincidir o 0 en caso contrario
 */
int eVentas_getCuit(eVentas* this,char* cuit);
/** \brief funcion usada para cargar monto de la venta
 * \param this, es el puntero de la estructura
 * \param monto, es el valor que se va asignar
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */
int eVentas_setMonto(eVentas* this,float monto);
/** \brief funcion usada para obtener el monto de la venta
 * \param this, es el puntero a la estructura de empleado
 * \param monto, es el puntero del valor a obtener
 * \return int 1 en caso de coincidir o 0 en caso contrario
 */
int eVentas_getMonto(eVentas* this,float* monto);

/** \brief funcion usada para imprimir las ventas
 * \param this, es el puntero de la estructura de empleado
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */
int ventas_Print(eVentas* this);

/** \brief funcion criterio usada para obtener la cantidad de ventas de un elemento
 * \param pElement, es el puntero que recibira al elemento la funcion al ser llamada desde linkdelist
 * \return int la cantidad de ventas del elemento recibido
 */
int cantidad_Ventas(void* pElement);
/** \brief funcion criterio usada para contar la ventas con monto mayor a 10000
 * \param pElement, es el puntero que recibira al elemento la funcion al ser llamada desde linkdelist
 * \return int retorna 1 si el monto de el elemento recibido cumple con el criterio, en caso contrario 0
 */
int cantidad_VentasMayorADiezmil(void* pElement);
/** \brief funcion criterio usada para contar la ventas con monto mayor a 20000
 * \param pElement, es el puntero que recibira al elemento la funcion al ser llamada desde linkdelist
 * \return int retorna 1 si el monto de el elemento recibido cumple con el criterio, en caso contrario 0
 */
int cantidad_VentasMayorAVeintemil(void* pElement);
/** \brief funcion criterio usada para devolver la cantidad de ventas de un producto particular
 * \param pElement, es el puntero que recibira al elemento la funcion al ser llamada desde linkdelist
 * \return int retorna la cantidad en caso de cumplir la condicion, 0 en caso contrario.
 */
int cantidad_TVsLCD(void* pElement);


#endif /* VENTAS_H_ */
