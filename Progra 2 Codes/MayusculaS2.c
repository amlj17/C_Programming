//
//  MayusculaS2.c
//  
//
//  Created by Andres Moguel on 1/24/21.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void LeerFrase(char frase[100]);
void Mayuscula2(char frase[100]);
void resultados(char frase[100]);

int main(void){
    char frase[100];
    LeerFrase(frase);
    Mayuscula2(frase);
    resultados(frase);
}

void LeerFrase(char frase[100]){
    printf("Ingresa una frase: ");
    scanf("%[^\n]", frase);
}

void Mayuscula2(char frase[100]){
     int largo = strlen(frase);
     
     for(int i=0;i<largo;i++)
     {
         if(i==0||i==(largo-1))
         {
             frase[i]=toupper(frase[i]);
         }
         else if(frase[i]==' ')//Conerting characters present before and after space to uppercase.
         {
             frase[i-1]=toupper(frase[i-1]);
             frase[i+1]=toupper(frase[i+1]);
             
         }
     }
}

void resultados(char frase[100]){
    printf("%s\n", frase);
}
