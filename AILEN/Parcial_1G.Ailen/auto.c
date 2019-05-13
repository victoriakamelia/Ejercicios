#include "auto.h"
#include "marca.h"
#include "color.h"
#include "validaciones.h"


/** \brief inicializa a los empleados
 *
 * \param aut[] eAuto
 * \param tamAut int
 * \return void
 *
 */
void inicializarAutos(eAuto aut[], int tamAut)
{
    for(int i=0; i < tamAut; i++)
    {
        aut[i].ocupado = VACIO;
    }
}



/** \brief muestra las opciones al usuario
 *
 * \return int
 *
 */
int menu()
{
    int opcion;
    char valOpcion[2];

    system("cls");
    system("COLOR F0");
    printf("     =================================================\n");
    printf("     #           >>>> MENU DE OPCIONES <<<<          #\n");
    printf("     =================================================\n");
    printf("     |                                               |\n");
    printf("                  1- Alta Auto                        \n");
    printf("     |                                               |\n");
    printf("                  2- Modificacion Auto                \n");
    printf("     |                                               |\n");
    printf("                  3- Baja Auto                        \n");
    printf("     |                                               |\n");
    printf("                  4- Listar x Marca/Patente           \n");
    printf("     |                                               |\n");
    printf("                  5- Listar Marcas                    \n");
    printf("     |                                               |\n");
    printf("                  6- Listar Colores                   \n");
    printf("     |                                               |\n");
    printf("                  7- Listar Servicios                 \n");
    printf("     |                                               |\n");
    printf("                  8- Alta Trabajo                     \n");
    printf("     |                                               |\n");
    printf("                  9- Listar Trabajos                  \n");
    printf("     |                                               |\n");
    printf("                  10- Salir                           \n");
    printf("     |                                               |\n");
    printf("     =================================================\n");
    printf("                                                      \n");
    printf("     Ingrese opcion: ");
    fflush(stdin);
    gets(valOpcion);

    opcion = validarEntero(valOpcion);

    return opcion;
}


/** \brief busca espacio libre, y lo devuelve si esta vacio, si no, salta un mensaje de error
 *
 * \param aut[] eAuto
 * \param tamAut int
 * \return int
 *
 */
int buscarLibreAuto(eAuto aut[], int tamAut)
{

    int indice = -1;

    for(int i=0; i < tamAut; i++)
    {
        if(aut[i].ocupado == VACIO)
        {
            indice = i;
            break;
        }
    }

    return indice;
}



/** \brief permite encontrar un auto mediante su ID
 *
 * \param aut[] eAuto
 * \param tamAut int
 * \param idAuto int
 * \return int
 *
 */
