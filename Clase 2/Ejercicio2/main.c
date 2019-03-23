#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int numero;
    float promedio;
    int suma=0;
    int acumPares=0;
    char seguir;
    int max;
    int min;
    int flag=0;
    int contador=0;



        do
        {

            printf("Ingrese un numero positivo: \n");
            scanf("%d", &numero);
            fflush(stdin);

            while(numero <= 0)
            {
                printf("EL NUMERO INGRESADO NO ES CORRECTO.\n");
                printf("Ingrese un numero positivo: \n");
                scanf("%d", &numero);
                fflush(stdin);

            }


            if(numero<min || flag == 0)
            {
                min=numero;
            }
            if(numero>max || flag == 0)
            {
                max=numero;
                flag=1;
            }

            suma=suma+numero;

            if(numero%2 == 0)
            {
                acumPares++;
            }


            contador++;
            printf("DESEA CONTINUAR? S/N.\n");
            scanf("%c", &seguir);



        }while(seguir == 's');

        if(seguir == 'n')
        {
            promedio=(float)suma/contador;

            printf("LA CANTIDAD DE NUMEROS PARES ES: %d\n", acumPares);
            printf("********************************************\n");
            printf("EL PROMEDIO DE LOS NUMEROS INGRESADOS ES: %.2f\n", promedio);
            printf("********************************************\n");
            printf("LA SUMA DE NUMEROS INGRESADOS ES: %d\n", suma);
            printf("********************************************\n");
            printf("EL MINIMO ES: %d\n", min);
            printf("********************************************\n");
            printf("EL MAXIMO ES: %d\n", max);
        }else
        {
            printf("LA OPCION INGRESADA NO ES CORRECTA.\n");
        }






    return 0;
}
