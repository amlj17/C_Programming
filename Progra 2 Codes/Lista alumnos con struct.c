//
//  Lista alumnos con struct.c
//  
//
//  Created by Andres Moguel on 1/28/21.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct def_lista{
    char nombre[20];
    float cal1;
    float cal2;
    float cal3;
    float promedio;
}tipo_alumno;

void Leer(tipo_alumno lista[]);
void calcProm(tipo_alumno lista[]);
void imprimir(tipo_alumno lista[]);

int main(void){
    tipo_alumno grupo[10]; //declaramos variable tipo estructura de lista que se llama grupo
    
}



void Leer(struct def_lista grupo[10]){
    int i;
    for (i=0; i<10; i++) {
        printf("ingresa los datos del alumno [%d] \n", i+1);
        printf("Nombre: ");
        gets(grupo[i].nombre);
        fpurge(stdin);
        printf("Calificacion 1:");
        scanf("%f", &grupo[i].cal1);
        fpurge(stdin);
        printf("Calificacion 2:");
        scanf("%f", &grupo[i].cal2);
        fpurge(stdin);
        printf("Calificacion 3:");
        scanf("%f", &grupo[i].cal3);
        fpurge(stdin);
    }
}

void calcProm(struct def_lista *grupo){
    int i;
    for (i=0; i<10; i++) {
        grupo[i].promedio = (grupo[i].cal1+grupo[i].cal2+grupo[i].cal3)/3;
    }
}

void imprimir(struct def_lista *grupo){
    int i;
    printf("la lista es:");
    for (i=0; i<20; i++) {
        printf("Nombre %s    cal1:%f, cal2:%f, cal3%f = %f \n",grupo[i].nombre, grupo[i].cal1,grupo[i].cal2, grupo[i].cal2, grupo[i].cal3, grupo[i].promedio );
    }
}
