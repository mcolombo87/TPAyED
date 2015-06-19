#include "PartidosXProv.h"
#include <string.h>

void constructorPartidosXProv(PartidosXProv partXprov)
{

}

void destructorPartidosXProv(PartidosXProv partXprov)
{

}

int getIdPartidosXProv(PartidosXProv partXprov)
{
    return partXprov.id;
}

char* getNombrePartidosXProv(PartidosXProv &partXprov)
{
    return partXprov.nombre;
}

int getVotosPartidosXProv(PartidosXProv partXprov)
{
    return partXprov.votos;
}

void setIdPartidosXProv(PartidosXProv &partXprov, int dato)
{
    partXprov.id = dato;
}

void setNombrePartidosXProv(PartidosXProv &partXprov,char  dato[20])
{
    strcpy(partXprov.nombre, dato);
}

void setVotosPartidosXProv(PartidosXProv &partXprov,int  dato)
{
    partXprov.votos = dato;
}
