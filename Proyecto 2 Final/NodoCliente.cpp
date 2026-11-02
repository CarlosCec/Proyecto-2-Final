#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "NodoCliente.h"

NodoCliente::NodoCliente(Cliente* objeto) {
    this->dato = objeto;
    this->siguiente = NULL;
}

Cliente* NodoCliente::getDato() const {
    return dato;
}

NodoCliente* NodoCliente::getSiguiente() const {
    return siguiente;
}

void NodoCliente::setSiguiente(NodoCliente* nuevo) {
    siguiente = nuevo;
}

NodoCliente::~NodoCliente() {
}

void NodoCliente::destruir() {
    this->dato = NULL;
    this->siguiente = NULL;
}
