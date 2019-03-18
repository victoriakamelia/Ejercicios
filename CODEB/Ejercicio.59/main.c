#include <stdio.h>
#include <stdlib.h>

int main()
{
    int max;
    int aux;
    int indice;
    int i=0;
    int vector[10]={1,5,8,0,99999,1,0,20,6,1006};

    max=vector[i];
    indice=i;


    for(i=0; i<10;i++)
    {
        aux=vector[i];
        printf("%d-", vector[i]);

       if(aux>max)
       {
           max=vector[i];
           indice=i+1;

       }
    }

    printf("\n%d\n%d", max, indice);

    return 0;
}
