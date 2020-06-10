#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include ".h"

#define NOMBRE_LEN 50
#define RAZA_LEN 20
#define CANTIDAD_CLIENTES 4

#define LIBRE 1
#define OCUPADO 0

typedef struct
{
	char nombre[NOMBRE_LEN];
	char dni[RAZA_LEN];
	float altura;
	int isEmpty;
	int id;

}Cliente;

int cli_imprimir(Cliente elemento);
int cli_inicializarArray(Cliente array[],int limite);
int cli_altaArray(Cliente array[],int limite, int indice, int* id);
int cli_getEmptyIndex(Cliente array[],int limite);
int cli_imprimirArray(Cliente array[],int limite);
int cli_buscarId(Cliente array[], int limite, int valorBuscado);
int cli_modificarArray(Cliente array[],int limite, int indice);
int cli_bajaArray(Cliente array[],int limite, int indice);
int cli_ordenarPorNombre(Cliente array[],int limite);

int cli_altaForzadaArray(Pantalla array[],int limite, int indice, int* id,
                         char nombre[],char direccion[],float precio ,int tipo);



#endif // CLIENTE_H_INCLUDED
