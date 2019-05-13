#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#define TAM 15
#define SEC 4
#define COM 5
#define ALM 20
#define VACIO 0
#define OCUPADO 1

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int id;
    char descripcion[20];
} eSector;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int ocupado;
    eFecha fecha;
    int sector;
} eEmpleado;

typedef struct
{
    int id;
    char descripcion[20];
    float precio;
} eComida;

typedef struct
{
    int id;
    int idEmpleado;
    int idComida;
    eFecha fecha;
    int ocupado;
} eAlmuerzo;

/*------------------------------------------------------------------------------------------------------------------

                                            PROTOTIPOS

--------------------------------------------------------------------------------------------------------------------*/

int menu();
void inicializarEmpleados(eEmpleado vec[], int tam);
int buscarLibre(eEmpleado vec[], int tam);
int buscarEmpleado(eEmpleado vec[], int tam, int legajo);
void mostrarEmpleado(eEmpleado emp, eSector sec[], int tamSec);
void mostrarEmpleados(eEmpleado vec[], int tam, eSector sec[], int tamSec);
void altaEmpleado(eEmpleado vec[], int tam, eSector sec[], int tamSec);
void bajaEmpleado(eEmpleado vec[], int tam, eSector sec[], int tamSec);
void ModificacionEmpleado(eEmpleado vec[], int tam, eSector sec[], int tamSec);
void harcodeEmpleado(eEmpleado vec[], int tam);
void menuInformes(eEmpleado x[],int tam, eSector sec[], int tamSec, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm);

void harcodeSectores(eSector vec[], int tam);
void listarSectores(eSector x[], int tam);
void mostrarSectores(eSector x[], int tam, int idSector, char cadena[]);

void empleadoXanio(eEmpleado x[],int tam, int anio, eSector sec[], int tamSec);
void listarEmpXsector(eEmpleado x[], int tam, eSector sec[], int tamSec);
void totalEmpxSector(eEmpleado x[], int tam, eSector sec[], int tamSec);
void empXsector(eEmpleado x[], int tam, eSector sec[], int tamSec);
void sectMasEmpleados(eEmpleado x[], int tam, eSector sec[], int tamSec);
void empleadosMasGanadores(eEmpleado x[], int tam, eSector sec[], int tamSec);
void empMasGanadorXsector(eEmpleado x[], int tam, eSector sec[], int tamSec);
void sectorMujeres(eEmpleado x[], int tam, eSector sec[], int tamSec);
void promSector(eEmpleado x[], int tam, eSector sec[], int tamSec);
void menorIgual2009(eEmpleado x[], int tam, eSector sec[], int tamSec);
void mismoSalario(eEmpleado x[], int tam, eSector sec[], int tamSec);
void cantHombres(eEmpleado x[], int tam, eSector sec[], int tamSec);
void empMasPerdedor(eEmpleado x[], int tam, eSector sec[], int tamSec);

void harcodeAlmuerzos(eAlmuerzo x[], int tam);
void harcodeComidas(eComida x[], int tam);
void mostrarComidas(eComida x[], int tam, int idComida, char cadena[]);
void listarComidas(eComida x[], int tam);

void altaAlmuerzo(eEmpleado x[], int tam, eSector sec[], int tamSec, eAlmuerzo alm[], int tamAlm, eComida com[], int tamCom);
int buscarAlmuerzo(eAlmuerzo alm[], int tamAlm, int legajo);
int buscarLibreAlmuerzo(eAlmuerzo x[], int tamAlm);
void inicializarAlmuerzos(eAlmuerzo x[], int tamAlm);
void mostrarAlmuerzos(eAlmuerzo alm[], int tamAlm, eEmpleado emp[], int tam, eComida com[], int tamCom);
void mostrarAlmuerzo(eAlmuerzo alm, eEmpleado emp[], int tam, eComida com[], int tamCom);

void almuerzosXemp(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm, eSector sec[], int tamSec);
void almuerzosXfecha(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm, eSector sec[], int tamSec);
void almuerzosXdescrip(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm, eSector sec[], int tamSec);
void almuerzosXmismaFecha(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm);
void almuerzosXsector(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm, eSector sec[], int tamSec);
void almuerzosMasComido2(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm, eSector sec[], int tamSec);
void totalXfecha(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm, eSector sec[], int tamSec);
void importesEmpleado(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm, eSector sec[], int tamSec);
void AlmuerzosXhombres(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm, eSector sec[], int tamSec);
void AlmuerzosMasComidosXmujeres(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm, eSector sec[], int tamSec);
void empleadosQueNoAlmorzaron(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm, eSector sec[], int tamSec);
void almuerzosEmpMasPerdedor(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm, eSector sec[], int tamSec);
void almuerzoMasComidoXsector(eEmpleado x[], int tam, eSector sec[], int tamSec, eAlmuerzo alm[], int tamAlm, eComida com[], int tamCom);
void almuerzoXcomida(eEmpleado x[], int tam, eSector sec[], int tamSec, eAlmuerzo alm[], int tamAlm, eComida com[], int tamCom);
void almuerzosXmujeres(eEmpleado x[], int tam, eSector sec[], int tamSec, eAlmuerzo alm[], int tamAlm, eComida com[], int tamCom);
void ordenarEmpXsectorYnombre(eEmpleado x[], int tam, eSector sec[], int tamSec);
void contadorComida(eEmpleado x[], int tam, eSector sec[], int tamSec, eAlmuerzo alm[], int tamAlm, eComida com[], int tamCom);

int cargarId();
char validarSeguir();
int compararFechas(eFecha fech, eFecha fecha);
int validarEntero(char entero[]);
void comapunto(char sueldo[]);
float validarFloat(char sueldo[]);
void validarString(char x[]);

/*------------------------------------------------------------------------------------------------------------------

                                                 MAIN

--------------------------------------------------------------------------------------------------------------------*/

