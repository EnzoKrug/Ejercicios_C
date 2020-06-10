
#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

/**
 * Alumno.h
 *
 *  Created on: May 26, 2020
 *     o
 */

#define NOMBRE_LEN 50

typedef struct
{
	char nombre[NOMBRE_LEN];
	float altura;
	int id;
}Alumno;

Alumno* alumno_new(void);
Alumno* alumno_newParametros(char* nombre,float altura,int id);
void alumno_delete(Alumno* this);


/**************************************************************/

int alumno_initArray(Alumno* arrayPunteros[],int limite);
int alumno_buscarLibreArray(Alumno* arrayPunteros[],int limite);
int alumno_imprimirArray(Alumno* arrayPunteros[],int limite);
int alumno_deleteIndexInArray(Alumno* arrayPunteros[],int limite, int indice);
int alumno_buscarPorIdArray(Alumno* arrayPunteros[],int limite, int id);
int alumno_agregarAlumnoArray(Alumno* arrayPunteros[],int limite, char* nombre, float altura, int id);
int alumno_borrarPorIdArray(Alumno* arrayPunteros[],int limite, int id);

#endif // ALUMNO_H_INCLUDED
