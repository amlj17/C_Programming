/*
Andres Moguel
Fundamentos de Programación y Laboratorio
16 de Octubre de 2020
Practica 16 Funciones y Arreglos
Version 1
*/

#include <stdio.h>

/* declaracion de funciones
Todas regresan un entero
funciones para cada opcion del menú
suma, promedio, pares en suma de arrays, impares en multiplicacion de arrays
*/
float arregloSuma(float arreglo[], int tamano);
float arregloPromedio(float arreglo[], int tamano);
int arregloPares(int arreglo1[], int arreglo2[], int tamano);
int arregloImpares(int arreglo1[], int arreglo2[], int tamano);

/*Inicializamos la funcion main*/
void main(){
  /*declaramos las variables correspondientes, todas de tipo entero*/
  int opcion;
  int contador;
  int tamanoArreglo=0;
  float resultadoSuma=0;
  float resultadoPromedio=0;
  int resultadoPares=0;
  int resultadoImpares=0;

  /* Se imprime el menu con las distintas opciones*/
  printf("*******************************************\n");
  printf("Operaciones realizables por el programa\n");
  printf("     1. Suma del Arreglo\n");
  printf("     2. Promedio del Arreglo\n");
  printf("     3. Pares de suma del Arreglo\n");
  printf("     4. Impares de producto del Arreglo\n");
  printf("     5. Salir\n");
  printf("*******************************************\n");
  /*Mientras no se seleccione salir, el programa se repite*/
  while(opcion != 5){
    printf("Seleccione la opcion deseada: \n");
    scanf("%i", &opcion);
    /*se hace un switch case para cada opcion*/
    switch(opcion){
        case 1:{
          /*En este caso se evalua la suma del total del arreglo ingresado por el usuario*/
          printf("Se seleccionó la opcion 1\n");
          printf("Ingrese el tamaño deseado del arreglo: \n");
          scanf("%i", &tamanoArreglo);
          /*Declaramos el arreglo para sumar*/
          float Suma[tamanoArreglo];
          /*llenamos el arreglo*/
          for(contador = 0; contador < tamanoArreglo; contador++){
            printf("Ingresa el valor de la posicion [%i]: \n",contador);
            scanf("%f", &Suma[contador]);
          }
          /*llamamos la funcion arregloSuma, recibe un arreglo de tipo int y un entero*/
          resultadoSuma = arregloSuma(Suma, tamanoArreglo);
          printf("la suma total de los valores del arreglo es: %f\n", resultadoSuma);
          break;}
        case 2:{
           /*En este caso se evalua el promedio del total del arreglo ingresado por el usuario*/
          printf("Se seleccionó la opcion 2\n");
          printf("Ingrese el tamaño deseado del arreglo: \n");
          scanf("%i", &tamanoArreglo);
          /*Declaramos el arreglo para el promedio*/
          float Promedio[tamanoArreglo];
          /*llenamos el arreglo*/
          for( contador = 0; contador < tamanoArreglo; contador++){
            printf("Ingresa el valor de la posicion [%i]: \n",contador);
            scanf("%f", &Promedio[contador]);
          }
          /*llamamos la funcion arregloPromedio, recibe un arreglo de tipo int y un entero*/
          resultadoPromedio = arregloPromedio(Promedio, tamanoArreglo);
          printf("el promedio de los valores del arreglo es: %f\n", resultadoPromedio);
          break;}
        case 3:{
            /*En este caso se evalua los numeros pares de un arreglo*/
            printf("Se seleccionó la opcion 3\n");
            /*Se pide el tamaño de ambos arreglos*/
            printf("Ingrese el tamaño deseado de los arreglos a ingresar: \n");
            scanf("%i", &tamanoArreglo);
            /*Declaramos el primer arreglo*/
            int ArregloA[tamanoArreglo];
            /*llenamos el arreglo*/
            for(contador = 0; contador < tamanoArreglo; contador++){
              printf("Ingresa el valor de la posicion [%i]: \n",contador);
              scanf("%i", &ArregloA[contador]);
            }
            /*Declaramos el segundo arreglo*/
            int ArregloB[tamanoArreglo];
            /*llenamos el arreglo*/
            for(contador = 0; contador < tamanoArreglo; contador++){
              printf("Ingresa el valor de la posicion [%i]: \n",contador);
              scanf("%i", &ArregloB[contador]);
            }
            /*llamamos la funcion arregloPares, recibe dos arreglos de tipo int y un entero*/
            resultadoPares = arregloPares(ArregloA, ArregloB, tamanoArreglo);
            printf("el numero de numeros pares en el arreglo de la suma de los arreglos es: %i\n", resultadoPares);
            break;}
        case 4:{
            /*En este caso se evalua los numeros impares de un arreglo*/
            printf("Se seleccionó la opcion 4\n");
            /*Se pide el tamaño de ambos arreglos*/
            printf("Ingrese el tamaño deseado de los arreglos a ingresar: \n");
            scanf("%i", &tamanoArreglo);
            /*Declaramos el primer arreglo*/
            int ArregloC[tamanoArreglo];
            /*llenamos el arreglo*/
            for(contador = 0; contador < tamanoArreglo; contador++){
                printf("Ingresa el valor de la posicion [%i]: \n",contador);
                scanf("%i", &ArregloC[contador]);
            }
            /*Declaramos el segundo arreglo*/
            int ArregloD[tamanoArreglo];
            /*llenamos el arreglo*/
            for(contador = 0; contador < tamanoArreglo; contador++){
                printf("Ingresa el valor de la posicion [%i]: \n",contador);
                scanf("%i", &ArregloD[contador]);
            }
            /*llamamos la funcion arregloImpares, recibe dos arreglos de tipo int y un entero*/
            resultadoImpares = arregloImpares(ArregloC, ArregloD, tamanoArreglo);
            printf("el numero de numeros impares en el arreglo de la multiplicacion de los arreglos es: %i\n", resultadoImpares);
            break;}
        case 5:{
            /*opcion de salir*/
            printf("Salir\n");
            break;}
        default:{
            printf("Seleccione una opcion válida \n");
            break;}
 }
  }
}

