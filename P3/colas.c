#include "colas.h"

Cola cola_crear(){
   return glist2_crear();
}

void cola_destruir(Cola c,FuncionDestructora fd){
    glist2_destruir(c,fd);
}

int cola_vacia(Cola c){
    return glist2_vacia(c);
}

void* cola_inicio(Cola c){
    return glist2_primero(c);
}

void cola_encolar(Cola c, void* dato, FuncionCopia fc){
    glist2_insertar_final(c,dato,fc);
}

void cola_desencolar(Cola c,FuncionDestructora fd){
    glist2_eliminar_inicio(c,fd);
}

void cola_imprimir(Cola c, FuncionVisitante mostrar){
    glist2_recorrer(c,mostrar);
}