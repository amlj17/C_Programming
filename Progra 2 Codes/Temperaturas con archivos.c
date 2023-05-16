//
//  Temperaturas con archivos.c
//  
//
//  Created by Andres Moguel on 2/4/21.
//
#include <stdio.h>
void ingtemperaturas(int* totales);
void leerTemp(float temperaturas[], int totales);
void promedio(float temperaturas[], float* prom, int totales);
void tempMayores(float temperaturas[], int* max, int totales, float prom);
void resultados(float prom, int max, int totales, float temperaturas[]);
void menu(void);
void guarda_archivo(float temperaturas[], int totales);
void lee_archivo(float temperaturas[],int * totales);

int main(void){
    int totales;
    int opcion;
    int max;
    float prom;
    
    ingtemperaturas(&totales);
    float temperaturas[totales];
    do{
        menu();
        scanf("%d",&opcion);
        switch (opcion)
        {
            case 1:
                    leerTemp(temperaturas, totales);
                    break;
            case 2:
                promedio(temperaturas, &prom, totales);
                break;
            case 3:
                tempMayores(temperaturas, &max, totales, prom);
                break;
            case 4:
                resultados(prom, max, totales, temperaturas);
                break;
            case 5:
                guarda_archivo(temperaturas, totales);
                break;
            case 6:
                lee_archivo(temperaturas, &totales);
                
                
        }
    }while (opcion!=7);
}

void menu(void)
{
    printf("Menu:\n");
    printf("1 Insertar temperaturas\n");
    printf("2 Sacar promedio\n");
    printf("3 Calcular mayores al promedio\n");
    printf("4 Mostar temperaturas\n");
    printf("5 Guardar en archivo\n");
    printf("6 Leer de archivo\n");
    printf("7 Salir\n");
    printf("Opcion: ");
}


void ingtemperaturas(int* totales){
    printf("Ingrese la cantidad de temperaturas deseadas : ");
    scanf("%i", totales);
    while (*totales<0 || *totales>100) {
        printf("Error debe ingresar entre 0 y 100 temperaturas\n");
        printf("Ingrese la cantidad de temperaturas deseadas : ");
        scanf("%i", totales);
        __fpurge(stdin);
    }
}

void leerTemp(float temps[], int totales){
    int i;
    for (i=0; i<totales; i++) {
        printf("Ingresa la temperatura [%i]: ", i+1);
        scanf(" %f", &temps[i]);
        __fpurge(stdin);
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

void resultados(float prom, int max, int totales, float temperaturas[]){
    int i;
    printf("Las temperaturas son:\n");
    for (i=0; i<totales; i++) {
        printf("Temperatura [%d]: %f\n", i+1, temperaturas[i]);
    }
    printf("El media de las temperaturas es: %f \n", prom);
    printf("La cantidad de temperaturas mayores o iguales a la media es: %d \n", max);
}

void guarda_archivo(float temperaturas[], int totales)
{
    int i;
    char nombre_arch[50];
    FILE *archivo;

    printf("Dame el nombre del archivo donde quieres guardar la info:\n");
    __fpurge(stdin);
    gets(nombre_arch);

    archivo=fopen(nombre_arch,"wt");

    for(i=0; i<totales; i++)
    {
        fprintf(archivo,"%f\n",temperaturas[i]);
    }
    fclose(archivo);
}

void lee_archivo(float temperaturas[],int * totales)
{
    int i=0;
    char nombre_arch[50];
    FILE *archivo;

    printf("Dame el nombre del archivo de donde quieres leer la info:\n");
    __fpurge(stdin);
    gets(nombre_arch);

    archivo=fopen(nombre_arch,"rt");
    if (archivo!=NULL)
    {
        while(!feof(archivo))
        {
            fscanf(archivo,"%f\n",&temperaturas[i]);
            i++;
        }
        *totales=i;
        fclose(archivo);
    }
    else
        printf("ese nombre de archivo no existe.\n");

}
