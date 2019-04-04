#include <stdio.h>
#include <stdlib.h>

int len=10;



void menu(int[], int);
void cargarVector(int[], int);
void ordenarVector(int[], int);
void mostrarVector(int[], int);
void salir(int[],int);

int main()

{
    int vector[len];
    int accion;
    accion=menu(vector[len],len);

    return 0;
}

void menu(int vector[len],int len)
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

           cargarVector(vector[len], len);

        }else
             if(opcion == 2)
             {

                ordenarVector(vector[len], len);

             }else
                  if(opcion == 3)
                  {

                     mostrarVector(vector[len], len);

                  }else
                       if(opcion == 4)
                       {

                          salir(vector[len], len);

                       }else
                        {
                            printf("Ingreso opcion incorrecta. ");
                        }
        }else
             if(opcion == 4)
             {
                 salir(vector[len], len);
             }else
                {
                    printf("Para seleccionar otra opcion primero debe cargar el vector.");
                }



}

void cargarVector(int vector[], int len)
{


    for(int i=0; i<len; i++)
    {
        printf("Ingrese un numero: \n");
        scanf("%d", vector[i]);
    }


}

void ordenarVector(int vector[], int len)
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


}

void mostrarVector(int vector[], int len)
{
    for(int i=0; i<len;i++)
    {
       printf("%d", vector[i]);
    }



}

void salir(int vector[],int len)
{
    for(int i=0; i<len;i++)
    {
        printf("-%d-", vector[i]);
    }



}
