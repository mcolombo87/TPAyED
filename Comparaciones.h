#ifndef COMPARACIONES_H_INCLUDED
#define COMPARACIONES_H_INCLUDED
#include "Lista.h"

ResultadoComparacion compararPartido(PtrDato ptrDato1, PtrDato ptrDato2);
ResultadoComparacion compararProvincia(PtrDato ptrDato1, PtrDato ptrDato2);
ResultadoComparacion compararCandidatos(PtrDato ptrDato1, PtrDato ptrDato2);
ResultadoComparacion compararMesa(PtrDato ptrDato1, PtrDato ptrDato2);
ResultadoComparacion compararPartidoXProv(PtrDato ptrDato1, PtrDato ptrDato2);
ResultadoComparacion compararCandidatosXProv(PtrDato ptrDato1, PtrDato ptrDato2);

ResultadoComparacion votosCandidatosXProv(PtrDato , PtrDato );
ResultadoComparacion votosPartidoXProv(PtrDato , PtrDato );

#endif //
