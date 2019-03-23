#include <stdio.h>
#include <stdlib.h>

void ejercicioClaseDos();
int main()
{

    ejercicioClaseDos();
    return 0;
}
void ejercicioClaseDos()
{
    int numero;
    int acumulador=0;
    int min=;
    int max;
    int auxMax;
    int auxMin;
    int promedio;
    int i;



    for(i=0; i<5; i++)

    {
        printf("Ingrese un numero: \n");
        scanf("%d", &numero);

        if(auxMin<min)
            {
                min=auxMin;
            }else
             {
                 max=auxMax;
             }

        acumulador=acumulador+numero;
    }

    promedio=acumulador/5;
    printf("PROMEDIO: %d", promedio);
    printf("MINIMO: %d", max);
    printf("MAXIMO: %d", min);




}
