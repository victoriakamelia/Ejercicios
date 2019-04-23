#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <string.h>
#define TAM 8
#define TAMSEC 5

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
}eSector;

typedef struct
{

    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int ocupado;
    eFecha ingreso;
    int idSector;

} eEmpleado;


int menu();
void inicializarEmpleados(eEmpleado vec[], int tam);
int buscarLibre(eEmpleado vec[], int tam);
int buscarEmpleado(eEmpleado vec[], int tam, int legajo);
void mostrarEmpleado(eEmpleado emp,eSector list);
void mostrarEmpleados(eEmpleado vec[], int tam, eSector list[], int tamSec);
void altaEmpleado(eEmpleado vec[], int tam, eSector list[], int tamSec);
void bajaEmpleado(eEmpleado vec[], int tam, eSector list[], int tamSec);
void ModificacionEmpleado(eEmpleado vec[], int tam, eSector list[], int tamSec);
void harcodeEmpleado(eEmpleado list[], int tam);
void empleadoAnio(eEmpleado list[], int tam, int anio);
void empleadosXsector(eEmpleado list[], int tam, eSector lista[], int tamSec);
void harcodeSector(eSector list[], int tam);
int buscarIndiceSector(eSector list[], int tam,int id);
void empleadosXsectores(eEmpleado list[], int tam, eSector lista[], int tamSec);
void contadorEmpleadosSector(eEmpleado list[], int tam, eSector lista[], int tamSec);
void mejorSueldoSector(eEmpleado list[], int tam,eSector lista[], int tamSec);
void mostrarSectores(eSector list[], int tam);

int main()
{
    char seguir = 's';
    char confirma;
    //int anio;
    int sector;

    eEmpleado lista[TAM];

    eSector descripcion[TAMSEC];
    //inicializarEmpleados(lista, TAM);
    harcodeEmpleado(lista, TAM);
    harcodeSector(descripcion,TAMSEC);

    do
    {
        switch(menu())
        {

        case 1:
            // printf("\nAlta empleado\n\n");
            altaEmpleado(lista, TAM, descripcion,TAMSEC);
            system("pause");
            break;

        case 2:
            //printf("\nBaja empleado\n\n");
            bajaEmpleado(lista, TAM,descripcion,TAMSEC);
            system("pause");
            break;

        case 3:
            //printf("\nModificacion empleado\n\n");
            ModificacionEmpleado(lista,TAM,descripcion,TAMSEC);
            system("pause");
            break;

        case 4:
            printf("\nOrdenar empleados\n\n");
            system("pause");
            break;

        case 5:
            //printf("\nListar empleados\n\n");
            mostrarEmpleados(lista, TAM, descripcion, TAMSEC);
            system("pause");
            break;
        case 6:
            printf("Informes\n");
            /*printf("Ingrese anio: ");
            scanf("%d", &anio);
            empleadoAnio(lista, TAM, anio);*/
            printf("Ingrese sector:");
            scanf("%d", &sector);
            empleadosXsector(lista, TAM, descripcion, TAMSEC);
            printf("empleados por sectores\n");
            empleadosXsectores(lista, TAM, descripcion, TAMSEC);

           /* mejorSueldoSector(lista, TAM, 1);
            mejorSueldoSector(lista, TAM, 2);
            mejorSueldoSector(lista, TAM, 3);
            mejorSueldoSector(lista, TAM, 4);
            mejorSueldoSector(lista, TAM, 5);*/

            contadorEmpleadosSector(lista, TAM,descripcion, TAMSEC);
            system("pause");
            break;

        case 7:
            printf("\nConfirma salida s/n?: ");
            fflush(stdin);
            confirma = getche();

            if( tolower(confirma) == 's')
            {
                seguir = 'n';
            }
            break;

        default:
            printf("\n Opcion invalida\n\n");
            system("break");
        }
    }
    while(seguir == 's');

    return 0;
}

/*void inicializarEmpleados(eEmpleado vec[], int tam)
{
    int i;

    for(i=0; i < tam; i++)
    {
        vec[i].ocupado = 0;
    }
}*/

