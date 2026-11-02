#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "ClienteFisico.h"

ClienteFisico::ClienteFisico(string id, string nombre, string telefono, string correo, CentroDistribucion* centro) : Cliente(id, nombre, telefono, correo, centro) {
}

string ClienteFisico::getTipo() const {
    return "Persona fisica";
}

ClienteFisico::~ClienteFisico() {
}

void ClienteFisico::destruir() {
    Cliente::destruir();
}
