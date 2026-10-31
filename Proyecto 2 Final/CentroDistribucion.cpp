#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "CentroDistribucion.h"
#include "ListaDespachos.h"
#include "ListaSolicitudes.h"
#include "ListaPaquetes.h"
#include "ListaBodegas.h"
#include "ListaColaboradores.h"
#include "ListaClientes.h"

CentroDistribucion::CentroDistribucion(string cod, string nom, string prov, string dir, string tel)
    : codigo(cod), nombre(nom), provincia(prov), direccion(dir), telefono(tel) {
    despachos = new ListaDespachos();
    solicitudes = new ListaSolicitudes();
    paquetes = new ListaPaquetes();
    bodegas = new ListaBodegas();
    colaboradores = new ListaColaboradores();
    clientes = new ListaClientes();
}
CentroDistribucion::~CentroDistribucion() {
    // Primero las operaciones, luego los paquetes y finalmente sus referencias.
    delete despachos;
    delete solicitudes;
    delete paquetes;
    delete bodegas;
    delete colaboradores;
    delete clientes;
}
string CentroDistribucion::getCodigo() const { return codigo; }
string CentroDistribucion::getNombre() const { return nombre; }
string CentroDistribucion::getProvincia() const { return provincia; }
string CentroDistribucion::getDireccion() const { return direccion; }
string CentroDistribucion::getTelefono() const { return telefono; }
ListaDespachos& CentroDistribucion::getDespachos() const { return *despachos; }
ListaSolicitudes& CentroDistribucion::getSolicitudes() const { return *solicitudes; }
ListaPaquetes& CentroDistribucion::getPaquetes() const { return *paquetes; }
ListaBodegas& CentroDistribucion::getBodegas() const { return *bodegas; }
ListaColaboradores& CentroDistribucion::getColaboradores() const { return *colaboradores; }
ListaClientes& CentroDistribucion::getClientes() const { return *clientes; }
bool CentroDistribucion::vacio() const {
    return clientes->vacia() && colaboradores->vacia() && paquetes->vacia()
        && bodegas->vacia() && solicitudes->vacia() && despachos->vacia();
}
void CentroDistribucion::mostrar() const {
    cout << codigo << " | " << nombre << " | " << provincia << " | " << direccion
         << " | Tel: " << telefono << '\n';
}
