#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string.h>
#include "funciones.h"
#include "Lista.h"
#include "Cola.h"
#include "Provincia.h"
#include "Mesa.h"
#include "Voto.h"
#include "Urna.h"
#include "Candidato.h"
#include "Partido.h"
#include "Comparaciones.h"

using namespace std;

//-------------------------------ABM FUNCIONES-------------------------------------------------//

//---------------------------------ABM MESA----------------------------------------------------//
void agregarMesa(Lista &provincias){
      printf("---------------Agregar una mesa-----------------\n");
     PtrDato provincia = new Provincia;
     PtrDato mesa = new Mesas;
     PtrNodoLista buscar;
     Lista mesas;
     Cola urna;
     int idMesa, idProvincia;
     
     printf("Ingrese la provincia: ");
     scanf("%d", &idProvincia);
     printf("Ingrese el id de la mesa: ");
     scanf("%d", &idMesa);
     
     setIdProvincia(*(Provincia*)provincia,idProvincia);
     
     constructorMesa(*(Mesas*)mesa, idMesa, idProvincia, urna);
     //setIdMesa(*(Mesas*)mesa, idMesa);
     //setProvinciaMesa(*(Mesas*)mesa, idProvincia);
     //setUrnasMesa(*(Mesas*)mesa, urna);
     
     buscar = localizarDato(provincias, provincia);
     
     if(buscar != fin()){
               
                  printf("Se ha encontrado la provincia.\n");
                  provincia = buscar->ptrDato;
                  mesas = getMesasProv(*(Provincia*)provincia);
                  adicionarFinal(mesas, mesa);
                  setMesasProv(*(Provincia*)provincia, mesas);
                  printf("Se ha agregado una mesa.\n");   
               }else printf("No se ha encontrado la provincia.\n");
     system("Pause");     
     }

void bajaMesa(Lista &provincias){
     printf("---------------Dar de baja una mesa-----------------\n");
     PtrDato provincia = new Provincia;
     PtrDato mesa = new Mesas;
     PtrNodoLista buscar;
     Lista mesas;
     int idMesa, idProvincia, opcion = 0;
     
     printf("Ingrese la provincia de la mesa a dar de baja: ");
     scanf("%d",&idProvincia);
     printf("Ingrese el id de la mesa: ");
     scanf("%d",&idMesa);
     
     setIdProvincia(*(Provincia*)provincia,idProvincia);
     
     setIdMesa(*(Mesas*)mesa, idMesa);
     setProvinciaMesa(*(Mesas*)mesa, idProvincia);
     
     buscar = localizarDato(provincias, provincia);
     if(buscar != fin()){
                  printf("Provincia encontrada\n");
                  provincia = buscar->ptrDato;
                  mesas = getMesasProv(*(Provincia*)provincia);
                  buscar = localizarDato(mesas, mesa);
                  if(buscar != fin()){
                               printf("Se ha encontrado la mesa, esta seguro de querer borrar? 1-SI  2-NO  ");
                               scanf("%d", &opcion);
                               if(opcion == 1){
                                         eliminarNodo(mesas, buscar);
                                         printf("Mesa eliminada.\n");
                                    }else printf("Borrado cancelado.\n");
                            }else printf("No existe una mesa con ese ID\n");
               
               }else printf("No existe una provincia con ese ID\n");
     system("Pause");
     }
//-------------------------------FIN ABM MESA-------------------------------------------------//

//-------------------------------ABM PARTIDOS--------------------------------------------------//
void agregarPartido(Lista &partidos){
     printf("---------Agregar un partido------------\n");
     //cin.getline(var, tamaño, fin);
     PtrDato ptrdato;
     int idPartido = 0, opcion = 1;
     char nombre[20]="";
     Lista candidatos;
     crearLista(candidatos, compararCandidatos);
                  
     ptrdato = new Partido;
     printf("Ingrese el ID del partido:");
     fflush(stdin);
     scanf("%d",&idPartido);
     printf("Ingrese el nombre:");
     fflush(stdin);
     scanf("%s", nombre);
     //constructorPartido(*(Partido*)ptrdato, idPartido, nombre);
     setIdPartido(*(Partido*)ptrdato, idPartido);
     setNombrePartido(*(Partido*)ptrdato, nombre);
     setLista(*(Partido*)ptrdato, candidatos);
     if(localizarDato(partidos,ptrdato) != fin())
     {printf("Ya existe ese partido.\n");}
     else{
          adicionarFinal(partidos, ptrdato);
          printf("Se agrego con exito el partido politico.\n");
          }
          
     system("Pause");
     }

