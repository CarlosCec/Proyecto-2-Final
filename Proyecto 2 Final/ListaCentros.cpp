#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "ListaCentros.h"


ListaCentros::ListaCentros() : primero(NULL) {}
ListaCentros::~ListaCentros() {
    while (primero != NULL) {
        NodoCentro* borrar = primero;
        primero = primero->getSiguiente();
        delete borrar->getCentro();
        delete borrar;
    }
}
void ListaCentros::insertar(CentroDistribucion* dato) {
    NodoCentro* nodo = new NodoCentro(dato);
    if (primero == NULL) primero = nodo;
    else {
        NodoCentro* actual = primero;
        while (actual->getSiguiente() != NULL) actual = actual->getSiguiente();
        actual->setSiguiente(nodo);
    }
}
CentroDistribucion* ListaCentros::buscar(string clave) const {
    NodoCentro* actual = primero;
    while (actual != NULL) {
        if (actual->getCentro()->getCodigo() == clave) return actual->getCentro();
        actual = actual->getSiguiente();
    }
    return NULL;
}
NodoCentro* ListaCentros::getPrimero() const { return primero; }
bool ListaCentros::vacia() const { return primero == NULL; }
void ListaCentros::mostrar() const {
    if (primero == NULL) cout << "Sin registros.\n";
    NodoCentro* actual = primero;
    while (actual != NULL) {
        actual->getCentro()->mostrar();
        actual = actual->getSiguiente();
    }
}
bool ListaCentros::eliminar(string clave) {
    NodoCentro* actual = primero;
    NodoCentro* anterior = NULL;
    while (actual != NULL && actual->getCentro()->getCodigo() != clave) {
        anterior = actual;
        actual = actual->getSiguiente();
    }
    if (actual == NULL) return false;
    if (anterior == NULL) primero = actual->getSiguiente();
    else anterior->setSiguiente(actual->getSiguiente());
    delete actual->getCentro();
    delete actual;
    return true;
}
