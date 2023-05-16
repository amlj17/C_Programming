//
//  append.c
//  
//
//  Created by Andres Moguel on 2/4/21.
//

#include <stdio.h>

int main(void)
{
  FILE *Archivo;
  char Frase[200];

  Archivo = fopen("algo.txt","at"); //abrimos el archivo
  printf("dame tu frase favorita: \n");
  gets(Frase);
  fprintf(Archivo, "Tu frase favorita es:\n %s\n",Frase);
  // fputs(Frase, Archivo);//escribimos la frase en el archivo
  fclose(Archivo);

  return 0;
}
