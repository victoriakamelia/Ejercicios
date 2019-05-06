#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char nombre[20] = "JuAn carLos";
    char apellido[25] = {"PEreZ"};
    char ncomp[46];
    int cont = 0;

    strcpy(ncomp, apellido);
    strcat(ncomp, ", ");
    strcat(ncomp, nombre);

    strlwr(ncomp);

    ncomp[0] = toupper(ncomp[0]);

    while( ncomp[cont] != '\0'){

            if( ncomp[cont] == ' '){
                ncomp[cont + 1] = toupper(ncomp[cont+1]);
            }
            cont++;
    }




    puts(ncomp);









    return 0;
}
