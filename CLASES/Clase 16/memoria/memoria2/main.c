#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* vec;
    int* pAux;

    vec = (int*) malloc(sizeof(int)*5);

    if(vec == NULL){
        printf("No se consiguio memoria\n\n");
        exit(1);
    }

    for(int i=0; i < 5; i++){
        printf("Ingrese un numero: ");
        scanf("%d", vec + i );
    }

    for(int i=0; i < 5; i++){
        printf("%d ", *(vec + i));

    }

    printf("\n\n");

    pAux = (int*) realloc(vec, sizeof(int)*10);

    if( pAux != NULL){
        vec = pAux;
        printf("Se agrando el vector\n\n");
    }
    else{
        printf("No se pudo redimensionar el array\n");

    }

     for(int i=5; i < 10; i++){
        printf("Ingrese un numero: ");
        scanf("%d", vec + i );
    }

    for(int i=0; i < 10; i++){
        printf("%d ", *(vec + i));

    }
    printf("\n\n");

    vec = (int*)realloc(vec, sizeof(int)*5);

     for(int i=0; i < 10; i++){
        printf("%d ", *(vec + i));

    }
    printf("\n\n");







    free(vec);











    return 0;
}
