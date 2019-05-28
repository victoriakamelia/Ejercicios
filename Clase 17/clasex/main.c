#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10

typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    float sueldo;
    int estado;
} eEmpleado;

void inicializarEmpleados(eEmpleado* vec, int tam);
eEmpleado* newEmpleado();
eEmpleado* newEmpleadoParam(int id, char* nombre, char* apellido, float sueldo);
int buscarLibre(eEmpleado* vec, int tam);
int mostrarEmpleado(eEmpleado *vec);
int mostrarEmpleados(eEmpleado *vec, int tam);
void altaEmpleado(eEmpleado* vec, int tam);
void imprimirEmpleados(eEmpleado* vec, int tam);
int menu();
void guardarEnBinario(eEmpleado* vec, int tam);
void cargarEmpleado(eEmpleado* vec, int tam);


int main()
{
    eEmpleado* lista=(eEmpleado*)malloc(sizeof(eEmpleado)*TAM);
    //int i;
    char seguir='s';
    if(lista == NULL)
    {
        printf("No se pudo conseguir memoria\n");
        system("pause");
        exit(1);
    }
    inicializarEmpleados(lista, TAM);

    do
    {
        switch(menu())
        {
        case 1:
            cargarEmpleado(lista, TAM);

            break;
        case 2:
            altaEmpleado(lista, TAM);
            system("pause");
            break;
        case 3:

            mostrarEmpleados(lista, TAM);
            system("pause");
            break;
        case 4:
            guardarEnBinario(lista, TAM);
            system("pause");
            break;
        case 5:
            imprimirEmpleados(lista, TAM);
            system("pause");
            break;
        case 6:
            seguir='N';
            break;
        default:
            break;

        }


    }
    while(seguir=='s' || seguir=='S');
    return 0;
}


void inicializarEmpleados(eEmpleado* vec, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(vec != NULL)
        {
            (vec+i)->estado=0;
        }
    }
}

eEmpleado* newEmpleado()
{
    eEmpleado* emp=(eEmpleado*) malloc(sizeof(eEmpleado));
    if(emp != NULL)
    {
        emp->id=0;
        strcpy(emp->nombre, "");
        strcpy(emp->apellido, "");
        emp->sueldo=0;
        emp->estado=0;
    }

    return emp;
}

eEmpleado* newEmpleadoParam(int id, char* nombre, char* apellido, float sueldo)
{
    eEmpleado* emp=(eEmpleado*) malloc(sizeof(eEmpleado));
    if(emp != NULL)
    {
        emp->id=id;
        strcpy(emp->nombre, nombre);
        strcpy(emp->apellido, apellido);
        emp->sueldo=sueldo;
        emp->estado=1;
    }

    return emp;
}

int buscarLibre(eEmpleado* vec, int tam)
{
    int indice=-1;
    int i;

    if(vec != NULL && tam>0)
    {
        for(i=0; i<tam; i++)
        {
            if((vec+i)->estado==0)
            {
                indice=i;
            }

        }
    }

    return indice;
}

int mostrarEmpleados(eEmpleado *vec, int tam)
{
    int i;
    if(vec != NULL && tam>0)
    {
        for(i=0; i<tam; i++)
        {
            if((vec+i)->estado==1)
            {
                mostrarEmpleado(vec+i);
            }

        }
    }

    return 0;
}

int mostrarEmpleado(eEmpleado *vec)
{
    if(vec!=NULL)
    {
        printf("%d   %10s   %10s   %.2f", vec->id, vec->nombre, vec->apellido, vec->sueldo);
    }
    return 0;
}

int menu()
{
    int opcion;
    system("cls");
    printf("**MENU DE OPCIONES**\n\n");
    printf("1.CARGAR EMPLEADOS.\n\n");
    printf("2.ALTA EMPLEADOS.\n\n");
    printf("3.LISTAR EMPLEADOS.\n\n");
    printf("4.GUARDAR EMPLEADOS.\n\n");
    printf("5.IMPRIMIR EMPLEADOS.\n\n");
    printf("6.SALIR.\n\n");
    printf("INGRESE OPCION: ");
    scanf("%d", &opcion);


    return opcion;
}


void altaEmpleado(eEmpleado* vec, int tam)
{
    int indice;
    int auxInt;
    char auxCad[20];
    char auxCad2[20];
    float auxFloat;
    indice=buscarLibre(vec, tam);
    if(indice==-1)
    {
        printf("No hay lugar\n");
    }
    else
    {
        printf("INGRESE ID: ");
        scanf("%d", &auxInt);

        printf("INGRESE NOMBRE:");
        fflush(stdin);
        gets(auxCad);

        printf("INGRESE APELLIDO:");
        fflush(stdin);
        gets(auxCad2);

        printf("INGRESE SALARIO: ");
        scanf("%f", &auxFloat);

        eEmpleado* nuevoEmpleado=newEmpleadoParam(auxInt, auxCad, auxCad2, auxFloat);

        if(nuevoEmpleado != NULL)
        {
            *(vec+indice)=*nuevoEmpleado;
        }
free(nuevoEmpleado);
    }


}

void imprimirEmpleados(eEmpleado* vec, int tam)
{
    int i;
    FILE * f;
    if(vec != NULL && tam>0)
    {
        f=fopen("./listaEmpleados.txt", "w");
        if(f!=NULL)
        {
            fprintf(f, "ID      NOMBRE      APELLIDO     SALARIO\n");
            for(i=0; i<tam; i++)
            {
                if((vec+i)->estado==1)
                {
                    fprintf(f, "%d   %10s   %10s   %.2f", (vec+i)->id, (vec+i)->nombre, (vec+i)->apellido, (vec+i)->sueldo);
                }

            }

            fclose(f);
        }

    }

}


void guardarEnBinario(eEmpleado* vec, int tam)
{
    int i;
    FILE * f;
    if(vec != NULL && tam>0)
    {
        f=fopen("./listaEmpleados.bin", "wb");
        if(f!=NULL)
        {

            for(i=0; i<tam; i++)
            {
                if((vec+i)->estado==1)
                {
                    fwrite((vec+i),sizeof(eEmpleado), 1, f);
                }

            }


        }

        fclose(f);
    }

}

void cargarEmpleado(eEmpleado* vec, int tam)
{
    int indice;
    FILE* f;
    int cant;

    f=fopen("./empleados.bin", "rb");

    while(!feof(f))
    {
        indice=buscarLibre(vec, tam);
        cant=fread((vec+indice), sizeof(eEmpleado), 1, f);
        if(cant<1)
        {
            if(feof(f))
            {
                break;
            }else
            {
                printf("HUBO PROBLEMAS PARA LEER EL ARCHIVO");
            }
        }
    }

    fclose(f);
}
