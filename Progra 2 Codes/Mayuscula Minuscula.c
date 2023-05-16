//
//  Mayuscula Minuscula.c
//  
//
//  Created by Andres Moguel on 1/24/21.
//

#include <stdio.h>
#include <string.h>

void LeerFrase(char frase[100]);
void Mayuscula(char frase[100], char frase2[100]);
void Minuscula(char frase2[100]);
void resultados(char frase[100], char frase2[100]);

int main(void){
    char frase[100];
    char frase2[100];
    LeerFrase(frase);
    Mayuscula(frase, frase2);
    Minuscula(frase2);
    resultados(frase, frase2);
}

void LeerFrase(char frase[100]){
    printf("Ingresa una frase: ");
    scanf("%[^\n]", frase);
}

void Mayuscula(char frase[100], char frase2[100]){
    int i;
    strcpy(frase2, frase);
    for (i = 0; frase[i]!='\0'; i++) {
       if(frase[i] >= 'a' && frase[i] <= 'z') {
          frase[i] = frase[i] - 32;
       }
    }
}

void Minuscula(char frase2[100]){
    int m;
    int max;
    max = strlen(frase2);
    //pasamos a minusculas
    for (m=0; m<max; m++) {
       if(frase2[m]>=65 && frase2[m]<=90)
        frase2[m]=frase2[m]+32;
        }
}

void resultados(char frase[100], char frase2[100]){
    printf("%s\n", frase);
    printf("%s\n", frase2);
}
