//
//  arbol recursivo.c
//  
//
//  Created by Andres Moguel on 3/9/21.
//

#include<stdio.h>
#include<string.h>
#include <stdlib.h>

//arbol no recursivo

struct nodo{
    int num;
    struct nodo *izq, *der;
};

void inserta(struct nodo *insercion, struct nodo *elemento);
void imprime(struct nodo *p);
void borra(struct nodo *p);
int cuenta(struct nodo *p)

int  main(void)
{
    int i;
    struct nodo *raiz, *temp;
    
    raiz=NULL;
    printf("Ingresa numeros enteros, seguido por un caracter no numérico\n");
    while(scanf("%d", &i)==1){
        temp=(struct nodo *)malloc(sizeof(struct nodo));
        temp->der=NULL;
        temp->izq=NULL;
        temp->num=i;
        if(raiz==NULL)
            raiz=temp;
        else
            inserta(raiz, temp);
    }
    printf("numeros impresos en orden\n");
    imprime(raiz);
    borra(raiz);
}

void inserta(struct nodo *insercion, struct nodo *elemento){
    struct nodo *avanza;
    
    //printf entrando a insercion
    avanza = insercion;
    
    if(avanza!=NULL){
        if (elemento->num>avanza->num) {
            if (avanza->der!=NULL)
                inserta(avanza->der, elemento);
            else{
                avanza->der=elemento;
                return;
            }
        }
        if (elemento->num<=avanza->num) {
            if(avanza->izq!=NULL)
                inserta(avanza->izq, elemento);
            else{
                avanza->izq=elemento;
                return;
            }
        }
    }
    //printf saliendo de insercion
}


void imprime(struct nodo *p){
    if(p!=NULL){
        imprime(p->izq);
        printf("%d\n",p->num);
        imprime(p->der);
    }
}



void borra(struct nodo *p){
    if(p != NULL){
        borra(p->izq);
        borra(p->der);
        free(p);
    }
}

int cuenta(struct nodo *p){
    int suma=0;
    if(p!=NULL){
        cuenta(p->izq);
        suma+=p->num;
        cuenta(p->der);
    }
    return suma;
}
