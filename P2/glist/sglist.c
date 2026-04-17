#include "sglist.h"
#include <stdlib.h>

SGList sglist_crear(){
    return NULL;
}

void sglist_destruir(SGList lista, FuncionDestructora destroy){
    glist_destruir(lista,destroy);
}

int sglist_vacia(SGList lista){
    return lista == NULL;
}

void sglist_recorrer(GList lista, FuncionVisitante f){
    for (GNode *node = lista; node != NULL; node = node->next)
    f(node->data);
}

SGList sglist_insertar(SGList lista, void *dato, FuncionCopia copy, FuncionComparadora comparar){
    if(!lista || comparar(lista->data,dato)>=0){
        return glist_agregar_inicio(lista,dato,copy);
    }
    SGList aux=lista;
    for(;aux->next && comparar(aux->next->data,dato)<=0;aux=aux->next);
    aux->next = glist_agregar_inicio(aux->next,dato,copy);
    return lista;
}

int sglist_buscar(GList lista, void *dato, FuncionComparadora comparar){
    if(!lista || comparar(lista->data,dato)>0){
        return 0;
    }
    SGList aux=lista;
    int esIgual=0;
    for(;aux && esIgual<0;aux=aux->next){
        esIgual = comparar(aux->next->data,dato);
    }
    
    return esIgual==0;
}

SGList sglist_arr(void ** arr, int longitud, FuncionCopia copy, FuncionComparadora comparar){
    SGList lista= sglist_crear();
    for (int i = 0; i < longitud; ++i) {//lista ordenada
    lista =
        sglist_insertar(lista, arr[i], (FuncionCopia)copy,(FuncionComparadora)comparar);
    }
    return lista;

}