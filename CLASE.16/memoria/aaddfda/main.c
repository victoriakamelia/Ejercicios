#include <stdio.h>
#include <stdlib.h>


typedef struct{

    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
}eEmpleado;

eEmpleado* new_Empleado();
void mostrarEmpleado(eEmpleado* pEmp);
eEmpleado* new_EmpleadoParam(int leg, char* nombre, char sexo, float sueldo);

int main()
{

    eEmpleado* emp1 = new_Empleado();
    eEmpleado* emp2 = new_EmpleadoParam(1111, "Sofia", 'f', 35000);



    mostrarEmpleado(emp1);
    mostrarEmpleado(emp2);

    return 0;
}

eEmpleado* new_Empleado(){

    eEmpleado* nuevo;

    nuevo = (eEmpleado* ) malloc(sizeof(eEmpleado));

    if( nuevo != NULL){

        nuevo->legajo = 0;
        strcpy(nuevo->nombre , "");
        nuevo->sexo = ' ';
        nuevo->sueldo = 0;
    }


    return nuevo;


}

void mostrarEmpleado(eEmpleado* pEmp){

printf("Leg: %d Nombre: %s Sexo: %c Sueldo: %.2f\n\n", pEmp->legajo, pEmp->nombre, pEmp->sexo, pEmp->sueldo);

}


eEmpleado* new_EmpleadoParam(int leg, char* nombre, char sexo, float sueldo){

    eEmpleado* nuevo;

    nuevo = (eEmpleado* ) malloc(sizeof(eEmpleado));

    if( nuevo != NULL){

        nuevo->legajo = leg;
        strcpy(nuevo->nombre , nombre);
        nuevo->sexo = sexo;
        nuevo->sueldo = sueldo;
    }


    return nuevo;


}


