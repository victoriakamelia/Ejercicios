#include "color.h"

void listarColores(eColor col[], int tamCol)
{
    printf(" ID   Descripcion\n");
    printf("\n\n");

    for(int i=0; i<tamCol; i++)
    {
        printf(" %d   %s\n",col[i].id,col[i].nombreColor);
    }
}


void harcodeColores(eColor col[], int tamCol)
{
    eColor hardcode[]=
    {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Gris"},
        {5003, "Rojo"},
        {5004, "Azul"}

    };

    for(int i=0; i<tamCol; i++)
    {
        col[i]=hardcode[i];
    }
}


void obtenerColor(eColor col[], int tamCol, int idColor, char cadena[])
{
    for(int i=0; i<tamCol; i++)
    {
        if(col[i].id == idColor)
        {
            //COPIAR LA DESCRIPCION DE LA CADENA
            //DESTINO/ORIGEN
            strcpy(cadena,col[i].nombreColor);
        }
    }
}
