//
//  Tabla Cuadrados.c
//  
//
//  Created by Andres Moguel on 1/23/21.
//
#include <stdio.h>
void ObtenerNum(int enteros[100]);
void ObtenerCuadrados(int enteros[100], int cuadrados[100]);
void resultados(int enteros[100], int cuadrados[100]);

int main(void){
    int enteros[100];
    int cuadrados[100];
    ObtenerNum(enteros);
    ObtenerCuadrados(enteros, cuadrados);
    resultados(enteros, cuadrados);
}


void ObtenerNum(int enteros[100]){
    int i;
    for (i=0; i<100; i++) {
        enteros[i]=(i+1);
    }
}

void ObtenerCuadrados(int enteros[100], int cuadrados[100]){
    int i;
    for (i=0; i<100; i++) {
        cuadrados[i] = enteros[i]*enteros[i];
    }
}

void resultados(int enteros[100], int cuadrados[100]){
    int i;
    printf("      Tabla de enteros y sus cuadrados     \n");
    printf(" Número |  Cuadrado  \n");
    printf("---------------------\n");
    for (i=0; i<100; i++) {
        printf("  %d      |  %d  \n",enteros[i], cuadrados[i]);
    }
    
}
