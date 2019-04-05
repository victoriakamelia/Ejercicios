#include <stdio.h>
#include <stdlib.h>

int main()
{
    int codigo[]={8000,1901,1552,2503,9044,4505,1886,1857,6008,7009};
    int precio[]={150,75,195,560,225,145,700,400,120,60};
    int cantidad[]={89,5,2,78,56,15,3,30,4,0};
    int i;
    int j;
    int aux;


    for(i=0; i<9;i++)
    {
        for(j=i+1; j<10;j++)
        {
            if(codigo[i] < codigo[j])
            {
                aux=codigo[i];
                codigo[i]=codigo[j];
                codigo[j]=aux;


                aux=precio[i];
                precio[i]=precio[j];
                precio[j]=aux;


                aux=cantidad[i];
                cantidad[i]=cantidad[j];
                cantidad[j]=aux;


            }
        }
    }

    printf("\nCODIGO   PRECIO  CANTIDAD\n");
    for(i=0; i<10; i++)
    {
        printf("%d       %d       %d\n", codigo[i], precio[i], cantidad[i]);
    }
    return 0;
}