/*Declaracion de las disrintas funciones*/
/*funcion de la suma*/
float arregloSuma(float valores[], int tamano){
  float sumaValores = 0;
  int counter;
  //se recorre el arreglo y se van sumando los valores
  for(counter = 0; counter < tamano; counter++){
    sumaValores+=valores[counter];
  }
    return sumaValores;
}
/*funcion del promedio*/
float arregloPromedio(float arreglo[], int tamano){
  float sumaValores = 0;
  int counter;
  float promedio=0;
  //se recorre el arreglo y se van sumando los valores
  for(counter = 0; counter < tamano; counter++){
    sumaValores+=arreglo[counter];
  }
  promedio = sumaValores/(float)tamano; //hacemos un casteo para cambiar de int a float
  return promedio;
}
/*funcion de los pares*/
int arregloPares(int arreglo1[], int arreglo2[], int tamano){
  int arregloSumado[tamano];
  int counter;
  int totalPares=0;
  //llenamos el nuevo arreglo
  for(counter = 0; counter < tamano; counter++){
    arregloSumado[counter]= (arreglo1[counter] + arreglo2[counter]);
  }
  //encontramos los numeros pares con el modulo
  for(counter = 0; counter < tamano; counter++){
    if((arregloSumado[counter])%2==0){
      totalPares++;
    }
  }
  return totalPares;
}
/*funcions de los impares*/
int arregloImpares(int arreglo1[], int arreglo2[], int tamano){
  int arregloProducto[tamano];
  int counter;
  int totalPares=0;
  int totalImpares=0;
  //llenamos el nuevo arreglo de la multiplicacion
  for(counter = 0; counter < tamano; counter++){
    arregloProducto[counter]= (arreglo1[counter] * arreglo2[counter]);
  }
  //encontramos los numeros impares con el modulo
  for(counter = 0; counter < tamano; counter++){
    if((arregloProducto[counter])%2==0){
      totalPares++;
    }
    else{
      totalImpares++;
    }
  }
  return totalImpares;
}
