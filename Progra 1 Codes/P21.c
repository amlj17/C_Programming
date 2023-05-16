/*
Andres Moguel
Fundamentos de Prog y Lab
29 de octubre de 2020
Practica 21 apuntadores
Version 1
 */
#include <stdio.h>
//Iniciamos funcion main
void main(){
  float numero1 = 0;
  float numero2= 0;
  float suma = 0;
  float resta = 0;
  float *pointnum1; //variable puntero
  float *pointnum2; //variable puntero
  //Pedimos al usuario los valores
   printf("Ingrese el valor del primer numero \n");
   scanf(" %f" , &numero1);
   printf("Ingrese el valor del segundo numero \n");
   scanf(" %f" , &numero2);
   //inicializamos los punteros
   pointnum1 = &numero1;
   pointnum2 = &numero2;
   //se calcula la suma y resta con los punteros
   suma = *pointnum1 + *pointnum2;
   resta= *pointnum1 - *pointnum2;
   //se imprimen los resultados
   printf("El resultado de la suma es: %f\n", suma);
   printf("El resultado de la resta es: %f\n", resta);
}
