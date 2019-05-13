#include "marca.h"

void harcodeMarcas(eMarca mar[], int tamMar)
{
    eMarca hardcode[]=
    {
        {1000, "Renault"},
        {1001, "Fiat"},
        {1002, "Ford"},
        {1003, "Chevrolet"},
        {1004, "Peugeot"}
    };

    for(int i=0; i<tamMar; i++)
    {
        mar[i]=hardcode[i];
    }
}

void listarMarcas(eMarca mar[], int tamMar)
{
    printf(" ID   Descripcion\n");
    printf("\n\n");

    for(int i=0; i<tamMar; i++)
    {
        printf(" %d   %s\n",mar[i].id, mar[i].descripcion);
    }
}

void ObtenerMarcas(eMarca mar[], int tamMar, int idMarca, char cadena[])
{
    for(int i=0; i<tamMar; i++)
    {
        if(mar[i].id == idMarca)
        {
            //COPIAR LA DESCRIPCION DE LA CADENA
            //DESTINO/ORIGEN
            strcpy(cadena,mar[i].descripcion);

        }
    }
}
