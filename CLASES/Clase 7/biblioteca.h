typedef struct
{
    char nombre[20];
    char sexo;
    float sueldo;
    int legajo;
    int estado;

} Eempleado;



void mostrarEmpleado(Eempleado emp);
int mostrarEmpleados(Eempleado[],int tam);
void ordenamiento(Eempleado[], int tam);
int buscarLibre(Eempleado[], int tam);
int buscarId(Eempleado[], int tam, int id);
char validarSeguir();
int pedirSexo(Eempleado emp[],int index);
int getInt(Eempleado emp[],int index);
int getFloat(Eempleado emp[],int index);
int getText(Eempleado emp[],int index);
int bajaEmpleado(Eempleado emp[],int tam, int id);

