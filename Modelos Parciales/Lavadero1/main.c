#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "utn.h"
#include "auto.h"
#define TAM 6
#define TAMMAR 5
#define TAMCO 5
#define TAMSER 4
#define TAMTRA 6
#define OCUPADO 1
#define VACIO 0


int main()
{
    eAuto list[TAM]; /*=
    {
        {1000, "QWE 113", 1000, 5000, 1999, 1},
        {1001, "ZWE 143", 1001, 5004, 2000, 1},
        {1002, "RWE 623", 1003, 5001, 1999, 1},
        {1003, "TWE 723", 1000, 5002, 1999, 1},
        {1004, "GWE 823", 1004, 5003, 1999, 1},
        {1005, "IHE 923", 1001, 5000, 1999, 1}
    };*/

    eAuto aux;
    eTrabajo trabajo[TAMTRA]; /*=
{
    {0, "QWE 113", 20000, {02, 05, 2019}, 1},
    {1, "ZWE 143", 20001, {03, 05, 2019}, 1},
    {2, "RWE 623", 20003, {05, 05, 2019}, 1},
    {3, "TWE 723", 20000, {06, 05, 2019}, 1},
    {4, "GWE 823", 20002, {07, 05, 2019}, 1},
    {5, "IHE 923", 20001, {07, 05, 2019}, 0}
};*/

    eColor colores[TAMCO]=
    {
        {5000, "NEGRO"},
        {5001, "BLANCO"},
        {5002, "GRIS"},
        {5003, "ROJO"},
        {5004, "AZUL"}
    };

    eMarca marcas[TAMMAR]=
    {
        {1000, "RENAULT"},
        {1001, "FIAT"},
        {1002, "FORD"},
        {1003, "CHEVROLET"},
        {1004, "PEUGEOT"}

    };

    eServicio servicio[TAMSER]=
    {

        {20000, "LAVADO", 250.00},
        {20001, "PULIDO", 300.00},
        {20002, "ENCERADO", 400.00},
        {20003, "COMPLETO", 600.00},


    };


    char seguir='S';
    char seguir2;
    int flag1=0;
    int indice;
    char patente[8];

    initAutos(list,TAM);
    initTrabajo(trabajo, TAMTRA);

    do
    {
        switch(menu())
        {
        case 1:
            system("cls");
              if(addAutos(list, TAM, marcas, TAMMAR, colores, TAMCO)==0)
                {
                   flag1=1;
                }

            seguir=validarSeguir();
            break;
        case 2:
            system("cls");
            if(flag1==0  && hayAuto(list, TAM)==0)
            {
                printf("________________________________________________________________\n\n");
                printf("PARA MODIFICAR AUTOS, PRIMERO DEBE DAR DE ALTA.\n");
                printf("\n________________________________________________________________\n\n");
                system("pause");
                break;
            }
            else
            {
                system("cls");
                printf("\n________________________________________________________________\n\n");
                printf("SELECCIONE UN AUTO: \n");
                mostrarAutos(list, TAM, marcas, TAMMAR, colores, TAMCO);
                printf("Ingrese la patente del auto: ");
                fflush(stdin);
                gets(patente);

                while(buscarIndicePatente(list, TAM, patente)==-1)
                {
                    printf("La patente ingresada no corresponde a ningun auto existente.\n");
                    printf("SELECCIONE UN AUTO: \n");
                    mostrarAutos(list, TAM, marcas, TAMMAR, colores, TAMCO);
                    printf("Ingrese la patente del auto: ");
                    fflush(stdin);
                    gets(patente);
                }
                indice=buscarIndicePatente(list, TAM, patente);
                if(indice==-1)
                {
                    printf("\n________________________________________________________________\n\n");
                    printf("EL ID NO PERTENECE A NINGUNA DE LAS AUTOS EXISTENTES.\n");
                    printf("\n________________________________________________________________\n\n");
                }
                else
                {
                    system("cls");


                    printf("\n________________________________________________________________\n\n");
                    printf("DESEA MODIFICAR ESTE AUTO?: \n");
                    mostrarAuto(list[indice], colores, TAMCO, marcas, TAMMAR);
                    seguir2=validarSeguir();


                    if(seguir2=='S')
                    {
                        switch(menuDos())
                        {
                        case 1:
                            printf("C O L O R E S\n");
                            mostrarColores(colores, TAMCO);
                            list[indice].idColor=getInt("I N G R E S E   C O L O R: ", "COLOR DEBE SER ENTRE 5000 Y 5004.\n", 5000, 5004);
                            break;

                        case 2:
                            printf("\n________________________________________________________________\n\n");
                            list[indice].modeloAnio = getInt("INGRESE ANIO DEL MODELO: ", "ANIO DEBE SER ENTRE 1900 Y 2020.\n", 1900, 2019);
                            break;
                        case 3:
                            break;

                        default:
                            printf("OPCION NO VALIDA.");
                            break;

                        }
                    }
                    else
                    {
                        break;
                    }



                }


            }
            seguir=validarSeguir();
            break;
        case 3:
            system("cls");
            if(flag1==0  && hayAuto(list, TAM)==0)
            {
                printf("________________________________________________________________\n\n");
                printf("PARA DAR DE BAJA AUTOS, PRIMERO DEBE DAR DE ALTA.\n");
                printf("\n________________________________________________________________\n\n");
                system("pause");
                break;
            }
            else
            {
                system("cls");
                printf("\n________________________________________________________________\n\n");
                printf("SELECCIONE UN AUTO: \n");
                mostrarAutos(list, TAM, marcas, TAMMAR, colores, TAMCO);
                printf("INGRESE LA PATENTE DEL AUTO A DAR DE BAJA: ");
                fflush(stdin);
                gets(patente);

                while(buscarIndicePatente(list, TAM, patente)==-1)
                {
                    printf("LA PATENTE INGRESADA NO PERTENECE A NINGUN AUTO EXISTENTE.\n");
                    printf("SELECCIONE UN AUTO: \n");
                    mostrarAutos(list, TAM, marcas, TAMMAR, colores, TAMCO);
                    printf("INGRESE LA PATENTE DEL AUTO A DAR DE BAJA: ");
                    fflush(stdin);
                    gets(patente);
                }
                indice=buscarIndicePatente(list, TAM, patente);
                if(indice==-1)
                {
                    printf("\n________________________________________________________________\n\n");
                    printf("EL ID NO PERTENECE A NINGUNO DE LOS AUTOS EXISTENTES.\n");
                    printf("\n________________________________________________________________\n\n");
                }
                else
                {
                    system("cls");


                    printf("\n________________________________________________________________\n\n");
                    printf("DESEA DAR DE BAJA ESTE AUTO?: \n");
                    mostrarAuto(list[indice], colores, TAMCO, marcas, TAMMAR);
                    seguir2=validarSeguir();
                    if(seguir2=='S')
                    {
                            bajaAuto(list, indice);
                            printf("\n________________________________________________________________\n\n");
                            printf("AUTO PATENE %S DADA DE BAJA EXITOSAMENTE.\n", patente);
                            printf("\n________________________________________________________________\n\n");

                    }
                    else
                    {

                        printf("\n________________________________________________________________\n\n");
                        printf("BAJA AUTO CANCELADA.\n");
                        printf("\n________________________________________________________________\n\n");
                        system("pause");
                        break;
                    }


                }

            }


            seguir=validarSeguir();
            break;
        case 4:
            system("cls");
            if(hayAuto(list,TAM )==0 )
            {
                printf("Para listar autos, primero debe dar de alta algun auto.\n");
                system("pause");
            }else
            {
                printf("ID          PATENTE         MARCA        COLOR       MODELO\n");
                listarXmarcaYpatente(list, TAM, marcas, TAMMAR, colores, TAMCO,aux ) ;
            }

            seguir=validarSeguir();
            break;

        case 5:
            system("cls");
            mostrarMarcas(marcas, TAMMAR);
            seguir=validarSeguir();
            break;

        case 6:
            system("cls");
            mostrarColores(colores, TAMCO);
            seguir=validarSeguir();
            break;
        case 7:
            mostrarServicio(servicio, TAMSER);
            seguir=validarSeguir();
            break;
        case 8:
            if(hayAuto(list, TAM)==1)
            {
                if(buscarLibreT(trabajo, TAMTRA)==-1)
                {
                    printf("NO HAY MAS LUGAR PARA CARGAR TRABAJOS \n") ;
                    system("pause");
                }else
                {
                    addTrabajo(list, TAM, marcas, TAMMAR, colores, TAMCO, servicio, TAMSER, trabajo, TAMTRA);

                }

            }else
            {
                printf("PARA DAR DE ALTA TRABAJO PRIMERO DEBE DAR DE ALTA ALGUN AUTO.\n");
            }

            break;
        case 9:
            system("cls");
            if(hayTrabajo(trabajo, TAMTRA)== 0)
            {
                printf("PARA LISTAR TRABAJOS PRIMERO DEBE DAR DE ALTA \n");
            }
            else
            {
              mostrarTrabajos(trabajo, TAMTRA, list, TAM, servicio,TAMSER);
            }


            seguir=validarSeguir();
            break;
        case 10:
        seguir='N';
        break;

        default:
            system("cls");
            printf("\n________________________________________________________________\n\n");
            printf("LA OPCION INGRESADA NO ES VALIDA.");
            break;
        }


    }while(seguir=='S');

    return 0;
}
