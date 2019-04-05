#include <stdio.h>
#include <stdlib.h>
int getInt(int* puntero, int intentos, char* memsaje);

int main()
{
    int x;
    int flagX;
    char mensaje[20]={"INGRESE UN NUMERO"};


    flagX=getInt(&x, 3, mensaje);

    if(flagX == 1)
    {
        printf("%d", x);
    }
    else
    {
        printf("No se pudo cargar la variable. \n");
    }


    return 0;
}

int getInt(int* puntero, int intentos, char* mensaje)
{
    int num;
    int ok;
    int contador=0;

    printf("%s \n", mensaje);
    scanf("%d", &num);

    while(num <= 0)
    {
        printf("Error Reingrese un numero positivo: \n");
        scanf("%d", &num);
        contador++;

        if(contador == intentos)
        {
            ok=0;
            break;
        }
    }

    if(contador<intentos)
    {
        *puntero= num;
        ok=1;
    }


    return ok;

}
