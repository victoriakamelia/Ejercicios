#ifndef PELI_H_INCLUDED
#define PELI_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int id;
    char descripcion[51];

}eMarca;


typedef struct
{
    int id;
    char nombreColor[20];

}eColor;


typedef struct
{
    int id;
    char patente[7];
    int idMarca;
    int idColor;
    int modeloAnio;
    int isEmpty;

}eAuto;


typedef struct
{
    int id;
    char descricion[20];
    float precio;


}eServicio;

typedef struct

{
    int id;
    char patente[8];
    int idServicio;
    eFecha fecha;
    int isEmpty;


}eTrabajo;

#endif

int addautos(eAuto list[], int tam, eMarca marca[], int tamMar, eColor colores[], int tamCo);
int initautos(eAuto list[],int tam);
void getText(char texto[], char textoError[], char cadena[], int largo);
int hayauto(eAuto list[], int tam);
int menu();
int buscarId(eAuto list[], int tam, int id);
int menuDos();
int generarId();
void getFecha(eTrabajo trabajo[], int indice);
int getInt(char message[],char eMessage[], int lowLimit, int hiLimit);
int esNumerico(char str[]);
char validarSeguir();
int buscarLibre(eAuto list[],int tam);
int esSoloLetras(char str[]);
int bajaauto(eAuto list[],int tam, int id);
void mostrarauto(eAuto list, eColor colores[], int tamCo,eMarca marcas[], int tamMar);
void mostrarMarcas(eMarca marcas[], int tamMar);
int buscarIndiceColor(eColor colores[], int tamCo, int id);
int buscarIndiceMarca(eMarca marca[], int tamMar, int id);
void mostrarColores(eColor colores[], int tamCo);
void getAlpha(char texto[], char textoError[], char cadena[], int largo);
int esAlfa(char str[]);
void mostrarServicio(eServicio servicio[], int tamSer);
int generarIdServicio();
int buscarLibreT(eTrabajo trabajo[],int tam);
int buscarIdPatente(eAuto list[], int tam, char patente[]);
void getFecha(eTrabajo trabajo[], int indice);
int addTrabajo(eAuto list[], int tam, eMarca marca[], int tamMar, eColor colores[], int tamCo, eServicio servicio [], int tamSer, eTrabajo trabajo[], int tamTra);
void listarXmarcaYpatente(eAuto list[], int tam, eMarca marca[], int tamMar, eColor color[], int tamCo, eAuto aux);
void mostarTrabajo(eTrabajo trabajo);




