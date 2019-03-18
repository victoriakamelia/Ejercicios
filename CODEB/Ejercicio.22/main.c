#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroUno;
    int numeroDos;
    int aux;

    printf("Ingrese el primer numero: ");
    scanf("%d",&numeroUno);
    printf("Ingrese el segundo numero: ");
    scanf("%d",&numeroDos);

    aux=numeroUno;
    numeroUno=numeroDos;
    numeroDos=aux;

    printf("%d\n%d", numeroUno, numeroDos);
    return 0;
}
