#include "ListasGestor.h"
#include "ListaDobleCircular.h"
#include "ListaDobleLineal.h"
#include "ListaSimple.h";
#include <iostream>;
#include <stdlib.h>;
using namespace std;

ListasGestor::ListasGestor()
{
    this->ds = new DosListas();
}


void ListasGestor::procesarOpcionLS(int opcion)
{
    ListaSimple* LS = new ListaSimple();
    int num, num1;
    switch (opcion) {
    case 1:
        cout << LS->getCab();
        break;
    case 2:
        cout << LS->getLargo();
        break;
    case 3:
        cin >> num;
        LS->setLargo(num);
        break;
    case 4:
        cout << "Nodo: ";
        cin >> num;
        cout << LS->dirDato(num);
        break;
    case 5:
        cout << "Nodo: ";
        cin >> num;
        cout << LS->dirAnteriorDato(num);
        break;
    case 6:
        cin >> num;
        { NodoS* nodo1 = new NodoS(num);
        cout << LS->dirAnterior(nodo1); }
        break;
    case 7:
        cout << LS->dirUltimo();
        break;
    case 8:
        cout << LS->primero();
        break;
    case 9:
        cout << LS->ultimo();
        break;
    case 10:
        cout << "Posicion: ";
        cin >> num;
        cout << LS->datoPos(num);
        break;
    case 11:
        cout << LS->esVacia();
        break;
    case 12:
        cout << "Valor: ";
        cin >> num;
        cout << LS->existe(num);
        break;
    case 13:
        cout << "Nodo: ";
        cin >> num;
        LS->agregarInicio(num);
        break;
    case 14:
        cout << "Nodo: ";
        cin >> num;
        LS->agregarAlFinal(num);
        break;
    case 15:
        cout << "Nodo: ";
        cin >> num;
        cout << "Indice: ";
        cin >> num1;
        cout << LS->agregarAntesDe(num, num1);
        break;
    case 16:
        cout << "Nodo: ";
        cin >> num;
        cout << "Indice: ";
        cin >> num1;
        cout << LS->agregarDespuesDe(num, num1);
        break;
    case 17:
        LS->desplegar();
        break;
    case 18:
        LS->borrarLista();
        break;
    case 19:
        cout << "Valor: ";
        cin >> num;
        LS->borrar(num);
        break;
    case 20:
        LS->eleminarValoresRepetidosConsecutivos();
        break;
    case 21:
        LS->eliminarValoresRepetidosNoConsecutivos();
        break;
    case 22:
        cout << "gracias por usar el sistema";
        break;
    default:
        cout << "Opcion invalida";
        break;

    }
}

void ListasGestor::procesarOpcionLSL(int opcion)
{
    ListaDobleLineal* LD = new ListaDobleLineal();
    int num, num1;
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
    case 5:
        cout << LD->getCab();
        break;
    case 6:
        cout << LD->getLargo();
        break;
    case 7:
        cin >> num;
        LD->setLargo(num);
        break;
    case 8:
        cout << "Nodo: ";
        cin >> num;
        LD->dirDato(num);
        break;
    case 9:
        cout << "Nodo: ";
        cin >> num;
        cout << LD->dirAnterior(num);
        break;
    case 10:
        cin >> num;
        { NodoD* nodo1 = new NodoD(num);
        cout << LD->dirAnterior(nodo1); }
        break;
    case 11:
        cout << LD->dirUltimo();
        break;
    case 12:
        LD->primero();
        break;
    case 13:
        LD->ultimo();
        break;
    case 14:
        cout << "Posicion: ";
        cin >> num;
        LD->datoPos(num);
        break;
    case 15:
        LD->esVacia();
        break;
    case 16:
        cout << "Valor: ";
        cin >> num;
        LD->existe(num);
        break;
    case 17:
        cout << "Nodo: ";
        cin >> num;
        LD->agregarInicio(num);
        break;
    case 18:
        cout << "Nodo: ";
        cin >> num;
        LD->agregarAlFinal(num);
        break;
    case 19:
        cout << "Nodo: ";
        cin >> num;
        cout << "Indice: ";
        cin >> num1;
        LD->agregarAntesDe(num, num1);
        break;
    case 20:
        cout << "Nodo: ";
        cin >> num;
        cout << "Indice: ";
        cin >> num1;
        LD->agregarDespuesDe(num, num1);
        break;
    case 21:
        LD->desplegar();
        break;
    case 22:
        LD->borrarLista();
        break;
    case 23:
        cout << "Valor: ";
        cin >> num;
        LD->borrar(num);
        break;
    case 24:
        cout << "Posición: ";
        cin >> num;
        cout << LD->obtenerPosicionCardinal(num);
        break;
    case 25:
        cout << LD->obtenerMayor();
        break;
    case 26:
        cout << "Posición: ";
        cin >> num;
        LD->eliminarPosicionCardinal(num);
        break;
    case 29:
        cout << "gracias por usar el sistema";
        break;
    default:
        cout << "Opcion invalida";
        break;
    }
}

