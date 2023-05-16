//
//  Memoria dinamica numeros.c
//  
//
//  Created by Andres Moguel on 2/11/21.
//

#include<stdio.h>
#include <stdlib.h>
void leer(int lista[], int cantidad);
void imprime(int lista[], int cantidad);

int main(void){
    int *numeros;
    int elementos;
    
    printf("Cuantos numeros tienes?: ");
    scanf("%d", &elementos);
    
    numeros = (int*)malloc(sizeof(int)*elementos);
    
    leer(numeros, elementos);
    imprime(numeros, elementos);
    
    free(numeros);
    return 0;
}

void leer(int lista[], int cantidad){
    int i;
    for(i=0; i<cantidad; i++){
        printf("dame el número %d: ", i+1);
        scanf("%d", &lista[i]);
    }
}

void imprime(int lista[], int cantidad){
    int i;
    for(i=0; i<cantidad; i++){
        printf("%d\n", lista[i]);
    }
}
