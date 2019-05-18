#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "FUNCIONES.H"
#include "PELICULAS.H"
#define TAM 10
#define TAMAC 10
#define TAMGE 5
#define OCUPADO 1
#define VACIO 0

/**********************************************************************************************************/

/** \brief genera automaticamente un id y solicita por pantalla datos para dar de alta un empleado.
 *
 * \param list[] ePeliculas con el array de empleados a cargar.
 * \param tam int con el tamaño del array a cargar.
 * \param sector[] eActores con el tamaño del array a recorrer.
 * \param tamSec int con el tamaño del array a recorrer.
 * \return int retorna -1 si pudo dar de alta o 0 si lo logró.
 *
 */

int addPeliculas(ePeliculas list[], int tam, eActores actor[], int tamAc, eGenero generos[], int tamGe)
{
    int retorno=-1;
    int id=generarId();
    int indice=buscarLibre(list, TAM);

    if(buscarLibre(list, tam)==-1)
    {
        printf("\n________________________________________________________________\n\n");
        printf("NO QUEDA LUGAR DISPONIBLE PARA GENERAR PELICULAS.\n");
    }
    else
    {
        getText("I N G R E S E   T I T U L O: ", "TITULO INGRESADO EXCEDE EL PERMITIDO.\n", list[indice].titulo, 50);
        printf("\n________________________________________________________________\n\n");
        printf("G E N E R O S\n");
        mostrarGeneros(generos,tamGe);
        getInt(list,indice, "I N G R E S E   G E N E R O: ", "SECTOR DEBE SER ENTRE 1 Y 5.\n", 1, 5, list[indice].idGenero);
        printf("\n________________________________________________________________\n\n");
        getFecha(list, indice);
        printf("A C T O R E S\n");
        mostrarActores(actor, TAMAC);
        getInt(list,indice, "I N G R E S E   A C T O R: ", "ACTOR DEBE SER MAYOR A CERO.\n", 1, 50, list[indice].idActor);
        printf("\n________________________________________________________________\n\n");


        printf("PELICULA id %d GENERADA EXITOSAMENTE.\n", id);

        list[indice].id=id;
        list[indice].isEmpty=OCUPADO;


        retorno=0;

    }

    return retorno;
}

/**********************************************************************************************************/

/** \brief Inicializa un array
 *
 * \param list[] Employee con el array a ser recorrido.
 * \param tam int con el tamaño del array a recorrer.
 * \return int -1 si no pudo inicializar o 0 si lo logró.
 *
 */
int initPeliculas(ePeliculas list[],int tam)
{
    int retorno = -1;
    int i;
    if(tam > 0 && list != NULL)
    {
        retorno = 0;
        for(i=0; i<tam; i++)
        {
            list[i].isEmpty=0;

        }
    }
    return retorno;
}

/**********************************************************************************************************/

/** \brief Solicita un texto por pantalla al usuario y lo valida.
 *
 * \param texto[] char con el mensaje a mostrar para solicitar el dato por pantalla.
 * \param textoError[] char con el mensaje a mostrar en caso de error.
 * \param cadena[] char con la cadena en donde se guardará el texto.
 * \param largo int con el tamaño de la cadena en donde se guardará el texto.
 * \return void
 *
 */
void getText(char texto[], char textoError[], char cadena[], int largo)
{
    char auxChar[100];
    printf("\n________________________________________________________________\n\n");
    printf("\n%s", texto);
    fflush(stdin);
    gets(auxChar);
    while(esSoloLetras(auxChar)==0)
    {
        printf("\n________________________________________________________________\n\n");
        printf("\nSOLO DEBE INGRESAR LETRAS, REINTENTE: ");
        gets(auxChar);

    }
    while(strlen(auxChar)>= largo)
    {
        printf("\n________________________________________________________________\n\n");
        printf("\n%s", texto);
        printf("\n%s", textoError);
        gets(auxChar);

    }
    strcpy(cadena, auxChar);


}

/**********************************************************************************************************/

/** \brief Recorre un array para verificar si al menos hay un registro ocupado,
 *
 * \param list[]  con el array a recorrer.
 * \param tam int con el tamaño del array a recorrer.
 * \return int 0 si no pudo lograr el objetivo o 1 si lo logró.
 *
 */
int hayPelicula(ePeliculas list[], int tam)
{
    int retorno=0;
    int i;
    for(i=0; i<tam; i++)
    {
        if(list[i].isEmpty==OCUPADO)
        {
            retorno=1;
            break;
        }
    }

    return retorno;
}

/**********************************************************************************************************/

/** \brief Imprime un menú de opciones para que el usuario seleccione.
 *
 * \return int seleccionado por el usuario, validado.
 *
 */
