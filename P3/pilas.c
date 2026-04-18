#include "pilas.h"

Pila pila_crear() {
    return glist_crear(); // Reutilización pura
}

void pila_destruir(Pila p, FuncionDestructora fd) {
    glist_destruir(p, fd); // Reutilización pura
}

int pila_vacia(Pila p) {
    return glist_vacia(p);
}

void * pila_tope(Pila p) {
    if (glist_vacia(p)) {
        return NULL;
    }
    return glist_dato(p); 
}

void pila_apilar(Pila *p, void* dato,FuncionCopia copy){
    *p = glist_agregar_inicio(p,dato,copy);
}

void pila_desapilar(Pila *p, FuncionDestructora fd) {
    *p = glist_eliminar_inicio(*p, fd); 
}

void pila_imprimir(Pila p,FuncionVisitante mostrar){
    glist_recorrer(p,mostrar);
}

GList revertir(GList lista,FuncionCopia copy){
    Pila p = pila_crear();
    for (GNode *node = lista; node != NULL; node = node->next)
        pila_apilar(&p,node->data,copy);

    return p;
}