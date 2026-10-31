#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "ListaClientes.h"


ListaClientes::ListaClientes() : primero(NULL) {}
ListaClientes::~ListaClientes() {
    while (primero != NULL) {
        NodoCliente* borrar = primero;
        primero = primero->getSiguiente();
        delete borrar->getDato();
        delete borrar;
    }
}
void ListaClientes::insertar(Cliente* dato) {
    NodoCliente* nodo = new NodoCliente(dato);
    if (primero == NULL) primero = nodo;
    else {
        NodoCliente* actual = primero;
        while (actual->getSiguiente() != NULL) actual = actual->getSiguiente();
        actual->setSiguiente(nodo);
    }
}
Cliente* ListaClientes::buscar(string clave) const {
    NodoCliente* actual = primero;
    while (actual != NULL) {
        if (actual->getDato()->getIdentificacion() == clave) return actual->getDato();
        actual = actual->getSiguiente();
    }
    return NULL;
}
NodoCliente* ListaClientes::getPrimero() const { return primero; }
bool ListaClientes::vacia() const { return primero == NULL; }
void ListaClientes::mostrar() const {
    if (primero == NULL) cout << "Sin registros.\n";
    NodoCliente* actual = primero;
    while (actual != NULL) {
        actual->getDato()->mostrar();
        actual = actual->getSiguiente();
    }
}
bool ListaClientes::eliminar(string clave) {
    NodoCliente* actual = primero;
    NodoCliente* anterior = NULL;
    while (actual != NULL && actual->getDato()->getIdentificacion() != clave) {
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
