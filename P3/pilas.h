#include "../P2/glist/glist.h"
#include <stdlib.h>

typedef GList Pila;

Pila pila_crear();

void pila_destruir(Pila p, FuncionDestructora fd);

int pila_vacia(Pila p);

int pila_tope(Pila p);

void pila_apilar(Pila p, void* dato,FuncionCopia copy);

void pila_desapilar(Pila *p, FuncionDestructora fd);

void pila_imprimir(Pila p,FuncionVisitante mostrar);

