#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include "funciones.h"
#include "Lista.h"
#include "Cola.h"
#include "Pila.h"
#include "Provincia.h"
#include "Mesa.h"
#include "Urna.h"
#include "Voto.h"
#include <math.h>
#include <time.h>
#include "Partido.h"
#include "Candidato.h"
#include "CandidatosXProv.h"
#include "PartidosXProv.h"
#include "Test.h"
#include "Comparaciones.h"
#include <windows.h>


using namespace std;

void abreUrna(Lista&, int&);
void votacion(Lista&, Lista&,Lista&, int&, int&);
void cargandoMotor(Lista &prov, Lista &candidatos ,Lista &partidos, Lista &mesa);
void imprimirMegaEstructura(Lista &);
void cerrarUrna(Lista&);
void addMesa(Lista &, Lista &, int , int );
void cierraTodasUrnas(Lista &);

void sistemadevotacion(Lista &candidatos, Lista &partidos, Lista &mesa)
{

    Lista prov;
    crearLista(prov, compararProvincia);
    cargandoMotor(prov,candidatos ,partidos,mesa);
    /**Todas las Pruebas que quieran hacer por fuera del funcionamiento de la aplicacion**/
    /**deben hacerse usando los Test. Llaman a las funciones aca cuando quieren probar algo**/
//    probandoDistri(prov);
    /**Fin del Bloque de pruebas**/

    bool continuar = true;
    bool opcinvalida = false;
    int opcion;
    int idUrnaGlobal = 1;
    int idVotoGlobal = 1;
    bool votEnd = false;

    while(continuar == true)
    {
        system("cls"); //Menu principal
        cout << "**VOTACION en Progreso**" << endl;
        cout <<"*********************************************"<<endl;
        cout <<"\n"<<endl;
        cout << "1. Apertura de Mesas" << endl;
        cout << "2. Apertura de Urnas" << endl;
        cout << "3. Cerrar la Urna actual." << endl;
        cout << "4. Registro de Votos"<< endl;
        if (idVotoGlobal > 1){cout << "5. Finalizar votacion"<< endl;}else{cout << "5. Finalizar votacion(No disponible)"<< endl;}
        if (votEnd == true){cout << "6. Generar informes de la votacion"<< endl;}else{cout << "6. Generar informes de la votacion (No disponible)"<< endl;}
        cout << "\n" << endl;
        if (votEnd == true || idVotoGlobal == 1){cout << "0. Salir" << endl;}else{cout << "0. Salir (No disponible)" << endl;}

        if (opcinvalida == true)
        {
            printf("Valor Incorrecto, vuelva a ingresar una opcion valida...\n");
            opcinvalida=false;
        }


        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1: /*funcion de Apertura de Mesas*/
            addMesa(prov, mesa, 0, 0);
            break;
        case 2: /*funcion de Apertura de Urnas*/
            abreUrna(prov, idUrnaGlobal);
            break;
        case 3:
            cerrarUrna(prov);
            break;
        case 4:
            votacion(prov,partidos,mesa,idUrnaGlobal,idVotoGlobal);
            break;
        case 5:
            if (idVotoGlobal > 1){cierraTodasUrnas(prov);votEnd = distribuirVotos(prov);}else{cout << "\nNo se realizo ningun voto\n"<< endl; system("pause");}
             break;
        case 6:
            if (votEnd == true){reportes(prov);}else{cout << "\nLa votacion no finalizo o nunca comenzo\n"<< endl; system("pause");}
            break;
        case 100:
            imprimirMegaEstructura(prov);
            break;
        case 110:
            probandoDistri(prov);
            break;
        case 111:
            system("cls");
            for (int i = 0; i<=1000; i++)
            {
                Simvotacion(prov,partidos,mesa,idUrnaGlobal,idVotoGlobal);
            }
            break;
        case 0:
            if (votEnd == true){return;}else{cout << "\nNO PUEDE SALIR HASTA NO FINALIZAR LA VOTACION EN CURSO\n"<< endl; system("pause");}
            break;
        default:
            opcinvalida=true ;
            break;

        }


    }
    system("PAUSE");
    return;
}

