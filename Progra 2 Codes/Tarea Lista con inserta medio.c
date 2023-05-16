//
//  Tarea Lista con inserta medio.c
//  
//
//  Created by Andres Moguel on 2/20/21.
//
#include<stdio.h>
#include<string.h>
#include <stdlib.h>


typedef struct def_dato
{
    int num;
    struct def_dato *sig;
}tipo_dato;

void Inserta_Inicio(tipo_dato **inicio, int dato);
void Imprimir(tipo_dato *inicio);
void Borrar(tipo_dato **inicio);
void inserta_fin(tipo_dato **inicio, int dato);
void inserta_medio(tipo_dato **inicio, int dato, tipo_dato *temp);
void insertar(tipo_dato **inicio, int dato);

int main(void){
    tipo_dato *primero = NULL;
    int total, numero, i;
    
    printf("cuantos numeros tienes?: ");
    scanf("%d", &total);
    for(i=0; i<total;i++){
        printf("Dame el numero %d: ", i+1);
        scanf("%d",&numero);
        insertar(&primero, numero);
    }
    
    Imprimir(primero);
    Borrar(&primero);
}

void Inserta_Inicio(tipo_dato **inicio, int dato){
    tipo_dato *temp;
    
    temp =(tipo_dato*)malloc(sizeof(tipo_dato));
    temp ->num = dato;
    temp ->sig = *inicio;
    *inicio = temp;
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

void inserta_fin(tipo_dato **inicio, int dato){
    tipo_dato *temp, *temp2;
    
    temp=(tipo_dato*)malloc(sizeof(tipo_dato));
    temp->num=dato;
    temp->sig=NULL;
    if(*inicio!=NULL){
        temp2=*inicio;
        while (temp2->sig!=NULL) {
            temp2=temp2->sig;
        }
        temp2->sig=temp;
    }
    else
        (*inicio)=temp;
}

void inserta_medio(tipo_dato **inicio, int dato, tipo_dato *temp ){
    tipo_dato *nueva, *temp2;
    nueva=(tipo_dato*)malloc(sizeof(tipo_dato));
    nueva->num=dato;
    nueva->sig=temp;
    temp2=*inicio;
    while (temp2->sig!=temp) {
        temp2=temp2->sig;
    }
    temp2->sig=nueva;
    //duda donde hago el free de nueva
}


//esta bien la funcion, que falta??
//como se ingresa los parametros en las funciones??
void insertar(tipo_dato **inicio, int dato){
    tipo_dato *temp;
    
    temp = *inicio;
    while ((temp!=NULL)&&(dato>(temp->num))) {
        temp=temp->sig;
    }
    if (temp==NULL) {
        inserta_fin(inicio, dato);
    }
    else{
        if (temp==*inicio) {
            Inserta_Inicio(inicio, dato);
        }
        else
            inserta_medio(inicio, dato, temp);
    }
}

