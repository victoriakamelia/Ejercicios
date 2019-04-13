#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "biblioteca.h"
#define VACIO 0
#define OCUPADO 1
#define TAM 1


char validarSeguir()
{
    char seguir='S';

    printf("---------------------------------------------------\n");
    printf("----------*  Desea continuar?: S/N... *------------\n");
    printf("---------------------------------------------------\n");
    fflush(stdin);
    scanf("%s", &seguir);
    seguir=toupper(seguir);

    while(seguir != 'N' && seguir != 'S')
    {
    printf("---------------------------------------------------\n");
    printf("----------*      Opcion invalida.     *------------\n");
    printf("---------------------------------------------------\n");
    printf("---------------------------------------------------\n");
    printf("----------*  Desea continuar?: S/N... *------------\n");
    printf("---------------------------------------------------\n");
        fflush(stdin);
        scanf("%s", &seguir);
        seguir=toupper(seguir);

    }

    return seguir;
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


int getInt(Eempleado emp[],int tam, int index)
{
    int retorno=-1;
    int auxInt;
    printf("---------------------------------------------------\n");
    printf("----------*      Ingrese legajo:      *------------\n");
    printf("--------------------------------------* ");
    fflush(stdin);
    scanf("%d",&auxInt);



    while(auxInt<1000 || auxInt>9999)
    {
        printf("---------------------------------------------------\n");
        printf("----------*Legajo debe tener 4 cifras:*------------\n");
        printf("--------------------------------------* ");
        fflush(stdin);
        scanf("%d",&auxInt);

    }
    retorno=0;
    if(buscarId(emp, tam, auxInt)>=0)
    {
        printf("---------------------------------------------------\n");
        printf("------*Numero legajo ingresado existente*----------\n");
        printf("---------------------------------------------------\n");
        retorno=-1;
    }else
    {
        emp[index].legajo=auxInt;
    }



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

int modificarEmpleado(Eempleado emp[],int indice, int opcion2)
{
    int retorno=-1;

   if(opcion2==1)
   {
     getText(emp, indice);
        retorno=0;

   }else
   if(opcion2==2)
   {

     pedirSexo(emp, indice);
        retorno=0;

   }else
   if(opcion2==3)
   {
       getFloat(emp, indice);
        retorno=0;

   }else
   {
        printf("-----INGRESO OPCION INCORRECTA----");

   }

       return retorno;

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


//************************************************************************
void cargarEmpleado(Eempleado emp[], int tam)
{
    int index = buscarLibre(emp,tam);


    if(index ==-1)
    {

        printf("No hay espacio.");

    }
    else
    {
        if(getInt(emp,tam, index)   ==0 &&
                getText(emp, index) ==0 &&
                pedirSexo(emp,index)==0 &&
                getFloat(emp, index)==0)
        {
            emp[index].estado = OCUPADO;
            printf("---------------------------------------------------\n");
            printf("----------*       Empleado generado.  *------------\n");
            printf("---------------------------------------------------\n");
        }

    }


}

void initEmpleado(Eempleado emp[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        emp[i].estado = VACIO;
    }
}




void mostrarEmpleado(Eempleado emp)
{
    fflush(stdin);
    printf("Legajo     Nombre   Sexo    Sueldo\n");
    printf("%d      %5s      %c     %.2f\n",emp.legajo,emp.nombre,emp.sexo,emp.sueldo);


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
























