#include <stdio.h>
#include <stdlib.h>

int contadorPares(int vec[], int tam);
int main()
{
    int vec[]={10,7,5,4,9};
    //int tamanio=5;

    printf("La cantidad de pares %d", contadorPares(vec, 5));
    return 0;
}
int contadorPares(int vec[], int tam)
{
    int contadorPares=0;
    int i;


    for(i==0; i<tam; i++);
    {
        if(vec%2==0)
        {
            contadorPares++;
        }
    }
    return contadorPares;
}

