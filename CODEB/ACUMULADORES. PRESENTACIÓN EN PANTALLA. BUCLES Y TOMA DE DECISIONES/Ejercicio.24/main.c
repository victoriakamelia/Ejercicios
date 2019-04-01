#include <stdio.h>
#include <stdlib.h>

int main()
{
    int peso;
    int contadorMax=0;
    int contadorMin=0;
    char seguir='s';

    do
    {
        printf("Ingrese el peso del empleado: \n");
        scanf("%d", &peso);
        if(peso<=80)
        {
            contadorMin++;
        }else
        {
            contadorMax++;
        }
        fflush(stdin);

        printf("Desea continuar con la carga: s/n...\n");
        scanf("%c", &seguir);

    }while(seguir=='s');

    printf("La cantidad de empleados que pesa hasta 80kg inclusive es: %d.\n", contadorMin);
    printf("La cantidad de empleados que pesa mas de 80kg es: %d.\n", contadorMax);

    return 0;
}
