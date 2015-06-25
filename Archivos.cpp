#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "funciones.h"
#include "Mesa.h"
#include "Candidato.h"
#include "Partido.h"



void cargarArcCandidatos(Lista &lstCan)
{
    FILE *archivo;
    Candidato candidato;
    PtrDato dato;

     if((archivo=fopen("candidatos.txt", "r"))!=NULL)
     {

         while((fscanf(archivo,"%d;%[A-Za-z A-Za-z A-Za-z A-Za-z A-Za-z];%d",&candidato.id, &candidato.nombre, &candidato.PartidoPolitico))!=EOF)
         {

             dato = new Candidato;
             setIdCandidato(*(Candidato*)dato, candidato.id);
             setNombreCandidato(*(Candidato*)dato,candidato.nombre);
             setPartidoPoliticoCandidato(*(Candidato*)dato,candidato.PartidoPolitico);
             adicionarFinal(lstCan, dato);
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


     if((archivo3=fopen("partidos.txt", "r"))!=NULL)
     {
         while((fscanf(archivo3,"%d;%[A-Za-z A-Za-z A-Za-z A-Za-z A-Za-z]",&partido.id, &partido.nombre))!=EOF)
         {
             dato = new Partido;
             setIdPartido(*(Partido*)dato, partido.id);
             setNombrePartido(*(Partido*)dato, partido.nombre);
             //setLista(*(Partido*)dato,fin()); Que se llene con basura, no me importa (por ahora)
             adicionarFinal(lstPar, dato);
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

     if((archivo2=fopen("mesas.txt", "r"))!=NULL)
     {
         while((fscanf(archivo2,"%d;%d",&mesas.id, &mesas.provincia))!=EOF)
         {
             dato = new Mesas;
             setIdMesa(*(Mesas*)dato, mesas.id);
             setProvinciaMesa(*(Mesas*)dato,mesas.provincia);
             //setUrnasMesa(*(Mesas*)dato,fin()); Que se llene con basura, no me importa (por ahora)
             adicionarFinal(lstMes, dato);
         }
     }else {puts("\nAVISO IMPORTANTE:\n**No se encontro el archivo 'mesas.txt' o no fue posible abrirlo.**\n**No se cargaron datos de mesas**\n");
            puts("****Se creara un archivo nuevo con la informacion suministrada al cerrar la aplicacion, solo si existe informacion que almacenar...****\n");
            system("pause");}
    fclose(archivo2);

}

void guardarEnArchivos(Lista &Candidatos, Lista &Partidos, Lista &Mesa)
{

}
