#ifndef PELI_H_INCLUDED
#define PELI_H_INCLUDED
#include "Actores.h"
#include "Genero.h"
#include "Fecha.h"
typedef struct

{
    int id;
    char titulo[51];
    int idGenero;
    eFecha fechaEstreno;
    int idActor;
    int isEmpty;

}ePeliculas;

#endif // #endif // FUNCIONESBASICAS_H_INCLUDED

int addPeliculas(ePeliculas list[], int tam, eActores actor[], int tamAc, eGenero generos[], int tamGe);
void getFecha(ePeliculas pelicula[], int indice);
int getInt(char message[],char eMessage[], int lowLimit, int hiLimit);
int initPeliculas(ePeliculas list[],int tam);
int menu();
int menuDos();
int hayPelicula(ePeliculas list[], int tam);
int buscarId(ePeliculas list[], int tam, int id);
void getText(char texto[], char textoError[], char cadena[], int largo);

int generarId();
int buscarLibre(ePeliculas list[], int tam);
char validarSeguir();
int esNumerico(char str[]);
int esSoloLetras(char str[]);
int bajaPelicula(ePeliculas list[],int tam, int id);

void mostrarPelicula(ePeliculas list, eGenero generos[], int tamGe,eActores actor[], int TamAc);
int altaActor(eActores actores[], int tamAc);
int initActores(eActores actores[], int tamAc);
int hayActor(eActores actores[], int tamAc);



int buscarIndiceGenero(eGenero generos[], int tamGe, int id);
void mostrarGeneros(eGenero genero[], int tamGe);

void mostrarActores(eActores actor[], int tamAc);

int buscarIndiceActor(eActores actor[], int TamAc, int id);


