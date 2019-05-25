#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* f;
    char x;

    f=fopen("archivo.txt", "w");
    if(f == NULL)
    {
        printf("archivo no encontrado.");
        exit(1);

    }

    fprintf(f, "Hola mundo.");
    fclose(f);

    f=fopen("archivo.txt", "r");

    while(!feof(f))
    {
        x=fgetc(f);
        printf("%c", x);
    }

    fclose(f);
    return 0;
}
