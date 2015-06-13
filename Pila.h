#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

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


void crear(Pila& pila);
void destruir(Pila& pila);

PtrDatoPila pop(Pila& pila);
void push(Pila& pila, PtrDatoPila ptrDato);
bool estaVacia(Pila& pila);

#endif // PILA_H_INCLUDED
