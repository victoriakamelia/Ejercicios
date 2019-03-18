#include <stdio.h>
#include <stdlib.h>
int len=5;


void insercion(int [],int);


int main()
{

    int data[len];
    data[0]=3;
    data[1]=1;
    data[2]=2;
    data[3]=9;
    data[4]=5;
    insercion(data,len);


    return 0;
}

void insercion(int data[],int len)
{
     int i,j;
     int temp;
      for(i=1;i<len;i++)
        {
            temp = data[i];
            j=i-1;
                while(j>=0 && temp<data[j])
                    {
                        data[j+1] = data[j];
                        j--;
                    }
            data[j+1]=temp;
        }

        for(i=0; i<len;i++)
        {
            printf("%d",data[i]);

        }

}
