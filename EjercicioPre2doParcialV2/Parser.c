#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

int parser_parseEmpleados(FILE* fileName, LinkedList* listaEmpleados)
{

    int retorno =-1;

    if(fileName!= NULL && listaEmpleados!=NULL)
    {

        LinkedList* auxiliarPunteroEmployee = NULL;

        int flagOnce=1;
        char bufferId[128];
        int auxID;
        char bufferNombre[128];
        char bufferHorasTrabajadas[128];
        int contadorEmployees=0;

        do
        {
            if(flagOnce)
            {
                fscanf(fileName,"%[^,],%[^,],%[^\n]\n",
                       bufferId,
                       bufferNombre,
                       bufferHorasTrabajadas);
                flagOnce = 0;
            }
            else
            {

                if(fscanf(fileName,"%[^,],%[^,],%[^\n]\n",
                          bufferId,
                          bufferNombre,
                          bufferHorasTrabajadas) == 3)
                {

                    if(!funciones_ValidIdStr(bufferId,&auxID))
                    {
                        if( controller_findEmployeeByID(listaEmpleados,auxID) <0 )
                        {
                            auxiliarPunteroEmployee = (LinkedList*)employee_newParametros(bufferId,bufferNombre,bufferHorasTrabajadas);
                        }
                        else
                        {
                            printf("\nError, ID ya existe.\n");
                            auxiliarPunteroEmployee = NULL;
                        }
                    }


                    if(auxiliarPunteroEmployee != NULL)
                    {
                        ll_add(listaEmpleados,auxiliarPunteroEmployee);
                        contadorEmployees++;
                    }
                    else
                    {
                        printf("\n No se puede Agregar Empleado ID: %s\n",bufferId);
                    }
                }
                else
                {
                    break;
                }
            }
        }
        while(!feof(fileName));

        fclose(fileName);
        printf("\n Se Cargaron: %i Empleados\n",contadorEmployees);
        retorno = 0;
    }

    return retorno;
}

