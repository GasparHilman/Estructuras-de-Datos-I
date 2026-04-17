#ifndef __SLIST_H__
#define __SLIST_H__

#include "glist.h"

typedef int (*FuncionComparadora)(void *dato1,void *dato2);

typedef GList SGList;


SGList sglist_crear();

void sglist_destruir(SGList lista, FuncionDestructora destroy);

int sglist_vacia(SGList lista);

void sglist_recorrer(GList lista, FuncionVisitante f);

SGList sglist_insertar(SGList lista, void *dato, FuncionCopia copy, FuncionComparadora comparar);

int sglist_buscar(GList, void *, FuncionComparadora comparar);

SGList sglist_arr(void ** arr, int longitud, FuncionCopia copy, FuncionComparadora comparar);




#endif /* __SLIST_H__ */
