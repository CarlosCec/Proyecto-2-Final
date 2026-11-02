#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "NodoDespacho.h"

NodoDespacho* NodoDespacho::getSiguiente() const {
    return siguiente;
}

void NodoDespacho::setSiguiente(NodoDespacho* nuevo) {
    siguiente = nuevo;
}

Despacho* NodoDespacho::getDato() const {
    return dato;
}

NodoDespacho::NodoDespacho(Despacho* d) {
    this->dato = d;
    this->siguiente = NULL;
}

NodoDespacho::~NodoDespacho() {
}

void NodoDespacho::destruir() {
    this->dato = NULL;
    this->siguiente = NULL;
}
