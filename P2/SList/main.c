#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

static void imprimir_entero(int dato) {
  printf("%d ", dato);
}

int menor(int a,int b){
  return a<b;
}

int main(int argc, char *argv[]) {

  SList lista = slist_crear();
  
  lista = slist_agregar_inicio(lista, 5);
  lista = slist_agregar_inicio(lista, 2);
  lista = slist_agregar_inicio(lista, 3);
  lista = slist_agregar_inicio(lista, 1);
  slist_recorrer(lista, imprimir_entero);
  printf("\n");
  lista = slist_ordenar(lista,menor);
  slist_recorrer(lista, imprimir_entero);
  printf("\n");
  SList listaRev = slist_reverso(lista);
  listaRev = slist_eliminar(listaRev,1);
  listaRev = slist_eliminar(listaRev,2);
  slist_recorrer(listaRev, imprimir_entero);
  SList listaInter = slist_intercalar(listaRev,lista);
  printf("\n");
  slist_recorrer(listaInter, imprimir_entero);
  printf("\n");
  slist_destruir(lista);
  slist_destruir(listaRev);
  slist_destruir(listaInter);
  return 0;
}
