#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "NodoColaborador.h"

NodoColaborador::NodoColaborador(Colaborador* objeto) {
    this->dato = objeto;
    this->siguiente = NULL;
}

Colaborador* NodoColaborador::getDato() const {
    return dato;
}

NodoColaborador* NodoColaborador::getSiguiente() const {
    return siguiente;
}

void NodoColaborador::setSiguiente(NodoColaborador* nuevo) {
    siguiente = nuevo;
}

NodoColaborador::~NodoColaborador() {
}

void NodoColaborador::destruir() {
    this->dato = NULL;
    this->siguiente = NULL;
}
