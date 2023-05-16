/*
Andres Moguel
FUndamentos de Programacion y Laboratorio
Practica 12 funciones for
6 de octubre de 2020
Version 1
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*declaración de funciones*/
float suma(float limInf, float limSup, float inc);
float valorneg(float liminft, float limsup, float inc);
float valmay(float liminft, float limsup, float inc);
float valorCero(float f);
//funcion main
void main(){
  /*Se declaran variables de tipo flotante, los limites superior e inferior para acotar el domini\
o de la funcion, por cuanto se hará el incremento para cada evaluación*/
  float limiteSuperior;
  float limiteInferior;
  float incremento;
  float resultadoSuma=0;
  float resultadoNeg=0;
  float resultadoMayor=0;
  float resultadoOperacion=0;
  /*Se le pide al usuario ingresar los limites y el incremento*/
  printf("Ingresa el limite inferior: ");
  scanf("%f", &limiteInferior);
  printf("Ingresa el limite superior: ");
  scanf("%f", &limiteSuperior);
  printf("Ingrese los incrementos: ");
  scanf("%f", &incremento);
  /*Inciso a se llama funcion*/
  resultadoSuma=suma(limiteInferior, limiteSuperior, incremento);
  printf("La suma de todas las g(x) es: %f \n", resultadoSuma);
  /*Inciso b se llama la funcion*/
  resultadoNeg=valorneg(limiteInferior, limiteSuperior, incremento);
  printf("la suma de todas las g(x) negativas es: %f \n", resultadoNeg);
  /*inciso c se llama a la funcion*/
  resultadoMayor=valmay(limiteInferior, limiteSuperior, incremento);
  printf("El valor mayor es %f \n", resultadoMayor);
  /*Inciso d se llama a la funcion*/
  resultadoOperacion=valorCero(0);
  printf("El valor de x cuando f(x)=0 es: %f \n", resultadoOperacion);
  }

/*declaracion de funciones*/
//suma
float suma(float a, float m, float l){
  float x;
  float sum=0;
  for(x = a; x <= m; x+=l){
    sum=sum+pow(x,3)-5;
  }
  return sum;
}

//valores negativos
float valorneg(float a, float m, float l){
  float x;
  float sum=0;
  for(x = a; x <= m; x+=l){
    if(x<0){
    sum=sum+pow(x,3)-5;
    }
  }
  return sum;
}

//valor mayor
float valmay(float a, float m, float l){
  float x;
  float sumpos=0;
  float sumneg =0;
  float valmayor;
  for(x = a; x <= m; x+=l){
    if(x<0){
    sumneg=sumneg+pow(x,3)-5;
    }
    else{
      sumpos=sumpos+pow(x,3)-5;
    }
  }
  printf("Suma negativos: %f \n",sumneg);
  printf("Suna positivos: %f \n", sumpos);
  if(abs(sumneg)>abs(sumpos)){
      valmayor=sumneg;
    }
    else
      valmayor=sumpos;
  return valmayor;
}
//Valor en f(x)=0
float valorCero(float a){
  return cbrtf(a+5);
}


