#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define NOMBRE_LEN 8
#define CLAVE_LEN 15
#define USUARIOS_LEN 10
#define OCUPADO 1
#define LIBRE 0

/*1era etapa:
Poder guardar los datos a medida que los usuarios se quieran registrar ( usuario y clave)

2da etapa:
Poder mostrar todos los usuarios registrados en tu sistema

3era etapa:
Poder logearse al sistema si su usuario y clave son correctos*/

typedef struct
{
    char nombre[NOMBRE_LEN];
    char clave[CLAVE_LEN];
    int isEmpty;

}Usuario;

int user_initArray(Usuario* array, int limite);
int user_getIndex(Usuario* array, int limite);
int user_cargarArray(Usuario* array, int limite, int indice, FILE* pFile);
int user_saveArray(Usuario* array, int limite, FILE* pFile);
int user_mostrarArray(Usuario* array, int limite);

int main()
{
    Usuario listadoArray[USUARIOS_LEN];
    int opcion;
    int i;
    int indiceUsuario;
    FILE* pFile;

    if(!user_initArray(listadoArray,USUARIOS_LEN)
    {
        printf("\nINIT OK.");
    }
    do
    {
        printf("1. Registrar usuario\n2. Mostrar usuarios\n3. Login\n4. Salir");
        utn_getNumero(&opcion,"\nIngrese opcion: ","\nERROR. ",1,4,2);

        switch(opcion)
        {
        case 1:
            printf("\nCargar usuario");
            indiceUsuario = user_getIndex(listadoArray,USUARIOS_LEN);

            if(!user_cargarArray(listadoArray,USUARIOS_LEN,indiceUsuario,pFile))
            {
                printf("\nUsuario registrado con exito.");
            }
            else
            {
                printf("\nOcurrio un error.");
            }
            break;
        case 2:
            if(!user_saveArray(listadoArray,USUARIOS_LEN,pFile))
            {
                if(!user_mostrarArray(listadoArray,USUARIOS_LEN))
                {
                    printf("\nTodo ok.");
                }
            }
            break;
        case 3:

            break;
        }
    }while(opcion != 4);
    return 0;
}

int user_initArray(Usuario* array, int limite)
{
    int retorno = -1;
    int i;
    if(array != NULL && limite > 0)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            (array+i)->isEmpty = LIBRE;
        }
    }
    return retorno;
}

int user_getIndex(Usuario* array, int limite)
{
    int retorno = -1;
    int i;
    if(array != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            if(array->isEmpty == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int user_cargarArray(Usuario* array, int limite, int indice, FILE* pFile)
{
    int retorno = -1;
    Usuario buffer;
    if(array != NULL && limite > 0 && indice >= 0 && indice < limite)
    {
        utn_getDescripcion(buffer.nombre,NOMBRE_LEN,"\nIngrese su usuario:","\nERROR. usuario incorrecto",2);
        utn_getDescripcion(buffer.clave,CLAVE_LEN,"\nIngrese su clave:","\nERROR. clave incorrecta",2);
        buffer.isEmpty = OCUPADO;
        *(array+indice) = buffer;
        pFile = fopen("data usuarios.csv","w");
        fprintf(pFile,"%s,%s,%d\n",(array+indice)->nombre,(array+indice)->clave,(array+indice)->isEmpty);
        fclose(pFile);

    }
    return retorno;
}

int user_mostrarArray(Usuario* array, int limite)
{
    int retorno = -1;
    int i;
    if(array != NULL && limite > 0)
    {
        printf("\n %3s - %3s - %3s","Usuario","Clave","Estado");
        for(i=0;i<limite;i++)
        {
            if((array+i)->isEmpty == OCUPADO)
            {
                retorno = 0;
                printf("\n%3s - %3s - %3d",(array+i)->nombre,(array+i)->clave,(array+i)->isEmpty);
            }
        }
    }
    return retorno;
}

int user_saveArray(Usuario* array, int limite, FILE* pFile)
{
    int retorno = -1;
    int i;
    if(array != NULL && limite > 0)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if((array+i)->isEmpty == OCUPADO)
            {
                pFile = fopen("data usuarios.csv","r");
                fscanf(pFile,"%s[^,],%s[^,],%d[^\n]\n",(array+i)->nombre,(array+i)->clave,(array+i)->isEmpty);
                fclose(pFile);
            }
        }
    }
    return retorno;
}
