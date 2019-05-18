#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "PELI.h"
#define TAM 10
#define TAMAC 10
#define TAMGE 5
#define OCUPADO 1
#define VACIO 0


int main()
{
    ePeliculas list[TAM];

    eActores actores[TAMAC] =
    {
        {1000, "ANA ANITA", "CHILE"},
        {1001, "JOSE JOSECITO", "JAPON"},
        {1002, "INES INECITA", "FRANCIA"},
        {1003, "PEPE PEPECITO", "URUGUAY"},
        {1004, "MATILDA MATI", "ARGENTINA"},
        {1005, "ANDRES ANDRESI", "BOLIVIA"},
        {1006, "MARCELO MARCK", "EEUU"},
        {1007, "LEILA LEI", "VENEZUELA"},
        {1008, "FRAN FRANCO", "ITALIA"},
        {1009, "MERCEDES MER", "FRANCIA"}

    };

    eGenero generos[TAMGE]=
    {
        {1, "DRAMA"},
        {2, "ACCION"},
        {3, "INFANTIL"},
        {4, "POLICIAL"},
        {5, "TERROR"}
    };
    char seguir='S';
    char seguir2;
    char idStr[20];

    int flag1=0;
    int idBaja;
    int idModificar;
    int indice;

    initPeliculas(list,TAM);
    initActores(actores, TAMAC);

    do
    {
        switch(menu())
        {
        case 1:
            system("cls");
            if(hayActor(actores, TAMAC)==1)
            {
                if(addPeliculas(list, TAM, actores, TAMAC, generos, TAMGE)==0)
                {
                   flag1=1;
                }

            }else
            {
                printf("Parada dar de alta una pelicula primero debe dar de alta un actor.");
            }
            seguir=validarSeguir();
            break;
        case 2:
            system("cls");
            if(flag1==0 || hayPelicula(list, TAM)==0)
            {
                printf("________________________________________________________________\n\n");
                printf("PARA MODIFICAR PELICULAS, PRIMERO DEBE DAR DE ALTA.\n");
                printf("\n________________________________________________________________\n\n");
                system("pause");
                break;
            }
            else
            {
                system("cls");
                printf("\n________________________________________________________________\n\n");

                printf("INGRESE EL ID DE LA PELICULA A MODIFICAR: ");
                fflush(stdin);
                scanf("%s", idStr);
                while(esNumerico(idStr)==0)
                {
                    printf("\n________________________________________________________________\n\n");
                    printf("EL ID DEBE SER NUMERICO.\n");
                    printf("\n________________________________________________________________\n\n");
                    printf("INGRESE EL ID DE LA PELICULA A MODIFICAR: ");
                    fflush(stdin);
                    scanf("%s", idStr);
                }
                idModificar=atoi(idStr);
                indice=buscarId(list, TAM, idModificar);
                if(indice==-1)
                {
                    printf("\n________________________________________________________________\n\n");
                    printf("EL ID NO PERTENECE A NINGUNA DE LAS PELICULAS EXISTENTES.\n");
                    printf("\n________________________________________________________________\n\n");
                }
                else
                {
                    system("cls");


                    printf("\n________________________________________________________________\n\n");
                    printf("DESEA MODIFICAR ESTA PELICULA?: \n");
                    mostrarPelicula(list[indice],generos, TAMGE, actores, TAMAC);
                    seguir2=validarSeguir();


                    if(seguir2=='S')
                    {
                        switch(menuDos())
                        {
                        case 1:
                            getText("I N G R E S E   T I T U L O: ", "TITULO INGRESADO EXCEDE EL PERMITIDO.\n", list[indice].titulo, 50);
                            break;

                        case 2:
                            printf("A C T O R E S\n");
                            mostrarActores(actores, TAMAC);
                            list[indice].idActor=getInt("I N G R E S E   A C T O R: ", "ACTOR DEBE SER ENTRE 1000 Y 1009.\n", 1000, 1009);
                            break;
                        case 3:
                            printf("\n________________________________________________________________\n\n");
                            getFecha(list, indice);
                            break;
                        case 4:
                            break;
                        default:
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
            if(hayPelicula(list, TAM)==0)
            {
                printf("________________________________________________________________\n\n");
                printf("PARA DAR DE BAJA PELICULAS, PRIMERO DEBE DAR DE ALTA.\n");
                printf("\n________________________________________________________________\n\n");
                system("pause");
                break;

            }
            else
            {
                printf("\n________________________________________________________________\n\n");
                printf("INGRESE EL ID DE LA PELICULA A DAR DE BAJA: ");
                fflush(stdin);
                scanf("%s", idStr);

                while(esNumerico(idStr)==0)
                {
                    printf("\n________________________________________________________________\n\n");
                    printf("EL ID DEBE SER NUMERICO.\n");
                    printf("\n________________________________________________________________\n\n");
                    printf("INGRESE EL ID DE LA PELICULA A DAR DE BAJA: ");
                    fflush(stdin);
                    scanf("%s", idStr);
                }
                idBaja=atoi(idStr);
                indice=buscarId(list, TAM, idBaja);

                if(indice==-1)
                {
                    printf("\n________________________________________________________________\n\n");
                    printf("EL ID NO PERTENECE A NINGUNA DE LAS PELICULAS EXISTENTES\n");

                }
                else
                {
                    printf("\n________________________________________________________________\n\n");
                    printf("PELICULA A DAR DE BAJA: \n");
                     mostrarPelicula(list[indice],generos, TAMGE, actores, TAMAC);
                    printf("\n________________________________________________________________\n\n");
                    printf("ESTA PELICULA SE DARA DE BAJA DE FORMA PERMANENTE.\n");
                    seguir2=validarSeguir();
                    if(seguir2=='S')
                    {
                        if(bajaPelicula(list, TAM, idBaja)==-1)
                        {
                            printf("\n________________________________________________________________\n\n");
                            printf("NO SE PUDO DAR DE BAJA LA PELICULA SOLICITADA.\n");
                            printf("\n________________________________________________________________\n\n");
                        }
                        else
                        {
                            printf("\n________________________________________________________________\n\n");
                            printf("PELICULA ID %d DADA DE BAJA EXITOSAMENTE.\n", idBaja);
                            printf("\n________________________________________________________________\n\n");
                        }
                    }
                    else
                    {

                        printf("\n________________________________________________________________\n\n");
                        printf("BAJA PELICULA CANCELADA.\n");
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
            if(altaActor(actores, TAMAC)==-1)
            {
                printf("No queda lugar disponible para dar de alta actores.\n");
            }
            seguir=validarSeguir();
            break;

        case 5:
            system("cls");
            if(hayPelicula(list, TAM)==0)
            {
                printf("________________________________________________________________\n\n");
                printf("PARA VER INFORMES PRIMERO DEBE DAR DE ALTA.\n");
                printf("\n________________________________________________________________\n\n");
                system("pause");
                break;

            }
            else
            {
                system("cls");

            }

            seguir=validarSeguir();
            break;

        case 6:
            seguir='N';
            break;

        default:
            system("cls");
            printf("\n________________________________________________________________\n\n");
            printf("LA OPCION INGRESADA NO ES VALIDA.");
            break;
        }


    }
    while(seguir=='S');

    return 0;
}
