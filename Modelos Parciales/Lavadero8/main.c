#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "utn.h"
#include "auto.h"
#define TAM 22
#define TAMMAR 5
#define TAMCO 5
#define TAMSER 4
#define TAMTRA 35
#define OCUPADO 1
#define VACIO 0


int main()
{
    eAuto list[TAM]=
    {
       {1, "AAA 201", 1000, 5001, 1995, 1},
       {2, "DFR 234", 1003, 5000, 2002, 1},
       {3, "GFT 564", 1002, 5003, 2007, 1},
       {4, "ACD 321", 1002, 5003, 1995, 1},
       {5, "HTD 656", 1004, 5002, 2008, 1},
       {6, "QSZ 435", 1003, 5001, 1994, 1},
       {7, "LGX 201", 1001, 5000, 2012, 1},
       {8, "SUZ 324", 1001, 5002, 1991, 1},
       {9, "HCU 762", 1000, 5003, 2008, 1},
       {10, "DYC 735", 1003, 5001, 2002, 1},
       {11, "JJK 879", 1003, 5001, 2010, 1},
       {12, "FED 322", 1004, 5002, 2006, 1},
       {13, "GHV 332", 1001, 5003, 2007, 1},
       {14, "BDE 221", 1000, 5004, 1996, 1},
       {15, "OPD 332", 1000, 5001, 2014, 1},
       {16, "PPD 121", 1002, 5001, 2015, 1},
       {17, "IIT 230", 1001, 5000, 2009, 1},
       {18, "KOD 220", 1004, 5002, 2011, 1},
       {19, "QSZ 305", 1004, 5002, 1993, 1},
       {20, "SSD 128", 1002, 5003, 1992, 1},
       {21, "SSD 240", 1003, 5004, 1992, 1},
       {22, "EDF 213", 1001, 5000, 2001, 1},
   };


    eAuto aux;
    eTrabajo trabajo[TAMTRA]= {
        {1, "AAA 201", 20000, {12,3,2019}, 1},
       {2, "DFR 234", 20000, {2,4,2019}, 1},
       {3, "GFT 564", 20001, {7,1,2019}, 1},
       {4, "ACD 321", 20002, {9,11,2019}, 1},
       {5, "HTD 656", 20003, {12,12,2019}, 1},
       {6, "QSZ 435", 20001, {21,7,2019}, 1},
       {7, "LGX 201", 20001, {29,8,2019}, 1},
       {8, "SUZ 324", 20004, {31,5,2019}, 1},
       {9, "HCU 762", 20004, {2,2,2019}, 1},
       {10, "DYC 735", 20000, {18,2,2019}, 1},
       {11, "JJK 879", 20001, {17,3,2019}, 1},
       {12, "AAA 201", 20000, {17,4,2019}, 1},
       {13, "DFR 234", 20000, {2,6,2019}, 1},
       {14, "GFT 564", 20001, {7,3,2019}, 1},
       {15, "ACD 321", 20002, {21,7,2019}, 1},
       {16, "HTD 656", 20003, {11,9,2019}, 1},
       {17, "QSZ 435", 20001, {3,7,2019}, 1},
       {18, "LGX 201", 20001, {21,8,2019}, 1},
       {19, "SUZ 324", 20004, {28,5,2019}, 1},
       {20, "HCU 762", 20004, {2,8,2019}, 1},
       {21, "DYC 735", 20000, {8,2,2019}, 1},
       {22, "JJK 879", 20001, {17,3,2019}, 1},
       {23, "KOD 220", 20003, {17,4,2019}, 1},
       {24, "QSZ 305", 20000, {21,3,2019}, 1},
       {25, "SSD 128", 20002, {16,4,2019}, 1},
       {26, "SSD 240", 20000, {17,4,2019}, 1},
       {27, "EDF 213", 20001, {23,3,2019}, 1},
       {28, "AAA 201", 20000, {12,2,2019}, 1},
       {29, "DFR 234", 20000, {2,3,2019}, 1},
       {30, "GFT 564", 20001, {7,2,2019}, 1},
       {31, "ACD 321", 20002, {9,12,2019}, 1},
       {32, "HTD 656", 20003, {12,9,2019}, 1},
       {33, "QSZ 435", 20001, {21,5,2019}, 1},
       {34, "HTD 656", 20002, {12,2,2019}, 1},
       {35, "QSZ 435", 20000, {21,1,2019}, 0},
   };
    eTrabajo auxTra;
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

    //initAutos(list,TAM);
    //initTrabajo(trabajo, TAMTRA);

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
                            printf("AUTO PATENE %s DADA DE BAJA EXITOSAMENTE.\n", patente);
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
            //listados
            switch(menuTres())
            {
            case 1:
                autoColorNegro(list, TAM, colores, TAMCO, marcas, TAMMAR, aux);
                system("pause");
                seguir=validarSeguir();
                break;
            case 2:
                autosDeUnaMarca(list, TAM, colores, TAMCO, marcas, TAMMAR, aux);
                system("pause");
                seguir=validarSeguir();
                break;
            case 3:
                trabajoUnAutoSeleccionado(list, TAM, trabajo, TAMTRA, servicio, TAMSER, marcas, TAMMAR, colores, TAMCO, auxTra);
                system("pause");
                seguir=validarSeguir();
                break;
            case 4:
               /*autosSinTrabajo(trabajo, TAMTRA, list, TAM, aux, colores, TAMCO, marcas, TAMMAR);
               system("pause");
               seguir=validarSeguir();*/
                break;
            case 5:
                importexAuto(list, TAM, trabajo, TAMTRA, servicio, TAMSER, marcas, TAMMAR, colores, TAMCO);
                system("pause");
                seguir=validarSeguir();
                break;
            case 6:
                /*ServicioMasPedido(servicio, TAMSER, trabajo, TAMTRA);
                system("pause");
                seguir=validarSeguir();*/
                break;
            case 7:

                break;

            }
        case 11:
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
