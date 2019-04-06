#include <stdio.h>
#include <stdlib.h>
#define TAM 10
void funcionUno(int* , int* , char* , int );
int main()
{
    int legajo[TAM]={123,698,354,785,165,236,547,559,636,158};
    int edades[TAM]={23,58,45,12,85,41,70,36,63,50};
    char sexo[TAM]={'f', 'f', 'm','m','f','m','f', 'f', 'm','f'};
    int i;
    int j;
    int auxInt;
    int auxChar;


    for(i=0; i<TAM-1;i++)
    {
        for(j=i+1; j<TAM; j++)
        {
            if(sexo[i]>sexo[j])
            {
                auxInt=legajo[i];
                legajo[i]=legajo[j];
                legajo[j]=auxInt;

                auxInt=edades[i];
                edades[i]=edades[j];
                edades[j]=auxInt;

                auxChar=sexo[i];
                sexo[i]=sexo[j];
                sexo[j]=auxChar;
            }else
            {
                if(legajo[i]>legajo[j])
                {
                    auxInt=legajo[i];
                    legajo[i]=legajo[j];
                    legajo[j]=auxInt;

                    auxInt=edades[i];
                    edades[i]=edades[j];
                    edades[j]=auxInt;
                }
            }

        }
    }

    for(i=0; i < TAM;  i++)
        {


            printf("%d      %c      %d\n", legajo[i], sexo[i], edades[i]);


        }

        funcionUno(legajo, edades, sexo, TAM);

    return 0;
}


void funcionUno(int* legajo, int* edades, char* sexo, int tam)
{
    int leg;
    int i;

    printf("\nIngrese un legajo: ");
    scanf("%d", &leg);

    for(i=0; i<tam; i++)
    {
        if(legajo[i]==leg)
        {
            printf("El sexo del legajo %d es %c.\n", leg, sexo[i]);
            break;
        }
        else
        {
            printf("El legajo ingresado no es correcto.\n");
            break;
        }
    }
}
