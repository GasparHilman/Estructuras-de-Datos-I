#include "bstree.h"
#include <assert.h>
#include <stdlib.h>

/**
 * Estructura del nodo del arbol de busqueda binaria.
 * Tiene un puntero al dato (dato),
 * un puntero al nodo raiz del subarbol izquierdo (izq),
 * y un puntero al nodo raiz del subarbol derecho (der).
 */
struct _BST_Nodo {
  void *dato;
  struct _BST_Nodo *izq, *der;
};

/**
 * bstee_crear: Retorna un arbol de busqueda binaria vacio
 */
BSTree bstee_crear() { return NULL; }

/**
 * bstree_destruir: Destruye el arbol y sus datos
 */
void bstree_destruir(BSTree raiz, FuncionDestructora destr) {
  if (raiz != NULL) {
    bstree_destruir(raiz->izq, destr);
    bstree_destruir(raiz->der, destr);
    destr(raiz->dato);
    free(raiz);
  }
};

/**
 * bstree_buscar: Retorna 1 si el dato se encuentra y 0 en caso
 * contrario
 */
int bstree_buscar(BSTree raiz, void *dato, FuncionComparadora comp) {
  if (raiz == NULL)
    return 0;
  else if (comp(dato, raiz->dato) == 0) // raiz->dato == dato
    return 1;
  else if (comp(dato, raiz->dato) < 0) // dato < raiz->dato
    return bstree_buscar(raiz->izq, dato, comp);
  else // raiz->dato < dato
    return bstree_buscar(raiz->der, dato, comp);
}

/**
 * bstree_insertar: Inserta un dato no repetido en el arbol, manteniendo la
 * propiedad del arbol de busqueda binaria
 */
BSTree bstree_insertar(BSTree raiz, void *dato, FuncionCopiadora copia,
                       FuncionComparadora comp) {
  if (raiz == NULL) { // insertar el dato en un nuevo nodo
    struct _BST_Nodo *nuevoNodo = malloc(sizeof(struct _BST_Nodo));
    assert(nuevoNodo != NULL);
    nuevoNodo->dato = copia(dato);
    nuevoNodo->izq = nuevoNodo->der = NULL;
    return nuevoNodo;
  } else if (comp(dato, raiz->dato) < 0) // dato < raiz->dato
    raiz->izq = bstree_insertar(raiz->izq, dato, copia, comp);
  else if (comp(dato, raiz->dato) > 0) // raiz->dato < dato
    raiz->der = bstree_insertar(raiz->der, dato, copia, comp);
  // si el dato ya se encontraba, no es insertado
  return raiz;
}

/**
 * bstree_recorrer: Recorrido DSF del arbol
 */
void bstree_recorrer(BSTree raiz, BSTreeRecorrido orden,
                     FuncionVisitanteExtra visita, void *extra) {
  if (raiz != NULL) {
    if (orden == BTREE_RECORRIDO_PRE)
      visita(raiz->dato, extra);
    bstree_recorrer(raiz->izq, orden, visita, extra);
    if (orden == BTREE_RECORRIDO_IN)
      visita(raiz->dato, extra);
    bstree_recorrer(raiz->der, orden, visita, extra);
    if (orden == BTREE_RECORRIDO_POST)
      visita(raiz->dato, extra);
  }
}

BSTree bstree_mayor(BSTree arbol){
  if(!arbol->der){
    return arbol;
  }
  return bstree_mayor(arbol->der);
}

BSTree bstree_eliminar(BSTree arbol, void *dato,FuncionComparadora comp, FuncionDestructora destroy){
  if(!arbol)
    return NULL;
  
  if(comp(dato, arbol->dato) < 0){
    arbol->izq = bstree_eliminar(arbol->izq,dato, comp, destroy);
  }else if(comp(dato, arbol->dato) > 0){
    arbol->der = bstree_eliminar(arbol->der,dato, comp, destroy);
  }else{
    if((!arbol->izq) || (!arbol->der)){
      BSTree nuevaRaiz = ((!arbol->der)?arbol->izq:arbol->der);
      if (destroy != NULL) {
      destroy(arbol->dato);
      }
      free(arbol);
      return nuevaRaiz;
    }
    BSTree mayorIzq = bstree_mayor(arbol->izq);
    void *dato_reemplazo = mayorIzq->dato;
    arbol->izq = bstree_eliminar(arbol->izq,mayorIzq->dato,comp,NULL);

    if (destroy != NULL) {
      destroy(arbol->dato);
    }
    arbol->dato = dato_reemplazo;
 

  }
  return arbol;
}

int bstree_elementos(BSTree arbol){
  if(!arbol){
    return 0;
  }
  return 1+bstree_elementos(arbol->izq)+bstree_elementos(arbol->der);
}

void * bstree_k_esimo_menor(BSTree arbol, int k){
    if(!arbol){
      return NULL;
    }
    int cantIzq = bstree_elementos(arbol->izq);
    if(cantIzq< k-1){
      bstree_k_esimo_menor(arbol->der,k-cantIzq+1);
    }else if(cantIzq >= k){
      bstree_k_esimo_menor(arbol->izq,k);
    }else{
      return arbol->dato;
    }
}
int bstree_validar_aux(BSTree arbol, FuncionComparadora comp, void **ultimo_visitado){
  if(!arbol){
    return 1;
  }

  int izquierda = bstree_validar_aux(arbol->izq,comp,ultimo_visitado);
  if(!izquierda)
    return 0;

  if(*ultimo_visitado != NULL) {
        if (comp(*ultimo_visitado, arbol->dato) >= 0) {
            return 0;
        }
    }

  *ultimo_visitado = arbol->dato;

  return bstree_validar_aux(arbol->der, comp, ultimo_visitado);
}

int bstree_validar(BSTree arbol,FuncionComparadora comp){
  void *ultimo = NULL;
  return bstree_validar_aux(arbol, comp, &ultimo);
}