void ListasGestor::procesarOpcionLSC(int opcion)
{
    ListaDobleCircular* LDC = new ListaDobleCircular();
    int num, num1;
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
    case 5:
        cout << LDC->getCab();
        break;
    case 6:
        cout << LDC->getLargo();
        break;
    case 7:
        cin >> num;
        LDC->setLargo(num);
        break;
    case 8:
        cout << "Nodo: ";
        cin >> num;
        LDC->dirDato(num);
        break;
    case 9:
        cout << "Nodo: ";
        cin >> num;
        LDC->dirAnterior(num);
        break;
    case 10:
        cin >> num;
        { NodoD* nodo1 = new NodoD(num);
        LDC->dirAnterior(nodo1); }
        break;
    case 11:
        LDC->dirUltimo();
        break;
    case 12:
        LDC->primero();
        break;
    case 13:
        LDC->ultimo();
        break;
    case 14:
        cout << "Posicion: ";
        cin >> num;
        LDC->datoPos(num);
        break;
    case 15:
        LDC->esVacia();
        break;
    case 16:
        cout << "Valor: ";
        cin >> num;
        LDC->existe(num);
        break;
    case 17:
        cout << "Nodo: ";
        cin >> num;
        LDC->agregarInicio(num);
        break;
    case 18:
        cout << "Nodo: ";
        cin >> num;
        LDC->agregarAlFinal(num);
        break;
    case 19:
        cout << "Nodo: ";
        cin >> num;
        cout << "Indice: ";
        cin >> num1;
        LDC->agregarAntesDe(num, num1);
        break;
    case 20:
        cout << "Nodo: ";
        cin >> num;
        cout << "Indice: ";
        cin >> num1;
        LDC->agregarDespuesDe(num, num1);
        break;
    case 21:
        LDC->desplegar();
        break;
    case 22:
        LDC->borrarLista();
        break;
    case 23:
        cout << "Valor: ";
        cin >> num;
        LDC->borrar(num);
        break;
    case 24:
        LDC->agregarNodoCadaDosNodosConsecutivos();
        break;
    case 25:
        cout << LDC->obtenerPromedio();
        break;
    case 26:
        LDC->eliminarValoresEnNodosPares();
        break;
    case 29:

        break;
    default:
        cout << "Opcion invalida";
        break;
    }
}

void ListasGestor::definirLista1()
{
    ListaSimple* ls = this->crearLista();
    this->ds->setL1(ls);
}

void ListasGestor::definirLista2()
{
    ListaSimple* ls = this->crearLista();
    this->ds->setL2(ls);
}

ListaSimple* ListasGestor::crearLista()
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

void ListasGestor::sonIguales()
{
    if (this->ds->sonIguales()) {
        cout << "Las listas son iguales";
    }
    else {
        cout << "Las listas no son iguales";
    }
}

void ListasGestor::invertirListas()
{
    this->ds->copiarInversa(this->ds->getL1(), this->ds->getL2());
}