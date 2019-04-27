#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "employee.h"
#define TAM 10


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
        printf(" `.   `.                   1)Modificar Nombre.                   .'   .' \n");
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
int menu()
{
        int opcion;

        system("cls");
        system("color 57");
        printf("   .-.     .-.     .-.     .-.     .-.     .-.     .-.     .-.     .-. \n");
        printf(" .'   `._.'   `._.'   `._.'   `._.'   `._.'   `._.'   `._.'   `._.'   `.\n");
        printf("(    .     .-.     .-.     .-.     .-.     .-.     .-.     .-.     .    )\n");
        printf(" `.   `._.'   `._.'   `._.'   `._.'   `._.'   `._.'   `._.'   `._.'   .'\n");
        printf("   )    )                                                       (    (\n");
        printf(" ,'   ,'             M E N U   D E   O P C I O N E S.            `.   `.\n");
        printf("(    (                                                             )    )\n");
        printf(" `.   `.                   1)Alta empleado.                      .'   .' \n");
        printf("   )    )                                                      (    (\n");
        printf(" ,'   ,'                   2)Modificer empleado.                `.   `.\n");
        printf("(    (                                                            )    )\n");
        printf(" `.   `.                   3)Baja empleado.                      .'   .' \n");
        printf("   )    )                                                      (    (\n");
        printf(" ,'   ,'                   4)Informes.                          `.   `.\n");
        printf("(    (                                                            )    )\n");
        printf(" `.   `.                   5)Salir.                              .'   .' \n");
        printf("   )    )       _       _       _       _       _       _       (    (\n");
        printf(" ,'   .' `.   .' `.   .' `.   .' `.   .' `.   .' `.   .' `.   .' `.   `.\n");
        printf("(    '  _  `-'  _  `-'  _  `-'  _  `-'  _  `-'  _  `-'  _  `-'  _  `    )\n");
        printf("`.   .' `.   .' `.   .' `.   .' `.   .' `.   .' `.   .' `.   .' `.   .'\n");
        printf("  `-'     `-'     `-'     `-'     `-'     `-'     `-'     `-'     `-'\n");
        printf("->->->->->->->->->->->->->->->->-->->->-INGRESE OPCION SELECCIONADA: ");
        scanf("%d", &opcion);
        printf("\n\n\n");

        return opcion;
}


char validarSeguir()
{
    char seguir='S';
    printf("\n         /D E S E A    C O N T I N U A R ?   S/N: ");
    scanf("%s", &seguir);
    seguir=toupper(seguir);

    while(seguir != 'N' && seguir != 'S')
    {
        printf("\n          /LA OPCION INGRESADA ES INVALIDA.");
        printf("\n         /D E S E A    C O N T I N U A R ?   S/N: ");
        scanf("%s", &seguir);
        seguir=toupper(seguir);

    }

    return seguir;

}
int initEmployees(Employee list[],int tam)
{
    int retorno = -1;
    int i;
    if(tam > 0 && list != NULL)
    {
        retorno = 0;
        for(i=0; i<tam; i++)
        {
            list[i].isEmpty=0;
            list[i].id=0;
        }
    }
    return retorno;
}

int buscarLibre(Employee list[],int tam)
{
    int retorno = -1;
    int i;
    if(tam > 0 && list != NULL)
    {
        //retorno = -2;
        for(i=0; i<tam; i++)
        {
            if(list[i].isEmpty == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

