#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "auto.h"
#include "marca.h"
#include "color.h"
#include "servicio.h"

#define VACIO 0
#define OCUPADO 1

#define TAM 10
#define MAR 5
#define COL 5
#define SERV 4
#define TRA 15

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int id;
    char patente[6];
    int idServicio;
    eFecha fechaTrabajo;
    int ocupado;

} eTrabajo;

void inicializarTrabajo(eTrabajo tra[], int tamTra);
int buscarLibreTrabajo(eTrabajo tra[], int tamTra);
int buscarTrabajo(eTrabajo tra[], int tamTra, int idTrabajo);
void altaTrabajo(eTrabajo tra[], int tamTra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ);
void mostrarTrabajo(eTrabajo tra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ);
void mostrarTrabajos(eTrabajo tra[], int tamTra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ);
void harcodeTrabajos(eTrabajo tra[],int tamTra);
#endif // TRABAJO_H_INCLUDED
