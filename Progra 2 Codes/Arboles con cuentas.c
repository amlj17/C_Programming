//
//  Arboles con cuentas.c
//  
//
//  Created by Andres Moguel on 4/7/21.
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
int sum(struct nodo *p);
int cuenta(struct nodo *p);
int par(struct nodo *p);


int  main(void)
{
    int i;
    int suma, pares, total;
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
    suma=sum(raiz);
    printf("suma de nodos: %d\n", suma);
    total=cuenta(raiz);
    printf("cuenta de nodos: %d\n", total);
    pares=par(raiz);
    printf("cuenta de nodos pares: %d\n", pares);
    
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

int sum(struct nodo *p){
    int suma=0;
    if(p==NULL)
        return 0;
    suma = p->num;
    return (suma + sum(p->izq)+sum(p->der));
}

int cuenta(struct nodo *p){
    int suma=1;
    if(p==NULL)
        return 0;
    else
        return (suma + cuenta(p->izq) + cuenta(p->der));
}

int par(struct nodo *p){
    int suma=0;
    if(p==NULL)
        return 0;
    
        if((p->num%2)==0)
            suma++;
    return (suma +par(p->izq)+par(p->der));
    
}
