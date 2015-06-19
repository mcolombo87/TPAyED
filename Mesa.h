#ifndef MESA_H_INCLUDED
#define MESA_H_INCLUDED
#include "Cola.h"

typedef struct{
    int id;
    int provincia;
    Cola urnas;
}Mesas;

void constructorMesa(Mesas mesa);

void destructorMesa(Mesas mesa);

int getIdMesa(Mesas mesa);

int getProvinciaMesa(Mesas mesa);

Cola getUrnasMesa(Mesas mesa);

void setIdMesa(Mesas &mesa, int dato);

void setProvinciaMesa(Mesas &mesa,int  dato);

void setUrnasMesa (Mesas &mesa, Cola dato);

#endif // MESA_H_INCLUDED
