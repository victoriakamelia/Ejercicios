#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "PELI.H"
#define TAM 10
#define TAMAC 10
#define TAMGE 5
#define OCUPADO 1
#define VACIO 0

/**********************************************************************************************************/

/** \brief genera automaticamente un id y solicita por pantalla datos para dar de alta una película.
 *
 * \param list[] eAuto con el array de autos a cargar.
 * \param tam int con el tamaño del array a cargar.
 * \param actor[] eActores con el tamaño del array a recorrer.
  * \param tamAc int con el tamaño del array a cargar.
 * \param generos[] eActores con el tamaño del array a recorrer.
 * \param tamGe int con el tamaño del array a recorrer.
 * \return int retorna -1 si pudo dar de alta o 0 si lo logró.
 *
 */

int addautos(eAuto list[], int tam, eMarca marca[], int tamMar, eColor colores[], int tamCo)
{
    int retorno=-1;
    int id=generarId();
    int indice=buscarLibre(list, TAM);

    if(buscarLibre(list, tam)==-1)
    {
        printf("\n________________________________________________________________\n\n");
        printf("NO QUEDA LUGAR DISPONIBLE PARA GENERAR AUTOS.\n");
    }
    else
    {
        //validar alfanumerico
        getAlpha("I N G R E S E   P A T E N T E: ", "PATENTE INGRESADO EXCEDE EL PERMITIDO.\n", list[indice].patente, 8);
        printf("\n________________________________________________________________\n\n");
        printf("M A R C A S\n");
        mostrarMarcas(marca,tamMar);
        list[indice].idMarca=getInt("I N G R E S E   M A R C A: ", "SECTOR DEBE SER ENTRE 1000 Y 1004.\n", 1000,1004);
        printf("C O L O R E S\n");
        mostrarColores(colores, tamCo);
        list[indice].idColor=getInt("I N G R E S E   C O L O R: ", "COLOR DEBE SER ENTRE 5000 Y 5004.\n", 5000, 5004);
        printf("\n________________________________________________________________\n\n");
        list[indice].modeloAnio=getInt("INGRESE AÑO DEL MODELO: ", "AÑO DEBE SER ENTRE 1900 Y 2020.\n", 1900, 2020);

        printf("AUTO id %d GENERADA EXITOSAMENTE.\n", id);

        list[indice].id=id;
        list[indice].isEmpty=OCUPADO;


        retorno=0;

    }

    return retorno;
}

/**********************************************************************************************************/

/** \brief Inicializa un array
 *
 * \param list[]  con el array a ser recorrido.
 * \param tam int con el tamaño del array a recorrer.
 * \return int -1 si no pudo inicializar o 0 si lo logró.
 *
 */
int initautos(eAuto list[],int tam)
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
int hayauto(eAuto list[], int tam)
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

/**********************************************************************************************************/

/** \brief recorre un array buscando el indice del id solicitado.
 *
 * \param list[] Employee con el array a recorrer.
 * \param tam int con el tamaño del array a recorrer.
 * \param id int con el id de la auto cuyo indice se desea conocer.
 * \return int retorna -1 si no encontro el indice y el numero del indice si lo encontró.
 *
 */
int buscarId(eAuto list[], int tam, int id)
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





/** \brief genera un id entero autoincremental
 *
 * \return int retorno el id incrementado
 *
 */
int generarId()
{
    static int id=1000;

    return id++;
}


int generarIdTrabajo()
{
    static int id=0;

    return id++;
}
/**********************************************************************************************************/
/** \brief obtine por pantall y valida una fecha
 *
 * \param auto[] con el arrray en donde se guardará la fecha
 * \param indice int con el indice en donde se guardará la fecha
 * \return void
 *
 */

void getFecha(eTrabajo trabajo[], int indice)
{

    int fecha;

    fecha=getInt("INGRESE DIA DE INGRESO: ", "DIA DEBE SER ENTRE 1 Y 31.\n", 1,31);
    trabajo[indice].fecha.dia=fecha;
    fecha=getInt("INGRESE MES DE INGRESO: ", "MES DEBE SER ENTRE 1 Y 12.\n", 1,12);
    trabajo[indice].fecha.mes=fecha;
    fecha=getInt("INGRESE ANIO DE INGRESO: ", "ANIO DEBE SER ENTRE 1900 Y 2019.\n", 1900,2019);
    trabajo[indice].fecha.anio=fecha;

}

