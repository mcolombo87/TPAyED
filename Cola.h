#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#ifndef NULL
#define NULL      0
#endif

/* Tipo de Informacion que esta contenida en los Nodos de la
   Cola, identificada como Dato. */
typedef void* PtrDatoCola;

/* Tipo de Estructura de los Nodos de la Cola. */
struct NodoCola {
    PtrDatoCola ptrDato; // puntero al dato almacenado
    NodoCola* sgte; // puntero al siguiente
};

/* Tipo de Puntero a los Nodos de la Cola, el cual se usa para trabajar
    sobre la Cola y acceder a sus Datos. */
typedef NodoCola* PtrNodoCola;


/* Tipo de Estructura de la Cola */
struct Cola{
    PtrNodoCola first;      // puntero al primer nodo de la cola
    PtrNodoCola last;
};


void crearCola(Cola& cola);
void destruir(Cola& cola);

PtrDatoCola desencolar(Cola& cola);
void encolar(Cola& cola, PtrDatoCola ptrDato);
bool estaVacia(Cola& cola);
PtrNodoCola finCola();


#endif // COLA_H_INCLUDED
