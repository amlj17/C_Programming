/*
Andres Moguel
Fundamentos de Programacion y Laboratorio
Practica 22
29 de Octubre de 2020
Version 1
 */
/*Se define el parametro k*/
#include <stdio.h>
#include <math.h>
#define k 9E9

void main(){
  //declaramos variables
  float q1 =0;
  float q2 =0;
  float r = 0;
  float F =0;
  //declaramos sus punteros
  float *pointq1;
  float *pointq2;
  float *pointr;

  //pedimos al usuario los valores
   printf("Ingrese el valor de q1:\n");
  scanf("%f" ,&q1);
  printf("Ingrese el valor de q2\n");
  scanf("%f" ,&q2);
  printf("Ingrese el valor de r\n");
  scanf("%f", &r);

  //inicializamos punteros
  pointq1 = &q1;
  pointq2 = &q2;
  pointr = &r;

  //calculamos F
  F = k * (*pointq1 * *pointq2/(pow(*pointr,2)));

  //imprimios resultados
  printf("q1[C] = %f\n", *pointq1);
  printf("q2[C] = %f\n", *pointq2);
  printf("r[m] = %f\n", *pointr);
  printf("El valor de la fuerza es: %f [N]\n", F);
}


