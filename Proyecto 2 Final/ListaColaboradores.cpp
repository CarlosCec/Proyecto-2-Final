#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "ListaColaboradores.h"

ListaColaboradores::ListaColaboradores() {
    this->primero = NULL;
}

ListaColaboradores::~ListaColaboradores() {
}

void ListaColaboradores::destruir() {
    while (primero != NULL) {
        NodoColaborador* borrar = primero;
        primero = primero->getSiguiente();
        borrar->getDato()->destruir();
        delete borrar->getDato();
        borrar->destruir();
        delete borrar;
    }
}

void ListaColaboradores::insertar(Colaborador* dato) {
    NodoColaborador* nodo = new NodoColaborador(dato);
    if (primero == NULL) {
        primero = nodo;
    } else {
        NodoColaborador* actual = primero;
        while (actual->getSiguiente() != NULL) {
            actual = actual->getSiguiente();
        }
        actual->setSiguiente(nodo);
    }
}

Colaborador* ListaColaboradores::buscar(string clave) const {
    NodoColaborador* actual = primero;
    while (actual != NULL) {
        if (actual->getDato()->getIdentificacion() == clave) {
            return actual->getDato();
        }
        actual = actual->getSiguiente();
    }
    return NULL;
}

NodoColaborador* ListaColaboradores::getPrimero() const {
    return primero;
}

bool ListaColaboradores::vacia() const {
    return primero == NULL;
}

void ListaColaboradores::mostrar() const {
    if (primero == NULL) {
        cout << "Sin registros.\n";
    }
    NodoColaborador* actual = primero;
    while (actual != NULL) {
        actual->getDato()->mostrar();
        actual = actual->getSiguiente();
    }
}

bool ListaColaboradores::eliminar(string clave) {
    NodoColaborador* actual = primero;
    NodoColaborador* anterior = NULL;
    while (actual != NULL && actual->getDato()->getIdentificacion() != clave) {
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
