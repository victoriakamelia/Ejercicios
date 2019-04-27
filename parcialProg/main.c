#include <stdio.h>
#include <stdlib.h>

/*1.Realizar una función que saque el promedio en base a 2 números, y
devuelva 1(en caso de que lo logre) o 0(en caso de que este todo mal).
SIN VECTORES*/

int calcularPromedio(int num1, int num2);
int main()
{
    int numero1=8;
    int numero2=10;
    calcularPromedio(numero1, numero2);
    return 0;
}

int calcularPromedio(int num1, int num2)
{
    int retorno=0;
    int promedio;
    promedio=(num1+num2)/2;
    printf("%d", promedio);
    return retorno;

}
