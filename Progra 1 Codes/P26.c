/*Andres Moguel
Fundamentos de Programacion y Laboratorio
Practica 26
5 de Nov de 2020
Version 1
 */

#include <stdio.h>
#include <stdlib.h>
#define MAXCOL 40

//prototipo de funciones
void entrada(int *matriz[MAXCOL], int filas, int columnas);
void suma(int *matriz[MAXCOL], int filas, int columnas);
void salida(int *matriz[MAXCOL], int filas, int columnas);

void main(){
  int counter;
  int filas;
  int cols;
  //puntero de matriz
  int *mat[MAXCOL];
  printf("Ingrese el numero de filas: ");
  scanf("%i", &filas);
  printf("Ingrese el numero de columnas: ");
  scanf("%i", &cols);
  printf("Matriz de %i x %i\n", filas, cols);
  //reservamos memoria
  for(counter = 0; counter<filas; counter++){
    mat[counter] = (int *) malloc (cols * sizeof(int));
  }
  //llamada de distintas funciones
  printf("Matriz Ingresada\n");
  printf("Datos de entrada\n");
  entrada(mat, filas, cols);
  printf("La matriz ingresada es: \n");
  salida(mat, filas, cols);
  printf("La suma de todas las filas es: ");
  suma(mat, filas, cols);
  printf("\n");
}

//funciones
//datos de entrada, recibe matriz y filas y columnas
void entrada(int *mat[MAXCOL], int nf, int mc){
  int contF=0;
  int contC=0;
  for(contF=0; contF<nf;contF++){
    for(contC=0; contC<mc; contC++){
      printf("Datos de [%i][%i]: ", contF+1, contC);
      scanf("%i", (*( mat + contF) + contC));
    }
  }
}
//Imprime la matriz ingresada por el usuario
void salida(int *mat[MAXCOL], int nf, int mc){
  int contF=0;
  int contC=0;
  for(contF=0; contF<nf;contF++){
    for(contC=0; contC<mc; contC++){
      printf("%i  ", *(*( mat + contF) + contC));
    }
    printf("\n");
  }
}
//imprime la suma de todos los componentes cde la matriz
void suma(int *mat[MAXCOL], int nf, int mc){
  int contF=0;
  int contC=0;
  int Acumulado=0;
  for(contF=0; contF<nf;contF++){
    for(contC=0; contC<mc; contC++)
      Acumulado += *(*( mat + contF) + contC);
  }
printf("%i", Acumulado);
}