int main()
{
    char seguir = 's';
    eEmpleado lista[TAM];
    eSector sector[SEC];
    eComida comida[COM];
    eAlmuerzo almuerzo[ALM];
    harcodeEmpleado(lista,TAM);
    harcodeSectores(sector,SEC);
    harcodeComidas(comida,COM);
    harcodeAlmuerzos(almuerzo,ALM);


    //inicializarEmpleados(lista, TAM); // llamada
    //inicializarAlmuerzos(almuerzo,ALM);


    do
    {
        switch(menu())
        {


        case 1:
            altaEmpleado(lista, TAM, sector, SEC);
            system("pause");
            break;


        case 2:
            bajaEmpleado(lista, TAM, sector, SEC);
            system("pause");
            break;


        case 3:
            ModificacionEmpleado(lista,TAM, sector, SEC);
            system("pause");
            break;


        case 4:
            menuInformes(lista,TAM, sector, SEC, comida, COM, almuerzo, ALM);
            system("pause");
            break;


        case 5:
            mostrarEmpleados(lista, TAM, sector, SEC);
            system("pause");
            break;


        case 6:
            altaAlmuerzo(lista,TAM,sector,SEC,almuerzo,ALM,comida,COM);
            system("pause");
            break;


        case 7:
            mostrarAlmuerzos(almuerzo,ALM,lista,TAM,comida,COM);
            system("pause");
            break;


        case 8:
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

/*------------------------------------------------------------------------------------------------------------------

                                           ABM EMPLEADO

--------------------------------------------------------------------------------------------------------------------*/

void inicializarEmpleados(eEmpleado vec[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        vec[i].ocupado = VACIO;
    }
}



int menu()
{
    int opcion;
    system("cls");
    system("COLOR F0");
    printf("     =================================================\n");
    printf("     #           >>>> MENU DE OPCIONES <<<<          #\n");
    printf("     =================================================\n");
    printf("     |                                               |\n");
    printf("                  1- Alta Empleado                    \n");
    printf("     |                                               |\n");
    printf("                  2- Baja Empleado                    \n");
    printf("     |                                               |\n");
    printf("                  3- Modificacion Empleado            \n");
    printf("     |                                               |\n");
    printf("                  4- Informes                         \n");
    printf("     |                                               |\n");
    printf("                  5- Mostrar Empleados                \n");
    printf("     |                                               |\n");
    printf("                  6- Alta Almuerzos                   \n");
    printf("     |                                               |\n");
    printf("                  7- Mostrar Almuerzos                \n");
    printf("     |                                               |\n");
    printf("                  8- Salir                            \n");
    printf("     |                                               |\n");
    printf("     =================================================\n");
    printf("                                                      \n");
    printf("     Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}



int buscarLibre(eEmpleado vec[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == VACIO)
        {
            indice = i;
            break;
        }
    }

    return indice;
}



int buscarEmpleado(eEmpleado vec[], int tam, int legajo)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].legajo == legajo && vec[i].ocupado == OCUPADO)
        {
            indice = i;
            break;
        }
    }

    return indice;
}



void mostrarEmpleado(eEmpleado emp, eSector sec[], int tamSec)
{
    char cadena[20];

    mostrarSectores(sec,tamSec,emp.sector,cadena);

    printf("     %d   %s   %c    %.2f   %02d/%02d/%d   %s\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo, emp.fecha.dia, emp.fecha.mes, emp.fecha.anio, cadena);

}



void mostrarEmpleados(eEmpleado vec[], int tam, eSector sec[], int tamSec)
{
    int cont= 0;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == OCUPADO)
        {

            mostrarEmpleado(vec[i],sec,tamSec);
            cont++;
        }
    }

    if(cont == 0)
    {
        printf("     No hay empleados que mostrar\n\n");
    }

}



void altaEmpleado(eEmpleado vec[], int tam, eSector sec[], int tamSec)
{
    int indice;
    int idSector;
    char seguir;

    do
    {

        system("cls");
        printf("Alta Empleado\n");
        indice = buscarLibre(vec, tam);


        if(indice == -1)
        {
            printf("No hay lugar\n");
            system("pause");
            break;
        }
        else
        {


            vec[indice].legajo = cargarId();


            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(vec[indice].nombre);


            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &vec[indice].sexo);


            printf("Ingrese sueldo: ");
            scanf("%f", &vec[indice].sueldo);


            printf("Ingrese dia de ingreso: ");
            scanf("%d",&vec[indice].fecha.dia);


            printf("Ingrese dia de ingreso: ");
            scanf("%d",&vec[indice].fecha.mes);


            printf("Ingrese dia de ingreso: ");
            scanf("%d",&vec[indice].fecha.anio);


            listarSectores(sec,tamSec);


            printf("Ingrese ID Sector: ");
            scanf("%d",&idSector);


            vec[indice].sector = idSector;


            vec[indice].ocupado = OCUPADO;


            printf("\nEl empleado ha sido registrado con exito!!!\n\n");

            printf("\n\n");

            seguir = validarSeguir();

        }

    }
    while(seguir == 'S' || seguir == 's');

}



void bajaEmpleado(eEmpleado vec[], int tam, eSector sec[], int tamSec)
{

    int legajo;
    char seguir;
    int esta;

    printf("Baja Empleado\n");
    printf("\n\n");
    mostrarEmpleados(vec,tam,sec,tamSec);


    printf("Ingrese legajo: ");
    scanf("%d", &legajo);
    printf("\n\n");


    esta = buscarEmpleado(vec, tam, legajo);


    if( esta == -1)
    {

        printf("\nEl legajo %d no esta registrado en el sistema\n", legajo);
    }
    else
    {
        printf("Empleado a eliminar\n");
        mostrarEmpleado(vec[esta],sec,tamSec);

        seguir = validarSeguir();

        if(seguir == 's' || seguir == 'S')
        {
            vec[esta].ocupado = VACIO;
            printf("\nEmpleado eliminado con exito\n");
        }
        else
        {
            printf("\nLa eliminacion ha sido cancelada\n");
        }

    }

}



