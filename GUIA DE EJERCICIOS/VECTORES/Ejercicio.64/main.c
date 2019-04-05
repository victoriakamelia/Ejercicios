#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vec[10]={-4,-5,-6,-1,5,6,3,8,2,9};
    int i;
    int j;
    int aux;

    for(i=0; i<10-1; i++)
    {
        for(j=i+1; j<10; j++)
        {
            if(vec[i]<vec[j])
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
        }
    }

    for(i=0; i<10; i++)
    {
        while(vec[i]>0)
        {
           printf("%d ", vec[i]);
           break;
        }

    }
    printf("\n\n");
    for(i=0; i<10; i++)
    {
        while(vec[i]<0)
        {
           printf("%d ", vec[i]);
           break;
        }

    }
    return 0;



}
