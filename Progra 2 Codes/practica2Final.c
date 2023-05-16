//practica 2 final
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
typedef struct def_arbol
{
  char simbolo;
  float proba;
  struct def_arbol *izq, *der;
}tipo_arbol;

// Estructura para crear una fila de nodos de tipo_arbol
typedef struct def_fila
{
  int size, frente, fin;
  tipo_arbol **lista;
}tipo_fila;

typedef struct Arbol
{
    char caracter;
    float proba;
    struct Arbol *sig,*der,*izq;
}tipoarbol;

typedef struct def_datos
{
    char carac;
    float probabilidad;
    struct def_datos *sig;
}tipodato;

typedef struct codigos
{
    char caracter;
    char codigo[MAX];
    struct codigos *sig;
}tipocodigo;



void Insertar(tipoarbol **Inicio,tipocodigo **start, tipodato **diccionario);
void IngresarSimboloMas(tipocodigo **Inicio,char caracter); //
void Sumas_Probas(tipoarbol **Inicio,float probabilidad,char caracter,tipocodigo **start); //
void Listar(tipodato *inicio);
int comprobar_Probabilidades(tipodato *inicio);
void borrarLista(tipoarbol **inicio);
void borrarCodigos(tipocodigo **inicio);
void borrarDiccionarios(tipodato **inicio);
void Eliminar(tipoarbol **Inicio,tipocodigo **start, tipodato **diccionario);
void EliminarAux(tipocodigo **Inicio, char caracter);
void modificar(tipoarbol *Inicio,tipocodigo *start, tipodato *diccionario);
void ModificarAux(tipocodigo *start,char caraN,char cara);
void menu(void);
void mostrar_instrucciones(void);
void Agregar_Fila(tipo_fila *fila, tipo_arbol *aux);
tipo_arbol *Encontrar_Min(tipo_fila *fila1, tipo_fila *fila2);
tipo_arbol *Obtener_Nodo(tipo_fila *fila);
void Crear_Arbol(tipodato *inicio, tipo_arbol **raiz);
void Crear_Codigos(tipo_arbol *raiz, char *codigo, int *size, tipocodigo Codigos[MAX]);
void Borrar_Arbol(tipo_arbol *raiz);
void imprimirArbol(tipo_arbol *p);
void Ingresar_Simbolo(tipodato **inicio, char simbolo, float proba);
void NombreArchivo(char *Archivo);
void Codificar(tipocodigo Codigos[MAX], int size);
void Decodificar(tipo_arbol *raiz);
void guarda(tipodato *inicio);
void Leer_Archivo(tipodato **inicio, char *Archivo);



