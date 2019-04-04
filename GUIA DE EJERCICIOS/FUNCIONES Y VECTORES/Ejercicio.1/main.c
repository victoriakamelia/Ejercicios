#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void mostarVector(int* vec, int tam);
int main()
{
    int vec[TAM]={3,6,8,4,59};

    mostarVector(vec, TAM);

    return 0;
}

void mostarVector(int* vec, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("El valor en el indice %d es: %d\n", i, vec[i]);
    }
}