int menu()
{
    int opcion;
    char opcionStr[20];

    system("cls");
    system("color 57");
    printf("   .-.     .-.     .-.     .-.     .-.     .-.     .-.     .-.     .-. \n");
    printf(" .'   `._.'   `._.'   `._.'   `._.'   `._.'   `._.'   `._.'   `._.'   `.\n");
    printf("(    .     .-.     .-.     .-.     .-.     .-.     .-.     .-.     .    )\n");
    printf(" `.   `._.'   `._.'   `._.'   `._.'   `._.'   `._.'   `._.'   `._.'   .'\n");
    printf("   )    )                                                       (    (\n");
    printf(" ,'   ,'             M E N U   D E   O P C I O N E S.            `.   `.\n");
    printf("(    (                                                             )    )\n");
    printf(" `.   `.                   1)ALTA PELICULA.                      .'   .' \n");
    printf("   )    )                                                      (    (\n");
    printf(" ,'   ,'                   2)MODIFICAR PELICULA.                `.   `.\n");
    printf("(    (                                                            )    )\n");
    printf(" `.   `.                   3)BAJA PELICULA.                      .'   .' \n");
    printf("   )    )                                                      (    (\n");
    printf(" ,'   ,'                   4)INFORMES.                          `.   `.\n");
    printf("(    (                                                            )    )\n");
    printf(" `.   `.                   5)SALIR.                              .'   .' \n");
    printf("   )    )       _       _       _       _       _       _       (    (\n");
    printf(" ,'   .' `.   .' `.   .' `.   .' `.   .' `.   .' `.   .' `.   .' `.   `.\n");
    printf("(    '  _  `-'  _  `-'  _  `-'  _  `-'  _  `-'  _  `-'  _  `-'  _  `    )\n");
    printf("`.   .' `.   .' `.   .' `.   .' `.   .' `.   .' `.   .' `.   .' `.   .'\n");
    printf("  `-'     `-'     `-'     `-'     `-'     `-'     `-'     `-'     `-'\n");
    printf("->->->->->->->->->->->->->->->->-->->->-INGRESE OPCION SELECCIONADA: ");
    scanf("%s", opcionStr);
    printf("\n\n\n");
    while(esNumerico(opcionStr)==0)
    {
        printf("->->->->->->->->->->->->->-LA OPCION SELECCIONADA DEBE SER NUMERICA: ");
        fflush(stdin);
        scanf("%s", opcionStr);
    }
    opcion=atoi(opcionStr);

    return opcion;
}

/**********************************************************************************************************/

/** \brief recorre un array buscando el indice del id solicitado.
 *
 * \param emp[] Employee con el array a recorrer.
 * \param tam int con el tamaño del array a recorrer.
 * \param id int con el id del sector cuyo indice se desea conocer.
 * \return int retorna -1 si no encontro el indice y el numero del indice si lo encontró.
 *
 */
int buscarId(ePelicula list[], int tam, int id)
{
    int i;
    int retorno=-1;
    for(i=0; i<tam; i++)
    {
        if(list[i].id==id && list[i].isEmpty == OCUPADO)
        {
            retorno=i;


            break;
        }

    }

    return retorno;
}
/**********************************************************************************************************/

/** \brief Imprime un menú de opciones pra que el usuario elija.
 *
 * \return int seleccionado por el usuario.
 *
 */
int menuDos()
{
    int opcion;
    system("cls");
    system("color 57");
    printf("   .-.     .-.     .-.     .-.     .-.     .-.     .-.     .-.     .-. \n");
    printf(" .'   `._.'   `._.'   `._.'   `._.'   `._.'   `._.'   `._.'   `._.'   `.\n");
    printf("(    .     .-.     .-.     .-.     .-.     .-.     .-.     .-.     .    )\n");
    printf(" `.   `._.'   `._.'   `._.'   `._.'   `._.'   `._.'   `._.'   `._.'   .'\n");
    printf("   )    )                                                       (    (\n");
    printf(" ,'   ,'       M E N U   D E   M O D I F I C A C I O N E S.      `.   `.\n");
    printf("(    (                                                             )    )\n");
    printf(" `.   `.                   1)Modificar titulo.                   .'   .' \n");
    printf("   )    )                                                      (    (\n");
    printf(" ,'   ,'                   2)Modificer apellido.                `.   `.\n");
    printf("(    (                                                            )    )\n");
    printf(" `.   `.                   3)Modificar salario.                 .'   .' \n");
    printf("   )    )                                                      (    (\n");
    printf(" ,'   ,'                   4)Modificer sector.                  `.   `.\n");
    printf("(    (                                                            )    )\n");
    printf(" `.   `.                                                         .'   .' \n");
    printf("   )    )       _       _       _       _       _       _       (    (\n");
    printf(" ,'   .' `.   .' `.   .' `.   .' `.   .' `.   .' `.   .' `.   .' `.   `.\n");
    printf("(    '  _  `-'  _  `-'  _  `-'  _  `-'  _  `-'  _  `-'  _  `-'  _  `    )\n");
    printf("`.   .' `.   .' `.   .' `.   .' `.   .' `.   .' `.   .' `.   .' `.   .'\n");
    printf("  `-'     `-'     `-'     `-'     `-'     `-'     `-'     `-'     `-'\n");
    printf("->->->->->->->->->->->->->->->->-->->->-INGRESE OPCION SELECCIONADA: ");
    scanf("%d",&opcion);

    return opcion;


}


