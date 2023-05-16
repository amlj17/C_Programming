//
//  Practica1.c
//  
//
//  Created by Andres Moguel on 2/17/21.
//

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

//Funciones Prototipo
unsigned char ** Leer_Archivo_Binario(char NombreArchivo[100], int *Columnas, int *Filas);
void Negativo(unsigned char **Mat_Imagen, int Columnas, int Filas);
void Ecualizar(unsigned char **Mat_Imagen, int Columnas, int Filas);
void Agrandar(unsigned char **Mat_Imagen, int Columnas, int Filas);
void Reducir(unsigned char **Mat_Imagen, int Columnas, int Filas);
void menu(void);
void mostrar_instrucciones(void);

int main(void)
{
    char NombreArchivo[100];
    int Columnas =0;
    int Filas =0;
    int i;
    char m;
    unsigned char  **Mat_Imagen;
    int opcion;
  //Mensajes de bienvenida y creacion
    mostrar_instrucciones();
  
    Mat_Imagen = Leer_Archivo_Binario(NombreArchivo,&Columnas,&Filas);
    
    if(Mat_Imagen == 0){
        return 0;
    }
    
    do
       {
           menu();
           scanf("%d",&opcion);
           switch (opcion)
           {
               case 1: printf("Negativo de una imagen\n");
                   Negativo(Mat_Imagen,Columnas,Filas);
                       break;
               case 2: printf("Ecualizacion lineal de una imagen\n");
                   Ecualizar(Mat_Imagen,Columnas,Filas);
                       break;
               case 3: printf("Reduccion de una imagen\n");
                   Reducir(Mat_Imagen,Columnas,Filas);
                       break;
               case 4: printf("Ampliacion de una imagen\n");
                   Agrandar(Mat_Imagen,Columnas,Filas);
                       break;
               case 5: printf("Salir\n");
                   for (i=0;i<Filas;i++){
                       free(Mat_Imagen[i]);
                   }
                   free(Mat_Imagen);
                       break;
               default:
                       printf("opcion invalida\n");
                       break;
           }
       } while (opcion!=5);
    

}

void mostrar_instrucciones(void){
    //Mensajes de bienvenida y creacion
    system("clear");
    printf("\t\t Bienvenido\n");
    printf("\n---Programa elaborado por Andres Moguel Lopez Jensen---\n\n");
    printf("\n---Presiona la tecla Enter para desplegar informacion acerca del programa---\n");

    scanf("%c",&m);
    printf("\nEste programa le da la opcion al usuario de elegir una imagen y transformarla: sacando su negativa, ampliandola, reduciendola o ecualizandola de forma lineal.\n\n");
    system("clear");
}

void menu(void)
{
    printf("Menu:\n");
    printf("1 Negativo de una imagen\n");
    printf("2 Ecualizacion lineal de una imagen\n");
    printf("3 Reduccion de una imagen\n");
    printf("4 Ampliacion de una imagen\n");
    printf("5 Salir\n");
    printf("Opcion: ");
}

unsigned char ** Leer_Archivo(char NombreArchivo[100], int *Columnas, int *Filas){
    FILE *Archivo;
    unsigned char **Mat_Imagen;
    int i=0,j=0;

    printf("\nDame el nombre de tu archivo en donde se encuentra la imagen: ");
    gets(NombreArchivo);
    Archivo = fopen (NombreArchivo,"rt");
  
    if(Archivo != NULL){
        fscanf(Archivo,"P5 %i %i 255 ",Columnas,Filas);
        //Creara las filas
        Mat_Imagen=(unsigned char**)malloc((*Filas)*sizeof(unsigned char*));
        //Creara las columnas
        for(i=0;i<*Filas;i++){
            (Mat_Imagen)[i]=(unsigned char*)malloc((*Columnas)*sizeof(unsigned char));
        }
        for(i=0;i<*Filas;i++){
            for(j=0;j<*Columnas;j++){
                fread(&Mat_Imagen[i][j], 1, 1, Archivo);
            }
        }
        fclose(Archivo);
     
    }
    else{
        printf("El archivo no existe \n");
        return 0;
    }
    return Mat_Imagen;
}
//Funcion la imagen la convierte a negativo
void Negativo(unsigned char **Mat_Imagen ,int Columnas, int Filas){
    unsigned char **Nueva;
    FILE *Archivo;
    char nombre[100];
    int i,j;
    Nueva=(unsigned char**)malloc((Filas)*sizeof(unsigned char*));
    for(i=0;i<Filas;i++){
        (Nueva)[i]=(unsigned char*)malloc((Columnas)*sizeof(unsigned char));
    }
        
  for(int i=0;i<Filas;i++){
      for(int j=0;j<Columnas;j++){
          Nueva[i][j]=(255-Mat_Imagen[i][j]);
      }
  }
    
    system("clear");
    printf("\nDame el nombre de tu archivo con la imagen en Negativo (agregra extension)\n");
    fpurge(stdin);
    gets(nombre);
    
    Archivo = fopen (nombre,"wt");
    fprintf(Archivo,"P5 %i %i 255 ",Columnas,Filas);
    fclose(Archivo);
    Archivo = fopen (nombre,"at");
       
    for(i=0;i<Filas;i++){
        for(j=0;j<Columnas;j++){
            fprintf(Archivo, "%c" ,Nueva[i][j]);
        }
    }
    fclose(Archivo);
    
    for (i=0;i<Filas;i++){
        free(Nueva[i]);
    }
    free(Nueva);
    printf("La imagen se ha guardado correctamente\n");
    system("clear");
}

