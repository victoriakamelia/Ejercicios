#include <stdio.h>
#include <stdlib.h>

int len=10;
int vector[];


void menu();
int cargarVector(int[], int);
int ordenarVector(int[], int);
int mostarVector(int[], int);
int salir(int[],int);

int main()

{
    menu();

    return 0;
}

void menu()
{
   int opcion;

    printf("**********MENU DE VECTORES**********\n");
    printf("*ELIJA UNA OPCION PARA CONTINUAR:***\n");
    printf("*1)CARGAR UN VECTOR.****************\n");
    printf("*2)ORDENAR UN VECTOR.***************\n");
    printf("*3)MOSTRAR UN VECTOR.***************\n");
    printf("*4)SALIR.***************************\n");
    printf("************************************\n");
    scanf("%d",&opcion);


    if(opcion == 1)
    {
        if(opcion == 1)
        {

            cargarVector();

        }else
             if(opcion == 2)
             {

                ordenarVector();

             }else
                  if(opcion == 3)
                  {

                     mostrarVector();

                  }else
                       if(opcion == 4)
                       {

                          salir();

                       }else
                        {
                            printf("Ingreso opcion incorrecta. ");
                        }
        }else
             if(opcion == 4)
             {
                 salir();
             }else
                {
                    printf("Para seleccionar otra opcion primero debe cargar el vector.");
                }

                return 0;

}

int cargarVector(int vector[])
{


    for(int i=0; i<len; i++)
    {
        printf("Ingrese el %d° numero: \n", i);
        scanf("%d", vector[i]);
    }

    return 0;
}

int ordenarVector(int vector[], int len)
{
   int i,j;
   int temp;

   for(i=1;i<len;i++)
   {
        temp = vector[i];
        j=i-1;

        while(j>=0 && temp<vector[j])
        {
            vector[j+1] = vector[j];
            j--;
        }

        vector[j+1]=temp;
    }

    return 0;
}

int mostarVector(int vector[],len)
{
    for(i=0, i<len;i++)
        printf("-%d-", vector[i]);

        return 0;
}

int salir(int vector[],len)
{
    for(i=0, i<len;i++)
        printf("-%d-", vector[i]);

        return 0;
}