int menu()
{
    int opcion;

    system("cls");
    printf("  *** ABM Empleados ***\n\n");
    printf("1- Alta Empleado\n");
    printf("2- Baja Empleado\n");
    printf("3- Modificacion Empleado\n");
    printf("4- Ordenar Empleados\n");
    printf("5- Listar Empleados\n");
    printf("6- Informes\n");
    printf("7- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int buscarLibre(eEmpleado vec[], int tam)
{

    int indice = -1;
    int i;

    for(i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 0)
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
    int i;

    for(i=0; i < tam; i++)
    {
        if( vec[i].legajo == legajo && vec[i].ocupado == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarEmpleado(eEmpleado emp, eSector list)
{


    printf("  %2d   %10s   %2c    %.2f    %02d/%02d/%2d   %5d\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo, emp.ingreso.dia, emp.ingreso.mes, emp.ingreso.anio, emp.idSector);

}

void mostrarEmpleados(eEmpleado vec[], int tam, eSector list[], int tamSec)
{
    int cont= 0;
    int i;


    for(i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1)
        {

            mostrarEmpleado(vec[i], list[i]);
            cont++;
        }
    }
    if(cont == 0)
    {
        printf("No hay empleados que mostrar\n\n");
    }
}

void altaEmpleado(eEmpleado vec[], int tam, eSector list[], int tamSec)
{
    int indice;
    int legajo;
    int esta;

    indice = buscarLibre(vec, tam);

    if(indice == -1)
    {
        printf("No hay lugar");
    }
    else
    {

        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarEmpleado(vec, tam, legajo);

        if( esta == -1)
        {
            vec[indice].legajo = legajo;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(vec[indice].nombre);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &vec[indice].sexo);

            printf("Ingrese sueldo: ");
            scanf("%f", &vec[indice].sueldo);

            printf("Ingrese dia de ingreso:");
            scanf("%d", &vec[indice].ingreso.dia);

            printf("Ingrese mes de ingreso:");
            scanf("%d", &vec[indice].ingreso.mes);

            printf("Ingrese anio de ingreso:");
            scanf("%d", &vec[indice].ingreso.anio);

            printf("Ingrese sector: ");
            scanf("%d", &vec[indice].idSector);

            vec[indice].ocupado = 1;

            printf("\nEl empleado ha sido registrado con exito!!!\n\n");

        }
        else
        {

            printf("Ya existe un empleado con el legajo %d\n", legajo);

            mostrarEmpleado(vec[esta], list[esta]);
        }
    }
}

void bajaEmpleado(eEmpleado vec[], int tam, eSector list[], int tamSec)
{

    int legajo;
    char confirma;
    int esta;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    esta = buscarEmpleado(vec, tam, legajo);

    if( esta == -1)
    {

        printf("\nEl legajo %d no esta registrado en el sistema\n", legajo);
    }
    else
    {
        mostrarEmpleado(vec[esta],list[esta]);

        printf("\nConfirma la eliminacion? s/n");
        fflush(stdin);
        confirma = tolower(getche());

        if(confirma == 's')
        {
            vec[esta].ocupado = 0;
        }
        else
        {
            printf("\nLa eliminacion ha sido cancelada\n");
        }

    }





}

void ModificacionEmpleado(eEmpleado vec[], int tam, eSector list[], int tamSec)
{

    int legajo;
    char confirma;
    float nuevoSueldo;
    int esta;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    esta = buscarEmpleado(vec, tam, legajo);

    if( esta == -1)
    {

        printf("\nEl legajo %d no esta registrado en el sistema\n", legajo);
    }
    else
    {
        mostrarEmpleado(vec[esta], list[esta]);
        printf("\nQuiere cambiar el sueldo? s/n");
        fflush(stdin);
        confirma = tolower(getche());

        if(confirma == 's')
        {
            printf("\nIngrese nuevo sueldo: ");
            scanf("%f", &nuevoSueldo);

            vec[esta].sueldo = nuevoSueldo;
        }
        else
        {
            printf("\nNo se ha modificado el sueldo\n");
        }

    }


}
void harcodeEmpleado(eEmpleado list[], int tam)
{
    int i;
    eEmpleado hardcode[8]=
    {
        {1111, "ANDRES", 'M', 45000, 1, {5, 6, 2011},1},
        {2222, "MARTIN", 'M', 25000, 1,{8, 11, 2004},2},
        {3333, "JUANA", 'F', 8000, 1,{25, 8, 2013},0},
        {4444, "LUISA", 'F', 25000, 1,{8, 6, 2012},5},
        {5555, "PEDRO", 'M', 27000, 1,{6, 6, 2014},4},
        {6666, "ANTONIP", 'M', 25000, 1,{3, 6, 2018},0},
        {7777, "MARIA", 'F', 26000, 1,{6, 5, 2017},3},
        {8888, "ANALIA", 'F', 28000, 1,{1, 6, 2017},4}
    };
    for(i=0; i<tam; i++)
    {
        list[i]=hardcode[i];
    }


}

/*void empleadoAnio(eEmpleado list[], int tam, int anio)
{
    int cont= 0;
    int i;

    for(i=0; i < tam; i++)
    {
        if(list[i].ocupado == 1 && list[i].ingreso.anio==anio)
        {

            mostrarEmpleado(list[i], );
            cont++;
        }
    }
    if(cont == 0)
    {
        printf("No hay empleados que mostrar\n\n");
    }
}*/

void harcodeSector(eSector list[], int tam)
{
    int i;
    eSector hardcode[5]=  {
                        {0, "RRHH"},
                        {1, "LEGALES"},
                        {2, "VENTAS"},
                        {3, "CONTABLE"},
                        {4, "SISTEMAS"}
                        };

    for(i=0;i<tam;i++)
    {
        list[i]=hardcode[i];
    }
}

int buscarIndiceSector(eSector list[], int tam,int id)
{
    int i;
    int retorno=-1;

    for(i=0; i<tam; i++)
    {
        if(list[i].id==id)
        {
            retorno=i;
        }
    }

    return retorno;
}


void empleadosXsector(eEmpleado list[], int tam, eSector lista[], int tamSec)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(list[i].idSector == 1)
        {
            mostrarEmpleado(list[i], lista[i]);
        }
    }
}

void empleadosXsectores(eEmpleado list[], int tam,  eSector lista[], int tamSec)
{
    eEmpleado aux;
    int i, j;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(list[i].idSector > list[j].idSector )
            {

                aux=list[i];
                list[i]=list[j];
                list[j]=aux;

            }
        }

    }

    for(i=0; i<tam; i++)
    {
        mostrarEmpleado(list[i], lista[i]);
    }
}

