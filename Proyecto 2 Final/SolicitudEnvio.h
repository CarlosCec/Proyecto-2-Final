#ifndef SOLICITUDENVIO_H
#define SOLICITUDENVIO_H
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

class Paquete;
class Cliente;
class Colaborador;
class CentroDistribucion;
class SolicitudEnvio {
private:
    string codigo, destino, fecha, estado;
    double costoEstimado;
    Paquete* paquete;
    Cliente* cliente;
    Colaborador* responsable;
    CentroDistribucion* centro;
public:
    void destruir();
    ~SolicitudEnvio();
    SolicitudEnvio(string codigo, Paquete* paquete, Cliente* cliente, Colaborador* responsable, CentroDistribucion* centro, string destino, string fecha, double costo);
    string getCodigo() const;
    string getDestino() const;
    string getFecha() const;
    string getEstado() const;
    double getCostoEstimado() const;
    Paquete* getPaquete() const;
    Cliente* getCliente() const;
    Colaborador* getResponsable() const;
    CentroDistribucion* getCentro() const;
    bool cambiarEstado(string nuevo);
    void mostrar() const;
};
#endif
