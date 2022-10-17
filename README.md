# EstructuraDeDatos-1
Programación de Estructuras de Datos 1 en lenguaje de programación de C++
CONTENIDO DEL REPOSITORIO:

IMPLEMENTACIÓN DE LISTAS
- Listas Simples.

		// operaciones micelaneas
		NodoS* dirDato(int) // Direccion del nodo cuyo dato es el referenciado
		NodoS* dirAnteriorDato(int) //Direccion del nodo anterior al nodo cuyo valor sea el referenciado
		NodoS* dirAnterior(NodoS*) // Direccion del nodo anterior del nodo de la direccion referenciada
		NodoS* dirUltimo() // Direccion del ultimo nodo

		// TDA de la lista
		int primero() // dato primero de la lista
		int ultimo() // dato ultimo de la lista
		int datoPos(int) // retornar el dato en la posicion de referencia
		bool esVacia() // retorna verdadero si la lista esta vacia
		bool existe(int) // retorna verdadero si un valor existe en la lista

		// operaciones de agregar
		void agregarInicio(int) // agrega un nodo al inicio
		void agregarAlFinal(int) // agrega al final
		bool agregarAntesDe(int, int) // agrega un nodo antes de un indice
		bool agregarDespuesDe(int, int) // agrega despues de un indice
		bool agregarPosicion(int, int)

		// operaciones de borrar

		bool borrar(int) // eliminar el nodo cuyo valor sea el entero de entrada
		bool borrarLista() // vacia toda la lista
		bool borrarPos(int) // eliminar el nodo que se ubica en la posicion de referencia

		// operaciones de desplegar
		void desplegar()

		// operaciones de ordenamiento
		void ordenarAscendente() // ordena ascendente
		
		// eliminar valores repetidos
		void eleminarValoresRepetidosConsecutivos()
		void eliminarValoresRepetidosNoConsecutivos()
    
- Listas Doble Lineal.

  	int primero()
	int ultimo()
	int datoPos(int)
	bool esVacia()
	bool existe(int)

	void agregarInicio(int)
	void agregarAlFinal(int)
	void agregarAntesDe(int, int)
	void agregarDespuesDe(int, int)
	bool agregarPosicion(int, int)

	bool borrar(int) // eliminar el nodo cuyo valor sea el entero de entrada
	bool borrarLista() // vacia toda la lista
	bool borrarPos(int) // eliminar el nodo que se ubica en la posicion de referencia

	// operaciones de desplegar
	void desplegar()

	// operaciones de ordenamiento
	void ordenarAscendente() // ordena ascendente

	// eliminar valores repetidos
	void eleminarValoresRepetidosConsecutivos()
	void eliminarValoresRepetidosNoConsecutivos()

	NodoD* obtenerPosicionCardinal(int)
	int obtenerMayor()
	void eliminarPosicionCardinal(int)
  
- Listas Doble Circular.

  	int primero()
	int ultimo()
	int datoPos(int)
	bool esVacia()
	bool existe(int)

	void agregarInicio(int)
	void agregarAlFinal(int)
	void agregarAntesDe(int, int)
	void agregarDespuesDe(int, int)
	bool agregarPosicion(int, int)

	bool borrar(int) // eliminar el nodo cuyo valor sea el entero de entrada
	bool borrarLista() // vacia toda la lista
	bool borrarPos(int) // eliminar el nodo que se ubica en la posicion de referencia

	// operaciones de desplegar
	void desplegar()

	// operaciones de ordenamiento
	void ordenarAscendente() // ordena ascendente

	// eliminar valores repetidos
	void eleminarValoresRepetidosConsecutivos()
	void eliminarValoresRepetidosNoConsecutivos()

	void agregarNodoCadaDosNodosConsecutivos()
	float obtenerPromedio()
	void eliminarValoresEnNodosPares()
