#include "ListaDobleLineal.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

ListaDobleLineal::ListaDobleLineal()
{
    this->cab = NULL;
    this->largo = 0;
}

ListaDobleLineal::~ListaDobleLineal()
{
    this->cab = NULL;
    this->largo = 0;
}

NodoD* ListaDobleLineal::getCab()
{
    return this->cab;
}

int ListaDobleLineal::getLargo()
{
    return this->largo;
}

void ListaDobleLineal::setCab(NodoD* nodoD)
{
    this->cab = nodoD;
}

void ListaDobleLineal::setLargo(int largo)
{
    this->largo = largo;
}

NodoD* ListaDobleLineal::dirDato(int dato)
{
    // Devuelve la direccion donde se ubica un dato
    NodoD* dir = NULL;
    NodoD* aux = this->getCab();
    while (aux != NULL && dir == NULL) {
        if (aux->getDato() == dato) {
            dir = aux;
        }
        else {
            aux = aux->getSiguiente();
        }
    }
    return dir;
}

NodoD* ListaDobleLineal::dirAnterior(int dato)
{
    if (this->esVacia()) return NULL;
    NodoD* dir = NULL;
    NodoD* aux = this->getCab();
    while (aux != NULL && aux->getSiguiente() != NULL && dir == NULL) {
        if (aux->getSiguiente()->getDato() == dato) {
            dir = aux;
        }
        else {
            aux = aux->getSiguiente();
        }
    }
    return dir;
}

NodoD* ListaDobleLineal::dirAnterior(NodoD* nodoD)
{
    return nodoD->getAnterior();
}

NodoD* ListaDobleLineal::dirPosicion(int posicion)
{
    if (this->esVacia()) return NULL; // si la lista es vacia devuelve NULL
    if (posicion < 0 || posicion > this->getLargo() - 1) return NULL; // si el usuario envia un valor negativo o una posicion mayor al largo devuelve NULL
    NodoD* dir = NULL;
    int posicionActual = 0;
    NodoD* aux;
    aux = this->getCab();
    while (aux != NULL && dir == NULL) {
        if (posicion == posicionActual) {
            dir = aux;
        }
        aux = aux->getSiguiente();
        posicionActual += 1;
    }
    return dir;
}

NodoD* ListaDobleLineal::dirUltimo()
{
    // revisa que la lista no esta vacia
    if (this->esVacia()) return NULL;
    NodoD* aux = this->getCab();
    NodoD* dir = NULL;
    while (aux != NULL) {
        if (aux->getSiguiente() == NULL) {
            dir = aux;
        }
        aux = aux->getSiguiente();
    }
    return dir;
}

int ListaDobleLineal::primero()
{
    if (this->esVacia()) return 0; // retorna 0 si la lista esta vacia 
    return this->getCab()->getDato();
}

int ListaDobleLineal::ultimo()
{
    if (this->esVacia()) return 0; // retorna 0 si la lista esta vacia
    NodoD* aux;
    aux = this->getCab();
    int dato = 0;
    while (aux != NULL) {
        if (aux->getSiguiente() == NULL) { // revisa si es el ultimo elemento de la lista
            dato = aux->getDato();
        }
        aux = aux->getSiguiente();
    }
    return dato;
}

int ListaDobleLineal::datoPos(int posicion)
{
    // La posiciones de la lista las tomare como un arreglo, es decir empezando en 0
    if (this->esVacia()) return 0; // si la lista es vacia devuelve un 0
    if (posicion < 0) return 0; // si el usuario envia un valor negativo devuelve 0
    int dato = 0;
    int posicionActual = 0;
    NodoD* aux;
    aux = this->getCab();
    while (aux != NULL) {
        if (posicion == posicionActual) {
            dato = aux->getDato();
        }
        aux = aux->getSiguiente();
        posicionActual += 1;
    }
    return dato;
}

bool ListaDobleLineal::esVacia()
{
    return this->cab == NULL;
}

bool ListaDobleLineal::existe(int dato)
{
    return this->dirDato(dato) != NULL;
}

void ListaDobleLineal::agregarInicio(int dato)
{
    // agrega _dato al inicio de la lista.
    NodoD* nuevo = new NodoD(dato); //Paso 1. Crear el nodo
    nuevo->setNodoSiguiente(getCab()); //Paso 2. Enlazar el nuevo nodo a la lista
    //Paso 3 Reacomodar la lista con el nuevo nodo
    if (!esVacia()) {
        getCab()->setNodoAnterior(nuevo);
    }
    setCab(nuevo);
    setLargo(getLargo() + 1);

}

void ListaDobleLineal::agregarAlFinal(int dato)
{
    if (this->esVacia()) {
        agregarInicio(dato);
    }
    else {
        NodoD* nodoTemp = new NodoD(dato);
        NodoD* nodoUltimo = this->dirUltimo();
        nodoUltimo->setNodoSiguiente(nodoTemp);
        nodoTemp->setNodoAnterior(nodoUltimo);
    }
    setLargo(getLargo() + 1);
}

void ListaDobleLineal::agregarAntesDe(int datoRef, int datoNuevo)
{
    if (getCab()->getDato() == datoNuevo) {
        agregarInicio(datoNuevo);
    }
    else
    {
        NodoD* aux = this->dirDato(datoRef);
        if (aux != NULL) {
            NodoD* nuevo = new NodoD(datoNuevo);//Paso 1. Crear el nodo
            //Paso 2. Enlazar el nuevo nodo a la lista O sea guindar el nodo....
            nuevo->setNodoSiguiente(aux);
            nuevo->setNodoAnterior(aux->getAnterior());

            //Paso 3. Reacomodar la lista con el nuevo nodo. Recuede el orden....
            aux->getAnterior()->setNodoSiguiente(nuevo);
            aux->setNodoAnterior(nuevo);
            setLargo(getLargo() + 1);
        }
    }
}

