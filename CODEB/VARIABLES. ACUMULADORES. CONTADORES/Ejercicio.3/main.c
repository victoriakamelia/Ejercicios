#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroUno;
    int numeroDos;
    int producto;
    int cuadrado;

    printf("Ingrese numero uno:\n");
    scanf("%d", &numeroUno);

    while(numeroUno <= 0)
    {
        printf("Ingrese un numero mayor a cero:\n");
        scanf("%d", &numeroUno);
    }

    printf("Ingrese numero dos:\n");
    scanf("%d", &numeroDos);

    while(numeroDos <= 0)
    {
        printf("Ingrese un numero mayor a cero:\n");
        scanf("%d", &numeroDos);
    }

    producto=numeroUno*numeroDos;
    cuadrado=numeroUno*numeroUno;

    printf("El producto de los numeros ingresados es: %d.\nEl cuadrado de %d es %d.\n", producto, numeroUno, cuadrado);


    return 0;
}
