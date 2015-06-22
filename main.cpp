/** Algoritmo y Estructura de Datos.
 *
 *  Trabajo Practico "Elecciones".
 *
 */

/**
    NOTAS: ...
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "funciones.h"
#include "Lista.h"
#include "Comparaciones.h"
//#include "Test.h"

using namespace std;

int main()
{
    /**Todas las Pruebas que quieran hacer por fuera del funcionamiento de la aplicacion**/
    /**deben hacerse usando los Test. Llaman a las funciones aca cuando quieren probar algo**/
//    PruebaDeCola();
//    PruebadePila();
//    PruebadeLista();
//    PruebaEstructuras();
//    pruebaCandidatosListas();
//    PruebaDeCola();
    /**Fin del Bloque de pruebas**/

    bool continuar = true;
    bool opcinvalida = false;
    int opcion;
    
    Lista provincias;
    Lista partidos;
    crearLista(provincias, compararProvincia);
    crearLista(partidos, compararPartido);


    while(continuar == true)
    {
        system("cls"); //Menu principal
        cout << "TP Algoritmos y Estructura de Datos" << endl;
        cout << "'Elecciones'" << endl;
        cout <<"*********************************************"<<endl;
        cout <<"\n"<<endl;
        cout << "1. Editar informacion almacenada" << endl;
        cout << "2. Comenzar votacion" << endl;
        cout << "3. Generar informes de la votacion"<< endl;
        cout << "\n" << endl;
        cout << "0. Salir" << endl;

        if (opcinvalida == true)
        {
            printf("Valor Incorrecto, vuelva a ingresar una opcion valida...\n");
            opcinvalida=false;
        }


        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1: /*funcion edicion de datos*/
            edicionDeDatos(provincias, partidos);
            nuevatarea(continuar);
            break;
        case 2: /*nos lleva al sub menu de votacion e inicia el motor de votacion*/
            sistemadevotacion();
            nuevatarea(continuar);
            break;
        case 3: /*Genera Informes de Votacion*/
            //ACA Va la llamada al MODULO DE EDICION
            nuevatarea(continuar);
            break;
        case 0:
            return 0;
            break;
        default:
            opcinvalida=true ;
            break;

        }


    }
    eliminarLista(provincias);
    eliminarLista(partidos);
    system("PAUSE");
    return EXIT_SUCCESS;
}