int main(void)
{
   tipoarbol *inicio=NULL;
   tipocodigo *start=NULL;
   tipoarbol *raiz=NULL;
    tipodato *primero = NULL;
    tipo_arbol *raiz2 = NULL; // Raiz del arbol
    
    int opcion=0;
    int libre=0;
    int size = 0;
    char codigo[MAX], Archivo[MAX];
    tipocodigo Codigos[MAX]; // Arreglo de codigos

    mostrar_instrucciones();
    while(opcion!=10)
    {
        system("clear");
        menu();
        __fpurge(stdin);
        scanf("%i",&opcion);
        switch(opcion)
        {
            case 1:

           if(libre!=1)
        {
          Insertar(&inicio,&start, &primero);
        }
        else
          {
            system("clear");
        printf("\nNo se pueden insertar  simbolos con el arbol ya creado\n");
         printf("\nEnter para volver a menu\n");
                    __fpurge(stdin);
                    getchar();
          }

        break;

        
    case 2: Listar(primero);
        break;

    case 3:
      if(libre!=1)
        {
          Eliminar(&inicio,&start, &primero);
        }
        else
          {
            system("clear");
        printf("\nNo se pueden eliminar simbolos con el arbol ya creado\n");
         printf("\nEnter para volver a menu\n");
                    __fpurge(stdin);
                    getchar();
          }

        break;

    case 4:
      
       if(libre!=1)
        {
           modificar(inicio,start, primero);
        }
        else
          {
        
        system("clear");
                   printf("\nNo se pueden modificar simbolos con el arbol ya creado\n");
                    printf("\nEnter para volver a menu\n");
                    __fpurge(stdin);
                    getchar();
          }

        break;

      
      
    case 5:
           guarda(primero);
                break;
                
    case 6:
                printf("Ingrese el nombre del archivo de donde desea leer los simbolos.\n\n");
                NombreArchivo(Archivo);
                Leer_Archivo(&primero, Archivo);
                break;
                
    case 7:
                if(libre == 0 && (comprobar_Probabilidades(primero)==1))
                       {
                         if(raiz2 != NULL)
                       {
                         Borrar_Arbol(raiz2);
                         raiz2 = NULL;
                       }
                         Crear_Arbol(primero, &raiz2);
                         if(raiz2 == NULL)
                       printf("No se pudieron generar los codigos. Verifique sus datos e intente otra vez.\n");
                         else
                       {
                         Crear_Codigos(raiz2, codigo, &size, Codigos);
                       }
                           //imprimirArbol(raiz2);
                           for (int j=0; j<size; j++)
                           {
                             printf("%c = %s\n",Codigos[j].caracter ,Codigos[j].codigo);
                           }
                           libre=1;
                           system("clear");
                                printf("\ncodigos generados existosamente\n");
                                printf("\nEnter para volver a menu\n");
                                __fpurge(stdin);
                                getchar();
                       }
                     else
                     {
                         system("clear");
                         printf("\nRevise que tenga 2+ simbolos o estos ya fueron generados\n");
                         printf("\nEnter para volver a menu\n");
                         __fpurge(stdin);
                         getchar();
                     }
                break;
                
            case 8:
                    if(libre==1)
                    {
                        Codificar(Codigos, size);
                        system("clear");
                        
                    }
                    else
                    {
                        system("clear");
                        printf("\nPrimero  debe generar los codigos\n");
                        printf("\nEnter para volver a menu\n");
                        __fpurge(stdin);
                        getchar();
                        
                    }
                        
                        break;
                
            case 9:
                    
                    
                    if(libre==1)
                    {
                        Decodificar(raiz2);
                        system("clear");
                        
                    }
                    else
                    {
                        system("clear");
                        printf("\nPrimero debe generar los codigos\n");
                        printf("\nEnter para volver a menu\n");
                        __fpurge(stdin);
                        getchar();
                        
                    }
                    break;
                
            case 10:
                borrarLista(&inicio);
                borrarCodigos(&start);
                borrarDiccionarios(&primero);
                Borrar_Arbol(raiz2);
                break;
                
        }
    }
    
    
}

//funcion Menu
void menu(void)
{
    printf("Menu:\n");
    printf("1.- Ingresar símbolo al diccionario\n");
    printf("2.- Listar símbolos introducidos\n");
    printf("3.- Eliminar símbolo\n");
    printf("4.- Modificar símbolo \n");
    printf("5.- Guardar diccionario\n");
    printf("6.- Cargar diccionario\n");
    printf("7.- Generar códigos\n");
    printf("8.- Codificar mensaje\n");
    printf("9.- Decodificar mensaje\n");
    printf("10.- salir\n");
    printf("Opcion: ");
}

//funcion mostrar instrucciones
void mostrar_instrucciones(void){
    system("clear");
    printf("\nBienvenido\n");
    printf("Programa elaborado por:\n");
    printf("Rodrigo Garcia Gorostizaga\n");
    printf("Mariana Morfin Marquez\n");
    printf("Andres Moguel Lopez Jensen\n");
    printf("Presione <ENTER> para ver una descripcion del programa\n");
    getchar();
    system("clear");
    printf("\nEste programa..... \n");
    printf("Presione <ENTER> comenzar a usar el programa\n");
    getchar();
    system("clear");
}

