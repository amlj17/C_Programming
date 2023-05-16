//
//  Heap Sort.c
//  
//
//  Created by Andres Moguel on 3/18/21.
//

#include<stdio.h>
#include<string.h>
#include <stdlib.h>

void makeheap(int x[], int n);
void heapsort1(int x[], int n);
                     
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
    
    heapsort1(numeros, total);
    
    printf("ordenados: \n");
    for (i=0; i<total; i++) {
        printf("%d\n",numeros[i]);
    }
}

void makeheap(int x[], int n){
    int i, val, s, f;
    for(i=1;i<n;i++)
    {
        val=x[i];
        s=i;
        f=(s-1)/2;
        while(s>0 && x[f]<val)
        {
            x[s]=x[f];
            s=f;
            f=(s-1)/2;
        }
        x[s]=val;
    }
}

void heapsort1(int x[], int n){
    int i, s, f, ivalue;
    for(i=n-1; i>0; i--)
    {
        ivalue=x[i];
        x[i]=x[0];
        f=0;
        if(i==1)
            s=-1;
        else
            s =1;
        if(i>2 && x[2]>x[1])
            s=2;
        while(s>=0 && ivalue<x[s])
        {
            x[f]=x[s];
            f=s;
            s=2*f+1;
            if(s+1<=i-1 && x[s]<x[s+1])
                s++;
            if(s>i-1)
                s=-1;
        }
        x[f]=ivalue;
    }
}
