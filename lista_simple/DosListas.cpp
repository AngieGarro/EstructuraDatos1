#include "DosListas.h"
#include <stdlib.h>;
#include <iostream>;

using namespace std;

DosListas::DosListas()
{
	L1 = new ListaSimple;
	L2 = new ListaSimple;
}

ListaSimple* DosListas::getL1()
{
	return this->L1;
}

ListaSimple* DosListas::getL2()
{
	return this->L2;
}

void DosListas::setL1(ListaSimple* lista)
{
	this->L1 = lista;
}

void DosListas::setL2(ListaSimple* lista)
{
	this->L2 = lista;
}

bool DosListas::sonIguales()
{
	bool iguales = true;
	if (L1->getLargo() == L2->getLargo()) {
		NodoS* aux1 = L1->getCab();
		NodoS* aux2 = L2->getCab();
		while (aux1 != NULL && iguales) {
			if (aux1->getDato() != aux2->getDato()) {
				iguales = false;
			}
			else {
				aux1 = aux1->getNext();
				aux2 = aux2->getNext();
			}
		}

	}
	else {
		iguales = false;
	}
	return iguales;
}

void DosListas::copiarInversa(ListaSimple* L1, ListaSimple* L2)
{
	NodoS* aux = L1->getCab();
	if (!L1->esVacia() && L2->esVacia())
	{
		while (aux != NULL)
		{
			L2->agregarInicio(aux->getDato());
			aux = aux->getNext();
		}

		L1->desplegar();
		L2->desplegar();
		L2->borrarLista();
	}
	else {
		cout << "Las listas estan vacias";
	}
}
