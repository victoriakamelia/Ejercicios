#include <stdio.h>
#include <stdlib.h>

int sumar3();
int main()
{
    printf("RESULTADO: %d.\n", sumar3());
    return 0;
}

int sumar3()
{
    int numero1;
    int numero2;
    int suma;

    printf("INGRESE UN NUMERO: \n");
    scanf("%d", &numero1);
    printf("INGRESE OTRO NUMERO: \n");
    scanf("%d", &numero2);

    suma=numero1+numero2;

    return suma;
}
