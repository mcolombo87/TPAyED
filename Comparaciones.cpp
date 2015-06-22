#include "Comparaciones.h"
#include "Lista.h"
#include "Partido.h"
#include "Provincia.h"
#include "Candidato.h"
#include "Mesa.h"
#include "PartidosXProv.h"
#include "CandidatosXProv.h"
#include "Voto.h"



ResultadoComparacion compararPartido(PtrDato ptrDato1, PtrDato ptrDato2) {
if (((Partido*)ptrDato1)->id > ((Partido*)ptrDato2)->id) {
        return MAYOR;
    }
    else if (((Partido*)ptrDato1)->id < ((Partido*)ptrDato2)->id){
        return MENOR;
    }
    else {
        return IGUAL;
    }
}

ResultadoComparacion compararProvincia(PtrDato ptrDato1, PtrDato ptrDato2) {
if (((Provincia*)ptrDato1)->id > ((Provincia*)ptrDato2)->id) {
        return MAYOR;
    }
    else if (((Provincia*)ptrDato1)->id < ((Provincia*)ptrDato2)->id){
        return MENOR;
    }
    else {
        return IGUAL;
    }
}

ResultadoComparacion compararCandidatos(PtrDato ptrDato1, PtrDato ptrDato2) {
if (((Candidato*)ptrDato1)->id > ((Candidato*)ptrDato2)->id) {
        return MAYOR;
    }
    else if (((Candidato*)ptrDato1)->id < ((Candidato*)ptrDato2)->id){
        return MENOR;
    }
    else {
        return IGUAL;
    }
}

ResultadoComparacion compararMesa(PtrDato ptrDato1, PtrDato ptrDato2) {
if (((Mesas*)ptrDato1)->id > ((Mesas*)ptrDato2)->id) {
        return MAYOR;
    }
    else if (((Mesas*)ptrDato1)->id < ((Mesas*)ptrDato2)->id){
        return MENOR;
    }
    else {
        return IGUAL;
    }
}

/**Comparaciones entre VOTOS y PartidosXProvincia y CandidatosXProvincias para contabilizar*/
ResultadoComparacion compararPartidoXProv(PtrDato ptrDato1, PtrDato ptrDato2) {
if (((PartidosXProv*)ptrDato1)->id > ((CandidatosXProv*)ptrDato2)->PartidoPolitico) {
        return MAYOR;
    }
    else if (((PartidosXProv*)ptrDato1)->id < ((PartidosXProv*)ptrDato2)->id){
        return MENOR;
    }
    else {
        return IGUAL;
    }
}

ResultadoComparacion compararCandidatosXProv(PtrDato ptrDato1, PtrDato ptrDato2) {
if (((CandidatosXProv*)ptrDato1)->id > ((Voto*)ptrDato2)->idCandidato) { //Compara con idCandidato(dentro de voto)
        return MAYOR;
    }
    else if (((CandidatosXProv*)ptrDato1)->id < ((Voto*)ptrDato2)->idCandidato){
        return MENOR;
    }
    else {
        return IGUAL;
    }
}
