#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int acumulador;


    for(i=0; i<100; i++)
    {
        i=i+2;
        printf("%d ", i);

        acumulador=acumulador+i;

    }
    printf("La suma de todos los numeros es : %d", acumulador);
    return 0;
}
