#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "funciones.h"
#include "Mesa.h"
#include "Candidato.h"
#include "Partido.h"
#include <windows.h>



void cargarArcCandidatos(Lista &lstCan, Lista &lstPar)
{
    FILE *archivo;
    Candidato candidato;
    PtrDato dato;
    PtrNodoLista buscar;
    int modcontar, modcontar2, sumador = 1;
    //Valida
    PtrDato partRef = new Partido;

     if((archivo=fopen("candidatos.txt", "r"))!=NULL)
     {
         system("cls");
         while((fscanf(archivo,"%d;%[A-Za-z A-Za-z A-Za-z A-Za-z A-Za-z];%d",&candidato.id, &candidato.nombre, &candidato.PartidoPolitico))!=EOF)
         {

             dato = new Candidato;
             setIdCandidato(*(Candidato*)dato, candidato.id);
             setNombreCandidato(*(Candidato*)dato,candidato.nombre);
             setPartidoPoliticoCandidato(*(Candidato*)dato,candidato.PartidoPolitico);
             //Corroboro que no exista Ids duplicados durante la carga de los ficheros.
             buscar = localizarDato(lstCan, dato);
             if(buscar == fin()){
                adicionarFinal(lstCan, dato);

                modcontar = sumador % 3;
                modcontar2 = sumador %30;  //El mod y los ifs a continuaci�n son solo para generar una animaci�n
                if (sumador >= 1)               //cuando los tiempos en encontrar un movimiento v�lido se hacen muy largos
                  {if (sumador ==1)           //entonces cada multiplo de xxxx n�mero se dibuja un caracter
                     {puts("Cargando informacion desde archivos, aguarde...");}
                  if(modcontar ==0)
                  {printf("%c", 16);}
                  if(modcontar2 == 0){system("cls");puts("Cargando informacion desde archivos, aguarde...");}
                  }sumador = sumador +1;
                  Sleep(10);

                //Valido referencias.
                setIdPartido(*(Partido*)partRef, candidato.PartidoPolitico);
                buscar = localizarDato(lstPar, partRef);
                if(buscar == fin()){printf("\n*El candidato de ID: %d, hace referencia a un Partido Politico que NO existe.*\nUTILICE EL ABM PARA CORREGIR EL ERROR ANTES DE COMENZAR LA VOTACION\n", candidato.id);system("pause");}


                       }else{ printf("\n**Se detecto un ID duplicado en los archivos\n**El Candidato: %s -SERA OMITIDO-\n**Corrobore la informacion suministrada en los archivos**\n", candidato.nombre);
             system("Pause");}
         }
     }else {puts("\nAVISO IMPORTANTE:\n**No se encontro el archivo 'candidatos.txt' o no fue posible abrirlo.**\n**No se cargaron datos de candidatos**\n");
            puts("****Se creara un archivo nuevo con la informacion suministrada al cerrar la aplicacion,\nsolo si existe informacion que almacenar...****\n");
            system("pause");}

    fclose(archivo);
}

void cargarArcPartidos(Lista &lstPar)
{

    FILE *archivo3;
    Partido partido;
    PtrDato dato;
    PtrNodoLista buscar;
    Lista candidatos;
    int modcontar, modcontar2, sumador = 1;

     if((archivo3=fopen("partidos.txt", "r"))!=NULL)
     {
         system("cls");
         while((fscanf(archivo3,"%d;%[A-Za-z A-Za-z A-Za-z A-Za-z A-Za-z]",&partido.id, &partido.nombre))!=EOF)
         {

             dato = new Partido;
              /*setIdPartido(*(Partido*)dato, partido.id);
             setNombrePartido(*(Partido*)dato, partido.nombre);*/
             constructorPartido(*(Partido*)dato,partido.id,partido.nombre, candidatos);
            //Corroboro que no exista Ids duplicados durante la carga de los ficheros.
             buscar = localizarDato(lstPar, dato);
             if(buscar == fin()){
                adicionarFinal(lstPar, dato);

                modcontar = sumador % 3;
                modcontar2 = sumador %30;  //El mod y los ifs a continuaci�n son solo para generar una animaci�n
                if (sumador >= 1)               //cuando los tiempos en encontrar un movimiento v�lido se hacen muy largos
                  {if (sumador ==1)           //entonces cada multiplo de xxxx n�mero se dibuja un caracter
                     {puts("Cargando informacion desde archivos, aguarde...");}
                  if(modcontar ==0)
                  {printf("%c", 16);}
                  if(modcontar2 == 0){system("cls");puts("Cargando informacion desde archivos, aguarde...");}
                  }
                sumador = sumador +1;
                Sleep(10);
                       }else{ printf("\n**Se detecto un ID duplicado en los archivos\n**El Partido: %s -SERA OMITIDO-\n**Corrobore la informacion suministrada en los archivos**\n", partido.nombre);
             system("Pause");}
         }
     }else {puts("\nAVISO IMPORTANTE:\n**No se encontro el archivo 'partidos.txt' o no fue posible abrirlo.**\n**No se cargaron datos de partidos**\n");
            puts("****Se creara un archivo nuevo con la informacion suministrada al cerrar la aplicacion, solo si existe informacion que almacenar...****\n");
            system("pause");}

    fclose(archivo3);
}