void modificarPartido(Lista &partidos){
     printf("---------Modificar un partido------------\n");
     PtrDato ptrdato;
     int idPartido = 0, opcion = 1;
     char nombre[20]="";
     ptrdato = new Partido;
     
     printf("Ingrese el ID del partido a cambiar:");
     fflush(stdin);
     scanf("%d",&idPartido);
     setIdPartido(*(Partido*)ptrdato, idPartido);
     PtrNodoLista dato =localizarDato(partidos,ptrdato);
     
     if( dato != fin()){
         PtrDato insertar;
         insertar = dato->ptrDato;
         
         printf("Se ha encontrado el partido\n");
         printf("Ingrese el nombre del partido para cambiar:");
         fflush(stdin);
         scanf("%s", nombre);
         setNombrePartido(*(Partido*)insertar, nombre);
         printf("Se ha modificado correctamente.\n");
         }else printf("no se ha encontrado el partido.\n");
     
     system("Pause");
     }
     
void bajaPartido(Lista &partidos){
     printf("---------Dar de baja un partido------------\n");
     PtrDato ptrdato;
     int idPartido = 0, opcion = 0;
     char nombre[20]="";
     ptrdato = new Partido;
     
     printf("Ingrese el ID del partido para dar de baja: ");
     fflush(stdin);
     scanf("%d",&idPartido);
     setIdPartido(*(Partido*)ptrdato, idPartido);
     setNombrePartido(*(Partido*)ptrdato, nombre);
     
     PtrNodoLista dato = localizarDato(partidos,ptrdato);
     
     if(dato != fin()){
                printf("Esta seguro de querer borrar? 1-SI  2-NO  ");
                scanf("%d", &opcion);
                if(opcion == 1){
                          eliminarNodo(partidos, dato);//NO BORRA LA LISTA, SE QUEDA EN MEMORIA?
                          printf("Partido eliminado.\n");
                       }else printf("Borrado cancelado.\n");
             }else printf("No existe ese partido.\n");
     system("Pause");
     }

//-------------------------------FIN ABM PARTIDO-------------------------------------------------//
//--------------------------------ABM CANDIDATOS-----------------------------------------------------------//
void agregarCandidato(Lista &partidos){ 
     printf("---------Agregar un candidato a un partido------------\n");
     PtrDato ptrdato;
     PtrDato busqueda = new Partido;
     PtrDato partidoPolitico;
     
     ptrdato = new Candidato;
     Lista candidatos;
    
     int id = 0, partido = 1;
     char nombre2[20] = "";
     
     printf("Ingrese el ID del partido: ");
     scanf("%d",&partido);
     printf("Ingrese el ID del Candidato: ");
     scanf("%d",&id);
     printf("Ingrese el Nombre del candidato: ");
     fflush(stdin);
     scanf("%s",nombre2);
     
     setIdCandidato(*(Candidato*)ptrdato, id);
     setPartidoPoliticoCandidato(*(Candidato*)ptrdato, partido);
     setNombreCandidato(*(Candidato*)ptrdato, nombre2);
     setIdPartido(*(Partido*)busqueda, partido);//para buscar el partido
     
     PtrNodoLista dato = localizarDato(partidos, busqueda);
    
     if(dato != fin()){
                       printf("Se ha encontrado el partido.\n");
                       partidoPolitico = dato->ptrDato;
                       candidatos = getLista(*(Partido*)partidoPolitico);
                       adicionarFinal(candidatos, ptrdato);
                       setLista(*(Partido*)partidoPolitico, candidatos);
                       printf("Se ha agregado un candidato.\n");         
                }else printf("No se ha encontrado el partido.\n");     
     
     system("PAUSE");
     }
     
void modificarCandidato(Lista &partidos){
     printf("---------Modificar un candidato de un partido------------\n");
     
     PtrDato partidoAux = new Partido;
     PtrDato candidato = new Candidato;
     PtrNodoLista buscar;
     Lista candidatos; //Lista donde se modifican los datos
     int idCandidato = 0, idPartido = 1;
     char nombreCandidato[20] = "";
     
     printf("Ingrese el ID del partido del candidato a buscar: ");
     scanf("%d",&idPartido);
     printf("Ingrese el ID del candidato a buscar: ");
     scanf("%d",&idCandidato);
     
     setIdCandidato(*(Candidato*)candidato, idCandidato);
     setPartidoPoliticoCandidato(*(Candidato*)candidato, idPartido);
     setNombreCandidato(*(Candidato*)candidato, nombreCandidato);
     
     setIdPartido(*(Partido*)partidoAux, idPartido);
     buscar = localizarDato(partidos, partidoAux);
     
     if(buscar != fin()){
             printf("Se ha encontrado el partido.\n");
             partidoAux = buscar->ptrDato;
             candidatos = getLista(*(Partido*)partidoAux);
             buscar = localizarDato(candidatos, candidato);        
             if(buscar != fin()){
                                printf("Se ha encontrado el candidato.\n");
                                candidato = buscar->ptrDato;
                                printf("Ingrese el ID del candidato: ");
                                scanf("%d",&idCandidato);
                                printf("Ingrese el Nombre del candidato: ");
                                fflush(stdin);
                                scanf("%s",nombreCandidato);
                                setPartidoPoliticoCandidato(*(Candidato*)candidato, idPartido);
                                setNombreCandidato(*(Candidato*)candidato, nombreCandidato);
                                //setLista(*(Partido*)partidoAux, candidatos);
                                printf("El candidato %s se ha modificado correctamente.\n", getNombreCandidato(*(Candidato*)candidato));
                    }else printf("El candidato no existe.\n");
             
             
             }else printf("El partido no existe.\n");
     system("Pause");
     }
     