//funcion para insertar
void Insertar(tipoarbol **Inicio,tipocodigo **start, tipodato **diccionario)
{
    tipoarbol *Temp,*Temp2,*Temp3;
    tipodato *aux, *aux1, *aux2;
    float proba;
    char caracter;
    
    Temp=(tipoarbol*)malloc(sizeof(tipoarbol));
    aux=(tipodato*)malloc(sizeof(tipodato));

      system("clear");

    do{
      printf(" Ingrese el caracter\n[+ es un caracter reservado]\n");
      __fpurge(stdin);
      scanf("%c",&caracter);
    }while(caracter=='+');
    
     IngresarSimboloMas(start,caracter);
    
    do{
        
      printf("Cual es su probabilidad? en rango [0,100]\n");
      __fpurge(stdin);
      scanf("%f",&proba);
        
    }while((proba<0)||(proba>100));
    
    aux->carac = caracter;
    aux->probabilidad = proba;
    aux->sig = NULL;
    aux1= *diccionario;
    while((aux1 != NULL) && (aux1->probabilidad < proba))
      {
        aux2= aux1;
        aux1= aux1->sig;
      }
    if(*diccionario == aux1)
      *diccionario = aux;
    else
      aux2->sig = aux;
    aux->sig = aux1;
    
    
    Temp->proba=proba;
    Temp->caracter=caracter;
    
    Temp->sig=NULL;
    Temp->izq=NULL;
    Temp->der=NULL;

    if(*Inicio==NULL)
    {
       *Inicio=Temp;
        return;
    }
    
    Temp2=*Inicio;
    
    while(Temp2!=NULL)
    {
        if((Temp2->proba)>proba)
        {
            break;
        }
       
        Temp2=Temp2->sig;
    }
    
    
    if(Temp2!=*Inicio)
    {
    
     Temp3=*Inicio;
    
     while(Temp3->sig!=Temp2)
     {
        Temp3=Temp3->sig;
        
     }
    
     Temp3->sig=Temp;
     Temp->sig=Temp2;
    }
    else
    {
        *Inicio=Temp;
        (*Inicio)->sig=Temp2;
        
    }
    
    return;
}


//Funcion para imprimir diccionarios, listarlos
void Listar(tipodato *inicio)
{
    tipodato *temp;
    temp = inicio;
    system("clear");
    printf("\nLista:\n");
    
     if(temp == NULL)
    {
      printf("No hay nada ingresado en el diccionario\n ");
      printf("Cargue un archivo o ingrese manualmente\n");
    }
    
    while(temp!=NULL)
    {
        printf("Caracter: %c con Probabilidad: %f \n",temp->carac,temp->probabilidad);
        temp=temp->sig;
        
    }
    
    printf("\nEnter para volver a menu\n");
    __fpurge(stdin);
    getchar();
    return;
    
}


//funcion que comprueba
//probabilidades suman a 100
//sin caracteres repetidos
int comprobar_Probabilidades(tipodato *inicio)
{

   float cuenta=0;
   tipodato *temp, *temp2;
    temp = inicio;

    while(temp!=NULL)//recorrer arbol sumando probabilidades
    {
        cuenta+=temp->probabilidad;
        temp=temp->sig;
    }

    if(cuenta!=100)
    {
      printf("Las probabilidades no suman al 100 por ciento intente de nuevo");
         return 0;  //regresa 0 que significa que no sigue el programa
    }
    temp = inicio;
    while(temp != NULL)
      {
        temp2 = temp->sig;
        while(temp2 != NULL)
    {
      if(temp2->carac == temp->carac)
        {
          printf("Tiene repetido un simbolo, intente de nuevo.\n");
          return 0;
        }
        temp2 = temp2->sig;
      }
          temp = temp->sig;
        }
     if(cuenta==100)
     {
       printf("Datos validos \n");
         return 1; //regresa 1 que validamos en el main
     }
    return 0;
}

