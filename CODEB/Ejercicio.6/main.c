#include <stdio.h>
#include <stdlib.h>

int main()
{
    int contadorPosi=0;
    int contadorNega=0;
    int numero;

    for(int i=0; i<10; i++)
    {
        printf("Ingrese un numero: \n");
        scanf("%d",&numero);

        if(numero <= 0)
        {
            contadorNega++;
        }else
        {
            contadorPosi++;
        }

    }

    printf("Cantidad de numeros positivos: %d .\nCantidad de numeros negativos: %d .", contadorPosi, contadorNega);
    return 0;
}
