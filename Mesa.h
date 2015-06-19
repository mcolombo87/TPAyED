#ifndef MESA_H_INCLUDED
#define MESA_H_INCLUDED
#include "Cola.h"

#ifndef NULL
#define NULL      0
#endif

typedef struct{
        int id;
        int provincia;
        Cola urnas;
}Mesa;

void constructorMesa(Mesa mesa);

void destructorMesa(Mesa mesa);

int getIdMesa(Mesa mesa);

int getProvinciaMesa(Mesa mesa);

Cola getUrnasMesa(Mesa mesa);

void setIdMesa(Mesa &mesa, int dato);

void setProvinciaMesa(Mesa &mesa,int  dato);

void setUrnasMesa (Mesa &mesa, Cola dato);

#endif // MESA_H_INCLUDED
