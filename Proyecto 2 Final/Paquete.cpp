#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "Paquete.h"
#include "CentroDistribucion.h"
#include "Bodega.h"

Paquete::Paquete(string cod, string desc, double kg, int cat, Cliente* cli, CentroDistribucion* cen) {
    this->codigo = cod;
    this->descripcion = desc;
    this->peso = kg;
    this->categoria = cat;
    this->estado = RECIBIDO;
    this->cliente = cli;
    this->centro = cen;
    this->bodega = NULL;
    this->fila = -1;
    this->columna = -1;
}

void Paquete::mostrar() const {
    cout << codigo << " | " << descripcion << " | " << peso << " kg | " << nombreCategoria(categoria) << " | " << nombreEstado(estado) << " | Cliente: " << cliente->getIdentificacion() << " | Centro: " << centro->getCodigo();
    if (bodega != NULL) {
        cout << " | " << bodega->getCodigo() << "-" << fila << "-" << columna;
    } else {
        cout << " | Sin ubicacion";
    }
    cout << '\n';
}

void Paquete::setUbicacion(Bodega* nuevaBodega, int nuevaFila, int nuevaColumna) {
    bodega = nuevaBodega;
    fila = nuevaFila;
    columna = nuevaColumna;
}

void Paquete::registrarCambio(int nuevo, string fecha, Colaborador* responsable) {
    bitacora.agregar(estado, nuevo, fecha, responsable);
    estado = nuevo;
}

string Paquete::getCodigo() const {
    return codigo;
}

double Paquete::getPeso() const {
    return peso;
}

int Paquete::getCategoria() const {
    return categoria;
}

int Paquete::getEstado() const {
    return estado;
}

Cliente* Paquete::getCliente() const {
    return cliente;
}

CentroDistribucion* Paquete::getCentro() const {
    return centro;
}

Bodega* Paquete::getBodega() const {
    return bodega;
}

int Paquete::getFila() const {
    return fila;
}

int Paquete::getColumna() const {
    return columna;
}

const Bitacora& Paquete::getBitacora() const {
    return bitacora;
}

Paquete::~Paquete() {
}

void Paquete::destruir() {
    this->bitacora.destruir();
    this->cliente = NULL;
    this->centro = NULL;
    this->bodega = NULL;
    this->fila = -1;
    this->columna = -1;
}
