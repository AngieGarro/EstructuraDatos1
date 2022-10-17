#include "NodoS.h"
#include <stdlib.h>

NodoS::NodoS(){
	this->dato = 0;
	this->next = nullptr;
}
NodoS::NodoS(int _dato){
	this->dato = _dato;
	this->next = nullptr;
}

int NodoS::getDato() {
	return this->dato;
}

NodoS* NodoS::getNext() {
	return this->next;
}

void NodoS::setDato(int dato) {
	this->dato = dato;
}

void NodoS::setNext(NodoS* ptr) {
	this->next = ptr;
}