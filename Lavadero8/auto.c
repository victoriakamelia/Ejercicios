#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "utn.h"
#include "auto.h"
#define OCUPADO 1
#define VACIO 0

/******************************************************************************************************************************
AUTOS*************************************************************************************************************************/

/** \brief da de alta un registro en el array de autos
 *
 * \param list[] eAuto con el array a cargar
 * \param tam int con el tamaño del array a cargar
 * \param marca[] eMarca con el array de marcas a recorrer
 * \param tamMar int con el tamaño del array a recorrer
 * \param colores[] eColor con el array de marcas a recorrer
 * \param tamCo int con el tamaño del array a recorrer
 * \return int devuelve -1 si no pudo dar de alta y 0 si lo logró
 *
 */

int addAutos(eAuto list[], int tam, eMarca marca[], int tamMar, eColor colores[], int tamCo)
{
    int retorno=-1;
    int id=generarId();
    int indice=buscarLibre(list, tam);

    if(buscarLibre(list, tam)==-1)
    {
        printf("\n________________________________________________________________\n\n");
        printf("NO QUEDA LUGAR DISPONIBLE PARA GENERAR AUTOS.\n");
    }
    else
    {
        getPatente("I N G R E S E   P A T E N T E: ", "PATENTE INGRESADO EXCEDE EL PERMITIDO.\n", list[indice].patente, 8);
        printf("\n________________________________________________________________\n\n");

        printf("M A R C A S\n");
        mostrarMarcas(marca,tamMar);
        list[indice].idMarca=getInt("I N G R E S E   M A R C A: ", "SECTOR DEBE SER ENTRE 1000 Y 1004.\n", 1000,1004);

        printf("C O L O R E S\n");
        mostrarColores(colores, tamCo);
        list[indice].idColor=getInt("I N G R E S E   C O L O R: ", "COLOR DEBE SER ENTRE 5000 Y 5004.\n", 5000, 5004);

        printf("\n________________________________________________________________\n\n");
        list[indice].modeloAnio=getInt("INGRESE ANIO DEL MODELO: ", "ANIO DEBE SER ENTRE 1900 Y 2020.\n", 1900, 2019);

        printf("AUTO id %d GENERADA EXITOSAMENTE.\n", id);

        list[indice].id=id;
        list[indice].isEmpty=OCUPADO;
        retorno=0;
    }
    return retorno;
}

/** \brief busca en qué indice se posiciona la patente solicitada
 *
 * \param list[] eAuto con el array a recorrer
 * \param tam int con el tamaño del array a recorrer
 * \param patente[] char con la patente a buscar
 * \return int devuelve el indice si encontro la patente o -1 si no la encontró
 *
 */
int buscarIndicePatente(eAuto list[], int tam, char patente[])
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



/** \brief busca el indice en donde se posiciona el ID requerido
 *
 * \param list[] eAuto con el array a recorrer
 * \param tam int con el tamaño del array a recorrer
 * \param id int con el ID requerido
 * \return int devuelve el indice si encontró el id o -1 si no lo encontró
 *
 */
int buscarIndice(eAuto list[], int tam, int id)
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

/** \brief busca la primer posicion libre del array
 *
 * \param list[] eAuto con el array a recorrer
 * \param tam int con el tamaño del array a recorrer
 * \return int con el indice de la primera posicion disponible en el array.
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

/** \brief verifica si al menos hay un registro ocupado
 *
 * \param list[] eAuto con el array a recorrer
 * \param tam int con el tamaño del array a recorrer
 * \return int retorna 1 si encontró un registro ocupado o 0 si no encontró.
 *
 */
int hayAuto(eAuto list[], int tam)
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

/** \brief genera un id autoincremental desde el numero 1000
 *
 * \return int retorna el id autoincrementado.
 *
 */
int generarId()
{
    static int id=1;
    return id++;
}

/** \brief inicializa un array
 *
 * \param list[] eAuto con el array a inicializar
 * \param tam int con el tamaño del array a inicializar
 * \return int retona 0 si pudo lograrlo o -1 si no lo logró
 *
 */
int initAutos(eAuto list[],int tam)
{
    int retorno = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        list[i].isEmpty=0;
        retorno = 0;
    }
    return retorno;
}

/** \brief hace baja lógica en un registro.
 *
 * \param list[] eAuto con el array en donde se dará la baja
 * \param indice int con la posicion del array en donde se dará la baja
 * \return void
 *
 */
