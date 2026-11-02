#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "NodoCentro.h"

NodoCentro::NodoCentro(CentroDistribucion* objeto) {
    this->centro = objeto;
    this->siguiente = NULL;
}

CentroDistribucion* NodoCentro::getCentro() const {
    return centro;
}

NodoCentro* NodoCentro::getSiguiente() const {
    return siguiente;
}

void NodoCentro::setSiguiente(NodoCentro* nuevo) {
    siguiente = nuevo;
}

NodoCentro::~NodoCentro() {
}

void NodoCentro::destruir() {
    this->centro = NULL;
    this->siguiente = NULL;
}
