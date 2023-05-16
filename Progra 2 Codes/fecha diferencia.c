//
//  fecha diferencia.c
//  
//
//  Created by Andres Moguel on 1/24/21.
//
#include<stdio.h>
#include<stdlib.h>
void consigueFecha(int* dia, int* mes, int* anio);
int valido_fecha(int dia, int mes, int anio);
void diferencia(int dia1, int mes1, int anio1, int dia2, int mes2, int anio2, int* dia_dif, int* mes_dif, int* anio_dif );
void resultados(int dia_dif, int mes_dif, int anio_dif, int* total_dia);

int main(void){
    int dia1, mes1, anio1,
        dia2, mes2, anio2;
    int total_dia;
    int dia_dif, mes_dif, anio_dif;
    printf("Fecha de inicio: \n");
    consigueFecha(&dia1, &mes1, &anio1);
    printf("Fecha de fin: \n");
    consigueFecha(&dia2, &mes2, &anio2);
    if(!valido_fecha(dia1, mes1, anio1))
       {
           printf("primera fecha es invalida.\n");
           exit(0);
       }
       if(!valido_fecha(dia2, mes2, anio2))
       {
           printf("Segunda fecha es invalida.\n");
           exit(0);
       }
    diferencia(dia1, mes1, anio1, dia2, mes2, anio2, &dia_dif, &mes_dif, &anio_dif );
    resultados(dia_dif, mes_dif, anio_dif, &total_dia);
    
}

void consigueFecha(int* dia, int* mes, int* anio){
    printf("Ingresa la fecha (DD/MM/YYYY): ");
    scanf("%d/%d/%d", dia, mes, anio);
}

void resultados(int dia_dif, int mes_dif, int anio_dif, int* total_dia){
    printf("Diferencia de : %d anios %02d meses and %02d dias.\n", anio_dif, mes_dif, dia_dif);
       *total_dia = dia_dif + (mes_dif * 30) + (anio_dif * 365);
       printf("Esa diferencia equivale a: %d dias.\n", *total_dia);
}

void diferencia(int dia1, int mes1, int anio1, int dia2, int mes2, int anio2, int* dia_dif, int* mes_dif, int* anio_dif ){
    if(dia2 < dia1)
       {
           if (mes2 == 3)
           {
               if ((anio2 % 4 == 0 && anio2 % 100 != 0) || (anio2 % 400 == 0))
               {
                   dia2 += 29;
               }

               else
               {
                   dia2 += 28;
               }
           }

           else if (mes2 == 5 || mes2 == 7 || mes2 == 10 || mes2 == 12)
           {
              dia2 += 30;
           }

           else
           {
              dia2 += 31;
           }

           mes2 = mes2 - 1;
       }

       if (mes2 < mes1)
       {
           mes2 += 12;
           anio2 -= 1;
       }

       *dia_dif = dia2 - dia1;
       *mes_dif = mes2 - mes1;
       *anio_dif = anio2 - anio1;
}


int valido_fecha(int dia, int mes, int anio)
{
    int is_valido = 1, is_leap = 0;
    if (anio >= 1800 && anio <= 9999)
    {
        if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))
        {
            is_leap = 1;
        }
        if(mes >= 1 && mes <= 12)
        {
            if (mes == 2)
            {
                if (is_leap && dia == 29)
                {
                    is_valido = 1;
                }
                else if(dia > 28)
                {
                    is_valido = 0;
                }
            }
            else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
            {
                if (dia > 30)
                {
                    is_valido = 0;
                }
            }
            else if(dia > 31)
            {
                is_valido = 0;
            }
        }

        else
        {
            is_valido = 0;
        }

    }
    else
    {
        is_valido = 0;
    }

    return is_valido;
}
