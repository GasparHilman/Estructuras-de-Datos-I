#include "dlist.h"


static void imprimir_entero(int dato) {
  printf("%d ", dato);
}

int menor(int a,int b){
  return a<b;
}

int main(int argc, char *argv[]) {

  DList lista = dlist_crear();
  
  dlist_agregar_inicio(&lista, 5);
  dlist_agregar_inicio(&lista, 2);
  dlist_agregar_inicio(&lista, 3);
  dlist_agregar_inicio(&lista, 1);
  dlist_agregar_final(&lista, 6);
  dlist_recorrer(lista, imprimir_entero,0);
  printf("\n");
  dlist_recorrer(lista, imprimir_entero,1);
  printf("\n");
  dlist_destruir(lista);
}