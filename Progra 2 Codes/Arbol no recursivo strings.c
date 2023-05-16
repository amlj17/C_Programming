//
//  Arbol no recursivo strings.c
//  
//
//  Created by Andres Moguel on 3/10/21.
//
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

//arbol no recursivo

struct nodo{
    char frase[50];
    struct nodo *izq, *der;
};

void inserta(struct nodo **insercion, char fra[50]);
void imprime(struct nodo *p);
void borra(struct nodo *p);

int  main(void)
{
    char fra[50];
    struct nodo *raiz;
    int opcion;
    
    raiz=NULL;
    printf("Ingresa un nombre\n");
    gets(fra);
    fpurge(stdin);
    inserta(&raiz, fra);
    do {
        printf("Deseas ingresar otro nombre?\n");
        printf("1. si\n");
        printf("2 no\n");
        scanf("%d",&opcion);
        fpurge(stdin);
        switch (opcion) {
            case 1:
                printf("Ingresa un nombre\n");
                gets(fra);
                fpurge(stdin);
                inserta(&raiz, fra);
                break;
            case 2:
                printf("Se procede a imprimir");
                break;
        }
    } while (opcion!=2);
    printf("nombres impresos en orden\n");
    imprime(raiz);
    borra(raiz);
}

void inserta(struct nodo **insercion, char fra[50]){
    struct nodo *avanza, *nuevo;
    
    avanza=*insercion;
    if((nuevo=(struct nodo*)malloc(sizeof(struct nodo)))==NULL){
        printf("No hay memoria.\n");
        exit(1);
    }
    strcpy(nuevo->frase, fra);
    nuevo->izq=NULL;
    nuevo->der=NULL;
    
    while (avanza != NULL)
    {
        if (strcmp(fra, avanza->frase)>0)
        {
            //moverse a la derecha
            if(avanza->der !=NULL)
                avanza=avanza->der;
            else{
                avanza->der=nuevo;
                return;
            }
        }
        if (strcmp(fra, avanza->frase)<=0)
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
        puts(p->frase);
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
