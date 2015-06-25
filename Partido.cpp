#include "Partido.h"
#include <string.h>
#include "Comparaciones.h"
#include "Lista.h"

void constructorPartido(Partido &partido, int id, char nombre[20], Lista candidatos)
{
     partido.id = id;
     strcpy(partido.nombre, nombre);
     crearLista(candidatos,compararCandidatos);
     partido.candidatos = candidatos;
}

void destructorPartido(Partido partido)
{

}

int getIdPartido(Partido partido)
{
    return partido.id;
}

char* getNombrePartido(Partido &partido)
{
    return partido.nombre;
}

Lista getLista(Partido partido)
{
    return partido.candidatos;
}

void setIdPartido(Partido &partido, int dato)
{
    partido.id = dato;
}

void setNombrePartido(Partido &partido,char  dato[20])
{
    strcpy(partido.nombre, dato);
}

void setLista(Partido &partido, Lista dato)
{
    partido.candidatos = dato;
}
