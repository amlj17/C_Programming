//
//  alumnos con archivos binarios.c
//
//
//  Created by Andres Moguel on 2/4/21.
//

#include<stdio.h>
#include<string.h>

typedef struct def_alumno
{
    char nombre[50];
    float cal1,cal2,cal3,prom;
}tipo_alumno;

void lee(tipo_alumno lista[],int *posicion);
void sacaprom(tipo_alumno lista[],int posicion);
void imprime(tipo_alumno lista[],int posicion);
void menu(void);
void lee_archivo(tipo_alumno lista[],int *posicion);
void guarda_archivo(tipo_alumno lista[],int posicion);
void modifica(tipo_alumno lista[], int posicion);

int main(void)
{
    tipo_alumno grupo[10];
    int opcion, posicion;
    //posicion indica la cantidad de personas en el grupo (el valor maximo puede llegar a ser 10)

    posicion=0;
    do
    {
        menu();
        scanf("%d",&opcion);
        switch (opcion)
        {
            case 1: if(posicion<10)
                        lee(grupo,&posicion);
                    else
                        printf("ya no puede insertar mas posicion\n");
                    break;
            case 2: sacaprom(grupo,posicion);
                    break;
            case 3: imprime(grupo,posicion);
                    break;
            case 4: modifica(grupo,posicion);
                    break;
            case 5: guarda_archivo(grupo,posicion);
                    break;
            case 6: lee_archivo(grupo,&posicion);
                    break;
            case 7: printf("Adios\n");
                    break;
            default:
                    printf("opcion invalida\n");
                    break;
        }
        /* code */
    } while (opcion!=7);

    return 1;
}

void menu(void)
{
    printf("Menu:\n");
    printf("1 Insertar alumno\n");
    printf("2 Sacar promedios\n");
    printf("3 Mostar posicion\n");
    printf("4 Modificar alumno\n");
    printf("5 Guardar\n");
    printf("6 Leer\n");
    printf("7 Salir\n");
    printf("Opcion: ");
}
void lee(tipo_alumno lista[], int *posicion)
{
    printf("Nombre del alumno %d:",(*posicion)+1);
    fpurge(stdin);
    gets(lista[*posicion].nombre);
    printf("cal 1 de %s: ",lista[*posicion].nombre);
    fpurge(stdin);
    scanf("%f",&lista[*posicion].cal1);
    printf("cal 2: ");
    fpurge(stdin);
    scanf("%f",&lista[*posicion].cal2);
    fpurge(stdin);
    printf("cal 3: ");
    scanf("%f",&lista[*posicion].cal3);
    *posicion = (*posicion)+1;
}

void sacaprom(tipo_alumno lista[], int posicion)
{
    int i;

    for(i=0;i<posicion;i++)
        lista[i].prom=(lista[i].cal1+lista[i].cal2+lista[i].cal3)/3;

}

void imprime(tipo_alumno lista[], int posicion)
{
    int i;

    for(i=0;i<posicion;i++)
        printf("%s: %.2f, %.2f, %.2f = %.2f\n",lista[i].nombre,lista[i].cal1,lista[i].cal2,lista[i].cal3,lista[i].prom);

}

void guarda_archivo(tipo_alumno lista[], int posicion)
{
    char nombre_arch[50];
    FILE *archivo;

    printf("Dame el nombre del archivo donde quieres guardar la info:\n");
    fpurge(stdin);
    gets(nombre_arch);
    archivo=fopen(nombre_arch,"wb");
    fwrite(lista,sizeof(tipo_alumno), posicion, archivo);
    fclose(archivo);
}

void lee_archivo(tipo_alumno lista[],int * posicion)
{
    char nombre_arch[50];
    long int tamanobytes;
    FILE *archivo;

    printf("Dame el nombre del archivo de donde quieres leer la info:\n");
    fpurge(stdin);
    gets(nombre_arch);

    archivo=fopen(nombre_arch,"rb");
    if (archivo!=NULL)
    {
        *posicion = 0;
        fseek(archivo, 0L, SEEK_END);
        tamanobytes = ftell(archivo);
        tamanobytes = tamanobytes/sizeof(tipo_alumno);
        fseek(archivo, 0L, SEEK_SET);
        if (tamanobytes<=10){
            fread(lista, sizeof(tipo_alumno), tamanobytes, archivo);
        }
        *posicion = tamanobytes;
        fclose(archivo);
    }
    else
        printf("ese nombre de archivo no existe.\n");

}

void modifica(tipo_alumno lista[], int posicion)
{
    int i=0;
    char nombre[50];

    printf("a quien quieres modificar? ");
    fpurge(stdin);
    gets(nombre);

    while((strcmp(nombre,lista[i].nombre)!=0)&&(i<posicion))
        i++;

    if(i<posicion)
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
