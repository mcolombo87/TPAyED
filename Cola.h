#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

/* Tipo de Informacion que esta contenida en los Nodos de la
   Cola, identificada como Dato. */
typedef void* PtrDato;

/* Tipo de Estructura de los Nodos de la Cola. */
struct Nodo {
    PtrDato ptrDato; // puntero al dato almacenado
    Nodo* sgte; // puntero al siguiente
};

/* Tipo de Puntero a los Nodos de la Cola, el cual se usa para trabajar
    sobre la Cola y acceder a sus Datos. */
typedef Nodo* PtrNodo;


/* Tipo de Estructura de la Cola */
struct Cola{
    PtrNodo top;      // puntero al primer nodo de la cola
    PtrNodo last;
};


void crear(Cola& cola);
void destruir(Cola& cola);

PtrDato pop(Cola& cola);
void push(Cola& cola, PtrDato ptrDato);
bool estaVacia(Cola& cola);

#endif // COLA_H_INCLUDED
