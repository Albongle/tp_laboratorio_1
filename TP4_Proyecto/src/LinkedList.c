#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    if((this=(LinkedList*) malloc(sizeof(LinkedList)))!=NULL)
    {
    	this->size=0;
    	this->pFirstNode=NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	returnAux=this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNodeAux=NULL;
	int i;
	if(this!=NULL && nodeIndex>=0 && nodeIndex<ll_len(this))
	{
		pNodeAux=this->pFirstNode;
		for(i=0;i<nodeIndex;i++)
		{
			pNodeAux=pNodeAux->pNextNode;
		}
	}

    return pNodeAux;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNodePrev=NULL;
    Node* pNuevoNodo=NULL;

    if(this!=NULL && nodeIndex>=0 && nodeIndex<=ll_len(this))
	{
    	if((pNuevoNodo=(Node*)malloc(sizeof(Node)))!=NULL)
		{
    		pNuevoNodo->pNextNode=NULL;
    		pNuevoNodo->pElement=pElement;
    		if(nodeIndex==0)
    		{
    			pNuevoNodo->pNextNode=this->pFirstNode;
    			this->pFirstNode=pNuevoNodo;
    		}
    		else if(nodeIndex==ll_len(this))
    		{
    			pNodePrev=getNode(this,(nodeIndex-1));
    			pNodePrev->pNextNode=pNuevoNodo;
    		}
    		else
    		{
    			pNodePrev=getNode(this,nodeIndex-1);
    			pNuevoNodo->pNextNode=pNodePrev->pNextNode;
    			pNodePrev->pNextNode=pNuevoNodo;

    		}
    		returnAux=0;
    		this->size++;

	   }

   }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if (this!=NULL)
    {
    	if((addNode(this,ll_len(this),pElement))==0)
    	{
    		returnAux=0;
    	}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNodeAux=NULL;

    if(this!=NULL && index >=0 && index <ll_len(this))
    {
    	if((pNodeAux=getNode(this,index))!=NULL)
    	{
    		returnAux=pNodeAux->pElement;
    	}
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNodeAux=NULL;

    if(this!=NULL && index >=0 && index <ll_len(this))
    {
    	if((pNodeAux=getNode(this,index))!=NULL)
    	{
    		pNodeAux->pElement=pElement;
    		returnAux=0;
    	}
    }


    return returnAux;
}



/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNodeAuxPrev;
    Node* pNodeAux;
    if(this!=NULL && index>=0 && index<ll_len(this))
    {
    	pNodeAux=getNode(this,index);
    	if(index==0)
    	{
    		this->pFirstNode=pNodeAux->pNextNode;

    	}
    	else
    	{
    		pNodeAuxPrev = getNode(this,index-1);
    		pNodeAuxPrev->pNextNode=pNodeAux->pNextNode;
    	}
    	free(pNodeAux);
   		this->size--;
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    int tam;
    if(this!=NULL)
    {
    	tam=ll_len(this);
    	for(i=0;i<tam;i++)
    	{
    		ll_remove(this,i);
    	}
    	returnAux=0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	if(ll_clear(this)==0)
    	{
    		free(this);
    		returnAux=0;
    	}
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int cont=0;
    Node* pNodeAux=NULL;
    if(this!=NULL)
    {
    	pNodeAux=this->pFirstNode;
    	while(pNodeAux!=NULL)
    	{
    		if(pNodeAux->pElement==pElement)
    		{
    			returnAux=cont;
    			break;
    		}
    		cont++;
    		pNodeAux=pNodeAux->pNextNode;
    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	if(ll_len(this)==0)
    	{
    		returnAux=1;
    	}
    	else
    	{
    		returnAux=0;
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL && index>=0 && index <=ll_len(this))
    {
    	if(addNode(this,index,pElement)==0)
    	{
    		returnAux=0;
    	}
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* pNodeAux=NULL;
    if(this!=NULL && index>=0 && index<ll_len(this))
    {
    	if((pNodeAux=getNode(this,index))!=NULL)
    	{
    		returnAux=pNodeAux->pElement;
    		ll_remove(this,index);
    	}

    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	if(ll_indexOf(this,pElement)>=0)
    	{
    		returnAux=1;
    	}
    	else
    	{
    		returnAux=0;
    	}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    Node* pNodeAux=NULL;
    int cont=0;
    if(this!=NULL && this2!=NULL)
    {
    	pNodeAux=this2->pFirstNode;
    	while(pNodeAux!=NULL)
    	{
    		if(ll_contains(this,pNodeAux->pElement))
    		{
    			cont++;
    		}
    		pNodeAux=pNodeAux->pNextNode;
    	}

    	if(cont==ll_len(this2))
    	{
    		returnAux=1;
    	}
    	else
    	{
    		returnAux=0;
    	}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
	int i;
	Node* pNodeAux= NULL;
    LinkedList* cloneArray = NULL;
    if(this!=NULL && from>=0 && from<ll_len(this) && to>from && to<=ll_len(this))
    {
    	if((cloneArray=ll_newLinkedList())!=NULL)
    	{
    		for(i=from;i<to;i++)
    		{
    			pNodeAux=getNode(this,i);
    			addNode(cloneArray,i,pNodeAux->pElement);
    		}
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this!=NULL)
    {
    	cloneArray=ll_subList(this,0,ll_len(this));
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* pElementAux=NULL;
    void* pElement1= NULL;
    void* pElement2= NULL;
    int i;
    int cont=0;
    int flag=1;
    if(this!=NULL && pFunc!=NULL && (order==0 || order==1))
    {
    	while(flag)
    	{
    		cont++;
    		flag=0;
    		for(i=0 ;i<(ll_len(this)-cont);i++)
    		{
    			pElement1=ll_get(this,i);
    			pElement2=ll_get(this,i+1);
    			switch (order)
    			{
    				case 0:
    				{
	                    if(pFunc(pElement1,pElement2)==-1)
	                    {
	                        pElementAux=pElement1;
	                        ll_set(this,i,pElement2);
	                        ll_set(this,i+1,pElementAux);
	                        flag=1;
	                    }
    					break;
    				}
    				case 1:
    				{
	                    if(pFunc(pElement1,pElement2))
	                    {
	                        pElementAux=pElement1;
	                        ll_set(this,i,pElement2);
	                        ll_set(this,i+1,pElementAux);
	                        flag=1;
	                    }
    					break;
    				}
    			}
    		}
    	}
    	returnAux=0;
    }
    return returnAux;
}


LinkedList* ll_map(LinkedList* this, void (*pFunc)(void* element))
{
	int i;
	if(this!=NULL && pFunc!=NULL)
	{
		for(i=0; i<ll_len(this);i++)
		{
			pFunc(ll_get(this,i));
		}

	}
return this;
}

int ll_count(LinkedList* this, int (*pFunc)(void* element))
{
	int returnAux=0;
	int i;
	if(this!=NULL && pFunc!=NULL)
	{
		for(i=0; i<ll_len(this);i++)
		{
			returnAux+=pFunc(ll_get(this,i));
		}

	}
	return returnAux;
}
