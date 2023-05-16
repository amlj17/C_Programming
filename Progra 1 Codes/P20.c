/*
Andres Moguel
Fundamentos de Prog y Lab
27 de octubre de 2020
Practica 20 funciones modular
Version 1
Principal.c
 */
#include <stdio.h>
#include "funciones.h"

float suma(float, float);
float resta(float, float);
float multiplicacion(float, float);
float division(float, float);

void main(){
  // declaramos variables
  float numero1;
  float numero2;
  //se le piden los datos al usuario
   printf("Ingrese el valor del primer numero \n");
   scanf(" %f" , &numero1);
   printf("Ingrese el valor del segundo numero \n");
   scanf(" %f" , &numero2);

   //imprimimos los reultados
   printf("El resultado de la suma es: %f\n", suma(numero1, numero2));
   printf("El resultado de la resta es: %f\n", resta(numero1, numero2));
   printf("El resultado de la multiplicacion es: %f\n", multiplicacion(numero1, numero2));
   printf("El resultado de la division es: %f\n", division(numero1, numero2));

}

//funcionsuma.c
#include <stdio.h>
float suma(float x, float y){
   float resultado;
   resultado = x+y;
   return resultado;
 }

//funcionMult.c
#include <stdio.h>
float multiplicacion(float x, float y){
   float resultado;
   resultado = x*y;
   return resultado;
 }

//funcionDiv.c
#include <stdio.h>
float division(float x, float y){
   float resultado;
   resultado = x/y;
   return resultado;
 }

//funcionresta.c
#include <stdio.h>
float resta(float x, float y){
   float resultado;
   resultado = x-y;
   return resultado;
 }

#Se compilan lo siguiente

all:
        gcc principal.c funcionsuma.c funcionresta.c funcionDiv.c funcionMult.c -o salidaP20
