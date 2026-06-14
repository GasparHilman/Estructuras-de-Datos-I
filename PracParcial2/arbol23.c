#include <stdlib.h>
typedef struct nodo_arbol23 * Arbol23 ;

// Representa un arbol especial utilizado para marcar que un arbol es binario
//poniendolo como tercer hijo

#define CENTINELA (( Arbol23 ) 1)

struct nodo_arbol23 {
int k1 , k2 ;
Arbol23 left , middle , right ;
};


Arbol23 arbol23_crear (){
    return NULL;
}

int cantidad_de_valores ( Arbol23 t ){
    if(!t)
        return 0;
    
    if(t->right == CENTINELA){
        return 1;
    }else{
        return 2;
    }

}

Arbol23 crear_nodo_binario ( int x , Arbol23 l , Arbol23 r ){
    Arbol23 arbol = malloc(sizeof(struct nodo_arbol23));
    arbol->k1 = x;
    arbol->left = l;
    arbol->middle = r;
    arbol->right = CENTINELA;
    return arbol;
}

int insertar_impl ( Arbol23 t , int x , int * out_x , Arbol23 * out_l , Arbol23 *out_r ){
    if(!t){
        *out_x = x;
        *out_l = NULL;
        *out_r = NULL;
        return 1;
    }
    int result;
    if(t->right == CENTINELA){
        if(x < t->k1)
            result = insertar_impl(t->left,x,out_x,out_l,out_r);
            if(result){
            t->k2 = t->k1;
            t->k1= *out_x;
            t->right = t->middle;
            t->left = out_l;
            t->middle = out_r;
            
        }
        else{
            result = insertar_impl(t->middle,x,out_x,out_l,out_r);
            if(result){
            t->k2= *out_x;
            t->middle = out_l;
            t->right = out_r;
            }
        }
        
        return 0;
    }else{
        if(x < t->k1){
            result = insertar_impl(t->left,x,out_x,out_l,out_r);
            if(result){
                *out_l = crear_nodo_binario(*out_x,*out_l,*out_r);
                *out_r = crear_nodo_binario(t->k2,t->left,t->right);
                *out_x = t->k1;
                free(t);
                return 1;
            }
        }
        else if(x > t->k2){
            result= insertar_impl(t->right,x,out_x,out_l,out_r);
            if(result){
                *out_r = crear_nodo_binario(*out_x,*out_l,*out_r);
                *out_l = crear_nodo_binario(t->k1,t->left,t->middle);
                *out_x = t->k2;
                free(t);
                return 1;
            }
            
        }else{
            result = insertar_impl(t->middle,x,out_x,out_l,out_r);
            if(result){
                *out_l = crear_nodo_binario(t->k1,t->left,*out_l);
                *out_r = crear_nodo_binario(t->k2,*out_r,t->right);
                //out_x = out_x;
                free(t);
                return 1;
            }
        }
        return 0;
    }
}