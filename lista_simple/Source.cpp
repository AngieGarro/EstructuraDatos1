#include "ListaSimple.h"
#include "ListasGestor.h";
#include "ListaDobleLineal.h";
#include "ListaDobleCircular.h";
#include <iostream>;
#include <stdlib.h>;
using namespace std;

int main() {
    ListaSimple* LS = new ListaSimple(); // INSTANCIA DE LISTA SIMPLE LS es un puntero a la estructura
    ListaDobleLineal* LDL = new ListaDobleLineal();
    ListaDobleCircular* LDC = new ListaDobleCircular();

    int opcion, num, num1;

    do {
        cout << "\n";
        cout << "MENU PRINCIPAL DE LISTAS\n";
        cout << "1 - Ver metodos de Lista Simple\n";
        cout << "2 - Ver metodos de Lista Doble Lineal\n";
        cout << "3 - Ver metodos de Lista Doble Circular\n";
        cout << "4 - Salir\n";
        cin >> opcion;

        switch (opcion) {
        case 1:
        {
            ListasGestor* ldg = new ListasGestor;
            int subOpcion;
            do {
                cout << "\n";
                cout << "MENU LISTA SIMPLE\n";
                cout << "1 - Obtener cabeza\n";
                cout << "2 - Obtener largo\n";
                cout << "3 - Agregar largo\n";
                cout << "4 - Obtener direccion del nodo referenciado\n";
                cout << "5 - Obtener direccino del nodo anterior al referneciado\n";
                cout << "6 - Obtener direccion del nodo anterior de la direccion referenciada\n";
                cout << "7 - Obtener direccion del ultimo nodo\n";
                cout << "8 - Obtener primer dato de la lista\n";
                cout << "9 - Obtener ultimo dato de la lista\n";
                cout << "10 - Obtener dato en posicion referenciada\n";
                cout << "11 - Obtener si la lista es vacia\n";
                cout << "12 - Verificar si un valor existe en la lista\n";
                cout << "13 - Agregar un nodo al inicio\n";
                cout << "14 - Agregar un nodo al final\n";
                cout << "15 - Agregar un nodo antes de un indice\n";
                cout << "16 - Agregar un nodo despues de un indice\n";
                cout << "17 - Desplegar lista\n";
                cout << "18 - Borrar Lista\n";
                cout << "19 - Eliminar elemento\n";
                cout << "20 - Eliminar nodos consegutivos iguales\n";
                cout << "21 - Eliminar nodos no consegutivos iguales\n";
                cout << "22 - Volver al menu principal\n";

                cout << "Selection: ";
                cin >> subOpcion;
                ldg->procesarOpcionLS(subOpcion);
            } while (opcion != 22);
            break;
        }
        case 2:
        {
            ListasGestor* ldg = new ListasGestor;
            int subOpcion;
            do {
                cout << "\n";
                cout << "MENU LISTA DOBLE LINEAL\n";
                cout << "1 - definir lista 1\n";
                cout << "2 - definir lista 2\n";
                cout << "3 - verificar si la listas son iguales\n";
                cout << "4 - Invertir listas\n";
                cout << "5 - Obtener cabeza\n";
                cout << "6 - Obtener largo\n";
                cout << "7 - Agregar largo\n";
                cout << "8 - Obtener direccion del nodo referenciado\n";
                cout << "9 - Obtener direccino del nodo anterior al referneciado\n";
                cout << "10 - Obtener direccion del nodo anterior de la direccion referenciada\n";
                cout << "11 - Obtener direccion del ultimo nodo\n";
                cout << "12 - Obtener primer dato de la lista\n";
                cout << "13 - Obtener ultimo dato de la lista\n";
                cout << "14 - Obtener dato en posicion referenciada\n";
                cout << "15 - Obtener si la lista es vacia\n";
                cout << "16 - Verificar si un valor existe en la lista\n";
                cout << "17 - Agregar un nodo al inicio\n";
                cout << "18 - Agregar un nodo al final\n";
                cout << "19 - Agregar un nodo antes de un indice\n";
                cout << "20 - Agregar un nodo despues de un indice\n";
                cout << "21 - Desplegar lista\n";
                cout << "22 - Borrar Lista\n";
                cout << "23 - Eliminar elemento\n";
                cout << "24 - Obtener la direccion del nodo en la posición cardinal\n";
                cout << "25 - Obtener mayor numero";
                cout << "26 - Eliminar nodo en la posicion cardinal\n";

                cout << "27 - Volver al menu principal\n";
                cout << "dijite la opcion: ";
                cin >> subOpcion;
                ldg->procesarOpcionLSL(subOpcion);
            } while (subOpcion != 27);
            break;
        }
        case 3:
        {
            ListasGestor* ldg = new ListasGestor;
            int subOpcion;
            do {
                cout << "\n";
                cout << "MENU LISTA DOBLE CIRCULAR\n";
                cout << "1 - definir lista 1\n";
                cout << "2 - definir lista 2\n";
                cout << "3 - verificar si la listas son iguales\n";
                cout << "4 - Invertir listas\n";
                cout << "5 - Obtener cabeza\n";
                cout << "6 - Obtener largo\n";
                cout << "7 - Agregar largo\n";
                cout << "8 - Obtener direccion del nodo referenciado\n";
                cout << "9 - Obtener direccino del nodo anterior al referneciado\n";
                cout << "10 - Obtener direccion del nodo anterior de la direccion referenciada\n";
                cout << "11 - Obtener direccion del ultimo nodo\n";
                cout << "12 - Obtener primer dato de la lista\n";
                cout << "13 - Obtener ultimo dato de la lista\n";
                cout << "14 - Obtener dato en posicion referenciada\n";
                cout << "15 - Obtener si la lista es vacia\n";
                cout << "16 - Verificar si un valor existe en la lista\n";
                cout << "17 - Agregar un nodo al inicio\n";
                cout << "18 - Agregar un nodo al final\n";
                cout << "19 - Agregar un nodo antes de un indice\n";
                cout << "20 - Agregar un nodo despues de un indice\n";
                cout << "21 - Desplegar lista\n";
                cout << "22 - Borrar Lista\n";
                cout << "23 - Eliminar elemento\n";
                cout << "24 - Anadir un nodo entre cada dos nodos consecutivos, cuyo valor sera igual a la diferencia entre los dos nodos\n";
                cout << "25 - Obtener el resultado del promedio de todos los valores de la lista\n";
                cout << "26 - Eliminara de la lista doble todos aquellos nodos que se ubiquen en posición cardinal par\n";
                cout << "27 - Volver al menu principal\n";
                cout << "dijite la opcion: ";
                cin >> subOpcion;
                ldg->procesarOpcionLSC(subOpcion);
            } while (subOpcion != 27);
            break;
        }
        case 4:
        {
            cout << "Gracias por usar el sistema";
            break;
        }
        default:
        {
            cout << "Opcion invalida";
            break;
        }
        }
    } while (opcion != 4);
}