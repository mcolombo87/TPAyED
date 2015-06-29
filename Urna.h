#ifndef URNA_H_INCLUDED
#define URNA_H_INCLUDED
#include "Pila.h"

typedef struct{
        int id;
        char* horaApertura;
        char* horaCierre;
        Pila votos;
}Urna;

void constructorUrna(Urna &urna, int id, char* horaApertura, char* horaCierre, Pila votos);

void destructorUrna(Urna urna);

int getIdUrna(Urna urna);

char* getHoraAperturaUrna(Urna &urna);

char* getHoraCierreUrna(Urna &urna);

Pila getVotosUrna(Urna urna);

void setIdUrna(Urna &urna, int dato);

void setHoraAperturaUrna(Urna &urna, char* dato);

void setHoraCierreUrna(Urna &urna,char* dato);

void setVotosUrna(Urna &urna, Pila dato);

#endif // URNA_H_INCLUDED
