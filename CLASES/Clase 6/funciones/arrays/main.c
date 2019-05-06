#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define pf printf

int buscarEntero(int num, int vec[], int tam);

int main()
{
    char nombres[][20]={"Juan", "Jose", "Ana", "Maria", "Mia", "Jaime", "Esteban", "Julio", "Lara", "Sofia"};
    int legajos[TAM] = {123, 543, 679, 432, 567, 111, 323, 145, 674, 543};
    int edades[TAM] = {23, 24, 21, 23, 22, 22, 44, 36, 29, 38};
    char sexos[TAM] = {'f', 'f', 'm', 'f', 'm', 'm', 'f', 'f', 'm', 'f'};
    int auxInt;
    char auxChar;

    char sex;
    int leg;
    int index;


   /* printf("Ingrese legajo: ");
    scanf("%d", &leg);

    index = buscarEntero(leg, legajos, TAM);

    if( index == -1){
        printf("\nEl legajo %d no esta registrado en el sistema\n\n", leg);
    }
    else{

    sex = sexos[index];

    printf("\nLa persona con legajo: %d es de sexo %c\n\n", leg, sex);

    }

    /*for(int i=0; i < TAM - 1;  i++)
    {
        for(int j = i +1; j < TAM;  j++)
        {
            if( sexos[i] > sexos[j])
            {
                auxInt = legajos[i];
                legajos[i] = legajos[j];
                legajos[j] = auxInt;

                auxInt = edades[i];
                edades[i] = edades[j];
                edades[j] = auxInt;

                auxChar = sexos[i];
                sexos[i] = sexos[j];
                sexos[j] = auxChar;
            }
            else if( sexos[i] == sexos[j] && edades[i] < edades[j])
            {
                auxInt = legajos[i];
                legajos[i] = legajos[j];
                legajos[j] = auxInt;

                auxInt = edades[i];
                edades[i] = edades[j];
                edades[j] = auxInt;



            }
        }



    }

*/

    for(int i=0; i < TAM;  i++)
    {


        printf("%15s   %d      %c      %d\n", nombres[i], legajos[i], sexos[i], edades[i]);


    }









    return 0;
}

int buscarEntero(int num, int vec[], int tam)
{
    int indice = -1;

    for(int i=0; i< tam; i++)
    {
        if( num == vec[i])
        {
            indice = i;
            break;
        }
    }

    return indice;

}





































