#include "validaciones.h"
#include "trabajo.h"


/** \brief carga el id incrementalmente
 *
 * \return int
 *
 */
int cargarId()
{
    static int id = 7;


    return id++;
}


/** \brief carga el id trabajo incrementalmente
 *
 * \return int
 *
 */
int cargarIdTrabajo()
{
    static int id1 = 3010;


    return id1++;
}


/** \brief pregunta si desea continuar
 *
 * \return char
 *
 */
char validarSeguir()
{
    char seguir;

    printf("     Desea continuar? s/n: ");
    fflush(stdin);
    seguir = getchar();
    seguir = toupper(seguir);

    while(seguir != 'S'  && seguir !='N' && seguir !='n' && seguir !='s')
    {
        printf("     ERROR. Esta opcion no es valida\n");
        printf("     Desea continuar? s/n: ");
        fflush(stdin);
        seguir = getchar();
        seguir = toupper(seguir);
    }

    return seguir;
}

/** \brief compara que las fechas sean iguales
 *
 * \param
 * \param
 * \return
 *
 */

int compararFechas(eFecha fech, eFecha fecha)
{
    int igual = 0;

    if(fech.dia == fecha.dia && fech.mes == fecha.mes && fech.anio == fecha.anio)
    {
        igual = 1;
    }
    return igual;
}


/** \brief recorre la cadena buscando que cada uno de sus chars sea igual a positivo o cero
 *
 * \param entero[] char
 * \return int
 *
 */
int validarEntero(char entero[])
{
    int entero1;

        while(strlen(entero)<=0)
    {
        printf("     El campo no puede estar vacio: ");
        fflush(stdin);
        gets(entero);
    }

    for(int i=0; i<strlen(entero); i++)
    {

        entero1 = atoi(entero);

        while(isalpha(entero[i]) != 0 || entero1 <= 0 || entero[i] == ' ' || entero[i] == ',' || entero[i] == '.')
        {
            printf("     Reingrese un valor numerico y positivo: ");
            fflush(stdin);
            gets(entero);
            i=0;
            entero1 = atoi(entero);
        }

    }

    return entero1;
}


void validarAlfaNum(char x[], int largo)
{

    while(strlen(x)<=0)
    {
        printf("     El campo no puede estar vacio: ");
        fflush(stdin);
        gets(x);
    }

    for(int i=0; i<strlen(x); i++)
    {
        while(strlen(x)>largo || (x[i] < 'a' || x[i] > 'z') && (x[i] < 'A' || x[i] > 'Z') && (x[i] < '0' || x[i] > '9') && x[i] != ' ')
        {
            printf("     Reingrese solo caracteres alfanum >%d: ",largo);
            fflush(stdin);
            gets(x);
            i=0;
        }
    }
}


void ValidarPatente(char x[])
{

    for(int i=0; i<=2; i++)
    {
        while(strlen(x)!=6)
    {
        printf("La patente deben ser 3 letras y 3 numeros: ");
        fflush(stdin);
        gets(x);
    }
         for(int j=3; j<strlen(x); j++)
    {
        while((x[i] < 'a' || x[i] > 'z') && (x[i] < 'A' || x[i] > 'Z'))
        {
            printf("Reingrese patente valida, 3 letras y 3 numeros: ");
            fflush(stdin);
            gets(x);
        }
        while(x[j] < '0' || x[j] > '9')
        {
            printf("Reingrese patente valida: ");
            fflush(stdin);
            gets(x);
        }
    }

    }
}


int validarEnteroRango(char entero[], int corto, int largo)
{
    int entero1;

        while(strlen(entero)<=0)
    {
        printf("     El campo no puede estar vacio: ");
        fflush(stdin);
        gets(entero);
    }

    for(int i=0; i<strlen(entero); i++)
    {

        entero1 = atoi(entero);

        while(isalpha(entero[i]) != 0 || entero1 <= 0 || entero[i] == ' ' || entero[i] == ',' || entero[i] == '.' || entero1 < corto || entero1 > largo)
        {
            printf("     Reingrese un valor numerico y positivo >%d <%d: ",corto,largo);
            fflush(stdin);
            gets(entero);
            i=0;
            entero1 = atoi(entero);
        }

    }

    return entero1;
}


int validarEnteroTam(char entero[], int largo)
{
    int entero1;

        while(strlen(entero)<=0)
    {
        printf("     El campo no puede estar vacio: ");
        fflush(stdin);
        gets(entero);
    }

    for(int i=0; i<strlen(entero); i++)
    {

        entero1 = atoi(entero);

        while(isalpha(entero[i]) != 0 || entero1 <= 0 || entero[i] == ' ' || entero[i] == ',' || entero[i] == '.' || strlen(entero)>largo)
        {
            printf("     Reingrese un valor numerico y positivo >%d: ",largo);
            fflush(stdin);
            gets(entero);
            i=0;
            entero1 = atoi(entero);
        }

    }

    return entero1;
}


void validarStringTam(char x[], int largo)
{

    while(strlen(x)<=0)
    {
        printf("     El campo no puede estar vacio: ");
        fflush(stdin);
        gets(x);
    }

    for(int i=0; i<strlen(x); i++)
    {
        while(isalpha(x[i]) == 0 || strlen(x)>largo || x[0] == '\0')
        {
            printf("     Reingrese solo caracteres alfabeticos >%d: ",largo);
            fflush(stdin);
            gets(x);
            i=0;
        }
    }
}
