//
//  Listado Alumnos.c
//  
//
//  Created by Andres Moguel on 1/26/21.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void capturas(char Alumnos[20][50], int edades[20], int *cuantos);
void busqueda(char Alumnos[20][50], int edades[20], int cuantos);
void imprimir(char Alumnos[20][50], int edades[20], int cuantos);

int main(void){
    char Alumnos[20][50];
    int edades[20];
    int cantidad;
    capturas(Alumnos,edades, &cantidad);
    imprimir(Alumnos, edades, cantidad);
    busqueda(Alumnos, edades, cantidad);
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
    //usamos while para incrementar el valor de i.
    //i se incrementa hasta llegar al valor donde si se encuentra el alumno
    while ((strcmp(buscar, Alumnos[i])!=0)&&(i<cuantos)) {
        i++;
    }
    //si i es menor a cuantos (esta dentro del arreglo, imprimimos el arreglo de la posición i)
    if (i<cuantos) {
        printf("%s tiene edad: %d", Alumnos[i],edades[i]);
    }
    //si i ya no es parte del arreglo o bueno su valor no lo es
    else
        printf("%s no esta en la lista", buscar);
}

void imprimir(char Alumnos[20][50], int edades[20], int cuantos){
    int i;
    printf("la lista completa es:\n");
    for (i=0; i<=cuantos; i++) {
        printf("Nombre: %s Edad: %d\n", Alumnos[i], edades[i]);
    }
}

