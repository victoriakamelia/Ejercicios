#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    float sueldo;
    char sexo;
    eFecha fecha;
}eEmpleado;

void mostrarEmpleados(eEmpleado* list, int tam);
void mostrarEmpleado(eEmpleado* list);
int main()
{
    eEmpleado lista[]=
    {
        {1000, "JUAN", 34000, 'M', {1,5,2019}},
        {1100, "ANA", 33000, 'F', {8,6,2015}},
        {1200, "MARIO", 21000, 'M', {14,2,2017}}

    };
    eEmpleado* pEmp;
    pEmp= lista;

    //printf("%s", pEmp->nombre);
    //printf("%02d/%02d/%d ", pEmp->fecha.dia, pEmp->fecha.mes, pEmp->fecha.anio);
    //printf("Ingrese nombre: ");
    //scanf("%s", pEmp->nombre);
    //gets(pEmp->nombre);

    //printf("%s", pEmp->nombre);

    //printf("Ingrese sueldo: ");
    //scanf("%f", &pEmp->sueldo);
    //printf("%.2f", pEmp->sueldo);

    mostrarEmpleados(pEmp, 3);

    return 0;
}

void mostrarEmpleados(eEmpleado* list, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        mostrarEmpleado(&list[i]);
    }
}

void mostrarEmpleado(eEmpleado* list)
{

printf("%d   -%10s   -   %.2f   -   %c   -   %02d/%02d/%d\n", list->legajo, list->nombre, list->sueldo, list->sexo, list->fecha.dia, list->fecha.mes, list->fecha.anio);

}
