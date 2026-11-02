#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "NodoBodega.h"

NodoBodega* NodoBodega::getSiguiente() const {
    return siguiente;
}

void NodoBodega::setSiguiente(NodoBodega* nuevo) {
    siguiente = nuevo;
}

Bodega* NodoBodega::getDato() const {
    return dato;
}

NodoBodega::NodoBodega(Bodega* d) {
    this->dato = d;
    this->siguiente = NULL;
}

NodoBodega::~NodoBodega() {
}

void NodoBodega::destruir() {
    this->dato = NULL;
    this->siguiente = NULL;
}