/**********************************************************************************************************/
/** \brief  obtiene por pantalla y valida un entero
 *
 * \param message[] char mensaje a mostrar para pedir entero
 * \param eMessage[] char mensaje a mostrar en caso de un ingreso erróneo
 * \param lowLimit int menor numero permitido
 * \param hiLimit int maximo numero permitido
 * \return int retorna el entero validado
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
 * \param list[]  con el array a recorrer.
 * \param tam int con el tamaño del array a recorrer.
 * \return int -1 si no pudo lograr el objetivo o 0 si lo logró.
 *
 */
int buscarLibre(eAuto list[],int tam)
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


/**********************************************************************************************************/

/** \brief valida que la cadena que recibe solo contenga letras o espacios.
 *
 * \param str[] char con la cadena a validar.
 * \return int retorna 0 si no es solo letras/espacios o 1 si es solo letras/espacios.
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

/**********************************************************************************************************/


/** \brief Recorre un array para hacer una baja lógica en el indice solicitado.
 *
 * \param list[] con el array a recorrer.
 * \param tam int con el tamaño del array a recorrer.
 * \param id int el indice a dar de baja.
 * \return int -1 si no pudo lograr el objetivo o 0 si lo logró.
 *
 */
int bajaauto(eAuto list[],int tam, int id)
{
    int retorno = -1;
    int i;

    for(i = 0; i < tam; i++)
    {
        if(list[i].id == id)
        {
            list[i].isEmpty = VACIO;
            retorno = 0;
        }
    }
    return retorno;
}

/**********************************************************************************************************/
/** \brief
 *
 * \param list eAuto con la auto a mostrar
 * \param generos[] eGenero con el array de generos
 * \param tamGe int con el tamaño del array
 * \param actor[] eActores con el array a recorrer
 * \param TamAc int con el tamaño del array
 * \return void
 *
 */
void mostrarauto(eAuto list, eColor colores[], int tamCo,eMarca marcas[], int tamMar)
{
    int idMar=list.idMarca;
    int indiceMar=buscarIndiceMarca(marcas, tamMar, idMar);
    int idColor=list.idColor;
    int indiceColor=buscarIndiceColor(colores, tamCo, idColor);
    printf("%5d     %10s     %10s   %10s     %5d\n", list.id, list.patente, marcas[indiceMar].descripcion, colores[indiceColor].nombreColor, list.modeloAnio );
}




/** \brief da de alta un actor
 *
 * \param actores[] eActores con el array de actores a cargar
 * \param tamAc int con el tamaño del array de actores
 * \return int retorna -1 si no pudo dar de alta y 0 si lo logro
 *
 */
 /*
int altaActor(eActores actores[], int tamAc)
{
    static int id=100;
    static int indice=0;
    int retorno=-1;
    if(id<=tamAc+100)
    {
            actores[indice].id=id;
            getText("Ingrese nombre completo: ", "Nombre excede la cantidad de letras permitidas",actores[indice].nombre, 51);
            getText("Ingrese pais de origen: ", "Pais excede la cantidad de letras permitidas",actores[indice].pais, 30);
            printf("\n________________________________________________________________\n\n");
            printf("ACTOR ID %d DADO DE ALTA EXITOSAMENTE.\n", id);
            retorno=0;
            actores[indice].isEmpty=OCUPADO;
            id++;
            indice++;

    }
    return retorno;
}*/

/**********************************************************************************************************/

/** \brief
 *
 * \param genero[] eGenero
 * \param tamGe int
 * \return void
 *
 */
void mostrarMarcas(eMarca marcas[], int tamMar)
{
    int i;
    printf("\n________________________________________________________________\n\n");
    printf("ID        -  DESCRIPCION\n\n");
    for(i=0; i<tamMar; i++)
    {
        printf("%5d         %10s\n", marcas[i].id, marcas[i].descripcion);
    }


}

/** \brief
 *
 * \param generos[] eGenero
 * \param tamGe int
 * \param id int
 * \return int
 *
 */
int buscarIndiceColor(eColor colores[], int tamCo, int id)
{
    int indice;
    int i;

    for(i =0; i<tamCo; i++)
    {
        if(colores[i].id == id)
        {
            indice=i;
        }
    }

    return indice;
}



/** \brief
 *
 * \param actor[] eActores
 * \param TamAc int
 * \param id int
 * \return int
 *
 */
int buscarIndiceMarca(eMarca marca[], int tamMar, int id)
{
    int indice;
    int i;

    for(i =0; i<tamMar; i++)
    {
        if(marca[i].id == id)
        {
            indice=i;
        }
    }

    return indice;
}


