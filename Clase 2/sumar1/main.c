#include <stdio.h>
#include <stdlib.h>

int sumar1(int, int);
int main()
{
    int numeroUno;
    int numeroDos;

    printf("INGRESE UN NUMERO: \n");
    scanf("%d", &numeroUno);
    printf("INGRESE OTRO NUMERO: \n");
    scanf("%d", &numeroDos);

    printf("RESULTADO : %d \n", sumar1(numeroUno, numeroDos));
    return 0;
}

int sumar1(int numero1, int numero2)
{
    int suma;
    suma=numero1+numero2;


    return suma;
}