void bajaAuto(eAuto list[], int indice)
{
    list[indice].isEmpty=VACIO;
}

/** \brief realiza un listado ordenado por modelo de auto y luego alfabeticamente por patente,
 *
 * \param list[] eAuto con el array a recorrer.
 * \param tam int con el tamaño del array a recorrer.
 * \param marca[] eMarca  con el array a recorrer.
 * \param tamMar intcon el tamaño del array a recorrer.
 * \param color[] eColor con el array a recorrer.
 * \param tamCo int con el tamaño del array a recorrer.
 * \param aux eAuto con el auxiliar de la estructura con el cual se hará el swapeo.
 * \return void
 *
 */
void listarXmarcaYpatente(eAuto list[], int tam, eMarca marca[], int tamMar, eColor color[], int tamCo, eAuto aux)
{
    int i, j;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(list[i].idMarca > list[j].idMarca)
            {
                aux=list[i];
                list[i]=list[j];
                list[j]=aux;
            }
            if(stricmp(list[i].patente, list[j].patente)>0 && list[i].idMarca== list[j].idMarca)
            {
                aux=list[i];
                list[i]=list[j];
                list[j]=aux;
            }
        }
    }

    for(int i=0; i<tam; i++)
    {
        mostrarAuto(list[i], color, tamCo, marca, tamMar);
    }
}

/** \brief muestra un auto y sus datos
 *
 * \param list eAuto con el registro a mostrar
 * \param colores[] eColor con el array a recorrer.
 * \param tamCo int con el tamaño del array a recorrer.
 * \param marcas[] eMarca con el array a recorrer.
 * \param tamMar int con el tamaño del array a recorrer.
 * \return void
 *
 */
void mostrarAuto(eAuto list, eColor colores[], int tamCo, eMarca marcas[], int tamMar)
{
    int idMar=list.idMarca;
    int indiceMar=buscarIndiceMarca(marcas, tamMar, idMar);
    int idColor=list.idColor;
    int indiceColor=buscarIndiceColor(colores, tamCo, idColor);
    printf("%5d     %10s     %10s   %10s     %5d\n", list.id, list.patente, marcas[indiceMar].descripcion, colores[indiceColor].nombreColor, list.modeloAnio );
}

/** \brief muestra un listado de todos los autos activos
 *
 * \param list[] eAuto con el array a recorrer.
 * \param tam int con el tamaño del array a recorrer.
 * \param marcas[] eMarca con el array a recorrer.
 * \param tamMar int con el tamaño del array a recorrer.
 * \param colores[] eColor con el array a recorrer.
 * \param tamCo int con el tamaño del array a recorrer.
 * \return void
 *
 */
void mostrarAutos(eAuto list[], int tam, eMarca marcas[], int tamMar, eColor colores[], int tamCo)
{
    int i;
    for(i=0; i< tam; i++)
    {
        mostrarAuto(list[i], colores, tamCo, marcas, tamMar);
    }
}

/********************************************************************************************************************************
TRABAJOS************************************************************************************************************************/

/** \brief Da de alta un registro en el array de trabajos.
 *
 * \param list[] eAuto con el array a recorrer.
 * \param tam int con el tamaño del array a recorrer.
 * \param marca[] eMarca con el array a recorrer.
 * \param tamMar int con el tamaño del array a recorrer.
 * \param colores[] eColor con el array a recorrer.
 * \param tamCo int con el tamaño del array a recorrer.
 * \param servicio[] eServicio con el array a recorrer.
 * \param tamSer int con el tamaño del array a recorrer.
 * \param trabajo[] eTrabajo con el array a cargar.
 * \param tamTra int con el tamaño del array a cargar.
 * \return int devuelve -1 si no lo logró o 0 si lo logró.
 *
 */
int addTrabajo(eAuto list[], int tam, eMarca marca[], int tamMar, eColor colores[], int tamCo, eServicio servicio[], int tamSer, eTrabajo trabajo[], int tamTra)
{
    int retorno=-1;
    int id=generarIdTrabajo();
    int indice=buscarLibreT(trabajo, tamTra);
    char patente[8];
    int idServicio;

    printf("SELECCIONE UN AUTO: ");
    mostrarAutos(list, tam, marca,tamMar, colores, tamCo);
    printf("Ingrese la patente del auto: ");
    fflush(stdin);
    gets(patente);

    while(buscarIndicePatente(list, tam, patente)==-1)
    {
        printf("La patente ingresada no corresponde a ningun auto existente.\n");
        printf("SELECCIONE UN AUTO: ");
        printf("Ingrese la patente del auto: ");
        fflush(stdin);
        gets(patente);
    }
    strcpy(trabajo[indice].patente, patente);

    mostrarServicio(servicio, tamSer);
    idServicio=getInt("Ingrese el id del servicio a cargar: ", "El id debe ser entre 20000 y 20003: ", 20000, 20003);

    trabajo[indice].idServicio=idServicio;
    getFecha(trabajo, indice);

    trabajo[indice].id=id;
    trabajo[indice].isEmpty= OCUPADO;
    retorno=0;

    return retorno;
}

