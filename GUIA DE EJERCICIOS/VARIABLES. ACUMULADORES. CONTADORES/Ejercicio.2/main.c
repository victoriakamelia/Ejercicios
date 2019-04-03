#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroUno;
    int numeroDos;
    int suma;

    printf("Ingrese numero uno:\n");
    scanf("%d", &numeroUno);
    printf("Ingrese numero dos:\n");
    scanf("%d", &numeroDos);

    suma= numeroUno+numeroDos;
    printf("La suma de los numeros ingresados es: %d", suma);

    return 0;
}
