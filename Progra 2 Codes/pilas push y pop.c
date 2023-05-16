//
//  pilas push y pop.c
//  
//
//  Created by Andres Moguel on 2/24/21.
//

#include<stdio.h>
#include<string.h>
#include <stdlib.h>


typedef struct def_letra
{
    char let;
    struct def_letra *sig;
}tipo_letra;

void push(tipo_letra **inicio, char letra);
char pop(tipo_letra **inicio);

int main(void){
    char frase [200];
    int i;
    tipo_letra *primero = NULL;
    
    printf("Ingresa la frase a voltear: ");
    gets(frase);
    i= 0;
    while (frase[i]!='\0') {
        push(&primero, frase[i]);
        i++;
    }
    
    //imprimimos el pop
        while(primero!=NULL) {
            printf("%c", pop(&primero));
        }
}


void push(tipo_letra **inicio, char letra){
    tipo_letra *temp;
    temp =(tipo_letra*)malloc(sizeof(tipo_letra));
    temp->let=letra;
    temp->sig=*inicio;
    *inicio=temp;
}

char pop(tipo_letra **inicio){
    tipo_letra *temp;
    char letra;
        temp = *inicio;
        letra =temp->let;
        (*inicio)=(*inicio)->sig;
        free(temp);
    return letra;
}

