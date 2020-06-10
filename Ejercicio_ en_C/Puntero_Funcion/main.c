#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int legajo;
    char division;
    float nota;
}eAlumno;
eAlumno* crearAlumno(void);
eAlumno* crearAlumnoConParametros(int,char,float);
int mostrarAlumno(eAlumno*);

int main()
{
    eAlumno* pAlumno;
    pAlumno = crearAlumnoConParametros(100,'B',9);

    mostrarAlumno(pAlumno);


    return 0;
}


eAlumno* crearAlumno(void)//constructor por defecto
{
    eAlumno* pAlumno;
    pAlumno = (eAlumno*) calloc(sizeof(eAlumno),1);
    /*pAlumno = (eAlumno*) malloc(sizeof(eAlumno));
    if(pAlumno!=NULL)
    {
        pAlumno->legajo = 0;
        pAlumno->division = '';
        pAlumno->nota = 0;

    }*/
    return pAlumno;
}


eAlumno* crearAlumnoConParametros(int legajo,char division, float nota)//Constructor parametrizado
{
    eAlumno* pAlumno;
    pAlumno = crearAlumno();
    if(pAlumno!=NULL)
    {
        pAlumno->legajo = legajo;
        pAlumno->division = division;
        pAlumno->nota = nota;
    }

    return pAlumno;
}

int mostrarAlumno(eAlumno* pAlumno)
{
    int retorno=0;
    if(pAlumno!=NULL)
    {
         printf("%d -- %c -- %f\n", pAlumno->legajo, pAlumno->division, pAlumno->nota);
        retorno = 1;
    }
    return retorno;
}




