#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int id;
    char marca[20];
    float cilindrada;
}eAuto;

void mostrarAuto(eAuto* unAuto);
void mostrarAutos(eAuto* lista, int tam);

int main()
{
    /*eAuto auto1={1111, "FORD", 1.6};
    eAuto auto2={2221, "RENAULT", 1.8};
    eAuto auto3={3333, "PEUGEOT", 1.2};*/

    eAuto * lista= (eAuto*) malloc(3 * sizeof(eAuto));

    /* * lista   =auto1;
    *(lista+1)=auto2;
    *(lista+2)=auto3; */

    FILE * f;
    int contador=0;
    int cant;

    f=fopen("./autos.dat", "rb");
    if(f == NULL)
    {
        exit(1);
    }

    //fwrite(lista, sizeof(eAuto), 3, f);

    while (!feof(f))
    {
        cant=fread(lista+contador, sizeof(eAuto), 1, f);
        if (cant<1)
        {
            if(feof(f)==0)
            {
                break;
            }else
            {
                printf("Se produjo un error.");
                break;
            }
        }
        contador++;
    }


    fclose(f);

  mostrarAutos(lista,contador);
    return 0;
}


void mostrarAuto(eAuto* unAuto)
{
    if(unAuto != NULL)
    {
        printf("%d   %10s   %.2f\n", unAuto->id,unAuto->marca,unAuto->cilindrada);

    }
}

void mostrarAutos(eAuto* lista, int tam)
{
    int i;
    printf("ID        MARCA     CILINDRADO\n");
    if(lista != NULL && tam>0)
    {
        for(i=0; i<tam; i++)
        {
            mostrarAuto(lista+i);
        }
    }

}
