#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "NodoPaquete.h"

NodoPaquete* NodoPaquete::getSiguiente() const {
    return siguiente;
}

void NodoPaquete::setSiguiente(NodoPaquete* nuevo) {
    siguiente = nuevo;
}

Paquete* NodoPaquete::getDato() const {
    return dato;
}

NodoPaquete::NodoPaquete(Paquete* d) {
    this->dato = d;
    this->siguiente = NULL;
}

NodoPaquete::~NodoPaquete() {
}

void NodoPaquete::destruir() {
    this->dato = NULL;
    this->siguiente = NULL;
}
