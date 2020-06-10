#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Alumno.h"

#define QTY_ALUMNOS 100

/**
 * 1 Alta alumno
 * 2 Baja alumno
 * 3 Modificar alumno
 * 4 Ordenar por nombre
 * 5 Imprimir
 * 6 Informe promedio alturas
 * 7 Informe alumno mas alto
 **/


int main(void)
{
	Alumno* arrayPunterosAlumno[QTY_ALUMNOS];

	if(!alumno_initArray(arrayPunterosAlumno,QTY_ALUMNOS))
	{
		printf("INIT OK");

		if(alumno_agregarAlumnoArray(arrayPunterosAlumno,QTY_ALUMNOS,"A BORRAR",1.85,111) >= 0)
		{
			printf("Alta OK");
		}

		if(alumno_agregarAlumnoArray(arrayPunterosAlumno,QTY_ALUMNOS,"ANA",1.65,112) >= 0)
		{
			printf("Alta OK");
		}


		alumno_imprimirArray(arrayPunterosAlumno,QTY_ALUMNOS);

		if(!alumno_borrarPorIdArray(arrayPunterosAlumno,QTY_ALUMNOS,111))
		{
			printf("\nBORRADO OK");
		}

		alumno_imprimirArray(arrayPunterosAlumno,QTY_ALUMNOS);

	}

	return 0;
}
