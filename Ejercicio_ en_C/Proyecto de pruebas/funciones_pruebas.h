#ifndef FUNCIONES_PRUEBAS_H_INCLUDED
#define FUNCIONES_PRUEBAS_H_INCLUDED

#define NOMBRE_LEN 50
#define DESCRIPCION_LEN 250

typedef struct
{
    char nombre[NOMBRE_LEN];
    char descripcion[DESCRIPCION_LEN];
    float precio;

}eProducto;

/** \brief
 *
 * \param pResultado char*
 * \param longitud int
 * \param mensaje char*
 * \param mensajeError char*
 * \param reintentos int
 * \return int
 *
 */
int utn_getNombre(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos);

/** \brief
 *
 * \param pResultado char*
 * \param longitud int
 * \param mensaje char*
 * \param mensajeError char*
 * \param reintentos int
 * \return int
 *
 */
int utn_getDescripcion(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos);
#endif // FUNCIONES_PRUEBAS_H_INCLUDED
