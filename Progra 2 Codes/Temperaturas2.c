//
//  Temperaturas2.c
//  
//
//  Created by Andres Moguel on 1/23/21.
//

#include <stdio.h>
void temperaturas(int* totales);
void leerTemp(float temperaturas[], int totales);
void promedio(float temperaturas[], float* prom, int totales);
void tempMayores(float temperaturas[], int* max, int totales, float prom);
void resultados(float prom, int max);

int main(void){
    int totales;
    temperaturas(&totales);
    float temperaturas[totales];
    int max;
    float prom;
    leerTemp(temperaturas, totales);
    promedio(temperaturas, &prom, totales);
    tempMayores(temperaturas, &max, totales, prom);
    resultados(prom, max);
}

void temperaturas(int* totales){
    printf("Ingrese la cantidad de temperaturas deseadas : ");
    scanf("%i", totales);
    while (*totales<5 || *totales>100) {
        printf("Error d&ebe ingresar entre 5 y 100 temperaturas\n");
        printf("Ingrese la cantidad de temperaturas deseadas : ");
        scanf("%i", totales);
    }
}

void leerTemp(float temps[], int totales){
    int i;
    for (i=0; i<totales; i++) {
        printf("Ingresa la temperatura [%i]: ", i+1);
        scanf(" %f", &temps[i]);
    }
}

void promedio(float temperaturas[], float* prom, int totales){
    int i;
    int acumulado =0;
    float elementos = 0;
    for (i=0; i<totales; i++) {
        acumulado +=  temperaturas[i];
        elementos++;
    }
    *prom = (acumulado/elementos);
}

void tempMayores(float temperaturas[], int* max, int totales, float prom){
    int i;
    *max = 0;
    for (i=0; i<totales; i++) {
        if (prom < temperaturas[i]) {
            *max+=1;
        }
    }
}

void resultados(float prom, int max){
    printf("El media de las temperaturas es: %f \n", prom);
    printf("La cantidad de temperaturas mayores o iguales a la media es: %d \n", max);
}