void ModificacionEmpleado(eEmpleado vec[], int tam, eSector sec[], int tamSec)
{

    int legajo;
    float sueldo;
    char nombre[20];
    int opcion;
    int esta;
    char seguir;

    printf("Modificacion Empleado\n");
    printf("\n\n");
    mostrarEmpleados(vec,tam,sec,tamSec);


    printf("Ingrese legajo: ");
    scanf("%d", &legajo);


    esta = buscarEmpleado(vec, tam, legajo);


    if( esta == -1)
    {

        printf("\nEl legajo %d no esta registrado en el sistema\n", legajo);
    }
    else
    {
        printf("\n\n");
        printf("Empleado a modificar\n");
        mostrarEmpleado(vec[esta],sec,tamSec);

        printf("     Que desea modificar?\n");
        printf("     1. Nombre\n     2. Sueldo\n");
        printf("     Ingrese opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            system("cls");

            printf("Modificar Nombre\n");

            printf("Ingrese nuevo nombre: ");
            fflush(stdin);
            gets(nombre);

            seguir = validarSeguir();

            if(seguir == 's' || seguir == 'S')
            {

                strcpy(vec[esta].nombre,nombre);

                printf("\n\n");
                printf("     Modificacion exitosa!\n");

            }
            else
            {
                printf("\n\n");
                printf("     Modificacion cancelada\n");
            }
            break;

        case 2:
            system("cls");

            printf("Modificar Sueldo\n");

            printf("Ingrese nuevo sueldo: ");
            fflush(stdin);
            scanf("%f",&sueldo);

            seguir = validarSeguir();

            if(seguir == 's' || seguir == 'S')
            {

                vec[esta].sueldo = sueldo;

                printf("\n\n");
                printf("     Modificacion exitosa!\n");

            }
            else
            {
                printf("\n\n");
                printf("     Modificacion cancelada\n");
            }
            break;

        default:
            printf("Esta opcion no existe\n");
            break;

        }
    }

}



