//
//  strlen_strcpy_strcat.c
//  
//
//  Created by Andres Moguel on 1/27/21.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void LeerFrase(char frase[100]);
int largo(char frase[100]);
void copia(char frase2[100], char frase1[100]);
void concatena(char frase1[100], char frase2[100]);

int main(void){
    char frase1[100];
    char frase2[100];
    int length1;
    int length2;
    
    //lectura
    printf("Ingresa la primer frase\n");
    LeerFrase(frase1);
    printf("Ingresa la segunda frase\n");
    LeerFrase(frase2);
   
    //largo
    length1 = largo(frase1);
    printf("La longitud de la frase 1 es: %d caracteres\n", length1);
    length2 = largo(frase2);
    printf("La longitud de la frase 2 es: %d caracteres\n", length2);
  
    //concatena
    printf("las frases antes de concatenar son: \n");
    printf("frase 1:  %s \n",frase1);
    printf("frase 2:  %s \n",frase2);
    concatena(frase1, frase2);
    printf("las frase después de concatenar es: \n");
    puts(frase1);
   
    //copia
    printf("frases antes de copiar:\n");
    printf("frase 1:  %s \n",frase1);
    printf("frase 2:  %s \n",frase2);
    copia(frase2, frase1);
    printf("copiamos frase1 a frase2:\n");
    printf("frase 1:  %s \n",frase1);
    printf("frase 2:  %s \n",frase2);
    
}

void LeerFrase(char frase[100]){
    printf("Ingresa una frase: ");
    fpurge(stdin);
    gets(frase);
}

int largo(char frase[100]){
    int longitud=0;
    int i;
    i = 0;
    while (frase[i]!='\0') {
        i++;
    }
    longitud = i;
    return longitud;
}

void copia(char frase2[100], char frase1[100]){
    int i=0;
    while (frase1[i]!='\0') {
        frase2[i]=frase1[i];
        i++;
    }
    frase2[i] = '\0';
}

void concatena(char frase1[100], char frase2[100]){
    int i=0;
    int j = 0;
    while (frase1[i]!='\0') {
        i++;
    }
    while (frase2[j]!='\0') {
        frase1[i]=frase2[j];
        j++;
        i++;
    }
    frase1[i] = '\0';
}
