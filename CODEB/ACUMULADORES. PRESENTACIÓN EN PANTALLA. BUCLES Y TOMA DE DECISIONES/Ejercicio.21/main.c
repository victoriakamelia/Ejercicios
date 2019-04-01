#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int contador=0;
    int i;

    printf("Ingrese un numero: \n");
    scanf("%d", &numero);

    for(i=0; i <= numero; i++)
    {
        if(i%3==0 && i!=0)
        {
            contador++;
            printf("%d ",i);
        }
    }

    printf("La cantidad de numeros multiplos de 3 entre %d y 0 es: %d.", numero, contador);


    return 0;
}
