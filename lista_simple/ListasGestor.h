#include "DosListas.h";
#include "ListaDobleCircular.h"
#include "ListaDobleLineal.h"
#include <stdlib.h>;
#include "ListaSimple.h";
#pragma once
class ListasGestor
{
private:
	DosListas* ds;

public:
	ListasGestor();
	void procesarOpcionLS(int);
	void procesarOpcionLSL(int);
	void procesarOpcionLSC(int);
	void definirLista1();
	void definirLista2();
	ListaSimple* crearLista();
	void sonIguales();
	void invertirListas();
};
