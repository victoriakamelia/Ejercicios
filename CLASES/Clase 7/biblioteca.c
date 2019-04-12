#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "biblioteca.h"
#define VACIO 0
#define OCUPADO 1
#define TAM 1


int buscarLibre(Eempleado emp[], int tam)
{
    int i;
    int indice = -1;

    for(i=0; i<tam; i++)
    {
        if(emp[i].estado == VACIO)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarId(Eempleado emp[], int tam, int id)
{
    int i;
    int retorno=-1;
    for(i=0; i<tam; i++)
    {
        if(emp[i].legajo==id && emp[i].estado == OCUPADO)
        {
            retorno=i;

            break;
        }

    }

    return retorno;
}

char validarSeguir()
{
    char seguir='S';

    printf("\n /D E S E A    C O N T I N U A R ?   S/N: ");
    fflush(stdin);
    scanf("%s", &seguir);
    seguir=toupper(seguir);

    while(seguir != 'N' && seguir != 'S')
    {
        printf("\n /LA OPCION INGRESADA ES INVALIDA.");
        printf("\n /D E S E A    C O N T I N U A R ?   S/N: ");
        fflush(stdin);
        scanf("%s", &seguir);
        seguir=toupper(seguir);

    }

    return seguir;

}


void ordenamiento(Eempleado emp[], int tam)
{
    printf("---------------------------------------------------\n");
    printf("----------*  O R D E N A M I E N T O  *------------\n");
    printf("---------------------------------------------------\n");
    int i;
    int j;
    Eempleado aux;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(emp[i].sueldo < emp[j].sueldo)
            {
                aux = emp[i];
                emp[i] = emp[j];
                emp[j] = aux;
            }
        }
    }

    for(i=0; i<tam; i++)
    {
        if(emp[i].estado == OCUPADO)
        {
            mostrarEmpleado(emp[i]);

        }
    }

}


void mostrarEmpleado(Eempleado emp)
{
    fflush(stdin);
    printf("Legajo     Nombre   Sexo    Sueldo\n");
    printf("%d      %5s      %c     %.2f\n",emp.legajo,emp.nombre,emp.sexo,emp.sueldo);


}

int mostrarEmpleados(Eempleado emp[],int tam)
{
    int i;
    int retorno=-1;

    for(i=0; i<tam; i++)
    {
        if(emp[i].estado == OCUPADO)
        {
            mostrarEmpleado(emp[i]);
            retorno=0;
        }
    }

return retorno;

}

int getInt(Eempleado emp[], int index)
{
    int retorno=-1;
    printf("---------------------------------------------------\n");
    printf("----------*      Ingrese legajo:      *------------\n");
    printf("--------------------------------------* ");
    fflush(stdin);
    scanf("%d",&emp[index].legajo);

    while(emp[index].legajo<1000 || emp[index].legajo>9999)
    {
        printf("---------------------------------------------------\n");
        printf("----------*Legajo debe tener 4 cifras:*------------\n");
        printf("--------------------------------------* ");
        fflush(stdin);
        scanf("%d",&emp[index].legajo);
    }
    retorno=0;

    return retorno;
}

int getFloat(Eempleado emp[],int index)
{
    int retorno=-1;
    printf("---------------------------------------------------\n");
    printf("----------*      Ingrese sueldo:      *------------\n");
    printf("--------------------------------------* ");
    fflush(stdin);
    scanf("%f",&emp[index].sueldo);
    while(emp[index].sueldo < 0)
    {
        printf("---------------------------------------------------\n");
        printf("----------*Sueldo debe ser positivo:  *------------\n");
        printf("--------------------------------------* ");
        fflush(stdin);
        scanf("%f",&emp[index].sueldo);
    }
    retorno=0;

    return retorno;
}

int getText(Eempleado emp[],int index)
{
    char auxCad[100];
    int retorno=-1;

    printf("---------------------------------------------------\n");
    printf("----------*      Ingrese nombre:      *------------\n");
    printf("--------------------------------------* ");
    fflush(stdin);
    gets(auxCad);

    while(strlen(auxCad)>19)
    {
        printf("---------------------------------------------------\n");
        printf("----------*Error, caracteres excedidos*------------\n");
        printf("--------------------------------------* ");
        fflush(stdin);
        gets(auxCad);
    }

    strcpy(emp[index].nombre,auxCad);
    retorno=0;

    return retorno;
}

int pedirSexo(Eempleado emp[],int index)
{

    int retorno=-1;
    printf("---------------------------------------------------\n");
    printf("----------*      Ingrese sexo(F/M):   *------------\n");
    printf("--------------------------------------* ");
    fflush(stdin);
    scanf("%c",&emp[index].sexo);

    while(emp[index].sexo != 'f' && emp[index].sexo != 'm' && emp[index].sexo !='F' && emp[index].sexo !='M')
    {
        printf("---------------------------------------------------\n");
        printf("----------*    Sexo debe ser F o M:   *------------\n");
        printf("--------------------------------------* ");
        fflush(stdin);
        scanf("%c",&emp[index].sexo);
    }

    retorno=0;

    return retorno;

}

int bajaEmpleado(Eempleado emp[],int tam, int id)
{
    int retorno = 0;
    int i;

    for(i = 0; i < tam; i++)
        {
        if(emp[i].legajo == id)
            {
                emp[i].estado = VACIO;
                retorno = 1;
            }
        }
    return retorno;
}




