//
//  Argumentos de Programa.c
//  
//
//  Created by Andres Moguel on 2/10/21.
//

#include<stdio.h>

int main(int argc, char *argv[])
{
  int i;
  printf("La linea de comandos tiene %d argumentos\n", argc);
  for(i=0; i<argc; i++){
    puts(argv[i]);
  }
}
