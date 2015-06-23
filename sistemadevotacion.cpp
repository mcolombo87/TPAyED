#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "funciones.h"
#include "Cola.h"
#include "Pila.h"
#include "Provincia.h"
#include "Mesa.h"
#include "Urna.h"
#include "Voto.h"
#include <math.h>
#include "CandidatosXProv.h"
#include "PartidosXProv.h"

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
    int pantallaEntradas = 0; //Contar ingresos a funcion
    int pantallaEntradasProv;
    //Para recorrer lista de prov.
    PtrNodoLista prov = primero(lstProvincias);
    PtrDato provDato;
    Lista provMesas;
    //Para manejas las listas internas de Provincia
    Lista lstCandxProv;
    Lista lstPartxProv;
    //Para recorrer lista de mesas
    PtrNodoLista mesa;
    PtrDato mesaDato;
    Cola mesasUrnas;
    //Para recorrer la Cola
    PtrDatoCola urna;
    //Para recorrer la Pila
    Pila votos;
    PtrDatoPila votoUnidad;
    //Puntero auxiliar
    PtrDato cursor;
    PtrDato cursor2;

    while (prov != fin())
    {
        pantallaEntradasProv =0;
       provDato = prov->ptrDato;
       provMesas = getMesasProv(*(Provincia*)provDato);
       lstCandxProv = getCandidatosProv(*(Provincia*)provDato);
       lstPartxProv = getPartidosProv(*(Provincia*)provDato);
       mesa = primero(provMesas);
       while (mesa != fin())
       {
           mesaDato = mesa ->ptrDato;
           mesasUrnas = getUrnasMesa(*(Mesas*)mesaDato);
           urna = desencolar(mesasUrnas);
           while (urna != finCola())
           {
               votos = getVotosUrna(*(Urna*)urna); //Hasta aca tengo la pila
               votoUnidad = pop(votos);
               while (votoUnidad != fin())
               {
                    cursor = localizarDato(lstCandxProv, votoUnidad);
                    if (cursor != fin()) //Por las dudas valido que haya un resultado aunque deberia siempre existir
                    {
                        setVotosCandidatosXProv(*(CandidatosXProv*)cursor, (getVotosCandidatosXProv(*(CandidatosXProv*)cursor))+1);
                    }else {puts("Error: El candidato votado no se encuentra registrado en la Provincia"); system("pause");}
                    cursor2 = localizarDato(lstPartxProv, cursor);
                    if (cursor2 != fin()) //Por las dudas valido que haya un resultado aunque deberia siempre existir
                    {
                        setVotosPartidosXProv(*(PartidosXProv*)cursor2, (getVotosPartidosXProv(*(PartidosXProv*)cursor2))+1);
                    }else {puts("Error: El partido al que pertenece el candidato votado no se encuentra registrado en la Provincia"); system("pause");}

                    pantallaFinalizandoVotac(provDato, mesaDato, urna, pantallaEntradas, pantallaEntradasProv); //LLamo a la pantalla de progreso
                    votoUnidad = pop(votos); //Saco un nuevo voto
               }
               urna = desencolar(mesasUrnas); //Saco una nueva urna
           }
           mesa = siguiente(provMesas, mesa); //Paso a un nuevo nodo de la lista (es decir a otra Mesa)
       }
       prov = siguiente(lstProvincias,prov);
    }
    puts ("\n\n**PROCESO TERMINADO**\n");
    system("PAUSE");
}

void pantallaFinalizandoVotac(PtrDato &provDato, PtrDato &mesaDato, PtrDatoCola &urna, int &pantallaEntradas, int &pantallaEntradasProv)
{
        pantallaEntradas = pantallaEntradas +1;
        pantallaEntradasProv = pantallaEntradasProv +1;
        char caracter = '+';
        double valor;
        system ("CLS");
        puts ("**Contabilizando Votos en PROCESO**\n");
        puts ("иииииииииииииииииииииииииииииииииии\n");

        printf("Provincia: %d\n", (getIdProvincia(*(Provincia*)provDato)));
        printf("Mesa: %d\n", (getIdMesa(*(Mesas*)mesaDato)));
        printf("Urna: %d\n", (getIdUrna(*(Urna*)urna)));
        printf("Votos Contados en la Provincia: %d\n", &pantallaEntradasProv);
        puts ("**********************************\n");
        printf("Votos TOTALES: %d\n\n", &pantallaEntradas);

        puts("Por favor aguarde...\n");
        valor = sin((double)pantallaEntradas);
        if (round(valor) == (1)){printf("%c", &caracter);}
        if (round(valor) == (2)){printf("%c%c", &caracter, &caracter);}
        if (round(valor) == (3)){printf("%c%c%c", &caracter, &caracter, &caracter);}
        if (round(valor) == (4)){printf("%c%c%c%c", &caracter, &caracter, &caracter, &caracter);}
        if (round(valor) == (5)){printf("%c%c%c%c%c", &caracter, &caracter, &caracter, &caracter, &caracter);}
        if (round(valor) == (6)){printf("%c%c%c%c%c%c", &caracter, &caracter, &caracter, &caracter, &caracter, &caracter);}
        if (round(valor) == (7)){printf("%c%c%c%c%c%c%c", &caracter, &caracter, &caracter, &caracter, &caracter, &caracter, &caracter);}
        if (round(valor) == (8)){printf("%c%c%c%c%c%c%c%c", &caracter, &caracter, &caracter, &caracter, &caracter, &caracter, &caracter, &caracter);}
        if (round(valor) == (9)){printf("%c%c%c%c%c%c%c%c%c", &caracter, &caracter, &caracter, &caracter, &caracter, &caracter, &caracter, &caracter, &caracter);}
        if (round(valor) == (10)){printf("%c%c%c%c%c%c%c%c%c%c", &caracter, &caracter, &caracter, &caracter, &caracter, &caracter, &caracter, &caracter, &caracter, &caracter);}


}

