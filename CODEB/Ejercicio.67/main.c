#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define TAM 2

char validarSeguir();
void menu();
void cargarArray(int* array, int tam);
void buscarIndice(int* array, int tam);
void buscarValor(int* array, int tam);


int main()
{
    menu();
    return 0;
}
void menu()
{
    int seguir='S';
    int array[TAM];
    int opcion;

    do
    {
        system("cls");
        system("COLOR 3B");
        printf("\n1.CARGAR UN ARRAY DE TAMANIO %d\n", TAM);
        printf("\n2.BUSCAR UN VALOR Y ENCONTRAR EL INDICE\n");
        printf("\n3.BUSCAR UN INDICE Y ENCONTRAR EL VALOR\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            cargarArray(array, TAM);
            seguir=validarSeguir();
            break;
        case 2:
            buscarIndice(array, TAM);
            seguir=validarSeguir();
            break;
        case 3:
            buscarValor(array,TAM);
            seguir=validarSeguir();
            break;

        default:
            break;


        }

    }while(seguir=='S');

}


char validarSeguir()
{
    char seguir='S';
    printf("\n         /D E S E A    C O N T I N U A R ?   S/N: ");
    scanf("%s", &seguir);
    seguir=toupper(seguir);

    while(seguir != 'N' && seguir != 'S')
    {
        printf("\n          /LA OPCION INGRESADA ES INVALIDA.");
        printf("\n         /D E S E A    C O N T I N U A R ?   S/N: ");
        scanf("%s", &seguir);
        seguir=toupper(seguir);

    }

    return seguir;

}

void cargarArray(int* array, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("Ingrese un valor para la posicion %d del array...\n", i);
        scanf("%d", &array[i]);
    }
}

void buscarIndice(int* array, int tam)
{
    int i;
    int valor;
    int flag=0;

    printf("Ingrese el valor a buscar: \n");
    scanf("%d", &valor);


    for(i=0; i < tam; i++)
    {
        if(array[i]==valor)
        {
            printf("EL valor fue encontrado en el indice: %d\n", i);
            flag=1;

        }
    }

    if(flag==0)
    {
        printf("No se ha encontrado ningun resultado :( \n");
    }


}

void buscarValor(int* array, int tam)
{

    int indice;


    printf("Ingrese el indice a buscar: \n");
    scanf("%d", &indice);

    if(indice>tam)
    {
        printf("El indice ingresado no es válido.\n");
    }else
    {
        printf("El valor en el indice %d es: %d \n", indice, array[indice]);
    }





}
