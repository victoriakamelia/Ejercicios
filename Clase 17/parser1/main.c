#include <stdio.h>
#include <stdlib.h>

int main()
{
    //int numeros[]={3,2,4,5,2,6,5,4,7,1,9,3};
    FILE* f;
    int num1;
    int num2;
    int num3;
    int num4;
    int cant;

    f=fopen("./parser.txt", "r");

    if(f == NULL)
    {
        printf("No se pudo abrir archivo\n");
        system("pause");
        exit(1);
    }


    /*for(i=0; i<12; i++)
    {
        if((i+1)%4 !=0)
        {
        fprintf(f, "%d,", numeros[i]);
        }else
        {
            fprintf(f, "%d\n", numeros[i]);
        }

    }*/

    while(!feof(f))
    {
        cant=fscanf(f,"%d,%d,%d,%d\n", &num1, &num2, &num3, &num4);

        //printf("cant %d", cant);
        //system("pause");
        if(cant<4)
        {
            if(feof(f))
            {
                break;
            }else
            {
                printf("No se pudo sarasa");

            }
        }
        printf("%d %d %d %d", num1, num2, num3, num4);
    }

    fclose(f);

    return 0;
}
