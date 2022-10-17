#pragma once
#include "NodoS.h"; // cuando usamos comillas dobles, c++ entiende que estas buscando las clases dentro del proyecto
#include <stdlib.h>
class ListaSimple
{
	private:
	NodoS* cab;  // puntero cabeza de la lista
	int largo; // cantidad de nodos de la lista

	public:
		ListaSimple(); // constructor default
		~ListaSimple();

		ListaSimple* serieFibonacci(int);

		NodoS* getCab(); // obtiene el valora de la cabeza
		int getLargo(); // obtiene el largo de la lista

		void setCab(NodoS*); // modifica la cabeza de la lista
		void setLargo(int); // modifica el largo de la lista
		
		// operaciones micelaneas
		NodoS* dirDato(int); // Direccion del nodo cuyo dato es el referenciado
		NodoS* dirAnteriorDato(int); //Direccion del nodo anterior al nodo cuyo valor sea el referenciado
		NodoS* dirAnterior(NodoS*); // Direccion del nodo anterior del nodo de la direccion referenciada
		NodoS* dirUltimo(); // Direccion del ultimo nodo

		// TDA de la lista
		int primero(); // dato primero de la lista
		int ultimo(); // dato ultimo de la lista
		int datoPos(int); // retornar el dato en la posicion de referencia
		bool esVacia(); // retorna verdadero si la lista esta vacia
		bool existe(int); // retorna verdadero si un valor existe en la lista

		// operaciones de agregar
		void agregarInicio(int); // agrega un nodo al inicio
		void agregarAlFinal(int); // agrega al final
		bool agregarAntesDe(int, int); // agrega un nodo antes de un indice
		bool agregarDespuesDe(int, int); // agrega despues de un indice
		bool agregarPosicion(int, int);

		// operaciones de borrar

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

};