void ListaDobleLineal::agregarDespuesDe(int datoRef, int dato)
{
    if (!this->esVacia()) {
        NodoD* aux = this->dirDato(datoRef);
        if (aux != NULL) {
            NodoD* nodoTemporal = new NodoD(dato);
            nodoTemporal->setNodoAnterior(aux);
            if (aux->getSiguiente() != NULL) {
                aux->getSiguiente()->setNodoAnterior(nodoTemporal);
                nodoTemporal->setNodoSiguiente(aux->getSiguiente());
            }
            aux->setNodoSiguiente(nodoTemporal);
            setLargo(getLargo() + 1);
        }
    }
}

bool ListaDobleLineal::agregarPosicion(int posicion, int dato)
{
    // Agregar validaciones de longitud de la posicion
    bool agregado = false;
    if (!this->esVacia()) 
    {
        NodoD* aux = this->dirPosicion(posicion);
        if (aux != NULL) {
            NodoD* nodoTemporal = new NodoD(dato);
            if (posicion == 0) {
                this->setCab(nodoTemporal);
            }
            if (aux->getAnterior() != NULL) {
                nodoTemporal->setNodoAnterior(aux->getAnterior());
                aux->getAnterior()->setNodoSiguiente(nodoTemporal);
            }
            aux->setNodoAnterior(nodoTemporal);
            nodoTemporal->setNodoSiguiente(aux);
            agregado = true;
            setLargo(getLargo() + 1);
        }
    }
    return agregado;
}

bool ListaDobleLineal::borrar(int dato)
{
    if (this->esVacia()) return false;
    bool eliminado = false;
    NodoD* aux = this->getCab();
    if (aux->getDato() == dato) {
        this->setCab(aux->getSiguiente());
        delete aux;
        this->setLargo(this->getLargo() - 1);
    }
    else {
        while (aux != NULL) {
            if (aux->getDato() == dato) {
                aux->getAnterior()->setNodoSiguiente(aux->getSiguiente());
                if (aux->getSiguiente() != NULL) {
                    aux->getSiguiente()->setNodoAnterior(aux->getAnterior());
                }
                delete aux;
                aux = NULL;
                eliminado = true;
                this->setLargo(this->getLargo() - 1);
            }
            else {
                aux = aux->getSiguiente();
            }
        }
    }
    return eliminado;
}

bool ListaDobleLineal::borrarLista()
{
    bool eliminado = false;
    if (!this->esVacia()) {
        NodoD* aux = this->getCab();
        while (aux != NULL) {
            this->setCab(aux->getSiguiente());
            delete aux;
            aux = this->getCab();
        };
        eliminado = true;
        this->setLargo(0);
    }
    return eliminado;
}

bool ListaDobleLineal::borrarPos(int posicion) 
{
    bool eliminado = false;
    NodoD* aux = this->dirPosicion(posicion);
    if (aux != NULL) {
        // moviendo la cabeza en caso de que el aux sea la cabeza
        if (this->getCab() == aux) {
            this->setCab(aux->getSiguiente());
            aux->getSiguiente()->setNodoAnterior(NULL);
        }
        else {
            aux->getAnterior()->setNodoSiguiente(aux->getSiguiente());
            if (aux->getSiguiente() != NULL) {
                aux->getSiguiente()->setNodoAnterior(aux->getAnterior());
            }
        }
        delete aux;
        eliminado = true;
        this->setLargo(largo - 1);
    }
    return eliminado;
}

void ListaDobleLineal::desplegar()
{
    NodoD* aux = this->getCab();
    cout << "LISTA \n" << endl;
    while (aux != NULL) {
        cout << aux->getDato() << "->";
        aux = aux->getSiguiente();
    }
    cout << "Final";
}

void ListaDobleLineal::ordenarAscendente()
{
}

void ListaDobleLineal::eleminarValoresRepetidosConsecutivos()
{
}

void ListaDobleLineal::eliminarValoresRepetidosNoConsecutivos()
{
}

NodoD* ListaDobleLineal::obtenerPosicionCardinal(int posicion)
{
    if (posicion < 0 || posicion > this->getLargo() - 1 || this->esVacia()) return NULL;
    NodoD* aux = this->getCab();
    NodoD* dir = NULL;
    for (int i = 0; i < getLargo(); i++)
    {
        if (i == posicion) {
            dir = aux;
            break;
        }
        else {
            aux = aux->getSiguiente();
        }
    }
    return dir;
}

int ListaDobleLineal::obtenerMayor()
{
    if (this->esVacia()) return 0;
    NodoD* aux = this->getCab();
    int valorMayor = 0;
    while (aux != NULL) {
        if (aux->getDato() > valorMayor) {
            valorMayor = aux->getDato();
        }
        aux = aux->getSiguiente();
    }
    return valorMayor;
}

void ListaDobleLineal::eliminarPosicionCardinal(int posicion)
{
    if (this->esVacia() || posicion < 0 || posicion > getLargo() -1) return;
    NodoD* aux = this->obtenerPosicionCardinal(posicion);
    if (aux != NULL) {
        
        // es la cabeza
        if (posicion == 0) {
            this->setCab(aux->getSiguiente());
        }
        if (aux->getAnterior() != NULL) {
            aux->getAnterior()->setNodoSiguiente(aux->getSiguiente());
        }
        if (aux->getSiguiente() != NULL) {
            aux->getSiguiente()->setNodoAnterior(aux->getAnterior());
        }
    }
}
