#include "ListaSimple.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

ListaSimple::ListaSimple() {
	this->cab = NULL;
	this->largo = 0;
}

ListaSimple::~ListaSimple()
{
	this->cab = NULL;
	this->largo = 0;
}

ListaSimple* ListaSimple::serieFibonacci(int n)
{
	if (n < 1) return NULL;
	ListaSimple* serieFibonacci = new ListaSimple();
	NodoS* aux1 = new NodoS(0);
	serieFibonacci->setCab(aux1);
	// Si n es mayor a 1 le agrega el segundo valor del fibonacci "1"
	if (n > 1) {
		NodoS* aux2 = new NodoS(1);
		aux1->setNext(aux2);
		// le resto 2 a n para no iterar por los numeros 0 y 1. De esta manera devuelvo la cantidad correcta de numeros del fibonacci
		int nodos = n - 2;
		for (int i = 0; i < nodos; i++) {
			int nuevoValor = aux1->getDato() + aux2->getDato();
			NodoS* nodoTemporal = new NodoS(nuevoValor);
			aux2->setNext(nodoTemporal);
			aux1 = aux1->getNext();
			aux2 = aux2->getNext();
		}
	}
	return serieFibonacci;
}

NodoS* ListaSimple::getCab() {
	return this->cab;
}

int ListaSimple::getLargo() {
	return this->largo;
}

void ListaSimple::setCab(NodoS* ptr) {
	this->cab = ptr;
}

void ListaSimple::setLargo(int n) {
	this->largo = n;
}

NodoS* ListaSimple::dirDato(int dato)
{	
	// Devuelve la direccion donde se ubica un dato
	NodoS* dir = NULL;
	NodoS* aux = this->getCab();
	while (aux != NULL && dir == NULL) {
		if (aux->getDato() == dato) {
			dir = aux;
		}
		else {
			aux = aux->getNext();
		}
	}
	return dir;
}

NodoS* ListaSimple::dirAnteriorDato(int dato)
{	// Direccion anterior del nodo anterior en que se ubica el _dato
	if (this->esVacia()) return NULL;
	NodoS* dir = NULL;
	NodoS* aux = this->getCab();
	while (aux != NULL && aux->getNext() != NULL && dir == NULL) {
		if (aux->getNext()->getDato() == dato) {
			dir = aux;
		} else {
			aux = aux->getNext();
		}
	}
	return dir;
}

NodoS* ListaSimple::dirAnterior(NodoS* nodo)
{	
	if (this->esVacia()) return NULL;
	NodoS* dir = NULL;
	NodoS* aux = this->getCab();
	cout << nodo->getDato();
	while (aux != NULL && dir == NULL) {
		if (aux->getNext()->getDato() == nodo->getDato()) {
			dir = aux;
		}
		aux = aux->getNext();
		
	}
	return dir;
}

NodoS* ListaSimple::dirUltimo()
{
	// revisa que la lista no esta vacia
	if (this->esVacia()) return NULL;
	NodoS* aux = this->getCab();
	NodoS* dir = NULL;
	while (aux != NULL) {
		if (aux->getNext() == NULL) {
			dir = aux;
		}
		aux = aux->getNext();
	}
	return dir;
}

int ListaSimple::primero()
{	
	if (this->esVacia()) return 0; // retorna 0 si la lista esta vacia 
	return this->getCab()->getDato();
}

int ListaSimple::ultimo()
{
	if (this->esVacia()) return 0; // retorna 0 si la lista esta vacia
	NodoS* aux;
	aux = this->getCab();
	int dato = 0;
	while (aux != NULL) {
		if (aux->getNext() == NULL) { // revisa si es el ultimo elemento de la lista
			dato = aux->getDato();
		}
		aux = aux->getNext();
	}
	return dato;
}

int ListaSimple::datoPos(int posicion)
{
	// La posiciones de la lista las tomare como un arreglo, es decir empezando en 0
	if (this->esVacia()) return 0; // si la lista es vacia devuelve un 0
	if (posicion < 0) return 0; // si el usuario envia un valor negativo devuelve 0
	int dato = 0;
	int posicionActual = 0;
	NodoS* aux;
	aux = this->getCab();
	while (aux != NULL) {
		if (posicion == posicionActual) {
			dato = aux->getDato();
		}
		aux = aux->getNext();
		posicionActual += 1;
	}
	return dato;
}

bool ListaSimple::esVacia()
{
	return this->cab == NULL;
}

bool ListaSimple::existe(int dato)
{	
	return this->dirDato(dato) != NULL;
}

