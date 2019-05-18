#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "auto.h"
#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"
#include "validaciones.h"

#define VACIO 0
#define OCUPADO 1

#define TAM 10
#define MAR 5
#define COL 5
#define SERV 4
#define TRA 15

int main()
{
    char seguir = 's';
    int flagAuto = 0;
    int flagTrabajo = 0;
    int flagNoTrabajo = 0;

    eAuto autos[TAM];
    eMarca marca[MAR];
    eColor color[COL];
    eServicio servicio[SERV];
    eTrabajo trabajo[TRA];

    //inicializarAutos(autos,TAM);
    //inicializarTrabajo(trabajo,TRA);

    harcodeAutos(autos,TAM);
    harcodeColores(color,COL);
    harcodeMarcas(marca,MAR);
    harcodeServicios(servicio,SERV);
    harcodeTrabajos(trabajo,TRA);

    do
    {
        switch(menu())
        {


        case 1:
            altaAutos(autos,TAM,marca,MAR,color,COL);
            flagAuto = 1;
            flagTrabajo = 1;
            system("pause");
            break;


        case 2:
            if(flagAuto == 1)
            {
            ModificacionAuto(autos,TAM,marca,MAR,color,COL);
            }
            else
            {
                printf("Primero debe dar de Alta un Auto\n");
            }
            system("pause");
            break;


        case 3:
            if(flagAuto == 1)
            {
                bajaAuto(autos,TAM,marca,MAR,color,COL);
            }
            else
            {
                printf("Primero debe dar de Alta un Auto\n");
            }
            system("pause");
            break;


        case 4:

            if(flagAuto == 1)
            {
                listarAutos(autos,TAM,marca,MAR,color,COL);
            }
            else
            {
                printf("Primero debe dar de Alta un Auto\n");
            }
            system("pause");
            break;


        case 5:
            system("cls");
            printf("LISTA MARCAS\n");
            listarMarcas(marca,MAR);
            system("pause");
            break;


        case 6:
            system("cls");
            printf("LISTA COLORES\n");
            listarColores(color,COL);
            system("pause");
            break;


        case 7:
            system("cls");
            printf("LISTA SERVICIOS\n");
            listarServicios(servicio,SERV);
            system("pause");
            break;


        case 8:
            if(flagTrabajo == 1)
            {
                altaTrabajo(trabajo,TRA,autos,TAM,marca,MAR,color,COL,servicio,SERV);
                flagNoTrabajo = 1;
            }
            else
            {
                printf("Primero debe dar de Alta un Auto\n");
            }
            system("pause");
            break;

        case 9:
            if(flagNoTrabajo == 1)
            {
                mostrarTrabajos(trabajo,TRA,autos,TAM,marca,MAR,color,COL,servicio,SERV);
            }
            else
            {
                printf("Primero debe dar de Alta un Trabajo\n");
            }
            system("pause");
            break;


        case 10:
            system("cls");
            printf("Hasta luego");
            seguir = 'n';
            break;


        default:
            printf("\n     Opcion invalida\n\n");
            system("pause");
            break;
        }

    }
    while(seguir == 's');

    return 0;
}