bool distribuirVotos(Lista &lstProvincias)
{
    bool votEnd;

    int pantallaEntradas = 0; //Contar ingresos a funcion
    int pantallaEntradasProv, idPartidoVotado, contadorAux;
    //Para recorrer lista de prov.
    PtrNodoLista prov = primero(lstProvincias);
    PtrDato provDato;
    Lista provMesas;
    //Para manejas las listas internas de Provincia
    Lista lstCandxProv, lstPartxProv;

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
    PtrDato cursor, cursor2, cursorAuxBusq;
    PtrNodoLista cursorNodo;
    bool encontrado;

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

               while (votoUnidad != finPila())
               {
                    puts("3");
                    cursorNodo = primero(lstCandxProv); //RASTREO EL DATO PARA CANDIDATO
                    encontrado = false;
                    while (encontrado == false && cursorNodo != fin())
                    {
                        cursorAuxBusq = cursorNodo ->ptrDato;
                        if (getIdCandidatosXProv(*(CandidatosXProv*)cursorAuxBusq) != getIdCandidatoVoto(*(Voto*)votoUnidad))
                        {
                            cursorNodo = siguiente(lstCandxProv, cursorNodo);
                        }else{encontrado = true; cursor = cursorNodo ->ptrDato;}
                    }

                    if (cursorNodo != fin()) //Por las dudas valido que haya un resultado aunque deberia siempre existir
                    {
                        setVotosCandidatosXProv(*(CandidatosXProv*)cursor, (getVotosCandidatosXProv(*(CandidatosXProv*)cursor))+1);
                        idPartidoVotado = getPartidoCandidatosXProv(*(CandidatosXProv*)cursor);
                    }else {puts("\nError: El candidato votado no se encuentra registrado en la Provincia"); system("pause");}


                    cursorNodo = primero(lstPartxProv); //RASTREO EL DATO PARA PARTIDO
                    encontrado = false;
                    while (encontrado == false && cursorNodo != fin())
                    {
                        cursorAuxBusq = cursorNodo ->ptrDato;
                        if (getIdPartidosXProv(*(PartidosXProv*)cursorAuxBusq) != idPartidoVotado)
                        {
                            cursorNodo = siguiente(lstCandxProv, cursorNodo);
                        }else{encontrado = true; cursor2 = cursorNodo ->ptrDato;}
                    }
                    cursor = cursorNodo ->ptrDato;

                    if (cursorNodo != fin()) //Por las dudas valido que haya un resultado aunque deberia siempre existir
                    {

                        setVotosPartidosXProv(*(PartidosXProv*)cursor2, (getVotosPartidosXProv(*(PartidosXProv*)cursor2))+1);
                    }else {puts("\nError: El partido al que pertenece el candidato votado no se encuentra registrado en la Provincia"); system("pause");}

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
    votEnd = true;
    return votEnd;
}

void pantallaFinalizandoVotac(PtrDato &provDato, PtrDato &mesaDato, PtrDatoCola &urna, int &pantallaEntradas, int &pantallaEntradasProv)
{
        pantallaEntradas = pantallaEntradas +1;
        pantallaEntradasProv = pantallaEntradasProv +1;
        char caracter = '*';
        double valor;
        system ("CLS");
        puts ("**Contabilizando Votos en PROCESO**\n");
        puts ("иииииииииииииииииииииииииииииииииии\n");

        printf("Provincia: %d\n", (getIdProvincia(*(Provincia*)provDato)));
        printf("Mesa: %d\n", (getIdMesa(*(Mesas*)mesaDato)));
        printf("Urna: %d\n", (getIdUrna(*(Urna*)urna)));
        printf("Votos Contados en la Provincia: %d\n", pantallaEntradasProv);
        puts ("**********************************\n");
        printf("Votos TOTALES: %d\n\n", pantallaEntradas);

        puts("Por favor aguarde...\n");
        valor = 5*sin(pantallaEntradas)+6; //(double)
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
        Sleep(50);


}

char* hora()
{
      time_t t;
      struct tm *tm;
      char* fechayhora = new char;

      t=time(NULL);
      tm=localtime(&t);
      strftime(fechayhora, 100, "%H:%M", tm);
      return fechayhora;
      }

void votacion(Lista &provincias, Lista &partidos, Lista &lstMesas, int &id, int &idVoto){
          PtrDato provincia = new Provincia;
          PtrDato mesa = new Mesas;
          PtrDatoPila voto = new Voto;
          PtrDatoCola urna;// = new Urna;
          PtrNodoLista buscar;
          Lista mesas;
          Cola urnas;
          Pila votos;
          bool correcto;

          int idProvincia, idMesa, opcion = 0, idCandidato;
          cout << "Ingrese la provincia donde vota: ";
          correcto = scanf("%d",&idProvincia);
          while(!correcto){
            fflush(stdin);
            cout << "Debe ingresar un numero" << endl;
            correcto = scanf("%d",&idProvincia);
            fflush(stdin);
          }
          cout << "Ingrese la mesa donde vota: ";
          correcto = scanf("%d",&idMesa);
          while(!correcto){
            fflush(stdin);
            cout << "Debe ingresar un numero" << endl;
            correcto = scanf("%d",&idMesa);
            fflush(stdin);
          }

          setIdProvincia(*(Provincia*)provincia, idProvincia);
          setIdMesa(*(Mesas*)mesa, idMesa);
          setProvinciaMesa(*(Mesas*)mesa, idProvincia);

          buscar = localizarDato(provincias, provincia);

          if(buscar != fin()){
            cout << "Provincia encontrada" << endl;
            provincia = buscar->ptrDato;
            mesas = getMesasProv(*(Provincia*)provincia);
            buscar = localizarDato(mesas, mesa);
            if(buscar != fin()){
                cout << "Mesa encontrada" << endl;
                mesa = buscar->ptrDato;
                urnas = getUrnasMesa(*(Mesas*)mesa);
                if(estaVacia(urnas) || getHoraCierreUrna(*(Urna*)((punteroCola(*(Mesas*)mesa)->last)->ptrDato)) != NULL){
                    cout << "Debe abrir una urna primero." << endl;
                }else{
                    cout << "Listado de candidatos:" << endl;
                    imprimirPartidos(partidos);
                    cout << "Ingrese el ID del candidato a votar: ";
                    fflush(stdin);
                    correcto = scanf("%d",&idCandidato);
                    while(!correcto){
                        cout << "Debe ingresar un numero: " << endl;
                        fflush(stdin);
                        correcto = scanf("%d",&idCandidato);
                        fflush(stdin);
                    }
                    setIdVoto(*(Voto*)voto, idVoto++);
                    setIdCandidatoVoto(*(Voto*)voto,idCandidato);
                    urna = (punteroCola(*(Mesas*)mesa)->last)->ptrDato;
                    votos = getVotosUrna(*(Urna*)urna);
                    push(votos, voto);
                    setVotosUrna(*(Urna*)urna, votos);
                    setMesasProv(*(Provincia*)provincia, mesas);
                    cout << "El voto se agrego correctamente." << endl;
                    }
            }else{
                cout << "No existe esa mesa " << endl;
                cout << "Desea agregarla:  1-Si 2-No";
                cin >> opcion;
                if(opcion == 1){
                    addMesa(provincias, lstMesas, idProvincia, idMesa);

                }
                }
          }else cout << "No existe esa provincia " << endl;

         system("PAUSE");
     }

void cargandoMotor(Lista &prov, Lista &candidatos ,Lista &partidos, Lista &mesa)
{
    PtrNodoLista cursorLista;
    PtrNodoLista cursorLista2;
    Provincia provinciaEstruc;
    PtrDato lstMesas;
    PtrDato candProv;
    PtrDato partProv;
    PtrDato dato;
    PtrDato dato2;
    PtrDato dato3;
    PtrDato dato4;
    Lista lstAux;
    //PRueba
    PtrNodoLista cursorLista3;
    PtrDato dato5;

    cursorLista = primero(prov);

    //Primera pasada, seteo de Provincias
    for (int i=1; i<=24; i++)
    {
        dato = new Provincia;
        setIdProvincia(*(Provincia*)dato, i);
        lstMesas = new Lista;
        crearLista(*(Lista*)lstMesas, compararMesa);
        setMesasProv(*(Provincia*)dato, *(Lista*)lstMesas);
        candProv = new Lista;
        crearLista(*(Lista*)candProv, compararCandidatosXProv);
        setCandidatosProv(*(Provincia*)dato, *(Lista*)candProv);
        adicionarFinal(prov,dato);
        cursorLista = primero(candidatos);
        //cursorLista2 = primero(*(Lista*)candProv));
        while (cursorLista != fin()) //Seteo CANDXPROV
        {
            dato2 = cursorLista ->ptrDato;
            //dato3 = cursorLista2 ->ptrDato;
            dato4 = new CandidatosXProv;
            setIdCandidatosXProv(*(CandidatosXProv*)dato4, getIdCandidato(*(Candidato*)dato2));
            setNombreCandidatosXProv(*(CandidatosXProv*)dato4, getNombreCandidato(*(Candidato*)dato2));
            setPartidoCandidatosXProv(*(CandidatosXProv*)dato4, getPartidoPolitico(*(Candidato*)dato2));
            setVotosCandidatosXProv(*(CandidatosXProv*)dato4, 0);
            adicionarFinal(*(Lista*)candProv, dato4);

            setCandidatosProv(*(Provincia*)dato, *(Lista*)candProv);

            cursorLista=siguiente(candidatos,cursorLista);
        }

        partProv = new Lista;
        crearLista(*(Lista*)partProv, compararPartidoXProv);
        setPartidosProv(*(Provincia*)dato, *(Lista*)partProv);
        cursorLista = primero(partidos);
        //cursorLista2 = primero(*(Lista*)candProv));
        while (cursorLista != fin()) //Seteo PARTXPROV
        {
            dato2 = cursorLista ->ptrDato;
            //dato3 = cursorLista2 ->ptrDato;
            dato4 = new PartidosXProv;
            setIdPartidosXProv(*(PartidosXProv*)dato4, getIdPartido(*(Partido*)dato2));
            setNombrePartidosXProv(*(PartidosXProv*)dato4, getNombrePartido(*(Partido*)dato2));
            setVotosPartidosXProv(*(PartidosXProv*)dato4, 0);
            adicionarFinal(*(Lista*)partProv, dato4);
            cursorLista=siguiente(partidos,cursorLista);
            setPartidosProv(*(Provincia*)dato, *(Lista*)partProv); //Resetear?
        }
    }

    //Segunda pasada seteo mesas
    cursorLista = primero(mesa);
    int idAux;
    Cola urna;
    while (cursorLista != fin())
    {
        dato = cursorLista ->ptrDato;
        cursorLista2 = primero(prov);
        while (cursorLista2 != fin())
        {
            dato2 = cursorLista2 ->ptrDato;
            if ( (getIdProvincia(*(Provincia*)dato2)) == (getProvinciaMesa(*(Mesas*)dato)) )
            {
                dato3 = new Mesas;
                constructorMesa(*(Mesas*)dato3, getIdMesa(*(Mesas*)dato),getProvinciaMesa(*(Mesas*)dato), urna);

                lstAux = getMesasProv(*(Provincia*)dato2);
                adicionarFinal(lstAux, dato3);
                setMesasProv(*(Provincia*)dato2, lstAux);
            }
            cursorLista2 = siguiente(prov,cursorLista2);
        }
        cursorLista = siguiente(mesa,cursorLista);
    }

    //Tercera pasada re-armo la lista de partidos distribuyendo candidatos.

    int idPartAux;
    cursorLista = primero(partidos);
    while (cursorLista != fin())
    {
        dato = cursorLista ->ptrDato;
        idPartAux = getIdPartido(*(Partido*)dato);
        cursorLista2 = primero(candidatos);
        while(cursorLista2 != fin())
        {
            dato2 = cursorLista2 ->ptrDato;
            if (idPartAux == getPartidoPolitico(*(Candidato*)dato2))
            {
                lstAux = getLista(*(Partido*)dato);
                adicionarFinal(lstAux, dato2);
                setLista(*(Partido*)dato, lstAux);

            }
            cursorLista2 = siguiente(candidatos, cursorLista2);
        }
        cursorLista = siguiente(partidos, cursorLista);
    }


}

void reportes(Lista provincia){

    system("cls");
    puts("REPORTES");
     Lista partidosXprovincia;
     Lista candidatosXprovincia;
     Lista auxiliarPartidos;
     Lista auxiliarCandidatos;
     crearLista(auxiliarPartidos, compararPartidoXProv);
     crearLista(auxiliarCandidatos, compararCandidatosXProv);
     PtrDato partido;
     int votosPartido = 0, votosCandidato = 0;
     int totalVotos = 0;
     double porcentaje = 0;
     PtrNodoLista cursor, cursor2;
     bool primer = true;

     cursor = primero(provincia);

     partidosXprovincia = getPartidosProv(*(Provincia*)cursor->ptrDato);//Traigo la lista de PXP
     cursor2 = primero(partidosXprovincia); //Busco el primer partido almacenado en la lista

     for(int i = 0; i < longitud(partidosXprovincia); i++){ // For determinado por la cantidad de partidos que hay
          while(cursor != fin()){ // Recorro todas las provincias
             partidosXprovincia = getPartidosProv(*(Provincia*)cursor->ptrDato);//En cada provincia, geteo la lista PXP
             cursor2 = localizarDato(partidosXprovincia, cursor2->ptrDato);
             if(cursor2 != fin()){ //Busco el partido en la lista
                 if(primer){
                             partido = new PartidosXProv;// Para saber si es la primera vez que entra el partido
                             primer  = false;
                             setIdPartidosXProv(*(PartidosXProv*)partido, getIdPartidosXProv(*(PartidosXProv*)cursor2->ptrDato));
                             setNombrePartidosXProv(*(PartidosXProv*)partido, getNombrePartidosXProv(*(PartidosXProv*)cursor2->ptrDato));
                             }
                 votosPartido += getVotosPartidosXProv(*(PartidosXProv*)cursor2->ptrDato);// sumo todos los votos de ese partido
                        }
             cursor = siguiente(provincia, cursor); //Recorro la lista de provincias
                  }
             setVotosPartidosXProv(*(PartidosXProv*)partido, votosPartido); //Terminadas las provincias, seteo los votos
             adicionarFinal(auxiliarPartidos, partido); // agrego a la lista auxiliar
             cursor2 = siguiente(partidosXprovincia, cursor2); // Sigo con el proximo partido
             primer = true;
             cursor = primero(provincia);
             votosPartido = 0;
          }//Probando sin agregar ni un voto, la lista de partidos se carga correctamente.


     cursor = primero(provincia);
     candidatosXprovincia = getCandidatosProv(*(Provincia*)cursor->ptrDato);
     cursor2 = primero(candidatosXprovincia);
     primer = true;

     for(int i = 0; i < longitud(candidatosXprovincia); i++)
        {
        while(cursor != fin())
        {
           candidatosXprovincia = getCandidatosProv(*(Provincia*)cursor ->ptrDato);
           cursor2 = localizarDato(candidatosXprovincia, cursor2->ptrDato);
           if(cursor2 != fin())
           {
                if(primer){
                           partido = new CandidatosXProv;
                           primer  = false;
                           setPartidoCandidatosXProv(*(CandidatosXProv*)partido, getPartidoCandidatosXProv(*(CandidatosXProv*)cursor2->ptrDato));
                           setIdCandidatosXProv(*(CandidatosXProv*)partido, getIdCandidatosXProv(*(CandidatosXProv*)cursor2->ptrDato));
                           setNombreCandidatosXProv(*(CandidatosXProv*)partido, getNombreCandidatosXProv(*(CandidatosXProv*)cursor2->ptrDato));
                           }
                votosCandidato += getVotosCandidatosXProv(*(CandidatosXProv*)cursor2->ptrDato);
            }
            cursor = siguiente(provincia, cursor);
        }
           setVotosCandidatosXProv(*(CandidatosXProv*)partido, votosCandidato);
           adicionarFinal(auxiliarCandidatos, partido);
           cursor2 = siguiente(candidatosXprovincia, cursor2); // Sigo con el proximo partido
           primer = true;
           votosCandidato = 0;//Hasta aca, deberian estar cargadas las listas auxiliares con los resultados de la votacion
           cursor = primero(provincia);
        }


           cursor = primero(provincia);// Me pongo al inicio de la lista grosa
           while(cursor != fin()){
               partidosXprovincia = getPartidosProv(*(Provincia*)cursor->ptrDato); //Geteo la lista
               cursor2 = primero(partidosXprovincia);
               while(cursor2 != fin()){ //
                   totalVotos+= getVotosPartidosXProv(*(PartidosXProv*)cursor2->ptrDato);//Sumo los votos de todos los partidos para sacar el total
                   cursor2 = siguiente(partidosXprovincia, cursor2);
                             }
               cursor = siguiente(provincia, cursor);
                        }
            printf("TOTAL DE VOTOS: %d\n\n", totalVotos);

           cursor = primero(auxiliarCandidatos);
           porcentaje = totalVotos * 1.5 /100;
           puts("Candidatos que no llegaron al 1.5% de votos:");
           while(cursor != fin()){
                if(getVotosCandidatosXProv(*(CandidatosXProv*)cursor->ptrDato) <= porcentaje){
                     printf("%s - ", getNombreCandidatosXProv(*(CandidatosXProv*)cursor->ptrDato));}
                cursor = siguiente(auxiliarCandidatos, cursor);
                        }

            double porcTemp;
            int tempInt;
            auxiliarCandidatos.compara = votosCandidatosXProv;
            reordenar(auxiliarCandidatos);
            puts("\n***\t***\n\n\nVotos Generales (todas las provincias) por Candidato:\n");
                  cursor = primero(auxiliarCandidatos);
           while(cursor != fin()){
                printf("\n%s\n Votos: %d\n", getNombreCandidatosXProv(*(CandidatosXProv*)cursor->ptrDato), getVotosCandidatosXProv(*(CandidatosXProv*)cursor->ptrDato));
                tempInt = getVotosCandidatosXProv(*(CandidatosXProv*)cursor->ptrDato);
                porcTemp = tempInt *100/totalVotos;
                printf("%2.f%c del Total.\n******", porcTemp, 37 );
                cursor = siguiente(auxiliarCandidatos, cursor);
                        }

            puts("\n***\t***\n\n\nVotos Generales (todas las provincias) por Partido:\n");
            auxiliarPartidos.compara = votosPartidoXProv;
            reordenar(auxiliarPartidos);
          cursor = primero(auxiliarPartidos);
           while(cursor != fin()){
                printf("\n%s\n Votos: %d\n******", getNombrePartidosXProv(*(PartidosXProv*)cursor->ptrDato), getVotosPartidosXProv(*(PartidosXProv*)cursor->ptrDato));
                tempInt = getVotosPartidosXProv(*(PartidosXProv*)cursor->ptrDato);
                porcTemp = tempInt*100/totalVotos;
                printf("%2.f%c del Total.\n******", porcTemp, 37);
                cursor = siguiente(auxiliarPartidos, cursor);
                        }
          Lista can;
          cursor = primero(provincia);
          system("PAUSE");
          puts("\n***\t***\n\n\nResultados Generales por provincia y candidatos:\n");
           while(cursor != fin()){
            can = getCandidatosProv(*(Provincia*)cursor->ptrDato);
            can.compara = votosCandidatosXProv;
            reordenar(can);
            cursor2 = primero(can);
            if((getIdProvincia(*(Provincia*)cursor->ptrDato)) == 12)system("Pause");
            printf("ID provincia: %d\n", getIdProvincia(*(Provincia*)cursor->ptrDato));
            while(cursor2 != fin()){
                printf("\tNombre: %s  cantidad de votos: %d\n",getNombreCandidatosXProv(*(CandidatosXProv*)cursor2->ptrDato), getVotosCandidatosXProv(*(CandidatosXProv*)cursor2->ptrDato));
                cursor2 = siguiente(can, cursor2);
            }

            cursor = siguiente(provincia, cursor);
           }

           cursor = primero(provincia);
          system("PAUSE");
          puts("\n***\t***\n\n\nResultados Generales por provincia y partido:\n");
           while(cursor != fin()){
            can = getPartidosProv(*(Provincia*)cursor->ptrDato);
            can.compara = votosPartidoXProv;
            reordenar(can);
            cursor2 = primero(can);
            if((getIdProvincia(*(Provincia*)cursor->ptrDato)) == 12)system("Pause");
            printf("ID provincia: %d\n", getIdProvincia(*(Provincia*)cursor->ptrDato));
            while(cursor2 != fin()){
                printf("\tNombre: %s  cantidad de votos: %d\n",getNombrePartidosXProv(*(PartidosXProv*)cursor2->ptrDato), getVotosPartidosXProv(*(PartidosXProv*)cursor2->ptrDato));
                cursor2 = siguiente(can, cursor2);
            }

            cursor = siguiente(provincia, cursor);
           }

        puts("\n");
        system("Pause");

     }

void imprimirMegaEstructura(Lista &provincias){
     PtrNodoLista cursor, cursor2, cursor3;
     Lista mesas, candidatos;
     Cola urnas;
     PtrDatoCola urna;
     cursor3 = primero(provincias);
     int i = 1;

     while(cursor3 != fin()){
            printf("ID provincia: %d\n", getIdProvincia(*(Provincia*)cursor3->ptrDato));
            mesas = getMesasProv(*(Provincia*)cursor3->ptrDato);

            cursor = primero(mesas);
            while(cursor != fin()){
                  printf("\tID mesa: %d  ID provincia: %d \n",getIdMesa(*(Mesas*)cursor->ptrDato), getProvinciaMesa(*(Mesas*)cursor->ptrDato));
                  urnas = getUrnasMesa(*(Mesas*)cursor->ptrDato);
                  if(!estaVacia(urnas)){
                       urna = desencolar(urnas);
                       while(urna != finCola()){
                        printf("\t\tID: %d  Hora Apertura: %s Hora cierre: %s \n", getIdUrna(*(Urna*)urna),getHoraAperturaUrna(*(Urna*)urna),getHoraCierreUrna(*(Urna*)urna));
                        urna = desencolar(urnas);
                       }
                  }
                  cursor=siguiente(mesas,cursor);
                  }
             cursor3 = siguiente(provincias, cursor3);
          }


        system("pause");
     }

void abreUrna(Lista &provincias, int &id){
     PtrDato provincia = new Provincia;
     PtrDato mesa = new Mesas;
     PtrNodoLista buscar;
     PtrDatoCola urna;
     Lista mesas;
     Cola urnas;
     Pila votos;
     int idProvincia, idMesa, opcion;



     cout << "Ingrese la provincia donde abrira la urna: ";
     cin >> idProvincia;
     cout << "Ingrese la mesa donde abrira la urna: ";
     cin >> idMesa;

     setIdProvincia(*(Provincia*)provincia, idProvincia);
     setIdMesa(*(Mesas*)mesa, idMesa);
     setProvinciaMesa(*(Mesas*)mesa, idProvincia);

     buscar = localizarDato(provincias, provincia);

     if(buscar != fin()){
          cout << "Provincia encontrada" << endl;
          provincia = buscar->ptrDato;
          mesas = getMesasProv(*(Provincia*)provincia);
          buscar = localizarDato(mesas, mesa);

          if(buscar != fin()){
                cout << "Mesa encontrada" << endl;
                mesa = buscar->ptrDato;
                urnas = getUrnasMesa(*(Mesas*)mesa);
                if(!estaVacia(urnas) && getHoraCierreUrna(*(Urna*)((punteroCola(*(Mesas*)mesa)->last)->ptrDato)) == NULL){
                    cout << "Debe cerrar la urna antes de abrir otra." << endl;
                }else{
                    crearPila(votos);
                    urna = new Urna;
                    constructorUrna(*(Urna*)urna, id, hora(), NULL , votos);
                    printf("Id urna: %d\n", id);
                    id++;
                    encolar(urnas, urna);
                    setUrnasMesa(*(Mesas*)buscar->ptrDato, urnas);
                    setMesasProv(*(Provincia*)provincia, mesas);
                    cout << "Se agrego la urna correctamente." << endl;
                    }
          }else cout << "No se ha encontrado la mesa." << endl;
    }else cout << "No se ha encontrado la provincia." << endl;
    system("Pause");
}


void cerrarUrna(Lista &provincias){
    PtrDato provincia = new Provincia;
    PtrDato mesa = new Mesas;
    PtrDatoCola urna;
    PtrNodoLista buscar;
    PtrNodoCola ptrUrna;
    Cola urnas;
    Lista mesas;
    int idProvincia, idMesa;

     cout << "Ingrese la provincia donde cerrara la urna: ";
     cin >> idProvincia;
     cout << "Ingrese la mesa donde cerrara la urna: ";
     cin >> idMesa;

     setIdProvincia(*(Provincia*)provincia, idProvincia);
     setIdMesa(*(Mesas*)mesa, idMesa);

     buscar = localizarDato(provincias, provincia);
     if(buscar != fin()){
          cout << "Provincia encontrada" << endl;
          provincia = buscar->ptrDato;
          mesas = getMesasProv(*(Provincia*)provincia);
          buscar = localizarDato(mesas, mesa);
          if(buscar != fin()){
                cout << "Mesa encontrada" << endl;
                mesa = buscar->ptrDato;
                if(!estaVacia(urnas) && getHoraCierreUrna(*(Urna*)((punteroCola(*(Mesas*)mesa)->last)->ptrDato)) == NULL){
                    cout << "Se cerrara la urna actual." << endl;
                    ptrUrna = urnas.last;
                    urna = (punteroCola(*(Mesas*)mesa)->last)->ptrDato;
                    setHoraCierreUrna(*(Urna*)urna, hora());
                    printf("ID: %d  Hora Apertura: %s Hora cierre: %s se ha cerrado.\n", getIdUrna(*(Urna*)urna),getHoraAperturaUrna(*(Urna*)urna),getHoraCierreUrna(*(Urna*)urna));
                    }else cout << "No hay urna abierta, Debe abrir una primero." << endl;
          }else cout << "La mesa no existe" << endl;
     }else cout << "La provincia no existe." << endl;
    system("Pause");
}

void addMesa(Lista &provincias, Lista &mesas, int idProvincia, int idMesa){

     PtrDato mesa = new Mesas;
     PtrDato provincia = new Provincia;
     PtrNodoLista buscar,buscar2;
     Cola urna;
     Lista lstMesas;
     bool control = false;

     if(idProvincia == 0){
        cout << "Ingrese el id de la provincia: " << endl;
        scanf("%d", &idProvincia);
        cout << "Ingrese el id de la mesa: " << endl;
        scanf("%d", &idMesa);
        control = true;
     }

     constructorMesa(*(Mesas*)mesa, idMesa, idProvincia, urna);
     setIdProvincia(*(Provincia*)provincia, idProvincia);

     buscar = localizarDato(provincias, provincia);
     if(buscar != fin()){
            buscar2 = localizarDato(mesas, mesa);
            if(buscar2 == fin()){
                lstMesas = getMesasProv(*(Provincia*)buscar->ptrDato);
                adicionarFinal(lstMesas, mesa);
                adicionarFinal(mesas, mesa);
                setMesasProv(*(Provincia*)buscar->ptrDato, lstMesas);
                printf("Se ha agregado una mesa con el id %d.\n", idMesa);
                }else printf("Ya existe una mesa con ese id.\n");
      }else printf("No existe esa provincia.\n");
      if(control)system("Pause");
     }

/**SIMULACION DE VOTOS**/

void Simvotacion(Lista &provincias, Lista &partidos, Lista &lstMesas, int &id, int &idVoto){
          PtrDato provincia = new Provincia;
          PtrDato mesa = new Mesas;
          PtrDatoPila voto = new Voto;
          PtrDatoCola urna;// = new Urna;
          PtrNodoLista buscar;
          Lista mesas;
          Cola urnas;
          Pila votos;
          bool correcto;
          int modcontar, modcontar2;

          int idProvincia, idMesa, opcion = 0, idCandidato;
          idProvincia = Faleatorio(24);

          idMesa = idProvincia * 5;

              modcontar = idVoto % 5;
              modcontar2 = idVoto %50;  //El mod y los ifs a continuación son solo para generar una animación
              if (idVoto > 1)               //cuando los tiempos en encontrar un movimiento válido se hacen muy largos
                  {if (idVoto ==5)           //entonces cada multiplo de xxxx número se dibuja un caracter
                     {puts("SIMULANDO VOTOS, POR FAVOR ESPERE...");}
                  if(modcontar ==0)
                  {printf("%c", 16);}
                  if(modcontar2 == 0){system("cls");puts("SIMULANDO VOTOS, POR FAVOR ESPERE...");}
                  }
            Sleep(73);


          setIdProvincia(*(Provincia*)provincia, idProvincia);
          setIdMesa(*(Mesas*)mesa, idMesa);

          setProvinciaMesa(*(Mesas*)mesa, idProvincia);

          buscar = localizarDato(provincias, provincia);

          if(buscar != fin()){

            provincia = buscar->ptrDato;
            mesas = getMesasProv(*(Provincia*)provincia);
            buscar = localizarDato(mesas, mesa);
            if(buscar != fin()){
                mesa = buscar->ptrDato;
                urnas = getUrnasMesa(*(Mesas*)mesa);
                if(estaVacia(urnas) || getHoraCierreUrna(*(Urna*)((punteroCola(*(Mesas*)mesa)->last)->ptrDato)) != NULL){
                    SimabreUrna(provincias, id, idProvincia, idMesa);
                }else{

                    idCandidato = Faleatorio(15);

                    setIdVoto(*(Voto*)voto, idVoto++);
                    setIdCandidatoVoto(*(Voto*)voto,idCandidato);
                    urna = (punteroCola(*(Mesas*)mesa)->last)->ptrDato;
                    votos = getVotosUrna(*(Urna*)urna);
                    push(votos, voto);
                    setVotosUrna(*(Urna*)urna, votos);
                    setMesasProv(*(Provincia*)provincia, mesas);

                    }
                }
            }
          }



void SimabreUrna(Lista &provincias, int &id, int idProv, int idMesa){
     PtrDato provincia = new Provincia;
     PtrDato mesa = new Mesas;
     PtrNodoLista buscar;
     PtrDatoCola urna;
     Lista mesas;
     Cola urnas;
     Pila votos;
     int idProvincia = idProv, opcion;



     setIdProvincia(*(Provincia*)provincia, idProvincia);
     setIdMesa(*(Mesas*)mesa, idMesa);
     setProvinciaMesa(*(Mesas*)mesa, idProvincia);

     buscar = localizarDato(provincias, provincia);

     if(buscar != fin()){

          provincia = buscar->ptrDato;
          mesas = getMesasProv(*(Provincia*)provincia);
          buscar = localizarDato(mesas, mesa);

          if(buscar != fin()){

                mesa = buscar->ptrDato;
                urnas = getUrnasMesa(*(Mesas*)mesa);
                if(!estaVacia(urnas) && getHoraCierreUrna(*(Urna*)((punteroCola(*(Mesas*)mesa)->last)->ptrDato)) == NULL){

                }else{
                    crearPila(votos);
                    urna = new Urna;
                    constructorUrna(*(Urna*)urna, id, NULL, NULL , votos);
                    id++;
                    encolar(urnas, urna);
                    setUrnasMesa(*(Mesas*)buscar->ptrDato, urnas);
                    setMesasProv(*(Provincia*)provincia, mesas);

                    }
          }
    }
}

int Faleatorio (int valor_de_ref) // Devuelve el número aleatorio que determinará el movimiento
{
    int parcial;
    srand(time(0)); //Necesario para resetear el rand y que no me devuelva el mismo número

    valor_de_ref = valor_de_ref + 1;  //El rango de numeros entre los que va a tirar el aleatorio esta
    parcial = rand()%valor_de_ref;    //definido por una variable, ya que contemple el posible y/o futuro uso de la misma función
                                      //para otros usos.
    return(parcial);
}

void cierraTodasUrnas(Lista &provincias){
     PtrNodoLista cursor, cursor3;
     Lista mesas;
     Cola urnas;
     PtrDatoCola urna;
     PtrNodoCola ptrUrna;
     cursor3 = primero(provincias);
     int contador = 0;

     while(cursor3 != fin()){
            mesas = getMesasProv(*(Provincia*)cursor3->ptrDato);
            cursor = primero(mesas);
            while(cursor != fin()){
                  urnas = getUrnasMesa(*(Mesas*)cursor->ptrDato);
                  if(!estaVacia(urnas) && getHoraCierreUrna(*(Urna*)((punteroCola(*(Mesas*)cursor->ptrDato)->last)->ptrDato)) == NULL){
                    ptrUrna = urnas.last;
                    urna = (punteroCola(*(Mesas*)cursor->ptrDato)->last)->ptrDato;
                    setHoraCierreUrna(*(Urna*)urna, hora());
                    contador++;
                    }
                  cursor=siguiente(mesas,cursor);
                  }
             cursor3 = siguiente(provincias, cursor3);
          }
    cout << "Cantidad de urnas cerradas: ";
    cout << contador << endl;
    system("Pause");

}
