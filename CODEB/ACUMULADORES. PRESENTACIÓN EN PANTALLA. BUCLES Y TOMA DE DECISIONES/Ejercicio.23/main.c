#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int max;
    int flag=0;
    int i;

    for(i=0; i<3; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numero);

        if(flag == 0 || numero>max)
        {
            max=numero;
            flag=1;
        }
    }

    printf("El mayor numero ingresado es: %d", max);
    return 0;
}
