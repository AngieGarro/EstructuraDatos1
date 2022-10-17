#pragma once
#include "ListaSimple.h"
#include <stdlib.h>


class DosListas
{
private:
	ListaSimple* L1; //Primera lista.
	ListaSimple* L2; //Segunda lista.

public:
	DosListas();
	ListaSimple* getL1();
	ListaSimple* getL2();

	void setL1(ListaSimple*);
	void setL2(ListaSimple*);

	bool sonIguales();

	void copiarInversa(ListaSimple*, ListaSimple*);
};