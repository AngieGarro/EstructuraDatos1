#include "ListaDobleCircular.h"
#include <iostream>
#include <stdlib.h>

using namespace std;
ListaDobleCircular::ListaDobleCircular()
{
	{
		this->cab = NULL;
		this->largo = 0;
	}
}

ListaDobleCircular::~ListaDobleCircular()
{
}

NodoD* ListaDobleCircular::getCab()
{
	return this->cab;
}

int ListaDobleCircular::getLargo()
{
	return this->largo;
}

void ListaDobleCircular::setCab(NodoD* nodo)
{
	this->cab = nodo;
}

void ListaDobleCircular::setLargo(int largo)
{
	this->largo = largo;
}

NodoD* ListaDobleCircular::dirDato(int dato)
{
	if (this->esVacia()) return NULL;
	NodoD* aux = this->getCab();
	NodoD* dir = NULL;
	for (int i = 0; i < getLargo(); i++) {
		if (aux->getDato() == dato) {
			dir = aux;
			break;
		}
		else {
			aux = aux->getSiguiente();
		}
	}
	return dir;
}

NodoD* ListaDobleCircular::dirAnterior(int  dato)
{
	if (this->esVacia()) return NULL;
	NodoD* aux = this->getCab();
	NodoD* dir = NULL;
	for (int i = 0; i < getLargo(); i++) {
		if (aux->getDato() == dato) {
			dir = aux->getAnterior();
			break;
		}
		else {
			aux = aux->getSiguiente();
		}
	}
	return dir;
}

NodoD* ListaDobleCircular::dirAnterior(NodoD* dir)
{
	return dir->getAnterior();
}

NodoD* ListaDobleCircular::dirUltimo()
{
	if (this->esVacia()) return NULL;
	NodoD* aux = this->getCab();
	if (aux->getAnterior() != NULL) {
		return aux;
	}
	else {
		return aux->getAnterior();
	}
}

NodoD* ListaDobleCircular::dirPosicion(int posicion)
{
	if (this->esVacia()) return NULL; // si la lista es vacia devuelve NULL
	if (posicion < 0 || posicion > this->getLargo() - 1) return NULL; // si el usuario envia un valor negativo o una posicion mayor al largo devuelve NULL
	NodoD* dir = NULL;
	NodoD* aux = this->getCab();
	for (int i = 0; i < getLargo(); i++) {
		if (i == posicion) {
			dir = aux;
			break;
		}
		else {
			aux = aux->getSiguiente();
		}
	}
	return dir;
}

int ListaDobleCircular::primero()
{
	if (this->esVacia()) return 0;
	return this->getCab()->getDato();
}

int ListaDobleCircular::ultimo()
{
	NodoD* aux = this->getCab();
	if (aux->getAnterior() != NULL) {
		return aux->getDato();
	}
	else {
		return aux->getAnterior()->getDato();
	}
	return 0;
}

int ListaDobleCircular::datoPos(int posicion)
{
	// La posiciones de la lista las tomare como un arreglo, es decir empezando en 0
	if (this->esVacia()) return 0; // si la lista es vacia devuelve un 0
	if (posicion < 0) return 0; // si el usuario envia un valor negativo devuelve 0
	int dato = 0;
	int posicionActual = 0;
	NodoD* aux;
	aux = this->getCab();
	while (aux != NULL) {
		if (posicion == posicionActual) {
			dato = aux->getDato();
		}
		aux = aux->getSiguiente();
		posicionActual += 1;
	}
	return dato;
	return 0;
}

bool ListaDobleCircular::esVacia()
{
	return this->cab == NULL;
}

bool ListaDobleCircular::existe(int dato)
{
	return this->dirDato(dato) != NULL;
}

void ListaDobleCircular::agregarInicio(int dato)
{
	NodoD* nodoTemporal = new NodoD(dato);
	if (this->esVacia()) {
		this->setCab(nodoTemporal);
		this->setLargo(largo + 1);
	}
	else {
		NodoD* aux = this->getCab();
		nodoTemporal->setNodoSiguiente(aux);
		if (aux->getAnterior() != NULL) {
			nodoTemporal->setNodoAnterior(aux->getAnterior());
			aux->getAnterior()->setNodoSiguiente(nodoTemporal);
		}
		else {
			nodoTemporal->setNodoAnterior(aux);
			aux->setNodoSiguiente(nodoTemporal);
		}
		aux->setNodoAnterior(nodoTemporal);
		this->setCab(nodoTemporal);
		this->setLargo(largo + 1);
	}
}

