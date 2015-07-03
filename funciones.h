#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "Lista.h"
#include "Cola.h"

void nuevatarea(bool &contin);//Procedimiento invocado para la recursividad del menu principal.
void sistemadevotacion(Lista &candidatos, Lista &partidos, Lista &mesa);//Inicia el sistema de votacion con su nuevo menu.
bool distribuirVotos(Lista &lstProvincias); //Comienza a distribuir los votos guardado en las estructuras (pilas, colas, listas) y los clasifica.
void edicionDeDatos(Lista&, Lista&, Lista&); //LLeva a la edicion de datos
void agregarMesa(Lista&);
void reportes(Lista provincia);
void pantallaFinalizandoVotac(PtrDato &provDato, PtrDato &mesaDato, PtrDatoCola &urna, int &pantallaEntradas, int &pantallaEntradasProv);

//Funciones para el módulo de carga.

void cargarArcCandidatos(Lista &lstCan, Lista &lstPar);
void cargarArcPartidos(Lista &lstPar);
void cargarArcMesas(Lista &lstMes);
void guardarEnArchivos(Lista &Candidatos, Lista &Partidos, Lista &Mesa);

#endif // FUNCIONES_H_INCLUDED
