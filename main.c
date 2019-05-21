#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* pNum;

    pNum=(int*)malloc(sizeof(int));

    if(pNum==NULL)
    {
        printf("No se encontro memoria.\n");
        system("pause");
        exit(1);
    }else
    {
        *pNum=5;
    }

    free(pNum);
    return 0;
}
