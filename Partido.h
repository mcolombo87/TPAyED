#ifndef PARTIDO_H_INCLUDED
#define PARTIDO_H_INCLUDED
#include "Lista.h"

#ifndef NULL
#define NULL      0
#endif

typedef struct{
        int id;
        char nombre[20];
        Lista candidatos;
}Partido;

void constructorPartido(Partido partido);

void destructorPartido(Partido partido);

int getIdPartido(Partido partido);

char* getNombrePartido(Partido &partido);

Lista getLista(Partido partido);

void setIdPartido(Partido &partido, int dato);

void setNombrePartido(Partido &partido,char  dato[20]);

void setLista(Partido &partido, Lista dato);



#endif // PARTIDO_H_INCLUDED
