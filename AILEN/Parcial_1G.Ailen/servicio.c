#include "servicio.h"

void harcodeServicios(eServicio serv[], int tamServ)
{
    eServicio hardcode[]=
    {
        {20000, "Lavado",250},
        {20001, "Pulido",300},
        {20002, "Encerado",400},
        {20003, "Completo",600}

    };

    for(int i=0; i<tamServ; i++)
    {
        serv[i]=hardcode[i];
    }
}

void listarServicios(eServicio serv[], int tamServ)
{
    printf(" ID   Descripcion   Importe\n");
    printf("\n\n");

    for(int i=0; i<tamServ; i++)
    {
        printf(" %d   %s   %d\n",serv[i].id, serv[i].descripcion, serv[i].precio);
    }
}

void ObtenerServicios(eServicio serv[], int tamServ, int idServicio, char cadena[])
{
    for(int i=0; i<tamServ; i++)
    {
        if(serv[i].id == idServicio)
        {
            //COPIAR LA DESCRIPCION DE LA CADENA
            //DESTINO/ORIGEN
            strcpy(cadena,serv[i].descripcion);

        }
    }
}
