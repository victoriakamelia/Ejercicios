#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "PELI.h"
#define TAM 10
#define TAMMAR 5
#define TAMCO 5
#define TAMSER 4
#define TAMTRA 5
#define OCUPADO 1
#define VACIO 0


int main()
{
    eAuto list[TAM]=
    {
        {1000, "QWE 113", 1000, 5000, 1999,1},
        {1001, "ZWE 143", 1001, 5004, 2000, 1},
        {1002, "RWE 623", 1003, 5001, 1999, 1},
        {1003, "TWE 723", 1000, 5002, 1999, 1},
        {1004, "GWE 823", 1005, 5003, 1999, 1},
        {1005, "IHE 923", 1001, 5000, 1999, 1}
    };

   eAuto aux;
    eTrabajo trabajo[TAMTRA];




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
    char idStr[20];

    int flag1=0;
    int idBaja;
    int idModificar;
    int indice;

    initautos(list,TAM);


    do
    {
        switch(menu())
        {
        case 1:
            system("cls");
              if(addautos(list, TAM, marcas, TAMMAR, colores, TAMCO)==0)
                {
                   flag1=1;
                }

            seguir=validarSeguir();
            break;
        case 2:
            system("cls");
            if(flag1==0 || hayauto(list, TAM)==0)
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

                printf("INGRESE EL ID DEL AUTO A MODIFICAR: ");
                fflush(stdin);
                scanf("%s", idStr);
                while(esNumerico(idStr)==0)
                {
                    printf("\n________________________________________________________________\n\n");
                    printf("EL ID DEBE SER NUMERICO.\n");
                    printf("\n________________________________________________________________\n\n");
                    printf("INGRESE EL ID DE LA auto A MODIFICAR: ");
                    fflush(stdin);
                    scanf("%s", idStr);
                }
                idModificar=atoi(idStr);
                indice=buscarId(list, TAM, idModificar);
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
                    mostrarauto(list[indice], colores, TAMCO, marcas, TAMMAR);
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
                            list[indice].modeloAnio = getInt("INGRESE AÑO DEL MODELO: ", "AÑO DEBE SER ENTRE 1900 Y 2020.\n", 1900, 2020);
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
            if(hayauto(list, TAM)==0)
            {
                printf("________________________________________________________________\n\n");
                printf("PARA DAR DE BAJA AUTO, PRIMERO DEBE DAR DE ALTA.\n");
                printf("\n________________________________________________________________\n\n");
                system("pause");
                break;

            }
            else
            {
                printf("\n________________________________________________________________\n\n");
                printf("INGRESE EL ID DEL AUTO A DAR DE BAJA: ");
                fflush(stdin);
                scanf("%s", idStr);

                while(esNumerico(idStr)==0)
                {
                    printf("\n________________________________________________________________\n\n");
                    printf("EL ID DEBE SER NUMERICO.\n");
                    printf("\n________________________________________________________________\n\n");
                    printf("INGRESE EL ID DEL  AUTOPA DAR DE BAJA: ");
                    fflush(stdin);
                    scanf("%s", idStr);
                }
                idBaja=atoi(idStr);
                indice=buscarId(list, TAM, idBaja);

                if(indice==-1)
                {
                    printf("\n________________________________________________________________\n\n");
                    printf("EL ID NO PERTENECE A NINGUNA DE L0S AUTOS EXISTENTES\n");

                }
                else
                {
                    printf("\n________________________________________________________________\n\n");
                    printf("AUTOS A DAR DE BAJA: \n");
                    mostrarauto(list[indice], colores, TAMCO, marcas, TAMMAR);
                    printf("\n________________________________________________________________\n\n");
                    printf("ESTE AUTO SE DARA DE BAJA DE FORMA PERMANENTE.\n");
                    seguir2=validarSeguir();
                    if(seguir2=='S')
                    {
                        if(bajaauto(list, TAM, idBaja)==-1)
                        {
                            printf("\n________________________________________________________________\n\n");
                            printf("NO SE PUDO DAR DE BAJA EL AUTO SOLICITADO.\n");
                            printf("\n________________________________________________________________\n\n");
                        }
                        else
                        {
                            printf("\n________________________________________________________________\n\n");
                            printf("AUTO ID %d DADA DE BAJA EXITOSAMENTE.\n", idBaja);
                            printf("\n________________________________________________________________\n\n");
                        }
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
            if(hayauto(list, TAM)==1)
            {
                //FALTA FUNCION MOSTRAR AUTOSSSSS
                printf("ID          PATENTE         MARCA        COLOR       MODELO\n");
                listarXmarcaYpatente(list, TAM, marcas, TAMMAR, colores, TAMCO, aux);
            }else
            {
                printf("PARA LISTAR AUTOS PRIMERO DEBE DAR DE ALTA ALGUN AUTO.\n");
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
            if(hayauto(list, TAM)==1)
            {
               addTrabajo(list, TAM, marcas, TAMMAR, colores, TAMCO, servicio, TAMSER, trabajo, TAMTRA);
            }else
            {
                printf("PARA DAR DE ALTA TRABAJO PRIMERO DEBE DAR DE ALTA ALGUN AUTO.\n");
            }

            break;
        case 9:
            system("cls");
            for(int i=0; i<TAMTRA; i++)
            {
                mostarTrabajo(trabajo[i]);
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
