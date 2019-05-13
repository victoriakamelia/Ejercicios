#include "trabajo.h"
#include "servicio.h"
#include "auto.h"
#include "marca.h"
#include "color.h"
#include "validaciones.h"

void harcodeTrabajos(eTrabajo tra[], int tamTra)
{
    eTrabajo hardcode[]=
    {
        {3000,"abc123",20000,{13,5,2019},1},
        {3001,"knj605",20001,{10,5,2019},1},
        {3002,"dlb011",20001,{1,5,2019},1},
        {3003,"awf818",20002,{1,5,2019},1},
        {3004,"www234",20003,{30,4,2019},1},
        {3005,"awf818",20000,{10,4,2019},1},
        {3006,"biu587",20003,{15,4,2019},1},
        {3007,"biu587",20000,{30,4,2019},1},
        {3008,"weg260",20002,{31,3,2019},1},
        {3009,"www234",20002,{21,3,2019},1},
        {3010,"sew899",20000,{12,4,2019},0},
        {3011,"kdm285",20001,{13,4,2019},0},
        {3012,"awf818",20002,{13,4,2019},0},
        {3013,"dlb011",20003,{15,4,2019},0},
        {3014,"sew899",20002,{26,4,2019},0}
    };

    for(int i=0; i<tamTra; i++)
    {
        tra[i]=hardcode[i];
    }
}


void inicializarTrabajo(eTrabajo tra[], int tamTra)
{

    for(int i=0; i < tamTra; i++)
    {
        tra[i].ocupado = VACIO;
    }
}



