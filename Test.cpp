#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string.h>
#include "Test.h"
#include "Lista.h"
#include "Cola.h"
#include "Pila.h"
#include "Voto.h"
#include "Urna.h"
#include "Mesa.h"

void PruebaDeCola()
{
    printf("Prueba de Cola\n");
    Cola miCola;
    PtrDatoCola dato;
    PtrDatoCola datoSacado;
    crearCola(miCola);
    int A = 10;
    dato = &A;
    encolar(miCola,dato);
    datoSacado = desencolar(miCola);
    //Imprimo sacado de cola
    printf("\nDato desde la cola: %d\n", *(int*)datoSacado);
    //Meto varios y vemos que pasa
    if (estaVacia(miCola)){puts("\nCOLA: Esta Vacia!!\n");}else{puts("\nCola: No esta vacia!\n");}
    int B = 4;
    int C = 2;
    PtrDatoCola dato2;
    PtrDatoCola dato3;
    dato2 = &B;
    dato3 = &C;
    encolar(miCola, dato2);
    encolar(miCola, dato3);
    encolar(miCola, dato);
    if (estaVacia(miCola)){puts("\nCOLA: Esta Vacia!!\n");}else{puts("\nCola: No esta vacia!\n");}
    //Imprimo sacado de cola y Pruebo el esVacia
    datoSacado = desencolar(miCola);
    printf("\nDato desde la cola 1: %d", *(int*)datoSacado);
    if (estaVacia(miCola)){puts("\nCOLA: Esta Vacia!!\n");}else{puts("\nCola: No esta vacia!\n");}
    datoSacado = desencolar(miCola);
    printf("\nDato desde la cola 2: %d", *(int*)datoSacado);
    if (estaVacia(miCola)){puts("\nCOLA: Esta Vacia!!\n");}else{puts("\nCola: No esta vacia!\n");}
    datoSacado = desencolar(miCola);
    printf("\nDato desde la cola 3: %d\n", *(int*)datoSacado);
    if (estaVacia(miCola)){puts("\nCOLA: Esta Vacia!!\n");}else{puts("\nCola: No esta vacia!\n");}


    system("PAUSE");
}

void PruebadeLista()
{
    Lista miLista;
    PtrDato dato;
    //dato = new char;
    crearLista(miLista, NULL);
    int A = 10;
    dato = &A;
    adicionarPrincipio(miLista, dato);
    PtrNodoLista imprimo = primero(miLista);
    //imprimo directamente
    printf("\nDato guardado: %d\n", *(int*)dato);
    //Lo capturo desde la lista.
    dato = imprimo->ptrDato;
    printf("\nDato guardado desde Lista: %d\n", *(int*)dato);

    //Almacenamos otros dato y probamos
    PtrDato dato2;
    PtrDato dato3;
    int B = 4;
    dato2 = &B;
    adicionarFinal(miLista,dato2);
    int C = 6;
    dato3 = &C;
    adicionarFinal(miLista, dato3);
    //imprimo todos
    PtrNodoLista primerElemento;
    primerElemento = primero(miLista);
    printf("\nDato guardado desde Lista: %d\n", *(int*)(primerElemento->ptrDato));
    PtrNodoLista siguienteElemento;
    siguienteElemento = siguiente(miLista, primerElemento);
    printf("\nDato guardado desde Lista: %d\n", *(int*)(siguienteElemento->ptrDato));
    siguienteElemento = siguiente(miLista,siguienteElemento);
    printf("\nDato guardado desde Lista: %d\n", *(int*)(siguienteElemento->ptrDato));

    system("PAUSE");
}

void PruebadePila()
{
    printf("Prueba de Pila\n");
    Pila miPila;
    PtrDatoPila dato;
    PtrDatoPila datoSacado;
    crearPila(miPila);
    int A = 10;
    dato = &A;
    push(miPila,dato);
    datoSacado = pop(miPila);
    //Imprimo sacado de pila
    printf("\nDato desde la Pila: %d\n", *(int*)datoSacado);
    //Meto varios y vemos que pasa
    if (estaVaciaPila(miPila)){puts("\nPila: Esta Vacia!!\n");}else{puts("\nPila: No esta vacia!\n");}
    int B = 4;
    int C = 2;
    PtrDatoPila dato2;
    PtrDatoPila dato3;
    dato2 = &B;
    dato3 = &C;
    push(miPila, dato2);
    push(miPila, dato3);
    push(miPila, dato);
    if (estaVaciaPila(miPila)){puts("\nPila: Esta Vacia!!\n");}else{puts("\nPila: No esta vacia!\n");}
    //Imprimo sacado de pila y Pruebo el esVacia
    datoSacado = pop(miPila);
    printf("\nDato desde la Pila 1: %d", *(int*)datoSacado);
    if (estaVaciaPila(miPila)){puts("\nPila: Esta Vacia!!\n");}else{puts("\nPila: No esta vacia!\n");}
    datoSacado = pop(miPila);
    printf("\nDato desde la Pila 2: %d", *(int*)datoSacado);
    if (estaVaciaPila(miPila)){puts("\nPila: Esta Vacia!!\n");}else{puts("\nPila: No esta vacia!\n");}
    datoSacado = pop(miPila);
    printf("\nDato desde la Pila 3: %d\n", *(int*)datoSacado);
    if (estaVaciaPila(miPila)){puts("\nPila: Esta Vacia!!\n");}else{puts("\nPila: No esta vacia!\n");}

    system("PAUSE");
}

void PruebaEstructuras()
{
    PtrDato miVoto;
    miVoto = new Voto;

    //Muestro
    printf("\nId: %d", getIdVoto(*(Voto*)miVoto));
    printf("\nIdCandidato: %d", getIdCandidatoVoto(*(Voto*)miVoto));
    if(miVoto== NULL){puts("\nBorrado ok\n");} else {puts("\nSigue ahi\n");}

    setIdVoto(*(Voto*)miVoto, 1);
    setIdCandidatoVoto(*(Voto*)miVoto, 3);
    printf("\nId: %d", getIdVoto(*(Voto*)miVoto));
    printf("\nIdCandidato: %d", getIdCandidatoVoto(*(Voto*)miVoto));
    //Cambio y muestro con get
    if(miVoto == NULL){puts("\nBorrado ok\n");} else {puts("\nSigue ahi\n");}

    setIdVoto(*(Voto*)miVoto, 3);
    setIdCandidatoVoto(*(Voto*)miVoto, 5);
    printf("\nId: %d", getIdVoto(*(Voto*)miVoto));
    printf("\nIdCandidato: %d", getIdCandidatoVoto(*(Voto*)miVoto));
    //destructorVoto(*(Voto*)miVoto);
    //Ver COMPROBAR BORRADOS
    if(miVoto == NULL){puts("\nBorrado ok\n");} else {puts("\nSigue ahi\n");}

    puts("####################################");

    PtrDato miUrna;
    miUrna = new Urna;
    char hora[5];
    strcpy(hora, "10:05");
    setIdUrna(*(Urna*)miUrna, 1);
    setHoraAperturaUrna(*(Urna*)miUrna, hora);
    printf("\nId de Urna: %d", getIdUrna(*(Urna*)miUrna));
    printf("\nHora de Apertura: %s", (getHoraAperturaUrna(*(Urna*)miUrna)));

    system("PAUSE");
}
