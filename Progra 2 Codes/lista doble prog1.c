//
//  lista doble prog1.c
//  
//
//  Created by Andres Moguel on 2/24/21.
//

#include<stdio.h>
#include<string.h>
#include <stdlib.h>


typedef struct def_dato
{
    int num;
    struct def_dato *sig, *ant;
}tipo_dato;

void Inserta_Inicio(tipo_dato **inicio, int dato);
void inserta_fin(tipo_dato **inicio, int dato);
void Imprimir(tipo_dato *inicio);
void Borrar(tipo_dato **inicio);
void ImprimirReversa(tipo_dato *inicio);

int main(void){
tipo_dato *primero = NULL;
    int numero, total,i;
    
    printf("cuantos numeros tienes: ");
    scanf("%d", &total);
    for(i=0; i<total; i++){
    printf("dame el numero [%d]: ", i+1);
    scanf("%d", &numero);
    Inserta_Inicio(&primero, numero);
    }
    printf("En orden de inicio a fin con inserta inicio\n");
    Imprimir(primero);
    printf("de fin a inicio con inserta inicio\n");
    ImprimirReversa(primero);
}

void Inserta_Inicio(tipo_dato **inicio, int dato){
    tipo_dato *temp;
    
    temp =(tipo_dato*)malloc(sizeof(tipo_dato));
    temp ->num = dato;
    temp->ant = NULL;
    temp ->sig = *inicio;
    if (*inicio!=NULL) {
        (*inicio)->ant=temp;
    }
    *inicio = temp;
}


void inserta_fin(tipo_dato **inicio, int dato){
    tipo_dato *temp, *temp2;
    
    temp=(tipo_dato*)malloc(sizeof(tipo_dato));
    temp->num=dato;
    temp->sig=NULL;
    if(*inicio==NULL){
        temp->ant=*inicio;
        *inicio=temp;
    }else{
        temp2=*inicio;
        while (temp2->sig !=NULL) {
            temp2=temp2->sig;
        }
        temp2->sig=temp;
        temp->ant=temp2;
    }
}
void Imprimir(tipo_dato *inicio){
    tipo_dato *temp;
    
    temp = inicio;
    while (temp!=NULL) {
        printf("%d\n", temp->num);
        temp=temp ->sig;
    }
}

void Borrar(tipo_dato **inicio){
    tipo_dato *temp;
    
    while (*inicio!=NULL) {
        temp=*inicio;
        *inicio=(*inicio)->sig;
        free(temp);
    }
}

void ImprimirReversa(tipo_dato *inicio){
    tipo_dato *temp;
    
    temp = inicio;
    while (temp->sig!=NULL) {
        temp=temp ->sig;
    }
    while (temp!=NULL) {
        printf("%d\n", temp->num);
        temp=temp->ant;
    }
}
