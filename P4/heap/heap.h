typedef void *(*FuncionCopiadora)(void *dato);
typedef int (*FuncionComparadora)(void *, void *);
typedef void (*FuncionDestructora)(void *dato);
typedef void (*FuncionVisitante)(void* dato);

typedef struct _BHeap {
void **arr;
int capacidad;
int ultimo;
FuncionComparadora comp;
} *BHeap;

BHeap bheap_crear(FuncionComparadora comp);

void bheap_destruir(BHeap h,FuncionDestructora destroy);

int bheap_es_vacio(BHeap h);

void bheap_recorrer(BHeap h,FuncionVisitante visit);

BHeap bheap_insertar(BHeap h,void* dato);

BHeap bheap_insertar_ultimo_en(BHeap h, int pos);

BHeap bheap_eliminar(BHeap h,void * dato,FuncionDestructora destroy);

BHeap bheap_primero(BHeap h);