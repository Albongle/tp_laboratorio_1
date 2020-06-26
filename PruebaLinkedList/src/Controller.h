

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* es la referencia del archivo
 * \param pArrayListEmployee LinkedList*, es el listado que almacena las posiciones de memorias de los empleados
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* es la referencia del archivo
 * \param pArrayListEmployee LinkedList*, es el listado que almacena las posiciones de memorias de los empleados
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);


/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*, es el listado que almacena las posiciones de memorias de los empleados
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);


/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList*, es el listado que almacena las posiciones de memorias de los empleados
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);
/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList*, es el listado que almacena las posiciones de memorias de los empleados
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*, es el listado que almacena las posiciones de memorias de los empleados
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList*, es el listado que almacena las posiciones de memorias de los empleados
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 * \param path char* es la referencia del archivo
 * \param pArrayListEmployee LinkedList*, es el listado que almacena las posiciones de memorias de los empleados
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* es la referencia del archivo
 * \param pArrayListEmployee LinkedList*, es el listado que almacena las posiciones de memorias de los empleados
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief libera momoria en los momentos necesarios.
 *
 * \param pArrayListEmployee LinkedList*es el listado que almacena las posiciones de memorias de los empleados
 * \return int
 *
 */

int controller_memoryFree(LinkedList* pArrayListEmployee);


