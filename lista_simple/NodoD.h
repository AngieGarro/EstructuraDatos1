#pragma once
class NodoD
{
private:
	int dato;
	NodoD* anterior;
	NodoD* siguiente;
public:
	NodoD();
	NodoD(int);

	int getDato();
	NodoD* getAnterior();
	NodoD* getSiguiente();

	void setDato(int);
	void setNodoAnterior(NodoD*);
	void setNodoSiguiente(NodoD*);
};

