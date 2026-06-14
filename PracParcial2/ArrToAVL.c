#include <stdlib.h>

typedef struct _AVL_Nodo {
  int dato;
  struct _AVL_Nodo* izq, * der;
  int altura;
} *AVL;

int max_altura(int a, int b) {
    return (a > b) ? a : b;
}

AVL ArrToAVL(int *arr,int largo){
    if(largo <=0){
        return NULL;
    }
    int medio = largo / 2;
    AVL avl=malloc(sizeof(struct _AVL_Nodo));
    avl->dato = arr[medio];
    avl->izq = ArrToAVL_aux(arr,medio);
    avl->der =ArrToAVL_aux(arr+(medio)+1,largo-medio-1);

    int alt_izq = (avl->izq != NULL) ? avl->izq->altura : 0;
    int alt_der = (avl->der != NULL) ? avl->der->altura : 0;
    avl->altura = 1 + max_altura(alt_izq, alt_der);
    return avl;

}

