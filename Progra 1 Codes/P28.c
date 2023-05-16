/*
Andres Moguel
Fundamentos de Programacion y Laboratorio
Practica 28
10 de Noviembre de 2020
Version 1
*/

#include <stdio.h>
#include <stdlib.h>

//prototipos de funciones tanto entrada como rango
void entrada(int *arreglo, int tam);
void rango(int *arreglo, int tam, int *VT, int *TC, int *CS, int *OT);

//inicializamos main
void main(){
  //declaramos las variavles a utilizar
  int tamano;
  int *array;
  int veinteTreinta = 0;
  int treintaCincuenta = 0;
  int cincuentaSetenta = 0;
  int otros = 0;
  //tamano del arreglo es definido por el usuario
  printf("Ingrese el tamaño del arreglo: ");
  scanf("%i", &tamano);
  //reservamos el tamaño en memoria (asignacion dinamica)
  array = (int *) malloc(tamano * sizeof(int));
  //llamamos la funcion de entrada
  entrada(array, tamano);
  //llamamos funcion rango de valores con el metodo de por referencia
  rango(array, tamano, &veinteTreinta, &treintaCincuenta, &cincuentaSetenta, &otros);
  //se imprimen los resultados
  printf("Imprimimos los valores en los rangos \n");
  printf("Valores entre 20-30: %i\n", veinteTreinta);
  printf("Valores entre 30-50: %i\n", treintaCincuenta);
  printf("Valores entre 50-70: %i\n", cincuentaSetenta);
  printf("Otros: %i\n", otros);
}
//fin de main

//funciones
//funcion para ingresar el arreglo, recibe el arreglo vacio y n que es su tamaño
void entrada(int *array, int n){
  int contador=0;
  //llenamos el arreglo
  for( contador = 0; contador < n; contador++){
    printf("Ingresa el valor de la posicion [%i]: ",contador);
    scanf("%d",  array + contador);
  }
}

//funcion para determinar la cantidad de valores en el rango
//recibe el arreglo y su tamaño así como los rangos con cantidades en 0
void rango(int *array, int n, int *VT, int *TC, int *CS, int *O){
  int counter =0;
  //asignamos a los distintos valores con un for con ifs dentro
  for( counter = 0; counter < n; counter++){
    if(*(array+counter)>=20 && *(array+counter)<=30)
      ++ *VT;
    else if(*(array+counter)>=30 && *(array+counter)<=50)
      ++ *TC;
    else if(*(array+counter)>=50 && *(array+counter)<=70)
      ++ *CS;
    else
      ++ *O;
  }
}

