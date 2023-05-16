//
//  Letras y Cantidad.c
//  
//
//  Created by Andres Moguel on 1/23/21.
//

#include <stdio.h>
#include <string.h>

void LeerFrase(char frase[1000]);
void contarLetras(char frase[1000], char letras[27], int cantidad[26]);
void resultados(char  letras[27], int cantidad[26]);

int main(void){
    char frase[1000];
    char letras[27] = "abcdefghijklmnopqrstuvwxyz";
    int cantidad[26]= {0};
    LeerFrase(frase);
    contarLetras(frase, letras, cantidad);
    resultados(letras, cantidad);
}

void LeerFrase(char frase[1000]){
    printf("Ingresa una frase: ");
    scanf("%[^\n]", frase);
}

void contarLetras(char frase[1000], char letras[27], int cantidad[26]){
    int i;
    int j;
    char c;
    int max;
    max = strlen(frase);
    //cambio a minusculas
    for (i=0; i<max; i++) {
       if(frase[i]>=65 && frase[i]<=90)
        frase[i]=frase[i]+32;
        }
    //asignamos cada letra de la frase a c y comparamos si es igual al arreglo con el abc
    for (i=0; i<max; i++) {
        c = frase[i];
        for (j=0; j<26; j++) {
            if (c == letras[j]) {
                cantidad[j]++;
            }
        }
    }
}

void resultados(char  letras[27], int cantidad[26]){
    int i;
    printf("las letras que aparecen y su cantidad\n ");
    for (i=0; i<26; i++) {
        if (cantidad[i]>0) {
            printf("la letra %c aparece %d veces\n", letras[i], cantidad[i]);
        }
    }
}

