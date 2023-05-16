//
//  Promedios Alumnos.c
//  
//
//  Created by Andres Moguel on 1/21/21.
//

#include <stdio.h>
void llenarMatriz(float calificaciones[20][3]);
void promedios(float califciaciones[20][3], float promedio[20]);
void resultados(float califciaciones[20][3], float promedio[20]);

int main(void){
    float calificaciones[20][3];
    float promedio[20];
    llenarMatriz(calificaciones);
    promedios(calificaciones, promedio);
    resultados(calificaciones, promedio);
}

void llenarMatriz(float calificaciones[20][3]){
    int i, j;
    for (i=0; i<20; i++) {
        printf("dame las calificaciones del alunmo %d:\n", i+1);
        for (j=0; j<3; j++) {
            printf("Dame la calificacion %d:", j+1);
            scanf("%f", &calificaciones[i][j]);
        }
    }
}


void promedios(float califciaciones[20][3], float promedio[20] ){
    int i, j;
    float suma;
        for (i=0; i<20; i++) {
            suma = 0;
        for (j=0; j<3; j++) {
            suma += califciaciones[i][j];
    }
            promedio[i]=suma/3;
        }
    }

void resultados(float califciaciones[20][3], float promedio[20]){
    int i;
    for (i=0; i<20; i++) {
        printf("el promedio del alumno %d es: %f\n",i+1, promedio[i]);
    }
}
