#ifndef __DLIST_H__
#define __DLIST_H__

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef void (*FuncionVisitante) (int dato);

typedef struct _DNodo {
int dato;
struct _DNodo* sig;
struct _DNodo* ant;
} DNodo;

typedef struct {
DNodo* primero;
DNodo* ultimo;
} DList;

typedef enum {
DLIST_RECORRIDO_HACIA_ADELANTE,
DLIST_RECORRIDO_HACIA_ATRAS
} DListOrdenDeRecorrido;

/**
 * Devuelve una lista vacía.
 */
DList dlist_crear();

/**
 * Destruccion de la lista.
 */
void dlist_destruir(DList lista);

/**
 * Determina si la lista es vacía.
 */
int dlist_vacia(DList lista);

/**
 * Agrega un elemento al final de la lista.
 */
void dlist_agregar_final(DList *lista, int dato);

/**
 * Agrega un elemento al inicio de la lista.
 */
void dlist_agregar_inicio(DList *lista, int dato);

/**
 * Devuelve la longitud de una lista.
 */
int dlist_longitud(DList lista);

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void dlist_recorrer(DList lista, FuncionVisitante visit,DListOrdenDeRecorrido orden);


#endif /* __DLIST_H__ */
