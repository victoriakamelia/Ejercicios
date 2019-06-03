#include <stdio.h>
#include <stdlib.h>
#define TAM 10

int main()
{
    int* pNum;
    int i;

    pNum=(int*)malloc(sizeof(int)*5);

    if(pNum==NULL)
    {
        printf("No se encontro memoria.\n");
        system("pause");
        exit(1);
    }else
    {
        for(i=0;i<5;i++)
        {
            printf("Ingrese un numero para la posicion %d: ", i);
            scanf("%d",pNum+i);
        }

        for(i=0;i<5;i++)
        {
            printf("\nEl numero para la posicion %d es: ", i);
            printf("%d ", *(pNum++));
        }
    }

    free(pNum);
    return 0;
}
