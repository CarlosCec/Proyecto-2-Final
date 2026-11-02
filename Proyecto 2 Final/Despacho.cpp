#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "Despacho.h"
#include "Paquete.h"

Despacho::Despacho(string cod, SolicitudEnvio* s, string f, string h) {
    this->codigo = cod;
    this->destino = s->getDestino();
    this->fecha = f;
    this->hora = h;
    this->finalizado = false;
    this->solicitud = s;
    this->paquete = s->getPaquete();
    this->cliente = s->getCliente();
    this->responsable = s->getResponsable();
    this->centro = s->getCentro();
}

void Despacho::mostrar() const {
    cout << codigo << " | Solicitud: " << solicitud->getCodigo() << " | Paquete: " << paquete->getCodigo() << " | Cliente: " << cliente->getIdentificacion() << " | Colaborador: " << responsable->getIdentificacion() << " | Centro: " << centro->getCodigo() << " | Destino: " << destino << " | " << fecha << ' ' << hora << " | " << getEstado() << '\n';
}

bool Despacho::estaFinalizado() const {
    return finalizado;
}

void Despacho::finalizar() {
    finalizado = true;
}

string Despacho::getCodigo() const {
    return codigo;
}

string Despacho::getFecha() const {
    return fecha;
}

string Despacho::getEstado() const {
    return finalizado ? "Finalizado" : "En proceso";
}

SolicitudEnvio* Despacho::getSolicitud() const {
    return solicitud;
}

Paquete* Despacho::getPaquete() const {
    return paquete;
}

Cliente* Despacho::getCliente() const {
    return cliente;
}

Colaborador* Despacho::getResponsable() const {
    return responsable;
}

CentroDistribucion* Despacho::getCentro() const {
    return centro;
}

Despacho::~Despacho() {
}

void Despacho::destruir() {
    this->solicitud = NULL;
    this->paquete = NULL;
    this->cliente = NULL;
    this->responsable = NULL;
    this->centro = NULL;
}
