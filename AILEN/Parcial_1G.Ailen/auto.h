#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "marca.h"
#include "color.h"

#define VACIO 0
#define OCUPADO 1

#define TAM 10
#define MAR 5
#define COL 5
#define SERV 4
#define TRA 15

typedef struct
{
    int id;
    char patente[7];
    int idMarca;
    int idColor;
    int modelo;
    int ocupado;

} eAuto;

void inicializarAutos(eAuto aut[], int tamAut);
int menu();
int buscarLibreAuto(eAuto aut[], int tamAut);
int buscarAuto(eAuto aut[], int tamAut, int idAuto);
int buscarPatente(eAuto aut[], int tamAut, int idPatente[]);
void altaAutos(eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol);
void mostrarAuto(eAuto aut, eMarca mar[], int tamMar, eColor col[], int tamCol);
void mostrarAutos(eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol);
void bajaAuto(eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol);
void ModificacionAuto(eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol);
void listarAutos(eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol);
void harcodeAutos(eAuto aut[], int tamAut);
#endif // AUTO_H_INCLUDED
