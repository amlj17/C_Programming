//
//  eliminar palabra.c
//  
//
//  Created by Andres Moguel on 1/23/21.
//

#include <stdio.h>
#include <string.h>

void LeerFrase(char frase[100]);
void quitaEspacios(char frase[100], char fraseNueva[100]);
void RompePalabras(char fraseNueva[100], char palabras[10][10], int* largo);
void resultados(char palabras[10][10], int largo);

int main(void){
    char frase[100] = {0};
    char fraseNueva[100];
    char palabras[10][10]= {0};
    int largo;
    LeerFrase(frase);
    quitaEspacios(frase, fraseNueva);
    RompePalabras(fraseNueva, palabras, &largo);
    resultados(palabras, largo);
}

void LeerFrase(char frase[100]){
    printf("Ingresa una frase: ");
    scanf("%[^\n]", frase);
}

void quitaEspacios(char frase[100], char fraseNueva[100]){
     int i = 0, j = 0;
    while (frase[i] != '\0')
      {
         if (!(frase[i] == ' ' && frase[i+1] == ' ')) {
           fraseNueva[j] = frase[i];
           j++;
         }
         i++;
      }
      fraseNueva[j] = '\0';
}

void RompePalabras(char fraseNueva[100], char palabras[10][10], int* largo){
    int i=0, j=0, k=0;
    while(fraseNueva[k]!='\0')
    {
        j=0;
        while(fraseNueva[k]!=' '&&fraseNueva[k]!='\0')
        {
            palabras[i][j]=fraseNueva[k];
            k++;
            j++;
        }
        palabras[i][j]='\0';
        i++;
        if(fraseNueva[k]!='\0')
        {
            k++;
        }
    }
    *largo=i;
}
void resultados(char palabras[10][10], int largo){
    int i;
    
    for(i=0;i <largo ;i+=2)
    printf(" %s",palabras[i]);
    printf("\n");
}

