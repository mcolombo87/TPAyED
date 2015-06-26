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
void agregarMesa(Lista &mesas){
      printf("---------------Agregar una mesa-----------------\n");
     cout << longitud(mesas) << endl;
     PtrDato mesa = new Mesas;
     PtrNodoLista buscar;
     Cola urna;
     int idMesa, idProvincia;
     bool correcto;
     
     cout << "Ingrese el id de la provincia: ";
     fflush(stdin);
     correcto = scanf("%d",&idProvincia);
     while(!correcto){
           cout << "Debe ingresar un numero entero, intente de nuevo: " << endl;
           fflush(stdin);
           correcto = scanf("%d",&idProvincia);           
                      }
     printf("Ingrese el id de la mesa: ");
     fflush(stdin);
     correcto = scanf("%d",&idMesa);
     while(!correcto){
           cout << "Debe ingresar un numero entero, intente de nuevo: " << endl;
           fflush(stdin);
           correcto = scanf("%d",&idMesa);           
                      }
     
     constructorMesa(*(Mesas*)mesa, idMesa, idProvincia, urna);
     
     buscar = localizarDato(mesas, mesa);
     if(buscar == fin()){
        adicionarFinal(mesas, mesa);
        printf("Se ha agregado una mesa con el id %d.\n", idMesa);   
               }else printf("Ya existe una mesa con ese id.\n");
     system("Pause");     
     }

void bajaMesa(Lista &mesas){
     printf("---------------Dar de baja una mesa-----------------\n");
     
     PtrDato mesa = new Mesas;
     PtrNodoLista buscar;
     bool correcto;
     int idMesa, idProvincia, opcion = 0;
     
     printf("Ingrese el id de la mesa: ");
     fflush(stdin);
     correcto = scanf("%d",&idMesa);
     while(!correcto){
           cout << "Debe ingresar un numero entero, intente de nuevo: " << endl;
           fflush(stdin);
           correcto = scanf("%d",&idMesa);           
                      }
     
     setIdMesa(*(Mesas*)mesa, idMesa);
     buscar = localizarDato(mesas, mesa);
     
     if(buscar != fin()){
            printf("Se ha encontrado la mesa ID: %d, esta seguro de querer borrar? 1-SI  2-NO  ", idMesa);
            fflush(stdin);
            correcto = scanf("%d",&opcion);
            while(!correcto){
                             cout << "Debe ingresar un numero entero, intente de nuevo: " << endl;
                             fflush(stdin);
                             correcto = scanf("%d",&opcion);           
                      }
            
            if(opcion == 1){
                     eliminarNodo(mesas, buscar);
                     printf("Mesa eliminada.\n");
                     }else printf("Borrado cancelado.\n");
                            }else printf("No existe una mesa con ese ID\n");
               
     system("Pause");
     }
//-------------------------------FIN ABM MESA-------------------------------------------------//

//-------------------------------ABM PARTIDOS--------------------------------------------------//
void agregarPartido(Lista &partidos){
     printf("---------Agregar un partido------------\n");
     PtrDato ptrdato= new Partido;;
     int idPartido;
     PtrNodoLista buscar;
     char nombre[20]="";
     bool correcto;
     Lista candidatos;
                  
     printf("Ingrese el ID del partido:");
     fflush(stdin);
     correcto = scanf("%d",&idPartido);
     while(!correcto){
           cout << "Debe ingresar un numero entero, intente de nuevo: " << endl;
           fflush(stdin);
           correcto = scanf("%d",&idPartido);
           fflush(stdin);           
                      }
                      
     printf("Ingrese el nombre:");
     fflush(stdin);
     cin.getline(nombre, 20, '\n');
     while(strlen(nombre) < 3){
                     cout << "Debe ingresa un nombre de al menos 3 caracteres: ";
                     cin.getline(nombre, 20, '\n');
                     fflush(stdin);}
     constructorPartido(*(Partido*)ptrdato, idPartido, nombre, candidatos);
     buscar = localizarDato(partidos, ptrdato);
     if(buscar == fin()){
               adicionarFinal(partidos, ptrdato);
               printf("Se agrego con exito el partido ""%s"".\n", getNombrePartido(*(Partido*)ptrdato));
               }else cout << "Ya existe un partido con ese ID.\n" << endl;
             
     system("Pause");
     }

