#include "ListaDobleGestor.h"
#include <iostream>;
#include <stdlib.h>;
using namespace std;
ListaDobleGestor::ListaDobleGestor()
{
	this->ds = new DosListas();
}

void ListaDobleGestor::procesarOpcion(int opcion)
{
	switch (opcion) {
		case 1:
			this->definirLista1();
			break;
		case 2:
			this->definirLista2();
			break;
		case 3:
			this->sonIguales();
			break;
		case 4:
			this->invertirListas();
			break;
		default:
			break;
	}
}

void ListaDobleGestor::definirLista1()
{
	ListaSimple* ls = this->crearLista();
	this->ds->setL1(ls);
}

void ListaDobleGestor::definirLista2()
{
	ListaSimple* ls = this->crearLista();
	this->ds->setL2(ls);
}

ListaSimple* ListaDobleGestor::crearLista()
{
	ListaSimple* ls = new ListaSimple();
	int opcion;
	do {
		cout << "\n";
		cout << "1 - Agregar numero a la nueva lista \n";
		cout << "2 - Terminar \n";
		cin >> opcion;
		switch (opcion) {
		case 1:
			int numero;
			cout << "Digite su numero: ";
			cin >> numero;
			ls->agregarAlFinal(numero);
			break;
		case 2:
			break;
		default:
			cout << "Digite una opcion correcta \n";
			break;
		}
	} while (opcion != 2);
	return ls;
}

void ListaDobleGestor::sonIguales()
{
	if (this->ds->sonIguales()) {
		cout << "Las listas son iguales";
	}
	else {
		cout << "Las listas no son iguales";
	}
}

void ListaDobleGestor::invertirListas()
{
	this->ds->copiarInversa(this->ds->getL1(), this->ds->getL2());
}
