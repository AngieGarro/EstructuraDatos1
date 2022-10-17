#pragma once
#include "DosListas.h";
#include <stdlib.h>;
#include "ListaSimple.h";
class ListaDobleGestor
{
private:
	DosListas* ds;

public:
	ListaDobleGestor();
	void procesarOpcion(int);
	void definirLista1();
	void definirLista2();
	ListaSimple* crearLista();
	void sonIguales();
	void invertirListas();
};