void modificarPartido(Lista &partidos){
     printf("---------Modificar un partido------------\n");
     PtrDato ptrdato = new Partido;
     int idPartido = 0;
     char nombre[20]="";
     bool correcto;
     
     printf("Ingrese el ID del partido a cambiar:");
     fflush(stdin);
     correcto = scanf("%d",&idPartido);
     while(!correcto){
          cout << "Debe ingresar un numero entero, intente de nuevo: " << endl;
          fflush(stdin);
          correcto = scanf("%d",&idPartido); 
          fflush(stdin);           
                      }
                      
     setIdPartido(*(Partido*)ptrdato, idPartido);
     PtrNodoLista dato = localizarDato(partidos, ptrdato);
     
     if( dato != fin()){
         ptrdato = dato->ptrDato;
         printf("Se ha encontrado el partido\n");
         printf("Ingrese el nombre del partido para cambiar:");
         fflush(stdin);
         cin.getline(nombre, 20, '\n');
         while(strlen(nombre) < 3){
                     cout << "Debe ingresa un nombre de al menos 3 caracteres: ";
                     cin.getline(nombre, 20, '\n');
                     fflush(stdin);}
         setNombrePartido(*(Partido*)ptrdato, nombre);
         printf("El partido %s se ha modificado correctamente.\n", getNombrePartido(*(Partido*)ptrdato));
         }else printf("no se ha encontrado el partido.\n");
     
     system("Pause");
     }
     
void bajaPartido(Lista &partidos){
     printf("---------Dar de baja un partido------------\n");
     PtrDato ptrdato = new Partido;
     int idPartido = 0, opcion = 0;
     char nombre[20]="";
     bool correcto;
     
     printf("Ingrese el ID del partido para dar de baja: ");
     fflush(stdin);
     correcto = scanf("%d",&idPartido);
     while(!correcto){
                      fflush(stdin);
          cout << "Debe ingresar un numero entero, intente de nuevo: " << endl;
          correcto = scanf("%d",&idPartido);
          fflush(stdin);           
                      }
                      
     setIdPartido(*(Partido*)ptrdato, idPartido);
     PtrNodoLista dato = localizarDato(partidos,ptrdato);
     
     if(dato != fin()){
                printf("Esta seguro de querer borrar el partido %s? 1-SI  2-NO  ", getNombrePartido(*(Partido*)dato->ptrDato));
                fflush(stdin);
                correcto = scanf("%d",&opcion);
                while(!correcto){
                      fflush(stdin);
                      cout << "Debe ingresar un numero entero, intente de nuevo: " << endl;
                      correcto = scanf("%d",&opcion);
                      fflush(stdin);           
                      }
                if(opcion == 1){
                          eliminarNodo(partidos, dato);
                          printf("Partido eliminado.\n");
                       }else printf("Borrado cancelado.\n");
             }else printf("No existe ese partido.\n");
     system("Pause");
     }

//-------------------------------FIN ABM PARTIDO-------------------------------------------------//
//--------------------------------ABM CANDIDATOS-----------------------------------------------------------//
void agregarCandidato(Lista &candidatos){ 
     printf("---------Agregar un candidato a un partido------------\n");
     PtrDato ptrdato = new Candidato;
    
     int id, partido;
     char nombre[20] = "";
     bool correcto;
     PtrNodoLista buscar;
     
     printf("Ingrese el ID del partido: ");
     correcto = scanf("%d",&partido);
     while(!correcto){
                      fflush(stdin);
          cout << "Debe ingresar un numero entero, intente de nuevo: " << endl;
          correcto = scanf("%d",&partido);  
          fflush(stdin);         
                      }
     printf("Ingrese el ID del Candidato: ");
     correcto = scanf("%d",&id);
     while(!correcto){
                      fflush(stdin);
          cout << "Debe ingresar un numero entero, intente de nuevo: " << endl;
          correcto = scanf("%d",&id); 
          fflush(stdin);          
                      }
     printf("Ingrese el Nombre del candidato: ");
     fflush(stdin);
     cin.getline(nombre, 20, '\n');
     while(strlen(nombre) < 5){
                     cout << "Debe ingresa un nombre de al menos 5 caracteres: ";
                     cin.getline(nombre, 20, '\n');
                     fflush(stdin);}
     
     setIdCandidato(*(Candidato*)ptrdato, id);
     setPartidoPoliticoCandidato(*(Candidato*)ptrdato, partido);
     setNombreCandidato(*(Candidato*)ptrdato, nombre);
     
     buscar = localizarDato(candidatos, ptrdato);
     if(buscar == fin()){
               adicionarFinal(candidatos, ptrdato);
               printf("Se ha agregado un candidato.\n");
               }else cout << "Ya existe un candidato con esa ID" << endl;              
     
     system("PAUSE");
     }
     