int buscarAuto(eAuto aut[], int tamAut, int idAuto)
{

    int indice = -1;

    for(int i=0; i < tamAut; i++)
    {
        if( aut[i].id == idAuto && aut[i].ocupado == OCUPADO)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


/** \brief permite encontrar una patente comparando con el ingresado
 *
 * \param aut[] eAuto
 * \param tamAut int
 * \param idPatente[] int
 * \return int
 *
 */
int buscarPatente(eAuto aut[], int tamAut, int idPatente[])
{

    int indice = -1;

    for(int i=0; i < tamAut; i++)
    {
        if( stricmp(aut[i].patente,idPatente) == 0 && aut[i].ocupado == OCUPADO)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

/** \brief ingresa los datos del auto a dar de alta
 *
 * \param aut[] eAuto
 * \param tamAut int
 * \param mar[] eMarca
 * \param tamMar int
 * \param col[] eColor
 * \param tamCol int
 * \return void
 *
 */
void altaAutos(eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol)
{
    char patente[6];
    int idMarca;
    char valMarca[4];
    int idColor;
    char valColor[4];
    int modelo;
    char valModelo[4];
    int indice;
    char seguir;

    do
    {

        system("cls");
        printf("Alta Auto\n");


        indice = buscarLibreAuto(aut,tamAut);

        if(indice == -1)
        {
            printf("No hay mas espacio para cargar autos\n");
            printf("\n\n");
            system("pause");
            break;
        }
        else
        {

            printf("Ingrese patente: ");
            fflush(stdin);
            gets(patente);

            ValidarPatente(patente);

            if(buscarPatente(aut,tamAut,patente)!=-1)
            {
                printf("La patente %s ya esta en uso\n",patente);
                system("pause");
                break;
            }
            else
            {
                strcpy(aut[indice].patente,patente);

                listarMarcas(mar,tamMar);
                printf("Ingrese ID Marca: ");
                fflush(stdin);
                gets(valMarca);

                idMarca = validarEnteroRango(valMarca,1000,1004);

                aut[indice].idMarca = idMarca;

                listarColores(col,tamCol);
                printf("Ingrese ID Color: ");
                fflush(stdin);
                gets(valColor);

                idColor = validarEnteroRango(valColor,5000,5004);

                aut[indice].idColor = idColor;

                printf("Ingrese modelo (anio de fabricacion): ");
                fflush(stdin);
                gets(valModelo);

                modelo = validarEnteroRango(valModelo,1970,2019);

                aut[indice].id = cargarId();

                aut[indice].modelo = modelo;

                aut[indice].ocupado = OCUPADO;


                printf("El Auto se ha registrado con exito!!\n");


                seguir = validarSeguir();

            }
        }
    }
    while(seguir == 'S' || seguir == 's');
}


/** \brief muestra los datos de un auto
 *
 * \param aut eAuto
 * \param mar[] eMarca
 * \param tamMar int
 * \param col[] eColor
 * \param tamCol int
 * \return void
 *
 */
void mostrarAuto(eAuto aut, eMarca mar[], int tamMar, eColor col[], int tamCol)
{
    char marca[20];
    char color[20];

    for(int i=0; i<tamMar; i++)
    {
        if(mar[i].id == aut.idMarca)
        {
            strcpy(marca,mar[i].descripcion);
            break;
        }
    }

    for(int j=0; j<tamCol; j++)
    {
        if(col[j].id == aut.idColor)
        {
            strcpy(color,col[j].nombreColor);
            break;
        }
    }

    printf("%4d %8s %9s %6s %6d\n", aut.id, aut.patente, marca, color, aut.modelo);

}



/** \brief muestra los datos de todos los autos mediante un recorrido de todo el array
 *
 * \param aut[] eAuto
 * \param tamAut int
 * \param mar[] eMarca
 * \param tamMar int
 * \param col[] eColor
 * \param tamCol int
 * \return void
 *
 */
void mostrarAutos(eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol)
{
    int flag = 0;

    system("cls");
    printf("  ID   Patente   Marca   Color   Modelo\n\n");


    for(int i=0; i<tamAut; i++)
    {
        if(aut[i].ocupado == OCUPADO)
        {
            mostrarAuto(aut[i],mar,tamMar,col,tamCol);
            flag = 1;
        }
    }


    if(flag == 0)
    {
        printf("No hay autos cargados\n");

    }
}

/** \brief da de baja un auto, segun su patente
 *
 * \param aut[] eAuto
 * \param tamAut int
 * \param mar[] eMarca
 * \param tamMar int
 * \param col[] eColor
 * \param tamCol int
 * \return void
 *
 */
void bajaAuto(eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol)
{

    char patente[6];
    char seguir;
    int esta;

    printf("Baja Auto\n");
    printf("\n\n");

    mostrarAutos(aut,tamAut,mar,tamMar,col,tamCol);

    printf("Ingrese patente: ");
    fflush(stdin);
    gets(patente);

    esta = buscarPatente(aut,tamAut,patente);

    if( esta == -1)
    {

        printf("\nLa patente %s no esta registrada en el sistema\n", patente);
    }
    else
    {
        printf("Auto a eliminar\n");

        mostrarAuto(aut[esta],mar,tamMar,col,tamCol);

        seguir = validarSeguir();

        if(seguir == 's' || seguir == 'S')
        {
            aut[esta].ocupado = VACIO;
            printf("\nAuto eliminado con exito\n");
        }
        else
        {
            printf("\nLa eliminacion ha sido cancelada\n");
        }

    }


    }


/** \brief modifica los valores a elegir por parte del usuario
 *
 * \param aut[] eAuto
 * \param tamAut int
 * \param mar[] eMarca
 * \param tamMar int
 * \param col[] eColor
 * \param tamCol int
 * \return void
 *
 */
void ModificacionAuto(eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol)
{

    char patente[6];
    int idColor;
    char valColor[4];
    int idModelo;
    char valModelo[4];
    int opcion;
    char valOpcion[2];
    int esta;
    char seguir;

    printf("Modificacion Auto\n");
    printf("\n\n");

    mostrarAutos(aut,tamAut,mar,tamMar,col,tamCol);

    printf("Ingrese patente: ");
    fflush(stdin);
    gets(patente);

    esta = buscarPatente(aut,tamAut,patente);


    if( esta == -1)
    {

        printf("\nLa patente %s no esta registrada en el sistema\n", patente);
    }
    else
    {
        printf("\n\n");
        system("cls");
        printf("Auto a modificar\n");
        mostrarAuto(aut[esta],mar,tamMar,col,tamCol);

        printf("     Que desea modificar?\n");
        printf("     1. Color\n     2. Modelo\n");
        printf("     Ingrese opcion: ");
        fflush(stdin);
        gets(valOpcion);

        opcion = validarEntero(valOpcion);

        switch(opcion)
        {
        case 1:
            system("cls");

            printf("Modificar Color\n");

            listarColores(col,tamCol);

            printf("Ingrese un nuevo color: ");
            fflush(stdin);
            gets(valColor);

            idColor = validarEnteroRango(valColor,5000,5004);

            seguir = validarSeguir();

            if(seguir == 's' || seguir == 'S')
            {

                aut[esta].idColor = idColor;

                printf("\n\n");
                printf("     Modificacion exitosa!\n");

            }
            else
            {
                printf("\n\n");
                printf("     Modificacion cancelada\n");
            }
            break;

        case 2:
            system("cls");

            printf("Modificar Modelo\n");

            printf("Ingrese un nuevo modelo: ");
            fflush(stdin);
            gets(valModelo);

            idModelo = validarEnteroRango(valModelo,1970,2019);

            seguir = validarSeguir();

            if(seguir == 's' || seguir == 'S')
            {

                aut[esta].modelo = idModelo;

                printf("\n\n");
                printf("     Modificacion exitosa!\n");

            }
            else
            {
                printf("\n\n");
                printf("     Modificacion cancelada\n");
            }
            break;

        default:
            printf("Esta opcion no existe\n");
            break;

        }
    }

}

/** \brief lista los autos por marca y patente
 *
 * \param aut[] eAuto
 * \param tamAut int
 * \param mar[] eMarca
 * \param tamMar int
 * \param col[] eColor
 * \param tamCol int
 * \return void
 *
 */
void listarAutos(eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol)
{
   eAuto aux;

   for(int i=0; i<tamAut-1; i++)
   {
       for(int j=i+1; j<tamAut; j++)
       {
           if(aut[i].idMarca > aut[j].idMarca)
           {
               aux = aut[i];
               aut[i] = aut[j];
               aut[j] = aux;
           }
           else if(aut[i].idMarca == aut[j].idMarca && stricmp(aut[i].patente,aut[j].patente)>0)
           {
               aux = aut[i];
               aut[i] = aut[j];
               aut[j] = aux;
           }
       }
   }

   mostrarAutos(aut,tamAut,mar,tamMar,col,tamCol);

}
/** \brief harcodea datos de los autos
 *
 * \param
 * \param
 * \return
 *
 */

void harcodeAutos(eAuto aut[], int tamAut)
{
    eAuto hardcode[]=
    {
        {1, "abc123", 1000, 5001,2000,1},
        {2, "awf818", 1000, 5002,2019,1},
        {3, "knj605", 1004, 5000,1971,1},
        {4, "biu587", 1002, 5001,1980,1},
        {5, "dlb011", 1001, 5003,2010,1},
        {6, "weg260", 1001, 5004,2011,1},
        {7, "www234", 1003, 5000,2015,0},
        {8, "sew899", 1004, 5003,2019,0},
        {9, "aem769", 1002, 5002,2000,0},
        {10, "kdm285", 1003, 5002,2012,0}

    };


    for(int i=0; i<tamAut; i++)
    {
        aut[i]=hardcode[i];
    }
}
