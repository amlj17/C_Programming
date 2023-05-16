/*
Andres Moguel
Fundamentos de Programacion y Laboratorio
Practica 25
3 de Noviembre de 2020
Version 1
*/

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

//Prototipo de funcion
// recibe un int que es el tamaño del arreglo
//recibe el arreglo comp apuntador
void reordenar(int tamano, int *array);

void main(){
  int contador;
  int tamano;
  int *array;
  //tamano del arreglo es definido por el usuario
  printf("Ingrese el tamaño del arreglo: ");
  scanf("%i", &tamano);
  //reservamos el tamaño en memoria
  array = (int *) malloc(tamano * sizeof(int));
  //llenamos el arreglo
  for( contador = 0; contador < tamano; contador++){
    printf("Ingresa el valor de la posicion [%i]: ",contador);
    scanf("%d",  array + contador);
  }
  //llamamos a funcion de reordenar recibe el tamaño y el arreglo
  reordenar(tamano, array);
  //imprimir lista reordenada
  printf("arreglo ordenado\n");
  for(contador = 0; contador < tamano; contador++){
    printf(" array[%i] = %i \n", contador, *(array+contador));
  }
}

//Funcion que ordena de mayor a menor un arreglo

#include <stdio.h>
void reordenar(int tam, int *x){
  int j;
  int k;
  int temporal;
  for(k = 0; k < tam-1; k++){
    for(j = k+1; j < tam; j++){
        if(*(x+j)> *(x+k)){
          temporal = *(x+k);
          *(x+k)= *(x+j);
          *(x+j) = temporal;
        }
      }
  }
}

#Make File para practica 25
all:
        gcc ordenar.c practica25.c -o salidap25

