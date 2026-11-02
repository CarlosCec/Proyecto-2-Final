#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "Celda.h"

void Celda::setPaquete(Paquete* nuevo) {
    paquete = nuevo;
}

Celda::Celda() {
    this->paquete = NULL;
}

Paquete* Celda::getPaquete() const {
    return paquete;
}

Celda::~Celda() {
}

void Celda::destruir() {
    this->paquete = NULL;
}
