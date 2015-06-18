#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "Test.h"
#include "Lista.h"

void PruebaDeCola()
{
    printf("Prueba de Cola\n");

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
