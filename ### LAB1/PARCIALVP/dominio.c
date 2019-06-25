#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominio.h"
#include "funciones_yg.h"

eDominio* dominio_new()
{
    eDominio* this;
    this=malloc(sizeof(eDominio));
    return this;
}

eDominio* dominio_newParametros(char* idStr,char* strDominio, char* anio)
{
   eDominio* this=NULL;
    this=dominio_new();
    int auxID;
    int auxAnio;

    auxID=atoi(idStr);
    auxAnio=atoi(anio);




        dominio_setId(this, &auxID);
        dominio_setDominio(this,strDominio);
        dominio_setAnio(this,&auxAnio);


            return this;

    /*else
    {
        printf("\nError! en validacion de parametros");
        return NULL;
    }*/



}

int dominio_setId(eDominio* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->id=*id;
        retorno=0;
    }
    return retorno;

}

int dominio_getId(eDominio* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int dominio_setDominio(eDominio* this,char* dominioS)
{
    int retorno=-1;

    if(this!=NULL)
    {
        strcpy(this->dominio,dominioS);
        retorno=0;
    }
    return retorno;
}



int dominio_getDominio(eDominio* this,char* dominioS)
{
    int retorno=-1;

    if(this!=NULL)
    {
        strcpy(dominioS, this->dominio);
        retorno=0;
    }
    return retorno;
}





int dominio_setAnio(eDominio* this,int* anioS)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->anio=*anioS;
        retorno=0;
    }
    return retorno;
}


int dominio_getAnio(eDominio* this,int* anioS)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *anioS=this->anio;
        retorno=0;
    }
    return retorno;
}


void dominio_printDominio(eDominio* dominio)
{
    int bufferId;
    char bufferDominio[20];
    int bufferAnio;

    if(dominio!= NULL)
    {
        if( !dominio_geteDominio(dominio,&bufferId,bufferDominio,&bufferAnio))
        {
            printf("\n%d-%s-%-d", bufferId,bufferDominio,bufferAnio);

        }
    }
}

int dominio_geteDominio(eDominio* this,int* id,char* dominioS, int* anio)
{

    int retorno =-1;


    if(this!= NULL)
    {
        if( !dominio_getId(this,id)&&
                !dominio_getDominio(this, dominioS) &&
                !dominio_getAnio(this,anio))

        {

            retorno =0;

        }
    }
    return retorno;
}
