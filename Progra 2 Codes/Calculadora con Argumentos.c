//
//  Calculadora con Argumentos.c
//  
//
//  Created by Andres Moguel on 2/10/21.
//

#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int i;
    int num1;
    int num2;
    int resultado;
    sscanf(argv[1],"%d", &num1);
    sscanf(argv[3],"%d", &num2);
    if (strcmp(argv[2], "+")==0) {
        resultado=num1+num2;
        printf("%d\n", resultado);
    }
    else  if (strcmp(argv[2], "-")==0) {
           resultado=num1-num2;
            printf("%d\n", resultado);
       }
    else if (strcmp(argv[2], "x")==0) {
              resultado=num1*num2;
               printf("%d", resultado);
          }
    else if (strcmp(argv[2], "/")==0) {
              resultado=num1/num2;
               printf("%d\n", resultado);
          }
    else
      printf("ingresa algo valido");
}