void cargarArcMesas(Lista &lstMes)
{

    FILE *archivo2;
    Mesas mesas;
    PtrDato dato;
    PtrNodoLista buscar;
    int modcontar, modcontar2, sumador = 1;
     if((archivo2=fopen("mesas.txt", "r"))!=NULL)
     {
         system("cls");
         while((fscanf(archivo2,"%d;%d",&mesas.id, &mesas.provincia))!=EOF)
         {

             dato = new Mesas;
             setIdMesa(*(Mesas*)dato, mesas.id);
             setProvinciaMesa(*(Mesas*)dato,mesas.provincia);
            //Corroboro que no exista Ids duplicados durante la carga de los ficheros.
             buscar = localizarDato(lstMes, dato);
             if(buscar == fin()){
                    if (mesas.provincia > 24 || mesas.provincia < 1 )
                    {
                        printf("\n***La provincia a la que la Mesa ID: %d, hace referencia NO ES VALIDA***\n-LA MESA SERA OMITIDA Y ELIMINADA\n**Corrobore la informacion suministrada en los archivos, genere nuevamente la mesa**\n", mesas.id);
                        system("Pause");
                    }else{
                adicionarFinal(lstMes, dato);
                modcontar = sumador % 3;
                modcontar2 = sumador %30;  //El mod y los ifs a continuaci�n son solo para generar una animaci�n
                if (sumador >= 1)               //cuando los tiempos en encontrar un movimiento v�lido se hacen muy largos
                  {if (sumador ==1)           //entonces cada multiplo de xxxx n�mero se dibuja un caracter
                     {puts("Cargando informacion desde archivos, aguarde...");}
                  if(modcontar ==0)
                  {printf("%c", 16);}
                  if(modcontar2 == 0){system("cls");puts("Cargando informacion desde archivos, aguarde...");}
                  }sumador = sumador +1;
                  Sleep(10);
                  }
                       }else{ printf("\n**Se detecto un ID duplicado en los archivos\n**La mesa de ID: %d Provincia: %d -SERA OMITIDA-\n**Corrobore la informacion suministrada en los archivos**\n", mesas.id, mesas.provincia);
             system("Pause");}
         }
     }else {puts("\nAVISO IMPORTANTE:\n**No se encontro el archivo 'mesas.txt' o no fue posible abrirlo.**\n**No se cargaron datos de mesas**\n");
            puts("****Se creara un archivo nuevo con la informacion suministrada al cerrar la aplicacion, solo si existe informacion que almacenar...****\n");
            system("pause");}
    fclose(archivo2);

}

void guardarEnArchivos(Lista &Candidatos, Lista &Partidos, Lista &Mesa)
{
    FILE *fileCandi, *filePart, *fileMesa;
    PtrNodoLista nodo;

    //Guardo Mesas
    if((fileMesa=fopen("mesas.txt", "w"))!=NULL)
     {
         nodo = primero(Mesa);
         while (nodo != fin())
         {
             fprintf(fileMesa,"%d;%d\n", getIdMesa(*(Mesas*)nodo->ptrDato),getProvinciaMesa(*(Mesas*)nodo->ptrDato) );
             nodo = siguiente(Mesa, nodo);
         }
     } else{puts("El archivo mesas.txt no pudo ser creado");}

     //Guardo Candidatos
    if((fileCandi=fopen("candidatos.txt", "w"))!=NULL)
     {
         nodo = primero(Candidatos);
         while (nodo != fin())
         {
             fprintf(fileCandi,"%d;%s;%d\n", getIdCandidato(*(Candidato*)nodo->ptrDato),getNombreCandidato(*(Candidato*)nodo->ptrDato),getPartidoPolitico(*(Candidato*)nodo->ptrDato) );
             nodo = siguiente(Candidatos, nodo);
         }
     } else{puts("El archivo candidatos.txt no pudo ser creado");}

     //Guardo Partidos
    if((filePart=fopen("partidos.txt", "w"))!=NULL)
     {
         nodo = primero(Partidos);
         while (nodo != fin())
         {
             fprintf(filePart,"%d;%s\n", getIdPartido(*(Partido*)nodo->ptrDato),getNombrePartido(*(Partido*)nodo->ptrDato) );
             nodo = siguiente(Partidos, nodo);
         }
     } else{puts("El archivo partidos.txt no pudo ser creado");}
}

