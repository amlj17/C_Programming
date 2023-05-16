/*
Andres Moguel
Fundamentos de Programacion y Laboratorio
Practica 24
3 de Nov de 2020
Version 1
 */

#include <stdio.h>
void main(){
  // declaramos variables
  int tamanoArreglo;
  int contador;
  int tamanoSuma;
  //pedimos tamano de arreglo
  printf("Ingrese el tamaño deseado del arreglo: \n");
  scanf("%i", &tamanoArreglo);
  float Array1[tamanoArreglo];
  float Array2[tamanoArreglo];
  //determinamos tamano de suma
  if(tamanoArreglo%2 == 0)
    tamanoSuma = (tamanoArreglo/2);
  else
    tamanoSuma = (tamanoArreglo/2)+1;
  float Suma[tamanoSuma];

  //llenamos arreglos
  for( contador = 0; contador < tamanoArreglo; contador++){
    printf("Ingresa el valor de la posicion [%i]: \n",contador);
    scanf("%f", &Array1[contador]);
  }

   for( contador = 0; contador < tamanoArreglo; contador++){
      printf("Ingresa el valor de la posicion [%i]: \n",contador);
      scanf("%f", &Array2[contador]);
   }
   //se hace la suma
   int j = 0;
   for( contador = 0; contador < tamanoArreglo; contador+=2){
     *(Suma+ j) = *(Array1+contador) + *(Array2 + contador);
     printf("El resultado de la posición [%i] es: %f \n", j, *(Suma+j));
     j++;
   }
}
