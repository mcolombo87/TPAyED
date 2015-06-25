#include "Mesa.h"

void constructorMesa(Mesas &mesa, int id, int prov, Cola urna)
{
     mesa.id = id;
     mesa.provincia = prov;
     crearCola(urna);
     mesa.urnas = urna;
}

void destructorMesa(Mesas mesa)
{

}

int getIdMesa(Mesas mesa)
{
    return mesa.id;
}

int getProvinciaMesa(Mesas mesa)
{
    return mesa.provincia;
}

Cola getUrnasMesa(Mesas mesa)
{
    return mesa.urnas;
}

void setIdMesa(Mesas &mesa, int dato)
{
    mesa.id = dato;
}

void setProvinciaMesa(Mesas &mesa,int  dato)
{
    mesa.provincia = dato;
}

void setUrnasMesa (Mesas &mesa, Cola dato)
{
    mesa.urnas = dato;
}
