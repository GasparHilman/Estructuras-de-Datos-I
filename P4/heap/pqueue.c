#include "pqueue.h"


int cola_prioridad_es_vacia(PQueue pq){
    return bheap_es_vacio(pq);
}

void* cola_prioridad_maximo(PQueue pq){
    return bheap_primero(pq);
}

void cola_prioridad_eliminar_maximo(PQueue pq, FuncionDestructora destroy){
    bheap_eliminar(pq, cola_prioridad_maximo(pq),destroy);
}

void cola_prioridad_insertar(PQueue pq,void * dato){
    bheap_insertar(pq,dato);
}