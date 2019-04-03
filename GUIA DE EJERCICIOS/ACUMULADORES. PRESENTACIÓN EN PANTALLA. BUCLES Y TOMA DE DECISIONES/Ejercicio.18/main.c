#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int i;
    int acumulador=0;
    int producto=1;

    for(i=0; i<10; i++)
    {
          printf("Ingrese un numero: ");
          scanf("%d", &numero);

    while(numero==0)
    {
        printf("Ingrese un numero distinto a cero: ");
          scanf("%d", &numero);
    }

    if (numero >0)
    {
        acumulador=acumulador+numero;
    }else
    {
        producto=producto*numero;
    }

    }

    printf("La suma de los positivos es: %d.", acumulador);
    printf("El producto de los negativos es: %d.", producto);
    return 0;
}
