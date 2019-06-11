#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char buffer[4][30];
    int cant;
    pFile = fopen("data.csv", "r");

    if( f == NULL){
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }

       fscanf(f, "%[^,],%[^,],%[^,],%[^\n],\n", buffer[0], buffer[1], buffer[2], buffer[3]);
       printf("%s %s %s %s\n", buffer[0], buffer[1], buffer[2], buffer[3]);

    while( !feof(f)){

       cant =  fscanf(f, "%[^,],%[^,],%[^,],%[^\n],\n", buffer[0], buffer[1], buffer[2], buffer[3]);



        if(cant < 4){

            if( feof(f)){
                break;
            }
            else{
                printf("Problemas para leer el archivo\n");
                break;
            }
        }
         (lista + cont)->id = atoi(buffer[0]);
         strcpy( (lista + cont)->nombre, buffer[1]);
         strcpy( (lista + cont)->apellido, buffer[2]);
        (lista + cont)->sueldo = atof(buffer[3]);
        cont++;
        auxEmpleado = (eEmpleado*) realloc(lista, sizeof(eEmpleado)* (cont +1));
        if( auxEmpleado != NULL){
            lista = auxEmpleado;
        }

     //   printf(" %5d %15s %15s %8.2f\n", atoi(buffer[0]), buffer[1], buffer[2], atof(buffer[3]));
    }
    printf("\n\n");

    fclose(f);

    for(int i=0; i < cont; i++){
        printf(" %5d %15s %15s %8.2f\n", (lista + i)->id, (lista + i)->nombre, (lista + i)->apellido, (lista + i)->sueldo);

    }


    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
