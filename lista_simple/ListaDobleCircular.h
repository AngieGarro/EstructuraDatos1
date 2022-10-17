#include "NodoD.h";

#pragma once
class ListaDobleCircular
{
private:
	NodoD* cab;
	int largo;

public:
	ListaDobleCircular();
	~ListaDobleCircular();

	NodoD* getCab();
	int getLargo();

	void setCab(NodoD*);
	void setLargo(int);

	NodoD* dirDato(int);
	NodoD* dirAnterior(int);
	NodoD* dirAnterior(NodoD*);
	NodoD* dirUltimo();
	NodoD* dirPosicion(int posicion);


	int primero();
	int ultimo();
	int datoPos(int);
	bool esVacia();
	bool existe(int);

	void agregarInicio(int);
	void agregarAlFinal(int);
	void agregarAntesDe(int, int);
	void agregarDespuesDe(int, int);
	bool agregarPosicion(int, int);

	bool borrar(int); // eliminar el nodo cuyo valor sea el entero de entrada
	bool borrarLista(); // vacia toda la lista
	bool borrarPos(int); // eliminar el nodo que se ubica en la posicion de referencia

	// operaciones de desplegar
	void desplegar();

	// operaciones de ordenamiento
	void ordenarAscendente(); // ordena ascendente

	// eliminar valores repetidos
	void eleminarValoresRepetidosConsecutivos();
	void eliminarValoresRepetidosNoConsecutivos();

	void agregarNodoCadaDosNodosConsecutivos();
	float obtenerPromedio();
	void eliminarValoresEnNodosPares();
};

