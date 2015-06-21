#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "Lista.h"

void nuevatarea(bool &contin);//Procedimiento invocado para la recursividad del menu principal.
void sistemadevotacion();//Inicia el sistema de votacion con su nuevo menu.
void distribuirVotos(Lista &lstProvincias); //Comienza a distribuir los votos guardado en las estructuras (pilas, colas, listas) y los clasifica.

#endif // FUNCIONES_H_INCLUDED
