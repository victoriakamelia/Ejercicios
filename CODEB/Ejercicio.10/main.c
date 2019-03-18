#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int contador=0;

    for(i=0; i<100; i++)
    {
        if(i%2 != 0)
        {
            printf("%d \n",i);
            contador++;
        }
    }

    printf("%d", contador);
    return 0;
}