void contadorEmpleadosSector(eEmpleado list[], int tam, eSector lista[], int tamSec)
{
    int i;
    int max;
    int flag=0;
    int vec[5];
    int indice;

    for(i=0; i<tam;i++)
    {
        vec[i]=0;
    }





    for(i=0; i<tam; i++)
    {
        if(list[i].idSector==1)
        {
            vec[0]++;
        }else
        if(list[i].idSector==2)
        {
            vec[1]++;
        }else
        if(list[i].idSector==3)
        {
            vec[2]++;
        }else
        if(list[i].idSector==4)
        {
            vec[3]++;
        }else
        {
            vec[4]++;
        }


    }



    printf("Sector 1: %d \n", vec[0]);
    printf("Sector 2: %d \n", vec[1]);
    printf("Sector 3: %d \n", vec[2]);
    printf("Sector 4: %d \n", vec[3]);
    printf("Sector 5: %d \n", vec[4]);

    for(i=0; i<tam; i++)
    {
        if(vec[i]>max || flag==0)
        {
            max=vec[i];
            indice=i;
            flag=1;
        }
    }


    printf("El sector %d tiene la mayor cantidad de empleados con %d\n", indice, max );


}

void mejorSueldoSector(eEmpleado list[], int tam,  eSector lista[], int tamSec)
{
    int i;
    int flag=0;
    int max;
    int indice;


    for(i=0; i<tam;i++)
    {
        if(list[i].idSector == idSector)
        {
            if(list[i].sueldo>max || flag==0)
            {
                max=list[i].sueldo;
                indice=i;
            }
        }
    }
    printf("En el sector %d el sueldo mas alto es %d\n", idSector, max);
    mostrarEmpleado(list[indice], lista[indice]);
}

void mostrarSectores(eSector list[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("%d %s", list[i].id, list[i].descripcion);
    }
}
