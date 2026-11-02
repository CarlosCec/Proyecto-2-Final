#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "ListaSolicitudes.h"

ListaSolicitudes::ListaSolicitudes() {
    this->primero = NULL;
}

ListaSolicitudes::~ListaSolicitudes() {
}

void ListaSolicitudes::destruir() {
    while (primero != NULL) {
        NodoSolicitud* borrar = primero;
        primero = primero->getSiguiente();
        borrar->getDato()->destruir();
        delete borrar->getDato();
        borrar->destruir();
        delete borrar;
    }
}

void ListaSolicitudes::insertar(SolicitudEnvio* dato) {
    NodoSolicitud* nodo = new NodoSolicitud(dato);
    if (primero == NULL) {
        primero = nodo;
    } else {
        NodoSolicitud* actual = primero;
        while (actual->getSiguiente() != NULL) {
            actual = actual->getSiguiente();
        }
        actual->setSiguiente(nodo);
    }
}

SolicitudEnvio* ListaSolicitudes::buscar(string clave) const {
    NodoSolicitud* actual = primero;
    while (actual != NULL) {
        if (actual->getDato()->getCodigo() == clave) {
            return actual->getDato();
        }
        actual = actual->getSiguiente();
    }
    return NULL;
}

NodoSolicitud* ListaSolicitudes::getPrimero() const {
    return primero;
}

bool ListaSolicitudes::vacia() const {
    return primero == NULL;
}

void ListaSolicitudes::mostrar() const {
    if (primero == NULL) {
        cout << "Sin registros.\n";
    }
    NodoSolicitud* actual = primero;
    while (actual != NULL) {
        actual->getDato()->mostrar();
        actual = actual->getSiguiente();
    }
}
