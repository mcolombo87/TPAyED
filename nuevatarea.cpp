
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "funciones.h"

//Procedimiento invocado para la recursividad
void nuevatarea(bool &contin )
{
    int respuesta;
    int fail=1;

    while(fail==1)
    {
        printf("Desea realizar otra tarea? 1:Si, 2:NO\n");
        printf("**NO finalizará la ejecución**\n");
        scanf("%d", &respuesta);
        switch(respuesta)
        {
        case 1:
            contin = true;
            fail=0;
            break;
        case 2:
            contin = false;
            fail=0;
            break;
        default:
            system("cls");
            printf("Respuesta incorrecta, vuelva a ingresarlo\n");
            fail=1;
            break;
        }
    }

}
