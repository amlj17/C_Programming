//
//  registros y lectura.c
//  
//
//  Created by Andres Moguel on 5/9/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXIMO 100

typedef struct client
{
  char nombre[30];
  char apellidoP[30];
  char apellidoM[30];
  int id;
  int tel;
  char correo[50];
  int estatus;
  struct client *sig;
  
}cliente;

typedef struct dog
{
    char nombre[30];
    char tamano[30];
    int estatus;
    int idc;
    int idp;
  struct dog *sig;
}perro;

typedef struct cita
{
    int tel
    char nombrePerro //id
    char tamanio
    int diaIni;
    int mesIni;
    int amioIni
    int diaFin
    int mesFin
    int anioFin
}

void inserta_cli(cliente **inicio, char *nombre, char *aPat, char *aMat, int id, int tel, char *correo, int estatus);
void inserta_perro(perro **inicio, char *nombre, char *tamano, int stat, int idcli, int idperro);
void BorrarPerr(perro **inicio);
void BorrarCli(cliente **inicio);
void Leer_Cliente(cliente **inicio);
void Leer_Perro(perro **inicio);
void guarda_perro(perro *inicio);

int main(void){
    cliente *primero = NULL;
    perro *inicio = NULL;
}


void inserta_cli(cliente **inicio, char *nombre, char *aPat, char *aMat, int id, int tel, char *correo, int estatus){
    cliente *temp, *temp2;
    
    temp=(cliente*)malloc(sizeof(cliente));
    strcpy(temp->nombre, nombre);
    strcpy(temp->apellidoP, aPat);
    strcpy(temp->apellidoM, aMat);
    temp->id= id;   //HAY QUE AUTOMATIZAR ID
    temp->tel =tel;
    strcpy(temp->correo, correo);
    temp->estatus=estatus;
    temp->sig=NULL;
    if(*inicio!=NULL){
        temp2=*inicio;
        while (temp2->sig!=NULL) {
            temp2=temp2->sig;
        }
        temp2->sig=temp;
    }
    else
        (*inicio)=temp;
}

void inserta_perro(perro **inicio, char *nombre, char *tamano, int stat, int idcli, int idperro){
    perro *temp, *temp2;
    
    temp=(perro*)malloc(sizeof(perro));
    strcpy(temp->nombre, nombre);
    strcpy(temp->tamano, tamano);;
    temp->estatus=stat;
    temp->idc=idcli;
    temp->idp=idperro; //HAY QUE AUTOMATIZAR ID
    temp->sig=NULL;
    if(*inicio!=NULL){
        temp2=*inicio;
        while (temp2->sig!=NULL) {
            temp2=temp2->sig;
        }
        temp2->sig=temp;
    }
    else
        (*inicio)=temp;
}


void BorrarPerr(perro **inicio){
    perro *temp;
    
    while (*inicio!=NULL) {
        temp=*inicio;
        *inicio=(*inicio)->sig;
        free(temp);
    }
}


void BorrarCli(cliente **inicio){
    cliente *temp;
    
    while (*inicio!=NULL) {
        temp=*inicio;
        *inicio=(*inicio)->sig;
        free(temp);
    }
}


void Leer_Cliente(cliente **inicio)
{
  FILE *Archi;
  char nombre[MAXIMO];
  char aPat[MAXIMO];
  char aMat[MAXIMO];
  int id;
  int tel;
  char correo[MAXIMO];
    int estatus;
    
  Archi = fopen("clientes.dat", "rt");
  while(fgets(nombre, MAXIMO+2, Archi) != NULL)
    {
      nombre[strlen(nombre)-1] = 0;
      fgets(aPat, MAXIMO+2, Archi);
      aPat[strlen(aPat)-1] = 0;
    fgets(aMat, MAXIMO+2, Archi);
    aMat[strlen(aMat)-1] = 0;
      fscanf(Archi, "%d\n", &id);
    fscanf(Archi, "%d\n", &tel);
    fgets(correo, MAXIMO+2, Archi);
    correo[strlen(correo)-1] = 0;
    fscanf(Archi, "%d\n", &estatus);
        inserta_cli(inicio, nombre, aPat, aMat, id, tel, correo, estatus);
    }
  fclose(Archi);
}


void Leer_Perro(perro **inicio){
    FILE *Archi;
    char nombre[MAXIMO];
    char tamano[MAXIMO];
    int estatus;
    int idcli;
    int idperro;
      
    Archi = fopen("perros.dat", "rt");
    while(fgets(nombre, MAXIMO+2, Archi) != NULL)
      {
        nombre[strlen(nombre)-1] = 0;
        fgets(tamano, MAXIMO+2, Archi);
        tamano[strlen(tamano)-1] = 0;
        fscanf(Archi, "%d\n", &estatus);
      fscanf(Archi, "%d\n", &idcli);
      fscanf(Archi, "%d\n", &idperro);
          inserta_perro(inicio, nombre, tamano, estatus, idcli, idperro);
      }
    fclose(Archi);
}



void guarda_perro(perro *inicio){
    perro *temp;
    FILE *archivo;
    
    archivo = fopen("perros.dat", "wt");
    temp=inicio;
    while (temp!=NULL) {
        fprintf(archivo, "%s\n", temp->nombre);
        fprintf(archivo, "%s\n", temp->tamano);
        fprintf(archivo, "%d\n", temp->estatus);
        fprintf(archivo, "%d\n", temp->idc);
        fprintf(archivo, "%d\n", temp->idc);
        temp=temp->sig;
    }
        fclose(archivo);
}


void guarda_cliente(cliente *inicio){
    cliente *temp;
    FILE *archivo;
    
    archivo = fopen("clientes.dat", "wt");
    temp=inicio;
    while (temp!=NULL) {
        fprintf(archivo, "%s\n", temp->nombre);
        fprintf(archivo, "%s\n", temp->apellidoP);
        fprintf(archivo, "%s\n", temp->apellidoM);
        fprintf(archivo, "%d\n", temp->id);
        fprintf(archivo, "%d\n", temp->tel);
        fprintf(archivo, "%s\n", temp->correo);
        fprintf(archivo, "%d\n", temp->estatus);
        temp=temp->sig;
    }
        fclose(archivo);
}
