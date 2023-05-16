/*
Andres Moguel
Fundamentos de Programacion y Laboratorio
Practica 22
30 de Octubre de 2020
Version 1
 */
/*Se define el parametro k*/
#include <stdio.h>
#include <math.h>
#define k 9E9

void main(){
  //declaramos variables
  float q1 = 0;
  float q2 =0;
  float r ;
  float F =0;
  float limiteInferior;
  float limiteSuperior;
  //declaramos sus punteros
  float *pointq1;
  float *pointq2;
  float *pointr;
  //pedimos al usuario los valores
  printf("Ingrese el valor de q1:\n");
  scanf("%f" ,&q1);
  printf("Ingrese el valor de q2\n");
  scanf("%f" ,&q2);
  //pedimos al usuario los limites
  printf("Ingresa el limite inferior: \n");
  scanf("%f", &limiteInferior);
  printf("Ingresa el limite superior: \n");
  scanf("%f", &limiteSuperior);
  //inicializamos punteros

    pointq1 = &q1;
      pointq2 = &q2;
      pointr = &r;
      //Imprimimos resultados
      printf("q1[C] = %f\n", *pointq1);
      printf("q2[C] = %f\n", *pointq2);
      printf("Limite inferior: %f\n", limiteInferior);
      printf("Limite Superior: %f\n", limiteSuperior);
      printf("Fuerza     Radio\n");
      //calculamos F e imprimimos
      for(*pointr = limiteInferior; *pointr <= limiteSuperior; *pointr+=1){
        if(*pointr == 0){
          printf("Valor no definido r = %f\n", *pointr);
        }
        else{
        F = k * (*pointq1 * *pointq2/(pow(*pointr,2)));
        printf("%f     %f\n", F, *pointr);
        }
      }
    }


