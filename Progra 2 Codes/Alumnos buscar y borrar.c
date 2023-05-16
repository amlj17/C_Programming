//
//  Alumnos buscar y borrar.c
//  
//
//  Created by Andres Moguel on 1/27/21.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void capturas(char Alumnos[20][50], int edades[20], int *cuantos);
void busqueda(char Alumnos[20][50], int edades[20], int cuantos);
void imprimir(char Alumnos[20][50], int edades[20], int cuantos);
void borra(char Alumnos[20][50], int edades[20], int *cuantos);

int main(void){
    char Alumnos[20][50];
    int edades[20];
    int cantidad;
    capturas(Alumnos,edades, &cantidad);
    imprimir(Alumnos, edades, cantidad);
    busqueda(Alumnos, edades, cantidad);
    borra(Alumnos, edades, &cantidad);
    imprimir(Alumnos, edades, cantidad);
}

void capturas(char Alumnos[20][50], int edades[20], int *cuantos){
    int i;
    printf("Cuantos alumnos tienes: ");
    scanf("%d", cuantos);
    for (i=0; i<*cuantos; i++) {
        printf("Ingresa los datos del alumno [%d]:\n", i+1);
        printf("Ingresa el nombre: ");
        fpurge(stdin);
        gets(Alumnos[i]);
        printf("Ingresa la edad: ");
        scanf("%d", &edades[i]);
    }
}

void busqueda(char Alumnos[20][50], int edades[20], int cuantos){
    int i=0;
    char buscar[50];
    printf("ingrese el nombre del Alumno que desea buscar: ");
    fpurge(stdin);
    gets(buscar);
    while ((strcmp(buscar, Alumnos[i])!=0)&&(i<cuantos)) {
        i++;
    }
    if (i<cuantos) {
        printf("%s tiene edad: %d", Alumnos[i],edades[i]);
    }
    else
        printf("%s no esta en la lista", buscar);
}

void borra(char Alumnos[20][50], int edades[20], int *cuantos){
    int i=0;
    int j;
    char borrar[50];
    printf("ingrese el nombre del Alumno que desea bprrar: ");
    fpurge(stdin);
    gets(borrar);
    while ((strcmp(borrar, Alumnos[i])!=0)&&(i<*cuantos)) {
        i++;
    }
    if (i<*cuantos) {
        for (j=i; j<*cuantos; j++) {
            strcpy(Alumnos[j], Alumnos[j+1]);
            edades[j] = edades[j+1];
        }
        (*cuantos)--;
    }
    else
        printf("%s no esta en la lista", borrar);
}

void imprimir(char Alumnos[20][50], int edades[20], int cuantos){
    int i;
    printf("la lista completa es:\n");
    for (i=0; i<cuantos; i++) {
        printf("Nombre: %s Edad: %d\n", Alumnos[i], edades[i]);
    }
}
