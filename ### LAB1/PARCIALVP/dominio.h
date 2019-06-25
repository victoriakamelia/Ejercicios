#ifndef DOMINIO_H_INCLUDED
#define DOMINIO_H_INCLUDED

typedef struct
{
    int id;
    char dominio[20];
    int anio;
    //int tipo;

}eDominio;

#endif // DOMINIO_H_INCLUDED

eDominio* dominio_new();
eDominio* dominio_newParametros(char* idStr,char* strDominio, char* anio);
int dominio_setId(eDominio* this,int* id);
int dominio_getId(eDominio* this,int* id);
int dominio_setDominio(eDominio* this,char* dominioS);
int dominio_getDominio(eDominio* this,char* dominioS);
int dominio_setAnio(eDominio* this,int* anioS);
int dominio_getAnio(eDominio* this,int* anioS);

int dominio_geteDominio(eDominio* this,int* id,char* dominioS, int* anio);
void dominio_printDominio(eDominio* dominio);
