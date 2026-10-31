#ifndef CLIENTEEMPRESA_H
#define CLIENTEEMPRESA_H
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "Cliente.h"

class ClienteEmpresa : public Cliente {
private:
    string actividad;
    double descuento;
public:
    ClienteEmpresa(string id, string nombre, string telefono, string correo,
                   CentroDistribucion* centro, string actividad, double descuento);
    string getActividad() const;
    string getTipo() const;
    double getDescuento() const;
    string toString() const;
};
#endif
