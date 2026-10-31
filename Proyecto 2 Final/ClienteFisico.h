#ifndef CLIENTEFISICO_H
#define CLIENTEFISICO_H
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "Cliente.h"

class ClienteFisico : public Cliente {
public:
    ClienteFisico(string id, string nombre, string telefono, string correo, CentroDistribucion* centro);
    string getTipo() const;
};
#endif
