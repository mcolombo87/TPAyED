#ifndef PROVINCIA_H_INCLUDED
#define PROVINCIA_H_INCLUDED
#include "Lista.h"

#ifndef NULL
#define NULL      0
#endif

typedef struct{
        int id;
        Lista mesas;
        Lista partidosXprovincia;
        Lista candidatosXprovincia;
}Provincia;

void constructorProvincia(Provincia provincia);

void destructorProvincia(Provincia provincia);

int getIdProvincia(Provincia provincia);

Lista getMesasProv(Provincia provincia);

Lista getPartidosProv(Provincia provincia);

Lista* getPartidosProvPtr (Provincia&);

Lista getCandidatosProv(Provincia provincia);

void setIdProvincia(Provincia &provincia, int dato);

void setMesasProv(Provincia &provincia, Lista dato);

void setPartidosProv(Provincia &provincia, Lista dato);

void setCandidatosProv(Provincia &provincia, Lista dato);


#endif // PROVINCIA_H_INCLUDED
