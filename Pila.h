#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#ifndef NULL
#define NULL      0
#endif

/* Tipo de Informacion que esta contenida en los Nodos de la
   Pila, identificada como Dato. */
typedef void* PtrDatoPila;

/* Tipo de Estructura de los Nodos de la Pila. */
struct NodoPila {
    PtrDatoPila ptrDato; // puntero al dato almacenado
    NodoPila* sgte; // puntero al siguiente
};

/* Tipo de Puntero a los Nodos de la Pila, el cual se usa para trabajar
    sobre la Pila y acceder a sus Datos. */
typedef NodoPila* PtrNodoPila;


/* Tipo de Estructura de la Pila */
struct Pila{
    PtrNodoPila top;      // puntero al primer nodo de la pila
};


void crearPila(Pila& pila);
void destruirPila(Pila& pila);

PtrDatoPila pop(Pila& pila);
void push(Pila& pila, PtrDatoPila ptrDato);
bool estaVaciaPila(Pila& pila);
PtrNodoPila finPila();
// PILA_H_INCLUDED
#endif
