#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "ListaBodegas.h"

ListaBodegas::ListaBodegas() : primero(NULL) {}

ListaBodegas::~ListaBodegas() {
    while (primero != NULL) {
        NodoBodega* borrar = primero;
        primero = primero->getSiguiente();
        delete borrar->getDato();
        delete borrar;
    }
}

void ListaBodegas::insertar(Bodega* dato) {
    NodoBodega* nodo = new NodoBodega(dato);
    anexar(nodo);
}

void ListaBodegas::anexar(NodoBodega* nodo) {
    if (primero == NULL) primero = nodo;
    else {
        NodoBodega* actual = primero;
        while (actual->getSiguiente() != NULL) actual = actual->getSiguiente();
        actual->setSiguiente(nodo);
    }
}

Bodega* ListaBodegas::buscar(string codigo) const {
    NodoBodega* actual = primero;
    while (actual != NULL) {
        if (actual->getDato()->getCodigo() == codigo) return actual->getDato();
        actual = actual->getSiguiente();
    }
    return NULL;
}

bool ListaBodegas::eliminar(string codigo) {
    NodoBodega* actual = primero;
    NodoBodega* anterior = NULL;
    while (actual != NULL && actual->getDato()->getCodigo() != codigo) {
        anterior = actual;
        actual = actual->getSiguiente();
    }
    if (actual == NULL) return false;
    if (anterior == NULL) primero = actual->getSiguiente();
    else anterior->setSiguiente(actual->getSiguiente());
    delete actual->getDato();
    delete actual;
    return true;
}

void ListaBodegas::mostrar() const {
    if (primero == NULL) cout << "Sin registros.\n";
    NodoBodega* actual = primero;
    while (actual != NULL) {
        actual->getDato()->mostrar();
        actual = actual->getSiguiente();
    }
}

const NodoBodega* ListaBodegas::getPrimero() const { return primero; }
bool ListaBodegas::vacia() const { return primero == NULL; }
