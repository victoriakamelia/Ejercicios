#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    int tam, i;
    LinkedList* listaEmpleados = ll_newLinkedList();
    Employee* emp1=employee_newParametros("1111", "JUAN", "123", "35000");
    Employee* emp2=employee_newParametros("2222", "JUANA", "340", "16000");
    Employee* emp3=employee_newParametros("3333", "pedro", "234", "2000");

    printf("cantidad elementos: %d\n", ll_len(listaEmpleados));
    if(ll_add(listaEmpleados, emp1)==0)
    {
        printf("Se ha agregado con exito a la lista\n");
    }
     printf("cantidad elementos: %d\n", ll_len(listaEmpleados));
    if(ll_add(listaEmpleados, emp2)==0)
    {
        printf("Se ha agregado con exito a la lista");
    }
     printf("cantidad elementos: %d\n", ll_len(listaEmpleados));
    if(ll_add(listaEmpleados, emp3)==0)
    {
        printf("Se ha agregado con exito a la lista");
    }
    printf("cantidad elementos: %d\n", ll_len(listaEmpleados));
    mostrarEmpleado((Employee*)ll_get(listaEmpleados, 1));

    tam=ll_len(listaEmpleados);

    for(i=0; i<tam; i++)
    {
        mostrarEmpleado((Employee*)ll_get(listaEmpleados, i));
    }




    /*do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
        }
    }while(option != 10);*/


    return 0;
}
