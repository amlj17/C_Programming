//
//  Ordenamiento directo.c
//  
//
//  Created by Andres Moguel on 3/16/21.
//

#include<stdio.h>
#include<string.h>
#include <stdlib.h>

void ordenar(int lista[], int totales);
void burbuja(int m[], int elementos);
void insercion(int m[], int elementos);
void selsort(int arr[], int elementos);


int main(void){
    int total;
    int i;
    int numeros[100];
      printf("Cuantos numeros desea ingresar: ");
      scanf("%d", &total);
      fpurge(stdin);
    int numeros[total];
    for (i=0; i<total; i++) {
        printf("ingrese el numero[%i]: ", i+1);
        scanf("%d", &numeros[i]);
        fpurge(stdin);
    }
    printf("Desorden:\n");
    for (i=0; i<total; i++) {
        printf("%d\n", numeros[i]);
    }
    
    //ordenar(numeros, total);
    //burbuja(numeros, total);
    
    printf("ordenados: \n");
    for (i=0; i<total; i++) {
        printf("%d\n",numeros[i]);
    }
}

void ordenar(int lista[], int totales){
    int i, j, temp;
    for(i=0; i<totales; i++)
        for(j=i+1; j<totales; j++)
            if (lista[i]>lista[j]) {
                temp=lista[i];
                lista[i]=lista[j];
                lista[j]=temp;
            }
}


void burbuja(int m[], int elementos){
    int aux, i, s=1;
    
    while(s&&(--elementos>0))
    {
        s=0;
        for(i=1; i<=elementos; i++)
            if(m[i-1]>m[i]){
                aux = m[i-1];
                m[i-1]=m[i];
                m[i]=aux;
                s=1;
            }
    }
}

void insercion(int m[], int elementos){
    int i, k, x;
    //double x
    //desde el segundo elemento
    for(i=1; i<elementos; i++){
        x=m[i];
        k=i-1;
        while (k>=0 && x<m[k]) {
            m[k+1]=m[k];
            k--;
        }
        m[k+1]=x;
    }
}

void selsort(int arr[], int elementos){
    int i, j, min, temp;
    for (i=0; i<elementos; i++) {
        min=i;
        for(j=i+1; j<elementos; j++)
            if(arr[j]<arr[min])
                min=j;
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}
