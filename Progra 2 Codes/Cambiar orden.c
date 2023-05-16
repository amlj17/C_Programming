//
//  Cambiar orden.c
//  
//
//  Created by Andres Moguel on 1/23/21.
//

#include <stdio.h>
void Leerfrase(char frase[100] );
void reverse(char* inicio, char* fin);
void reverseWords(char frase[100]);
void resultados (char frase[100]);
int main()
{
    char frase[100];
    Leerfrase(frase);
    reverseWords(frase);
    resultados(frase);
    return 0;
}

void Leerfrase(char frase[100]){
    printf("Ingresa una frase: ");
    scanf("%[^\n]", frase);
}

void reverse(char* inicio, char* fin)
{
    char temp;
    while (inicio < fin) {
        temp = *inicio;
        *inicio++ = *fin;
        *fin-- = temp;
    }
}
 
// Function to reverse words*/
void reverseWords(char frase[100])
{
    char* word_inicio = frase;
 
    // Word boundary
    char* temp = frase;
 
    // Reversing individual words as
    // explained in the first step
    while (*temp) {
        temp++;
        if (*temp == '\0') {
            reverse(word_inicio, temp - 1);
        }
        else if (*temp == ' ') {
            reverse(word_inicio, temp - 1);
            word_inicio = temp + 1;
        }
    }
 
    // Reverse the entire string
    reverse(frase, temp - 1);
}

void resultados(char frase[100]){
     printf("%s \n", frase);
}
