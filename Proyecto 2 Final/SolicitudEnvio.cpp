#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "SolicitudEnvio.h"
#include "Paquete.h"
#include "Cliente.h"
#include "Colaborador.h"
#include "CentroDistribucion.h"

SolicitudEnvio::SolicitudEnvio(string cod, Paquete* p, Cliente* cli, Colaborador* col,
                               CentroDistribucion* cen, string dest, string fec, double costo)
    : codigo(cod), destino(dest), fecha(fec), estado("Pendiente"), costoEstimado(costo),
      paquete(p), cliente(cli), responsable(col), centro(cen) {}
string SolicitudEnvio::getCodigo() const { return codigo; }
string SolicitudEnvio::getDestino() const { return destino; }
string SolicitudEnvio::getFecha() const { return fecha; }
string SolicitudEnvio::getEstado() const { return estado; }
double SolicitudEnvio::getCostoEstimado() const { return costoEstimado; }
Paquete* SolicitudEnvio::getPaquete() const { return paquete; }
Cliente* SolicitudEnvio::getCliente() const { return cliente; }
Colaborador* SolicitudEnvio::getResponsable() const { return responsable; }
CentroDistribucion* SolicitudEnvio::getCentro() const { return centro; }
bool SolicitudEnvio::cambiarEstado(string nuevo) {
    if (estado != "Pendiente") return false;
    if (nuevo != "Aprobada" && nuevo != "Rechazada" && nuevo != "Anulada") return false;
    estado = nuevo;
    return true;
}
void SolicitudEnvio::mostrar() const {
    cout << codigo << " | Paquete: " << paquete->getCodigo()
         << " | Cliente: " << cliente->getIdentificacion()
         << " | Colaborador: " << responsable->getIdentificacion()
         << " | Centro: " << centro->getCodigo() << " | Destino: " << destino
         << " | Fecha: " << fecha << " | Costo CRC: " << costoEstimado
         << " | " << estado << '\n';
}
