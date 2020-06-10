#include <stdio.h>
#include <stdlib.h>

int main()
{


    int info_sortDueniosPorCantidadMascotas(Cliente cli_array[], int cli_limite, Mascota pet_array[], int pet_limite)
    {
        int retorno = -1;
        int i;
        int j;
        AuxCantidadMascota cantidadMascota[cli_limite];

        if(cli_array != NULL && cli_limite > 0 && pet_array != NULL && pet_limite > 0)
        {
            InicializarStrucAuxiliar(cli_array,cli_limite,cantidadMascota);

            info_cantidadMascotasPorCliente(cantidadMascota,pet_limite,pet_array,cli_limite);

            retorno = 0;
            for(i=0;i<(cli_limite-1);i++)
            {
                for(j=i+1;j<cli_limite;j++)
                {
                   if(cantidadMascota[i].contador > cantidadMascota[j].contador && cantidadMascota[i].idCliente == cli_array[i].idCliente && cantidadMascota[j].idCliente == cli_array[j].idCliente)
                    {
                        cli_swapArray(cli_array, i, j);
                    }
                }
            }
        }
        return retorno;
    }

    int InicializarStrucAuxiliar(Cliente cli_array[], int cli_limite, AuxCantidadMascota aux_array[])
    {
        int retorno = -1;
        int i;
        if(cli_array != NULL && cli_limite > 0 && aux_array != NULL)
        {
            for(i=0;i<cli_limite;i++)
            {
                aux_array[i].idCliente = cli_array[i].idCliente;
                aux_array[i].contador = 0;
                aux_array[i].isEmpty = OCUPADO;
            }
            retorno = 0;
        }
        return retorno;
    }

    int info_cantidadMascotasPorCliente(AuxCantidadMascota aux_array[],int pet_limite,Mascota pet_array[], int cli_limite)
    {
        int retorno = -1;
        int i;
        int j;
        if(pet_array != NULL && cli_limite > 0 && aux_array != NULL && pet_limite > 0)
        {
            for(i=0;i<cli_limite;i++)
            {
                if(aux_array[i].isEmpty == OCUPADO)
                {
                    for(j=0;j<pet_limite;j++)
                    {
                        if(pet_array[j].isEmpty == OCUPADO && pet_array[j].idCliente == aux_array[i].idCliente)
                        {
                            aux_array[i].contador++;
                        }
                    }
                }
            }
            retorno = 0;
        }
        return retorno;
    }

    void MostrarProveedorConMasProductos(eProveedor listaProveedor[],int sizeProveedor, eProducto listaProducto[], int sizeProductos)
    {
        eAuxiliar listaProveedorConMasProductos[sizeProveedor];
        int i;
        int j;
        int proveedorConMasProductos; //Maximo

       // listaProducto[0].isEmpty = LIBRE; //Dar de baja manualmente

        InicializarStrucAuxiliar(listaProveedor,sizeProveedor,listaProveedorConMasProductos); //OK
        CantidadDeProductosPorProveedor(listaProveedorConMasProductos,sizeProveedor,listaProducto,sizeProductos); //OK
        proveedorConMasProductos = EncontrarProveedorConMasProductos(listaProveedorConMasProductos,sizeProveedor); //OK

        printf("\n\nProveedor con mas productos:");
        for(i=0; i<sizeProveedor; i++)
        {
            for(j=0; j<sizeProveedor; j++)
            {
                if(listaProveedor[j].idProveedor == listaProveedorConMasProductos[i].idProveedor && listaProveedorConMasProductos[i].cantidadDeProductos == proveedorConMasProductos)
                {
                    printf("\n %s %d Productos \n", listaProveedor[j].nombre,
                                                    listaProveedorConMasProductos[i].cantidadDeProductos);
                }
            }
        }
    }
    void InicializarStrucAuxiliar(eProveedor listaProveedor[], int sizeProveedor, eAuxiliar listaProveedorConMasProductos[])
    {
        int i;
        for(i=0; i<sizeProveedor; i++)
        {
            listaProveedorConMasProductos[i].idProveedor = listaProveedor[i].idProveedor;
            listaProveedorConMasProductos[i].cantidadDeProductos = 0;
        }
    }

    void CantidadDeProductosPorProveedor(eAuxiliar listaProveedorConMasProductos[],int sizeProveedor,eProducto listaProducto[], int sizeProductos)
    {
        int i;
        int j;

        for(i=0; i<sizeProveedor; i++)
        {
            for(j=0; j<sizeProductos; j++)
            {
                if(listaProducto[j].isEmpty == OCUPADO && listaProducto[j].idProveedor == listaProveedorConMasProductos[i].idProveedor)//Alumno que no este dado de baja
                {
                    listaProveedorConMasProductos[i].cantidadDeProductos++; //Cuento la cantidad de productos por proveedor
                }
            }
        }
    }

    int EncontrarProveedorConMasProductos(eAuxiliar listaProveedorConMasProductos[],int sizeProveedor)
    {
        int i;
        int maximo;
        for(i=0; i<sizeProveedor; i++)
        {
            if(i==0 || listaProveedorConMasProductos[i].cantidadDeProductos > maximo)
            {
                maximo = listaProveedorConMasProductos[i].cantidadDeProductos; //Encuentro el proveedor con mas productos
            }
        }
        return maximo;
    }

}
