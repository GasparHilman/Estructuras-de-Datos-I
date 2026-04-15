#include "slist.h"

SList slist_crear() {
  return NULL;
}

void slist_destruir(SList lista) {
  SNodo *nodoAEliminar;
  while (lista != NULL) {
    nodoAEliminar = lista;
    lista = lista->sig;
    free(nodoAEliminar);
  }
}

int slist_vacia(SList lista) {
  return lista == NULL;
}

SList slist_agregar_final(SList lista, int dato) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = NULL;

  if (lista == NULL)
    return nuevoNodo;

  SList nodo = lista;
  for (;nodo->sig != NULL;nodo = nodo->sig);
  /* ahora 'nodo' apunta al ultimo elemento en la lista */

  nodo->sig = nuevoNodo;
  return lista;
}

SList slist_agregar_inicio(SList lista, int dato) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = lista;
  return nuevoNodo;
}

void slist_recorrer(SList lista, FuncionVisitante visit) {
  for (SNodo *nodo = lista; nodo != NULL; nodo = nodo->sig)
    visit(nodo->dato);
}

int slist_longitud(SList lista){
  int l=0;
  for(;lista;lista=lista->sig,l++);
  return l;
}

SList slist_concatenar(SList lista1,SList lista2){
  if (!lista1){
    return lista2;
  }

  SList aux= lista1;
  for(;aux->sig;aux=aux->sig);

  aux->sig = lista2;
  return lista1;
}

SList slist_insertar(SList lista, int dato, int pos){
  SList aux = lista;
  if(pos == 0){
    return slist_agregar_inicio(lista,dato);
  }

  for(int i=0;i<pos-1 && aux;i++,aux=aux->sig);
  
  if (aux == NULL) {
    return lista; 
  }

  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = aux->sig;
  aux->sig = nuevoNodo;

  return lista;
}

SList slist_eliminar(SList lista, int pos){
  SList aux = lista;

  for(int i=0;i<pos-1 && aux;i++,aux=aux->sig);

  if (aux == NULL || aux->sig == NULL) {//caso lista vacia + pos invalida cubierto
    return lista; 
  }
  if(pos == 0){
    return aux->sig;
  }
  
  aux->sig=(aux->sig)->sig;
  return lista;

}

int slist_contiene(SList lista, int dato){
  int contiene=0;
  for(;lista && !contiene;lista=lista->sig){
    if (lista->dato == dato){
      contiene = 1;
    }
  }
  return contiene;
}

int slist_indice(SList lista, int dato){
  int contiene=0,i=0;
  for(;lista && !contiene;lista=lista->sig){
    if (lista->dato == dato){
      contiene = 1;
    }
    i++;
  }
  return contiene ? i-1 : -1;
} 

SList slist_intersecar(SList lista1, SList lista2){
  SList lista3 = slist_crear();
  SList aux1 = lista1;

  for(;aux1;aux1=aux1->sig){
    if(slist_contiene(lista2,aux1->dato)){
      lista3 = slist_agregar_inicio(lista3,aux1->dato);
    }
  }

  return lista3;
}

SList slist_intersecar_custom(SList lista1, SList lista2,int (*funcionIgualdad)(int,int)){
  SList lista3 = slist_crear();
  SList aux1 = lista1;
  SList aux2;

  for(;aux1;aux1=aux1->sig){
    aux2 = lista2;
    for(;aux2;aux2=aux2->sig){
      if(funcionIgualdad(aux1->dato,lista2->dato)){
        lista3 = slist_agregar_inicio(lista3,aux1->dato);
      }
    }
  }
  return lista3;
}
      

SList slist_ordenar(SList lista,int (*funcionComparacion)(int,int)){
  if(!lista  || !lista->sig){
    return NULL;
  }

  int longitud = slist_longitud(lista);

  for(int i=0;i<longitud-1;i++){

    SNodo *actual = lista;
    for(int j=0;j<longitud-i-1;j++){

      if(funcionComparacion(actual->dato,actual->sig->dato)){
        int temp = actual->dato;
        actual->dato = actual->sig->dato;
        actual->sig->dato = temp;
      }
      actual = actual->sig;
    }
  }
  return lista;
}

SList slist_reverso(SList lista){
  SList listaRev = slist_crear();
  for(SList nodo = lista;nodo;nodo=nodo->sig){
    listaRev = slist_agregar_inicio(listaRev,nodo->dato);
  }

  return listaRev;
}


SList slist_intercalar(SList l1, SList l2){
  SList listaNueva = slist_crear();
  SList nodo1 = l1,nodo2=l2;
  for(;nodo1 && nodo2;nodo1=nodo1->sig,nodo2=nodo2->sig){
    listaNueva = slist_agregar_final(listaNueva,nodo1->dato);
    listaNueva = slist_agregar_final(listaNueva,nodo2->dato);
  }
   listaNueva = slist_concatenar(listaNueva,nodo1);
   listaNueva = slist_concatenar(listaNueva,nodo2);
  return listaNueva;
}

SList slist_partir(SList lista) {
  SList temp = lista;
  int len = slist_longitud(lista);

  for (int i = 0; i < (len - 1) / 2; i++, temp = temp->sig){

  }
  SList segunda_mitad = temp->sig;
  temp->sig = NULL;
  return segunda_mitad;
}

  
  

