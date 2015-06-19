#include "Pila.h"
#include <string.h>

/* Implementación de Primitivas */
/*------------------------------*/
void crearPila(Pila& pila)
{
    pila.top = finPila();
}

/*----------------------------------------------------------------------------*/
PtrNodoPila finPila() {
  return NULL;
}

/*----------------------------------------------------------------------------*/
void push(Pila &pila, PtrDatoPila ptrDato) {

  PtrNodoPila nuevoNodo = new NodoPila;

  if (!estaVaciaPila(pila)) { //pila NO vacia
    nuevoNodo->ptrDato = ptrDato;
    nuevoNodo->sgte= pila.top;
    pila.top = nuevoNodo;
    //El primer nodo no cambia
   }
   else{
    nuevoNodo->ptrDato = ptrDato;
    nuevoNodo->sgte= finPila();
    //Como es nuevo el primero y ultimo son el mismo
    pila.top = nuevoNodo;
   }

}

/*----------------------------------------------------------------------------*/
bool estaVaciaPila(Pila &pila) {

    if(pila.top == NULL)
    {
        return true;
    }
    else{return false;}
}

/*----------------------------------------------------------------------------*/
PtrDatoPila pop(Pila &pila) {

    PtrDatoPila pilaNodoDato;
    PtrNodoPila nodoAux; //Nodo que saco.

    nodoAux = pila.top;
    pilaNodoDato = nodoAux ->ptrDato;
    pila.top = nodoAux ->sgte;

  return pilaNodoDato;
}

/*----------------------------------------------------------------------------*/

void destruirPila(Pila &pila){

//    if(estaVacia()){
//        delete pila;
//    }
}
