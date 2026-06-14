#include <stdlib.h>
#include <stdio.h>
// Intercambia los valores entre dos punetros a entero .
void swap_int ( int * x , int * y ) {
int temp = * x ;
* x = * y ;
* y = temp ;
}
// Devuelve la posicion del padre del elemento en la posicion i
int padre ( int i ) {
return (i -1) /2;
}
// Devuelve la posicion del hijo izquierdo del elemento en la posicion i
int izq ( int i ) {
return i *2+1;
}
// Devuelve la posicion del hijo derecho del elemento en la posicion i
int der ( int i ) {
return i *2+2;
}
// Hunde el elemento en la posicion pos del arreglo hasta que este cumpla la
//condicion de max - heap . n es la cantidad de elementos del arreglo
void hundir ( int pos , int * arr , int n ) {
int max_pos = pos ;
if ( izq ( pos ) < n && arr [ izq ( pos ) ] > arr [ max_pos ]) max_pos = izq ( pos ) ;
if ( der ( pos ) < n && arr [ der ( pos ) ] > arr [ max_pos ]) max_pos = der ( pos ) ;
if ( max_pos != pos ) {
swap_int (& arr [ pos ] , & arr [ max_pos ]) ;
hundir ( max_pos , arr , n ) ;
}
}
// Flota el elemento en la posicion pos hasta que el arreglo cumpla con la
//condicion de max - heap . n es la cantidad de elementos del arreglo .
void flotar ( int pos , int * arr , int n ) {
if ( pos == 0) return ;
int pos_padre = padre ( pos ) ;
if ( arr [ pos_padre ] < arr [ pos ]) {
swap_int (& arr [ pos ] , & arr [ pos_padre ]) ;
flotar ( pos_padre , arr , n ) ;
}
}

void arrToHeap(int * arr , int n){
    for(int i = (n/2)-1;i>=0;i--){
        hundir(i,arr,n);
    }
}

void ordenar ( int * arr , int n ){
    arrToHeap(arr,n);    
    for(int i = n-1;i>0;i--){
        swap_int(&arr[0],&arr[i]);
        hundir(0,arr,i);
    }
    
}
int main(){
    int arr[10] = {99,7,13,64,2,54,3,9,8,1};
    ordenar(arr,10);
    for(int i =0;i<10;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}