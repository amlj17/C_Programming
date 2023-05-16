//
//  Sel Sort Strings.c
//  
//
//  Created by Andres Moguel on 3/17/21.
//

#include<stdio.h>
#include<string.h>
#include <stdlib.h>

void selsortNom(char arr[50][30], int elementos);

int main(void){
    int total;
    int i;
    char nombres[50][30];
    printf("Cuantos nombres desea ingresar: ");
    scanf("%d", &total);
    fpurge(stdin);
    for (i=0; i<total; i++) {
        printf("ingrese el nombre[%i]: ", i+1);
        gets(nombres[i]);
        fpurge(stdin);
    }
    printf("Desorden:\n");
    for (i=0; i<total; i++) {
        puts(nombres[i]);
    }
    
    selsortNom(nombres, total);
    
    printf("ordenados: \n");
    for (i=0; i<total; i++) {
        puts(nombres[i]);
    }
}


void selsortNom(char arr[50][30], int elementos){
    int i, j, min;
    char temp[30];
    for (i=0; i<elementos; i++)
    {
        min=i;
        for(j=i+1; j<elementos; j++)
            if(strcmp(arr[j],arr[min])<0)
                min=j;
        if(min!=i){
        strcpy(temp, arr[i]);
        strcpy(arr[i], arr[min]);
        strcpy(arr[min], temp);
    }
        
    }
}
