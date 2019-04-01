#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int cuadrado;

    printf("Ingrese un numero para calcular el cuadrado del mismo:\n");
    scanf("%d",&numero);

    if(numero <= 0)
    {
        printf("Error. Ingrese un numero para calcular el cuadrado del mismo:\n");
        scanf("%d",&numero);
    }

    cuadrado=numero*numero;
    printf("El cuadrado de %d es %d", numero, cuadrado);
    return 0;
}
