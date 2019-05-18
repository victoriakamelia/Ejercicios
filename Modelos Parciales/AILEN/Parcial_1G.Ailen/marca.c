#include "marca.h"

/** \brief harcodea las marcas
 *
 * \param mar[] eMarca
 * \param tamMar int
 * \return void
 *
 */
void harcodeMarcas(eMarca mar[], int tamMar)
{
    eMarca hardcode[]=
    {
        {1000, "Renault"},
        {1001, "Fiat"},
        {1002, "Ford"},
        {1003, "Chevrolet"},
        {1004, "Peugeot"}
    };

    for(int i=0; i<tamMar; i++)
    {
        mar[i]=hardcode[i];
    }
}

/** \brief lista las marcas
 *
 * \param mar[] eMarca
 * \param tamMar int
 * \return void
 *
 */
void listarMarcas(eMarca mar[], int tamMar)
{
    printf(" ID   Descripcion\n");
    printf("\n\n");

    for(int i=0; i<tamMar; i++)
    {
        printf(" %d   %s\n",mar[i].id, mar[i].descripcion);
    }
}

/** \brief obtiene la descripcion de la marca segun su ID, recorriendo toda la cadena
 *
 * \param mar[] eMarca
 * \param tamMar int
 * \param idMarca int
 * \param cadena[] char
 * \return void
 *
 */
void ObtenerMarcas(eMarca mar[], int tamMar, int idMarca, char cadena[])
{
    for(int i=0; i<tamMar; i++)
    {
        if(mar[i].id == idMarca)
        {
            //COPIAR LA DESCRIPCION DE LA CADENA
            //DESTINO/ORIGEN
            strcpy(cadena,mar[i].descripcion);

        }
    }
}
