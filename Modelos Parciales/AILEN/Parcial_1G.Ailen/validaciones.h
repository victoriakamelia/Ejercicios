#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "trabajo.h"

int cargarId();
int cargarIdTrabajo();
char validarSeguir();
int compararFechas(eFecha fech, eFecha fecha);
int validarEntero(char entero[]);
void validarAlfaNum(char x[], int largo);
void ValidarPatente(char x[]);
int validarEnteroRango(char entero[], int corto, int largo);
int validarEnteroTam(char entero[], int largo);
void validarStringTam(char x[], int largo);

#endif // VALIDACIONES_H_INCLUDED
