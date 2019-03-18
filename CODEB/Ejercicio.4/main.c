#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroUno;
    int numeroDos;
    int resultado;

    system("cls");

    printf("Ingrese un numero: \n");
    scanf("%d", &numeroUno);

    printf("Ingrese un numero: \n");
    scanf("%d", &numeroDos);

    resultado=numeroUno-numeroDos;

    if(resultado < 0)
    {
        printf("El resultado de %d-%d=%d y es negativo\n", numeroUno, numeroDos, resultado);
    }else
    {
       printf("El resultado de %d-%d=%d y es positivo\n", numeroUno, numeroDos, resultado);
    }

    return 0;

}
