#include <stdio.h>
#include <stdlib.h>

//GESTIÓN DE LA MEMORIA Y PUNTEROS

//dados dos punteros a enteros, intercambia el contenido de las variables apuntadas
void swap(int *n,int *m){
    int temp = *n;
    *n = *m ;
    *m = temp;
}

char *get_new_line(void){
    char *linea=malloc(25*sizeof(char));
    scanf("%[^\n]",linea);
    return linea;
}

//Toma un puntero a función, y un entero, y aplica la función al entero y retorna el valor dado.
int apply(int (*f)(int), int n){
    return f(n);
}

int most(int n){
    return n+1;
}

//toma un puntero a función, un puntero a un entero, y reemplaza  el entero
// apuntado por el valor de ejecutar la función apuntada sobre el valor apuntado.
void apply_in(int (*f)(int), int* n){
    int temp = *n;
    *n = f(temp);
}

typedef void (*VisitorFunc)(int);

//toma un puntero a una función, un arreglo de enteros,
//y su longitud, y aplica la función a cada elemento del arreglo.
void recorre(VisitorFunc f, int l[], int lon){
    for(int i=0; i< lon;i++){
        f(l[i]);
    }
}


//ESTRUCTURAS Y PUNTEROS


//Defina una estructura para representar puntos en el plano, y una función medio que dados dos de
//estos puntos, calcule el punto medio.
typedef struct{
    float x;
    float y;
} Punto;


Punto medio(Punto p1, Punto p2){
    Punto pmedio;
    pmedio.x = (p1.x + p2.x) /2;
    pmedio.y = (p1.y + p2.y) /2;
    return pmedio;
}

//representa una carta de la baraja espa˜nola
typedef struct{
    int palo;
    int num;
} Carta;

typedef Carta Mazo[48];

//tome un mazo y lo llen con las cartas correspondientes.
void llenar(Mazo mazo){
    for(int i= 0; i<4; i++){
        for(int j=0;j<12;j++){
            mazo[(12*i)+j].palo=i;
            mazo[(12*i)+j].num=j;
        }
    }
}
//recibe un mazo y devuelve una carta al azar del mismo.
Carta azar(Mazo mazo){
    int num=rand()%48;
    printf("%d",num);
   return mazo[num];
}