void ListaSimple::agregarInicio(int _dato)
{
	// Crea un nuevo nodo con el dato y se colo al inicio de la lista
	// Enlazarel nuevo nodo a la lista
	// Racomodar la lista con el nuevo nodo
	
	NodoS* nodoTemp = new NodoS(_dato); // Paso 1
	nodoTemp->setNext(this->getCab()); // Paso 2
	this->setCab(nodoTemp); // Paso 3
	setLargo(this->getLargo() + 1);
}

void ListaSimple::agregarAlFinal(int _dato)
{
	if (this->esVacia()) {
		this->agregarInicio(_dato);
	} else {
		NodoS* nodoTemp = new NodoS(_dato);
		NodoS* nodoUltimo = this->dirUltimo();
		if (nodoUltimo != NULL) {
			nodoUltimo->setNext(nodoTemp);
		}
	}
}

bool ListaSimple::agregarAntesDe(int _ref, int _dato)
{
	bool agregado = false;
	if (!this->esVacia()) { // valida que la lista no sea vacia
		if (getCab()->getDato() == _ref) { // valida que el indice de referencia no este en la primera posicion de la lista
			agregarInicio(_dato);
			agregado = true;
		} else {
			NodoS* ant = dirAnteriorDato(_ref); //  llama a dir anterior dato
			if (ant != NULL) { // valida que tengamos una direccion anterior
				NodoS* temp = new NodoS(_dato); // crea el dato temporal
				temp->setNext(ant->getNext()); // enlaza el nodo temporal al nodo siguiente
				ant->setNext(temp); // enlaza el nodo anterior con el nodo temporal
				agregado = true;
			}
		}
	}
	return false;
}

bool ListaSimple::agregarDespuesDe(int _ref, int _dato)
{
	// crear el nodo temporal
	// buscar el dato dentro de la lista y obtener la posicion del dato
	// hacer que el nodo temporal apunte al mismo elemento que apunta el nodo del dato
	// hacer que el nodo que tiene el dato apunte al nodo que acabamos de crear
	bool agregado = false;
	if (!this->esVacia()) {
		NodoS* nodoDato= this->dirDato(_ref);
		NodoS* nodoTemp = new NodoS(_dato);
		if (nodoDato != NULL) {
			nodoTemp->setNext(nodoDato->getNext());
			nodoDato->setNext(nodoTemp);
			agregado = true;
		}
	}
	return agregado;
}

bool ListaSimple::agregarPosicion(int, int)
{
	return false;
}

bool ListaSimple::borrar(int _dato)
{	
	bool eliminado = false;
	if (!this->esVacia()) {
		NodoS* aux = this->getCab();
		if (aux->getDato() == _dato) {
			this->setCab(aux->getNext());
			delete aux;
		}
		else {
			while (aux != NULL) {
				if (aux->getDato() == _dato) {
					NodoS* nodoAnterior = this->dirAnterior(aux);
					nodoAnterior->setNext(aux->getNext());
					delete aux;
					aux = NULL;
					eliminado = true;
				}
				else {
					aux = aux->getNext();
				}
			}
		}
	}
	return eliminado;
}

bool ListaSimple::borrarLista()
{
	bool eliminado = false;
	if (!this->esVacia()) {
		NodoS* aux = this->getCab();
		while (aux != NULL) {
			this->setCab(aux->getNext());
			delete aux;
			aux = this->getCab();
		};
		eliminado = true;
	}
	return eliminado;
}

bool ListaSimple::borrarPos(int)
{
	return false;
}

void ListaSimple::desplegar()
{
	NodoS* aux = getCab();
	cout << "LISTA \n" << endl;
	while (aux != NULL) {
		cout << aux->getDato() << "->";
		aux = aux->getNext();
	}
	cout << "Final";
}

void ListaSimple::ordenarAscendente()
{
}

void ListaSimple::eleminarValoresRepetidosConsecutivos()
{
	NodoS* ant = this->getCab();
	while (ant->getNext() != NULL) {
		if (ant->getDato() == ant->getNext()->getDato()) {
			NodoS* aux = ant->getNext();
			ant->setNext(aux->getNext());
			delete aux;
		}
		else {
			ant = ant->getNext();
		}
	}
}

void ListaSimple::eliminarValoresRepetidosNoConsecutivos()
{
	NodoS* aux = this->getCab();
	NodoS* ant = this->getCab();
	
	while (aux->getNext() != NULL) {
		while (ant->getNext() != NULL) {
			if (ant->getDato() == aux->getNext()->getDato()) {
				NodoS* nodoAEliminar = ant->getNext();
				ant->setNext(nodoAEliminar->getNext());
				delete nodoAEliminar;
			}
			else {
				ant = ant->getNext();
			}
		}
		aux = aux->getNext();
	}
}
