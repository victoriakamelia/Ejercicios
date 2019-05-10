#include <stdio.h>
#include <stdlib.h>
#include "FUNCIONES.H"
#include "PELICULAS.H"
#define TAM 10
#define TAMAC 10
#define TAMGE 5
#include "PELICULAS.H"

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

    do
    {
        switch(menu())
        {
        case 1:
            system("cls");
            if(addPeliculas(list, TAM, actores, TAMAC, generos, TAMGE)==0)
            {
                flag1=1;
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
                    printf("DESEA MODIFICAR ESTA PELICULA?: ");
                    seguir2=validarSeguir();


                    if(seguir2=='S')
                    {
                        switch(menuDos())
                        {
                        case 1:
                            getText("I N G R E S E   N O M B R E: ", "NOMBRE INGRESADO EXCEDE EL PERMITIDO.\n", list[indice].titulo, 50);
                            break;

                        case 3:

                            break;
                        case 4:
                            getInt(list,indice, "I N G R E S E   S E C T O R: ", "SECTOR DEBE SER ENTRE 1 Y 5.\n", 1, 5);
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

                    printf("\n________________________________________________________________\n\n");
                    printf("ESTA PELICULA SE DARA DE BAJA DE FORMA PERMANENTE.\n");
                    seguir2=validarSeguir();
                    if(seguir2=='S')
                    {
                        if(-1)
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

        case 5:
            break;
            seguir='N';
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
