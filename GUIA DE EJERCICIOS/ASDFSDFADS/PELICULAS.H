#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[51];
    char pais[51];

}eActores;
typedef struct
{
    int id;
    char nombre[51];

}eGenero;
typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct

{
    int id;
    char titulo[51];
    int idGenero;
    eFecha fechaEstreno;
    int idActor;
    int isEmpty;

}ePeliculas;



int addPeliculas(ePeliculas list[], int tam, eActores actor[], int tamAc, eGenero generos[], int tamGe);
void getFecha(ePeliculas pelicula[], int indice);
int getInt(ePeliculas list[], int indice,char message[],char eMessage[], int lowLimit, int hiLimit);
int initPeliculas(ePeliculas list[],int tam);
int menu();
int menuDos();
int hayPelicula(ePeliculas list[], int tam);
int buscarId(ePeliculas list[], int tam, int id);
void getText(char texto[], char textoError[], char cadena[], int largo);
void mostrarActores(eActores actor[], int tamAc);
void mostrarGeneros(eGenero genero, int tamGe);
int generarId();
int buscarLibre(ePeliculas list[], int tam);
char validarSeguir();
int esNumerico(char str[]);

#endif // #endif // FUNCIONESBASICAS_H_INCLUDED
