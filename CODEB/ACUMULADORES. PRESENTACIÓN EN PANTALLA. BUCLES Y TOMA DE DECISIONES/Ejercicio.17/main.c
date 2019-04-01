#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    if(numero%2==0)
    {
        printf("El numero ingresado es par.");
    }else
    {
        printf("El numero ingresado es impar.");
    }
    return 0;
}
