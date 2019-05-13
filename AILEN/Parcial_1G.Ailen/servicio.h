#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

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
    char descripcion[20];
    int precio;

} eServicio;

void harcodeServicios(eServicio serv[], int tamServ);
void listarServicios(eServicio serv[], int tamServ);
void ObtenerServicios(eServicio serv[], int tamServ, int idServicio, char cadena[]);
#endif // SERVICIO_H_INCLUDED
