#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "auto.h"
#include "utn.h"
#define OCUPADO 1
#define VACIO 0

/** \brief valida la opcion seleccionada por el usuario
 *
 * \return char devuelve un char s o n
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

/** \brief valida el ingreso por pantalla de un entero
 *
 * \param message[] char con el mensaje a mostrar por pantalla
 * \param eMessage[] char con el mensaje de error
 * \param lowLimit int con el menor valor permitido
 * \param hiLimit int con el maximo valor permitido
 * \return int con el entero validado
 *
 */
int getInt(char message[],char eMessage[], int lowLimit, int hiLimit)
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

/** \brief valida que el contenido sea solo numerico
 *
 * \param str[] char con la cadena a validad
 * \return int retorna 0 si el dato no es numerico o 1 si lo es.
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

/** \brief valida el ingreso de una patente con formato LLL 111 (tres letras, un espacio y tres numeros)
 *
 * \param str[] char con la cadena a validar
 * \return int -1 si hay error o 0 si no lo hay.
 *
 */
int esPatente(char str[])
{
        int retono=0;
        strupr(str);

        if( (str[0] < 'A' || str[0] > 'Z') ||
            (str[1] < 'A' || str[1] > 'Z') ||
            (str[2] < 'A' || str[2] > 'Z') ||
            (str[3] != ' ')                ||
            (str[4] < '0' || str[4] > '9') ||
            (str[5] < '0' || str[5] > '9') ||
            (str[6] < '0' || str[6] > '9'))
            {
                retono= -1;
            }
        return retono;

}

/** \brief valida que sean solo letras
 *
 * \param str[] charcon la cadena a validar
 * \return int retorna 0 si hay error o si no lo hay.
 *
 */
int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

/** \brief muestra un menu de opciones por pantalla
 *
 * \return int devuelve y valida la opcion seleccionada por el usuario
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
    printf(" `.   `.                   1)ALTA AUTO.                         .'   .' \n");
    printf("   )    )                  2)MODIFICAR AUTO.                   (    (\n");
    printf(" ,'   ,'                   3)BAJA AUTOS.                        `.   `.\n");
    printf("(    (                     4)LISTAR AUTOS.                       )    )\n");
    printf(" `.   `.                   5)LISTAR MARCAS                     .'   .' \n");
    printf("   )    )                  6)LISTAR COLORES.                  (    (\n");
    printf(" ,'   ,'                   7)LISTAR SERVICIOS                  `.   `.\n");
    printf("(    (                     8)ALTA TRABAJO                        )    )\n");
    printf(" `.   `.                   9)LISTAR  TRABAJOS.                 .'   .' \n");
    printf("   )    )       _       _  10)SALIR    _       _      _       (    (\n");
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

/** \brief muestra un menu de opciones por pantalla
 *
 * \return int devuelve y valida la opcion seleccionada por el usuario
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
    printf(" `.   `.                   1)Modificar color.                   .'   .' \n");
    printf("   )    )                                                      (    (\n");
    printf(" ,'   ,'                   2)Modificer modelo.                  `.   `.\n");
    printf("(    (                                                            )    )\n");
    printf(" `.   `.                   3)Volver al menu anterior.          .'   .' \n");
    printf("   )    )                                                      (    (\n");
    printf(" ,'   ,'                                                        `.   `.\n");
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

/** \brief solicita y valida el ingreso de una patente
 *
 * \param texto[] char con el mensaje para pedir el valor por pantalla
 * \param textoError[] char con el mensaje a mostrar en caso de error.
 * \param cadena[] char con la cadena en donde se guardará el dato validado
 * \param largo int con el maximo de caracteres permitido.
 * \return void
 *
 */
void getPatente(char texto[], char textoError[], char cadena[], int largo)
{
    char auxChar[100];
    printf("\n________________________________________________________________\n\n");
    printf("\n%s", texto);
    fflush(stdin);
    gets(auxChar);
    while(esPatente(auxChar)==-1)
    {
        printf("\n________________________________________________________________\n\n");
        printf("\nSOLO DEBE INGRESAR FORMATO PATENTE (LLL 111), REINTENTE: ");
        fflush(stdin);
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

/** \brief solicita por pantalla el ingreso de una cadena
 *
 * \param texto[] char con el mensaje a mostrar para solicitar los datos
 * \param textoError[] char con el mensaje a mostrar en caso de error
 * \param cadena[] char con la cadena en donde se guardara el texto validado
 * \param largo int con el maximo de caracteres permitos.
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
