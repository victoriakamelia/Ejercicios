#include <stdio.h>
#include <stdlib.h>

void sumar4();
int main()
{
    sumar4();
    return 0;
}

void sumar4()
{
    int numero1;
    int numero2;
    int suma;

    printf("INGRESE UN NUMERO: \n");
    scanf("%d", &numero1);
    printf("INGRESE OTRO NUMERO: \n");
    scanf("%d", &numero2);

    suma=numero1+numero2;
    printf("RESULTADO: %d.\n", suma);
}