void mostrarColores(eColor colores[], int tamCo)
{
    int i;
    printf("\n________________________________________________________________\n\n");
    printf("ID    -      COLOR\n");
    for(i=0; i<tamCo; i++)
    {
        printf("%5d         %10s\n", colores[i].id, colores[i].nombreColor);
    }


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
void getAlpha(char texto[], char textoError[], char cadena[], int largo)
{
    char auxChar[100];
    printf("\n________________________________________________________________\n\n");
    printf("\n%s", texto);
    fflush(stdin);
    gets(auxChar);
    while(esAlfa(auxChar)==0)
    {
        printf("\n________________________________________________________________\n\n");
        printf("\nSOLO DEBE INGRESAR ALFANUMERICOS, REINTENTE: ");
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



/**********************************************************************************************************/

/** \brief valida que la cadena que recibe solo contenga numeros.
 *
 * \param str[] char con la cadena a validar.
 * \return int retorna 0 si no es solo numeros o 1 si es solo numeros.
 *
 */
int esAlfa(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] < '0' || str[i] > '9') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && str[i] != ' ')
            return 0;
        i++;
    }
    return 1;
}

int addTrabajo(eAuto list[], int tam, eMarca marca[], int tamMar, eColor colores[], int tamCo, eServicio servicio[], int tamSer, eTrabajo trabajo[], int tamTra)
{
    int retorno=-1;
    int id=generarIdTrabajo();
    int indice=buscarLibreT(trabajo, tamTra);
    char patente [8];
    int idServicio;
    int i;
    printf("SELECCIONE UN AUTO: ");
    for(i = 0; i< tam; i++)
    {
        mostrarauto(list[i], colores, tamCo, marca, tamMar);
    }


    printf("Ingrese la patente del auto: ");
    fflush(stdin);
    scanf("%s", patente);

    while(buscarIdPatente(list, tam, patente)==-1)
    {
        printf("La patente ingresada no corresponde a ningun auto existente.\n");
        printf("SELECCIONE UN AUTO: ");
        printf("Ingrese la patente del auto: ");
        fflush(stdin);
        scanf("%s", patente);
    }
    strcpy(trabajo[indice].patente, patente);

    //mostrarServicio(servicio, tamSer);
    idServicio=getInt("Ingrese el id del servicio a cargar: ", "El id debe ser entre 20000 y 20003", 200001, 20003);

    trabajo[indice].idServicio=idServicio;

    getFecha(trabajo, indice);

    trabajo[indice].id=id;

    retorno=0;

    return retorno;



}


int buscarIdPatente(eAuto list[], int tam, char patente[])
{
    int indice=-1;
    int i;

    for(i =0; i<tam; i++)
    {
        if(stricmp(list[i].patente, patente)==0)
        {
            indice=i;
        }
    }

    return indice;
}


void mostrarServicio(eServicio servicio[], int tamSer)
{
    int i;
    printf("\n________________________________________________________________\n\n");
    printf("ID        -  DESCRIPCION    - PRECIO\n\n");
    for(i=0; i<tamSer; i++)
    {
        printf("%5d         %10s        %.2f\n", servicio[i].id, servicio[i].descricion, servicio[i].precio);
    }


}

int buscarLibreT(eTrabajo trabajo[],int tam)
{
    int retorno = -1;
    int i;

        for(i=0; i<tam; i++)
        {
            if(trabajo[i].isEmpty == VACIO)
            {
                retorno = i;
                break;
            }
        }

    return retorno;
}

void listarXmarcaYpatente(eAuto list[], int tam, eMarca marca[], int tamMar, eColor color[], int tamCo, eAuto aux)
{
    int i, j;

    for(i=0; i<tam-1; i++)
    {
        if(list[i].isEmpty==OCUPADO)
        {
            for(j=i+1; j<tam; j++)
        {
            if(list[i].idMarca > list[j].idMarca)
            {
                aux=list[i];
                list[i]=list[j];
                list[j]=aux;
            }
        }

        }

    }

    for(i=0; i<tam; i++)
    {
        mostrarauto(list[i], color, tamCo, marca, tamMar);
    }

}

void mostarTrabajo(eTrabajo trabajo)
{
    /*char idPatente[8]=trabajo.patente;
    int indicePatente=buscarIdPatente(list,tam, patente);*/
    printf("%d    - %10s     - %d    - %d/%d/%d", trabajo.id, trabajo.patente, trabajo.idServicio, trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio );
}