//Funcion la imagen la Ecualiza
void Ecualizar(unsigned char **Mat_Imagen, int Columnas, int Filas){
    unsigned char **Nueva;
    FILE *Archivo;
    char nombre[100];
    float Maximo=0;
    float Minimo=255;
    float pendiente;
    int i,j;

    Nueva=(unsigned char**)malloc((Filas)*sizeof(unsigned char*));
    for(i=0;i<Filas;i++){
        (Nueva)[i]=(unsigned char*)malloc((Columnas)*sizeof(unsigned char));
    }
    //encontramos maximos y minimos
    for(i=0;i<Filas;i++){
        for(j=0;j<Columnas;j++){
            if(Mat_Imagen[i][j]>Maximo){
                Maximo = Mat_Imagen[i][j];
            }
            if(Mat_Imagen[i][j]<Minimo){
                Minimo = Mat_Imagen[i][j];
            }
        }
    }
    //encontramos la pendiente
    pendiente=((255-0)/(Maximo-Minimo));
    //ecualizamos la imagen
    for(i=0;i<Filas;i++){
        for(j=0;j<Columnas;j++){
            Nueva[i][j]=((pendiente*Mat_Imagen[i][j])-(pendiente*Maximo));
        }
    }
    
    system("clear");
    printf("\nDame el nombre del archivo que contenga la imagen Ecualizada (agregra extension)\n");
    fpurge(stdin);
    gets(nombre);
      
    Archivo = fopen (nombre,"wt");
    fprintf(Archivo,"P5 %i %i 255 ",Columnas,Filas);
    fclose(Archivo);
    Archivo = fopen (nombre,"at");
         
    for(i=0;i<Filas;i++){
        for(j=0;j<Columnas;j++){
            fprintf(Archivo, "%c" ,Nueva[i][j]);
        }
    }
         
    fclose(Archivo);
      
    for (i=0;i<Filas;i++){ //ELIMINAR MATRIZ{
        free(Nueva[i]);
    }
    free(Nueva);
    printf("La imagen se ha guardado correctamente\n");
    system("clear");
}

//Funcion reduce el tamanio a la imagen
void Reducir(unsigned char **Mat_Imagen, int Columnas, int Filas){
    unsigned char **Nueva;
    FILE *Archivo;
    char nombre[100];
    int i,j;
    int col_Nueva,fil_Nueva;
    int m=0,n=0;
    
    if(Filas%2==0){
        fil_Nueva=Filas/2;
    }
    else{
        fil_Nueva=(Filas/2)+1;
    }
    
    if(Columnas%2==0){
        col_Nueva=Columnas/2;
    }
    else{
        col_Nueva=(Columnas/2)+1;
    }
    
    Nueva=(unsigned char**)malloc((fil_Nueva)*sizeof(unsigned char*));
    for(i=0;i<fil_Nueva;i++){
        (Nueva)[i]=(unsigned char*)malloc((col_Nueva)*sizeof(unsigned char));
    }
    
    for(i=0;i<fil_Nueva;i++){
        for(j=0;j<col_Nueva;j++){
            Nueva[i][j]=Mat_Imagen[n][m];
            m+=2;
        }
        m=0;
        n+=2;
    }
     
    system("clear");
    printf("\nDame el nombre de tu archivo que contenga la imagen Reducida (agregra extension)\n");
    fpurge(stdin);
    gets(nombre);
      
    Archivo = fopen (nombre,"wt");
    fprintf(Archivo,"P5 %i %i 255 ",col_Nueva,fil_Nueva);
    fclose(Archivo);
    Archivo = fopen (nombre,"at");
         
    for(i=0;i<fil_Nueva;i++){
        for(j=0;j<col_Nueva;j++){
            fwrite(&Nueva[i][j],1,1,Archivo);
        }
    }
    fclose(Archivo);
      
  for (i=0;i<fil_Nueva;i++){
      free(Nueva[i]);
    }
    free(Nueva);

    printf("La imagen se ha guardado correctamente\n");
    system("clear");
    return;
}

//Funcion Agranda el tamanio a la imagen
void Agrandar(unsigned char **Mat_Imagen, int Columnas, int Filas){
    FILE *Archivo;
    char nombre[100];
    int col_Nueva, fil_Nueva;
    int i;
    int j=0;
    int k=0;
    int h=0;
    unsigned char **Nueva;

    fil_Nueva = Filas*2;
    col_Nueva = Columnas*2;
  
    Nueva=(unsigned char**)malloc((fil_Nueva)*sizeof(unsigned char*));
    for(i=0;i<fil_Nueva;i++){
        Nueva[i]=(unsigned char*)malloc((col_Nueva)*sizeof(unsigned char));
    }
    for(i=0;i<Filas;i++){
        for(k=0;k<Columnas;k++){
            Nueva[j][h]=Mat_Imagen[i][k];
            Nueva[j+1][h]=Mat_Imagen[i][k];
            h++;
            Nueva[j][h]=Mat_Imagen[i][k];
            Nueva[j+1][h]=Mat_Imagen[i][k];
            h++;
    }
        h=0;
        j+=2;
         
    }
    system("clear");
    fpurge(stdin);
    printf("\nDame el nombre de tu archivo que contenga la imagen Agrandada(agregra extension)\n");
    gets(nombre);
      
    Archivo = fopen (nombre,"wt");
    fprintf(Archivo,"P5 %i %i 255 ",col_Nueva,fil_Nueva);
    fclose(Archivo);
    Archivo = fopen (nombre,"at");
         
    for(i=0;i<fil_Nueva;i++){
        for(j=0;j<col_Nueva;j++){
            fwrite(&Nueva[i][j],1,1,Archivo);
        }
    }
    fclose(Archivo);

  for (i=0;i<fil_Nueva;i++){
      free(Nueva[i]);
    }
    free(Nueva);
    printf("La imagen se ha guardado correctamente\n");
    system("clear");
  
}
