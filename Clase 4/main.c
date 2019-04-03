#include <stdio.h>
#include <stdlib.h>

int pedirDesdeHasta(int desde, int hasta);

int main()
{
    int desde=1;
    int hasta=5;
    printf("Numero validado: %d", pedirDesdeHasta(desde, hasta));
    return 0;
}

int pedirDesdeHasta(int desde, int hasta)
{
    int num;
    printf("Ingrese un numero entre %d y %d: \n", desde, hasta);
    scanf("%d", &num);

    while(num <= desde || num >= hasta)
    {

        printf("Error. Ingrese un numero entre %d y %d: \n", desde, hasta);
        scanf("%d", &num);
    }

    return num;
}
