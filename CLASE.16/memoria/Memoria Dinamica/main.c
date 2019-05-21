#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* pNum;

    pNum = (int*) malloc(sizeof(int));

    if(pNum == NULL){
        printf("No se consiguio memoria\n");
        system("pause");
        exit(1);
    }
    printf("Ingrese un numero: ");
    scanf("%d", pNum);

    printf("Usted ingreso el numero: %d\n\n", *pNum);

    free(pNum);




    return 0;
}
