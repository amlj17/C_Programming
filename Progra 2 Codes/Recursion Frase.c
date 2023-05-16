//
//  Recursion Frase.c
//  
//
//  Created by Andres Moguel on 3/4/21.
//

#include<stdio.h>
#include<string.h>
#include <stdlib.h>

void invierte(char frase[], int i);

int  main(void)
{
    char linea[200];
    
    printf("dame una frase: ");
    gets(linea);
    invierte(linea, 0);
    printf("\n");
    
    return 0;
}

void invierte(char frase[], int i){
    if(frase[i]!='\0')
        invierte(frase, i+1);
    printf("%c", frase[i]);
}
