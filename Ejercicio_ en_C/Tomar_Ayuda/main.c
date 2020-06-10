/**
 *
 * Krug Enzo 1°F
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Informe.h"
#include "utn.h"

int main(void) {

	Cliente arrayClientes[CANTIDAD_CLIENTES];
	int idClientes=0;
	int opcion;
	int auxiliarIndice;
	int auxiliarId;

	if(cli_inicializarArray(arrayClientes,CANTIDAD_CLIENTES) == 0)
	{
		printf("Array inicializado correctamente. \n\n");
	}



	pan_altaForzadaArray(arrayPantallas,CANTIDAD_PANTALLAS,0,&idPantallas,"Pantalla 1","Zapiola 879", 12000.22,0);
	pan_altaForzadaArray(arrayPantallas,CANTIDAD_PANTALLAS,1,&idPantallas,"Pantalla 2","9 de julio 222", 22000.22,1);
	pan_altaForzadaArray(arrayPantallas,CANTIDAD_PANTALLAS,2,&idPantallas,"Pantalla 3","Mitre 750", 42000.22,0);

	cont_altaForzadaArray(arrayContrataciones,CANTIDAD_CONTRATACIONES,0,&idContrataciones,1,"Archivo1.mov","1234",2);
	cont_altaForzadaArray(arrayContrataciones,CANTIDAD_CONTRATACIONES,1,&idContrataciones,1,"Archivo2.mov","1234",10);
	cont_altaForzadaArray(arrayContrataciones,CANTIDAD_CONTRATACIONES,2,&idContrataciones,1,"Archivo3.mov","1234",20);
	cont_altaForzadaArray(arrayContrataciones,CANTIDAD_CONTRATACIONES,3,&idContrataciones,0,"Archivo4.mov","2222",2);
	cont_altaForzadaArray(arrayContrataciones,CANTIDAD_CONTRATACIONES,4,&idContrataciones,0,"Archivo5.mov","2222",10);
	cont_altaForzadaArray(arrayContrataciones,CANTIDAD_CONTRATACIONES,5,&idContrataciones,2,"Archivo6.mov","2222",20);
	do
	{
		if(!utn_getNumero(	&opcion,
							"\n\n1.Cargar un Cliente"
							"\n2.Modificar un Clientes"
							"\n3.Eliminar un Cliente"
							"\n4.Ordenar lista de Clientes por nombre"
							"\n5.Imprimir lista Clientes"
							"\n4.Ordenar lista de Clientes por nombre y altura"
							"\n7.Salir\n\n",
							"\nError opcion invalida",1,7,2) )
		{
			switch(opcion)
			{
			case 1:
				auxiliarIndice = cli_getEmptyIndex(arrayClientes,CANTIDAD_CLIENTES);
				if(auxiliarIndice >= 0)
				{
					if(cli_altaArray(arrayClientes,CANTIDAD_CLIENTES,auxiliarIndice,&idClientes) == 0)
					{
						printf("\nCarga realizada con exito\n");
					}
				}
				else
				{
					printf("\nNO HAY MAS LUGAR");
				}
				break;
			case 2:
				cli_imprimirArray(arrayClientes,CANTIDAD_CLIENTES);
				if(utn_getNumero(&auxiliarId,"\nIndique el ID del cliente a modificar","\nID invalido",0,idClientes,0) == 0)
				{
					auxiliarIndice = cli_buscarId(arrayClientes,CANTIDAD_CLIENTES,auxiliarId);
					if(	auxiliarIndice >= 0 &&
						cli_modificarArray(arrayClientes,CANTIDAD_CLIENTES,auxiliarIndice) == 0)
					{
						printf("\nModificacion realizada con exito\n");
					}
				}
				break;

			case 3:
				cli_imprimirArray(arrayClientes,CANTIDAD_CLIENTES);
				if(utn_getNumero(&auxiliarId,"\nIndique el ID del cliente a eliminar","\nID invalido",0,idClientes,0)==0)
				{
					auxiliarIndice = cli_buscarId(arrayClientes,CANTIDAD_CLIENTES,auxiliarId);
					if(	auxiliarIndice >= 0 &&
						cli_bajaArray(arrayClientes,CANTIDAD_CLIENTES,auxiliarIndice)== 0)
					{
						printf("\nBaja realizada con exito\n");
					}
				}
				break;
			case 4:
				cli_ordenarPorNombre(arrayClientes,CANTIDAD_CLIENTES);
				break;

			case 5:
				cli_imprimirArray(arrayClientes,CANTIDAD_CLIENTES);
				break;

			case 6:
				cli_ordenarPorNombre(arrayClientes,CANTIDAD_CLIENTES);
				break;

			}
		}
	}while(opcion != 7);

	return EXIT_SUCCESS;
}
