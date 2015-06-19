#include "Urna.h"
#include <string.h>

void constructorUrna(Urna urna)
{

}

void destructorUrna(Urna urna)
{

}

int getIdUrna(Urna urna)
{
    return urna.id;
}

char* getHoraAperturaUrna(Urna &urna)
{
    return urna.horaApertura;
}

char* getHoraCierreUrna(Urna &urna)
{
    return urna.horaCierre;
}

Pila getVotosUrna(Urna urna)
{
    return urna.votos;
}

void setIdUrna(Urna &urna, int dato)
{
    urna.id = dato;
}

void setHoraAperturaUrna(Urna &urna,char  dato[5])
{
    strcpy(urna.horaApertura, dato);
}

void setHoraCierreUrna(Urna &urna,char  dato[5])
{
    strcpy(urna.horaCierre, dato);
}

void setVotosUrna(Urna &urna, Pila dato)
{
    urna.votos = dato;
}
