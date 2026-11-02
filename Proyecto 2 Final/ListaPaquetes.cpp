#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "ListaPaquetes.h"

ListaPaquetes::ListaPaquetes() {
    this->primero = NULL;
}

ListaPaquetes::~ListaPaquetes() {
}

void ListaPaquetes::destruir() {
    while (primero != NULL) {
        NodoPaquete* borrar = primero;
        primero = primero->getSiguiente();
        borrar->getDato()->destruir();
        delete borrar->getDato();
        borrar->destruir();
        delete borrar;
    }
}

void ListaPaquetes::insertar(Paquete* dato) {
    NodoPaquete* nodo = new NodoPaquete(dato);
    anexar(nodo);
}

void ListaPaquetes::anexar(NodoPaquete* nodo) {
    if (primero == NULL) {
        primero = nodo;
    } else {
        NodoPaquete* actual = primero;
        while (actual->getSiguiente() != NULL) {
            actual = actual->getSiguiente();
        }
        actual->setSiguiente(nodo);
    }
}

Paquete* ListaPaquetes::buscar(string codigo) const {
    NodoPaquete* actual = primero;
    while (actual != NULL) {
        if (actual->getDato()->getCodigo() == codigo) {
            return actual->getDato();
        }
        actual = actual->getSiguiente();
    }
    return NULL;
}

bool ListaPaquetes::eliminar(string codigo) {
    NodoPaquete* actual = primero;
    NodoPaquete* anterior = NULL;
    while (actual != NULL && actual->getDato()->getCodigo() != codigo) {
        anterior = actual;
        actual = actual->getSiguiente();
    }
    if (actual == NULL) {
        return false;
    }
    if (anterior == NULL) {
        primero = actual->getSiguiente();
    } else {
        anterior->setSiguiente(actual->getSiguiente());
    }
    actual->getDato()->destruir();
    delete actual->getDato();
    actual->destruir();
    delete actual;
    return true;
}

void ListaPaquetes::mostrar() const {
    if (primero == NULL) {
        cout << "Sin registros.\n";
    }
    NodoPaquete* actual = primero;
    while (actual != NULL) {
        actual->getDato()->mostrar();
        actual = actual->getSiguiente();
    }
}

const NodoPaquete* ListaPaquetes::getPrimero() const {
    return primero;
}

bool ListaPaquetes::vacia() const {
    return primero == NULL;
}
