#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "funciones.h"

using namespace std;

void sistemadevotacion()
{

    bool continuar = true;
    bool opcinvalida = false;
    int opcion;

    while(continuar == true)
    {
        system("cls"); //Menu principal
        cout << "**VOTACION en Progreso**" << endl;
        cout <<"*********************************************"<<endl;
        cout <<"\n"<<endl;
        cout << "1. Apertura de Mesas" << endl;
        cout << "2. Apertura de Urnas" << endl;
        cout << "3. Registro de Votos"<< endl;
        cout << "4. Finalizar votacion"<< endl;
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
        case 1: /*funcion de Apertura de Mesas*/
            //ACA Va la llamada al modulo de apertura de mesas
            break;
        case 2: /*funcion de Apertura de Urnas*/
            //ACA Va la llamada al modulo de apertura de urnas
            break;
        case 3: /*Registrar voto*/
            //ACA Va la llamada al modulo de registrar votos
            break;
        case 4: /*Finaliza la votacion*/
            //ACA Va la llamada al modulo que finaliza la votacion
            break;
        case 0:
            return;
            break;
        default:
            opcinvalida=true ;
            break;

        }


    }
    system("PAUSE");
    return;
}

void distribuirVotos(Lista &lstProvincias)
{
    //Para recorrer lista de prov.
    PtrNodoLista prov = primero(lstProvincias);
    PtrDato provDato;
    Lista provMesas;
    //Para recorrer lista de mesas
    PtrNodoLista mesa;
    PtrDato mesaDato;
    Cola mesasUrnas;
    //Para recorrer la Cola
    PtrDatoCola urna;
    //Para recorrer la Pila
    Pila votos;
    PtrDatoPila votoUnidad;

    while (prov != fin())
    {
       provDato = prov->ptrDato;
       provMesas = getMesasProv(*(Provincia*)provDato);
       mesa = primero(provMesas);
       while (mesa != fin())
       {
           mesaDato = mesa ->ptrDato;
           mesasUrnas = getUrnasMesas(*(Mesas*)mesaDato);
           urna = desencolar(mesasUrnas);
           while (urna != finCola())
           {
               votos = getVotosUrna(*(Urna*)urna); //Hasta aca tengo la pila
               votoUnidad = pop(votos);
               while (votoUnidad != fin())
               {
                   //Hasta aca tengo el voto atomico (continuara)
               }
           }

       }

    }
    /**Ya accedi al minimo, tengo que distribuir y asegurarme de pasar al otro nodo de la lista*/
}
