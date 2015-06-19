#ifndef URNA_H_INCLUDED
#define URNA_H_INCLUDED
#include "Pila.h"

typedef struct{
        int id;
        char horaApertura[5];
        char horaCierre[5];
        Pila votos;
}Urna;

void constructorUrna(Urna urna);

void destructorUrna(Urna urna);

int getIdUrna(Urna urna);

char* getHoraAperturaUrna(Urna &urna);

char* getHoraCierreUrna(Urna &urna);

Pila getVotosUrna(Urna urna);

void setIdUrna(Urna &urna, int dato);

void setHoraAperturaUrna(Urna &urna,char  dato[5]);

void setHoraCierreUrna(Urna &urna,char  dato[5]);

void setVotosUrna(Urna &urna, Pila dato);

#endif // URNA_H_INCLUDED
