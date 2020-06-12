#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief reserva memoria para una estructura de tipo empleado e inicializa los campos,
 * retornado su posicion de moemora.
 * \param void
 * \return Employee* retorna el puntero a la estructura
 */
Employee* employee_new();


/** \brief reserva memoria para una estructura de tipo empleado y carga la informacion enviada,
 *  retornado su posicion de moemora.
 * \param idStr, es el Id generado para el nuevo empleado
 * \param nombreStr, es el nombre del nuevo empleado
 * \param horasTrabajasStr, es la cantidad de horas trabajadas
 * \param sueldoStr, es el sueldo del empleado
 * \return Employee* retorna el puntero a la estructura
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);


/** \brief evalua si el Id enviado como valor pertenece a la estructura de la posicion de memoria recibida
 * \param this, es el puntero a la estructura de empleado
 * \param id, es el id valor
 * \return int 1 en caso de coincidir o 0 en caso contrario
 */
int employee_getPos(Employee* this,int id);

/** \brief genera el alta de un nuevo empleado de manera manual, retorna por puntero la posicion de memoria conseguida.
 * \param this, es el puntero que apunta a la estructura de empleado
 * \return int 1 en caso de exitoso, 0 en caso  exista algun error en los parametros o -1 en caso que no haya memoria
 */
int employee_Add(Employee** this);

/** \brief funcion usada para editar un empleado.
 * \param this, es el puntero de la estructura de empleado
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */
int employee_edit(Employee* this);

/** \brief funcion usada para eliminar un empleado.
 * \param this, es el puntero de la estructura de empleado
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */
int employee_delete(Employee* this);

/** \brief funcion usada para imprimir un empleado.
 * \param this, es el puntero de la estructura de empleado
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */
int employee_Print(Employee* this);

/** \brief funcion usada para cargar el Id a un empleado.
 * \param this, es el puntero de la estructura de empleado
 * \param id, es el valor que se va asignar al empleado
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */
int employee_setId(Employee* this,int id);

/** \brief funcion usada para obtener el Id a un empleado.
 * \param this, es el puntero de la estructura de empleado
 * \param *id, es el puntero donde se va a guardar el id del empleado
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */
int employee_getId(Employee* this,int* id);

/** \brief funcion usada para establecer el nombre a un empleado.
 * \param this, es el puntero de la estructura de empleado
 * \param *nombre, es el nombre del empleado a asignar
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief funcion usada para obtener el nombre de un empleado.
 * \param this, es el puntero de la estructura de empleado
 * \param *nombre, es el puntero de la variable donde se va a guardar el nombre obtenido
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief funcion usada para establecer las horas trabajadas a un empleado.
 * \param this, es el puntero de la estructura de empleado
 * \param horasTrabajadas, es el valor que se le va a signar a ese empleado
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief funcion usada para obtener las horas trabajadas de un empleado.
 * \param this, es el puntero de la estructura de empleado
 * \param *horasTrabajadas, es el puntero donde se van a guardar la informacion
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief funcion usada para establecer el sueldo de un empleado.
 * \param this, es el puntero de la estructura de empleado
 * \param sueldo, es valor a asignar como sueldo
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief funcion usada para obtener el sueldo de un empleado.
 * \param this, es el puntero de la estructura de empleado
 * \param *sueldo, es el puntero donde se guardara el valor obtenido
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief funcion usada para obtener todos los datos de un empleado como string
 * \param this, es el puntero de la estructura de empleado
 * \param *id, es el puntero donde se va a guardar el id del empleado
 * \param *nombre, es el puntero donde se va a guardar el nombre obtenido
 * \param *horasTrabajadas, es el puntero donde se van a guardar la informacion
 * \param *sueldo, es el puntero donde se guardara el valor obtenido
 * \return int 1 en caso de exitoso, 0 en caso  contrario
 */
int employee_getDatos(Employee* this,char* id,char* nombre,char* horasTrabajadas,char* sueldo);

/** \brief funcion criterio utilizada para relizar el ordenamiento por nombre
 * en caso que estos sean igual compara por sueldo
 * \param emp1, es el puntero usado para obetener los datos a comparar con emp2
 * \param emp2, es el puntero usado para obetener los datos a comparar con emp1
 * \return int 1 en caso que la comparacion sea valida, -1 en caso contrario
 */
int employee_OrdenPorNombre(void* emp1,void* emp2);

/** \brief funcion criterio utilizada para relizar el ordenamiento por sueldo
 *  la funcion es convocada desde la funcion employee_OrdenPorNombre
 * \param emp1, es el puntero usado para obetener los datos a comparar con emp2
 * \param emp2, es el puntero usado para obetener los datos a comparar con emp1
 * \return int 1 en caso que la comparacion sea valida, -1 en caso contrario
 */
int employee_OrdenaPorSueldo(void* emp1,void* emp2);
#endif // employee_H_INCLUDED
