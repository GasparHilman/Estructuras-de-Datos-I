#include "dlist.h"

DList dlist_crear(){
    DList lista;
    lista.primero=NULL;
    lista.ultimo=NULL;
    return lista;
}

void dlist_destruir(DList lista){
    DNodo *nodo=lista.primero;
    while(!nodo){
        DNodo *nodoaEliminar=nodo;
        nodo=nodo->sig;
        free(nodoaEliminar);
    }
}

int dlist_vacia(DList lista){
    return lista.primero == NULL;
}

void dlist_agregar_final(DList *lista, int dato){
    DNodo *nuevoNodo = malloc(sizeof(DNodo));
    nuevoNodo->dato = dato;
    nuevoNodo->sig = NULL;
    nuevoNodo->ant = lista->ultimo;
    if(!lista->primero){
        lista->primero = nuevoNodo;
        lista->ultimo = nuevoNodo;
        return;
    }
    lista->ultimo->sig=nuevoNodo;
    lista->ultimo=nuevoNodo;
}

void dlist_agregar_inicio(DList *lista, int dato){
    DNodo *nuevoNodo = malloc(sizeof(DNodo));
    nuevoNodo->dato = dato;
    nuevoNodo->sig = lista->primero;
    nuevoNodo->ant = NULL;
    if(!lista->primero){
        lista->primero = nuevoNodo;
        lista->ultimo = nuevoNodo;
        return;
    }
    lista->primero->ant=nuevoNodo;
    lista->primero=nuevoNodo;
}

int dlist_longitud(DList lista){
    int i=0;
    for(DNodo* aux=lista.primero;aux;aux = aux->sig,i++);
    return i;
}

void dlist_recorrer(DList lista, FuncionVisitante visit,DListOrdenDeRecorrido orden){
    if(orden){
        for(DNodo* aux=lista.ultimo;aux;aux = aux->ant){
            visit(aux->dato);
        }
    }else{
        for(DNodo* aux=lista.primero;aux;aux = aux->sig){
            visit(aux->dato);
        }
    }
}