//funcion que suma probas
//ayuda en modificar y eliminar
//intento de arbol
void Sumas_Probas(tipoarbol **Inicio,float probabilidad,char caracter,tipocodigo **start)
{
    
    tipoarbol *Temp,*Temp2,*Temp3;
       
       Temp=(tipoarbol*)malloc(sizeof(tipoarbol));

       
       Temp->proba=probabilidad;
       Temp->caracter=caracter;

       if(caracter!='+')
     {
                IngresarSimboloMas(start,caracter);
     }

      Temp->sig=NULL;
       Temp->izq=NULL;
       Temp->der=NULL;
       
       if(*Inicio==NULL)
       {
          *Inicio=Temp;
           return;
       }
       
       Temp2=*Inicio;
       
       while(Temp2!=NULL)
       {
           if((Temp2->proba)>probabilidad)
           {
               break;
           }
           Temp2=Temp2->sig;
       }
       
       
       if(Temp2!=*Inicio)
       {
        Temp3=*Inicio;
       
        while(Temp3->sig!=Temp2)
        {
           Temp3=Temp3->sig;
        }
       
        Temp3->sig=Temp;
        Temp->sig=Temp2;
       }
       else
       {
           *Inicio=Temp;
           (*Inicio)->sig=Temp2;
       }
       return;
    
}

//inserta caracter + a nodos de sumas de probas
//primer intento de arbol
void IngresarSimboloMas(tipocodigo **Inicio,char caracter)
{
    tipocodigo *Temp,*Temp2;
    Temp=(tipocodigo*)malloc(sizeof(tipocodigo));

    
      
      Temp->caracter=caracter;
      Temp->codigo[0]='\0';
      
      
      Temp->sig=NULL;
      
      if(*Inicio == NULL)
      {
          *Inicio=Temp;
      }
      else
      {
          Temp2=*Inicio;
          
          while(Temp2->sig!=NULL)
          {
              Temp2=Temp2->sig;
              
          }
          Temp2->sig=Temp;
      }
      return;
}

//libera memoria del primer intento del arbol
void borrarLista(tipoarbol **inicio)
{
  tipoarbol *temp;
    
  while(*inicio!=NULL)
    {
      temp=*inicio;
      *inicio=(*inicio)->sig;
      free(temp);
        
    }
  return;
}

//libera de lista de codigos
void borrarCodigos(tipocodigo **inicio)
{
  tipocodigo *temp;
    
  while(*inicio!=NULL)
    {
      temp=*inicio;
      *inicio=(*inicio)->sig;
      free(temp);
        
    }
  return;
}


//primera parte de eliminar un elemento del diccionario
void Eliminar(tipoarbol **Inicio,tipocodigo **start, tipodato **diccionario)
{
   
  char cara;
   
  tipoarbol *temp,*temp2,*temp3;
    tipodato *aux, *anterior;
  temp=*Inicio;
    aux = *diccionario;
  system("clear");
  printf("Caracter a eliminar:  \n");
  __fpurge(stdin);
  scanf("%c",&cara);
    
    while ((aux!=NULL&& aux->carac!=cara))
        aux=aux->sig;
    if(aux!=NULL){
        if (aux!=*diccionario) {
            anterior=*diccionario;
            while(anterior->sig!=aux)
                anterior=anterior->sig;
            anterior->sig=aux->sig;
            free(aux);
        }
        else{
            *diccionario=(*diccionario)->sig;
            free(aux);
        }
    }
    
  while(temp!=NULL)
    {
      if(temp->caracter==cara)
        {
      break;
        }
      temp=temp->sig;
    }
    
  if(temp==NULL)
    {
      printf("\nNo se encontro el caracter %c en el diccionario\n",cara);
      printf("\nEnter para volver a menu\n");
      __fpurge(stdin);
      getchar();
      return;
    }
    
  temp3=temp->sig;
  EliminarAux(start,cara);
    
  if(temp==*Inicio)
    {
      *Inicio=temp3;
      free(temp);
      system("clear");
      printf("Se borro exitosamente\n");
      printf("\nEnter para volver a menu\n");
      __fpurge(stdin);
      getchar();
      return;
    }
    
  temp2=*Inicio;

  while(temp2->sig!=temp)
    {
      temp2=temp2->sig;
    }
    
  temp2->sig=temp3;
  free(temp);

  system("clear");
  printf("\nse borro exitosamente\n");
  printf("\nEnter para volver a menu\n");
  __fpurge(stdin);
  getchar();
  return;
}


