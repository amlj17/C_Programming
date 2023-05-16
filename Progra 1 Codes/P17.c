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

//Prototipo de fucniones
void llenarMatriz(int mat[MAXFIL][MAXCOL], int fila, int colu); //recibe una matriz y dos e\
nteros
void imprimirMatriz(int mat[MAXFIL][MAXCOL], int fila, int colu); //recibe una matriz y dos\
 enteros
int sumaMatriz(int mat1[MAXFIL][MAXCOL], int mat2[MAXFIL][MAXCOL], int fila, int colu); //r\
ecibe 2 matrices y dos enteros

void main(){
  /* declaramos las variables y arreglos a utilizar en el program*/
  int numfilas;
  int numcolumnas;
  int matriz[MAXFIL][MAXCOL];
  int matrizX[MAXFIL][MAXCOL];
  int resultadoSuma = 0; //resultado de la suma total de los elementos de ambas matrices
  /*se le pide al usuario el numero de filas y columnas de la matriz*/
  printf("Ingrese el numero de filas de la matriz: \n");
  scanf("%i", &numfilas);
  printf("Ingrese el numero de coulmnas de la matriz:\n");
  scanf("%i", &numcolumnas);
  /* Se llena e imprime la primer matriz a traves de funciones*/
  printf("Primera matriz\n");
  llenarMatriz(matriz, numfilas, numcolumnas); //funcion de llenado
  imprimirMatriz(matriz, numfilas, numcolumnas); //funcion de impresion
  /*se llena e imprime la segunda matriz a través de funciones*/
  printf("Segunda Matriz\n");
  llenarMatriz(matrizX, numfilas, numcolumnas); //funcon de llenado
  imprimirMatriz(matrizX, numfilas, numcolumnas); //funcion de impresion
  resultadoSuma = sumaMatriz(matriz, matrizX, numfilas, numcolumnas); //funcion de suma tot\
al de elementos
  printf("El resultado de la suma de la matriz resultante es: %i \n", resultadoSuma);
}

/*Declaracion de funciones*/
/*funcion de llenado recibe una matriz y dos enteros, no regresa*/
void llenarMatriz(int a[MAXFIL][MAXCOL], int m, int l){
  int fil, col;
  for (fil=0; fil<m; fil++) {
    for (col=0; col<l; col++){
      printf("introducir datos para el elemento [%i][%i]: ", fil, col);
      scanf("%d",&a[fil][col]);
    }
  }
}
/*funcion de impresion recibe una matriz y dos enteros, no regresa*/
void imprimirMatriz(int a[MAXFIL][MAXCOL], int m, int l){
  int fil, col;
  printf("La matriz ingresada es: \n");
    for (fil=0; fil<m; fil++) {
        for (col=0; col<l; col++)
            printf("%4d", a[fil][col]);
            printf(" \n");
    }
}
/*funcion que suma el total de los valores, recibe dos matrices y dos enteros*/
int sumaMatriz(int a[MAXFIL][MAXCOL], int m[MAXFIL][MAXCOL], int l, int j){
  int fil, col;
  int SumaTotal = 0;
  for(fil = 0; fil<l; fil++){
    for(col =0; col<j; col++)
      SumaTotal+=a[fil][col]+ m[fil][col];
  }
  return SumaTotal;
}


