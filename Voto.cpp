#include "Voto.h"

void constructorVoto(Voto voto)
{
//    voto.id = NULL;
//    voto.idCandidato = NULL;
}

void destructorVoto(Voto voto)
{
    //delete voto;
}

int getIdVoto(Voto voto)
{
    return voto.id;
}

int getIdCandidatoVoto(Voto voto)
{
    return voto.idCandidato;
}

void setIdVoto(Voto &voto,int dato)
{
    voto.id = dato;
}

void setIdCandidatoVoto(Voto &voto,int dato)
{
    voto.idCandidato = dato;
}
