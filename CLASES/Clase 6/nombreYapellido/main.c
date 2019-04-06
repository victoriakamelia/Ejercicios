#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char nombre[20]="VICTORia";
    char apellido[25]="pereYRA";
    char nombreCompleto[47];
    int cont=0;


    /*strlwr(nombre);
    strlwr(apellido);*/





    /*nombre[0]=toupper(nombre[0]);
    apellido[0]=toupper(apellido[0]);*/


    strcpy(nombreCompleto, apellido);
    strcat(nombreCompleto, ", ");
    strcat(nombreCompleto, nombre);

    strlwr(nombreCompleto);

    nombreCompleto[0]=toupper(nombreCompleto[0]);

    while(nombreCompleto[cont])



    puts(nombreCompleto);



    return 0;
}
