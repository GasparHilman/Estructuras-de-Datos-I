#include <stdio.h>
#include <stdlib.h>

void bubble_sort(float arreglo[], int longitud) {
for (int iter = 0 ; iter < longitud - 1 ; iter++) {
for (int i = 0 ; i < longitud - iter - 1; i++) {
if (arreglo[i] > arreglo[i + 1]) {
float aux = arreglo[i];
arreglo[i] = arreglo[i + 1];
arreglo[i + 1] = aux;
}
}
}
}


//La mediana de un arreglo ordenado de n números se define como el elemento del medio cuando n es
//impar y como el promedio de los dos elementos del medio cuando n es par


//dado un arreglo, no necesariamente ordenado, de números y su long, calcula su mediana

float mediana(float * arr, int l){
    float * aux = malloc(l*sizeof(float));
    for(int i =0;i<l;i++){
        aux[i]=arr[i];
    }
    bubble_sort(aux,l);
    if(l % 2){
        return aux[(int)(l / 2)];
    }
    return (aux[l /2] + aux[(l/2)-1])/2;

}
//dado una cadena de char retorna la longitud de la cadena
int string_len(char * str){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

void string_reverse(char * str){
    int l = string_len(str)-1;
    char aux;
    for(int i=0;i < l;i++,l--){
        aux=str[i];
        str[i]=str[l];
        str[l]=aux;
    }
}

int string_concat(char* str1, char* str2, int max) {
    int i = 0;
    int j = 0; 
    while (str1[i] != '\0') {
        i++;
    }
    while (j < max && str2[j] != '\0') {
        str1[i + j] = str2[j];
        j++;
    }
    str1[i + j] = '\0';

    return j;
}

void string_unir(char* arregloStrings[], int n, char* sep, char* res){
    int co=0;
    for(int i=0;i < n;i++){
        for(int j=0;arregloStrings[i][j]!='\0';j++){
            res[co]=arregloStrings[i][j];
            co++;
        }
        if(i!=n-1){
            for(int j=0;sep[j]!='\0';j++){
                res[co]=sep[j];
                co++;
            }
        }
    }
    res[co]='\0';
}

typedef struct {
int* direccion;
int capacidad;
} ArregloEnteros;

ArregloEnteros* arreglo_enteros_crear(int capacidad){
    ArregloEnteros* a = malloc(sizeof(ArregloEnteros));
    a->direccion = malloc(capacidad * sizeof(int));
    a->capacidad = capacidad;
    return a;
}

void arreglo_enteros_destruir(ArregloEnteros* a){
    free(a->direccion);
    free(a);
}

int arreglo_enteros_leer(ArregloEnteros* arreglo, int pos){
    return arreglo->direccion[pos];
}

void arreglo_enteros_escribir(ArregloEnteros* arreglo, int pos, int valor){
    arreglo->direccion[pos] = valor;
}

int arreglo_enteros_capacidad(ArregloEnteros* arreglo){
    return arreglo->capacidad;
}

void arreglo_enteros_imprimir(ArregloEnteros* arreglo){
    for(int i=0;i<arreglo->capacidad;i++){
        printf("%d ",arreglo->direccion[i]);
    }
}

void arreglo_enteros_ajustar(ArregloEnteros* arreglo, int capacidad){
    if(capacidad< arreglo_enteros_capacidad(arreglo)){
        arreglo->capacidad=capacidad;
    }else{
        arreglo->direccion = realloc(arreglo->direccion,capacidad*sizeof(int));
        arreglo->capacidad=capacidad;
    }
}

void arreglo_enteros_insertar(ArregloEnteros* arreglo, int pos, int dato){
    int capacidad=arreglo_enteros_capacidad(arreglo);
    arreglo_enteros_ajustar(arreglo,capacidad+1);

    for(int i=capacidad;i>pos;i--){
        arreglo->direccion[i]=arreglo->direccion[i-1];
    }
    arreglo->direccion[pos]=dato;
}


void arreglo_enteros_eliminar(ArregloEnteros* arreglo, int pos){
    int capacidad=arreglo_enteros_capacidad(arreglo);
    for(int i=pos;i<capacidad-1;i++){
        arreglo->direccion[i]=arreglo->direccion[i+1];
    }
    arreglo_enteros_ajustar(arreglo,capacidad-1);
}
