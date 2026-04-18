#include <stdlib.h>

typedef void (*FuncionDestructora)(void*);
typedef void* (*FuncionCopia)(void*);
typedef void (*FuncionVisitante)(void*);

typedef struct _GNode {
    void* data;
    struct _GNode* next;
} GNode;

typedef struct {
    GNode* primero;
    GNode* ultimo;
} GList2;

GList2* glist2_crear();

void glist2_destruir(GList2* lista, FuncionDestructora destruir);

int glist2_vacia(GList2* lista);

void glist2_insertar_inicio(GList2* lista, void* data,FuncionCopia fc);

void glist2_insertar_final(GList2* lista, void* data, FuncionCopia fc);

void glist2_eliminar_inicio(GList2* lista, FuncionDestructora fd);

void glist2_recorrer(GList2* lista, FuncionVisitante fv);

void* glist2_primero(GList2 *lista);