int buscarLibreTrabajo(eTrabajo tra[], int tamTra)
{

    int indice = -1;

    for(int i=0; i < tamTra; i++)
    {
        if(tra[i].ocupado == VACIO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}



int buscarTrabajo(eTrabajo tra[], int tamTra, int idTrabajo)
{
    int indice= -1;

    for(int i=0; i<tamTra; i++)
    {
        if(tra[i].id == idTrabajo && tra[i].ocupado == OCUPADO)
        {
            indice = i;
            break;
        }
    }

    return indice;

}



void altaTrabajo(eTrabajo tra[], int tamTra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ)
{
    char patente[6];
    int idServicio;
    char valServicio[5];
    int indice;
    char seguir;
    char valDia[2];
    char valMes[2];
    char valAnio[4];

    do
    {

        system("cls");
        printf("Alta Trabajo\n");


        indice = buscarLibreTrabajo(tra,tamTra);


        if(indice == -1)
        {
            printf("No hay mas espacio para cargar trabajos\n");
            printf("\n\n");
            system("pause");
            break;
        }
        else
        {

            mostrarAutos(aut,tamAut,mar,tamMar,col,tamCol);

            printf("Ingrese patente: ");
            fflush(stdin);
            gets(patente);

            if(buscarPatente(aut,tamAut,patente)== -1)
            {
                printf("Esta patente no existe\n");
                system("pause");
                break;
            }
            else
            {
                strcpy(tra[indice].patente,patente);
            }

            listarServicios(serv,tamServ);

            printf("Ingrese ID Servicio: ");
            fflush(stdin);
            gets(valServicio);

            idServicio = validarEnteroRango(valServicio,20000,20003);

            tra[indice].idServicio = idServicio;

            printf("Fecha de Inicio\n");

            printf("Ingrese anio: ");
            fflush(stdin);
            gets(valAnio);

            tra[indice].fechaTrabajo.anio = validarEnteroRango(valAnio,2019,2080);

            printf("Ingrese mes: ");
            fflush(stdin);
            gets(valMes);

            tra[indice].fechaTrabajo.mes = validarEnteroRango(valMes,1,12);

            printf("Ingrese dia: ");
            fflush(stdin);
            gets(valDia);

            if (tra[indice].fechaTrabajo.mes == 4 ||tra[indice].fechaTrabajo.mes == 6 || tra[indice].fechaTrabajo.mes == 9 || tra[indice].fechaTrabajo.mes == 11)
            {
                tra[indice].fechaTrabajo.dia = validarEnteroRango(valDia,1,30);
            }else if(tra[indice].fechaTrabajo.mes == 2)
             {
                tra[indice].fechaTrabajo.dia = validarEnteroRango(valDia,1,28);
             }else
              {
                tra[indice].fechaTrabajo.dia = validarEnteroRango(valDia,1,31);
              }

            tra[indice].id = cargarIdTrabajo();

            tra[indice].ocupado = OCUPADO;


            printf("El Trabajo se ha registrado con exito!!\n");


            seguir = validarSeguir();

        }
    }
    while(seguir == 'S' || seguir == 's');
}


void mostrarTrabajo(eTrabajo tra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ)
{
    char marca[20];
    char servicio[20];
    int loMuestro;

    for(int i=0; i<tamAut; i++)
    {
        if(stricmp(aut[i].patente,tra.patente) == 0)
        {
            for(int j=0; j<tamMar; j++)
            {
                if(mar[j].id == aut[i].idMarca)
                {
                    strcpy(marca,mar[j].descripcion);
                    loMuestro = aut[i].ocupado;
                    break;
                }
            }
        }
    }

    for(int k=0; k<tamServ; k++)
    {
        if(serv[k].id == tra.idServicio)
        {
            strcpy(servicio,serv[k].descripcion);
            break;
        }
    }

    if(loMuestro)
    {
        printf("%5d %9s %9s %9s %02d/%02d/%d\n", tra.id, servicio, marca, tra.patente, tra.fechaTrabajo.dia, tra.fechaTrabajo.mes, tra.fechaTrabajo.anio);
    }

}



void mostrarTrabajos(eTrabajo tra[], int tamTra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ)
{
    int flag = 0;


    system("cls");
    printf("  ID   Servicio   Marca  Patente  Fecha\n\n");


    for(int i=0; i<tamTra; i++)
    {
        if(tra[i].ocupado == OCUPADO)
        {
            mostrarTrabajo(tra[i],aut,tamAut,mar,tamMar,col,tamMar,serv,tamServ);
            flag = 1;
        }
    }


    if(flag == 0)
    {
        printf("No hay trabajos cargados\n");
    }

}

/*
void menuInformes(eEmpleado x[],int tam, eSector sec[], int tamSec, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm)
{
    char seguir = 's';
    int opcion;
    int anio;

    do
    {

        system("cls");
        printf("1- Mostrar Empleados Por Anio\n");
        printf("2- Mostrar Empleados de un Sector\n");
        printf("3- Cantidad de Empleados x Sector\n");
        printf("4- Empleados x Sector\n");
        printf("5- Sectores con mas empleados\n");
        printf("6- Empleados que mas ganan x Sector\n");
        printf("7- Sectores con Mujeres\n");
        printf("8- Promedio y Total de Salarios de un Sector\n");
        printf("9- Nacidos <= 2009\n");
        printf("10- Cant de Comidas Comidas\n");
        printf("11- Cant de Hombres x Sector\n");
        printf("12- Empleado que menos gana\n");
        printf("13- Almuerzos x Empleado\n");
        printf("14- Almuerzos x Fecha\n");
        printf("15- Mostrar Empleados sg la descripcion comida\n");
        printf("16- Mostrar Almuerzos del mismo Dia\n");
        printf("17- Mostrar el almuerzo mas comido\n");
        printf("18- Almuerzos x Sector\n");
        printf("19- Clientes que no comieron\n");
        printf("20- Almuerzos x Hombres\n");
        printf("21- Comidas + comidas x Mujeres\n");
        printf("22- Almuerzos de los empleados mas perdedores\n");
        printf("23- Importes pagados x Cliente\n");
        printf("24- Recaudacion x Fecha\n");
        printf("25- Mostrar Empleados sg ID Comida\n");
        printf("26- Mostrar mujeres sg comida\n");
        printf("27- Almuerzo mas Comido x Sector\n");
        printf("28- Listar Empleados x Sector/Nombre\n");
        printf("29- Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {

        case 1:
            printf("\n\n");
            printf("Ingrese anio a buscar: ");
            scanf("%d",&anio);

            empleadoXanio(x,tam,anio,sec,tamSec);
            break;

        case 2:
            listarEmpXsector(x,tam,sec,tamSec);
            break;

        case 3:
            totalEmpxSector(x,tam,sec,tamSec);
            break;

        case 4:
            empXsector(x,tam,sec,tamSec);
            break;

        case 5:
            sectMasEmpleados(x,tam,sec,tamSec);
            break;

        case 6:
            empMasGanadorXsector(x,tam,sec,tamSec);
            break;

        case 7:
            sectorMujeres(x,tam,sec,tamSec);
            break;

        case 8:
            promSector(x,tam,sec,tamSec);
            break;

        case 9:
            menorIgual2009(x,tam,sec,tamSec);
            break;

        case 10:
            contadorComida(x,tam,sec,tamSec,alm,tamAlm,com,tamCom);
            break;

        case 11:
            cantHombres(x,tam,sec,tamSec);
            break;

        case 12:
            empMasPerdedor(x,tam,sec,tamSec);
            break;

        case 13:
            almuerzosXemp(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;

        case 14:
            almuerzosXfecha(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;

        case 15:
            almuerzosXdescrip(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;

        case 16:
            almuerzosXmismaFecha(x,tam,com,tamCom,alm,tamAlm);
            break;

        case 17:
            almuerzosMasComido2(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;

        case 18:
            almuerzosXsector(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;

        case 19:
            empleadosQueNoAlmorzaron(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;

        case 20:
            AlmuerzosXhombres(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;

        case 21:
            AlmuerzosMasComidosXmujeres(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;

        case 22:
            almuerzosEmpMasPerdedor(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;

        case 23:
            importesEmpleado(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;

        case 24:
            totalXfecha(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;


        case 25:
            almuerzoXcomida(x,tam,sec,tamSec,alm,tamAlm,com,tamCom);
            break;


        case 26:
            almuerzosXmujeres(x,tam,sec,tamSec,alm,tamAlm,com,tamCom);
            break;


        case 27:
            almuerzoMasComidoXsector(x,tam,sec,tamSec,alm,tamAlm,com,tamCom);
            break;


        case 28:
            ordenarEmpXsectorYnombre(x,tam,sec,tamSec);
            break;

        case 29:
            seguir = 'n';
            break;

        default:
            printf("\n Opcion invalida\n\n");
            system("break");
        }

        system("pause");
        system("cls");
    }
    while(seguir == 's');
}
*/
