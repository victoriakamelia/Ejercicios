#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    if(numero >=0)
    {
        printf("El numero ingresado es positivo.");
    }else
    {
        printf("El numero ingresado es negativo.");
    }
    return 0;
}
