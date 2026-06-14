#include "btree.h"
#include <assert.h>
#include <stdlib.h>

struct _BTNodo {
  int dato;
  struct _BTNodo *left;
  struct _BTNodo *right;
};


/**
 * Devuelve un arbol vacío.
 */
BTree btree_crear() { return NULL; }

/**
 * Destruccion del árbol.
 */
void btree_destruir(BTree nodo) {
  if (nodo != NULL) {
    btree_destruir(nodo->left);
    btree_destruir(nodo->right);
    free(nodo);
  }
}

/**
 * Indica si el árbol es vacío.
 */
int btree_empty(BTree nodo) { return nodo == NULL; }

/**
 * Crea un nuevo arbol, con el dato dado en el nodo raiz, y los subarboles dados
 * a izquierda y derecha.
 */
BTree btree_unir(int dato, BTree left, BTree right) {
  BTree nuevoNodo = malloc(sizeof(struct _BTNodo));
  assert(nuevoNodo != NULL);
  nuevoNodo->dato = dato;
  nuevoNodo->left = left;
  nuevoNodo->right = right;
  return nuevoNodo;
}

/**
 * Recorrido del arbol, utilizando la funcion pasada.
 */
void btree_recorrer(BTree arbol, BTreeOrdenDeRecorrido orden,
                    FuncionVisitantee visit) {
  if(!arbol)
    return;
  
  if (orden == BTREE_RECORRIDO_PRE)
      visit(arbol->dato);
  
  btree_recorrer(arbol->left,orden,visit);

  if (orden == BTREE_RECORRIDO_IN)
      visit(arbol->dato);

  btree_recorrer(arbol->right,orden,visit);

  if (orden == BTREE_RECORRIDO_POST)
      visit(arbol->dato);
  
  

  return;
}
void* id(void *dato){
  return dato;
}
void nada(void* dato){
  (void)dato;
}
/**

 
void btree_recorrer_pre(BTree arbol,FuncionVisitantee visit){
  if(!arbol)
    return;
  Pila pila = pila_crear();
  int seguir=1;
  while(seguir){
      visit(arbol->dato);
      if(arbol->right)
        pila_apilar(&pila,arbol->right,id);
      if(arbol->left)
        pila_apilar(&pila,arbol->left,id);
      if(pila){
      arbol = pila_tope(pila);
      pila_desapilar(&pila,nada);
      }else{
      seguir=0;
      }
  }
  

}
  */

int btree_nodos(BTree arbol){
  if(!arbol){
    return 0;
  }

  return 1 + btree_nodos(arbol->left) + btree_nodos(arbol->right);
}

int btree_buscar(BTree arbol, int dato){
  if(!arbol)
    return 0;
  
  if(dato < arbol->dato)
    return btree_buscar(arbol->left,dato);
  
  if(dato > arbol->dato)
    return btree_buscar(arbol->right,dato);

  return 1;
  
}

BTree btree_copiar(BTree arbol){
  return btree_unir(arbol->dato,btree_copiar(arbol->left),btree_copiar(arbol->right));
}

int btree_altura(BTree arbol){
  if(!arbol){
    return -1;
  }
  int d= btree_altura(arbol->right)+1 , i=btree_altura(arbol->left)+1;
  return (d>i? d : i);
}

int btree_nnodos_profundidad(BTree arbol, int profundidad){
  if(!arbol){
    return 0;
  }
  if(profundidad==0){
    return 1;
  }
  return btree_nnodos_profundidad(arbol->left, profundidad-1) + btree_nnodos_profundidad(arbol->right, profundidad-1);
}

int btree_profundidad_aux(BTree arbol, int dato, int profAct){
  if(!arbol)
    return -1;
  if(arbol->dato == dato)
    return profAct;
  return (dato < arbol->dato? btree_profundidad_aux(arbol->left,dato, profAct+1):btree_profundidad_aux(arbol->right,dato, profAct+1));
  
}

int btree_profundidad(BTree arbol,int dato){
  return btree_profundidad_aux(arbol,dato,0);
}

int btree_sumar(BTree arbol){
  if(!arbol)
    return 0;
  return arbol->dato + btree_sumar(arbol->left) + btree_sumar(arbol->right);
}

void btree_recorrer_extra(BTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitanteExtra visit, void *extra) {
    if (arbol == NULL) {
        return; 
    }

    if (orden == BTREE_RECORRIDO_PRE) {
        visit(arbol->dato, extra);
        btree_recorrer_extra(arbol->left, orden, visit, extra);
        btree_recorrer_extra(arbol->right, orden, visit, extra);
    } 
    else if (orden == BTREE_RECORRIDO_IN) {
        btree_recorrer_extra(arbol->left, orden, visit, extra);
        visit(arbol->dato, extra); 
        btree_recorrer_extra(arbol->right, orden, visit, extra);
    }
    else if (orden == BTREE_RECORRIDO_POST) {
        btree_recorrer_extra(arbol->left, orden, visit, extra);
        btree_recorrer_extra(arbol->right, orden, visit, extra);
        visit(arbol->dato, extra);
    }
}

void btree_recorrer_bfs_aux(BTree arbol, FuncionVisitante visit,int profAct,int prof){
  if(!arbol)
    return;
  if(profAct == prof){
    visit(&arbol->dato);
    return;
  }
  btree_recorrer_bfs_aux(arbol->left,visit,profAct+1,prof);
  btree_recorrer_bfs_aux(arbol->right,visit,profAct+1,prof);
}


void btree_recorrer_bfs(BTree arbol, FuncionVisitante visit){
  int altura = btree_altura(arbol);
  for(int i=0;i<=altura;i++){
    btree_recorrer_bfs_aux(arbol,visit,0,i);
  }
}


BTree mirror(BTree arbol){
  if(!arbol)
    return NULL;
  return btree_unir(arbol->dato,mirror(arbol->right),mirror(arbol->left));

}
int btree_es_completo_aux(BTree arbol,int profAct,int profTot,int *flag){
  if(!arbol && profAct< profTot){
    return 0;
  }
  if(profAct == profTot){
    if(arbol && *flag){
      return 0;
    }
    if(!arbol){
      *flag = 1;
    }
    return 1;
  }
  return btree_es_completo_aux(arbol->left,profAct+1,profTot,flag) && btree_es_completo_aux(arbol->right,profAct+1,profTot,flag);
  
}

int btree_es_completo(BTree arbol){
  if(! arbol) return 1;
  int x =0,completo=1;
  int altura = btree_altura(arbol);
  for(int i=0;i<=altura && completo;i++){
    x=0;
    completo = btree_es_completo_aux(arbol,0,i,&x);
  }
  return completo;
}

