//Andres Moguel

/*
Notas:
Al leer archivo marca segmentation, cierras 2 veces el archivo

1.Introducir coordenada. (1.5 de 1.5 punto)
2.Listar coordenadas. (1.5 de 1.5 punto)
3.Eliminar coordenada. (2 de 2 puntos)
4.Guardar coordenadas en archivo (2 de 2 puntos)
5.Leer coordenadas de archivo (1.5 2 puntos)
6.Salir. (1 de 1 punto)

Cal: 9.5

*/

#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <stdio_ext.h>

typedef struct def_coordenada
{
  int hora;
  int minuto;
  float longitud;
  float latitud;
  struct def_coordenada *sig;
}tipo_coordenada;

void insertar_coord(tipo_coordenada **inicio, int hr, int min, float lat, float lgt);
void listar_coord(tipo_coordenada *inicio);
int eliminar_coord(tipo_coordenada **inicio, int hr, int min, float lat, float lgt);
void guardar(tipo_coordenada *inicio);
void leer(tipo_coordenada **inicio);
void Borrar(tipo_coordenada **inicio);
void menu(void);

int main(void){
  tipo_coordenada *primero= NULL;
  int hora, minuto, opcion;
  float latitud, longitud;

  do
  {
    menu();
    scanf("%d", &opcion);
    switch(opcion){
    case 1:
      printf("Ingrese la hora en en el formato hh:mm\n");
      printf("Ingrese la hora:");
      scanf("%d", &hora);
      __fpurge(stdin);
      while(hora<0 || hora > 24){
	printf("Error hora invalida debe estar entre 1 y 24\n");
	printf("Ingrese hora: ");
	scanf("%d", &hora);
	__fpurge(stdin);
      }
      printf("Ingrese los minutos: ");
      scanf("%d", &minuto);
      __fpurge(stdin);
       while(minuto<0 || minuto > 60){
	printf("Error minuto invalida debe estar entre 0  y 60\n");
	printf("Ingrese minuto: ");
	scanf("%d", &minuto);
	__fpurge(stdin);
      }
      printf("Ingrese la latitud: ");
      scanf("%f", &latitud);
      __fpurge(stdin);
      while(latitud<(-90) || latitud > 90){
	printf("Error latitud invalida debe estar entre -90 y 90\n");
	printf("Ingrese latitud: ");
	scanf("%f", &latitud);
	__fpurge(stdin);
      }
      printf("Ingrese la longitud: ");
      scanf("%f", &longitud);
      __fpurge(stdin);
      while(longitud<(-180) || longitud>180){
	printf("Error longitud invalida debe estar entre -180 y 180\n");
	printf("Ingrese la longitud: ");
	scanf("%f", &longitud);
	__fpurge(stdin);
      }
      insertar_coord(&primero, hora, minuto, latitud, longitud);
      break;
    case 2:
      listar_coord(primero);
      break;
    case 3:
      printf("Dame la hora de la coordenada a eliminar: ");
      scanf("%d", &hora);
      __fpurge(stdin);
      printf("Dame el minuto de la coordenada a eliminar: ");
      scanf("%d", &minuto);
      __fpurge(stdin);
      if(eliminar_coord(&primero, hora, minuto, latitud, longitud)==1){
	  printf("La coordenada no se encuentra en la lista\n");
	}
	else
	  printf("fue eliminado exitosamente\n");
	break;
	case 4:
	   guardar(primero);
	break;
        case 5:
           leer(&primero);
        break;

    }
  }while(opcion!=6);
    Borrar(&primero);

}
  void menu(void){
        printf("Menu:\n");
        printf("1 Insertar coordenada \n");
        printf("2 Mostrar lista de coordenadas\n");
        printf("3 Eliminar coordenada\n");
        printf("4 Guardar\n");
        printf("5 Leer\n");
        printf("6 Salir\n");
        printf("Opcion: ");
}


  void insertar_coord(tipo_coordenada **inicio, int hr, int min, float lat, float lgt){
    tipo_coordenada *temp, *temp2;

    temp=(tipo_coordenada*)malloc(sizeof(tipo_coordenada));
    temp->hora=hr;
    temp->minuto=min;
    temp->latitud=lat;
    temp->longitud=lgt;
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

  
  void listar_coord(tipo_coordenada *inicio){
    tipo_coordenada *temp;
    
    temp = inicio;
    while (temp!=NULL) {
        printf("Hora: %d:%d   Latitud: %.2f   Longitud: %.2f\n", temp->hora, temp->minuto, temp->latitud, temp->longitud);
        temp=temp ->sig;
    }
  }

  
  int eliminar_coord(tipo_coordenada **inicio, int hr, int min, float lat, float lgt){
    tipo_coordenada *temp, *anterior;

    temp=*inicio;

    while((temp!=NULL)&&((temp->hora!=hr)&&(temp->minuto!=min))){
	  temp = temp->sig;
      }
    if(temp!=NULL){
      if(temp!=*inicio){
	anterior=*inicio;
	while(anterior->sig!=temp)
	  anterior=anterior->sig;
	anterior->sig=temp->sig;
	free(temp);
      }
      else{
	*inicio=(*inicio)->sig;
	free(temp);
      }
      return 0;
      }
    else return 1;
  }

  
  void guardar(tipo_coordenada *inicio){
    tipo_coordenada *temp;
    FILE *archivo;
    char nombrearch[50];

    printf("Dame el nombre del archivo donde desead guardar: ");
    __fpurge(stdin);
    gets(nombrearch);

    archivo=fopen(nombrearch, "wt");
    temp=inicio;
    while (temp!=NULL) {
       fprintf(archivo, "%d\n", temp->hora);
       fprintf(archivo, "%d\n", temp->minuto);
       fprintf(archivo, "%.2f\n", temp->latitud);
       fprintf(archivo, "%.2f\n", temp->longitud);
       
       temp=temp->sig;
    }
        fclose(archivo);
  }

  
  void leer(tipo_coordenada **inicio){
    FILE *archivo;
    char nombrearchivo[50];
    int hora, minuto;
    float latitud, longitud;

    printf("ingrese el nombre del archivo que desea leer: ");
    __fpurge(stdin);
    gets(nombrearchivo);
    archivo=fopen(nombrearchivo, "rt");
    if(archivo!=NULL){
      while(fscanf(archivo, "%d\n", &hora)==1)
	insertar_coord(inicio, hora, minuto, latitud, longitud);
      fclose(archivo);
    }
    else
      printf("EL archivo ingresado no existe");
    fclose(archivo);
  }

  
  void Borrar(tipo_coordenada **inicio){
    tipo_coordenada *temp;
    
    while (*inicio!=NULL) {
        temp=*inicio;
        *inicio=(*inicio)->sig;
        free(temp);
    }
  }
