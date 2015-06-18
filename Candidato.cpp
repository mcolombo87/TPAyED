#include "Candidato.h"
#include <string.h>


void constructorCandidato(Candidato candidato)
{

}

void destructorCandidato(Candidato candidato)
{

}

int getIdCandidato(Candidato candidato)
{
    return candidato.id;
}

char* getNombreCandidato(Candidato &candidato)
{
    return candidato.nombre;
}

char* getPartidoPolitico(Candidato &candidato)
{
    return candidato.PartidoPolitico;
}

void setIdCandidato(Candidato &candidato, int dato)
{
    candidato.id = dato;
}

void setNombreCandidato(Candidato &candidato,char  dato[20])
{
    strcpy(candidato.nombre, dato);
}

void setPartidoPoliticoCandidato(Candidato &candidato,char  dato[20])
{
    strcpy(candidato.PartidoPolitico, dato);
}
