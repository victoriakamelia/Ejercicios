#include <stdio.h>
#include <stdlib.h>

void calcuBaseTrian();

int main()
{

    calcuBaseTrian();
    return 0;
}

void calcuBaseTrian()
{
    int base;
    int altura;
    float resultado;

    printf("Ingrese la base del triangulo:  \n");
    scanf("%d", &base);

    printf("Ingrese la altura del triangulo:  \n");
    scanf("%d", &altura);

    resultado=(float)(base*altura)/2;

    printf("La superficie del triangulo es: %.2f\n", resultado);


}
