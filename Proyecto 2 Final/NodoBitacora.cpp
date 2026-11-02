#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "NodoBitacora.h"

NodoBitacora::NodoBitacora(int a, int n, string f, Colaborador* r) {
    this->anterior = a;
    this->nuevo = n;
    this->fecha = f;
    this->responsable = r;
    this->siguiente = NULL;
}

NodoBitacora* NodoBitacora::getSiguiente() const {
    return siguiente;
}

void NodoBitacora::setSiguiente(NodoBitacora* nuevo) {
    siguiente = nuevo;
}

int NodoBitacora::getAnterior() const {
    return anterior;
}

int NodoBitacora::getNuevo() const {
    return nuevo;
}

string NodoBitacora::getFecha() const {
    return fecha;
}

Colaborador* NodoBitacora::getResponsable() const {
    return responsable;
}

NodoBitacora::~NodoBitacora() {
}

void NodoBitacora::destruir() {
    this->responsable = NULL;
    this->siguiente = NULL;
}
