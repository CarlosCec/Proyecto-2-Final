#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "Cliente.h"


Cliente::Cliente(string id, string nom, string tel, string email, CentroDistribucion* c)
    : identificacion(id), nombre(nom), telefono(tel), correo(email), centro(c) {}
Cliente::~Cliente() {}
string Cliente::getIdentificacion() const { return identificacion; }
string Cliente::getNombre() const { return nombre; }
string Cliente::getTelefono() const { return telefono; }
string Cliente::getCorreo() const { return correo; }
CentroDistribucion* Cliente::getCentro() const { return centro; }
double Cliente::getDescuento() const { return 0; }
string Cliente::toString() const {
    ostringstream salida;
    salida << identificacion << " | " << nombre << " | " << getTipo()
           << " | Tel: " << telefono << " | Correo: " << correo;
    return salida.str();
}
void Cliente::mostrar() const { cout << toString() << '\n'; }
