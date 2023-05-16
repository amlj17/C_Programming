//
//  lista dinamica.c
//
//
//  Created by Andres Moguel on 2/17/21.
//


typedef struct def_dato
{
    int num;
    struct def_dato *sig;
}tipo_dato;

void Inserta_Inicio(tipo_dato **inicio, int dato);
void Imprimir(tipo_dato *inicio);
void Borrar(tipo_dato **inicio);
void inserta_fin(tipo_dato **inicio, int dato);
void inserta_medio(tipo_dato **inicio, int dato, tipo_dato *temp);
void insertar(tipo_dato **inicio, int dato);
int eliminar(tipo_dato **inicio, int dato);
void guarda(tipo_dato *inicio);
void leer(tipo_dato **inicio);
void menu(void);

int main(void){
    tipo_dato *primero = NULL;
    int numero, opcion;
    
    do
    {
        menu();
        scanf("%d", &opcion);
        switch (opcion){
            case 1:
                printf("dame el numero: ");
                scanf("%d", &numero);
                //name nombre y otras cosas
                insertar(&primero, numero); //pasamos nombre y otras cosas
                break;
            case 2:
                Imprimir(primero);
                break;
            case 3:
                printf("Dame el numero a eliminar: ");
                scanf("%d", &numero);
                __fpurge(stdin);
                if(eliminar(&primero, numero)==1){
                    printf("El numero no esta en la lista\n");
                }
                else
                    printf("fue eliminado con exito\n");
                break;
            case 4:
                guarda(primero);
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
        printf("1 Insertar numero\n");
        printf("2 Mostrar Numeros\n");
        printf("3 Eliminar Numero\n");
        printf("4 Guardar\n");
        printf("5 Leer\n");
        printf("6 Salir\n");
        printf("Opcion: ");
}

void Inserta_Inicio(tipo_dato **inicio, int dato){
    tipo_dato *temp;
    
    temp =(tipo_dato*)malloc(sizeof(tipo_dato));
    temp ->num = dato;
    //meter nombre y otras cosas
    temp ->sig = *inicio;
    *inicio = temp;
}

void Imprimir(tipo_dato *inicio){
    tipo_dato *temp;
    
    temp = inicio;
    while (temp!=NULL) {
        printf("%d\n", temp->num);
        temp=temp ->sig;
    }
}

void Borrar(tipo_dato **inicio){
    tipo_dato *temp;
    
    while (*inicio!=NULL) {
        temp=*inicio;
        *inicio=(*inicio)->sig;
        free(temp);
    }
}

void inserta_fin(tipo_dato **inicio, int dato){
    tipo_dato *temp, *temp2;
    
    temp=(tipo_dato*)malloc(sizeof(tipo_dato));
    temp->num=dato;
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

void inserta_medio(tipo_dato **inicio, int dato, tipo_dato *temp ){
    tipo_dato *nueva, *temp2;
    nueva=(tipo_dato*)malloc(sizeof(tipo_dato));
    nueva->num=dato;
    nueva->sig=temp;
    temp2=*inicio;
    while (temp2->sig!=temp) {
        temp2=temp2->sig;
    }
    temp2->sig=nueva;
}


void insertar(tipo_dato **inicio, int dato){
    tipo_dato *temp;
    
    temp = *inicio;
    while ((temp!=NULL)&&(dato>(temp->num))) {
        temp=temp->sig;
    }
    if (temp==NULL) {
        inserta_fin(inicio, dato);
    }
    else{
        if (temp==*inicio) {
            Inserta_Inicio(inicio, dato);
        }
        else
            inserta_medio(inicio, dato, temp);
    }
}

int eliminar(tipo_dato **inicio, int dato){
    tipo_dato *temp, *anterior;
    
    temp = *inicio;
    
    while ((temp!=NULL)&&(temp->num!=dato))
        temp=temp->sig;
    if (temp!=NULL) {
        if (temp!=*inicio) {
            anterior=*inicio;
            while(anterior->sig!=temp)
                anterior=anterior->sig;
            anterior->sig=temp->sig;
            free(temp);
        }
        else
        {
            *inicio=(*inicio)->sig;
            free(temp);
        }
        return 0;
        }
    else
        return 1;
    }

void guarda(tipo_dato *inicio){
    tipo_dato *temp;
    FILE *archivo;
    char nombrearch[50];
    
    printf("Ingrese el nombre del archivo: ");
    __fpurge(stdin);
    gets(nombrearch);
    
    archivo = fopen(nombrearch, "wt");
    temp=inicio;
    while (temp!=NULL) {
        fprintf(archivo, "%d\n", temp->num);
        temp=temp->sig;
    }
        fclose(archivo);
}

void leer(tipo_dato **inicio){
    FILE *archivo;
    char nombrearchivo[50];
    int numero;
    
    printf("Ingrese el nombre del archivo: ");
    __fpurge(stdin);
    gets(nombrearchivo);
    archivo =fopen(nombrearchivo, "rt");
     if(archivo!=NULL){
         while (fscanf(archivo, "%d\n", &numero)==1) {
             insertar(inicio, numero);
         }
         fclose(archivo);
     }
    else
        printf("ese archivo no existe");
    
    fclose(archivo);
}