//eliminar 2 segunda parte de eliminar
//ayuda a eliminar principal
void EliminarAux(tipocodigo **Inicio,char caracter)
{
    
  tipocodigo *temp,*temp2,*temp3;
  temp=*Inicio;
    
    
  while(temp!=NULL)
    {
      if(temp->caracter==caracter)
        {
      break;
        }
      temp=temp->sig;
    }
   
    
  temp3=temp->sig;
    
  if(temp==*Inicio)
    {
      *Inicio=temp3;
      free(temp);
      return;
    }
    
  temp2=*Inicio;

  while(temp2->sig!=temp)
    {
      temp2=temp2->sig;
    }
    
  temp2->sig=temp3;
  free(temp);
  return;
}

//Primera parte de modificar
//permite editar probas o caracteres
void modificar(tipoarbol *Inicio,tipocodigo *start, tipodato *diccionario)
{
  char cara;
  float proba;
  char caraN;
  tipoarbol *temp;
    tipodato *aux;
  int resp;
  temp=Inicio;
    aux=diccionario;
    
  system("clear");
  printf("Que caracter desea modificar?\n");
  __fpurge(stdin);
  scanf("%c",&cara);
    
    while (aux!=NULL) {
        if(aux->carac==cara)
            break;
        aux =aux->sig;
    }
    
  while(temp!=NULL)
    {
      if(temp->caracter==cara)
        {
      break;
            
        }
      temp=temp->sig;
    }
    
  if(temp==NULL)
    {
      system("clear");
      printf("\nNo se encontro el caracter %c\n",cara);
      printf("\nEnter para volver a menu\n");
      __fpurge(stdin);
      getchar();
      return;
    }


  printf("Que desea editar : caracter[1]  o probabilidad[2]\n");
  __fpurge(stdin);
  scanf("%i",&resp);
   
  if(resp==1)
    {
      printf("Cual es el nuevo caracter en vez de: %c\n",temp->caracter);
      __fpurge(stdin);
      scanf("%c",&caraN);
      temp->caracter=caraN;
        aux->carac=caraN;
      system("clear");

      ModificarAux(start,caraN,cara);
       
      printf("se modifico correctamente\n");
     
      printf("\nEnter para volver a menu\n");
      __fpurge(stdin);
      getchar();

      return;
    }

    
  if(resp==2)
    {
      do{
        
    printf("Cual es la nueva probabilidad? en rango [0,100]\n");
    __fpurge(stdin);
    scanf("%f",&proba);
        
      }while((proba<0)||(proba>100));

      
      temp->proba=proba;
        aux->probabilidad=proba;
      system("clear");
      printf("se modifico exitosamente\n");
      printf("\nEnter para volver a menu\n");
      __fpurge(stdin);
      getchar();
    
      return;
    }
  return;
}

//2da parte de modificar
//ayuda a modificar
void ModificarAux(tipocodigo *start,char caraN,char cara)
{
  tipocodigo *temp;
  temp=start;
    
  while(temp!=NULL)
    {
      if(temp->caracter==cara)
        {
      break;
        }
      temp=temp->sig;
    }
  temp->caracter=caraN;
  return;
}

//libera de lista dinamica de diccionarios
void borrarDiccionarios(tipodato **inicio){
    tipodato *temp;
    
    while (*inicio!=NULL) {
        temp=*inicio;
        *inicio=(*inicio)->sig;
        free(temp);
    }
}


//Funcion para agregar nodos tipo_arbol a una fila
void Agregar_Fila(tipo_fila *fila, tipo_arbol *aux)
{
  if(fila->fin == fila->size-1)
    return;
  fila->lista[++fila->fin] = aux;
  if(fila->frente == -1)
    ++fila->frente;
}


