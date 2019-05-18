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
    char patente[8];
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

/*AUTOS*/
int addAutos(eAuto list[], int tam, eMarca marca[], int tamMar, eColor colores[], int tamCo);
int buscarIndicePatente(eAuto list[], int tam, char patente[]);
int buscarIndice(eAuto list[], int tam, int id);
int buscarLibre(eAuto list[],int tam);
int hayAuto(eAuto list[], int tam);
int generarId();
int initAutos(eAuto list[],int tam);

void bajaAuto(eAuto list[], int indice);
void listarXmarcaYpatente(eAuto list[], int tam, eMarca marca[], int tamMar, eColor color[], int tamCo, eAuto aux);
void mostrarAuto(eAuto list, eColor colores[], int tamCo,eMarca marcas[], int tamMar);
void mostrarAutos(eAuto list[], int tam, eMarca marcas[], int tamMar, eColor colores[], int tamCo);

/*TRABAJOS*/
int addTrabajo(eAuto list[], int tam, eMarca marca[], int tamMar, eColor colores[], int tamCo, eServicio servicio[], int tamSer, eTrabajo trabajo[], int tamTra);
int buscarLibreT(eTrabajo trabajo[],int tam);
int generarIdTrabajo();
int hayTrabajo(eTrabajo trabajo[], int tamTra);
int initTrabajo(eTrabajo trabajo[],int tamTra);

void getFecha(eTrabajo trabajo[], int indice);
void mostrarTrabajo(eTrabajo trabajo, eAuto list[], int tam, eServicio servicio[], int tamSer);
void mostrarTrabajos(eTrabajo trabajos[], int tamTra, eAuto list[],int tam, eServicio servicio[], int tamSer);

/*MARCAS*/
int buscarIndiceMarca(eMarca marca[], int tamMar, int id);
void mostrarMarcas(eMarca marcas[], int tamMar);

/*COLORES*/
int buscarIndiceColor(eColor colores[], int tamCo, int id);
void mostrarColores(eColor colores[], int tamCo);


/*SERVICIOS*/
int buscarIndiceServicio(eServicio servicio[], int tamSer, int id);
void mostrarServicio(eServicio servicio[], int tamSer);

/*LISTADOS*/

void autoColorNegro(eAuto list[], int tam, eColor colores[], int tamCo, eMarca marcas[], int tamMar, eAuto aux);
void autosDeUnaMarca(eAuto list[], int tam, eColor colores[], int tamCo, eMarca marcas[], int tamMar, eAuto aux);
void trabajoUnAutoSeleccionado(eAuto list[], int tam, eTrabajo trabajo[], int tamTra, eServicio servicio[], int tamSer, eMarca marcas[], int tamMar, eColor colores[], int tamCo, eTrabajo auxTra);
//void autosSinTrabajo(eTrabajo trabajos[], int tamTra, eAuto list[], int tam, eAuto aux, eColor colores[], int tamCo, eMarca marcas[], int tamMar);

void importexAuto(eAuto list[], int tam, eTrabajo trabajo[], int tamTra, eServicio servicio[], int tamSer, eMarca marcas[], int tamMar, eColor colores[], int tamCo);
void ServicioMasPedido(eServicio servicio[], int tamSer, eTrabajo trabajos[], int tamTra);
