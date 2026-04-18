#include "glist2.h"

GList2* glist2_crear() {
    GList2* lista = malloc(sizeof(GList2));
    lista->primero = NULL;
    lista->ultimo = NULL;
    return lista;
}

void glist2_destruir(GList2* lista, FuncionDestructora fd) {
    GNode* actual = lista->primero;
    while (actual != NULL) {
        GNode* aBorrar = actual;
        actual = actual->next;
        if (fd) fd(aBorrar->data);
        free(aBorrar);
    }
    free(lista);
}

int glist2_vacia(GList2* lista) {
    return lista->primero == NULL;
}

void glist2_insertar_inicio(GList2* lista, void* dato, FuncionCopia fc) {
    GNode* nuevo = malloc(sizeof(GNode));
    nuevo->data = fc(dato);
    nuevo->next = lista->primero;
    
    lista->primero = nuevo;
    // Si la lista estaba vacía, el nuevo también es el último
    if (lista->ultimo == NULL) {
        lista->ultimo = nuevo;
    }
}

void glist2_insertar_final(GList2* lista, void* dato, FuncionCopia fc) {
    GNode* nuevo = malloc(sizeof(GNode));
    nuevo->data = fc(dato);
    nuevo->next = NULL;

    if (lista->ultimo == NULL) {
        // Lista vacía
        lista->primero = nuevo;
        lista->ultimo = nuevo;
    } else {
        // Enganche directo en O(1)
        lista->ultimo->next = nuevo;
        lista->ultimo = nuevo;
    }
}

void glist2_eliminar_inicio(GList2* lista, FuncionDestructora fd) {
    if (glist2_vacia(lista)) return;

    GNode* aBorrar = lista->primero;
    lista->primero = lista->primero->next;

    // Si quedó vacía, el último también debe ser NULL
    if (lista->primero == NULL) {
        lista->ultimo = NULL;
    }

    if (fd) fd(aBorrar->data);
    free(aBorrar);
}

void glist2_recorrer(GList2* lista, FuncionVisitante fv) {
    for (GNode* actual = lista->primero; actual != NULL; actual = actual->next) {
        fv(actual->data);
    }
}

void* glist2_primero(GList2 *lista){
    return lista->primero->data;
}