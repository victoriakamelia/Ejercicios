#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10


int main()
{
    char nombres[TAM][20]={"Juan", "Jose", "Ana", "Maria", "Mia", "Jaime", "Esteban", "Julio", "Lara", "Sofia"};
    int legajos[TAM] = {123, 543, 679, 432, 567, 111, 323, 145, 674, 543};
    int edades[TAM] = {23, 24, 21, 23, 22, 22, 44, 36, 29, 38};
    char sexos[TAM] = {'m', 'm', 'f', 'f', 'f', 'm', 'm', 'm', 'f', 'f'};
    int auxInt;
    char auxChar;
    char auxMatriz[20];
    int i;
    int j;


for(i=0; i < TAM-1;  i++)
{
    for(j=i+1; j < TAM;  j++)
    {
        /*if((strcmp(nombres[i],nombres[j]))>0)
        {

                strcpy(auxMatriz, nombres[i]);
                strcpy(nombres[i], nombres[j]);
                strcpy(nombres[j], auxMatriz);

                auxInt = legajos[i];
                legajos[i] = legajos[j];
                legajos[j] = auxInt;

                auxInt = edades[i];
                edades[i] = edades[j];
                edades[j] = auxInt;

                auxChar = sexos[i];
                sexos[i] = sexos[j];
                sexos[j] = auxChar;



        }*/

        if(sexos[i]>sexos[j])
            {
                strcpy(auxMatriz, nombres[i]);
                strcpy(nombres[i], nombres[j]);
                strcpy(nombres[j], auxMatriz);

                auxInt = legajos[i];
                legajos[i] = legajos[j];
                legajos[j] = auxInt;

                auxInt = edades[i];
                edades[i] = edades[j];
                edades[j] = auxInt;

                auxChar = sexos[i];
                sexos[i] = sexos[j];
                sexos[j] = auxChar;

            }else if (sexos[i]==sexos[j] && (strcmp(nombres[i],nombres[j]))>0)
            {
                strcpy(auxMatriz, nombres[i]);
                strcpy(nombres[i], nombres[j]);
                strcpy(nombres[j], auxMatriz);

                auxInt = legajos[i];
                legajos[i] = legajos[j];
                legajos[j] = auxInt;

                auxInt = edades[i];
                edades[i] = edades[j];
                edades[j] = auxInt;

            }
    }
}

    for( i=0; i < TAM;  i++)
    {


        printf("%15s    %d      %c      %d\n", nombres[i], legajos[i], sexos[i], edades[i]);


    }




    return 0;
}


