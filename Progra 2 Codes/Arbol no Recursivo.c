//
//  Arbol no Recursivo.c
//  
//
//  Created by Andres Moguel on 3/6/21.
//

#include<stdio.h>
#include<string.h>
#include <stdlib.h>

//arbol no recursivo

struct nodo{
    int num;
    struct nodo *izq, *der;
};

void inserta(struct nodo **insercion, int i);
void imprime(struct nodo *p);
void borra(struct nodo *p);

int  main(void)
{
    int i;
    struct nodo *raiz;
    
    raiz=NULL;
    printf("Ingresa numeros enteros, seguido por un caracter no numérico\n");
    while(scanf("%d", &i)==1)
        inserta(&raiz, i);
    printf("numeros impresos en orden\n");
    imprime(raiz);
    borra(raiz);
}

void inserta(struct nodo **insercion, int i){
    struct nodo *avanza, *nuevo;
    
    avanza=*insercion;
    if((nuevo=(struct nodo*)malloc(sizeof(struct nodo)))==NULL){
        printf("No hay memoria.\n");
        exit(1);
    }
    nuevo->num=i;
    nuevo->izq=NULL;
    nuevo->der=NULL;
    
    while (avanza != NULL)
    {
        if (i>avanza->num)
        {
            //moverse a la derecha
            if(avanza->der !=NULL)
                avanza=avanza->der;
            else{
                avanza->der=nuevo;
                return;
            }
        }
        if (i<=avanza->num)
        {
            //mueve izq
            if(avanza->izq!=NULL)
                avanza=avanza->izq;
            else{
                avanza->izq=nuevo;
                return;
            }
        }
    }
    avanza=nuevo;
    *insercion=avanza;
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
