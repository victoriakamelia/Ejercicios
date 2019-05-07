#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#define TAM 15
#define TAMSEC 5

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fechaIngreso;
    int idSector;
    int ocupado;

} eEmpleado;

typedef struct
{
    int id;
    char descripcion[20];

} eSector;

typedef struct
{
    int id;
    char descripcion[20];

} eComida;

typedef struct
{
    int id;
    int idEmpleado;
    int idComida;
    eFecha fecha;
    char descripcion[20];

} eAlmuerzo;



int menu();
void inicializarEmpleados(eEmpleado vec[], int tam);
void mostrarEmpleado(eSector sectores[], int tam, eEmpleado emp);
void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSector);
int buscarLibre(eEmpleado vec[], int tam);
int buscarEmpleado(eEmpleado vec[], int tam, int legajo);
void altaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSector);
int obtenerSector(eSector sectores[], int tam, int id, char desc[]);
void mostrarSectoresConEmpleados(eEmpleado empleados[], int tam, eSector sectores[], int tamSec);
void mostrarCantEmpleadosXSector(eEmpleado empleados[], int tam, eSector sectores[], int tamSec);
void mostrarSectores( eSector sectores[], int tam);
void SectorMasEmpleados( eEmpleado empleados[], int tam, eSector sectores[], int tamSec);
void  almuerzosXPersona(eEmpleado empleados[], int tam, eComida comidas[], int tamCom, eAlmuerzo almuerzos[], int tamAlm);
void mostrarAlmuerzo(eEmpleado empleados,eComida comidas[], int tamCom, eAlmuerzo almuerzos, int idComida);
int buscarIndexComida(eComida comidas[], int tamCom, int id);
void almuerzosSector(eEmpleado empleados[],eComida comidas[], int tamCom, eAlmuerzo almuerzos[], eSector sectores[]);
void almuezoMasComido(eComida comidas[], int tamCom,eAlmuerzo almuerzos[],int tamAlm);
void comidaXPersona(eEmpleado empleados[], int tam, eComida comidas[], int tamCom, eAlmuerzo almuerzos[], int tamAlm);
void almuezoMasComidoXSector(eComida comidas[], int tamCom,eAlmuerzo almuerzos[],int tamAlm, eSector sectores[], int tamSec, eEmpleado empleados[], int tam);



