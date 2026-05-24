#ifndef __BTREE_H__
#define __BTREE_H__
#include "../../P3/pilas.h"

typedef void (*FuncionVisitantee)(int dato);

typedef void (*FuncionVisitanteExtra) (int dato, void *extra);

typedef enum {
  BTREE_RECORRIDO_IN,
  BTREE_RECORRIDO_PRE,
  BTREE_RECORRIDO_POST
} BTreeOrdenDeRecorrido;

typedef struct _BTNodo *BTree;

/**
 * Devuelve un arbol vacío.
 */
BTree btree_crear();

/**
 * Destruccion del árbol.
 */
void btree_destruir(BTree nodo);

/**
 * Indica si el árbol es vacío.
 */
int btree_empty(BTree nodo);

/**
 * Crea un nuevo arbol, con el dato dado en el nodo raiz, y los subarboles dados
 * a izquierda y derecha.
 */
BTree btree_unir(int dato, BTree left, BTree right);

/**
 * Recorrido del arbol, utilizando la funcion pasada.
 */
void btree_recorrer(BTree arbol, BTreeOrdenDeRecorrido orden,
                    FuncionVisitantee visit);

//void btree_recorrer_pre(BTree arbol,FuncionVisitantee visit);


int btree_nodos(BTree arbol);

int btree_buscar(BTree arbol, int dato);

BTree btree_copiar(BTree arbol);

int btree_altura(BTree arbol);

int btree_nnodos_profundidad(BTree arbol, int profundidad);

int btree_profundidad_aux(BTree arbol, int dato, int profAct);

int btree_profundidad(BTree arbol,int dato);

int btree_sumar(BTree arbol);

#endif /* __BTREE_H__ */
