#include "contacto.h"
#include "glist.h"
#include "sglist.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

  GList lista = glist_crear();
  SGList listaOrdenada = sglist_crear();
  Contacto *contactos[6];
  contactos[0] = contacto_crear("Pepe Argento", "3412695452", 61);
  contactos[1] = contacto_crear("Moni Argento", "3412684759", 60);
  contactos[2] = contacto_crear("Coqui Argento", "3415694286", 15);
  contactos[3] = contacto_crear("Paola Argento", "3416259862", 29);
  contactos[4] = contacto_crear("Maria Elena Fuseneco", "3416874594", 59);
  contactos[5] = contacto_crear("Dardo Fuseneco", "3416894526", 64);

  for (int i = 0; i < 6; ++i) {
    lista =
        glist_agregar_inicio(lista, contactos[i], (FuncionCopia)contacto_copia);
  }

  listaOrdenada = sglist_arr((void **)contactos, 6, (FuncionCopia)contacto_copia,(FuncionComparadora)contacto_comparar);


  for (int i = 0; i < 6; ++i) {//lista ordenada
    contacto_destruir(contactos[i]);
  }

  printf("Lista:\n");
  glist_recorrer(lista, (FuncionVisitante)contacto_imprimir);
  printf("\n");

  GList listaFiltrada = glist_filtrar(lista,(FuncionCopia)contacto_copia,(Predicado)contacto_esMayor);

  printf("Lista filtrada:\n");
  glist_recorrer(listaFiltrada, (FuncionVisitante)contacto_imprimir);
  printf("\n");

  printf("Lista ordenada:\n");
  sglist_recorrer(listaOrdenada, (FuncionVisitante)contacto_imprimir);

  glist_destruir(lista, (FuncionDestructora)contacto_destruir);
  glist_destruir(listaFiltrada, (FuncionDestructora)contacto_destruir);
  sglist_destruir(listaOrdenada, (FuncionDestructora)contacto_destruir);

  return 0;
}