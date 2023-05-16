//
//  Cambios Variables.c
//  
//
//  Created by Andres Moguel on 1/20/21.
//

// cambios de variables
#include <stdio.h>
void cambia(int* a, int* b, int* c);

int main(void){
    int a, b, c;
    printf("introduce 3 números separados por espacios: \n");
    scanf("%d %d %d", &a, &b, &c);
    cambia(&a,&b,&c);
    printf("a=%d \n b=%d \n c=%d \n", a, b, c);
    return 0;
}

void cambia(int* a, int* b, int* c){
    int temporal;
    temporal = *a;
    *a = *c;
    *c = *b;
    *b = temporal;
}
