#include "NodoD.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

NodoD::NodoD()
{
    this->dato = 0;
    this->anterior = NULL;
    this->siguiente = NULL;
}

NodoD::NodoD(int dato)
{
    this->dato = dato;
    this->anterior = NULL;
    this->siguiente = NULL;
}

int NodoD::getDato()
{
    return this->dato;
}

NodoD* NodoD::getAnterior()
{
    return this->anterior;
}

NodoD* NodoD::getSiguiente()
{
    return this->siguiente;
}

void NodoD::setDato(int dato)
{
    this->dato = dato;
}

void NodoD::setNodoAnterior(NodoD* nodoD)
{
    this->anterior = nodoD;
}

void NodoD::setNodoSiguiente(NodoD* nodoD)
{
    this->siguiente = nodoD;
}
