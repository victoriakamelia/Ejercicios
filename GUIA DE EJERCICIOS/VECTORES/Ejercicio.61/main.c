#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vectorCompra[31]={65,9,8,50,5,1,6,36,8,0,0,0,888,9,4,44,55,6,78,79,45,45,0,1,5,5,5,98,5,4,7};
    int i;
    int flag=0;
    int ubicacion;
    int max;

    for(i=0; i<31; i++)
    {
        if(flag==0 || vectorCompra[i]>max)
        {
            max=vectorCompra[i];
            ubicacion=i+1;
            flag=1;
        }
    }

    printf("El dia que realizó más gasto fue el %d, con un total de $%d.\n", ubicacion, max);
    return 0;
}
