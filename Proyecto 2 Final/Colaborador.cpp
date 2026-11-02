#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "Colaborador.h"

Colaborador::Colaborador(string id, string nom, string fecha, string p, CentroDistribucion* c) {
    this->identificacion = id;
    this->nombre = nom;
    this->fechaIngreso = fecha;
    this->puesto = p;
    this->centro = c;
}

string Colaborador::getIdentificacion() const {
    return identificacion;
}

string Colaborador::getNombre() const {
    return nombre;
}

string Colaborador::getFechaIngreso() const {
    return fechaIngreso;
}

string Colaborador::getPuesto() const {
    return puesto;
}

CentroDistribucion* Colaborador::getCentro() const {
    return centro;
}

void Colaborador::mostrar() const {
    cout << identificacion << " | " << nombre << " | Ingreso: " << fechaIngreso << " | Puesto: " << puesto << '\n';
}

Colaborador::~Colaborador() {
}

void Colaborador::destruir() {
    this->centro = NULL;
}
