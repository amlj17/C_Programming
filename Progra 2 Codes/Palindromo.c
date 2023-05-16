//
//  Palindromo.c
//  
//
//  Created by Andres Moguel on 1/23/21.
//

#include <stdio.h>
#include <string.h>

void LeerFrase(char frase[100]);
void QuitaEsp(char frase[100]);
void RevisarPali(char frase[100], char reves[100], int* resultado);
void resultados(int resultado);

int main(void){
    char frase[100];
    char reves[100];
    int resultado;
    LeerFrase(frase);
    QuitaEsp(frase);
    RevisarPali(frase, reves, &resultado);
    resultados(resultado);
}

void LeerFrase(char frase[100]){
    printf("Ingresa una frase: ");
    scanf("%[^\n]", frase);
}

void QuitaEsp(char frase[100]){
      int count = 0;
      for (int i = 0; frase[i]; i++)
          if (frase[i] != ' ')
              frase[count++] = frase[i]; // here count is
                                     // incremented
      frase[count] = '\0';
}

void RevisarPali(char frase[100], char reves[100], int* resultado){
    int i=0;
    int j;
    int m;
    int max;
    max = strlen(frase);
    //pasamos a minusculas
    for (m=0; m<max; m++) {
       if(frase[m]>=65 && frase[m]<=90)
        frase[m]=frase[m]+32;
        }
   // Volteamos el string
    j=0;
    for (i=strlen(frase)-1; i>=0; i--) {
           reves[j]=frase[i];
           j++;
       }
    reves[j] = '\0';
    if (strcmp(frase, reves) == 0)  // comparar
        *resultado=1;
     else
       *resultado=0;

}
void resultados(int resultado){
    if (resultado==1) {
        printf("La frase es un palindromo.\n");
    }
    if (resultado==0) {
            printf("la frase no es un palindromo.\n");
        }
}