int main()
{
    char seguir = 's';
    char confirma;
    eSector sectores[] =
    {
        {1, "Sistemas"},
        {2, "RRHH"},
        {3, "Compras"},
        {4, "Ventas"},
        {5, "Legales"},

    };
    eEmpleado lista[TAM]=
    {
        {1234, "Juan", 'm', 30000,{12,3,2000},5, 1},
        {2222, "Ana", 'f', 32000, {2,7,2010}, 2,1},
        {2211, "Jorge", 'm', 28000,{14,5,2013}, 2,1},
        {3241, "Alberto", 'm', 35000, {2,9,2010},1, 1},
        {1111, "Sonia", 'f', 39000, {12,3,2012},3,1},
        {2224, "Miguel", 'm', 29700, {28,7,2009}, 2,1},
        {6578, "Adrian", 'm', 43200, {11,1,2016},5, 1},
        {3425, "Lucia", 'f', 32300, {19,10,2004}, 2,1},
        {5546, "Gaston", 'm', 29760, {13,9,2006},4,1},
        {7654, "Diego", 'm', 35000, {23,6,2010},1, 1},
        {9040, "Viviana", 'f', 47000,{18, 7,2011}, 1,1},
        {7439, "Gustavo", 'm', 25000, {12,12,2003}, 4,1},
        {7654, "Diego", 'm', 35000, {23,6,2010},1, 0},
        {9040, "Viviana", 'f', 47000,{18, 7,2011}, 1,0},
        {7439, "Gustavo", 'm', 25000, {12,12,2003}, 4,0}
    };
    //inicializarEmpleados(lista, TAM);

    eComida listaComidas[5]=
    {
        {1, "MILANESAS"},
        {2, "FIDEOS"},
        {3, "PIZZA"},
        {4, "PESCADO"},
        {5, "TARTA"}
    };

    eAlmuerzo listaAlmuerzo[20]=
    {
        {100, 1234, 1, {10,12,2019}},
        {101, 2222, 2, {11,12,2019}},
        {102, 3241, 3, {12,12,2019}},
        {103, 6578, 1, {12,12,2019}},
        {104, 3425, 2, {12,12,2019}},
        {105, 9040, 2, {13,12,2019}},
        {106, 1234, 4, {14,12,2019}},
        {107, 7439, 1, {14,12,2019}},
        {108, 5546, 5, {14,12,2019}},
        {109, 9040, 5, {15,12,2019}},
        {110, 7439, 3, {15,12,2019}},
        {111, 6578, 5, {16,12,2019}},
        {112, 2211, 5, {17,12,2019}},
        {113, 1111, 3, {17,12,2019}},
        {114, 7654, 2, {17,12,2019}},
        {115, 2224, 1, {18,12,2019}},
        {116, 7654, 2, {19,12,2019}},
        {117, 1111, 3, {19,12,2019}},
        {118, 2224, 2, {20,12,2019}},
        {119, 2211, 2, {21,12,2019}}


    };


    do
    {
        switch(menu())
        {

        case 1:
            //printf("\nAlta empleado\n\n");
            altaEmpleado(lista, TAM, sectores, TAMSEC);
            system("pause");
            break;

        case 2:
            printf("\nBaja empleado\n\n");
            system("pause");
            break;

        case 3:
            printf("\nModificacion empleado\n\n");
            system("pause");
            break;

        case 4:
            printf("\nOrdenar empleados\n\n");
            system("pause");
            break;

        case 5:
            //printf("\nListar empleados\n\n");
            mostrarEmpleados(lista, TAM, sectores, TAMSEC);
            system("pause");
            break;

        case 6:
            //printf("\nListar empleados\n\n");
            mostrarSectoresConEmpleados(lista, TAM, sectores, TAMSEC);
            system("pause");
            break;
        case 7:
            //printf("\nListar empleados\n\n");
            mostrarCantEmpleadosXSector(lista, TAM, sectores, TAMSEC);
            system("pause");
            break;

        case 8:
            //printf("\nListar empleados\n\n");
            SectorMasEmpleados(lista, TAM, sectores, TAMSEC);
            system("pause");
            break;

        case 9:
            //comidaXPersona(lista, TAM, listaComidas, 5, listaAlmuerzo, 20);
            //almuerzosSector(lista, listaComidas, 5, listaAlmuerzo, sectores);
            //almuezoMasComido(listaComidas, 5, listaAlmuerzo, 20);
            almuezoMasComidoXSector(listaComidas, 5, listaAlmuerzo, 20, sectores, TAMSEC, lista, TAM);
            system("pause");
            break;

        case 10:
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

void inicializarEmpleados(eEmpleado vec[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        vec[i].ocupado = 0;
    }
}

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
    printf("6- Listar Sectores con Empleados\n");
    printf("7- Cantidad de empleados por sector\n");
    printf("8- Sectores con mas empleados\n");
    printf("9-Almuerzo por empleados\n");
    printf("10- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void mostrarEmpleado(eSector sectores[], int tam, eEmpleado emp)
{
    char nombreSector[20];
    int consigioNombre;

    consigioNombre =  obtenerSector(sectores, tam, emp.idSector, nombreSector);

    if( !consigioNombre)
    {
        strcpy(nombreSector, "Sin definir");
    }
    printf("   %d   %10s     %c     %.2f     %02d/%02d/%4d    %s\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo, emp.fechaIngreso.dia, emp.fechaIngreso.mes, emp.fechaIngreso.anio, nombreSector);

}

void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSector)
{
    int contador = 0;

    system("cls");

    printf(" Legajo      Nombre     Sexo    Sueldo     FechaIngreso   Sector\n");
    printf(" ------      ------     ----    ------     ------------   ------\n");

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            mostrarEmpleado(sectores, tamSector, vec[i]);
            contador++;
        }
    }
    printf("\n\n");

    if( contador == 0)
    {
        printf("\nNo hay empleados que mostrar\n");
    }
}

int buscarLibre(eEmpleado vec[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
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

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1 && vec[i].legajo == legajo)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void altaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSector)
{

    int indice;
    int legajo;
    int esta;


    indice = buscarLibre(vec, tam);

    if( indice == -1)
    {

        printf("\nNo hay lugar en el sistema\n");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarEmpleado(vec, tam, legajo);

        if( esta != -1)
        {
            printf("Existe un empleado de legajo %d en el sistema\n", legajo);
            mostrarEmpleado(sectores, tamSector, vec[esta]);
        }
        else
        {
            vec[indice].legajo = legajo;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(vec[indice].nombre);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &vec[indice].sexo );

            printf("Ingrese sueldo: ");
            scanf("%f", &vec[indice].sueldo );

            printf("Ingrese fecha de ingreso dd/mm/aaaa: ");
            scanf("%d %d %d", &vec[indice].fechaIngreso.dia, &vec[indice].fechaIngreso.mes, &vec[indice].fechaIngreso.anio);

            mostrarSectores(sectores, tamSector);

            printf("Ingrese id sector: ");
            scanf("%d", &vec[indice].idSector);


            vec[indice].ocupado = 1;

            printf("Alta empleado exitosa!!!\n\n");

        }
    }

}

int obtenerSector(eSector sectores[], int tam, int idSector, char desc[])
{

    int todoOk = 0;

    for(int i=0; i < tam; i++)
    {

        if(idSector == sectores[i].id)
        {

            strcpy(desc, sectores[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}


void mostrarSectoresConEmpleados(eEmpleado empleados[], int tam, eSector sectores[], int tamSec)
{
    system("cls");

    for(int i=0; i < tamSec; i++)
    {
        printf("Sector: %s\n\n", sectores[i].descripcion);
        for(int j=0; j < tam; j++)
        {
            if( empleados[j].idSector == sectores[i].id && empleados[j].ocupado== 1)
            {
                mostrarEmpleado(sectores, tamSec, empleados[j]);
            }
        }
        printf("\n\n");

    }
}

void mostrarCantEmpleadosXSector(eEmpleado empleados[], int tam, eSector sectores[], int tamSec)
{
    int contador;

    for(int i=0; i < tamSec; i++)
    {
        contador = 0;
        printf("Sector: %s\n\n", sectores[i].descripcion);

        for(int j=0; j < tam; j++)
        {
            if( sectores[i].id == empleados[j].idSector && empleados[j].ocupado == 1)
            {
                contador++;
            }
        }

        printf("Cantidad: %d\n\n", contador);
    }


}

void mostrarSectores( eSector sectores[], int tam)
{

    printf("\n    Sectores\n");
    printf(" id     descripcion\n\n");

    for(int i=0; i < tam; i++)
    {
        printf("  %d      %10s\n", sectores[i].id, sectores[i].descripcion);
    }
    printf("\n\n");
}


void SectorMasEmpleados( eEmpleado empleados[], int tam, eSector sectores[], int tamSec)
{


    int totales[tamSec];
    int mayor;
    int flag = 0;



    for(int i=0; i < tamSec; i++)
    {

        totales[i] = 0;
        for(int j=0; j < tam; j++)
        {
            if( sectores[i].id == empleados[j].idSector && empleados[j].ocupado == 1)
            {
                totales[i]++;
            }
        }


    }

    for(int i=0; i < tamSec; i++)
    {
        if( flag == 0 || mayor < totales[i])
        {
            mayor = totales[i];
            flag = 1;
        }
    }

    printf("Cantidad mayor de empleados %d\n\n", mayor);
    printf("En el o los siguientes sectore\n\n");

    for(int i=0; i < tamSec; i++)
    {
        if( totales[i] == mayor)
        {
            printf("%s\n", sectores[i].descripcion);
        }

    }

}

void  almuerzosXPersona(eEmpleado empleados[], int tam, eComida comidas[], int tamCom, eAlmuerzo almuerzos[], int tamAlm)
{
    int i;
    int j;
    int k;
    int idComida;

    for(i=0; i<tamAlm; i++)
    {

        for(j=0; j<tam; j++)
        {
            if(empleados[j].legajo == almuerzos[i].idEmpleado && empleados[j].ocupado==1)
            {
                for(k=0; k<tamCom; k++)
                {
                    if(almuerzos[i].idComida == comidas[k].id)
                    {
                        idComida=k;
                        mostrarAlmuerzo(empleados[j], comidas, tamCom, almuerzos[i], idComida);

                    }
                }


                //printf("empleado: %10s id %d descripcion: %10s fecha: %02d/%02d/%d \n", empleados[j].nombre, empleados[j].legajo, comidas[idComida].descripcion, almuerzos[i].fecha);
            }

        }
    }

}

void mostrarAlmuerzo(eEmpleado empleados,eComida comidas[], int tamCom, eAlmuerzo almuerzos, int idComida)
{
    /* int indiceComida;
     indiceComida=buscarIndexComida(comidas, tamCom, idComida);*/

    printf("EMPLEADO: %10s - ID %d - COMIDA: %10s - FECHA: %02d/%02d/%d \n", empleados.nombre, empleados.legajo, comidas[idComida].descripcion, almuerzos.fecha);
}

int buscarIndexComida(eComida comidas[], int tamCom, int id)
{
    int i;
    int indice=-1;

    for(i=0; i<tamCom; i++)
    {
        if(comidas[i].id == id)
        {
            indice=i;
        }
    }

    return indice;
}

void almuerzosSector(eEmpleado empleados[],eComida comidas[], int tamCom, eAlmuerzo almuerzos[], eSector sectores[])
{
    int i, j;
    int au;
    char auxChar[20];
    int sector;
    printf("Ingrese un sector: ");
    scanf("%d", &sector);
    obtenerSector(sectores, 5, sector, auxChar);

    printf("%s\n",auxChar);
    for(i=0; i<20; i++)
    {

        if(empleados[i].idSector==sector)
        {

            for(j=0; j<20; j++)
            {
                if(empleados[i].legajo==almuerzos[j].idEmpleado && empleados[i].ocupado==1)
                {
                    au=buscarIndexComida(comidas, tamCom, almuerzos[j].idComida);

                    mostrarAlmuerzo(empleados[i], comidas, 5, almuerzos[j], au);
                }
            }
        }
    }


}

void almuezoMasComido(eComida comidas[], int tamCom,eAlmuerzo almuerzos[],int tamAlm)
{
    int comi[tamCom];
    int flag=0;
    int indice;
    int max;
    int i, j;


    for(i=0; i<tamCom; i++)
    {
        comi[i]=0;
    }


    for(i=0; i<tamAlm ; i++)
    {
        for(j=0; j<tamCom; j++)
        {
            if(comidas[j].id==almuerzos[i].idComida)
            {
                comi[j]++;
            }

        }
    }


    for(i=0; i<tamCom; i++)
    {
        if(comi[i]>max || flag==0)
        {
            max=comi[i];
            indice=i;
            flag=1;
        }
    }

    printf("maximo comidas %d de %s\n", max, comidas[indice].descripcion);
}

/*void almuerzoxComida(eComida comidas[], int tamCom,eAlmuerzo almuerzos[],int tamAlm)
{
    int i, j;
    int idComidita;
    printf("Ingrese id de comida que desea listar.\n");

    scanf("%d", &idComidita);

    for(i=0; i<tamAlm; i++)
    {

    }

}*/

void  comidaXPersona(eEmpleado empleados[], int tam, eComida comidas[], int tamCom, eAlmuerzo almuerzos[], int tamAlm)
{
    int i;
    int j;

    int idComida;
    int indexComida;
    printf("Elija comida: ");
    scanf("%d", &idComida);

    for(i=0; i<tamAlm; i++)
    {
        for(j=0; j<tam; j++)
        {
            if(empleados[j].legajo == almuerzos[i].idEmpleado && empleados[j].ocupado==1)
            {

                if(almuerzos[i].idComida == idComida)
                {
                    indexComida=buscarIndexComida(comidas, tamCom, idComida);
                    if(empleados[j].sexo== 'f')
                    {
                        mostrarAlmuerzo(empleados[j], comidas, tamCom, almuerzos[i], indexComida);
                    }

                }
            }
        }
    }
}

void almuezoMasComidoXSector(eComida comidas[], int tamCom,eAlmuerzo almuerzos[],int tamAlm, eSector sectores[], int tamSec, eEmpleado empleados[], int tam)
{
    int comi[tamCom];
    int flag=0;
    int indice;
    int max;
    int i, j, k;
    int elSector;

    printf("Elija un Sector");
    mostrarSectores(sectores, tamSec);
    scanf("%d", &elSector);


    for(i=0; i<tamCom; i++)
    {
        comi[i]=0;
    }


    for(i=0; i<tamCom ; i++)
    {

        for(k=0; k<tamAlm; k++)
        {
            if(almuerzos[k].idComida== comidas[i].id)
            {
                for(j=0; j<tam; j++)
                {
                    if(empleados[j].idSector==elSector && empleados[i].legajo == almuerzos[k].idEmpleado && empleados[j].ocupado==1)
                    {
                        comi[i]++;

                    }
                }
            }


        }




    }


    for(i=0; i<tamCom; i++)
    {
        if(comi[i]>max || flag==0)
        {
            max=comi[i];
            indice=i;
            flag=1;
        }
    }

    printf("maximo comidas %d de %s del sector %d\n", max, comidas[indice].descripcion, elSector);
}
