#ifndef __SLIST_H__
#define __SLIST_H__

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef void (*FuncionVisitante) (int dato);

typedef struct _SNodo {
  int dato;
  struct _SNodo *sig;
} SNodo;

typedef SNodo *SList;

/**
 * Devuelve una lista vacía.
 */
SList slist_crear();

/**
 * Destruccion de la lista.
 */
void slist_destruir(SList lista);

/**
 * Determina si la lista es vacía.
 */
int slist_vacia(SList lista);

/**
 * Agrega un elemento al final de la lista.
 */
SList slist_agregar_final(SList lista, int dato);

/**
 * Agrega un elemento al inicio de la lista.
 */
SList slist_agregar_inicio(SList lista, int dato);

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void slist_recorrer(SList lista, FuncionVisitante visit);

/**
 * Devuelve la longitud de una lista.
 */
int slist_longitud(SList lista);

/**
 * Devuelve la concatenación de dos listas, modificando la primera.
 */
SList slist_concatenar(SList lista1,SList lista2);

/**
 * Inserta un dato en una lista en una posición arbitraria.
 */
SList slist_insertar(SList lista, int dato, int pos);

/**
 * Elimina un dato en una lista en una posición arbitraria.
 */
SList slist_eliminar(SList lista, int pos);

/**
 * Determina si la lista contiene un dato.
 */
int slist_contiene(SList lista, int dato);

/**
 * Devuelve la posición de la primera ocurrencia de un elemento si el mismo está en
 * la lista dada, y -1 en caso que no esté.
 */
int slist_indice(SList lista, int dato);


/**
 * Devuelve una lista con los elementos comunes a ambas listas.
 */
SList slist_intersecar(SList lista1, SList lista2);

SList slist_intersecar_custom(SList lista1, SList lista2,int (*funcionIgualdad)(int,int));

/**
 * Ordena una lista de acuerdo al criterio dado por una función de comparación.
**/
SList slist_ordenar(SList lista,int (*funcionComparacion)(int,int));


/**
 * Obtiene el reverso de una lista.
**/
SList slist_reverso(SList lista);

/**
 * Intercala los elementos de ambas listas en una lista resultante.
**/
SList slist_intercalar(SList l1, SList l2);

/**
 * Divide una lista a la mitad-
**/
SList slist_partir(SList lista);


#endif /* __SLIST_H__ */
