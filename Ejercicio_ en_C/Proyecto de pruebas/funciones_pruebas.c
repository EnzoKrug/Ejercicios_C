
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int getString(char* cadena, int longitud);
static int esNombre(char* cadena, int longitud);
static int getNombre(char* pResultado, int longitud);
static int esDescripcion(char* cadena, int longitud);
static int getDescripcion(char* pResultado, int longitud);


/** \brief
 *
 * \param cadena char*
 * \param longitud int
 * \return int
 *
 */
static int getString(char* cadena, int longitud)
{
    int retorno = -1;
    char bufferString[4096]; //ERROR QUE SE VA A RESOLVER MAS ADELANTE
    if(cadena != NULL && longitud > 0)
    {
        fflush(stdin); // fflush o __fpurge
        if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
        {
            if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
            {
                bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
            }
            if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
            {
                strncpy(cadena,bufferString,longitud);
                retorno = 0;
            }
        }
    }
    return retorno;
}

/** \brief Obtiene un string valido como nombre
 *
 * \param pResultado char* Puntero al espacio de mmemoria donde se dejara el resultado de la funcion
 * \param longitud int Es el limite de elementos del array
 * \return int Retorna 0 (EXITO) si se obtiene un nombre y -1 (ERROR) si no
 *
 */
static int getNombre(char* pResultado, int longitud)
{
    int retorno = -1;
    char buffer[4096];

    if(pResultado != NULL && longitud >0)
    {
        if(getString(buffer,sizeof(buffer)) == 0 &&
           esNombre(buffer,sizeof(buffer)) /*== 0*/ &&
           strnlen(buffer,sizeof(buffer)) < longitud)
        {
            strncpy(pResultado,buffer,longitud);
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief
 *
 * \param cadena char*
 * \param longitud int
 * \return int
 *
 */
static int esNombre(char* cadena, int longitud)
{
    int i;
    int retorno  = -1;

    if(cadena != NULL && longitud > 0)
    {
        for(i=0;cadena[i] != '\0' && i < longitud;i++)
        {
            if((cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z'))
            {
                retorno = 0; //si esta fuera del rango de las letras
                break;
            }
        }
    }
    return retorno;
}

int utn_getNombre(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos)
{
    char bufferString[4096];
    int retorno = -1;
    while(reintentos = -1)
    {
        reintentos--;
        printf("%s",mensaje);
        if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud)
        {
            strncpy(pResultado,bufferString,longitud);
            retorno = 0;
            break;
        }
        printf("%s", mensajeError);
    }
    return retorno;
}

/** \brief
 *
 * \param pResultado char*
 * \param longitud int
 * \return int
 *
 */
static int getDescripcion(char* pResultado, int longitud)
{
    int retorno = -1;
    char buffer[4096];

    if(pResultado != NULL && longitud >0)
    {
        if(getString(buffer,sizeof(buffer)) == 0 &&
           esDescripcion(buffer,sizeof(buffer)) == 0 &&
           strnlen(buffer,sizeof(buffer)) < longitud)
        {
            strncpy(pResultado,buffer,longitud);
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief
 *
 * \param cadena char*
 * \param longitud int
 * \return int
 *
 */
static int esDescripcion(char* cadena, int longitud)
{
    int i;
    int retorno = -1;

    if(cadena != NULL && longitud > 0)
    {
        for(i=0;cadena[i] != '\0' && i < longitud;i++)
        {
            if(cadena[i] > 32 && cadena[i] < 126) //ver caracteres permitidos en la tabla ASCII
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int utn_getDescripcion(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos)
{
    char bufferString[4096];
    int retorno = -1;
    while(reintentos = -1)
    {
        reintentos--;
        printf("%s",mensaje);
        if(getDescripcion(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud)
        {
            strncpy(pResultado,bufferString,longitud);
            retorno = 0;
            break;
        }
        printf("%s", mensajeError);
    }
    return retorno;
}
