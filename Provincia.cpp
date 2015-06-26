#include "Provincia.h"

void constructorProvincia(Provincia provincia)
{

}

void destructorProvincia(Provincia provincia)
{

}

int getIdProvincia(Provincia provincia)
{
    return provincia.id;
}

Lista getMesasProv(Provincia provincia)
{
    return provincia.mesas;
}

Lista getPartidosProv(Provincia provincia)
{
    return provincia.partidosXprovincia;
}

Lista getCandidatosProv(Provincia provincia)
{
    return provincia.candidatosXprovincia;
}

void setIdProvincia(Provincia &provincia, int dato)
{
    provincia.id = dato;
}

void setMesasProv(Provincia &provincia, Lista dato)
{
    provincia.mesas = dato;
}

void setPartidosProv(Provincia &provincia, Lista dato)
{
    provincia.partidosXprovincia = dato;
}

void setCandidatosProv(Provincia &provincia, Lista dato)
{
    provincia.candidatosXprovincia = dato;
}
