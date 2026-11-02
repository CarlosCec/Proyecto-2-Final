#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "ListaDespachos.h"

ListaDespachos::ListaDespachos() {
    this->primero = NULL;
}

ListaDespachos::~ListaDespachos() {
}

void ListaDespachos::destruir() {
    while (primero != NULL) {
        NodoDespacho* borrar = primero;
        primero = primero->getSiguiente();
        borrar->getDato()->destruir();
        delete borrar->getDato();
        borrar->destruir();
        delete borrar;
    }
}

void ListaDespachos::insertar(Despacho* dato) {
    NodoDespacho* nodo = new NodoDespacho(dato);
    anexar(nodo);
}

void ListaDespachos::anexar(NodoDespacho* nodo) {
    if (primero == NULL) {
        primero = nodo;
    } else {
        NodoDespacho* actual = primero;
        while (actual->getSiguiente() != NULL) {
            actual = actual->getSiguiente();
        }
        actual->setSiguiente(nodo);
    }
}

Despacho* ListaDespachos::buscar(string codigo) const {
    NodoDespacho* actual = primero;
    while (actual != NULL) {
        if (actual->getDato()->getCodigo() == codigo) {
            return actual->getDato();
        }
        actual = actual->getSiguiente();
    }
    return NULL;
}

void ListaDespachos::mostrar() const {
    if (primero == NULL) {
        cout << "Sin registros.\n";
    }
    NodoDespacho* actual = primero;
    while (actual != NULL) {
        actual->getDato()->mostrar();
        actual = actual->getSiguiente();
    }
}

const NodoDespacho* ListaDespachos::getPrimero() const {
    return primero;
}

bool ListaDespachos::vacia() const {
    return primero == NULL;
}