/** \brief busca la primer posicion libre del array
 *
 * \param trabajo[] eTrabajo con el array a recorrer.
 * \param tam int  con el tamaño del array a recorrer.
 * \return int devuelve el primer indice desocupado o -1 si no hay registros desocupados.
 *
 */
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

/** \brief Genera un ID autoincremental desde el numero 0.
 *
 * \return int con el id autoincrementado.
 *
 */
int generarIdTrabajo()
{
    static int id=0;

    return id++;
}

/** \brief busca un registro en el array que este activo
 *
 * \param trabajo[] eTrabajo con el array a recorrer
 * \param tamTra int con el tamaño del array a recorrer
 * \return int retorna 1 si encontro un registro activo o 0 si no encontró.
 *
 */
int hayTrabajo(eTrabajo trabajo[], int tamTra)
{
    int retorno=0;
    int i;
    for(i=0; i<tamTra; i++)
    {
        if(trabajo[i].isEmpty==OCUPADO)
        {
            retorno=1;
            break;
        }
    }

    return retorno;
}


/** \brief inicializa un array
 *
 * \param trabajo[] eTrabajo con el array a inicializar
 * \param tamTra int con el tamaño del array ainicializar.
 * \return int retorna -1 si no pudo hacerlo, o 0 si lo logró.
 *
 */
int initTrabajo(eTrabajo trabajo[],int tamTra)
{
    int retorno = -1;
    int i;

    for(i=0; i<tamTra; i++)
    {
        trabajo[i].isEmpty=VACIO;
        retorno = 0;

    }
    return retorno;
}

/** \brief obtiene y valida una fecha
 *
 * \param trabajo[] eTrabajo con el array en donde se guardará la fecha
 * \param indice int con el indice de la posicion en donde se guardará la fecha.
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

/** \brief muestra un registro de trabajo con su contenido.
 *
 * \param trabajo eTrabajo con el registro a mostrar
 * \param list[] eAuto con el array a recorrer.
 * \param tam int  con el tamaño del array a recorrer.
 * \param servicio[] eServicio con el array a recorrer.
 * \param tamSer int con el tamaño del array a recorrer.
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo trabajo, eAuto list[], int tam, eServicio servicio[], int tamSer)
{
    char patente[8];
    strcpy(patente, trabajo.patente);
    int indicePatente=buscarIndicePatente(list,tam, patente);
    int idServicio=trabajo.idServicio;
    int indiceServicio=buscarIndiceServicio(servicio, tamSer, idServicio);

    printf("%d    - %10s     - %10s    - %d/%d/%d  \n", trabajo.id, list[indicePatente].patente, servicio[indiceServicio].descricion, trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio );
}

/** \brief muestra todos los registros activos con su contenido
 *
 * \param trabajos[] eTrabajo con el array a recorrer
 * \param tamTra int  con el tamaño del array a recorrer.
 * \param list[] eAuto con el array a recorrer.
 * \param tam int  con el tamaño del array a recorrer.
 * \param servicio[] eServicio con el array a recorrer.
 * \param tamSer int  con el tamaño del array a recorrer.
 * \return void
 *
 */
void mostrarTrabajos(eTrabajo trabajos[], int tamTra, eAuto list[],int tam, eServicio servicio[], int tamSer)
{
    int i;
    for(i=0; i< tamTra; i++)
    {
        if(trabajos[i].isEmpty== OCUPADO)
        {
            mostrarTrabajo(trabajos[i],list, tam,servicio, tamSer);
        }

    }
}

/********************************************************************************************************************************
MARCAS**************************************************************************************************************************/

