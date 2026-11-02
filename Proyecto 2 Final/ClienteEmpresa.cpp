#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "ClienteEmpresa.h"

ClienteEmpresa::ClienteEmpresa(string id, string nombre, string telefono, string correo, CentroDistribucion* centro, string act, double desc) : Cliente(id, nombre, telefono, correo, centro) {
    this->actividad = act;
    this->descuento = desc;
}

string ClienteEmpresa::getActividad() const {
    return actividad;
}

string ClienteEmpresa::getTipo() const {
    return "Empresa";
}

double ClienteEmpresa::getDescuento() const {
    return descuento;
}

string ClienteEmpresa::toString() const {
    ostringstream salida;
    salida << Cliente::toString() << " | Actividad: " << actividad << " | Descuento: " << descuento << "%";
    return salida.str();
}

ClienteEmpresa::~ClienteEmpresa() {
}

void ClienteEmpresa::destruir() {
    Cliente::destruir();
}
