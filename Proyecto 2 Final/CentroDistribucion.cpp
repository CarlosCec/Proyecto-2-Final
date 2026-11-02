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

CentroDistribucion::CentroDistribucion(string cod, string nom, string prov, string dir, string tel) {
    this->codigo = cod;
    this->nombre = nom;
    this->provincia = prov;
    this->direccion = dir;
    this->telefono = tel;
    this->despachos = new ListaDespachos();
    this->solicitudes = new ListaSolicitudes();
    this->paquetes = new ListaPaquetes();
    this->bodegas = new ListaBodegas();
    this->colaboradores = new ListaColaboradores();
    this->clientes = new ListaClientes();
}

CentroDistribucion::~CentroDistribucion() {
}

void CentroDistribucion::destruir() {
    // Primero las operaciones, luego los paquetes y finalmente sus referencias.
    if (this->despachos != NULL) {
        this->despachos->destruir();
        delete this->despachos;
        this->despachos = NULL;
    }
    if (this->solicitudes != NULL) {
        this->solicitudes->destruir();
        delete this->solicitudes;
        this->solicitudes = NULL;
    }
    if (this->paquetes != NULL) {
        this->paquetes->destruir();
        delete this->paquetes;
        this->paquetes = NULL;
    }
    if (this->bodegas != NULL) {
        this->bodegas->destruir();
        delete this->bodegas;
        this->bodegas = NULL;
    }
    if (this->colaboradores != NULL) {
        this->colaboradores->destruir();
        delete this->colaboradores;
        this->colaboradores = NULL;
    }
    if (this->clientes != NULL) {
        this->clientes->destruir();
        delete this->clientes;
        this->clientes = NULL;
    }
}

string CentroDistribucion::getCodigo() const {
    return codigo;
}

string CentroDistribucion::getNombre() const {
    return nombre;
}

string CentroDistribucion::getProvincia() const {
    return provincia;
}

string CentroDistribucion::getDireccion() const {
    return direccion;
}

string CentroDistribucion::getTelefono() const {
    return telefono;
}

ListaDespachos& CentroDistribucion::getDespachos() const {
    return *despachos;
}

ListaSolicitudes& CentroDistribucion::getSolicitudes() const {
    return *solicitudes;
}

ListaPaquetes& CentroDistribucion::getPaquetes() const {
    return *paquetes;
}

ListaBodegas& CentroDistribucion::getBodegas() const {
    return *bodegas;
}

ListaColaboradores& CentroDistribucion::getColaboradores() const {
    return *colaboradores;
}

ListaClientes& CentroDistribucion::getClientes() const {
    return *clientes;
}

bool CentroDistribucion::vacio() const {
    return clientes->vacia() && colaboradores->vacia() && paquetes->vacia() && bodegas->vacia() && solicitudes->vacia() && despachos->vacia();
}

void CentroDistribucion::mostrar() const {
    cout << codigo << " | " << nombre << " | " << provincia << " | " << direccion << " | Tel: " << telefono << '\n';
}
