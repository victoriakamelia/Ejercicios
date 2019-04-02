#include <stdio.h>
#include <stdlib.h>
int contarPares(int vec[], int tam);
int main()
{
    int vec[]={5,8,9,4,2};
    printf("Cantidad pares en array: %d.", contarPares(vec, 5));



    return 0;
}
int contarPares(int vec[], int tam)
{
    int i;
    int contadorPar=0;
    for(i=0; i<tam; i++)
    {
        if(vec[i]%2==0)
        {
            contadorPar++;
        }
    }

    return contadorPar;
}
