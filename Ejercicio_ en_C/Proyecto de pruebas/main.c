#include <stdio.h>
#include <stdlib.h>
#include "funciones_pruebas.h"

int main()
{

  eProducto auxProducto;

  if((utn_getNombre(auxProducto.nombre, NOMBRE_LEN, "\nNombre?\n", "Nombre invalido", 2) == 0) &&
    (utn_getDescripcion(auxProducto.descripcion, DESCRIPCION_LEN, "\nDescripcion?\n", "Descripcion invalida", 2) == 0))
  {
      printf("%s - %s " ,auxProducto.nombre,auxProducto.descripcion);
  }

	system("pause");

    return 0;
}