void ListaDobleCircular::agregarAlFinal(int dato)
{
	NodoD* nodoTemporal = new NodoD(dato);
	if (this->esVacia()) {
		this->setCab(nodoTemporal);
	}
	else {
		NodoD* aux = this->getCab();
		nodoTemporal->setNodoSiguiente(aux);
		if (aux->getAnterior() != NULL) {
			nodoTemporal->setNodoAnterior(aux->getAnterior());
			aux->getAnterior()->setNodoSiguiente(nodoTemporal);
		}
		else {
			nodoTemporal->setNodoAnterior(aux);
			aux->setNodoSiguiente(nodoTemporal);
		}
		aux->setNodoAnterior(nodoTemporal);
	}
	this->setLargo(largo + 1);
}

void ListaDobleCircular::agregarAntesDe(int datoRef, int dato)
{
	NodoD* aux = this->dirDato(datoRef);
	if (aux != NULL) {
		// se que existe
		NodoD* nodoTemporal = new NodoD(dato);
		nodoTemporal->setNodoSiguiente(aux);
		if (aux->getAnterior() != NULL) {
			nodoTemporal->setNodoAnterior(aux->getAnterior());
			aux->getAnterior()->setNodoSiguiente(nodoTemporal);
		}
		else {
			nodoTemporal->setNodoAnterior(aux);
			aux->setNodoSiguiente(nodoTemporal);
		}
		aux->setNodoAnterior(nodoTemporal);
		this->setLargo(largo + 1);
	}

}

void ListaDobleCircular::agregarDespuesDe(int datoRef, int dato)
{
	NodoD* aux = this->dirDato(datoRef);
	if (aux != NULL) {
		NodoD* nodoTemporal = new NodoD(dato);
		nodoTemporal->setNodoAnterior(aux);
		if (aux->getSiguiente() != NULL) {
			nodoTemporal->setNodoSiguiente(aux->getSiguiente());
			aux->getSiguiente()->setNodoAnterior(nodoTemporal);
		}
		else {
			nodoTemporal->setNodoSiguiente(aux);
			aux->setNodoAnterior(nodoTemporal);
		}
		aux->setNodoSiguiente(nodoTemporal);
		this->setLargo(largo + 1);
	}
}

bool ListaDobleCircular::agregarPosicion(int posicion, int dato)
{
	if (this->esVacia() || posicion < 0 || posicion > this->getLargo() - 1) return false;
	bool agregado = false;
	NodoD* aux = this->dirPosicion(posicion);
	
	if (aux != NULL) {
		NodoD* nodoTemporal = new NodoD(dato);
		nodoTemporal->setNodoSiguiente(aux);
		if (aux->getAnterior() != NULL) {
			nodoTemporal->setNodoAnterior(aux->getAnterior());
			aux->getAnterior()->setNodoSiguiente(nodoTemporal);
		}
		else {
			nodoTemporal->setNodoAnterior(aux);
			aux->setNodoSiguiente(nodoTemporal);
		}
		aux->setNodoAnterior(nodoTemporal);

		if (posicion == 0) {
			this->setCab(nodoTemporal);
		}
		setLargo(largo + 1);
		agregado = true;
	}
	return agregado;
}

bool ListaDobleCircular::borrar(int dato)
{
	if (this->esVacia()) return false;
	bool eliminado = false;
	NodoD* aux = this->dirDato(dato);
	if (aux != NULL) {
		if (aux->getAnterior() != NULL && aux->getSiguiente() != NULL) {
			aux->getAnterior()->setNodoSiguiente(aux->getSiguiente());
			aux->getSiguiente()->setNodoAnterior(aux->getAnterior());
			if (this->cab == aux) {
				this->setCab(aux->getSiguiente());
			}
		}
		else {
			this->setCab(NULL);
		}
		delete aux;
		eliminado = false;
		this->setLargo(largo - 1);
	}
	return eliminado;
}

