/*
Andres Moguel
Fundamentos de Programación y Laboratorio
16 de Octubre de 2020
Practica 16 Funciones y Arreglos
Version 1
*/

#include <stdio.h>
#define MAXFIL 30
#define MAXCOL 30
void main(){
  //definimos la matriz junto con las filas y columnas
    int matriz[MAXFIL][MAXCOL];
    int filas;
    int columnas;
    int i, j; //contador de filas y columnas
    //se pide al usuario filas y columnas
    printf("Introduce el numero de filas \n");
    scanf("%i", &filas);
    printf("Introduce el numero de columnas \n");
    scanf("%i", &columnas);
    for (i=0; i<filas; i++) {
        printf("\n introduce datos para la fila %2d\n", i+1);
        for (j=0; j<columnas; j++) {
            scanf("%d",&matriz[i][j]);
        }
    }
    //se imprime la matriz
    printf("La matriz ingresada es: \n");
    for (i=0; i<filas; i++) {
        for (j=0; j<columnas; j++)
            printf("%4d", matriz[i][j]);
            printf(" \n");
    }
}
