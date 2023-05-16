//
//  alumnos dinamica.c
//  
//
//  Created by Andres Moguel on 2/11/21.
//
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

typedef struct def_alumno
{
    char nombre[50];
    float cal1,cal2,cal3,prom;
}tipo_alumno;

void lee(tipo_alumno lista[],int *alumnos_ingresados);
void sacaprom(tipo_alumno lista[],int alumnos_ingresados);
void imprime(tipo_alumno lista[],int alumnos_ingresados);
void menu(void);
void lee_archivo(tipo_alumno lista[],int *alumnos_ingresados);
void guarda_archivo(tipo_alumno lista[],int alumnos_ingresados);
void modifica(tipo_alumno lista[], int alumnos_ingresados);

int main(void)
{
    tipo_alumno *grupo;
    int opcion, alumnos_ingresados;
    int total_alumnos;
    printf("Cuantos alumnos deseas ingresar?: ");
    scanf("%d", &total_alumnos);
    grupo = (tipo_alumno*)malloc(sizeof(tipo_alumno)*total_alumnos);

    alumnos_ingresados=0;
    do
    {
        menu();
        scanf("%d",&opcion);
        switch (opcion)
        {
            case 1: if(alumnos_ingresados<total_alumnos)
                        lee(grupo,&alumnos_ingresados);
                    else
                        printf("ya no puede insertar mas alumnos\n");
                    break;
            case 2: sacaprom(grupo,alumnos_ingresados);
                    break;
            case 3: imprime(grupo,alumnos_ingresados);
                    break;
            case 4: modifica(grupo,alumnos_ingresados);
                    break;
            case 5: guarda_archivo(grupo,alumnos_ingresados);
                    break;
            case 6: lee_archivo(grupo,&alumnos_ingresados);
                    break;
            case 7: printf("Adios\n");
                    break;
            default:
                    printf("opcion invalida\n");
                    break;
        }
        /* code */
    } while (opcion!=7);
    
    free(grupo);

    return 1;
}

void menu(void)
{
    printf("Menu:\n");
    printf("1 Insertar alumno\n");
    printf("2 Sacar promedios\n");
    printf("3 Mostar alumnos\n");
    printf("4 Modificar alumno\n");
    printf("5 Guardar\n");
    printf("6 Leer\n");
    printf("7 Salir\n");
    printf("Opcion: ");
}
void lee(tipo_alumno lista[], int *alumnos_ingresados)
{
    printf("Nombre del alumno %d:",(*alumnos_ingresados)+1);
    fpurge(stdin);
    gets(lista[*alumnos_ingresados].nombre);
    printf("cal 1 de %s: ",lista[*alumnos_ingresados].nombre);
    fpurge(stdin);
    scanf("%f",&lista[*alumnos_ingresados].cal1);
    printf("cal 2: ");
    fpurge(stdin);
    scanf("%f",&lista[*alumnos_ingresados].cal2);
    fpurge(stdin);
    printf("cal 3: ");
    scanf("%f",&lista[*alumnos_ingresados].cal3);
    *alumnos_ingresados = (*alumnos_ingresados)+1;
}

void sacaprom(tipo_alumno lista[], int alumnos_ingresados)
{
    int i;

    for(i=0;i<alumnos_ingresados;i++)
        lista[i].prom=(lista[i].cal1+lista[i].cal2+lista[i].cal3)/3;

}

void imprime(tipo_alumno lista[], int alumnos_ingresados)
{
    int i;

    for(i=0;i<alumnos_ingresados;i++)
        printf("%s: %.2f, %.2f, %.2f = %.2f\n",lista[i].nombre,lista[i].cal1,lista[i].cal2,lista[i].cal3,lista[i].prom);

}

void guarda_archivo(tipo_alumno lista[], int alumnos_ingresados)
{
    int i;
    char nombre_arch[50];
    FILE *archivo;

    printf("Dame el nombre del archivo donde quieres guardar la info:\n");
    fpurge(stdin);
    gets(nombre_arch);

    archivo=fopen(nombre_arch,"wt");

    for(i=0; i<alumnos_ingresados; i++)
    {
        fprintf(archivo,"%s\n",lista[i].nombre);
        fprintf(archivo,"%f\n",lista[i].cal1);
        fprintf(archivo,"%f\n",lista[i].cal2);
        fprintf(archivo,"%f\n",lista[i].cal3);
        fprintf(archivo,"%f\n",lista[i].prom);
    }
    fclose(archivo);
}

void lee_archivo(tipo_alumno lista[],int * alumnos_ingresados)
{
    int i=0;
    char nombre_arch[50];
    FILE *archivo;

    printf("Dame el nombre del archivo de donde quieres leer la info:\n");
    fpurge(stdin);
    gets(nombre_arch);

    archivo=fopen(nombre_arch,"rt");
    if (archivo!=NULL)
    {
        while(!feof(archivo))
        {
            fgets(lista[i].nombre,48,archivo);
            lista[i].nombre[strlen(lista[i].nombre)-1]='\0';
            fscanf(archivo,"%f\n",&lista[i].cal1);
            fscanf(archivo,"%f\n",&lista[i].cal2);
            fscanf(archivo,"%f\n",&lista[i].cal3);
            fscanf(archivo,"%f\n",&lista[i].prom);
            i++;
        }
        *alumnos_ingresados=i;
        fclose(archivo);
    }
    else
        printf("ese nombre de archivo no existe.\n");

}

void modifica(tipo_alumno lista[], int alumnos_ingresados)
{
    int i=0;
    char nombre[50];

    printf("a quien quieres modificar? ");
    fpurge(stdin);
    gets(nombre);

    while((strcmp(nombre,lista[i].nombre)!=0)&&(i<alumnos_ingresados))
        i++;

    if(i<alumnos_ingresados)
    {
        printf("cal 1 de %s: ",lista[i].nombre);
        fpurge(stdin);
        scanf("%f",&lista[i].cal1);
        printf("cal 2: ");
        fpurge(stdin);
        scanf("%f",&lista[i].cal2);
        fpurge(stdin);
        printf("cal 3: ");
        scanf("%f",&lista[i].cal3);
    }
    else
        printf("el alunno no esta en la lista\n");
    
}
