//
//  memoria dinamica arreglo bi.c
//  
//
//  Created by Andres Moguel on 2/11/21.
//

#include<stdio.h>
#include <stdlib.h>
void leer(int **tabla, int fil, int col);
void imprime(int **tabla, int fil, int col);

int main(void){
    int **matriz;
    int i;
    int renglones;
    int columnas;
    
    printf("Cuantos renglones y columnas tienes: ");
    scanf("%d,%d", &renglones,&columnas);
    
    matriz = (int**)malloc(sizeof(int*)*renglones);
    
    for (i=0; i<renglones; i++) {
        matriz[i]=(int*)malloc(sizeof(int)*columnas);
    }
    
    leer(matriz, renglones, columnas);
    imprime(matriz, renglones, columnas);
    
    for (i=0; i<renglones; i++) {
        free(matriz[i]);
       }
    free(matriz);
    
    return 0;
}

void leer(int **tabla, int fil, int col){
    int i,j;
    for(i=0; i<fil; i++){
        for (j=0; j<col; j++) {
            printf("dame el numero %d %d: ", i+1, j+1);
            scanf("%d", &tabla[i][j]);
        }
    }
}

void imprime(int **tabla, int fil, int col){
    int i, j;
    for(i=0; i<fil; i++){
        for (j=0; j<col; j++) {
            printf("%d ", tabla[i][j]);
        }
        printf("\n");
    }
}
