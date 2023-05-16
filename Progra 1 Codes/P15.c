/*
Andres Moguel
Fundamentos de Programacion y Lab.
13 de Octubre de 2020
Practica 15
Recursividad
Version 1
 */

#include<stdio.h>
/* definicion de funciones
recibre dos enteros y regresa un entero
calcula el cociente de una division
*/
int cociente(int num, int den);

/*inicio de main*/
void main(){
  /* las variables que se van a usar en main*/
  /*Todas son de tipo entero hay valores de numerador y denominador y el resultado*/
  int valNumerador=7;
  int valDenominador=3;
  int resultado;
  /*Asignamos el resultado a la funcion cociente
  asignando los valores del numerador y denominador*/
  resultado = cociente(valNumerador, valDenominador);
  /*se imprime el resultado*/
  printf("El cociente de la division es: %i \n", resultado);
}

/*funciones utilizadas en main*/
/* Regresa un entero y recibe dos enteros, calcula el cociente*/
int cociente(int num, int den){
  if (num<den){ //condicion de terminacion
      return 0;
    }
  else{
    return(1+cociente((num-den),den)); //se llama la funcion a si misma, recursividad
  }
}

