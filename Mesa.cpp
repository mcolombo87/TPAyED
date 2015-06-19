#include "Mesa.h"

void constructorMesa(Mesa mesa)
{

}

void destructorMesa(Mesa mesa)
{

}

int getIdMesa(Mesa mesa)
{
    return mesa.id;
}

int getProvinciaMesa(Mesa mesa)
{
    return mesa.provincia;
}

Cola getUrnasMesa(Mesa mesa)
{
    return mesa.urnas;
}

void setIdMesa(Mesa &mesa, int dato)
{
    mesa.id = dato;
}

void setProvinciaMesa(Mesa &mesa,int  dato)
{
    mesa.provincia = dato;
}

void setUrnasMesa (Mesa &mesa, Cola dato)
{
    mesa.urnas = dato;
}