void menuInformes(eEmpleado x[],int tam, eSector sec[], int tamSec, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm)
{
    char seguir = 's';
    int opcion;
    int anio;

    do
    {

        system("cls");
        printf("1- Mostrar Empleados Por Anio\n");
        printf("2- Mostrar Empleados de un Sector\n");
        printf("3- Cantidad de Empleados x Sector\n");
        printf("4- Empleados x Sector\n");
        printf("5- Sectores con mas empleados\n");
        printf("6- Empleados que mas ganan x Sector\n");
        printf("7- Sectores con Mujeres\n");
        printf("8- Promedio y Total de Salarios de un Sector\n");
        printf("9- Nacidos <= 2009\n");
        printf("10- Cant de Comidas Comidas\n");
        printf("11- Cant de Hombres x Sector\n");
        printf("12- Empleado que menos gana\n");
        printf("13- Almuerzos x Empleado\n");
        printf("14- Almuerzos x Fecha\n");
        printf("15- Mostrar Empleados sg la descripcion comida\n");
        printf("16- Mostrar Almuerzos del mismo Dia\n");
        printf("17- Mostrar el almuerzo mas comido\n");
        printf("18- Almuerzos x Sector\n");
        printf("19- Clientes que no comieron\n");
        printf("20- Almuerzos x Hombres\n");
        printf("21- Comidas + comidas x Mujeres\n");
        printf("22- Almuerzos de los empleados mas perdedores\n");
        printf("23- Importes pagados x Cliente\n");
        printf("24- Recaudacion x Fecha\n");
        printf("25- Mostrar Empleados sg ID Comida\n");
        printf("26- Mostrar mujeres sg comida\n");
        printf("27- Almuerzo mas Comido x Sector\n");
        printf("28- Listar Empleados x Sector/Nombre\n");
        printf("29- Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {

        case 1:
            printf("\n\n");
            printf("Ingrese anio a buscar: ");
            scanf("%d",&anio);

            empleadoXanio(x,tam,anio,sec,tamSec);
            break;

        case 2:
            listarEmpXsector(x,tam,sec,tamSec);
            break;

        case 3:
            totalEmpxSector(x,tam,sec,tamSec);
            break;

        case 4:
            empXsector(x,tam,sec,tamSec);
            break;

        case 5:
            sectMasEmpleados(x,tam,sec,tamSec);
            break;

        case 6:
            empMasGanadorXsector(x,tam,sec,tamSec);
            break;

        case 7:
            sectorMujeres(x,tam,sec,tamSec);
            break;

        case 8:
            promSector(x,tam,sec,tamSec);
            break;

        case 9:
            menorIgual2009(x,tam,sec,tamSec);
            break;

        case 10:
            contadorComida(x,tam,sec,tamSec,alm,tamAlm,com,tamCom);
            break;

        case 11:
            cantHombres(x,tam,sec,tamSec);
            break;

        case 12:
            empMasPerdedor(x,tam,sec,tamSec);
            break;

        case 13:
            almuerzosXemp(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;

        case 14:
            almuerzosXfecha(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;

        case 15:
            almuerzosXdescrip(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;

        case 16:
            almuerzosXmismaFecha(x,tam,com,tamCom,alm,tamAlm);
            break;

        case 17:
            almuerzosMasComido2(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;

        case 18:
            almuerzosXsector(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;

        case 19:
            empleadosQueNoAlmorzaron(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;

        case 20:
            AlmuerzosXhombres(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;

        case 21:
            AlmuerzosMasComidosXmujeres(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;

        case 22:
            almuerzosEmpMasPerdedor(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;

        case 23:
            importesEmpleado(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;

        case 24:
            totalXfecha(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;


        case 25:
            almuerzoXcomida(x,tam,sec,tamSec,alm,tamAlm,com,tamCom);
            break;


        case 26:
            almuerzosXmujeres(x,tam,sec,tamSec,alm,tamAlm,com,tamCom);
            break;


        case 27:
            almuerzoMasComidoXsector(x,tam,sec,tamSec,alm,tamAlm,com,tamCom);
            break;


        case 28:
            ordenarEmpXsectorYnombre(x,tam,sec,tamSec);
            break;

        case 29:
            seguir = 'n';
            break;

        default:
            printf("\n Opcion invalida\n\n");
            system("break");
        }

        system("pause");
        system("cls");
    }
    while(seguir == 's');
}

void empleadoXanio(eEmpleado x[],int tam, int anio, eSector sec[], int tamSec)
{
    int cont=0;

    for(int i=0; i<tam; i++)
    {
        if(x[i].ocupado == OCUPADO && x[i].fecha.anio == anio)
        {
            cont++;
            mostrarEmpleado(x[i],sec,tamSec);
        }
    }

    if(cont == 0)
    {
        printf("No hay empleados que buscar\n");
    }

}

void listarEmpXsector(eEmpleado x[], int tam, eSector sec[], int tamSec)
{
    int idSector;
    int flag = 0;

    system("cls");
    printf("  *** Listado de Sectores ***\n\n");

    listarSectores(sec,tamSec);
    printf("\n\n");

    printf("Ingrese ID Sector: ");
    scanf("%d",&idSector);

    for(int i=0; i<tam; i++)
    {
        if(x[i].sector == idSector && x[i].ocupado == OCUPADO)
        {
            mostrarEmpleado(x[i],sec,tamSec);

            flag = 1;

        }
    }


    if(flag == 0)
    {
        printf("No hay empleados que mostrar en este sector\n");
    }

}



void totalEmpxSector(eEmpleado x[], int tam, eSector sec[], int tamSec)
{

    int cont = 0;

    for(int i=0; i<tamSec; i++)
    {

        printf("Sector: %s\n",sec[i].descripcion);

        cont = 0;

        for(int j=0; j<tam; j++)
        {
            if(x[j].sector == sec[i].id && x[j].ocupado == OCUPADO)
            {
                cont++;
            }
        }

        printf("Cant de Empleados: %d\n\n",cont);

    }

    if(cont == 0)
    {
        printf("No hay empleados que contar\n");
    }

}



void empXsector(eEmpleado x[], int tam, eSector sec[], int tamSec)
{

    int flag = 0;

    for(int i=0; i<tamSec; i++)
    {

        printf("Sector: %s\n",sec[i].descripcion);

        for(int j=0; j<tam; j++)
        {

            if(x[j].sector == sec[i].id && x[j].ocupado == OCUPADO)
            {
                mostrarEmpleado(x[j],sec,tamSec);
                flag = 1;
            }

        }
    }


    if(flag == 0)
    {
        printf("No hay empleados que mostrar\n");
    }

}



void sectMasEmpleados(eEmpleado x[], int tam, eSector sec[], int tamSec)
{
    int mayor;
    int totales[tamSec];
    int flag = 0;


    for(int i=0; i<tamSec; i++)
    {
        totales[i] = 0;

        for(int j=0; j<tam; j++)
        {
            if(x[j].sector == sec[i].id && x[j].ocupado == OCUPADO)
            {
                totales[i]++;
            }
        }
    }


    for(int i=0; i<tamSec; i++)
    {

        if(flag == 0  || totales[i]>mayor)
        {
            mayor = totales[i];
            flag = 1;
        }
    }


    printf("Cant mayor de empleados %d\n",mayor);


    for(int i=0; i<tamSec; i++)
    {
        if(totales[i] == mayor)
        {
            printf("Sector/es %s\n",sec[i].descripcion);
        }
    }

}



void empMasGanadorXsector(eEmpleado x[], int tam, eSector sec[], int tamSec)
{
    float mayor;
    int flag;

    for(int i=0; i<tamSec; i++)
    {
        flag = 0;
        mayor = 0;

        for(int j=0; j<tam; j++)
        {

            if( (x[j].sueldo > mayor || flag ==0) && x[j].sector == sec[i].id && x[j].ocupado == OCUPADO )
            {
                mayor = x[j].sueldo;
            }

        }


        for(int j=0; j<tam; j++)
        {
            if(x[j].sueldo == mayor && x[j].ocupado == OCUPADO && x[j].sector == sec[i].id )
            {
                mostrarEmpleado(x[j],sec,tamSec);
            }
        }
    }


}



void sectorMujeres(eEmpleado x[], int tam, eSector sec[], int tamSec)
{
    int flag = 0;

    for(int i=0; i<tamSec; i++)
    {

        for(int j=0; j<tam; j++)
        {
            if(x[j].ocupado == OCUPADO && x[j].sector == sec[i].id && x[j].sexo == 'f')
            {
                printf("Sector: %s\n",sec[i].descripcion);
                mostrarEmpleado(x[j],sec,tamSec);
                flag = 1;

            }
        }
    }


    if(flag == 0)
    {
        printf("No hay ninguna mujer\n");
    }

}



void promSector(eEmpleado x[], int tam, eSector sec[], int tamSec)
{
    int idSector;
    float prom;
    int flag=0;
    int cont=0;
    float acum=0;


    system("cls");
    printf("  *** Listado de Sectores ***\n\n");


    listarSectores(sec,tamSec);
    printf("\n\n");
    printf("Ingrese ID Sector: ");
    scanf("%d",&idSector);


    for(int i=0; i<tam; i++)
    {
        if(x[i].sector == idSector && x[i].ocupado == OCUPADO)
        {
            flag = 1;
            cont++;
            acum+=x[i].sueldo;
        }
    }


    if(flag == 0)
    {
        printf("Sector Vacio\n");
    }
    else
    {
        prom = acum/cont;


        printf("La suma total de los salarios de este sector es %.2f y el promedio es de %.2f\n",acum,prom);
    }
}



void menorIgual2009(eEmpleado x[], int tam, eSector sec[], int tamSec)
{
    int flag = 0;

    for(int i=0; i<tamSec; i++)
    {
        for(int j=0; j<tam; j++)
        {
            if(x[j].fecha.anio <=2009 && x[j].sector == sec[i].id && x[j].ocupado == OCUPADO)
            {
                printf("Sector: %s\n",sec[i].descripcion);
                mostrarEmpleado(x[j],sec,tamSec);
                flag = 1;
            }
        }
    }


    if(flag == 0)
    {
        printf("No hay ningun empleado con el anio <=2009");
    }

}



void mismoSalario(eEmpleado x[], int tam, eSector sec[], int tamSec)
{
    float mismo;
    int flag;


    for(int i=0; i<tamSec; i++)
    {
        flag = 0;
        mismo = 0;


        printf("%d",i);
        printf("flag: %d\n",flag);
        printf("mismo: %d\n",mismo);


        for(int j=0; j<tam; j++)
        {
            if( (x[j].sueldo == mismo || flag == 0) && x[j].ocupado == OCUPADO && x[j].sector == sec[i].id)
            {
                mismo = x[j].sueldo;
                printf("acumulador: %f\n",mismo);
                flag = 1;


            }
        }


        if(flag == 0)
        {
            printf("Ningun empleado tiene el mismo salario\n");
            break;
        }


        else
        {
            for(int j=0; j<tam; j++)
            {
                if(x[j].sueldo == mismo && x[j].ocupado == OCUPADO)
                {
                    printf("%f",mismo);
                    mostrarEmpleado(x[j],sec,tamSec);


                }
            }
        }


        printf("i: ", i);
    }
}



void cantHombres(eEmpleado x[], int tam, eSector sec[], int tamSec)
{
    int cont = 0;

    for(int i=0; i<tamSec; i++)
    {


        for(int j=0; j<tam; j++)
        {
            if(x[j].sector == sec[i].id && x[j].ocupado == OCUPADO && x[j].sexo == 'm')
            {
                cont++;
            }
        }

    }


    printf("\n\n");
    printf("Total de hombres x Sector: %d\n\n",cont);

    if(cont == 0)
    {
        printf("No hay ningun hombre\n");
    }

}



void empMasPerdedor(eEmpleado x[], int tam, eSector sec[], int tamSec)
{
    float menor;
    int flag=0;

    for(int i=0; i<tamSec; i++)
    {
        menor = 0;

        for(int j=0; j<tam; j++)
        {

            if( (x[j].sueldo < menor || flag == 0) && x[j].sector == sec[i].id && x[j].ocupado == OCUPADO )
            {
                menor = x[j].sueldo;
                flag = 1;
            }

        }

        for(int j=0; j<tam; j++)
        {
            if(x[j].sueldo == menor && x[j].ocupado == OCUPADO && x[j].sector == sec[i].id )
            {
                mostrarEmpleado(x[j],sec,tamSec);
            }
        }

    }

}


void ordenarEmpXsectorYnombre(eEmpleado x[], int tam, eSector sec[], int tamSec)
{
    char descI[20];
    char descJ[20];
    eEmpleado aux;


    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            mostrarSectores(sec,tamSec,x[i].sector,descI);
            mostrarSectores(sec,tamSec,x[j].sector,descJ);


            if(strcmp(descI,descJ)>0)
            {
                aux = x[i];
                x[i] = x[j];
                x[j] = aux;
            }
            else if(strcmp(descI,descJ)==0 && strcmp(x[i].nombre,x[j].nombre)>0)
            {
                aux = x[i];
                x[i] = x[j];
                x[j] = aux;
            }
        }
    }


    mostrarEmpleados(x,tam,sec,tamSec);
}

/*------------------------------------------------------------------------------------------------------------------

                                       HARCODEOS/OBTENER

--------------------------------------------------------------------------------------------------------------------*/

void harcodeEmpleado(eEmpleado vec[], int tam)
{
    eEmpleado hardcode[]=
    {
        {1234, "Juan", 'm', 30000,1,{12,3,2000}, 4},
        {2222, "Ana", 'f', 28000,1, {2,7,2010},1},
        {2211, "Jorge", 'm', 28000,1,{14,5,2013},1},
        {3241, "Alberto", 'm', 35000,1, {2,9,2010},2},
        {8944, "Sonia", 'f', 39000,1, {12,3,2012},2},
        {2231, "Miguel", 'm', 29700,1, {28,7,2009},2},
        {6578, "Adrian", 'm', 43200,1, {11,1,2016}, 3},
        {3425, "Carolina", 'f', 32300,1, {19,10,2004},3},
        {7654, "Diego", 'm', 35000,0, {23,6,2010}, 2},
        {3456, "Mirta", 'f', 30000,1, {2,7,2009},1},
        {4567, "Ximena", 'f', 35000,1, {2,9,1995},2},
        {8900, "Ailen", 'f', 39000,1, {12,3,1996},2},
        {6599, "Silvia", 'f', 43200,1, {11,1,2017}, 3},
        {3234, "Brisa", 'f', 32300,0, {19,10,2003},3},
        {7623, "Juan Carlos", 'm', 35000,0, {23,6,2011}, 2}
    };


    for(int i=0; i<tam; i++)
    {
        vec[i]=hardcode[i];
    }
}

void harcodeSectores(eSector vec[], int tam)
{
    eSector hardcode[]=
    {
        {1, "RR.HH"},
        {2, "Contabilidad"},
        {3, "Sistemas"},
        {4, "Ventas"}
    };

    for(int i=0; i<tam; i++)
    {
        vec[i]=hardcode[i];
    }

}



void listarSectores(eSector x[], int tam)
{
    printf(" ID   Descripcion\n");
    printf("\n\n");

    for(int i=0; i<tam; i++)
    {
        printf(" %d   %s\n",x[i].id,x[i].descripcion);
    }
}



void mostrarSectores(eSector x[], int tam, int idSector, char cadena[])
{
    for(int i=0; i<tam; i++)
    {
        if(x[i].id == idSector)
        {
            //COPIAR LA DESCRIPCION DE LA CADENA
            //DESTINO/ORIGEN
            strcpy(cadena,x[i].descripcion);

        }
    }
}



void harcodeComidas(eComida x[], int tam)
{
    eComida hardcode[]=
    {
        {1, "Milanesa",80},
        {2, "Pescado",90},
        {3, "Tortilla",100},
        {4, "Salmon",150},
        {5, "Empanadas",105}

    };

    for(int i=0; i<tam; i++)
    {
        x[i]=hardcode[i];
    }
}

void listarComidas(eComida x[], int tam)
{
    printf(" ID   Descripcion\n");
    printf("\n\n");

    for(int i=0; i<tam; i++)
    {
        printf(" %d   %s %.2f\n",x[i].id,x[i].descripcion, x[i].precio);
    }

}



void mostrarComidas(eComida x[], int tam, int idComida, char cadena[])
{
    for(int i=0; i<tam; i++)
    {
        if(x[i].id == idComida)
        {
            //COPIAR LA DESCRIPCION DE LA CADENA
            //DESTINO/ORIGEN
            strcpy(cadena,x[i].descripcion);
        }
    }
}



void harcodeAlmuerzos(eAlmuerzo x[], int tam)
{
    eAlmuerzo hardcode[]=
    {
        {100,1234,1,{12,4,2019},0},
        {101,2222,3,{13,4,2019},1},
        {102,2211,2,{13,4,2019},1},
        {103,3241,4,{15,4,2019},1},
        {104,8944,5,{13,4,2019},1},
        {105,2231,1,{17,4,2019},1},
        {106,6578,3,{17,4,2019},1},
        {107,3425,5,{17,4,2019},0},
        {108,8944,4,{24,4,2019},1},
        {109,7654,2,{25,4,2019},1},
        {110,8944,1,{12,4,2019},1},
        {111,3456,3,{13,4,2019},1},
        {112,8944,2,{13,4,2019},1},
        {113,4567,4,{15,4,2019},1},
        {114,8900,5,{26,4,2019},1},
        {115,1234,2,{17,4,2019},1},
        {116,6599,3,{17,4,2019},1},
        {117,3234,5,{17,4,2019},1},
        {118,1234,4,{20,4,2019},1},
        {119,7623,2,{21,4,2019},1}
    };

    for(int i=0; i<tam; i++)
    {
        x[i]=hardcode[i];
    }
}

/*------------------------------------------------------------------------------------------------------------------

                                ALTA ALMUERZOS

--------------------------------------------------------------------------------------------------------------------*/

void inicializarAlmuerzos(eAlmuerzo x[], int tamAlm)
{

    for(int i=0; i < tamAlm; i++)
    {
        x[i].ocupado = VACIO;
    }
}



int buscarLibreAlmuerzo(eAlmuerzo x[], int tamAlm)
{

    int indice = -1;

    for(int i=0; i < tamAlm; i++)
    {
        if(x[i].ocupado == VACIO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}



int buscarAlmuerzo(eAlmuerzo alm[], int tamAlm, int legajo)
{
    int indice= -1;

    for(int i=0; i<tamAlm; i++)
    {
        if(alm[i].id == legajo && alm[i].ocupado == OCUPADO)
        {
            indice = i;
            break;
        }
    }

    return indice;

}



void altaAlmuerzo(eEmpleado x[], int tam, eSector sec[], int tamSec, eAlmuerzo alm[], int tamAlm, eComida com[], int tamCom)
{
    int id;
    int idComida;
    int indice;
    char seguir;
    eFecha fecha;

    do
    {

        system("cls");
        printf("Alta Almuerzo\n");


        indice = buscarLibreAlmuerzo(alm,tamAlm);




        if(indice == -1)
        {
            printf("No hay mas espacio para cargar almuerzos\n");
            printf("\n\n");
            system("pause");
            break;
        }
        else
        {
            alm[indice].id = cargarId();


            mostrarEmpleados(x,tam,sec,tamSec);


            printf("Ingrese ID Empleado: ");
            scanf("%d",&id);


            alm[indice].idEmpleado = id;


            listarComidas(com,tamCom);
            printf("Ingrese ID Comida: ");
            scanf("%d",&idComida);


            alm[indice].idComida = idComida;


            printf("Ingrese fecha de Almuerzo\n");
            printf("dd/mm/aaaa: ");
            scanf("%d %d %d",&fecha.dia,&fecha.mes,&fecha.anio);


            alm[indice].fecha = fecha;


            alm[indice].ocupado = OCUPADO;


            printf("El Almuerzo se ha registrado con exito!!\n");


            seguir = validarSeguir();

        }
    }
    while(seguir == 'S' || seguir == 's');
}

void mostrarAlmuerzo(eAlmuerzo alm, eEmpleado emp[], int tam, eComida com[], int tamCom)
{
    char nombre[20];
    char comida[20];
    float precio;
    int loMuestro;

    for(int i=0; i<tam; i++)
    {
        if(emp[i].legajo == alm.idEmpleado)
        {
            strcpy(nombre,emp[i].nombre);
            loMuestro = emp[i].ocupado;
            break;
        }
    }

    for(int j=0; j<tamCom; j++)
    {
        if(com[j].id == alm.idComida)
        {
            strcpy(comida,com[j].descripcion);
            precio = com[j].precio;
            break;
        }
    }

    if(loMuestro)
    {
        printf("%4d %d %10s %10s %02d/%02d/%d %.2f\n", alm.id, alm.idEmpleado, nombre, comida, alm.fecha.dia, alm.fecha.mes, alm.fecha.anio, precio);
    }

}



void mostrarAlmuerzos(eAlmuerzo alm[], int tamAlm, eEmpleado emp[], int tam, eComida com[], int tamCom)
{
    int flag = 0;


    system("cls");
    printf("  ID   Legajo   Nombre  Comida  Fecha\n\n");


    for(int i=0; i<tamAlm; i++)
    {
        if(alm[i].ocupado == OCUPADO)
        {
            mostrarAlmuerzo(alm[i],emp,tam,com,tamCom);
            flag = 1;
        }
    }


    if(flag == 0)
    {
        printf("No hay almuerzos cargados\n");
    }

}

void almuerzosXemp(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm, eSector sec[], int tamSec)
{
    int legajo;
    int flag = 0;

    system("cls");

    mostrarEmpleados(x,tam,sec,tamSec);

    printf("Ingrese el legajo  a buscar: ");
    scanf("%d",&legajo);

    printf("\n\n");

    printf("ALMUERZOS DEL EMPLEADO %d\n",legajo);

    for(int i=0; i<tamAlm; i++)
    {
        if(alm[i].idEmpleado == legajo && alm[i].ocupado == OCUPADO)
        {
            for(int k=0; k<tamCom; k++)
            {
                if(alm[i].idComida == com[k].id)
                {
                    printf("%d %10s\n",alm[i].id,com[k].descripcion);
                    flag = 1;




                }
            }
        }
    }



    if(flag == 0)
    {
        printf("Este empleado no tiene ningun almuerzo registrado\n");
    }

}



void almuerzosXfecha(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm, eSector sec[], int tamSec)
{

    int flag = 0;
    eFecha fecha;

    system("cls");

    printf("Ingrese fecha de ingreso dd/mm/aaaa: ");
    scanf("%d %d %d", &fecha.dia, &fecha.mes, &fecha.anio);

    for(int i=0; i<tamAlm; i++)
    {
        for(int j=0; j<tam; j++)
        {
            if(compararFechas(alm[i].fecha,fecha) && alm[i].idEmpleado == x[j].legajo && x[j].ocupado == OCUPADO && alm[i].ocupado == OCUPADO)
            {


                flag = 1;
                mostrarAlmuerzo(alm[i],x,tam,com,tamCom);
                break;


            }
        }
    }

    if(flag == 0)
    {
        printf("Ningun empleado almorzo este dia\n");
    }


}



void almuerzosXdescrip(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm, eSector sec[], int tamSec)
{
    char descrip[20];
    int flag = 0;

    system("cls");

    listarComidas(com,tamCom);

    printf("Ingrese la comida a buscar: ");
    fflush(stdin);
    gets(descrip);

    printf("\n\n");

    for(int i=0; i<tamAlm; i++)
    {
        for(int j=0; j<tam; j++)
        {
            for(int k=0; k<tamCom; k++)
            {
                if(x[j].ocupado == OCUPADO && x[j].legajo == alm[i].idEmpleado && alm[i].ocupado == OCUPADO && stricmp(com[k].descripcion,descrip)==0 && com[k].id == alm[i].idComida)
                {
                    flag = 1;
                    mostrarEmpleado(x[j],sec,tamSec);
                }
            }
        }
    }


    if(flag == 0)
    {
        printf("Nadie almorzo esta comida\n");
    }

}



void almuerzosXmismaFecha(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm)
{
    int flag = 0;

    for(int i=0; i<tamAlm; i++)
    {
        //alm[i].fecha.dia == alm[i].fecha.dia && alm[i].fecha.mes == alm[i].fecha.mes && alm[i].fecha.anio == alm[i].fecha.anio
        if(compararFechas(alm[i].fecha, alm[i].fecha))
        {
            for(int j=0; j<tam; j++)
            {
                if(x[j].ocupado == OCUPADO && x[j].legajo == alm[i].idEmpleado && alm[i].ocupado == OCUPADO)
                {
                    mostrarAlmuerzo(alm[j],x,tam,com,tamCom);
                    flag = 1;
                }
            }
        }
    }


    if(flag == 0)
    {
        printf("Nadie almorzo la misma fecha\n");
    }

}


void almuerzosXsector(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm, eSector sec[], int tamSec)
{
    int sector;
    int flag = 0;

    listarSectores(sec,tamSec);

    printf("Ingrese ID Sector:");
    scanf("%d",&sector);


    for(int i=0; i<tam; i++)
    {
        if(x[i].sector == sector && x[i].ocupado == OCUPADO)
        {
            for(int j=0; j<tamAlm; j++)
            {
                if(alm[j].idEmpleado == x[i].legajo && alm[i].ocupado == OCUPADO)
                {
                    for(int k=0; k<tamCom; k++)
                    {
                        if(alm[j].idComida == com[k].id)
                        {
                            printf("%s %s %0d/%0d/%d\n",x[i].nombre,com[k].descripcion,alm[j].fecha);
                            flag = 1;
                            break;
                        }
                    }




                }
            }
        }
    }



    if(flag == 0)
    {
        printf("Nadie en este sector almorzo\n");
    }
}



void almuerzosMasComido2(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm, eSector sec[], int tamSec)
{
    int cont[tamCom];
    int flag = 0;
    int mayor;

    for(int i=0; i<tamCom; i++)
    {
        cont[i] = 0;

        for(int j=0; j<tamAlm; j++)
        {
            if(com[i].id == alm[j].idComida && alm[i].ocupado == OCUPADO)
            {
                for(int k=0; k<tam; k++)
                {
                    if(x[k].ocupado == OCUPADO && x[k].legajo == alm[j].idEmpleado)
                    {
                        cont[i]++;




                    }
                }
            }
        }
    }


    for(int i=0; i<tamCom; i++)
    {
        if(flag == 0 || cont[i]>mayor)
        {
            mayor =  cont[i];

            flag = 1;
        }
    }


    printf("Comida mas pedida por los empleados:\n");


    for(int i=0; i<tamCom; i++)
    {
        if(cont[i] == mayor)
        {
            printf("%s\n",com[i].descripcion);
        }
    }
}



void almuerzosEmpMasPerdedor(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm, eSector sec[], int tamSec)
{
    int flag=0;
    int menor=0;


    for(int i=0; i<tam; i++)
    {
        for(int j=0; j<tamAlm; j++)
        {


            if(x[i].legajo == alm[j].idEmpleado && x[i].ocupado == OCUPADO && alm[j].ocupado == OCUPADO && (x[i].sueldo < menor || flag == 0))
            {
                for(int k=0; k<tamCom; k++)
                {
                    if(alm[j].idComida == com[k].id)
                    {
                        menor = x[i].sueldo;
                        flag = 1;
                    }
                }
            }
        }
    }



    for(int i=0; i<tam; i++)
    {
        for(int j=0; j<tamAlm; j++)
        {
            if(x[i].sueldo == menor && x[i].ocupado == OCUPADO && x[i].legajo == alm[j].idEmpleado && alm[j].ocupado == OCUPADO)
            {
                mostrarAlmuerzo(alm[j],x,tam,com,tamCom);
            }
        }
    }
}



void empleadosQueNoAlmorzaron(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm, eSector sec[], int tamSec)
{
    int flag;

    for(int i=0; i<tam; i++)
    {
        flag = 0;

        for(int j=0; j<tamAlm; j++)
        {
            if(x[i].legajo == alm[j].idEmpleado && x[i].ocupado == 1 && alm[j].ocupado == OCUPADO)
            {
                for(int k=0; k<tamCom; k++)
                {
                    if(com[k].id == alm[j].idComida)
                    {
                        flag = 1;
                        break;
                    }
                }
            }
        }


        if(flag == 0 && x[i].ocupado == OCUPADO)
        {
            printf("Empleados que no almorzaron\n");

            mostrarEmpleado(x[i],sec,tamSec);


        }

    }


    if(flag == 1)
    {
        printf("Todos los empleados almorzaron\n");
    }

}



void AlmuerzosMasComidosXmujeres(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm, eSector sec[], int tamSec)
{
    int mayor;
    int flag=0;
    int mujeres[tamCom];


    for(int i=0; i<tamCom; i++)
    {
        mujeres[i] = 0;


        for(int j=0; j<tamAlm; j++)
        {
            if(com[i].id == alm[j].idComida && alm[j].ocupado == OCUPADO)
            {
                for(int k=0; k<tam; k++)
                {
                    if(x[k].ocupado == OCUPADO && x[k].sexo == 'f' && x[k].legajo == alm[j].idEmpleado)
                    {
                        mujeres[i]++;
                    }
                }

            }
        }
    }


    for(int i=0; i<tamCom; i++)
    {
        if(mujeres[i] > mayor || flag == 0)
        {
            mayor = mujeres[i];

            flag = 1;
        }
    }


    printf("Almuerzos + comidos por Mujeres:\n");


    for(int i=0; i<tam; i++)
    {
        if(mujeres[i] == mayor)
        {
            printf("%s\n",com[i].descripcion);
        }
    }
}



void AlmuerzosXhombres(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm, eSector sec[], int tamSec)
{
    int flag = 0;

    for(int i=0; i<tamAlm; i++)
    {
        for(int j=0; j<tam; j++)
        {
            if(x[j].legajo == alm[i].idEmpleado && x[j].ocupado == OCUPADO && x[j].sexo == 'm' && alm[i].ocupado == OCUPADO)
            {
                for(int k=0; k<tamCom; k++)
                {
                    if(com[k].id == alm[i].idComida)
                    {
                        mostrarAlmuerzo(alm[i],x,tam,com,tamCom);
                        flag = 1;
                    }
                }
            }
        }
    }

    if(flag == 0)
    {
        printf("No hay almuerzos registrados\n");
    }
}



void importesEmpleado(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm, eSector sec[], int tamSec)
{
    float total = 0;
    int flag = 0;
    int legajo;


    mostrarEmpleados(x,tam,sec,tamSec);


    printf("Ingrese el legajo a buscar el importe: ");
    scanf("%d",&legajo);


    for(int i=0; i<tamAlm; i++)
    {
        if(alm[i].idEmpleado == legajo && alm[i].ocupado == OCUPADO)
        {
            for(int j=0; j<tamCom; j++)
            {
                if(alm[i].idComida == com[j].id)
                {
                    total+=com[j].precio;
                    flag = 1;
                    break;
                }
            }
        }
    }


    if(flag == 0)
    {
        printf("Este empleado no ha almorzado nada\n");
    }
    else
    {
        printf("Importe total: %.2f\n",total);
    }
}



void totalXfecha(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm, eSector sec[], int tamSec)
{
    float total = 0;
    int flag = 0;

    eFecha fecha;

    printf("Ingrese fecha aa/mm/aaaa: ");
    scanf("%d %d %d",&fecha.dia,&fecha.mes,&fecha.anio);


    for(int i=0; i<tamAlm; i++)
    {
        if(compararFechas(alm[i].fecha,fecha))
        {
            for(int j=0; j<tam; j++)
            {
                if(x[j].ocupado == OCUPADO && x[j].legajo == alm[i].idEmpleado && alm[i].ocupado == OCUPADO)
                {
                    for(int k=0; k<tamCom; k++)
                    {
                        if(com[k].id == alm[i].idComida)
                        {
                            total+=com[k].precio;
                            flag = 1;
                            break;
                        }
                    }
                }
            }
        }
    }


    if(flag == 0)
    {
        printf("No hay importes acumulados en esta fecha\n");
    }
    else
    {
        printf("Total recaudado en la fecha %0d/%0d/%d: %.2f\n",fecha.dia,fecha.mes,fecha.anio,total);
    }
}

void contadorComida(eEmpleado x[], int tam, eSector sec[], int tamSec, eAlmuerzo alm[], int tamAlm, eComida com[], int tamCom)
{
    int cont[tamCom];


    for(int i=0; i<tamCom; i++)
    {
        cont[i] = 0;


        for(int j=0; j<tamAlm; j++)
        {
            if(com[i].id == alm[j].idComida && alm[j].ocupado == 1)
            {
                cont[i]++;
            }
        }


        printf("Comida: %s  Cantidad: %d\n",com[i].descripcion,cont[i]);
    }
}



void almuerzoXcomida(eEmpleado x[], int tam, eSector sec[], int tamSec, eAlmuerzo alm[], int tamAlm, eComida com[], int tamCom)
{
    int flag = 0;
    int id;


    listarComidas(com,tamCom);
    printf("\n\n");
    printf("Ingrese ID Comida: ");
    scanf("%d",&id);


    for(int i=0; i<tamAlm; i++)
    {
        for(int j=0; j<tam; j++)
        {
            if(x[j].ocupado == OCUPADO && alm[i].idEmpleado == x[j].legajo && alm[i].ocupado == OCUPADO && alm[i].idComida == id)
            {
                flag = 1;
                mostrarAlmuerzo(alm[i],x,tam,com,tamCom);
                break;
            }
        }
    }


    if(flag == 0)
    {
        printf("Nadie almorzo esta comida\n");
    }
}



void almuerzosXmujeres(eEmpleado x[], int tam, eSector sec[], int tamSec, eAlmuerzo alm[], int tamAlm, eComida com[], int tamCom)
{
    int id;
    int flag = 0;


    listarComidas(com,tamCom);
    printf("\n\n");
    printf("Ingrese ID Comida: ");
    scanf("%d",&id);


    for(int i=0; i<tamAlm; i++)
    {
        for(int j=0; j<tam; j++)
        {
            if(x[j].ocupado == OCUPADO && x[j].legajo == alm[i].idEmpleado && alm[i].ocupado == OCUPADO && x[j].sexo == 'f' && alm[i].idComida == id)
            {
                mostrarAlmuerzo(alm[i],x,tam,com,tamCom);
                flag = 1;
            }
        }
    }


    if(flag == 0)
    {
        printf("Nadie almorzo de este sector\n");
    }
}



void almuerzoMasComidoXsector(eEmpleado x[], int tam, eSector sec[], int tamSec, eAlmuerzo alm[], int tamAlm, eComida com[], int tamCom)
{
    int sector[tamCom];
    int idSector;
    int flag = 0;
    int mayor;


    listarSectores(sec,tamSec);
    printf("\n\n");
    printf("Ingrese Sector: ");
    scanf("%d",&idSector);


    for(int i = 0; i<tamCom; i++)
    {
        sector[i] = 0;


        for(int j=0; j<tamAlm; j++)
        {
            if(alm[j].ocupado == OCUPADO && alm[j].idComida == com[i].id)
            {
                for(int k=0; k<tam; k++)
                {
                    if(x[k].ocupado == OCUPADO && x[k].sector == idSector && x[k].legajo == alm[j].idEmpleado)
                    {
                        sector[i]++;
                    }
                }
            }
        }
    }


    for(int i=0; i<tamCom; i++)
    {
        if(sector[i] > mayor || flag == 0)
        {
            mayor = sector[i];
            flag = 1;
        }
    }


    for(int i=0; i<tamCom; i++)
    {
        if(sector[i] == mayor)
        {
            printf("%s\n",com[i].descripcion);
        }
    }
}

/*------------------------------------------------------------------------------------------------------------------

                                                VALIDACIONES

--------------------------------------------------------------------------------------------------------------------*/

int cargarId()
{
    static int id = 1;


    return id++;
}

char validarSeguir()
{
    char seguir;

    printf("     Desea continuar? s/n: ");
    fflush(stdin);
    seguir = getchar();
    seguir = toupper(seguir);

    while(seguir != 'S'  && seguir !='N' && seguir !='n' && seguir !='s')
    {
        printf("     ERROR. Esta opcion no es valida\n");
        printf("     Desea continuar? s/n: ");
        fflush(stdin);
        seguir = getchar();
        seguir = toupper(seguir);
    }

    return seguir;
}


int compararFechas(eFecha fech, eFecha fecha)
{
    int igual = 0;

    if(fech.dia == fecha.dia && fech.mes == fecha.mes && fech.anio == fecha.anio)
    {
        igual = 1;
    }
    return igual;
}
