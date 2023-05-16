/*
Andres Moguel
Fundamentos de Programacion y Laboratorio
Examen 3
17 de Nov de 2020
Version 1
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define MAXCOL 40

/* Funciones.h practica 27*/
#define MAXCOL 40
//prototipo de funciones
void entrada(int *matriz[MAXCOL], int filas, int columnas);
void sumatotal(int *matriz[MAXCOL], int filas, int columnas);
void salida(int *matriz[MAXCOL], int filas, int columnas);
void sumacol(int *matriz[MAXCOL], int filas, int columnas);

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
  printf("la suma de la primer columna es: ");
  //ponemos 1 en donde va cols porque solo queremos la suma de la 1er columna
  sumacol(mat, filas, 1);
  printf("\n");
}

/* Funcion de datos de entrada de matriz
 a ingresar por el usuario
 "entrada.c" */

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

/* Funcion que imprime la matriz ingresada
   salida.c */


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

/* La suma de los elementos de la matriz*/
/* suma.c*/

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

/* Suma de las columnas de la matriz, primer columna
   sumacol.c */
#include <stdio.h>
#include <stdlib.h>
#define MAXCOL 40

//imprime la suma de todas las columnas, para imprimir solo la primer columnaç
//cuando se llama la funcion ponemos el parametro de mc = 1
void sumacol(int *mat[MAXCOL], int nf, int mc){
  int contF=0;
  int contC=0;
  int Acumulado=0;
  for(contC=0; contC<mc;contC++){
    for(contF=0; contF<nf; contF++)
      Acumulado += *(*( mat + contF) + contC);
  }
printf("%i", Acumulado);
}

