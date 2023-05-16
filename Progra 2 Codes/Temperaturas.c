//
//
// temperaturas
//
//

#include <stdio.h>
void leerTemp(float temperaturas[]);
void promedio(float temperaturas[], float* prom);
void tempMayor(float temperaturas[], float* max);
void tempBaja(float temperaturas[], float* min);
void resultados(float prom, float max, float min);

int main(void){
    float temperaturas[24];
    float max;
    float min;
    float prom;
    leerTemp(temperaturas);
    promedio(temperaturas, &prom);
    tempMayor(temperaturas, &max);
    tempBaja(temperaturas, &min);
    resultados(prom, max, min);
}

void leerTemp(float temps[24]){
    int i;
    for (i=0; i<24; i++) {
        printf("Ingresa la temperatura de las [%i:00] horas: ", i);
        scanf(" %f", &temps[i]);
    }
}

void promedio(float temperaturas[], float* prom){
    int i;
    int acumulado =0;
    float elementos = 0;
    for (i=0; i<24; i++) {
        acumulado +=  temperaturas[i];
        elementos++;
    }
    *prom = (acumulado/elementos);
}

void tempMayor(float temperaturas[], float* max){
    int i;
    *max = temperaturas[0];
    for (i=0; i<24; i++) {
        if (*max < temperaturas[i]) {
            *max = temperaturas[i];
        }
    }
}

void tempBaja(float temperaturas[], float* min){
    int i;
    *min = temperaturas[0];
    for (i=0; i<24; i++) {
        if (*min > temperaturas[i]) {
            *min = temperaturas[i];
        }
    }
}

void resultados(float prom, float max, float min){
    printf("El promedio de las temperaturas es: %f \n", prom);
    printf("La temperatura máxima es: %f \n", max);
    printf("La temperatura mínima es: %f \n", min);
}
