#include "CandidatosXProv.h"
#include <string.h>

void constructorCandidatosXProv(CandidatosXProv candXprov)
{

}

void destructorCandidatosXProv(CandidatosXProv candXprov)
{

}

int getIdCandidatosXProv(CandidatosXProv candXprov)
{
    return candXprov.id;
}

char* getNombreCandidatosXProv(CandidatosXProv &candXprov)
{
    return candXprov.nombre;
}

int getPartidoCandidatosXProv(CandidatosXProv candXprov)
{
    return candXprov.PartidoPolitico;
}

int getVotosCandidatosXProv(CandidatosXProv candXprov)
{
    return candXprov.voto;
}

void setIdCandidatosXProv(CandidatosXProv &candXprov, int dato)
{
    candXprov.id = dato;
}

void setNombreCandidatosXProv(CandidatosXProv &candXprov,char  dato[20])
{
    strcpy(candXprov.nombre, dato);
}

void setPartidoCandidatosXProv(CandidatosXProv &candXprov,int  dato)
{
    candXprov.PartidoPolitico = dato;
}

void setVotosCandidatosXProv(CandidatosXProv &candXprov,int  dato)
{
    candXprov.voto = dato;
}