/** \brief busca el indice de la posicion en donde se encuentra el ID solicitado
 *
 * \param marca[] eMarca con el array a recorrer.
 * \param tamMar int  con el tamaño del array a recorrer.
 * \param id int con el ID que se desea saber la posicion.
 * \return int devuelve el indice si encontró el id, o -1 si no lo encontró.
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
            break;
        }
    }

    return indice;
}

/** \brief muestra un listado de los registros
 *
 * \param marcas[] eMarca con el array de registros a mostrar.
 * \param tamMar int  con el tamaño del array a mostrar.
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

/********************************************************************************************************************************
COLOR***************************************************************************************************************************/

/** \brief busca el indice en donde se posiciona el id
 *
 * \param colores[] eColor con el array a recorrer.
 * \param tamCo int con el tamaño del array a recorrer.
 * \param id int con el id cuya posicion se desea saber.
 * \return int devuelve el indice de la posicion del id si enontro o -1 si no encontró.
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
            break;
        }
    }

    return indice;
}

/** \brief mustra un listado de los registros de un array
 *
 * \param colores[] eColor con el array a recorrer.
 * \param tamCo int con el tamaño del array a recorrer.
 * \return void
 *
 */
void mostrarColores(eColor colores[], int tamCo)
{
    int i;
    printf("\n________________________________________________________________\n\n");
    printf("ID         -       COLOR\n");
    for(i=0; i<tamCo; i++)
    {
        printf("%5d         %10s\n", colores[i].id, colores[i].nombreColor);
    }
}

/********************************************************************************************************************************
SERVICIO************************************************************************************************************************/

/** \brief busca la posicion del un ID solicitado
 *
 * \param servicio[] eServicio con el array a recorrer.
 * \param tamSer int con el tamaño deñ array a recorrer-
 * \param id int con el id cuya posicion se desea conocer.
 * \return int devuelve el indice del id si lo encuentra o -1 si no lo logró.
 *
 */