//Funcion para encontrar el nodo de menor probabilidad en alguna de las 2 filas
//trabaja con greedy
tipo_arbol *Encontrar_Min(tipo_fila *fila1, tipo_fila *fila2)
{
  // Si la fila 1 esta vacia, sacar nodo de la fila 2
  if(fila1->frente == -1)
    return Obtener_Nodo(fila2);
  // Si la fila 2 esta vacia, sacar nodo de la fila 1
  if(fila2->frente == -1)
    return Obtener_Nodo(fila1);
  // Comparamos el elemento de la fila 1 con el de la fila 2, si es menor, sacar nodo de la fila 1
  if(fila1->lista[fila1->frente]->proba < fila2->lista[fila2->frente]->proba)
    return Obtener_Nodo(fila1);
  // Sino sacar noso de la fila 2.
  return Obtener_Nodo(fila2);
}

//Funcion para sacar un nodo de alguna fila
//2da parte de greedy
tipo_arbol *Obtener_Nodo(tipo_fila *fila)
{
  tipo_arbol *temp;
  if(fila->frente == -1)
    return NULL;
  temp = fila->lista[fila->frente];
  if(fila->frente == fila->fin)
    fila->frente = fila->fin = -1;
  else
    ++fila->frente;
  return temp;
}

//crear codigos y guardarlos en una arreglo
//a partir del arbol
void Crear_Codigos(tipo_arbol *raiz, char *codigo, int *size, tipocodigo Codigos[MAX])
{
  char codi[MAX], codd[MAX];
  if(raiz != NULL)
    {
      if(raiz->der == NULL && raiz->izq == NULL)
    {
      strcpy(Codigos[*size].codigo, codigo);
      Codigos[*size].caracter = raiz->simbolo;
      (*size)++;
    }
      else
    {
      sprintf(codi, "%s0", codigo);
      Crear_Codigos(raiz->izq, codi, size, Codigos);
      sprintf(codd, "%s1", codigo);
      Crear_Codigos(raiz->der, codd, size, Codigos);
    }
    }
}

//liberar memoria del arbol
void Borrar_Arbol(tipo_arbol *raiz)
{
  if(raiz != NULL)
    {
      Borrar_Arbol(raiz->izq);
      Borrar_Arbol(raiz->der);
      free(raiz);
    }
}


//Funcion para crear un arbol binario para los codigos de Huffman
void Crear_Arbol(tipodato *inicio, tipo_arbol **raiz)
{
  tipodato *temp;
  tipo_arbol *left, *right, *nuevo, *aux;
  tipo_fila *fila1, *fila2;
  int i=0;
      temp = inicio;
      while(temp != NULL)
    {
      i++; // Contador del tamanio de la lista
      temp = temp->sig;
    }
      // Creamos 2 filas para los nodos...
      fila1 = (tipo_fila *)malloc(sizeof(tipo_fila));
      fila2 = (tipo_fila *)malloc(sizeof(tipo_fila));
      fila1->frente = fila1->fin = -1;
      fila1->size = i;
      fila2->frente = fila2->fin = -1;
      fila2->size = i;
      fila1->lista = (tipo_arbol **)malloc(sizeof(tipo_arbol *)*i);
      fila2->lista = (tipo_arbol **)malloc(sizeof(tipo_arbol *)*i);
      temp = inicio;
      while(temp != NULL)
    {
      // Creamos los nodos de los arboles...
      aux = (tipo_arbol *)malloc(sizeof(tipo_arbol));
      aux->proba = temp->probabilidad;
      aux->simbolo= temp->carac;
      aux->der = aux->izq = NULL;
      Agregar_Fila(fila1, aux); // Agregamos los nodos a la fila 1
      temp = temp->sig;
    }
      while(!((fila1->frente == -1) && (fila2->frente == fila2->fin && fila2->frente != -1)))
    {
      // Sacamos los 2 nodos de menor probabilidad
      left = Encontrar_Min(fila1, fila2);
      right = Encontrar_Min(fila1, fila2);
      // Creamos un nuevo nodo y unimos a los nodos de menor probabilidad
      nuevo = (tipo_arbol *)malloc(sizeof(tipo_arbol));
      nuevo->proba = left->proba + right->proba;
      nuevo->der = right;
      nuevo->izq = left;
      Agregar_Fila(fila2, nuevo); // Agregamos el nuevo nodo a la fila 2
    }
      // Sacamos la raiz de la fila 2
      *raiz = Obtener_Nodo(fila2);
      // Liberamos la memoria en uso
      free(fila1->lista);
      free(fila2->lista);
      free(fila1);
      free(fila2);
}

