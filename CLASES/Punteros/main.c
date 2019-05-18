#include <stdio.h>
#include <stdlib.h>

int main()
{
    char cadena[20]="Esto es una cadena";
    char* p;

    p = cadena;

    while(*p != '\0')
    {
        printf("%c", *p);
        p++;
    }
    return 0;
}
