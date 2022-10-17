#pragma once
class NodoS
{
	private:
		int dato;
		NodoS* next; // el puntero al siguiente nodo
	public:
		NodoS();
		NodoS(int);

		int getDato();
		NodoS* getNext();

		void setDato(int);
		void setNext(NodoS*);
};
