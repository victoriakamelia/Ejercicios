#include <stdio.h>
#include <stdlib.h>

void muestro1(int x[], int tam);
void muestro2(int x[], int tam);
void muestro3(int* x, int tam);
void muestro4(int* x, int tam);
int main()
{
    int vec[]={1,9,3,8,4};
    muestro1(vec, 5);
    muestro2(vec, 5);
    muestro3(vec, 5);
    muestro4(vec, 5);

    return 0;
}

void muestro1(int x[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("%d\n", x[i]);
    }
}
void muestro2(int x[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("%d\n", *(x++));
    }
}

void muestro3(int* x, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
    printf("%d\n", x[i]);
    }
}

void muestro4(int* x, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("%d\n", *(x++));
    }
}
