#include "Cola.h"

/******************************************************************************/
/* Implementación de Primitivas */
/*------------------------------*/
void crearCola(Cola& cola)
{
    cola.last = finCola();
    cola.first = finCola();
}

/*----------------------------------------------------------------------------*/
PtrNodoCola finCola() {
  return NULL;
}

/*----------------------------------------------------------------------------*/
void encolar(Cola &cola, PtrDatoCola ptrDato) {

  PtrNodoCola nuevoNodo = new NodoCola;

  if (!estaVacia(cola)) { //Cola NO vacia
    nuevoNodo->ptrDato = ptrDato;
    nuevoNodo->sgte= finCola();
    PtrNodoCola AuxNodo;
    AuxNodo = cola.last;
    cola.last = nuevoNodo;
    AuxNodo ->sgte = nuevoNodo;
    //El primer nodo no cambia
   }
   else{
    nuevoNodo->ptrDato = ptrDato;
    nuevoNodo->sgte= finCola();
    //Como es nuevo el primero y ultimo son el mismo
    cola.last = nuevoNodo;
    cola.first = nuevoNodo;
   }

}

/*----------------------------------------------------------------------------*/
bool estaVacia(Cola& cola) {

    if(cola.first == NULL)
    {
        return true;
    }
    else{return false;}
}

/*----------------------------------------------------------------------------*/
PtrDatoCola desencolar(Cola &cola) {

    PtrDatoCola colaNodoDato;
    PtrNodoCola nodoAux; //Nodo que saco.

    nodoAux = cola.first;
    colaNodoDato = nodoAux ->ptrDato;  //cola.first.ptrDato;
    cola.first = nodoAux ->sgte;

  return colaNodoDato;
  //ptrPrevio->sgte = ptrNodo->sgte;
}

/*----------------------------------------------------------------------------*/

void destruir(Cola &cola){

//    if(estaVacia()){
//        delete cola;
//    }
}
