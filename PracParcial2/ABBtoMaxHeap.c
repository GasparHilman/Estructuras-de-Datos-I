#include <assert.h>
#include <stdlib.h>

/**
 * Estructura del nodo del arbol de busqueda binaria.
 * Tiene un puntero al dato (dato),
 * un puntero al nodo raiz del subarbol izquierdo (izq),
 * y un puntero al nodo raiz del subarbol derecho (der).
 */
struct _BST_Nodo {
  int dato;
  struct _BST_Nodo *izq, *der;
};

typedef struct _BST_Nodo *BSTree;

typedef struct _BHeap {
int *arr;
int capacidad;
int ultimo;
} *BHeap;

void AbbToMH_aux(BSTree arbol,BHeap h){
    if(!arbol)
        return;

    AbbToMH_aux(arbol->der,h);
    
    if(h->ultimo == h->capacidad){
        h->capacidad = 2 * h->capacidad;
        h->arr = realloc(h->arr,sizeof(int)* h->capacidad);
    }
    h->arr[h->ultimo] = arbol->dato;
    h->ultimo++;

    AbbToMH_aux(arbol->izq,h);
}

BHeap AbbToMH(BSTree arbol){
    BHeap h= malloc(sizeof(struct _BHeap));
    h->capacidad=40;
    h->arr = malloc(sizeof(int)*h->capacidad);
    h->ultimo = 0;

    if(!arbol){
        return h;
    }
    AbbToMH_aux(arbol,h);

    return h;
}

