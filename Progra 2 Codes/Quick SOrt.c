//
//  Quick SOrt.c
//  
//
//  Created by Andres Moguel on 3/18/21.
//

#include<stdio.h>
#include<string.h>
#include <stdlib.h>

void quickSort(int a[], int l, int r);
int partition(int a[], int l, int r);
                     
int main(void){
    int total;
    int i;
    int numeros[100];
      printf("Cuantos numeros desea ingresar: ");
      scanf("%d", &total);
      fpurge(stdin);
    for (i=0; i<total; i++) {
        printf("ingrese el numero[%i]: ", i+1);
        scanf("%d", &numeros[i]);
        fpurge(stdin);
    }
    printf("Desorden:\n");
    for (i=0; i<total; i++) {
        printf("%d\n", numeros[i]);
    }
    
    quickSort(numeros, 0, total-1);
    
    printf("ordenados: \n");
    for (i=0; i<total; i++) {
        printf("%d\n",numeros[i]);
    }
}

void quickSort(int a[], int l, int r){
    int j;
    if(l<r)
    {
        //divide and conq
        j=partition(a, l, r);
        quickSort(a, l, j-1);
        quickSort(a, j+1, r);
    }
}

int partition(int a[], int l, int r){
    int pivot, i, j, t;
    
    pivot = a[l];
    i=l;
    j=r+1;
    
    while(1)
    {
        do
            ++i;
        while((a[i] <= pivot) && (i <= r));
        do
            --j;
        while(a[j] > pivot);
        if(i >= j)
            break;
        t=a[i];
        a[i]=a[j];
        a[j]=t;
    }
    t=a[l];
    a[l]=a[j];
    a[j]=t;
    return j;
}
