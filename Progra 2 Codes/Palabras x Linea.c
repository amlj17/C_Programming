//
//  Palabras x Linea.c
//  
/Users/AndresMoguel 1/Desktop/UIA/4to Semestre UIA/Programación Aplicada/Ejercicios/Temperaturas.c//
//  Created by Andres Moguel on 1/23/21.
//

#include <stdio.h>
#include <string.h>

void LeerFrase(char frase[100]);
void RompePalabras(char frase[100], char palabras[10][10], int* largo);
void resultados(char palabras[10][10], int largo);

int main(void){
    char frase[100] = {0};
    char palabras[10][10]= {0};
    int largo;
    LeerFrase(frase);
    RompePalabras(frase, palabras, &largo);
    resultados(palabras, largo);
}

void LeerFrase(char frase[100]){
    printf("Ingresa una frase: ");
    scanf("%[^\n]", frase);
}

void RompePalabras(char frase[100], char palabras[10][10], int* largo){
    int i=0, j=0, k=0;
    while(frase[k]!='\0')//for splitting sentence
    {
        j=0;
        while(frase[k]!=' '&&frase[k]!='\0')
        {
            palabras[i][j]=frase[k];
            k++;
            j++;
        }
        palabras[i][j]='\0';
        i++;
        if(frase[k]!='\0')
        {
            k++;
        }
    }
    *largo=i;
}
void resultados(char palabras[10][10], int largo){
    int i;
    
    for(i=0;i <largo ;i++)
    printf(" %s",palabras[i]);
    printf("\n");
}




void Separar(char f[])
{
    int i =0;
    int j = 0;
    int k = 0;
    int n,x;
    char p[1000][1000];
    while (f[k] !='\0') {
        j=0;
        while (f[k] != ' ' && (f[k] != '\0')) {
            p[i][j]=f[k];
            k++;
            j++;
        }
        p[i][j]='\0';
        i++;
        if(f[k]='\0')
            k++;
    }
    n=i;
    
    printf("las palabras pares son:\n");
    for (i=0; i<=5; i++) {
        printf("%s",p[i]);
    }
    printf("\n las palabras impares son:\n");
    for (i=0; i<=5; i=i+2) {
        printf("%s",p[i]);
    }
    printf("\n");
}
