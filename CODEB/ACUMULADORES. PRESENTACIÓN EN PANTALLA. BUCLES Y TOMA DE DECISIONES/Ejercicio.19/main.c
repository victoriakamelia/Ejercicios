#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int i;
    //int numeroActual;
    int sumador=0;


    printf("Ingrese un numero distinto a cero: ");
    scanf("%d", &numero);
    sumador=numero;

    for(i=0; i<numero; i++)
    {
        sumador=sumador+i;
        printf("%d \n", i);
    }

    printf("suma de todos los numeros: %d", sumador);


    return 0;
}
