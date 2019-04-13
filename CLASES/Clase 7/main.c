#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "biblioteca.h"
#define VACIO 0
#define OCUPADO 1
#define TAM 3


int main()
{
    Eempleado emp[TAM];//={{"JUAN",'M',1111,1111, 1}, {"ANA", 'F',2222,2222, 1}};
    int opcion;
    int opcion2;
    int auxIndex;
    char seguir='S';
    int indice;

    initEmpleado(emp,TAM);

    while(seguir=='S')
    {
        system("cls");
        system("COLOR 3B");
        printf("---------------------------------------------------\n");
        printf("---------------------------------------------------\n");
        printf("----------*       MENU PRINCIPAL      *------------\n");
        printf("---------------------------------------------------\n");
        printf("---------------------------------------------------\n");
        printf("----------*      1. Alta Empleado.    *------------\n");
        printf("---------------------------------------------------\n");
        printf("----------*      2. Mostrar Empleado. *------------\n");
        printf("---------------------------------------------------\n");
        printf("----------*      3. Ordenar Empleado. *------------\n");
        printf("---------------------------------------------------\n");
        printf("----------*      4. Modificar.        *------------\n");
        printf("---------------------------------------------------\n");
        printf("----------*      5. Dar de baja.      *------------\n");
        printf("---------------------------------------------------\n");
        printf("---------------------------------------------------\n");
        printf("---------------------------------------------------\n");
        printf("-----------------------Ingrese opcion: ");
        scanf("%d",&opcion);


        switch(opcion)
        {
        case 1:
            system("cls");
            cargarEmpleado(emp, TAM);




            seguir=validarSeguir();
            break;
        case 2:
            system("cls");
            if(mostrarEmpleados(emp,TAM)<0)
            {
                printf("---------------------------------------------------\n");
                printf("--------*NO HAY EMPLEADOS PARA MOSTRAR*------------\n");
                printf("---------------------------------------------------\n");
            }
            seguir=validarSeguir();
            break;
        case 3:
            system("cls");
            ordenamiento(emp,TAM);
            seguir=validarSeguir();
            break;
        case 4:
            system("cls");
            printf("---------------------------------------------------\n");
            printf("----------*Ingrese el ID del empleado:*------------\n");
            printf("--------------------------------------* ");
            scanf("%d", &indice);

            auxIndex=buscarId(emp, TAM, indice);

            if(auxIndex<0)
            {
                system("cls");
                printf("---------------------------------------------------\n");
                printf("----------*Ingreso ID incorrecta...   *------------\n");
                printf("---------------------------------------------------\n");
            }
            else if(auxIndex>=0)
            {
                system("cls");
                system("COLOR 3B");
                printf("---------------------------------------------------\n");
                printf("---------------------------------------------------\n");
                printf("----------*     SELECCIONE OPCION     *------------\n");
                printf("---------------------------------------------------\n");
                printf("---------------------------------------------------\n");
                printf("----------*      1. Nombre Empleado.  *------------\n");
                printf("---------------------------------------------------\n");
                printf("----------*      2. Sexo Empleado.    *------------\n");
                printf("---------------------------------------------------\n");
                printf("----------*      3. Sueldo Empleado.  *------------\n");
                printf("---------------------------------------------------\n");
                printf("---------------------------------------------------\n");
                printf("----------------------------Ingrese opcion: ");
                scanf("%d",&opcion2);
                system("cls");
                modificarEmpleado(emp,auxIndex, opcion2);
                seguir=validarSeguir();
                break;

            }

        case 5:
            system("cls");
            printf("---------------------------------------------------\n");
            printf("----------*Ingrese el ID del empleado:*------------\n");
            printf("--------------------------------------* ");
            scanf("%d", &indice);

            auxIndex=buscarId(emp, TAM, indice);

            if(auxIndex<0)
            {
                system("cls");
                printf("---------------------------------------------------\n");
                printf("----------*Ingreso ID incorrecta...   *------------\n");
                printf("---------------------------------------------------\n");
            }
            else if(auxIndex>=0)
            {
                if(bajaEmpleado(emp,TAM,indice)>0)
                {
                    printf("---------------------------------------------------\n");
                    printf("----------*   EMPLEADO DADO DE BAJA   *------------\n");
                    printf("---------------------------------------------------\n");
                }else
                {
                    printf("---------------------------------------------------\n");
                    printf("----------*  NO SE PUDO DAR DE BAJA   *------------\n");
                    printf("---------------------------------------------------\n");
                }
            }

            seguir=validarSeguir();
        default:
            printf("---------------------------------------------------\n");
            printf("----------*     Opcion incorrecta.    *------------\n");
            printf("---------------------------------------------------\n");
            break;
        }
    }

    return 0;
}