//imprime el arbol
// no se muestra
//solo es para verificar
void imprimirArbol(tipo_arbol *p){
    if(p!=NULL){
        imprimirArbol(p->izq);
        printf("%c: %f\n",p->simbolo, p->proba);
        imprimirArbol(p->der);
    }
}

//ingresar  simbolos
//utilizado en lectura
void Ingresar_Simbolo(tipodato **inicio, char simbolo, float proba)
{
  tipodato *temp, *aux1, *aux2;
  temp = (tipodato *)malloc(sizeof(tipodato));
  temp->carac = simbolo;
  temp->probabilidad = proba;
  temp->sig = NULL;
  aux1= *inicio;
  while((aux1 != NULL) && (aux1->probabilidad < proba))
    {
      aux2= aux1;
      aux1= aux1->sig;
    }
  if(*inicio == aux1)
    *inicio = temp;
  else
    aux2->sig = temp;
  temp->sig = aux1;
}


//codificar un mensaje
//el archivo debe ya estar creado
void Codificar(tipocodigo Codigos[MAX], int size)
{
  FILE *Archi, *file;
  char Archivo[MAX], Texto[MAX][MAX];
  int i=0, opcion, j, k, n, x;
  printf("Ingresa el archivo con el mensaje que desea codificar\n");
  NombreArchivo(Archivo);
  if((Archi = fopen(Archivo, "rt")) != NULL)
    {
      printf("\nIngresa el nombre del archivo en donde guardar el mensaje codificado.\n");
      NombreArchivo(Archivo);
      if((file = fopen(Archivo, "rt")) != NULL)
    {
      fclose(file);
      printf("El archivo ya existe. ¿Quieres sobrescribirlo?\n");
      printf("Ingresa 1 para aceptar y sobreescribir.\nIngresa 2 para rechazar y no hacerlo.\nOpcion: ");
      scanf("%d", &opcion);
      if(opcion == 1)
        {
          file = fopen(Archivo, "wt");
          while(fgets(Texto[i], MAX-2, Archi) != NULL)
        {
          Texto[i][strlen(Texto[i])-1] = 0;
          i++;
        }
          for(k = 0; k < i; k++)
        for (j = 0; j < strlen(Texto[k]); j++)
          {
            for(x = 0; x< size; x++)
              if(Codigos[x].caracter == Texto[k][j])
            {
              fprintf(file, "%s", Codigos[x].codigo);
            }
          }
          fclose(file);
          fclose(Archi);
          printf("Tu archivo ha sido guardado correctamente.\n");
        }
      else
        printf("No se sobreescribio el archivo.\n");
    }
      else
    {
      file = fopen(Archivo, "wt");
      while(fgets(Texto[i], MAX-2, Archi) != NULL)
        {
          Texto[i][strlen(Texto[i])-1] = 0;
          i++;
        }
      for(k = 0; k < i; k++)
        for (j = 0; j < strlen(Texto[k]); j++)
          {
        for(x = 0; x< size; x++)
          if(Codigos[x].caracter == Texto[k][j])
            {
              fprintf(file, "%s", Codigos[x].codigo);
            }
          }
      fclose(file);
      fclose(Archi);
      printf("Tu archivo ha sido guardado correctamente.\n");
    }
    }
  else
    printf("No se encontro el archivo.\n");
}