void modificarCandidato(Lista &candidatos){
     printf("---------Modificar un candidato de un partido------------\n");
     
     PtrDato candidato = new Candidato;
     int idCandidato = 0, idPartido = 1;
     char nombre[20] = "";
     bool correcto;
     PtrNodoLista buscar;
     
     printf("Ingrese el ID del candidato a buscar: ");
     correcto = scanf("%d",&idCandidato);
     while(!correcto){
                      fflush(stdin);
          cout << "Debe ingresar un numero entero, intente de nuevo: " << endl;
          correcto = scanf("%d",&idCandidato);
          fflush(stdin);           
                      }
     
     setIdCandidato(*(Candidato*)candidato, idCandidato);
     
     buscar = localizarDato(candidatos, candidato);
     
     if(buscar != fin()){
               printf("Se ha encontrado el candidato.\n");
               candidato = buscar->ptrDato;
               printf("Ingrese el Nombre del candidato: ");
               fflush(stdin);
               cin.getline(nombre, 20, '\n');
               while(strlen(nombre) < 5){
                     cout << "Debe ingresa un nombre de al menos 5 caracteres: ";
                     fflush(stdin);
                     cin.getline(nombre, 20, '\n');
                     fflush(stdin);}
               setNombreCandidato(*(Candidato*)candidato, nombre);
               printf("El candidato %s se ha modificado correctamente.\n", getNombreCandidato(*(Candidato*)candidato));
               }else printf("El candidato no existe.\n");
             
     system("Pause");
     }
     
void bajaCandidato(Lista &candidatos){
     printf("---------Dar de baja un candidato de un partido------------\n");
     
     PtrDato candidato = new Candidato;
     PtrNodoLista buscar;
     bool correcto;
    
     int idCandidato = 0, idPartido = 1, opcion = 0;
     
     printf("Ingrese el ID del candidato a buscar: ");
     correcto = scanf("%d", &idCandidato);
               while(!correcto){
                                fflush(stdin); 
                       cout << "Debe ingresar un numero entero, intente de nuevo: " << endl;
                       correcto = scanf("%d",&idCandidato); 
                       fflush(stdin);           
                                }
     
     setIdCandidato(*(Candidato*)candidato, idCandidato);
    
     buscar = localizarDato(candidatos, candidato);
     if(buscar != fin()){
               printf("Se ha encontrado el candidato, esta seguro de querer borrar a %s? 1-SI  2-NO  ",getNombreCandidato(*(Candidato*)buscar->ptrDato));
               correcto = scanf("%d", &opcion);
               while(!correcto){
                                fflush(stdin); 
                       cout << "Debe ingresar un numero entero, intente de nuevo: " << endl;
                       correcto = scanf("%d",&opcion); 
                       fflush(stdin);           
                                }
               if(opcion == 1){
                         eliminarNodo(candidatos, buscar);
                         printf("Candidato eliminado.\n");
                         }else printf("Borrado cancelado.\n");
               }else printf("El candidato con ese id no existe.\n");
             
     system("PAUSE");
     }
//-------------------------------FIN ABM CANDIDATO-------------------------------------------------//
//-------------------------------FIN ABM FUNCIONES-------------------------------------------------//

//----------------------------------------MENUS-------------------------------------------------//

void MesaABM(Lista &mesas)
{

    bool continuar = true;
    bool opcinvalida = false;
    int opcion;
    bool correcto;

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


         correcto = scanf("%d", &opcion);
               while(!correcto){
                                fflush(stdin); 
                       cout << "Debe ingresar un numero entero, intente de nuevo: " << endl;
                       correcto = scanf("%d",&opcion);
                       fflush(stdin);            
                                }

        switch(opcion)
        {
        case 1: 
            agregarMesa(mesas);
            break;
        case 2: 
            bajaMesa(mesas);
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

void CandidatoABM(Lista &candidatos)
{

    bool continuar = true;
    bool opcinvalida = false;
    int opcion;
    bool correcto;

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


         correcto = scanf("%d", &opcion);
               while(!correcto){
                                fflush(stdin); 
                       cout << "Debe ingresar un numero entero, intente de nuevo: " << endl;
                       correcto = scanf("%d",&opcion); 
                       fflush(stdin);           
                                }

        switch(opcion)
        {
        case 1: //funcion de agregar partido
            agregarCandidato(candidatos);
            break;
        case 2: //funcion de modificar partido
            modificarCandidato(candidatos);
            break;
        case 3: //Funcion dar de baja un partido
            bajaCandidato(candidatos);
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
    bool correcto;

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


         correcto = scanf("%d", &opcion);
               while(!correcto){
                       fflush(stdin);         
                       cout << "Debe ingresar un numero entero, intente de nuevo: " << endl;
                       correcto = scanf("%d",&opcion);
                       fflush(stdin);            
                                }

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

void edicionDeDatos(Lista &candidatos, Lista &partidos, Lista &mesas)
{

    bool continuar = true;
    bool opcinvalida = false;
    int opcion;
    bool correcto;

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


        correcto = scanf("%d", &opcion);
               while(!correcto){
                                fflush(stdin); 
                       cout << "Debe ingresar un numero entero, intente de nuevo: " << endl;
                       correcto = scanf("%d",&opcion);
                       fflush(stdin);            
                                }

        switch(opcion)
        {
        case 1: 
            PartidoABM(partidos);
            break;
        case 2: 
            CandidatoABM(candidatos);
            break;
        case 3: 
            MesaABM(mesas);
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
 