bool ListaDobleCircular::borrarLista()
{
	bool eliminado = false;
	if (!this->esVacia()) {
		NodoD* aux = this->getCab();

		for (int i = 0; i < getLargo(); i++) {
			this->setCab(aux->getSiguiente());
			delete aux;
			aux = this->getCab();
		}
		eliminado = true;
		this->setLargo(0);
	}
	return eliminado;
}

bool ListaDobleCircular::borrarPos(int posicion)
{
	bool eliminado = false;
	NodoD* aux = this->dirPosicion(posicion);
	if (aux != NULL) {
		// valido que el nodo a eliminar no sea el unico nodo en la lista
		if (aux->getAnterior() != NULL && aux->getSiguiente() != NULL) {
			// muevo la cabeza en caso de que el nodo a eliminar sea la cabeza
			if (this->getCab() == aux) {
				this->setCab(aux->getSiguiente());
			}
			// reordeno los nodos vecinos
			aux->getAnterior()->setNodoSiguiente(aux->getSiguiente());
			aux->getSiguiente()->setNodoAnterior(aux->getAnterior());
		}
		else {
			this->setCab(NULL);
		}
		delete aux;
		eliminado = true;
		setLargo(largo - 1);
	}
	return eliminado;
}

void ListaDobleCircular::desplegar()
{
	cout << "LISTA \n" << endl;
	if (!this->esVacia()) {
		NodoD* aux = this->getCab();
		for (int i = 0; i < this->getLargo(); i++)
		{
			cout << aux->getDato() << "<->";
			aux = aux->getSiguiente();
		}
	}
	cout << "Final";
}

void ListaDobleCircular::ordenarAscendente()
{
}

void ListaDobleCircular::eleminarValoresRepetidosConsecutivos()
{
}

void ListaDobleCircular::eliminarValoresRepetidosNoConsecutivos()
{
}

void ListaDobleCircular::agregarNodoCadaDosNodosConsecutivos()
{
	if (this->esVacia()) return;
	if (this->getLargo() > 2) {
		NodoD* aux = this->getCab();
		NodoD* aux2 = aux->getSiguiente();
		for (int i = 0; i < getLargo(); i++) {
			if (aux2 != getCab())
			{
				NodoD* nodoTemporal = new NodoD(aux->getDato() - aux2->getDato());
				nodoTemporal->setNodoAnterior(aux);
				nodoTemporal->setNodoSiguiente(aux2);

				aux->setNodoSiguiente(nodoTemporal);
				aux2->setNodoAnterior(nodoTemporal);


				aux2 = aux2->getSiguiente();
				aux = nodoTemporal->getSiguiente();
				setLargo(getLargo() + 1);
			}
			
		}
	}

}

float ListaDobleCircular::obtenerPromedio()
{
	if (this->esVacia()) return 0.0;
	NodoD* aux = this->getCab();
	int sumatoria = 0;
	for (int i = 0; i < getLargo(); i++) {
		sumatoria = sumatoria + aux->getDato();
		aux = aux->getSiguiente();
	}
	float resultado = sumatoria / getLargo();
	return resultado;
}

void ListaDobleCircular::eliminarValoresEnNodosPares()
{
	if (this->esVacia()) return;
	NodoD* aux = this->getCab();
	int largoActual = getLargo();
	for (int i = 0; i < getLargo(); i++) {
		NodoD* aux2;
		if (i == 0) {
			if (this->getLargo() > 1) {
				this->setCab(aux->getSiguiente());
				aux->getAnterior()->setNodoSiguiente(aux->getSiguiente());
				aux->getSiguiente()->setNodoAnterior(aux->getAnterior());
				aux2 = aux->getSiguiente();
				delete aux;
				aux = aux2;
			}
			else {
				this->setCab(NULL);
				delete aux;
			}
			largoActual = largoActual - 1;
		}
		else {
			if (i % 2 == 0) {
				aux->getAnterior()->setNodoSiguiente(aux->getSiguiente());
				aux->getSiguiente()->setNodoAnterior(aux->getAnterior());
				aux2 = aux->getSiguiente();
				delete aux;
				aux = aux2;
				largoActual = largoActual - 1;
			}
			else {
				aux = aux->getSiguiente();
			}
		}
	}
	setLargo(largoActual);
}
