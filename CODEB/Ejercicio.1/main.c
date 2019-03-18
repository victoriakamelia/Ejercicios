#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int acumulador=0;
    int promedio=0;

    for(int i=0;i<5;i++)
    {
    printf("Ingrese un numero: \n" );
    scanf("%d",&numero);
    acumulador=acumulador+numero;
    }

    promedio=acumulador/5;

    printf("El promedio de los numeros ingresados es de : %d \n", promedio);
    return 0;
}
