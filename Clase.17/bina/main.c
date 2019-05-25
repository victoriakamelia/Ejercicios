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
    eAuto auto1={1111, "FORD", 1.6};
    eAuto auto2={2221, "RENAULT", 1.8};
    eAuto auto3={3333, "PEUGEOT", 1.2};

    eAuto * lista= (eAuto*) malloc(3 * sizeof(eAuto));
    int i;

    * lista   =auto1;
    *(lista+1)=auto2;
    *(lista+2)=auto3;

    FILE * f;

    f=fopen("./autos.dat", "wb");
    if(f == NULL)
    {
        exit(1);
    }

    //fwrite(lista, sizeof(eAuto), 3, f);

    for( i=0; i<3; i++)
    {
        fwrite(lista+i, sizeof(eAuto), i, f);
    }

    mostrarAutos(lista, 3);
    fclose(f);
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
