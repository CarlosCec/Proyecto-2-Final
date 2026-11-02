#ifndef DESPACHO_H
#define DESPACHO_H
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "SolicitudEnvio.h"
#include "Cliente.h"
#include "Colaborador.h"
#include "CentroDistribucion.h"

class Despacho {
private:
    string codigo, destino, fecha, hora;
    bool finalizado;
    SolicitudEnvio* solicitud;
    Paquete* paquete;
    Cliente* cliente;
    Colaborador* responsable;
    CentroDistribucion* centro;
public:
    void destruir();
    ~Despacho();
    Despacho(string cod, SolicitudEnvio* s, string f, string h);
    string getCodigo() const;
    string getFecha() const;
    string getEstado() const;
    SolicitudEnvio* getSolicitud() const;
    Paquete* getPaquete() const;
    Cliente* getCliente() const;
    Colaborador* getResponsable() const;
    CentroDistribucion* getCentro() const;
    bool estaFinalizado() const;
    void finalizar();
    void mostrar() const;
};
#endif
