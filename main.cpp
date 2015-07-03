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
#include "Test.h"

using namespace std;

int main()
{

    //Creo las listas temporales y cargo archivos
    Lista lstCan;
    crearLista(lstCan, compararCandidatos);
    Lista lstPar;
    crearLista(lstPar, compararPartido);
    Lista lstMes;
    crearLista(lstMes, compararMesa);

    //El orden de carga NO es arbitrario, no puede ser de otra manera o falla la validacion de referencias
    cargarArcPartidos(lstPar);
    cargarArcCandidatos(lstCan, lstPar);
    cargarArcMesas(lstMes);

    /**Todas las Pruebas que quieran hacer por fuera del funcionamiento de la aplicacion**/
    /**deben hacerse usando los Test. Llaman a las funciones aca cuando quieren probar algo**/
//    PruebaDeCola();
//    PruebadePila();
//    PruebadeLista();
//    PruebaEstructuras();
//    pruebaCandidatosListas();
//    PruebaDeCola();
//    imprimirPartidos(lstPar);probandoDistri
//    cargaListaProvincias(provincias);
    /**Fin del Bloque de pruebas**/

    bool continuar = true;
    bool opcinvalida = false;
    int opcion;
    bool correcto;
    bool vota = true;



    while(continuar == true)
    {
        system("cls"); //Menu principal
        cout << "TP Algoritmos y Estructura de Datos" << endl;
        cout << "'Elecciones'" << endl;
        cout <<"*********************************************"<<endl;
        cout <<"\n"<<endl;
        if (vota){cout << "1. Editar informacion almacenada" << endl;}else{cout << "1. Editar informacion almacenada(No disponible)"<< endl;}
        if (vota){cout << "2. Comenzar votacion" << endl;}else{cout << "2. Comenzar votacion(No disponible)"<< endl;}
        cout << "\n" << endl;
        cout << "0. Salir" << endl;

        if (opcinvalida == true)
        {
            printf("Valor Incorrecto, vuelva a ingresar una opcion valida...\n");
            opcinvalida=false;
        }


        correcto = scanf("%d", &opcion);
               while(!correcto){
                                fflush(stdin);
                       cout << "Debe ingresar un numero entero, intente de nuevo: " << endl;
                       correcto = scanf("%d",&opcion);
                       fflush(stdin);
                                }

        switch(opcion)
        {
        case 1: /*funcion edicion de datos*/
            if(vota){edicionDeDatos(lstCan, lstPar, lstMes); puts ("\nFuncion ya no disponible\n");system("PAUSE");}
            nuevatarea(continuar);
            break;
        case 2: /*nos lleva al sub menu de votacion e inicia el motor de votacion*/
            if(vota){sistemadevotacion(lstCan, lstPar, lstMes); puts ("\nFuncion ya no disponible\n");system("PAUSE");}
            vota = false;
            nuevatarea(continuar);
            break;
        case 0:
            //Tareas antes de finalizar programa
            //eliminarLista(provincias);
//            eliminarLista(partidos);
            system("cls");
            puts("\t**Guardado de datos en Archivos, espere...**");
            guardarEnArchivos(lstCan, lstPar,lstMes);
            return 0;
            break;
        default:
            opcinvalida=true ;
            break;
        }


    }

    system("PAUSE");
    return EXIT_SUCCESS;
}



