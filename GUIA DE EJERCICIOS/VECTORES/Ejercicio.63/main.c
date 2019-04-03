#include <stdio.h>
#include <stdlib.h>
void cargaSecuencial();
int main()
{
    cargaSecuencial();
    return 0;
}

void cargaSecuencial()
{

    int edad[]={23,24,25,26,27,28,29,30,31,32};
    //int salario[]={10000,11000,120000,1300,14896,1563,15552,18596,300,6000};

    int i;

    int acumulador=0;
    int promedio;

    for(i=0; i<10; i++)
    {
        acumulador=acumulador+ edad[i];
    }

    promedio=acumulador/10;

    printf("EL PROMEDIO DE LAS EDADES ES: %d.\n", promedio);

    for(i=0; i<10; i++)
    {
        if(edad[i]>promedio)
        {
            printf("El trabajador con legajo %d supera el promedio de edad con %d.\n", i, edad[i]);
        }
    }
}
