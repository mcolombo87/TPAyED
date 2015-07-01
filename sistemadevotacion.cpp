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


using namespace std;

void abreUrna(Lista&, int&);
void votacion(Lista&, Lista&, int&, int&);
void cargandoMotor(Lista &prov, Lista &candidatos ,Lista &partidos, Lista &mesa);
void imprimirMegaEstructura(Lista &);
void cerrarUrna(Lista&);

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
        cout << "5. Finalizar votacion"<< endl;
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
            agregarMesa(prov);
            break;
        case 2: /*funcion de Apertura de Urnas*/
            abreUrna(prov, idUrnaGlobal);
            break;
        case 3: /*Registrar voto*/
            cerrarUrna(prov);
            break;
        case 4: /*Finaliza la votacion*/
            votacion(prov,partidos,idUrnaGlobal,idVotoGlobal);

            break;
        case 5:
            distribuirVotos(prov);
             break;
        case 6:
            reportes(prov);
            break;
        case 7:
            imprimirMegaEstructura(prov);
            break;
        case 8:
            probandoDistri(prov);
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
//       puts("0");
       while (mesa != fin())
       {
           mesaDato = mesa ->ptrDato;
           mesasUrnas = getUrnasMesa(*(Mesas*)mesaDato);
           urna = desencolar(mesasUrnas);
//           puts("1");
//           int a = getIdUrna(*(Urna*)urna);
//           printf("ID urna: %d\n", a );
//           system("PAUSE");
           while (urna != finCola())
           {
               votos = getVotosUrna(*(Urna*)urna); //Hasta aca tengo la pila
               votoUnidad = pop(votos);
//               puts("2");
//                printf("ID Voto: %d\n", getIdVoto(*(Voto*)votoUnidad));
//               system("PAUSE");
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
//                    puts("4");//
//                    //
//                    system("PAUSE");
//                    int a = getIdCandidatosXProv(*(CandidatosXProv*)cursor);
//                    char b[20];
//                    strcpy(b, getNombreCandidatosXProv(*(CandidatosXProv*)cursor));
//                    printf("\nDato Encontrado id: %d\nNombre: %s\n", a ,b );
//                    system("pause");
                    //
                    if (cursorNodo != fin()) //Por las dudas valido que haya un resultado aunque deberia siempre existir
                    {
                        setVotosCandidatosXProv(*(CandidatosXProv*)cursor, (getVotosCandidatosXProv(*(CandidatosXProv*)cursor))+1);
                        idPartidoVotado = getPartidoCandidatosXProv(*(CandidatosXProv*)cursor);
                    }else {puts("\nError: El candidato votado no se encuentra registrado en la Provincia"); system("pause");}

                    //HASTA ACA TODO BIEN
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
//                        puts("Entramos?");
                        //ontadorAux =
                        setVotosPartidosXProv(*(PartidosXProv*)cursor2, (getVotosPartidosXProv(*(PartidosXProv*)cursor2))+1);
                    }else {puts("\nError: El partido al que pertenece el candidato votado no se encuentra registrado en la Provincia"); system("pause");}
                    //VER LUEGO
//                     setVotosCandidatosXProv(*(CandidatosXProv*)cursor, (getVotosCandidatosXProv(*(CandidatosXProv*)cursor))+1);
//                     setVotosPartidosXProv(*(PartidosXProv*)cursor2, (getVotosPartidosXProv(*(PartidosXProv*)cursor2))+1);
                    //FIN DE VER LUEGO
//                    system("PAUSE");
//                    puts("Salimos?");
                    pantallaFinalizandoVotac(provDato, mesaDato, urna, pantallaEntradas, pantallaEntradasProv); //LLamo a la pantalla de progreso
                    votoUnidad = pop(votos); //Saco un nuevo voto
               }
//               puts ("5");
//               system("PAUSE");
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
        printf("Votos Contados en la Provincia: %d\n", pantallaEntradasProv);
        puts ("**********************************\n");
        printf("Votos TOTALES: %d\n\n", pantallaEntradas);

        puts("Por favor aguarde...\n");
        valor = 5*sin(5.49+pantallaEntradas)+6; //(double)
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

void votacion(Lista &provincias, Lista &partidos, int &id, int &idVoto){
          PtrDato provincia = new Provincia;
          PtrDato mesa = new Mesas;
          PtrDatoPila voto = new Voto;
          PtrDatoCola urna;// = new Urna;
          PtrNodoLista buscar;
          Lista mesas;
          Cola urnas;
          Pila votos;

          int idProvincia, idMesa, opcion = 0, idCandidato;
          cout << "Ingrese la provincia donde vota: ";
          cin >> idProvincia;
          cout << "Ingrese la mesa donde vota: ";
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
                if(estaVacia(urnas) || getHoraCierreUrna(*(Urna*)((punteroCola(*(Mesas*)mesa)->last)->ptrDato)) != NULL){
                    cout << "Debe abrir una urna primero." << endl;
                }else{
                    cout << "Listado de candidatos:" << endl;
                    imprimirPartidos(partidos);
                    cout << "Ingrese el ID del candidato a votar: ";
                    scanf("%d",&idCandidato);
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
                if(opcion == 1)agregarMesa(provincias);
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
//            /**PRUEBA BORRAR LUEGO*/
//            cursorLista3 = ultimo(*(Lista*)candProv);
//            dato5 = cursorLista3->ptrDato;
//            printf("\nNOMBRE Candidato: %s\n", getNombreCandidatosXProv(*(CandidatosXProv*)dato5));

            setCandidatosProv(*(Provincia*)dato, *(Lista*)candProv);
            //system("pause");
            //FIN PRUEBA, BORRAR LUEGO
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
//                setIdMesa(*(Mesas*)dato3, getIdMesa(*(Mesas*)dato));
//                setProvinciaMesa(*(Mesas*)dato3, getProvinciaMesa(*(Mesas*)dato));
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

    puts("REPORTES");
    system("pause");

     Lista partidosXprovincia;
     Lista candidatosXprovincia;
     Lista auxiliarPartidos;
     Lista auxiliarCandidatos;
     crearLista(auxiliarPartidos, NULL);
     crearLista(auxiliarCandidatos, NULL);
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

            puts ("Partidos OK");
            system("pause");


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
        }

            puts ("Candidatos OK");
            system("pause");

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
            printf("TOTAL DE VOTOS: %d", totalVotos);
            puts ("Conteo TOTAL ok");
            system("pause");

           cursor = primero(auxiliarCandidatos);
           porcentaje = totalVotos * 1.5 /100;
           while(cursor != fin()){
                if(getVotosCandidatosXProv(*(CandidatosXProv*)cursor->ptrDato) > porcentaje){
                     printf("%s entra.\n", getNombreCandidatosXProv(*(CandidatosXProv*)cursor->ptrDato));
                        }else {printf("%s no entra.\n", getNombreCandidatosXProv(*(CandidatosXProv*)cursor->ptrDato));}
                cursor = siguiente(auxiliarCandidatos, cursor);
                        }
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
