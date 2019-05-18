#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

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

} eMarca;

void harcodeMarcas(eMarca mar[], int tamMar);
void listarMarcas(eMarca mar[], int tamMar);
void ObtenerMarcas(eMarca mar[], int tamMar, int idMarca, char cadena[]);
#endif // MARCA_H_INCLUDED
