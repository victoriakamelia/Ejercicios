#include <stdio.h>
#include <stdlib.h>

int main()

{
    char letra;
    int contadorA=0;
    int contadorE=0;
    int contadorI=0;
    int contadorO=0;
    int contadorU=0;


    for(int i=0; i<5; i++)
    {

      printf("Ingrese una letra: \n");
      scanf("%c", &letra);


      if (letra == 'a')
      {
          contadorA++;
      }else
           if (letra == 'e')
           {
               contadorE++;
           }else
                if (letra == 'i')
                {
                    contadorI++;
                }else
                     if (letra == 'o')
                     {
                         contadorO++;
                     }else
                          if (letra == 'u')
                          {
                              contadorU++;
                          }


       fflush( stdin );

    }

    printf("Cantidad de letras A ingresadas: %d\n",contadorA);
    printf("Cantidad de letras E ingresadas: %d\n",contadorE);
    printf("Cantidad de letras I ingresadas: %d\n",contadorI);
    printf("Cantidad de letras O ingresadas: %d\n",contadorO);
    printf("Cantidad de letras U ingresadas: %d\n",contadorU);

    return 0;
}