int buscarIndiceServicio(eServicio servicio[], int tamSer, int id)
{
    int indice=-1;

    for(int i=0; i<tamSer; i++)
    {
        if(servicio[i].id==id)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

/** \brief muestra un listado de los registros disponibles de un array
 *
 * \param servicio[] eServicio con el array a recorrer
 * \param tamSer int con el tamaño del array a recorrer.
 * \return void
 *
 */
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

/*********************************************************************************************************************
INFORMES*/

void autoColorNegro(eAuto list[], int tam, eColor colores[], int tamCo, eMarca marcas[], int tamMar, eAuto aux)
{
    int i;
    int contador=0;
    int idColor;

    mostrarColores(colores, tamCo);
    idColor=getInt("I N G R E S E   C O L O R: ", "COLOR DEBE SER ENTRE 5000 Y 5004.\n", 5000, 5004);

    for(i=0; i<tam;i++)
    {
        if(list[i].idColor == idColor && list[i].isEmpty==OCUPADO)
        {
            aux=list[i];
            mostrarAuto(aux, colores, tamCo, marcas, tamMar);
            contador++;
        }
    }

    if(contador==0)
    {
        printf("No hay autos color negro para mostrar.\n");
    }
}

void autosDeUnaMarca(eAuto list[], int tam, eColor colores[], int tamCo, eMarca marcas[], int tamMar, eAuto aux)
{
    int i;
    int idMarca;
    int contador=0;

    mostrarMarcas(marcas,tamMar);
    idMarca=getInt("I N G R E S E   M A R C A: ", "MARCA DEBE SER ENTRE 1000 Y 1004.\n", 1000,1004);

    for(i=0; i<tam; i++)
    {
        if(list[i].idMarca == idMarca && list[i].isEmpty==OCUPADO)
        {
            aux=list[i];
            mostrarAuto(aux, colores, tamCo, marcas, tamMar);
            contador++;
        }
    }

    if(contador==0)
    {
        printf("No hay autos de esta marca para mostrar.\n");
    }


}

void trabajoUnAutoSeleccionado(eAuto list[], int tam, eTrabajo trabajo[], int tamTra, eServicio servicio[], int tamSer, eMarca marcas[], int tamMar, eColor colores[], int tamCo, eTrabajo auxTra)
{
    char patente[8];
    int i;
    int contador=0;
    printf("SELECCIONE UN AUTO: \n");
    mostrarAutos(list, tam, marcas, tamMar, colores, tamCo);
    printf("Ingrese la patente del auto: ");
    fflush(stdin);
    gets(patente);

    while(buscarIndicePatente(list, tam, patente)==-1)
    {
    printf("La patente ingresada no corresponde a ningun auto existente.\n");
    printf("SELECCIONE UN AUTO: \n");
    mostrarAutos(list, tam, marcas, tamMar, colores, tamCo);
    printf("Ingrese la patente del auto: ");
    fflush(stdin);
    gets(patente);
    }

    for(i=0; i<tamTra; i++)
    {
        if(strcmp(trabajo[i].patente, patente)==0 && trabajo[i].isEmpty==OCUPADO)
        {
            auxTra=trabajo[i];
            mostrarTrabajo(auxTra, list, tam, servicio, tamSer);
            contador++;
        }
    }

      if(contador==0)
    {
        printf("No hay trabajos de este auto para mostrar.\n");
    }

}
/*void autosSinTrabajo(eTrabajo trabajos[], int tamTra, eAuto list[], int tam, eAuto aux, eColor colores[], int tamCo, eMarca marcas[], int tamMar)
{
    int i, j;
    int contador=0;

    for(i=0; i<tamTra; i++)
    {
       for(j=0; j<tam; j++)
       {
           if((stricmp(trabajos[i].patente, list[j].patente)!=0) && list[j].isEmpty==OCUPADO )
           {
               aux=list[j];
               mostrarAuto(aux, colores, tamCo, marcas, tamMar);
               contador++;
               break;

           }


       }
    }

    if(contador==0)
    {
        printf("TODOS LOS AUTOS EXISTENTES RECIBIERON UN TRABAJO");
    }
}*/

void importexAuto(eAuto list[], int tam, eTrabajo trabajo[], int tamTra, eServicio servicio[], int tamSer, eMarca marcas[], int tamMar, eColor colores[], int tamCo)
{
    char patente[8];
    int i;
    float contador=0;
    int indiceServicio;
    int idServicio;
    printf("SELECCIONE UN AUTO: \n");
    mostrarAutos(list, tam, marcas, tamMar, colores, tamCo);
    printf("Ingrese la patente del auto: ");
    fflush(stdin);
    gets(patente);

    while(buscarIndicePatente(list, tam, patente)==-1)
    {
    printf("La patente ingresada no corresponde a ningun auto existente.\n");
    printf("SELECCIONE UN AUTO: \n");
    mostrarAutos(list, tam, marcas, tamMar, colores, tamCo);
    printf("Ingrese la patente del auto: ");
    fflush(stdin);
    gets(patente);
    }

    for(i=0; i<tamTra; i++)
    {
        if(stricmp(trabajo[i].patente, patente)==0 && trabajo[i].isEmpty==OCUPADO)
        {
            idServicio=trabajo[i].idServicio;
            indiceServicio=buscarIndiceServicio(servicio, tamSer, idServicio);
            contador=contador+servicio[indiceServicio].precio;
        }
    }

    printf("El total del auto %s es %.2f\n", patente, contador);

}

/*void ServicioMasPedido(eServicio servicio[], int tamSer, eTrabajo trabajos[], int tamTra)
{
    int vec[tamSer];
    int idServicio[tamSer];
    int indice;
    int i, j;
    int id;
    int flag=0;
    int max;
    for(i=0; i<tamSer; i++)
    {
        vec[i]=0;
        idServicio[i]=servicio[i].id;
    }


    for(i=0; i<tamTra; i++)
    {
        for(j=0; j<tamSer; j++)
        {
            if(trabajos[i].idServicio==idServicio[j])
            {
                vec[i]++;
            }

        }

    }

    for(i=0; i<tamSer; i++)
    {
        if(vec[i]>max || flag==0)
        {
            max=vec[i];
            flag=1;
            id=i;
        }
    }
    indice=buscarIndiceServicio(servicio, tamSer,id);

    printf("El servicio mas pedido es %s con %d veces pedido",servicio[indice].descricion, max);

}*/

/*void recaudacionEnUnaFecha(eTrabajo trabajo[], int tamTra)
{

    int dia=getInt("INGRESE DIA DE INGRESO: ", "DIA DEBE SER ENTRE 1 Y 31.\n", 1,31);

    int mes=getInt("INGRESE MES DE INGRESO: ", "MES DEBE SER ENTRE 1 Y 12.\n", 1,12);

    int anio=getInt("INGRESE ANIO DE INGRESO: ", "ANIO DEBE SER ENTRE 1900 Y 2019.\n", 1900,2019);
    int i;
    float recaudacion;

    for(i=0; i<tamTra; i++)
    {
        if((trabajo[i].fecha.dia == dia) && (trabajo[i].fecha.mes == mes) && (trabajo[i].fecha.anio == anio))

    }

}*/
