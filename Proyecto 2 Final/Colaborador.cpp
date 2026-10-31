#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "Colaborador.h"


Colaborador::Colaborador(string id, string nom, string fecha, string p, CentroDistribucion* c)
    : identificacion(id), nombre(nom), fechaIngreso(fecha), puesto(p), centro(c) {}
string Colaborador::getIdentificacion() const { return identificacion; }
string Colaborador::getNombre() const { return nombre; }
string Colaborador::getFechaIngreso() const { return fechaIngreso; }
string Colaborador::getPuesto() const { return puesto; }
CentroDistribucion* Colaborador::getCentro() const { return centro; }
void Colaborador::mostrar() const {
    cout << identificacion << " | " << nombre << " | Ingreso: " << fechaIngreso
         << " | Puesto: " << puesto << '\n';
}
