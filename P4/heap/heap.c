#include "heap.h"
#include <stdlib.h>

BHeap bheap_crear(FuncionComparadora comp){
    BHeap heap = malloc(sizeof(struct _BHeap));
    heap->capacidad = 20;
    heap->ultimo =0;
    heap->arr = malloc(sizeof(void *) *heap->capacidad);
    heap->comp = comp;
    return heap;
}

void bheap_destruir(BHeap h,FuncionDestructora destroy){
    for(int i=1; i<= h->ultimo; i++)
        destroy(h->arr[i]);
    free(h->arr);
    free(h);
}

int bheap_es_vacio(BHeap h){
    return (h->ultimo)==0;
}

void bheap_recorrer(BHeap h,FuncionVisitante visit){
    for(int i=0; i<= h->ultimo; i++)
        visit(h->arr[i]);
}

BHeap bheap_insertar(BHeap h,void* dato){
    if(h->capacidad == h->ultimo){
        h->capacidad+= h->capacidad;
        h->arr = realloc(h->arr,h->capacidad*sizeof(void *));
    }
    h->ultimo+= 1;
    h->arr[h->ultimo] = dato;
    int anterior = h->ultimo;
    for(int i = h->ultimo/2; i>=0; i=i/2){
        if(h->comp(h->arr[i],dato) < 0){
            h->arr[anterior] = h->arr[i];
            h->arr[i] = dato;
            anterior = i;
        }else{
            i=-1;
        }
        if(i==0) i=-1;
    }
    return h;
}
BHeap bheap_insertar_ultimo_en(BHeap h, int pos){
    void ** a = h->arr;
    void *ultimo = a[h->ultimo];
    int esMayor = 1,k;
    h->arr[pos] = ultimo;
    for(int i = pos; i*2<= h->ultimo && esMayor;){
        k= i*2;
        if(k+1 <= h->ultimo && h->comp(a[k+1],a[k])>0){
            k=k+1;
        }
        if(a[i]>a[k]){
            esMayor=0;
        }else{
            a[i] = a[k];
            a[k] = ultimo;
            i= k;
        }

    }
    return h;
}

BHeap bheap_eliminar(BHeap h,void * dato,FuncionDestructora destroy){
    int terminar=0;
    for(int i=0; i<= h->ultimo && !terminar; i++){
        if(h->comp(h->arr[i],dato) == 0){
            destroy(h->arr[i]);
            bheap_insertar_ultimo_en(h,i);
            h->ultimo-=1;
            terminar = 1;
        }
    }
        return h;

}

BHeap bheap_primero(BHeap h){
    if(bheap_es_vacio(h)){
        return NULL;
    }
    return h->arr[1];
}

