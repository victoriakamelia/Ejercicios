typedef struct
{
    char nombre[20];
    char sexo;
    float sueldo;
    int legajo;
    int estado;

} Eempleado;


char validarSeguir();
int bajaEmpleado(Eempleado emp[],int tam, int id);
int buscarId(Eempleado[], int tam, int id);
int buscarLibre(Eempleado[], int tam);

int getFloat(Eempleado emp[],int index);
int getInt(Eempleado emp[],int tam, int index);
int getText(Eempleado emp[],int index);

int modificarEmpleado(Eempleado emp[],int indice, int opcion2);
int mostrarEmpleados(Eempleado[],int tam);
int pedirSexo(Eempleado emp[],int index);
void cargarEmpleado(Eempleado emp[], int tam);
void initEmpleado(Eempleado emp[], int tam);
void mostrarEmpleado(Eempleado emp);
void ordenamiento(Eempleado[], int tam);