void bajaCandidato(Lista &partidos){ //NO DEJAR VACIA LA LISTA CANDIDATO O EXPLOTA TODO TODO
     printf("---------Dar de baja un candidato de un partido------------\n");
     
     PtrDato partidoAux = new Partido;
     PtrDato candidato = new Candidato;
     PtrNodoLista buscar;
     Lista candidatos; //Lista donde se modifican los datos
     int idCandidato = 0, idPartido = 1, opcion = 0;
     
     printf("Ingrese el ID del partido del candidato a buscar: ");
     scanf("%d",&idPartido);
     printf("Ingrese el ID del candidato a buscar: ");
     scanf("%d",&idCandidato);
     
     setIdCandidato(*(Candidato*)candidato, idCandidato);
     setPartidoPoliticoCandidato(*(Candidato*)candidato, idPartido);
     
     setIdPartido(*(Partido*)partidoAux, idPartido);
     buscar = localizarDato(partidos, partidoAux);
     
     if(buscar != fin()){
            
             printf("Se ha encontrado el partido.\n");
             partidoAux = buscar->ptrDato;
             candidatos = getLista(*(Partido*)partidoAux);
             buscar = localizarDato(candidatos, candidato);    
             if(buscar != fin()){
                       printf("Se ha encontrado el candidato, esta seguro de querer borrar? 1-SI  2-NO  ");
                       scanf("%d", &opcion);
                       if(opcion == 1){
                                    partidoAux = buscar->ptrDato;
                                    eliminarNodo(candidatos, buscar);
                                    printf("Candidato eliminado.\n");
                                 }else printf("Borrado cancelado.\n");
                       }else printf("El candidato con ese id no existe.\n");
             }else printf("No existe ese partido.\n");
             
     system("PAUSE");
     }
//-------------------------------FIN ABM CANDIDATO-------------------------------------------------//
//-------------------------------FIN ABM FUNCIONES-------------------------------------------------//

//----------------------------------------MENUS-------------------------------------------------//

void MesaABM(Lista &provincias)
{

    bool continuar = true;
    bool opcinvalida = false;
    int opcion;

    while(continuar == true)
    {
        system("cls"); //Menu principal
        cout << "**ABM Mesa**" << endl;
        cout <<"*********************************************"<<endl;
        cout <<"\n"<<endl;
        cout << "1. Agregar Mesa" << endl;
        cout << "2. Borrar Mesa" << endl;
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
        case 1: 
            agregarMesa(provincias);
            break;
        case 2: 
            bajaMesa(provincias);
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

void CandidatoABM(Lista &partidos)
{

    bool continuar = true;
    bool opcinvalida = false;
    int opcion;

    while(continuar == true)
    {
        system("cls"); //Menu principal
        cout << "**ABM Candidatos**" << endl;
        cout <<"*********************************************"<<endl;
        cout <<"\n"<<endl;
        cout << "1. Agregar candidato a partido" << endl;
        cout << "2. Modificar Candidato de partido" << endl;
        cout << "3. Baja candidaato de un partido"<< endl;
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
        case 1: //funcion de agregar partido
            agregarCandidato(partidos);
            break;
        case 2: //funcion de modificar partido
            modificarCandidato(partidos);
            break;
        case 3: //Funcion dar de baja un partido
            bajaCandidato(partidos);
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

void PartidoABM(Lista &partidos)
{

    bool continuar = true;
    bool opcinvalida = false;
    int opcion;

    while(continuar == true)
    {
        system("cls"); //Menu principal
        cout << "**ABM Partidos**" << endl;
        cout <<"*********************************************"<<endl;
        cout <<"\n"<<endl;
        cout << "1. Agregar partido" << endl;
        cout << "2. Modificar partido" << endl;
        cout << "3. Baja partido"<< endl;
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
        case 1: //funcion de agregar partido
            agregarPartido(partidos);
            break;
        case 2: //funcion de modificar partido
            modificarPartido(partidos);
            break;
        case 3: //Funcion dar de baja un partido
            bajaPartido(partidos);
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

void edicionDeDatos(Lista &provincias, Lista &partidos)
{

    bool continuar = true;
    bool opcinvalida = false;
    int opcion;

    while(continuar == true)
    {
        system("cls"); 
        cout << "**Edicion de datos**" << endl;
        cout <<"*********************************************"<<endl;
        cout <<"\n"<<endl;
        cout << "1. Editar Partido Politico" << endl;
        cout << "2. Editar Candidatos" << endl;
        cout << "3. Editar Mesas"<< endl;
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
        case 1: 
            PartidoABM(partidos);
            break;
        case 2: 
            CandidatoABM(partidos);
            break;
        case 3: 
            MesaABM(provincias);
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
 