void mostrarActores(eActores actor[], int tamAc)
{
    int i;
    printf("\n________________________________________________________________\n\n");
    printf("ID ACTOR  -  NOMBRE -  NACIONALIDAD\n\n");
    for(i=0; i<tamAc; i++)
    {
        printf("%5d         %10s         %10s\n", actor[i].id, actor[i].nombre, actor[i].pais);
    }

}

void mostrarGenero(eGenero genero[], int tamGe)
{
    int i;
    printf("\n________________________________________________________________\n\n");
    printf("ID GENERO  -  DESCRIPCION\n\n");
    for(i=0; i<tamGe; i++)
    {
        printf("%5d         %10s\n", genero[i].id, genero[i].nombre);
    }


}

int generarId()
{
    static int id=1000;

    return id++;
}

void getFecha(ePeliculas pelicula[], int indice)
{
    char numero[4];
    int fecha;

    printf("INGRESE DIA DE ESTRENO: ");
    fflush(stdin);
    scanf("%s", numero);

       while(esNumerico(numero)==-1)
    {
        printf("DIA DE ESTRENO DEBE SER NUMERICO\n");
        fflush(stdin);
        printf("INGRESE DIA DE ESTRENO: ");
        scanf("%s", numero);
    }

    fecha=atoi(numero);
    pelicula[indice].fechaEstreno.dia=fecha;

    printf("INGRESE MES DE ESTRENO: ");
    fflush(stdin);
    scanf("%s", numero);

    while(esNumerico(numero)==-1)
    {
        printf("MES DE ESTRENO DEBE SER NUMERICO\n");
        fflush(stdin);
        printf("INGRESE MES DE ESTRENO: ");
        scanf("%s", numero);
    }
    fecha=atoi(numero);
    pelicula[indice].fechaEstreno.mes=fecha;

    printf("INGRESE ANIO DE ESTRENO: ");
    fflush(stdin);
    scanf("%s", numero);

    while(esNumerico(numero)==-1)
    {
        printf("ANIO DE ESTRENO DEBE SER NUMERICO\n");
        fflush(stdin);
        printf("INGRESE ANIO DE ESTRENO: ");
        scanf("%s", numero);
    }
    fecha=atoi(numero);
    pelicula[indice].fechaEstreno.anio=fecha;






}

/**********************************************************************************************************/
int getInt(ePeliculas list[], int indice,char message[],char eMessage[], int lowLimit, int hiLimit, int* cadena[])
{
    int auxNum;
    char numStr[20];

    printf("\n________________________________________________________________\n\n");
    printf("\n%s", message);
    fflush(stdin);
    scanf("%s",numStr);
    while(esNumerico(numStr)==0)
    {
        printf("\n________________________________________________________________\n\n");
        printf("SOLO SE PERMITE EL INGRESO DE NUMERICOS, REINTENTE.");
        printf("\n%s", message);
        fflush(stdin);
        scanf("%s",numStr);
    }
    auxNum=atoi(numStr);
    while((auxNum<lowLimit || auxNum>hiLimit))
    {
        printf("\n________________________________________________________________\n\n");
        printf("\n%s", eMessage);
        scanf("%d", &auxNum);

    }


    return auxNum;

}

/**********************************************************************************************************/

/** \brief valida que la cadena que recibe solo contenga numeros.
 *
 * \param str[] char con la cadena a validar.
 * \return int retorna 0 si no es solo numeros o 1 si es solo numeros.
 *
 */
int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

/**********************************************************************************************************/

/** \brief Imprime un mensaje consultando al usuario si desea continuar
 *
 * \return Retorna un char, 'S' o 'N'.
 *
 */

char validarSeguir()
{
    char seguir='S';
    printf("\n________________________________________________________________\n\n");
    printf("\nDESEA CONTINUAR? S/N: ");
    scanf("%s", &seguir);
    seguir=toupper(seguir);

    while(seguir != 'N' && seguir != 'S')
    {
        printf("\n________________________________________________________________\n\n");
        printf("\nLA OPCION INGRESADA ES INVALIDA.");
        printf("\nDESEA CONTINUAR? S/N: ");
        scanf("%s", &seguir);
        seguir=toupper(seguir);

    }

    return seguir;

}

/**********************************************************************************************************/

/** \brief busca en el array si hay lugar disponible.
 *
 * \param list[] Employee con el array a recorrer.
 * \param tam int con el tamaño del array a recorrer.
 * \return int -1 si no pudo lograr el objetivo o 0 si lo logró.
 *
 */
int buscarLibre(ePeliculas list[],int tam)
{
    int retorno = -1;
    int i;

        for(i=0; i<tam; i++)
        {
            if(list[i].isEmpty == VACIO)
            {
                retorno = i;
                break;
            }
        }

    return retorno;
}



