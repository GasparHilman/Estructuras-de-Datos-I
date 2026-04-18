#include "glist2.h"

typedef GList2* Cola; 

Cola cola_crear();

void cola_destruir(Cola c,FuncionDestructora fd);

int cola_vacia(Cola c);

void* cola_inicio(Cola c);

void cola_encolar(Cola c, void* dato,FuncionCopia fc);

void cola_desencolar(Cola c, FuncionDestructora fd);

void cola_imprimir(Cola c, FuncionVisitante mostrar);