//Funcion para decodificar un mensaje de un archivo de texto
 //funciona "al reves" que codificar
void Decodificar(tipo_arbol *raiz)
{
  FILE *Archi, *file;
  char Archivo[MAX], Texto[MAX][MAX];
  int i=0, opcion, j, k;
  tipo_arbol *temp;
  printf("Ingresa el archivo con el mensaje que desea decodificar\n");
  NombreArchivo(Archivo);
  if((Archi = fopen(Archivo, "rt")) != NULL)
    {
      printf("\nIngresa el nombre del archivo en donde guardar el mensaje decodificado.\n");
      NombreArchivo(Archivo);
      if((file = fopen(Archivo, "rt")) != NULL)
    {
      fclose(file);
      printf("El archivo ya existe. ¿Quieres sobrescribirlo?\n");
      printf("Ingresa 1 para aceptar y sobre escribir.\nIngresa 2 para rechazar y no hacerlo.\nOpcion: ");
      scanf("%d", &opcion);
      if(opcion == 1)
        {
          file = fopen(Archivo, "wt");
          while(fgets(Texto[i], MAX-2, Archi) != NULL)
        {
          Texto[i][strlen(Texto[i])-1] = 0;
          i++;
        }
          temp = raiz;
          for(k = 0; k < i; k++)
        for (j = 0; j < strlen(Texto[k]); j++)
          {
            if (Texto[k][j] == '0')
              temp = temp->izq;
            else
              temp = temp->der;
            if(temp->izq == NULL && temp->der == NULL)
              {
            fprintf(file, "%c", temp->simbolo);
            temp = raiz;
              }
          }
          fclose(file);
          fclose(Archi);
          printf("Tu archivo se ha guardado correctamente.\n");
        }
      else
        printf("No se cambia el archivo.\n");
    }
      else
    {
      file = fopen(Archivo, "wt");
      while(fgets(Texto[i], MAX-2, Archi) != NULL)
        {
          Texto[i][strlen(Texto[i])-1] = 0;
          i++;
        }
      temp = raiz;
      for(k = 0; k < i; k++)
        for (j = 0; j < strlen(Texto[k]); j++)
          {
        if (Texto[k][j] == '0')
          temp = temp->izq;
        else
          temp = temp->der;
        if(temp->izq == NULL && temp->der == NULL)
          {
            fprintf(file, "%c", temp->simbolo);
            temp = raiz;
          }
          }
      fclose(file);
      fclose(Archi);
      printf("Tu archivo ha sido guardado correctamente.\n");
    }
    }
  else 
    printf("No se encontro el archivo.\n");
}

//Guardar un diccionario
void guarda(tipodato *inicio){
    tipodato *temp;
    FILE *archivo;
    char nombrearch[50];
        temp=inicio;
    
    printf("Ingrese el nombre del archivo: ");
    __fpurge(stdin);
    gets(nombrearch);
    
    archivo = fopen(nombrearch, "wt");
    while (temp!=NULL) {
        fprintf(archivo, "%c\n", temp->carac);
        fprintf(archivo, "%f\n", temp->probabilidad);
        temp=temp->sig;
    }
    fclose(archivo);
    printf("se ha guardado el archivo");
}

//cargar un diccionario
void Leer_Archivo(tipodato **inicio, char *Archivo)
{
  char simbolo;
  float proba;
  FILE *Archi;
  if((Archi = fopen(Archivo, "rt")) != NULL) // Si el archivo existe entonces...
    {
      while(fscanf(Archi, "%c\n%f\n", &simbolo, &proba) == 2)
    {
      Ingresar_Simbolo(inicio, simbolo, proba);
    }
      fclose(Archi);
    }
  else // Si el archivo no existe...
    printf("No puede encontrar el archivo que me diste.\n");
}

//para conseguir nombre de archivo
void NombreArchivo(char *Archivo)
{
  printf("Nombre: ");
  __fpurge(stdin);
  fgets(Archivo, MAX-2, stdin);
  Archivo[strlen(Archivo)-1] = 0;
}
