/*
Prueba del entorno de desarrollo
Andres Moguel Lopez Jensen
211768-5
Fundamentos de Programación y Laboratorio
22 de septiemvre 2020
*/

#include <stdio.h>

int main()
{
/* Declaramos tipos de datos básicos*/

int numeroEntero; // variable de tipo entero
char unCaracter; // caracter
float numeroPuntoDecimal; // Varianble de tipo flotante
double decimalPrecision;

/*Operador de asignación */

int numero1= 10;

int Num1 = 743;
int Num2 = 0734; //Octal
int Num3 = 0Xa; // Hexadecimal

/*Imprimir variables de tipo entero*/
 printf("El valor de numero1 es: %i \n", numero1);
 printf("%i %i %i \n" ,Num1, Num2, Num3);
 printf("%i %o %x \n" ,Num1, Num2, Num3);

/*Variables de tipo flotante*/
float Num4 = 0.00743;
float Num5 = 1.6E3;
float Num6 = 1.6e-3;
float Num7 = 1.6e+3;

/*Imprimir variables de tipo flotante*/
 printf("%f %.2f %f %f \n" ,Num4,Num5,Num6,Num7);

/*Variables de Caracter*/

 char Car1 = 'A';
 char Car2 = 'B';
 char Car3 = 'C';

 printf("%c %c %c \n" ,Car1,Car2,Car3);
/* Secuencia de Escape*/
 printf("%c\t %c\t %c\t \n\a" ,Car1,Car2,Car3);
 printf("%c\v %c\v %c\v \n",Car1, Car2, Car3);
 printf("Secuencia de escape de cadenas\f \n");
 printf("\"Ejemplo de comillas\" \n");

 /*Constante de caracteres */
 char Cad1[] = "Verde2";
 char Cad2[] = "2*(I+3)";
 char Cad3[] = "Linea 1\n Linea 2\n Linea 3\n";
 printf("%s\n", Cad1);
 printf("%s\n", Cad2);
 printf("%s\n", Cad3);

 return 0;
}
