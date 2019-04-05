#include <stdio.h>
#include <stdlib.h>

void sumar2(int, int);
int main()
{
    int numeroUno;
    int numeroDos;

    printf("INGRESE UN NUMERO: \n");
    scanf("%d", &numeroUno);
    printf("INGRESE OTRO NUMERO: \n");
    scanf("%d", &numeroDos);
    sumar2(numeroUno, numeroDos);
    return 0;
}

void sumar2(int numero1, int numero2)
{
    int suma;
    suma=numero1+numero2;

    printf("RESULTADO: %d\n", suma);

}
